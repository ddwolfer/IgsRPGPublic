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
	// �Cfps �����Ʊ�
	virtual void Update()=0;
	// ��L/�n���J cin  
	virtual void HandleInput() = 0;

	// �����I�s�w�q (�ڦn���Τ���)
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
	map<E_GamePage, EmptyState*> m_stateMap;
	EmptyState *m_current;
	//
	// �[�J�s���A
	//
	void AddState(E_GamePage pageID, EmptyState* state);
	//
	// ���ܪ��A
	//
	void Change(E_GamePage pageID) {

		if (m_current != nullptr) {
			m_current->Exit();
		}
		EmptyState *nextState = m_stateMap[pageID];
		nextState->Enter();
		m_current = nextState;
	}
	//
	// ��ܸӪ��A���e
	//
	void Update() {
		if (m_current != nullptr) {
			m_current->Update();
		}
	}
	//
	// ����Ӫ��A����J
	//
	void HandleInput() {
		if (m_current != nullptr) {
			m_current->HandleInput();
		}
	}
	static StateMachine* GetStateMachine();
	StateMachine();
	~StateMachine();

private:
	static StateMachine* pageMachine;
};

#endif // !_STATE_MACHINE_