#include <iostream>
using namespace std;
#include "workermanager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include "manager.h"
int main()
{

	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;
	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;
	//worker = new Boss(3, "����", 3);
	//worker->showInfo();
	//delete worker;
	//ʵ���������߶���
	Workermanager wm;

	int choice = 0;//�����洢�û���ѡ��
	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ��  " << endl;
		cin >> choice;//�����û���ѡ��

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://���ְ��
		
			break;
		case 2://��ʾְ��
		
			break;
		case 3://ɾ��ְ��
		
			break;
		case 4://�޸�ְ��
		
			break;
		case 5://����ְ��
		
			break;
		case 6://����ְ��
		
			break;
		case 7://����ļ�
		
			break;
		default:
			system("cls");//����
			break;
		}
	}

	//����չʾ�˵���Ա
	wm.Show_Menu();



	system("pause");
	return 0;
}