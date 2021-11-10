#include "MenuState.h"

void MenuState::Update() {
	cout << "[----------Menu----------]" << endl;
	cout << "(1)開始遊戲" << endl;
	cout << "(2)退出" << endl;
	cout << ">";
}

void MenuState::HandleInput() {
	int choose;
	cin >> choose;
	switch (choose) {
		// (1)開始遊戲 
	case State_Start:
		StateMachine::GetPageStateMachine()->Change(E_GamePage::selectRole);
		break;
		// (2)退出
	case State_Exit:
		StateMachine::GetPageStateMachine()->Change(E_GamePage::exit);
		break;
	default:
		cout << "錯誤輸入!" << endl;
		break;
	}
}