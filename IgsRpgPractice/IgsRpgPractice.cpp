// IgsRpgPractice.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "IgsRpgPractice.h"

int main()
{
	StateMachine*		pageStateMachine= new StateMachine();

	ExitState*			exitState		= new ExitState();
	MenuState*			menuState		= new MenuState();
	SelectRole*			selectRole		= new SelectRole();
	PlayerStep*			playerStep		= new PlayerStep();
	PlayerStatus*		playerStatus	= new PlayerStatus();
	BattlePhase*		battleState		= new BattlePhase();

	pageStateMachine->AddState(E_GamePage::exit, exitState);
	pageStateMachine->AddState(E_GamePage::mainMenu, menuState);
	pageStateMachine->AddState(E_GamePage::selectRole, selectRole);
	pageStateMachine->AddState(E_GamePage::playerStep, playerStep);
	pageStateMachine->AddState(E_GamePage::playerStatus, playerStatus);
	pageStateMachine->AddState(E_GamePage::battle, battleState);

	pageStateMachine->Change(E_GamePage::mainMenu);

	while (true) {
		// clear CMD 畫面
		cout << "\033[2J\033[1;1H";
		pageStateMachine->Update();
		pageStateMachine->HandleInput();
	}

    return 0;
}

