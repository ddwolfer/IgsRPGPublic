#ifndef _MENU_STATE_
#define _MENU_STATE_

#include "StateMachine.h"
enum E_ChooseRole
{
	State_Start = 1,
	State_Exit = 2
};

//
// �D���� 
// (1)�}�l�C�� 
// (2)�h�X
//
class MenuState : public EmptyState
{
public:
	void Update() {
		cout << "[----------Menu----------]" << endl;
		cout << "(1)�}�l�C��" << endl;
		cout << "(2)�h�X" << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)�}�l�C�� 
		case State_Start:
			StateMachine::GetStateMachine()->Change(E_GamePage::selectRole);
			break;
			// (2)�h�X
		case State_Exit:
			StateMachine::GetStateMachine()->Change(E_GamePage::exit);
			break;

		default:
			cout << "���~��J!" << endl;
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