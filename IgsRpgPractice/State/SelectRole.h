#ifndef _SELECT_ROLE_
#define _SELECT_ROLE_
#include "StateMachine.h"
//
// ��ܨ��� 
// 1) �Ԥh 
// 2) �k�v
//
class SelectRole : public EmptyState
{
public:
	void Update() {
		cout << "[----------��ܨ���----------]" << endl;
		cout << "(1)�Ԥh" << endl;
		cout << "(2)�k�v" << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)�Ԥh 
		case 1:
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
			break;
			// (2)�k�v
		case 2:
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
			break;

		default:
			cout << "���~��J!" << endl;
			break;
		}
	}
	void Enter() {}
	void Exit() {}

	SelectRole() {}
	~SelectRole() {}
};

#endif // !_SELECT_CH_