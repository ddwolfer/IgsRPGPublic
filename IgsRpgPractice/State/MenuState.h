#ifndef _MENU_STATE_
#define _MENU_STATE_

#include "StateMachine.h"
enum E_MenuSelect
{
	State_Start = 1,
	State_Exit = 2
};
//
// �D���� 
// (1)�}�l�C�� 
// (2)�h�X
//
class MenuState : public EmptyState
{
public:
	void Update();		// ��ܥD�����e��
	void HandleInput(); // ��J�ø��୶��
	void Enter() {}
	void Exit() {}

	MenuState() {}
	~MenuState() {}
};
#endif // !_MENU_STATE_