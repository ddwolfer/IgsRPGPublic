#include "BattleController.h"

BattleController* BattleController::m_battleController = nullptr;

BattleController::BattleController() {
	EnemyParent::ResetCountMap();
	m_enemyVec.clear();
	m_attackSort.clear();
	// 隨機生1~3隻
	m_enemyCount = (int)(rand() % 3) + 1;
	// 隨機 史萊姆or哥布林
	for (size_t idx = 0; idx < m_enemyCount; idx++) {
		m_enemyVec.push_back(m_enemyController.CreateEnemy(static_cast<E_Enemy>((int)(rand() % 2))));
	}
	m_battleEndFlag = false;
	m_playerActionTarget = 0;
}
void BattleController::InitBattleController() {
	delete m_battleController;
	m_battleController = new BattleController();
}
BattleController* BattleController::GetBattleController() {
	if (m_battleController == nullptr) {
		m_battleController = new BattleController();
	}
	return m_battleController;
}

//
// 顯示戰鬥資訊
//
void BattleController::ShowBattleInfo() {
	// 顯示 玩家資訊
	        
	cout << "[---------------玩家----------------]" << endl;
	PlayerController::GetPlayer()->ShowNameHp();
	// 顯示 敵人資訊
	cout << "[----------------敵人---------------]" << endl;
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		cout << " (" << idx + 1 << ") ";
		m_enemyVec[idx]->ShowNameHp();
	}
	// 顯示 攻擊順序
	cout << "[-----------------------------------]" << endl;
	cout << "攻擊順序: ";
	for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
		cout << m_attackSort[idx]->GetName();
		if ((idx + 1) < m_attackSort.size()) {
			cout << " -> ";
		}
	}
	cout << endl;
	return;
}

//
// 排攻擊順序
//
void BattleController::SortBattleAction() {
	//初始化
	m_attackSort.clear();
	//加入敵人
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		m_attackSort.push_back(m_enemyVec[idx]);
	}
	//加入玩家
	m_attackSort.push_back(PlayerController::GetPlayer());
	//排序
	sort(m_attackSort.begin(), m_attackSort.end(), [](CreatureParent* Target1, CreatureParent* Target2) {
		return Target1->GetSpeed() > Target2->GetSpeed();
		});

	return;
}
//
// 玩家選擇行動
//
void BattleController::PlayerChooseAction() {
	switch(PlayerController::GetPlayer()->PlayerBattleAction())
	{
		//普通攻擊
	case E_BattleAction::State_normalAttaack:
		PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_normalAttaack);
		break;
		//技能
	case E_BattleAction::State_specialAttack:
		PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_normalAttaack);
		break;
		//逃跑
	case E_BattleAction::State_escape:
		// 隨機逃跑結果 0->成功, 1->失敗
		switch ((int)(rand() % 2)) {
			//逃跑成功 直接return 到下一個State
		case Escape_Success:
			cout << "逃跑成功!" << endl;
			PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_escape);
			m_battleEndFlag = true;
			return;
			break;
			//逃跑失敗
		case Escape_Fail:
			cout << "逃跑失敗 X_X" << endl;
			PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_escape);
			m_battleEndFlag = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return;
}
// 
// 玩家選擇攻擊目標
//
void BattleController::PlayerChooseAttackTarget() {
	// 選擇目標
	m_playerActionTarget = 0;
	cout << "[-----------------------------------]" << endl << endl;
	cout << "選擇攻擊對象 1~" << m_enemyVec.size() << endl;
	while (m_playerActionTarget <= 0 || m_playerActionTarget > m_enemyVec.size()) {
		cout << ">";
		cin >> m_playerActionTarget;
		if (m_playerActionTarget > m_enemyVec.size() || m_playerActionTarget <= 0) {
			cout << "錯誤目標, 重新輸入" << endl;
		}
	}
	
}
// 
// 設定敵人動作
//
void BattleController::SetEnemyBattleAction() {
	cout << "[-----------------------------------]" << endl;
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		// 隨機發呆/普通攻擊
		m_enemyVec[idx]->SetBattleAction(static_cast<E_BattleAction>(rand() % 2));
	}
	return;
}
//
// 執行該生物的動作
//
void BattleController::BattleAction(CreatureParent* inputObj) {
	//
	// 如果玩家死亡就不要再打了
	//
	if (PlayerController::GetPlayer()->GetHp() <= 0) {
		return;
	}

	//
	// 如果生物已經死亡就略過, 回合結束時會把屍體清掉
	//
	if (inputObj->GetHp() <= 0) {
		cout << inputObj->GetName() << "\t已死亡." << endl;
		return;
	}
	//
	// 決定目標 敵人: 打玩家, 玩家: 打指定的目標
	//
	CreatureParent* ActionTarget = nullptr;
	if (inputObj == PlayerController::GetPlayer() ) {
		// 如果目標是 0 代表這回合沒有要攻擊
		if (m_playerActionTarget != 0)
			ActionTarget = m_enemyVec[m_playerActionTarget - 1];
	} else {
		ActionTarget = PlayerController::GetPlayer();
	}
	//
	// 看要做什麼動作
	//
	switch (inputObj->GetBattleAction())
	{
	case E_BattleAction::State_idle:
		inputObj->ActionIdle();
		break;
	case E_BattleAction::State_normalAttaack:
		inputObj->NormalAttackHit(ActionTarget);
		break;
	case E_BattleAction::State_specialAttack:
		inputObj->NormalAttackHit(ActionTarget);
		break;
	case E_BattleAction::State_escape:
		inputObj->ActionIdle();
		break;
	default:
		break;
	}
}
// 
// 戰鬥開始
//
void BattleController::StartBattlePhase() {
	for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
		BattleAction(m_attackSort[idx]);
	}
}
//
// 清掉死掉的地人
//
void BattleController::CleanDeadEnemy() {
	//遇到死掉的enemy (Hp <= 0), 就erase掉
	size_t idx = 0;
	while (idx < m_enemyVec.size()) {
		if (m_enemyVec[idx]->GetHp() <= 0) {
			m_enemyVec.erase(m_enemyVec.begin() + idx);
		}
		else {
			idx++;
		}
	}
}
//
// 確認戰鬥是否結束
//
void BattleController::CheckBattleEnd() {
	// 結束條件1 敵人死光
	if (m_enemyVec.size() <= 0) {
		cout << "[-----------------------------------]" << endl;
		cout << "~~戰鬥勝利~~" << endl;
		m_battleEndFlag = true;
		return;
	}
	// 結束條件2 玩家死了
	if (PlayerController::GetPlayer()->GetHp() <= 0) {
		cout << "[-----------------------------------]" << endl;
		cout << "        " << PlayerController::GetPlayer()->GetName() << "死亡" << endl;
		cout << endl << "[-------------GAME OVER-------------]" << endl << endl;
		m_battleEndFlag = true;
		return;
	}
}