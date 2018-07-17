#include "stdafx.h"
#include "ImageMgr.h"

BOOL ImageMgr::AddImg(LPCWSTR _FilePath)
{

	// 임시로 이미지 정보를 저장하기 위한 변수 선언
	ImgInfo t_ImgInfo;

	// 파일 경로를 임시 이미지 정보에 반영
	t_ImgInfo.m_Path = _FilePath;

	// 파일 이름을 저장하기 위한 준비
	wstring t_FilePath = _FilePath;

	// 뒤에서부터 검색하여 \ 를 찾아서 위치 저장
	int t_FindNum = (int)t_FilePath.find_last_of(L"\\");
	//.find_last_of("/\\");
	// 뒤에서부터 검색하여 . 을 찾아서 위치 저장
	int t_ListNum = (int)t_FilePath.find_last_of(L".");

	// 찾은 위치를 기준으로 이미지 이름을 저장
	t_ImgInfo.m_Name = t_FilePath.substr(t_FindNum + 1, (t_ListNum - t_FindNum - 1));


	if (m_Imglist.count(t_ImgInfo.m_Name) > 1)
	{
		MK_LOG("AddImg 실패");
		return false;
	}


	t_ImgInfo.m_Bitmap = ImageAsBitmap(_FilePath);

	m_Imglist.insert(pair<wstring, ImgInfo>(t_ImgInfo.m_Name, t_ImgInfo));


	return true;
}

BOOL ImageMgr::AddImg(LPCWSTR _FilePath, map<wstring, ImgInfo> &_Imglist)
{
	// 임시로 이미지 정보를 저장하기 위한 변수 선언
	ImgInfo t_ImgInfo;

	// 파일 경로를 임시 이미지 정보에 반영
	t_ImgInfo.m_Path = _FilePath;

	// 파일 이름을 저장하기 위한 준비
	wstring t_FilePath = _FilePath;

	// 뒤에서부터 검색하여 \ 를 찾아서 위치 저장
	int t_FindNum = (int)t_FilePath.find_last_of(L"\\");
	//.find_last_of("/\\");
	// 뒤에서부터 검색하여 . 을 찾아서 위치 저장
	int t_ListNum = (int)t_FilePath.find_last_of(L".");

	// 찾은 위치를 기준으로 이미지 이름을 저장
	t_ImgInfo.m_Name = t_FilePath.substr(t_FindNum + 1, (t_ListNum - t_FindNum - 1));


	if (_Imglist.count(t_ImgInfo.m_Name) > 1)
	{
		MK_LOG("AddImg 실패");
		return false;
	}


	t_ImgInfo.m_Bitmap = ImageAsBitmap(_FilePath);

	_Imglist.insert(pair<wstring, ImgInfo>(t_ImgInfo.m_Name, t_ImgInfo));


	return true;
}


ID2D1Bitmap * ImageMgr::ImageAsBitmap(LPCWSTR _FilePath)
{
	HRESULT hr = S_OK;

	ID2D1Bitmap *t_pBitmap;

	// Create a decoder
	IWICBitmapDecoder *t_pDecoder = nullptr;


	hr = m_pIWICFactory->CreateDecoderFromFilename(
		_FilePath,                      // Image to be decoded
		nullptr,                         // Do not prefer a particular vendor
		GENERIC_READ,                    // Desired read access to the file
		WICDecodeMetadataCacheOnDemand,  // Cache metadata when needed
		&t_pDecoder                      // Pointer to the decoder
	);

	HR_CHECK_MSG2("CreateDecoderFromFilename");


	// Retrieve the first frame of the image from the decoder
	IWICBitmapFrameDecode *t_pFrame = nullptr;

	hr = t_pDecoder->GetFrame(0, &t_pFrame);

	HR_CHECK_MSG2("GetFrame");


	//Step 3: Format convert the frame to 32bppPBGRA

	hr = m_pIWICFactory->CreateFormatConverter(&m_pConvertedSourceBitmap);

	HR_CHECK_MSG2("CreateFormatConverter");



	hr = m_pConvertedSourceBitmap->Initialize(
		t_pFrame,                        // Input bitmap to convert
		GUID_WICPixelFormat32bppPBGRA,   // Destination pixel format
		WICBitmapDitherTypeNone,         // Specified dither pattern
		nullptr,                         // Specify a particular palette 
		0.f,                             // Alpha threshold
		WICBitmapPaletteTypeCustom       // Palette translation type
	);

	HR_CHECK_MSG2("m_pConvertedSourceBitmap-Initialize");


	SafeRelease(t_pDecoder);
	SafeRelease(t_pFrame);

	m_pRT->CreateBitmapFromWicBitmap(
		m_pConvertedSourceBitmap,
		nullptr,
		&t_pBitmap);

	return t_pBitmap;
}

ImageMgr::~ImageMgr()
{
	if (m_pConvertedSourceBitmap != nullptr)
	{
		m_pConvertedSourceBitmap->Release();
		m_pConvertedSourceBitmap = nullptr;
	}
	if (m_pIWICFactory != nullptr)
	{
		m_pIWICFactory->Release();
		m_pIWICFactory = nullptr;
	}

	//	WIC Factory UnInit
	CoUninitialize();
}

