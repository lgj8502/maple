#pragma once

#include <Windows.h>

/*
	���ӽ����̽�

	����

	�̸�����::�Լ� or ����

	Ư¡

	���� �̸� �����ȿ� ������ ����� �����ϴ�.
*/

namespace MK_API
{
	//	Ű �Ŵ��� �ʱ�ȭ
	VOID	InitKeyMgr(VOID);

	//	��Ŀ�� Ȯ�� �� ����
	BOOL	GetFocus(VOID);
	VOID	SetFocus(BOOL bFocus);

	//	���� Ű ������ ���Ǵ� ���� �ð� ������Ʈ
	VOID	TickTimeUpdate(VOID);

	//	Ű ���� üũ
	BOOL	StayKeyDown( INT nKey );

	//	���� Ű ���� üũ ( ���� �ð� �������� ������ �� )
	BOOL	StayKeyDown( INT nKey, DWORD dwDelay );

	//	�ѹ� ����
	BOOL	OnceKeyDown( INT nKey );

	//	�ѹ� ��
	BOOL	OnceKeyUp( INT nKey );

	//	���Ű Ȯ��
	BOOL	IsToggleKey( INT nKey );
}