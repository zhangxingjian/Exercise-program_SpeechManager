#include"speechManager.h"

int main() {
	SpeechManager sm;
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++) {
		cout << "ѡ�ֱ�ţ� " << it->first
			<< "������ " << it->second.m_name
			<< "�ɼ��� " << it->second.m_score[0] << endl;

	}




	int choice = 0;

	while (true)
	{
		sm.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  //��ʼ����
			break;
		case 2:  //�鿴��¼
			break;
		case 3:  //��ռ�¼
			break;
		case 0:  //�˳�ϵͳ
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
