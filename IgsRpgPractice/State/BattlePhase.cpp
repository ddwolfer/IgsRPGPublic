#include "BattlePhase.h"
//
// 戰鬥流程 : 決定攻擊順序->
//
void BattlePhase::Update() {
	// 排攻擊順序
	m_attackSort.clear();
	//加入敵人
	if (m_attackSort.size() == 0) {
		for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
			m_attackSort.push_back(m_enemyVec[idx]);
		}
	}
	//加入玩家
	m_attackSort.push_back(PlayerController::GetPlayer());
	//排序
	sort(m_attackSort.begin(), m_attackSort.end(), [](CreatureParent* Target1, CreatureParent* Target2) {
		return Target1->GetSpeed() > Target2->GetSpeed();
		});
	// 顯示 玩家資訊
	cout << "[----------玩家----------]" << endl;
	PlayerController::GetPlayer()->ShowNameHp();
	// 顯示 敵人資訊
	cout << "[----------敵人----------]" << endl;
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		cout << " (" << idx + 1 << ") ";
		m_enemyVec[idx]->ShowNameHp();
	}
	// 顯示 攻擊順序
	cout << "[------------------------]" << endl << endl;
	cout << "攻擊順序: ";
	for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
		cout << m_attackSort[idx]->GetName();
		if ((idx + 1) < m_attackSort.size()) {
			cout << " -> ";
		}
	}
	cout << endl << endl;
	// 選擇行動
	switch (PlayerController::GetPlayer()->PlayerBattleAction())
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
			m_battleEndFlag = true;
			return;
			break;
			//逃跑失敗
		case Escape_Fail:
			cout << "逃跑失敗 X_X" << endl;
			PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_Idle);
			m_battleEndFlag = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	// 選擇目標
	int chooseAtkTarget;
	cout << "[------------------------]" << endl << endl;
	cout << "選擇攻擊對象 1~" << m_enemyVec.size() << endl;
	cout << ">";
	cin >> chooseAtkTarget;

	// 設定敵人動作
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		// 隨機發呆/普通攻擊
		m_enemyVec[idx]->SetBattleAction(static_cast<E_BattleAction>(rand()%2));
	}

	//戰鬥開始
	cout << "[------------------------]" << endl;
	for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
		if (m_attackSort[idx] == PlayerController::GetPlayer()) {
			m_attackSort[idx]->NormalAttackHit(m_enemyVec[chooseAtkTarget-1]);
		} else {
			m_attackSort[idx]->NormalAttackHit(PlayerController::GetPlayer());
		}
	}
	// 戰鬥結束判斷
	size_t idx = 0;
	while (idx < m_enemyVec.size()) {
		if (m_enemyVec[idx]->GetHp() <= 0) {
			m_enemyVec.erase(m_enemyVec.begin() + idx);
		} else {
			idx++;
		}
	}
	if (m_enemyVec.size() <= 0) {
		cout << "[------------------------]" << endl;
		cout << "~~戰鬥勝利~~" << endl;
		m_battleEndFlag = true;
		return;
	}
}
//
// 戰鬥開始前，生成一定數量敵人
//
void BattlePhase::Enter() {
	m_enemyVec.clear();
	m_attackSort.clear();
	// 隨機生1~3隻
	int enemyCount = (int)(rand() % 3) + 1;
	// 隨機 史萊姆or哥布林
	for (size_t idx = 0; idx < enemyCount; idx++) {
		m_enemyVec.push_back(m_enemyController.CreateEnemy(static_cast<E_Enemy>((int)(rand() % 2))));
	}
}

void BattlePhase::HandleInput() {
	cout << "[------------------------]" << endl;
	cout << "(按下任意鍵繼續)" << endl;
	cout << ">";
	int nextRound;
	cin >> nextRound;
	//
	// 逃跑成功 or 戰鬥結束
	//
	if (m_battleEndFlag) {
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
		return;
	}
}