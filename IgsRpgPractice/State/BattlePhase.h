#ifndef _BATTLE_PHASE_
#define _BATTLE_PHASE_

#include "StateMachine.h"
//
// �԰����q
//
class BattlePhase : public EmptyState
{
public:
	void Update() {
		cout<< "[�԰�]" << endl;
	}
	void HandleInput() {
		int choose;
		cin >> choose;
	}
	void Enter() {}
	void Exit() {}
	BattlePhase() {}
	~BattlePhase() {}
};
#endif // !_BATTLE_PHASE_
