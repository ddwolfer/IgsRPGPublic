#ifndef _BATTLE_CONTROLLER_
#define _BATTLE_CONTROLLER_
#include "Creature/Enemy/EnemyController.h"
#include "Creature/Player/PlayerController.h"

#include <algorithm>
#include <vector>

using namespace std;

class BattleController
{
public:
	//
	// 顯示戰鬥資訊
	//
	void ShowBattleInfo();
	//
	// 排攻擊順序
	//
	void SortBattleAction();
	//
	// 玩家選擇行動
	//
	void PlayerChooseAction();
	// 
	// 玩家選擇攻擊目標
	//
	void PlayerChooseAttackTarget();
	//
	// 設定敵人動作
	//
	void SetEnemyBattleAction();
	//
	// 戰鬥動作
	//
	void BattleAction(CreatureParent* inputCreature);
	//
	// 戰鬥開始
	//
	void StartBattlePhase();
	//
	// 清掉死掉的地人
	//
	void CleanDeadEnemy();
	//
	// 確認戰鬥是否結束
	//
	void CheckBattleEnd();

	int						GetEnemyCount()			{ return m_enemyCount; }
	int						GetPlayerActionTarget()	{ return m_playerActionTarget; }
	vector<EnemyParent*>	GetEnemyVec()			{ return m_enemyVec; }
	vector<CreatureParent*>	GetAttackSort()			{ return m_attackSort; }
	bool					GetEndFlag()			{ return m_battleEndFlag;	}

	void SetPlayerActionTarget(int inputTarget)				{ m_playerActionTarget = inputTarget; }
	void SetEnemyVec(vector<EnemyParent*> inputVec)			{ m_enemyVec = inputVec; }
	void SetAttackSort(vector<CreatureParent*> inputVec)	{ m_attackSort = inputVec; }

	static void InitBattleController();
	static BattleController* GetBattleController();
	
private:
	BattleController();
	~BattleController() {}

	static BattleController*	m_battleController;
	bool						m_battleEndFlag;
	int							m_playerActionTarget;
	int							m_enemyCount;
	EnemyController				m_enemyController;
	vector<EnemyParent*>		m_enemyVec;
	vector<CreatureParent*>		m_attackSort;
};



#endif // !_BATTLE_CONTROLLER_
