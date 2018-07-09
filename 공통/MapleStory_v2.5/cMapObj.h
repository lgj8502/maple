#pragma once



class cMapObj : public Object2D
{

private:

	D2D1_POINT_2F m_MapPos = {};

public:

	bool m_CrashCheck = false;
	bool m_isBaseTile = false;

	bool m_isLadderTop = false;
	cMapObj *m_LadderTop = nullptr;

	// Æ÷Å»¿ë

	int m_ChangeMap = -1;
	int m_PortalID = -1;
	int m_ChangeMapPortalID = -1;


	cMapObj();
	~cMapObj();

	D2D1_POINT_2F GetMapPos()
	{
		m_MapPos = m_Transform.GetPos();		

		return m_MapPos;
	}

};

