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
	// 每一輪 該State要做的事
	virtual void Update()=0;
	// State 結束後的輸入 & 轉換State
	virtual void HandleInput() = 0;
	// 首次呼叫定義
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
	// 儲存State class用的map
	map<E_GamePage, EmptyState*> m_stateMap;
	// 目前所在的狀態State
	EmptyState *m_current;
	// 加入新狀態
	void AddState(E_GamePage pageID, EmptyState* state);
	// 改變狀態
	void Change(E_GamePage pageID);
	// 顯示該狀態內容
	void Update();
	// 執行該狀態的輸入
	void HandleInput();
	// 回傳page用的state machine
	static StateMachine* GetPageStateMachine();
private:
	// 建構解構
	StateMachine();
	~StateMachine();
	// page用的state machine
	static StateMachine* pageMachine;
};

#endif // !_STATE_MACHINE_