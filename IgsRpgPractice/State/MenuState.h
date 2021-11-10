#ifndef _MENU_STATE_
#define _MENU_STATE_

#include "StateMachine.h"
enum E_MenuSelect
{
	State_Start = 1,
	State_Exit = 2
};
//
// 主頁面 
// (1)開始遊戲 
// (2)退出
//
class MenuState : public EmptyState
{
public:
	void Update();		// 顯示主頁面畫面
	void HandleInput(); // 輸入並跳轉頁面
	void Enter() {}
	void Exit() {}

	MenuState() {}
	~MenuState() {}
};
#endif // !_MENU_STATE_