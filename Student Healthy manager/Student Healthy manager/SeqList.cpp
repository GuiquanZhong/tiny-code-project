#include "SeqList.h"

SeqList::SeqList()
{
	a = NULL;
	last = 0;
	Maxsize = 0;
	cout << "新建学生健康档案成功" << endl;
}

void SeqList::StuInsert()
{
	StuCheck();
    cout << "请输入要插入的学生位置（0-" << last << "）：";
    int pos;
    cin >> pos;
    if (pos < 0 || pos > last)
    {
        cout << "位置不合法！" << endl;
        return;
    }
    Student s2;
    cout << "请输入学生信息" << endl;
    cout << "学号：";
    cin >> s2.number;
    cout << "姓名：";
    cin >> s2.name;
    cout << "出生日期：";
    cin >> s2.birthday;
    cout << "性别：";
    cin >> s2.sex;
    cout << "身体状况：";
    cin >> s2.healthy;
    for (int i = pos; i < last; i++)
    {
        a[i + 1] = a[i];
    }
    a[pos] = s2;
	cout << "插入成功" << endl;
    last++;
}
void SeqList::StuCheck()
{
    if (this->last == this->Maxsize)
    {
        int newMaxsize=Maxsize = this->Maxsize == 0 ? 4 : this->Maxsize * 2;
        Student* tmp = new Student[this->Maxsize*2];
        if (tmp == NULL)
        {
            cout << "new fail" << endl;
            exit(-1);
        }
        else
        {
            memcpy(tmp, a, this->last * sizeof(Student));
            delete[] a;
            a = tmp;
        }
    }
}
void SeqList::StuErase(string num, string name)
{
    bool flag = true;
    for (int i = 0; i < last; i++)
    {
        if (a[i].number == num && a[i].name == name)
        {
            for (int j = i; j < last-1; j++)
            {
                a[j] = a[j + 1];
            }
            last--;
            flag = false;
        }
    }
    if (flag == true)
    {
        cout << "未查询到该学生信息，请检查输入数据" << endl;
    }
    else
    {
        cout << "删除成功" << endl;
    }

}
void SeqList::writeToFile()
{
    ofstream file("Studenthealth.txt", ios::out);
    if (!file)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < last; i++)
    {

    }

}
int main()
{
	SeqList sx;
	sx.StuInsert();
	sx.StuInsert();
    sx.StuErase("20222132002", "wq");
	return 0;
}
