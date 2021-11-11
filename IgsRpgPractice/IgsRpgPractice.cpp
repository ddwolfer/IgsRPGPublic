// IgsRpgPractice.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "IgsRpgPractice.h"

int main()
{
	srand(time(0));

	StateMachine*		pageStateMachine= StateMachine::GetPageStateMachine();

	pageStateMachine->AddState(E_GamePage::exit, new ExitState());
	pageStateMachine->AddState(E_GamePage::mainMenu, new MenuState());
	pageStateMachine->AddState(E_GamePage::selectRole, new SelectRole());
	pageStateMachine->AddState(E_GamePage::playerStep, new PlayerStep());
	pageStateMachine->AddState(E_GamePage::playerStatus, new PlayerStatus());
	pageStateMachine->AddState(E_GamePage::battle, new BattlePhase());

	pageStateMachine->Change(E_GamePage::mainMenu);

	while (true) {
		// clear CMD 畫面
		cout << "\033[2J\033[1;1H";
		pageStateMachine->Update();
		pageStateMachine->HandleInput();
	}

    return 0;
}

