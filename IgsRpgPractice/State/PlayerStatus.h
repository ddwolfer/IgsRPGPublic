#ifndef _PLAYER_STATUS_
#define _PLAYER_STATUS_
#include "StateMachine.h"
//
// 角色狀態 
// 1) 返回
//
class PlayerStatus : public EmptyState
{
public:
	void Update() {
		cout << "[----------角色狀態----------]" << endl;
		cout << "晚點補" << endl;
		cout << "------------------------------" << endl;
		cout << "(1)返回" << endl;

	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)前進 
		case 1:
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
			break;
		default:
			cout << "錯誤輸入!" << endl;
			break;
		}
	}

	void Enter() {}
	void Exit() {}

	PlayerStatus() {}
	~PlayerStatus() {}
};

#endif // !_PLAYER_STATUS_