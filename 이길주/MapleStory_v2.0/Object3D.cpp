#include "stdafx.h"
#include "Object3D.h"


Object3D::Object3D()
{
}


Object3D::~Object3D()
{
}

void Object3D::Update(float _DelayTime)
{
	m_Transform.UpdateMatrix();
}

