#include "stdafx.h"
#include "TEST.h"


TEST::TEST()
{
	m_Renderer.AddBitmap(L"ServerMain");

	m_Renderer.SetImgRT({ 0,0,1200,800 });
}


TEST::~TEST()
{
}
