#include"speechManager.h"


SpeechManager::SpeechManager() {
	this->initSpeech();

	this->createSpeaker();

}



void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void SpeechManager::exitSystem() {

	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//
	this->m_Index = 1;

}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++) {
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;
		sp.m_score[0] = 0;
		sp.m_score[1] = 1;
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

}

void SpeechManager::startSpeech()
{//��һ�ֱ���
	//1����ǩ
	speechDraw();
	//2������
	speechContest();
	//3����ʾ�������
	showScore();
	//�ڶ��ֱ���
	this->m_Index++;
	//1����ǩ
	speechDraw();
	//2������
	speechContest();
	//3����ʾ���ս��
	showScore();
	//4���������
}

void SpeechManager::speechDraw()
{
	cout << "�� <<" << m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (m_Index ==1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;


	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest()
{
	cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;
	multimap<double, int, greater<int>>groupScore;
	int num = 0;
	vector<int> v_Src;
	if (m_Index==1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {

		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++) {

			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));

		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С���������:" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {

				cout << "��ţ�" << it->second 
					<< "������" << this->m_Speaker[it->second].m_name 
					<< "�ɼ�" << this->m_Speaker[it->second].m_score[this->m_Index - 1] 
					<< endl;

			}
			int count = 0;

			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1) {

					v2.push_back((*it).second);
				}
				else {
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;

		}
	
	}

	cout << "------------- ��" << this->m_Index << "�ֱ������  ------------- " << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "---------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_Speaker[*it].m_name << " �÷֣� " << m_Speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}



SpeechManager::~SpeechManager() {


}