#ifndef _STATE_MACHINE_
#define _STATE_MACHINE_

#include <iostream>
#include <map>

using namespace std;
//
// �������A
//
enum class E_GamePage {
	exit = 0,
	mainMenu = 1,
	selectRole = 2,
	playerStep = 3,
	playerStatus = 4,
	playerBag = 5,
	battle = 6
};
//
// ���A��Instance
//
class IState
{
public:
	// �C�@�� ��State�n������
	virtual void Update()=0;
	// State �����᪺��J & �ഫState
	virtual void HandleInput() = 0;
	// �����I�s�w�q
	virtual void Enter() = 0;
	// ������State�n������Ʊ�
	virtual void Exit() = 0;
};
//
// ��l�Ū��A
//
class EmptyState : public IState
{
public:
	void Update() {}
	void HandleInput() {}
	void Enter() {}
	void Exit() {}
};
//
// ���A��class
//
class StateMachine
{
public:
	// �x�sState class�Ϊ�map
	map<E_GamePage, EmptyState*> m_stateMap;
	// �ثe�Ҧb�����AState
	EmptyState *m_current;
	// �[�J�s���A
	void AddState(E_GamePage pageID, EmptyState* state);
	// ���ܪ��A
	void Change(E_GamePage pageID);
	// ��ܸӪ��A���e
	void Update();
	// ����Ӫ��A����J
	void HandleInput();
	// �^��page�Ϊ�state machine
	static StateMachine* GetPageStateMachine();
private:
	// �غc�Ѻc
	StateMachine();
	~StateMachine();
	// page�Ϊ�state machine
	static StateMachine* pageMachine;
};

#endif // !_STATE_MACHINE_