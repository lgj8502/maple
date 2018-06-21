#pragma once
#include "stdafx.h"

template <typename T>
class TemplateSingleton
{
	static T *m_Instance;

public:
	static T *GetInstance();

	void Release();
};

template <typename T>
T *TemplateSingleton<T>::m_Instance = nullptr;


template <typename T>
T *TemplateSingleton<T>::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new T;
	}

	return m_Instance;
}

template <typename T>
void TemplateSingleton<T>::Release()
{
	delete m_Instance;
	m_Instance = nullptr;
}

#define BASESET(classname)		\
private:						\
	friend TemplateSingleton;	\
	classname() = default;	