void ImageMgr::Init(ID2D1RenderTarget *_pRT)
{
	m_pRT = _pRT;

	//	WIC 옵션 켜기
	CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	// Create WIC factory
	CoCreateInstance(
		CLSID_WICImagingFactory,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&m_pIWICFactory));
}

void ImageMgr::FileFindDir(wstring _Path)
{
	HANDLE t_hSrch;
	WIN32_FIND_DATAW t_wfd;
	BOOL t_bResult = TRUE;
	// 파일 경로를 에서 첫번째 파일 정보를 받아옴
	t_hSrch = FindFirstFileW((_Path + L"*.*").c_str(), &t_wfd);

	// 첫번째 파일 정보 받아오기 오류시 종료 처리 (폴더 경로가 잘못된 경우 등)
	if (t_hSrch == INVALID_HANDLE_VALUE)
	{
		MK_LOG("FileFindDir 실패");
		return VOID();
	}
	while (t_bResult)
	{

		// 파일의 "dwFileAttributes" 속성이 16 (폴더)이고 첫번째 문자가 '.' 이 아니라면 폴더로 처리
		// 첫번째 문자가 '.' 인 경우 상위 경로 등을 의미하는 폴더로 무시
		if (t_wfd.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY && t_wfd.cFileName[0] != '.')
		{
			// 하위 폴더를 대상으로 다시 확인 함수 호출(재귀)
			FileFindDir((_Path + t_wfd.cFileName + L"\\").c_str());
		}
		// 파일의 "dwFileAttributes" 속성이 32(파일) 이라면 파일 관련 처리
		else if (t_wfd.dwFileAttributes != FILE_ATTRIBUTE_COMPRESSED && t_wfd.cFileName[0] != '.')
		{
			// wstring 의 find 함수를 사용하기 위해 파일명을 wstring 변수에 대입
			wstring t_FileTypeChk = t_wfd.cFileName;
			// ".png" 확장자가 있는 경우에만 AddImg 함수를 호출함
			if (t_FileTypeChk.find(L".png"))
			{
				//이미지 파일에 대한 bitmap 생성 및 리스트 관리를 위한 AddImg함수에 대상 파일(경로 포함) 정보 입력
				AddImg((LPCWSTR)(_Path + t_wfd.cFileName).c_str());
			}

		}

		// 확인 작업이 끝났다면 다음 파일로 대상 변경 (다음 파일이 없다면 false 로 반목이 중단됨
		t_bResult = FindNextFileW(t_hSrch, &t_wfd);
	}
	// 작업 종료에 따른 close 처리
	FindClose(t_hSrch);

	return VOID();
}

void ImageMgr::FileFindDir_Take(wstring _Path, map<wstring, ImgInfo> &_Imglist)
{
	HANDLE t_hSrch;
	WIN32_FIND_DATAW t_wfd;
	BOOL t_bResult = TRUE;
	// 파일 경로를 에서 첫번째 파일 정보를 받아옴
	t_hSrch = FindFirstFileW((_Path + L"*.*").c_str(), &t_wfd);

	// 첫번째 파일 정보 받아오기 오류시 종료 처리 (폴더 경로가 잘못된 경우 등)
	if (t_hSrch == INVALID_HANDLE_VALUE)
	{
		MK_LOG("FileFindDir 실패");
		return VOID();
	}
	while (t_bResult)
	{

		// 파일의 "dwFileAttributes" 속성이 16 (폴더)이고 첫번째 문자가 '.' 이 아니라면 폴더로 처리
		// 첫번째 문자가 '.' 인 경우 상위 경로 등을 의미하는 폴더로 무시
		if (t_wfd.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY && t_wfd.cFileName[0] != '.')
		{
			// 하위 폴더를 대상으로 다시 확인 함수 호출(재귀)
			FileFindDir((_Path + t_wfd.cFileName + L"\\").c_str());
		}
		// 파일의 "dwFileAttributes" 속성이 32(파일) 이라면 파일 관련 처리
		else if (t_wfd.dwFileAttributes != FILE_ATTRIBUTE_COMPRESSED && t_wfd.cFileName[0] != '.')
		{
			// wstring 의 find 함수를 사용하기 위해 파일명을 wstring 변수에 대입
			wstring t_FileTypeChk = t_wfd.cFileName;
			// ".png" 확장자가 있는 경우에만 AddImg 함수를 호출함
			if (t_FileTypeChk.find(L".png"))
			{
				//이미지 파일에 대한 bitmap 생성 및 리스트 관리를 위한 AddImg함수에 대상 파일(경로 포함) 정보 입력
				AddImg((LPCWSTR)(_Path + t_wfd.cFileName).c_str(), _Imglist);
			}

		}

		// 확인 작업이 끝났다면 다음 파일로 대상 변경 (다음 파일이 없다면 false 로 반목이 중단됨
		t_bResult = FindNextFileW(t_hSrch, &t_wfd);
	}
	// 작업 종료에 따른 close 처리
	FindClose(t_hSrch);

	return VOID();
}



