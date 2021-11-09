#ifndef _PLAYER_STATUS_
#define _PLAYER_STATUS_

#include "StateMachine.h"
#include "../Creature/Player/PlayerController.h"

using namespace std;

//
// 角色狀態 
// 1) 返回
//
class PlayerStatus : public EmptyState
{
public:
	void Update() {
		cout << "[----------角色狀態----------]" << endl;
		PlayerController::GetPlayer()->ShowStatus();
		cout << "(任意鍵返回)" << endl;

	}
	void HandleInput() {
		int choose;
		cin >> choose;
		StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
	}

	void Enter() {}
	void Exit() {}

	PlayerStatus() {}
	~PlayerStatus() {}
};

#endif // !_PLAYER_STATUS_