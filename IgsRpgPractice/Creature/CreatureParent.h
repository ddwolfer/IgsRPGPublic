#ifndef _CREATURE_
#define _CREATURE_

#include <string>
#include <iostream>

using namespace std;

enum class E_BattleAction {
	State_Idle = 0,
	State_normalAttaack = 1,
	State_specialAttack = 2,
	State_escape = 3
};
enum E_BattleEscape {
	Escape_Success = 0,
	Escape_Fail = 1
};

class CreatureParent
{
public:
	int GetHp()			{ return m_Hp; }
	int GetHpMax()		{ return m_HpMax; }
	int GetMana()		{ return m_Mana; }
	int GetManaMax()	{ return m_ManaMax; }
	int GetAtk()		{ return m_Atk; }
	int GetSpeed()		{ return m_Speed; }
	string GetName()    { return m_name; }
	E_BattleAction GetBattleAction() { return m_battleAction; }

	void SetHp(int inputHp)				{ m_Hp = inputHp; }
	void SetHpMax(int inputHpM)			{ m_HpMax = inputHpM; }
	void SetMana(int inputMana)			{ m_Mana = inputMana; }
	void SetManaMax(int inputManaM)		{ m_Mana = inputManaM; }
	void SetAtk(int inputAtk)			{ m_Atk = inputAtk; }
	void SetSpeed(int inputSpeed)		{ m_Speed = inputSpeed; }
	void SetRoleName(string inputName)	{ m_name = inputName; }
	void SetBattleAction(E_BattleAction inputAction) { m_battleAction = inputAction; }

	//
	// ��� �W�r+Hp/HpMax
	//
	void ShowNameHp();
	//
	// ������Function
	//
	void OnHit(int getDamage); // �Q���� 
	void NormalAttackHit(CreatureParent* attackTarget); // ���q�����ؼ�

	CreatureParent(
		string inputName,
		int inputHp = 1,
		int inputMana = 1,
		int inputAtk = 1,
		int inputSpeed = 1
	);
	~CreatureParent();

protected:
	string m_name;
	int m_HpMax;
	int m_Hp;
	int m_ManaMax;
	int m_Mana;
	int m_Atk;
	int m_Speed;
	E_BattleAction m_battleAction;
};
#endif