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
// 戰鬥時選擇角色動作
//
E_BattleAction RoleParent::PlayerBattleAction() {
	int choose;
	choose = 0;
	cout<< "[-----------------------------------]" << endl << endl;
	cout << "選擇你的行動:" << endl;
	cout << "(1) 普通攻擊" << endl;
	cout << "(2) 技能(還沒做好 所以還是普通攻擊)" << endl;
	cout << "(3) 逃跑" << endl;
	while (choose <= 0 || choose > 3) {		
		cout << ">";
		cin >> choose;
		if (choose <= 0 || choose > 3) {
			cout << "錯誤選項, 重新輸入" << endl;
		}
	}
	
	return static_cast<E_BattleAction>(choose);
}
//
// 顯示角色狀態
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