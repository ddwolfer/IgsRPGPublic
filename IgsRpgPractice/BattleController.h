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
	// ��ܾ԰���T
	//
	void ShowBattleInfo();
	//
	// �Ƨ�������
	//
	void SortBattleAction();
	//
	// ���a��ܦ��
	//
	void PlayerChooseAction();
	// 
	// ���a��ܧ����ؼ�
	//
	void PlayerChooseAttackTarget();
	//
	// �]�w�ĤH�ʧ@
	//
	void SetEnemyBattleAction();
	//
	// �԰��ʧ@
	//
	void BattleAction(CreatureParent* inputCreature);
	//
	// �԰��}�l
	//
	void StartBattlePhase();
	//
	// �M���������a�H
	//
	void CleanDeadEnemy();
	//
	// �T�{�԰��O�_����
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
