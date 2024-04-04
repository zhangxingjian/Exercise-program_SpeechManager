#include"speechManager.h"


SpeechManager::SpeechManager() {
	this->initSpeech();

	this->createSpeaker();

}



void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void SpeechManager::exitSystem() {

	cout << "欢迎下次使用" << endl;
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
		string name = "选手";
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
{//第一轮比赛
	//1、抽签
	speechDraw();
	//2、比赛
	speechContest();
	//3、显示晋级结果

	//第二轮比赛

	//1、抽签

	//2、比赛

	//3、显示最终结果

	//4、保存分数
}

void SpeechManager::speechDraw()
{
	cout << "第 <<" << m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "-------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
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
	cout << "------------- 第" << this->m_Index << "轮正式比赛开始：------------- " << endl;
	multimap<double, int, greater<int>>groupScore;

}



SpeechManager::~SpeechManager() {


}