#ifndef _PLAYER_STATUS_
#define _PLAYER_STATUS_
#include "StateMachine.h"
//
// ���⪬�A 
// 1) ��^
//
class PlayerStatus : public EmptyState
{
public:
	void Update() {
		cout << "[----------���⪬�A----------]" << endl;
		cout << "���I��" << endl;
		cout << "------------------------------" << endl;
		cout << "(1)��^" << endl;

	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)�e�i 
		case 1:
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
			break;
		default:
			cout << "���~��J!" << endl;
			break;
		}
	}

	void Enter() {}
	void Exit() {}

	PlayerStatus() {}
	~PlayerStatus() {}
};

#endif // !_PLAYER_STATUS_