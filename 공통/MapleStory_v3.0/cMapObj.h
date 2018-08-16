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

	// ��Ż��

	int m_ChangeMap = -1;
	int m_PortalID = -1;
	int m_ChangeMapPortalID = -1;

	// �޼ҿ�

	int m_SumOfMoney = 0;
	float m_DelTime = 1.0f;
	bool m_isDeleted = false;

	bool m_Start = true;
	bool m_JumpStart = false;
	float m_StartTime = 0.2f;
	float m_posY = 0.0f;

	// �����ۿ�

	int m_ItemNo;


	// NPC ��
	FUNC m_MouseDownFunc;
	bool m_isNPC = false;


	cMapObj();
	~cMapObj();

	D2D1_POINT_2F GetMapPos()
	{
		m_MapPos = m_Transform.GetPos();		

		return m_MapPos;
	}

};

