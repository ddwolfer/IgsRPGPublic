#include "BattlePhase.h"
//
// 戰鬥流程 : 決定攻擊順序-> 玩家決定動作 -> 設定敵人動作 -> 開始戰鬥 -> 檢查結束狀態
//
void BattlePhase::Update() {
	BattleController::GetBattleController()->SortBattleAction();
	BattleController::GetBattleController()->ShowBattleInfo();
	BattleController::GetBattleController()->PlayerChooseAction();
	// 如果是逃跑就不用選擇目標
	if (PlayerController::GetPlayer()->GetBattleAction() != E_BattleAction::State_escape) {
		BattleController::GetBattleController()->PlayerChooseAttackTarget();
	}
	// 如果逃跑成功, EndFlag 會 = true
	if (BattleController::GetBattleController()->GetEndFlag()) { return; }
	BattleController::GetBattleController()->SetEnemyBattleAction();
	BattleController::GetBattleController()->StartBattlePhase();
	BattleController::GetBattleController()->CleanDeadEnemy();
	BattleController::GetBattleController()->CheckBattleEnd();
}
//
// 戰鬥開始前，生成一定數量敵人
//
void BattlePhase::Enter() {
	// 重新生成一輪新的怪物
	BattleController::GetBattleController()->InitBattleController();
}

void BattlePhase::HandleInput() {
	cout << "[-----------------------------------]" << endl;
	cout << "(按下任意鍵繼續)" << endl;
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