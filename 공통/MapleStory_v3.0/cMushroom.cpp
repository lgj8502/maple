#include "stdafx.h"
#include "cMushroom.h"



cMushroom::~cMushroom()
{
}

void cMushroom::Setting()
{
	m_HP = 150;
	m_MaxHp = 150;
	m_AttackPower = 30;
	m_Exp = 50;

	m_Meso = 2;

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



