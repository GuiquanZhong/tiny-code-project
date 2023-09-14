#include "SeqList.h"

void SeqList::SeqList1()
{
	a = NULL;
	last = 0;
	Maxsize = 0;
    cout << "�ļ��½��ɹ�" << endl;
}

void SeqList::Stuadd()
{
    StuCheck();
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
    a[last] = s2;
    cout << "��ӳɹ�" << endl;
    last++;
}

void SeqList::StuFind()
{
    while (true)
    {
        cout << "1.ѧ�� 2.����";
        int x;
        cin >> x;
        bool flag = true;
        switch (x)
        {
        case '1':
        {
            cout << "������ѧ��" << endl;
            string s;
            for (int i = 0; i < last; i++)
            {
                if (a[i].number == s)
                {
                    cout << "ѧ��:" << a[i].number << endl;
                    cout << "����:" << a[i].name << endl;
                    cout << "����:" << a[i].birthday << endl;
                    cout << "�Ա�:" << a[i].sex << endl;
                    cout << "����״��:" << a[i].healthy << endl;
                    flag = false;
                }
            }
            if (flag == false)cout << "δ��ѯ����ѧ��" << endl;
        }
        case '2':
        {
            cout << "����������" << endl;
            string s;
            for (int i = 0; i < last; i++)
            {
                if (a[i].name == s)
                {
                    cout << "ѧ��:" << a[i].number << endl;
                    cout << "����:" << a[i].name << endl;
                    cout << "����:" << a[i].birthday << endl;
                    cout << "�Ա�:" << a[i].sex << endl;
                    cout << "����״��:" << a[i].healthy << endl;
                    flag = false;
                }
            }
            if (flag == false)cout << "δ��ѯ��������" << endl;
        }
        default:
            cout << "����ʧ�ܣ���������" << endl;
        }

    }
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
        Student* tmp = new Student[newMaxsize*2];
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
    //ofstream file("Studenthealthy.txt", ios::out);
    //if (!file)
    //{
    //    cout << "�ļ���ʧ��" << endl;
    //    return;
    //}
    //for (int i = 0; i < last; i++)
    //{
    //    file << a[i].number << endl;
    //    file << a[i].name << endl;
    //    file << a[i].birthday << endl;
    //    file << a[i].sex << endl;
    //    file << a[i].healthy << endl;
    //}
    //file.close();
    //cout << "�ļ�д��ɹ�" << endl;
    ofstream file("Studenthealthy.dat", ios::binary);
    if (!file)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    file.write(reinterpret_cast<char*>(a), last * sizeof(Student));
    file.close();
    cout << "�ļ�д��ɹ�" << endl;

}
void SeqList::readFile()
{
    /*ifstream file("Studenthealthy.txt", ios::in);
    string line;
    while (getline(file,line))
    {
        StuCheck();
        a[last].number = line;
        getline(file, a[last].name);
        getline(file, a[last].birthday);
        getline(file, a[last].sex);
        getline(file, a[last].healthy);
        last++;
    }
    file.close();
    cout << "��ȡ�ɹ�" << endl;*/
    StuCheck();
    ifstream file("Studenthealthy.dat", ios::binary);
    if (!file)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    // ��ȡ�ļ���С
    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.seekg(0, ios::beg);
    // �����������
    int objNum = fileSize / sizeof(Student);
    // ������ʱ��������
    Student* tmp = new Student[objNum];
    // ���ļ����ж�ȡ���ݵ���ʱ��������
    file.read(reinterpret_cast<char*>(tmp), fileSize);
    // ����ʱ�������鸳ֵ��ʵ�ʵĶ�������
    for (int i = 0; i < objNum; i++)
    {
        a[i] = tmp[i];
    }
    // �������һ�����������
    last = objNum;
    // �ر��ļ������ͷ���Դ
    file.close();
    cout << "��ȡ�ɹ�" << endl;

}
void SeqList::Stushow()
{
    for (int i = 0; i < last; i++)
    {
        cout << "ѧ��:" << a[i].number << endl;
        cout << "����:" << a[i].name << endl;
        cout << "����:" << a[i].birthday << endl;
        cout << "�Ա�:" << a[i].sex << endl;
        cout << "����״��:" << a[i].healthy << endl;
    }
}


void menu()
{
    cout << "****************************" << endl;
    cout << "*******1.�½�ѧ����������*******" << endl;
    cout << "*******2.���ѧ����Ϣ*******" << endl;
    cout << "*******3.����ѧ����Ϣ*******" << endl;
    cout << "*******4.����ѧ����Ϣ*******" << endl;
    cout << "*******5.ɾ��ָ��ѧ��*******" << endl;
    cout << "*******6.д���ļ�����*******" << endl;
    cout << "*******7.��ȡ�ļ�����*******" << endl;
    cout << "*******8.��ʾ����ѧ����Ϣ*******" << endl;
    cout << "*******9.�˳�*******" << endl;
}
