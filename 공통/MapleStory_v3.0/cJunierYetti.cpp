#include "stdafx.h"
#include "cJunierYetti.h"

cJunierYetti::~cJunierYetti()
{
}

void cJunierYetti::Setting()
{
	m_HP = 150;
	m_MaxHp = 150;
	m_AttackPower = 30;
	m_Exp = 138;


	m_Meso = 3;

	m_pIdle = new cNormalIdle;
	m_pMove = new cNormalMove;
	m_pHit = new cNormalHit;
	m_pDie = new cNormalDie;
	m_pAggro = new cNormalAggro;

	m_pIdle->m_pMob = this;
	m_pMove->m_pMob = this;
	m_pHit->m_pMob = this;
	m_pDie->m_pMob = this;
	m_pAggro->m_pMob = this;
}
