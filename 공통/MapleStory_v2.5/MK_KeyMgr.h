#pragma once

#include <Windows.h>

/*
	네임스페이스

	사용법

	이름공간::함수 or 변수

	특징

	같은 이름 공간안에 있으면 사용이 가능하다.
*/

namespace MK_API
{
	//	키 매니저 초기화
	VOID	InitKeyMgr(VOID);

	//	포커스 확인 및 설정
	BOOL	GetFocus(VOID);
	VOID	SetFocus(BOOL bFocus);

	//	지연 키 눌림에 사용되는 기준 시간 업데이트
	VOID	TickTimeUpdate(VOID);

	//	키 눌림 체크
	BOOL	StayKeyDown( INT nKey );

	//	지연 키 눌림 체크 ( 일정 시간 간격으로 눌리는 것 )
	BOOL	StayKeyDown( INT nKey, DWORD dwDelay );

	//	한번 눌림
	BOOL	OnceKeyDown( INT nKey );

	//	한번 뗌
	BOOL	OnceKeyUp( INT nKey );

	//	토글키 확인
	BOOL	IsToggleKey( INT nKey );
}