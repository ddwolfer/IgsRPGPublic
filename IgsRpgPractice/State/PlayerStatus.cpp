#include "PlayerStatus.h"
// 顯示角色狀態
void PlayerStatus::Update() {
	cout << "[----------角色狀態----------]" << endl;
	PlayerController::GetPlayer()->ShowStatus();
	cout << "(輸入任意鍵返回)" << endl;
	cout << ">";
}
// 按下任意key返回
void PlayerStatus::HandleInput() {
	int choose;
	cin >> choose;
	StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
}