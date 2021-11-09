#ifndef _PLAYER_STATUS_
#define _PLAYER_STATUS_

#include "StateMachine.h"
#include "../Creature/Player/PlayerController.h"

using namespace std;

//
// ���⪬�A 
// 1) ��^
//
class PlayerStatus : public EmptyState
{
public:
	void Update() {
		cout << "[----------���⪬�A----------]" << endl;
		PlayerController::GetPlayer()->ShowStatus();
		cout << "(���N���^)" << endl;

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