#include "SelectRole.h"
//
// ��ܿ��¾�~�e��
//
void SelectRole::Update() {
	cout << "[----------��ܨ���----------]" << endl;
	cout << "(1)�Ԥh" << endl;
	cout << "(2)�k�v" << endl;
	cout << ">";
}
//
// ��� 1�Ԥh 2�k�v
//
void SelectRole::HandleInput() {
	int choose;
	cin >> choose;
	switch (choose) {
		// (1)�Ԥh 
	case Type_Warrior:
		PlayerController::SetPlayer(new Warrior());
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
		break;
		// (2)�k�v
	case Type_Mage:
		PlayerController::SetPlayer(new Mage());
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
		break;
	default:
		cout << "���~��J!" << endl;
		break;
	}
}