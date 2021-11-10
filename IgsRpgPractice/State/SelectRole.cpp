#include "SelectRole.h"
//
// 顯示選擇職業畫面
//
void SelectRole::Update() {
	cout << "[----------選擇角色----------]" << endl;
	cout << "(1)戰士" << endl;
	cout << "(2)法師" << endl;
	cout << ">";
}
//
// 選擇 1戰士 2法師
//
void SelectRole::HandleInput() {
	int choose;
	cin >> choose;
	switch (choose) {
		// (1)戰士 
	case Type_Warrior:
		PlayerController::SetPlayer(new Warrior());
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
		break;
		// (2)法師
	case Type_Mage:
		PlayerController::SetPlayer(new Mage());
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
		break;
	default:
		cout << "錯誤輸入!" << endl;
		break;
	}
}