#include "SeqList.h"

SeqList::SeqList()
{
	a = NULL;
	last = 0;
	Maxsize = 0;
	cout << "�½�ѧ�����������ɹ�" << endl;
}

void SeqList::StuInsert()
{
	StuCheck();
    cout << "������Ҫ�����ѧ��λ�ã�0-" << last << "����";
    int pos;
    cin >> pos;
    if (pos < 0 || pos > last)
    {
        cout << "λ�ò��Ϸ���" << endl;
        return;
    }
    Student s2;
    cout << "������ѧ����Ϣ" << endl;
    cout << "ѧ�ţ�";
    cin >> s2.number;
    cout << "������";
    cin >> s2.name;
    cout << "�������ڣ�";
    cin >> s2.birthday;
    cout << "�Ա�";
    cin >> s2.sex;
    cout << "����״����";
    cin >> s2.healthy;
    for (int i = pos; i < last; i++)
    {
        a[i + 1] = a[i];
    }
    a[pos] = s2;
	cout << "����ɹ�" << endl;
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
        cout << "δ��ѯ����ѧ����Ϣ��������������" << endl;
    }
    else
    {
        cout << "ɾ���ɹ�" << endl;
    }

}
void SeqList::writeToFile()
{
    ofstream file("Studenthealth.txt", ios::out);
    if (!file)
    {
        cout << "�ļ���ʧ��" << endl;
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
