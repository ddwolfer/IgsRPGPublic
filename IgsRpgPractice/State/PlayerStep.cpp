#include "PlayerStep.h"
//
// 顯示選擇畫面
//
void PlayerStep::Update() {
	cout << "[----------決定下一步----------]" << endl;
	cout << "(1)前進" << endl;
	cout << "(2)角色狀態" << endl;
	cout << ">";
}
//
// 選擇並動作
//
void PlayerStep::HandleInput() {
	int choose;
	cin >> choose;
	switch (choose) {
		// (1)前進 
	case State_nextBattle:
		StateMachine::GetPageStateMachine()->Change(E_GamePage::battle);
		break;
		// (2)看角色狀態欄位
	case State_showPlayerStatus:
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStatus);
		break;
	default:
		cout << "錯誤輸入!" << endl;
		break;
	}
}