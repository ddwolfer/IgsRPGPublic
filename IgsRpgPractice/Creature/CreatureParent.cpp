#include "CreatureParent.h"
//
// 閒置不動作
// 
void CreatureParent::ActionIdle() {
	cout << m_name << "\t這回合不動作." << endl;
}
//
// 被攻擊 
//
void CreatureParent::OnHit(int getDamage) {
	cout << m_name << "\t受到了\t" << getDamage << "\t點傷害 " << endl;
	m_Hp -= getDamage;
}
//
// 普通攻擊目標
//
void CreatureParent::NormalAttackHit(CreatureParent* attackTarget) {
	cout << m_name << "\t普通攻擊 " << attackTarget->m_name <<",\t";
	attackTarget->OnHit(m_Atk);
}
//
// 顯示 名字+Hp/HpMax
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
	m_battleAction(E_BattleAction::State_idle){}

CreatureParent::~CreatureParent()
{
}
