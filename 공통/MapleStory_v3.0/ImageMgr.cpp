#include "stdafx.h"
#include "ImageMgr.h"

BOOL ImageMgr::AddImg(LPCWSTR _FilePath)
{

	// �ӽ÷� �̹��� ������ �����ϱ� ���� ���� ����
	ImgInfo t_ImgInfo;

	// ���� ��θ� �ӽ� �̹��� ������ �ݿ�
	t_ImgInfo.m_Path = _FilePath;

	// ���� �̸��� �����ϱ� ���� �غ�
	wstring t_FilePath = _FilePath;

	// �ڿ������� �˻��Ͽ� \ �� ã�Ƽ� ��ġ ����
	int t_FindNum = (int)t_FilePath.find_last_of(L"\\");
	//.find_last_of("/\\");
	// �ڿ������� �˻��Ͽ� . �� ã�Ƽ� ��ġ ����
	int t_ListNum = (int)t_FilePath.find_last_of(L".");

	// ã�� ��ġ�� �������� �̹��� �̸��� ����
	t_ImgInfo.m_Name = t_FilePath.substr(t_FindNum + 1, (t_ListNum - t_FindNum - 1));


	if (m_Imglist.count(t_ImgInfo.m_Name) > 1)
	{
		MK_LOG("AddImg ����");
		return false;
	}


	t_ImgInfo.m_Bitmap = ImageAsBitmap(_FilePath);

	m_Imglist.insert(pair<wstring, ImgInfo>(t_ImgInfo.m_Name, t_ImgInfo));


	return true;
}

BOOL ImageMgr::AddImg(LPCWSTR _FilePath, map<wstring, ImgInfo> &_Imglist)
{
	// �ӽ÷� �̹��� ������ �����ϱ� ���� ���� ����
	ImgInfo t_ImgInfo;

	// ���� ��θ� �ӽ� �̹��� ������ �ݿ�
	t_ImgInfo.m_Path = _FilePath;

	// ���� �̸��� �����ϱ� ���� �غ�
	wstring t_FilePath = _FilePath;

	// �ڿ������� �˻��Ͽ� \ �� ã�Ƽ� ��ġ ����
	int t_FindNum = (int)t_FilePath.find_last_of(L"\\");
	//.find_last_of("/\\");
	// �ڿ������� �˻��Ͽ� . �� ã�Ƽ� ��ġ ����
	int t_ListNum = (int)t_FilePath.find_last_of(L".");

	// ã�� ��ġ�� �������� �̹��� �̸��� ����
	t_ImgInfo.m_Name = t_FilePath.substr(t_FindNum + 1, (t_ListNum - t_FindNum - 1));


	if (_Imglist.count(t_ImgInfo.m_Name) > 1)
	{
		MK_LOG("AddImg ����");
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

	//	WIC �ɼ� �ѱ�
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
	// ���� ��θ� ���� ù��° ���� ������ �޾ƿ�
	t_hSrch = FindFirstFileW((_Path + L"*.*").c_str(), &t_wfd);

	// ù��° ���� ���� �޾ƿ��� ������ ���� ó�� (���� ��ΰ� �߸��� ��� ��)
	if (t_hSrch == INVALID_HANDLE_VALUE)
	{
		MK_LOG("FileFindDir ����");
		return VOID();
	}
	while (t_bResult)
	{

		// ������ "dwFileAttributes" �Ӽ��� 16 (����)�̰� ù��° ���ڰ� '.' �� �ƴ϶�� ������ ó��
		// ù��° ���ڰ� '.' �� ��� ���� ��� ���� �ǹ��ϴ� ������ ����
		if (t_wfd.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY && t_wfd.cFileName[0] != '.')
		{
			// ���� ������ ������� �ٽ� Ȯ�� �Լ� ȣ��(���)
			FileFindDir((_Path + t_wfd.cFileName + L"\\").c_str());
		}
		// ������ "dwFileAttributes" �Ӽ��� 32(����) �̶�� ���� ���� ó��
		else if (t_wfd.dwFileAttributes != FILE_ATTRIBUTE_COMPRESSED && t_wfd.cFileName[0] != '.')
		{
			// wstring �� find �Լ��� ����ϱ� ���� ���ϸ��� wstring ������ ����
			wstring t_FileTypeChk = t_wfd.cFileName;
			// ".png" Ȯ���ڰ� �ִ� ��쿡�� AddImg �Լ��� ȣ����
			if (t_FileTypeChk.find(L".png"))
			{
				//�̹��� ���Ͽ� ���� bitmap ���� �� ����Ʈ ������ ���� AddImg�Լ��� ��� ����(��� ����) ���� �Է�
				AddImg((LPCWSTR)(_Path + t_wfd.cFileName).c_str());
			}

		}

		// Ȯ�� �۾��� �����ٸ� ���� ���Ϸ� ��� ���� (���� ������ ���ٸ� false �� �ݸ��� �ߴܵ�
		t_bResult = FindNextFileW(t_hSrch, &t_wfd);
	}
	// �۾� ���ῡ ���� close ó��
	FindClose(t_hSrch);

	return VOID();
}

void ImageMgr::FileFindDir_Take(wstring _Path, map<wstring, ImgInfo> &_Imglist)
{
	HANDLE t_hSrch;
	WIN32_FIND_DATAW t_wfd;
	BOOL t_bResult = TRUE;
	// ���� ��θ� ���� ù��° ���� ������ �޾ƿ�
	t_hSrch = FindFirstFileW((_Path + L"*.*").c_str(), &t_wfd);

	// ù��° ���� ���� �޾ƿ��� ������ ���� ó�� (���� ��ΰ� �߸��� ��� ��)
	if (t_hSrch == INVALID_HANDLE_VALUE)
	{
		MK_LOG("FileFindDir ����");
		return VOID();
	}
	while (t_bResult)
	{

		// ������ "dwFileAttributes" �Ӽ��� 16 (����)�̰� ù��° ���ڰ� '.' �� �ƴ϶�� ������ ó��
		// ù��° ���ڰ� '.' �� ��� ���� ��� ���� �ǹ��ϴ� ������ ����
		if (t_wfd.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY && t_wfd.cFileName[0] != '.')
		{
			// ���� ������ ������� �ٽ� Ȯ�� �Լ� ȣ��(���)
			FileFindDir((_Path + t_wfd.cFileName + L"\\").c_str());
		}
		// ������ "dwFileAttributes" �Ӽ��� 32(����) �̶�� ���� ���� ó��
		else if (t_wfd.dwFileAttributes != FILE_ATTRIBUTE_COMPRESSED && t_wfd.cFileName[0] != '.')
		{
			// wstring �� find �Լ��� ����ϱ� ���� ���ϸ��� wstring ������ ����
			wstring t_FileTypeChk = t_wfd.cFileName;
			// ".png" Ȯ���ڰ� �ִ� ��쿡�� AddImg �Լ��� ȣ����
			if (t_FileTypeChk.find(L".png"))
			{
				//�̹��� ���Ͽ� ���� bitmap ���� �� ����Ʈ ������ ���� AddImg�Լ��� ��� ����(��� ����) ���� �Է�
				AddImg((LPCWSTR)(_Path + t_wfd.cFileName).c_str(), _Imglist);
			}

		}

		// Ȯ�� �۾��� �����ٸ� ���� ���Ϸ� ��� ���� (���� ������ ���ٸ� false �� �ݸ��� �ߴܵ�
		t_bResult = FindNextFileW(t_hSrch, &t_wfd);
	}
	// �۾� ���ῡ ���� close ó��
	FindClose(t_hSrch);

	return VOID();
}



