#include "StuHea_List.h"

void menu()
{
    cout << "****************************" << endl;
    cout << "*******1.新建学生健康档案*******" << endl;
    cout << "*******2.插入学生信息*******" << endl;
    cout << "*******3.查找学生信息*******" << endl;
    cout << "*******4.删除指定学生*******" << endl;
    cout << "*******5.写入文件档案*******" << endl;
    cout << "*******6.读取文件档案*******" << endl;
    cout << "*******7.显示所有学生信息*******" << endl;
    cout << "*******0.退出*******" << endl;
}

void StuList::StuList1()
{
    head = nullptr;
    cout << "新建学生健康档案成功" << endl;
}

void StuList::Stuadd()
{
    Student* newnode = new Student;
    cout << "请输入学生信息" << endl;
    cout << "学号：";
    cin >> newnode->number;
    cout << "姓名：";
    cin >> newnode->name;
    cout << "出生日期：";
    cin >> newnode->birthday;
    cout << "性别：";
    cin >> newnode->sex;
    cout << "身体状况：";
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
    cout << "添加成功" << endl;
}

void StuList::StuFind()
{
    cout << "请输入要查找的学生学号" << endl;
    string s1;
    cin >> s1;
    Student* cur = head;
    while (cur)
    {
        if (cur->number == s1)
        {
            cout << "学号:" << cur->number << endl;
            cout << "姓名:" << cur->name << endl;
            cout << "生日:" << cur->birthday << endl;
            cout << "性别:" << cur->sex << endl;
            cout << "身体状况:" << cur->healthy << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "未查询到该学号" << endl;
    return;
}

void StuList::StuErase()
{
    cout << "请输入要删除的学生学号：" << endl;
    string s2;
    cin >> s2;
    if (head == NULL)
    {
        cout << "当前健康表为空，无法删除" << endl;
        return;
    }
    Student* cur = head;
    if (head->number == s2)
    {
        Student* cur = head;
        head = head->next;
        delete cur;
        cout << "删除学生信息成功！" << endl;
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
            cout << "删除学生信息成功！" << endl;
            return;
        }
        cur = cur->next;
    }
    
}

void StuList::writeToFile()
{
    ofstream file("StuHealthy.txt", ios::out);
    if (!file)
    {
        cout << "文件打开失败" << endl;
            return;
    }
    Student* cur = head;
    while (cur)
    {
        file << cur->number << endl;
        file << cur->name << endl;
        file << cur->birthday << endl;
        file << cur->sex << endl;
        file << cur->healthy << endl;
        cur = cur->next;
    }
    file.close();
    cout << "文件写入成功" << endl;
}

void StuList::readFile()
{
    ifstream file("StuHealthy.txt", ios::in);
    string line;
    if (!file)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    
    while (getline(file, line))
    {
        Student* cur = head;
        if (cur == NULL)
        {
            cur = new Student;
            cur->next = NULL;
            head = cur;
        }
        else
        {
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = new Student;
            cur = cur->next;
            cur->next = NULL;
        }
        cur->number = line;
        getline(file, cur->name);
        getline(file, cur->birthday);
        getline(file, cur->sex);
        getline(file, cur->healthy);
        cur = cur->next;
    }
    file.close();
    cout << "文件读取成功" << endl;
}

void StuList::Stushow()
{
    Student* cur = head;
    while (cur)
    {
        cout << "学号:" << cur->number << endl;
        cout << "姓名:" << cur->name << endl;
        cout << "生日:" << cur->birthday << endl;
        cout << "性别:" << cur->sex << endl;
        cout << "身体状况:" << cur->healthy << endl;
        cout << endl;
        cur = cur->next;
    }
}

