#include"SeqList.h"

int main()
{
	menu();
	while (true)
	{
		cout << "请选择操作" << endl;
		int x;
		cin >> x;
		SeqList s1;
		switch (x)
		{
		case 1:
		{
			s1.SeqList1();
			break;
		}
		case 2:
		{
			s1.Stuadd();
			break;
		}
		case 3:
		{
			s1.StuInsert();
			break;
		}
		case 5:
		{
			cout << "请输入要删除学生的姓名与学号" << endl;
			string x1, x2;
			cin >> x1 >> x2;
			s1.StuErase(x1, x2);
			break;
		}
		case 4:
		{
			s1.StuFind();
			break;
		}
		case 7:
		{
			s1.readFile();
			break;
		}
		case 6:
		{
			s1.writeToFile();
			break;
		}
		case 8:
		{
			s1.Stushow();
			break;
		}
		case 9:
		{
			cout << "退出成功" << endl;
			exit(0);
			break;
		}
		default:cout << "输入错误，请重新输入" << endl;
		}
	}
	


	return 0;
}