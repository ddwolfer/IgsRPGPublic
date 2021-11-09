#include "RoleParent.h"

RoleParent::RoleParent(
	string inputName,
	int inputHp,
	int inputMana,
	int inputAtk,
	int inputSpeed
) : CreatureParent(inputName, inputHp, inputMana, inputAtk, inputSpeed) {
}

void RoleParent::ShowStatus() {
	cout << "--------------------------------------" << endl;
	cout << "Name: " << GetName() << endl;
	cout << "Hp  : " << GetHp() << " / " << GetHpMax() << endl;
	cout << "Mp  : " << GetMana() << " / " << GetManaMax() << endl;
	cout << "Atk : " << GetAtk() << endl;
	cout << "Spd : " << GetSpeed() << endl;
	cout << "--------------------------------------" << endl;
	return;
}