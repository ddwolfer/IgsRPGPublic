#ifndef _PLAYER_STEP_
#define _PLAYER_STEP_
#include "StateMachine.h"

//
// �C�����q 
// 1) �e�i(�԰�) 
// 2) �ݨ��⪬�A���
//
class PlayerStep : public EmptyState
{
public:
	void Update() {
		cout << "[----------�M�w�U�@�B----------]" << endl;
		cout << "(1)�e�i" << endl;
		cout << "(2)���⪬�A" << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)�e�i 
		case 1:
			cout << "�٨S��" << endl;
			break;
			// (2)�ݨ��⪬�A���
		case 2:
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStatus);
			break;
		default:
			cout << "���~��J!" << endl;
			break;
		}
	}
	void Enter() {}
	void Exit() {}

	PlayerStep() {}
	~PlayerStep() {}
};
#endif // !_PLAYER_STEP_
