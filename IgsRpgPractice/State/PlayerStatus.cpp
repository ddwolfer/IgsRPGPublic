#include "PlayerStatus.h"
// ��ܨ��⪬�A
void PlayerStatus::Update() {
	cout << "[----------���⪬�A----------]" << endl;
	PlayerController::GetPlayer()->ShowStatus();
	cout << "(��J���N���^)" << endl;
	cout << ">";
}
// ���U���Nkey��^
void PlayerStatus::HandleInput() {
	int choose;
	cin >> choose;
	StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
}