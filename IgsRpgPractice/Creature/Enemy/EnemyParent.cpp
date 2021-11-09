#include "EnemyParent.h"

EnemyParent::EnemyParent(
	string inputName,
	int inputHp,
	int inputMana,
	int inputAtk,
	int inputSpeed
) : CreatureParent(inputName, inputHp, inputMana, inputAtk, inputSpeed) {
}
EnemyParent::~EnemyParent()
{
}
void EnemyParent::ShowEnemyHp() {
	cout << m_name << " : " << GetHp() <<endl;
	return;
}