#ifndef _SELECT_ROLE_
#define _SELECT_ROLE_
#include "StateMachine.h"
#include "../Creature/Player/PlayerController.h"

enum E_ChooseRole
{
	Type_Warrior = 1,
	Type_Mage = 2
};
//
// ��ܨ��� 
// 1) �Ԥh 
// 2) �k�v
//

class SelectRole : public EmptyState
{
public:
	void Update() {
		cout << "[----------��ܨ���----------]" << endl;
		cout << "(1)�Ԥh" << endl;
		cout << "(2)�k�v" << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)�Ԥh 
		case Type_Warrior:
			PlayerController::SetPlayer(new Warrior());
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
			break;
			// (2)�k�v
		case Type_Mage:
			PlayerController::SetPlayer(new Mage());
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
			break;
		default:
			cout << "���~��J!" << endl;
			break;
		}
	}
	void Enter() {}
	void Exit() {}

	SelectRole() {}
	~SelectRole() {}
};

#endif // !_SELECT_CH_