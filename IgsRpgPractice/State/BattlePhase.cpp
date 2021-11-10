#include "BattlePhase.h"
//
// �԰��y�{ : �M�w��������-> ���a�M�w�ʧ@ -> �]�w�ĤH�ʧ@ -> �}�l�԰� -> �ˬd�������A
//
void BattlePhase::Update() {
	BattleController::GetBattleController()->SortBattleAction();
	BattleController::GetBattleController()->ShowBattleInfo();
	BattleController::GetBattleController()->PlayerChooseAction();
	// �p�G�O�k�]�N���ο�ܥؼ�
	if (PlayerController::GetPlayer()->GetBattleAction() != E_BattleAction::State_escape) {
		BattleController::GetBattleController()->PlayerChooseAttackTarget();
	}
	// �p�G�k�]���\, EndFlag �| = true
	if (BattleController::GetBattleController()->GetEndFlag()) { return; }
	BattleController::GetBattleController()->SetEnemyBattleAction();
	BattleController::GetBattleController()->StartBattlePhase();
	BattleController::GetBattleController()->CleanDeadEnemy();
	BattleController::GetBattleController()->CheckBattleEnd();
}
//
// �԰��}�l�e�A�ͦ��@�w�ƶq�ĤH
//
void BattlePhase::Enter() {
	// ���s�ͦ��@���s���Ǫ�
	BattleController::GetBattleController()->InitBattleController();
}

void BattlePhase::HandleInput() {
	cout << "[-----------------------------------]" << endl;
	cout << "(���U���N���~��)" << endl;
	cout << ">";
	int nextRound;
	cin >> nextRound;

	if (PlayerController::GetPlayer()->GetHp() <= 0) {
		StateMachine::GetPageStateMachine()->Change(E_GamePage::mainMenu);
		return;
	}

	if (BattleController::GetBattleController()->GetEndFlag()) {
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
		return;
	}

}