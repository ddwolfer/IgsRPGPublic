#ifndef _STATE_MACHINE_
#define _STATE_MACHINE_

#include <iostream>
#include <map>

using namespace std;
//
// 頁面狀態
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
// 狀態的Instance
//
class IState
{
public:
	// 每fps 做的事情
	virtual void Update()=0;
	// 鍵盤/搖桿輸入 cin  
	virtual void HandleInput() = 0;

	// 首次呼叫定義 (我好像用不到)
	virtual void Enter() = 0;
	// 結束該State要做什麼事情
	virtual void Exit() = 0;
};
//
// 初始空狀態
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
// 狀態機class
//
class StateMachine
{
public:
	map<E_GamePage, EmptyState*> m_stateMap;
	EmptyState *m_current;
	//
	// 加入新狀態
	//
	void AddState(E_GamePage pageID, EmptyState* state);
	//
	// 改變狀態
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
	// 顯示該狀態內容
	//
	void Update() {
		if (m_current != nullptr) {
			m_current->Update();
		}
	}
	//
	// 執行該狀態的輸入
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