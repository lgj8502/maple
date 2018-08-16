#include "stdafx.h"
#include "cMurucoon.h"

cMurucoon::~cMurucoon()
{
}

void cMurucoon::Setting()
{
	m_HP = 500;
	m_MaxHp = 500;
	m_AttackPower = 60;
	m_Exp = 257;

	m_Meso = 6;

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



