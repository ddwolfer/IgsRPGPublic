#include "RoleParent.h"

RoleParent::RoleParent(
	string inputName,
	int inputHp,
	int inputMana,
	int inputAtk,
	int inputSpeed
) : CreatureParent(inputName, inputHp, inputMana, inputAtk, inputSpeed) {
}
//
// �԰��ɿ�ܨ���ʧ@
//
E_BattleAction RoleParent::PlayerBattleAction() {
	cout<< "[-----------------------------------]" << endl << endl;
	cout << "��ܧA�����:" << endl;
	cout << "(1) ���q����" << endl;
	cout << "(2) �ޯ�(�٨S���n �ҥH�٬O���q����)" << endl;
	cout << "(3) �k�]" << endl;
	cout << ">";
	int choose;
	cin >> choose;
	return static_cast<E_BattleAction>(choose);
}
//
// ��ܨ��⪬�A
//
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