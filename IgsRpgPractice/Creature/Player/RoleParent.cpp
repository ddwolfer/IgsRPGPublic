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
	int choose;
	choose = 0;
	cout<< "[-----------------------------------]" << endl << endl;
	cout << "��ܧA�����:" << endl;
	cout << "(1) ���q����" << endl;
	cout << "(2) �ޯ�(�٨S���n �ҥH�٬O���q����)" << endl;
	cout << "(3) �k�]" << endl;
	while (choose <= 0 || choose > 3) {		
		cout << ">";
		cin >> choose;
		if (choose <= 0 || choose > 3) {
			cout << "���~�ﶵ, ���s��J" << endl;
		}
	}
	
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