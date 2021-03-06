#pragma once

#define WIN32_LEAN_AND_MEAN    

#include <string>
using namespace std;

#include <windows.h>
#include <windowsx.h>
#include <wincodec.h>

#include <sstream>
CONST INT WIN_WIDTH = 1200;
CONST INT WIN_HEIGHT = 800;

template <typename T>
void	SafeRelease(T &_p)
{
	if (_p != nullptr)
	{
		_p->Release();
		_p = nullptr;
	}
}

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

#include <DirectXColors.h>

#include <DirectXCollision.h>

using namespace DirectX;

#include <d2d1.h>
#pragma comment(lib, "d2d1.lib")

using namespace D2D1;

#include "DDSTextureLoader.h"

#include "MK_KeyMgr.h"
using namespace MK_API;

#include "cTimer.h"
#include "BufferType.h"

#include <DirectXCollision.h>
using namespace TriangleTests;

#include "Object2D.h"
#include "Object3D.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include "SceneMgr.h"
#include "Scene.h"
#include "Text2D.h"
#include "cLogMgr.h"
#include "ImageMgr.h"
#include "cUIMgr.h"
#include "SoundMgr.h"
#include "cMapMgr.h"
#include "cMap.h"
#include "cEffectMgr.h"
#include "cMob.h"
#include "cMonsterMgr.h"
#include "cPlayerMgr.h"

#define HR_CHECK if (FAILED(hr)) return hr;

#define HR_CHECK_MSG(message)								\
if	(FAILED(hr))											\
{ 															\
	MessageBoxA(nullptr, message, "오류", MB_OK); 			\
	return hr;												\
}		

#define HR_CHECK_MSG2(message)								\
if	(FAILED(hr))											\
{ 															\
	MessageBoxA(nullptr, message, "오류", MB_OK); 			\
	return nullptr;												\
}

