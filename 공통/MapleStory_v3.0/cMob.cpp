#include "stdafx.h"
#include "cMob.h"


void cMob::HPBarRender()
{
	if (m_isActiveHPBar == true)
	{
		for (int i = 0; i < 3; i++)
		{
			m_HPBar[i].Render();
		}
	}
}

void cMob::LeftWalk(float _DelayTime)
{
	if (m_Transform.GetPos().x < m_minX)
	{
		m_dir = 1;
		return;
	}

	m_Transform.m_velocityX = -m_MoveSpeed;
	m_Transform.VelocityTransX(_DelayTime);
	

}

void cMob::RightWalk(float _DelayTime)
{
	if (m_Transform.GetPos().x > m_maxX)
	{
		m_dir = 0;
		return;
	}

	m_Transform.m_velocityX = m_MoveSpeed;
	m_Transform.VelocityTransX(_DelayTime);
}

void cMob::Die()
{
	MOB_MGR->DelMob(this);

	m_isDead = true;
}


void cMob::RecvList(map<wstring, ImgInfo> _ImgList)
{
	map<wstring, ImgInfo>::iterator Iter;

	vector<wstring> wstr;	

	for (Iter = _ImgList.begin(); Iter != _ImgList.end(); Iter++)
	{
		wstr.push_back(Iter->first);

		m_Renderer.AddBitmap_Bottom(Iter->second.m_Bitmap);
	}

	int Idle = 0;
	int Move = 0;
	int Hit = 0;
	int Die = 0;
	int Fly = 0;
	int Attack = 0;

	int current = 0;

	for (auto &i : wstr)
	{
		wchar_t wbuf[256] = L"";

		wcscpy_s(wbuf, i.c_str());

		switch (wbuf[0])
		{
		case L'a': Attack++; break;
		case L'd': Die++; break;
		case L'f': Fly++; break;
		case L'h': Hit++; break;
		case L'm': Move++; break;
		case L's': Idle++; break;		

		default:
			break;
		}
	}

	if (Attack != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_ATTACK, current, Attack - 1, 0.2f);

		current += Attack;
	}

	if (Die != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_DIE, current, Die - 1, 0.5f);

		current += Die;
	}

	if (Fly != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_JUMP, current, current + Fly - 1, 0.2f);

		current += Fly;
	}

	if (Hit != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_HIT, current, current+ Hit - 1, 0.5f);

		current += Hit;
	}

	if (Move != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_MOVE, current, current + Move - 1, 0.2f);
		m_Renderer.AddAnimation_const(MOBSTATE_AGGRO, current, current + Move - 1, 0.2f);

		current += Move;
	}

	if (Idle != 0)
	{
		m_Renderer.AddAnimation_const(MOBSTATE_IDLE, current, current + Idle - 1, 0.5f);

		current = +Idle;
	}



	






	



}




