#include "CreatureParent.h"
//
// �Q���� 
//
void CreatureParent::OnHit(int getDamage) {
	cout << m_name << "\t����F\t" << getDamage << "\t�I�ˮ` " << endl;
	m_Hp -= getDamage;
}
//
// ���q�����ؼ�
//
void CreatureParent::NormalAttackHit(CreatureParent* attackTarget) {
	cout << m_name << "\t����\t" << attackTarget->m_name <<",\t";
	attackTarget->OnHit(m_Atk);
}
//
// ��� �W�r+Hp/HpMax
//
void CreatureParent::ShowNameHp() {
	cout << m_name << " " << GetHp() << " / " << GetHpMax() << " Hp" << endl;
	return;
}
CreatureParent::CreatureParent(
	string inputName,
	int inputHp,
	int inputMana,
	int inputAtk,
	int inputSpeed
) : m_name(inputName),
	m_Hp(inputHp),
	m_HpMax(inputHp),
	m_Mana(inputMana),
	m_ManaMax(inputMana),
	m_Atk(inputAtk),
	m_Speed(inputSpeed),
	m_battleAction(E_BattleAction::State_Idle){}

CreatureParent::~CreatureParent()
{
}
