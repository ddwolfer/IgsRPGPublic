#ifndef _EXIT_STATE_
#define _EXIT_STATE_

#include "StateMachine.h"
//
// �h�X�C��
//
class ExitState : public EmptyState
{
public:
	void Update() {
		exit(1);
	}
	void HandleInput() {}
	void Enter() {}
	void Exit() {}
	ExitState() {}
	~ExitState() {}
};
#endif // !_EXIT_STATE_
