#include "PlayerStep.h"
//
// ��ܿ�ܵe��
//
void PlayerStep::Update() {
	cout << "[----------�M�w�U�@�B----------]" << endl;
	cout << "(1)�e�i" << endl;
	cout << "(2)���⪬�A" << endl;
	cout << ">";
}
//
// ��ܨðʧ@
//
void PlayerStep::HandleInput() {
	int choose;
	cin >> choose;
	switch (choose) {
		// (1)�e�i 
	case State_nextBattle:
		StateMachine::GetPageStateMachine()->Change(E_GamePage::battle);
		break;
		// (2)�ݨ��⪬�A���
	case State_showPlayerStatus:
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStatus);
		break;
	default:
		cout << "���~��J!" << endl;
		break;
	}
}