#include "BattlePhase.h"
//
// �԰��y�{ : �M�w��������->
//
void BattlePhase::Update() {
	// �Ƨ�������
	m_attackSort.clear();
	//�[�J�ĤH
	if (m_attackSort.size() == 0) {
		for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
			m_attackSort.push_back(m_enemyVec[idx]);
		}
	}
	//�[�J���a
	m_attackSort.push_back(PlayerController::GetPlayer());
	//�Ƨ�
	sort(m_attackSort.begin(), m_attackSort.end(), [](CreatureParent* Target1, CreatureParent* Target2) {
		return Target1->GetSpeed() > Target2->GetSpeed();
		});
	// ��� ���a��T
	cout << "[----------���a----------]" << endl;
	PlayerController::GetPlayer()->ShowNameHp();
	// ��� �ĤH��T
	cout << "[----------�ĤH----------]" << endl;
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		cout << " (" << idx + 1 << ") ";
		m_enemyVec[idx]->ShowNameHp();
	}
	// ��� ��������
	cout << "[------------------------]" << endl << endl;
	cout << "��������: ";
	for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
		cout << m_attackSort[idx]->GetName();
		if ((idx + 1) < m_attackSort.size()) {
			cout << " -> ";
		}
	}
	cout << endl << endl;
	// ��ܦ��
	switch (PlayerController::GetPlayer()->PlayerBattleAction())
	{
		//���q����
	case E_BattleAction::State_normalAttaack:
		PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_normalAttaack);
		break;
		//�ޯ�
	case E_BattleAction::State_specialAttack:
		PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_normalAttaack);
		break;
		//�k�]
	case E_BattleAction::State_escape:
		 // �H���k�]���G 0->���\, 1->����
		switch ((int)(rand() % 2)) {
			//�k�]���\ ����return ��U�@��State
		case Escape_Success:
			cout << "�k�]���\!" << endl;
			m_battleEndFlag = true;
			return;
			break;
			//�k�]����
		case Escape_Fail:
			cout << "�k�]���� X_X" << endl;
			PlayerController::GetPlayer()->SetBattleAction(E_BattleAction::State_Idle);
			m_battleEndFlag = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	// ��ܥؼ�
	int chooseAtkTarget;
	cout << "[------------------------]" << endl << endl;
	cout << "��ܧ�����H 1~" << m_enemyVec.size() << endl;
	cout << ">";
	cin >> chooseAtkTarget;

	// �]�w�ĤH�ʧ@
	for (size_t idx = 0; idx < m_enemyVec.size(); idx++) {
		// �H���o�b/���q����
		m_enemyVec[idx]->SetBattleAction(static_cast<E_BattleAction>(rand()%2));
	}

	//�԰��}�l
	cout << "[------------------------]" << endl;
	for (size_t idx = 0; idx < m_attackSort.size(); idx++) {
		if (m_attackSort[idx] == PlayerController::GetPlayer()) {
			m_attackSort[idx]->NormalAttackHit(m_enemyVec[chooseAtkTarget-1]);
		} else {
			m_attackSort[idx]->NormalAttackHit(PlayerController::GetPlayer());
		}
	}
	// �԰������P�_
	size_t idx = 0;
	while (idx < m_enemyVec.size()) {
		if (m_enemyVec[idx]->GetHp() <= 0) {
			m_enemyVec.erase(m_enemyVec.begin() + idx);
		} else {
			idx++;
		}
	}
	if (m_enemyVec.size() <= 0) {
		cout << "[------------------------]" << endl;
		cout << "~~�԰��ӧQ~~" << endl;
		m_battleEndFlag = true;
		return;
	}
}
//
// �԰��}�l�e�A�ͦ��@�w�ƶq�ĤH
//
void BattlePhase::Enter() {
	m_enemyVec.clear();
	m_attackSort.clear();
	// �H����1~3��
	int enemyCount = (int)(rand() % 3) + 1;
	// �H�� �v�ܩior�����L
	for (size_t idx = 0; idx < enemyCount; idx++) {
		m_enemyVec.push_back(m_enemyController.CreateEnemy(static_cast<E_Enemy>((int)(rand() % 2))));
	}
}

void BattlePhase::HandleInput() {
	cout << "[------------------------]" << endl;
	cout << "(���U���N���~��)" << endl;
	cout << ">";
	int nextRound;
	cin >> nextRound;
	//
	// �k�]���\ or �԰�����
	//
	if (m_battleEndFlag) {
		StateMachine::GetPageStateMachine()->Change(E_GamePage::playerStep);
		return;
	}
}