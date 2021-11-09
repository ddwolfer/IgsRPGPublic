#ifndef _MENU_STATE_
#define _MENU_STATE_

#include "StateMachine.h"
enum E_ChooseRole
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
	void Update() {
		cout << "[----------Menu----------]" << endl;
		cout << "(1)開始遊戲" << endl;
		cout << "(2)退出" << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)開始遊戲 
		case State_Start:
			StateMachine::GetStateMachine()->Change(E_GamePage::selectRole);
			break;
			// (2)退出
		case State_Exit:
			StateMachine::GetStateMachine()->Change(E_GamePage::exit);
			break;

		default:
			cout << "錯誤輸入!" << endl;
			break;
		}
	}
	void Enter() {

	}
	void Exit() {}

	MenuState() {}
	~MenuState() {}
};
#endif // !_MENU_STATE_