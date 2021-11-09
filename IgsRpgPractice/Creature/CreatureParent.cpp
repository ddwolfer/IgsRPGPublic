#include "CreatureParent.h"

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
	m_Speed(inputSpeed) {}

CreatureParent::~CreatureParent()
{
}
