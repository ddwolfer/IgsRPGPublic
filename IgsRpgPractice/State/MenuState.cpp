#include "MenuState.h"

void MenuState::Update() {
	cout << "[----------Menu----------]" << endl;
	cout << "(1)�}�l�C��" << endl;
	cout << "(2)�h�X" << endl;
	cout << ">";
}

void MenuState::HandleInput() {
	int choose;
	cin >> choose;
	switch (choose) {
		// (1)�}�l�C�� 
	case State_Start:
		StateMachine::GetPageStateMachine()->Change(E_GamePage::selectRole);
		break;
		// (2)�h�X
	case State_Exit:
		StateMachine::GetPageStateMachine()->Change(E_GamePage::exit);
		break;
	default:
		cout << "���~��J!" << endl;
		break;
	}
}