#ifndef _PLAYER_STEP_
#define _PLAYER_STEP_
#include "StateMachine.h"

//
// 遊戲階段 
// 1) 前進(戰鬥) 
// 2) 看角色狀態欄位
//
class PlayerStep : public EmptyState
{
public:
	void Update() {
		cout << "[----------決定下一步----------]" << endl;
		cout << "(1)前進" << endl;
		cout << "(2)角色狀態" << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)前進 
		case 1:
			cout << "還沒做" << endl;
			break;
			// (2)看角色狀態欄位
		case 2:
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStatus);
			break;
		default:
			cout << "錯誤輸入!" << endl;
			break;
		}
	}
	void Enter() {}
	void Exit() {}

	PlayerStep() {}
	~PlayerStep() {}
};
#endif // !_PLAYER_STEP_
