#include"speechManager.h"

int main() {
	SpeechManager sm;
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++) {
		cout << "选手编号： " << it->first
			<< "姓名： " << it->second.m_name
			<< "成绩： " << it->second.m_score[0] << endl;

	}*/




	int choice = 0;

	while (true)
	{
		sm.show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  //开始比赛
			sm.startSpeech();
			break;
		case 2:  //查看记录
			break;
		case 3:  //清空记录
			break;
		case 0:  //退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;

}
