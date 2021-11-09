#ifndef _SELECT_ROLE_
#define _SELECT_ROLE_
#include "StateMachine.h"
//
// 選擇角色 
// 1) 戰士 
// 2) 法師
//
class SelectRole : public EmptyState
{
public:
	void Update() {
		cout << "[----------選擇角色----------]" << endl;
		cout << "(1)戰士" << endl;
		cout << "(2)法師" << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
		switch (choose) {
			// (1)戰士 
		case 1:
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
			break;
			// (2)法師
		case 2:
			StateMachine::GetStateMachine()->Change(E_GamePage::playerStep);
			break;

		default:
			cout << "錯誤輸入!" << endl;
			break;
		}
	}
	void Enter() {}
	void Exit() {}

	SelectRole() {}
	~SelectRole() {}
};

#endif // !_SELECT_CH_