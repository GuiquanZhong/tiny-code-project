#include "StuHea_List.h"

void menu()
{
    cout << "****************************" << endl;
    cout << "*******1.�½�ѧ����������*******" << endl;
    cout << "*******2.����ѧ����Ϣ*******" << endl;
    cout << "*******3.����ѧ����Ϣ*******" << endl;
    cout << "*******4.ɾ��ָ��ѧ��*******" << endl;
    cout << "*******5.д���ļ�����*******" << endl;
    cout << "*******6.��ȡ�ļ�����*******" << endl;
    cout << "*******7.��ʾ����ѧ����Ϣ*******" << endl;
    cout << "*******8.�˳�*******" << endl;
}

void StuList::StuList1()
{
    head = nullptr;
    cout << "�½�ѧ�����������ɹ�" << endl;
}

void StuList::Stuadd()
{
    Student* newnode = new Student;
    cout << "������ѧ����Ϣ" << endl;
    cout << "ѧ�ţ�";
    cin >> newnode->number;
    cout << "������";
    cin >> newnode->name;
    cout << "�������ڣ�";
    cin >> newnode->birthday;
    cout << "�Ա�";
    cin >> newnode->sex;
    cout << "����״����";
    cin >> newnode->healthy;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else {
        Student* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
    cout << "��ӳɹ�" << endl;
}

void StuList::StuFind()
{
    cout << "������Ҫ���ҵ�ѧ��ѧ��" << endl;
    string s1;
    cin >> s1;
    Student* cur = head;
    while (cur)
    {
        if (cur->number == s1)
        {
            cout << "ѧ��:" << cur->number << endl;
            cout << "����:" << cur->name << endl;
            cout << "����:" << cur->birthday << endl;
            cout << "�Ա�:" << cur->sex << endl;
            cout << "����״��:" << cur->healthy << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "δ��ѯ����ѧ��" << endl;
    return;
}

void StuList::StuErase()
{
    cout << "������Ҫɾ����ѧ��ѧ�ţ�" << endl;
    string s2;
    if (head == NULL)
    {
        cout << "��ǰ������Ϊ�գ��޷�ɾ��" << endl;
        return;
    }
    Student* cur = head;
    if (head->number == s2)
    {
        Student* cur = head;
        head = head->next;
        delete cur;
        cout << "ɾ��ѧ����Ϣ�ɹ���" << endl;
        return;
    }
    while (cur->next)
    {
        if (cur->next->number==s2);
        {
            Student* prev = cur;
            cur = cur->next;
            prev->next = cur->next;
            delete cur;
            cout << "ɾ��ѧ����Ϣ�ɹ���" << endl;
            return;
        }
        cur = cur->next;
    }
    
}

void StuList::writeToFile()
{

}

void StuList::readFile()
{
}

void StuList::Stushow()
{
    Student* cur = head;
    while (cur)
    {
        cout << "ѧ��:" << cur->number << endl;
        cout << "����:" << cur->name << endl;
        cout << "����:" << cur->birthday << endl;
        cout << "�Ա�:" << cur->sex << endl;
        cout << "����״��:" << cur->healthy << endl;
        cout << endl;
        cur = cur->next;
    }
}

