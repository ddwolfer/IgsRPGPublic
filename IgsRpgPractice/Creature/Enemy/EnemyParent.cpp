#include "EnemyParent.h"

map<string, int> EnemyParent::m_countEachTypeEnemy = {};

int EnemyParent::AddEnemyInCountMap(string inputName) {
	if (m_countEachTypeEnemy.find(inputName) == m_countEachTypeEnemy.end()) {
		m_countEachTypeEnemy[inputName] = 1;
	} else {
		m_countEachTypeEnemy[inputName] += 1;
	}
	//cout << inputName << "現在有 " << m_countEachTypeEnemy[inputName] << " 個" << endl;
	return m_countEachTypeEnemy[inputName];
}

void EnemyParent::ResetCountMap() {
	m_countEachTypeEnemy.clear();
}

EnemyParent::EnemyParent(
	string inputName,
	int inputHp,
	int inputMana,
	int inputAtk,
	int inputSpeed
) : CreatureParent(inputName, inputHp, inputMana, inputAtk, inputSpeed) {
	// 幫敵人做編號(每種敵人分開算)
	m_name = m_name + to_string(AddEnemyInCountMap(inputName));
}
EnemyParent::~EnemyParent()
{
}