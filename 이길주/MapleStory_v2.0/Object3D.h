#pragma once

#include "Transform3D.h"
#include "RenderObject3D.h"

class Object3D
{
public:

	Transform3D		m_Transform;
	RenderObject3D	m_RenderObject;
	
	float			m_Dist = 0.0f;

	Object3D();
	~Object3D();

	void	Update(float _DelayTime);
};

