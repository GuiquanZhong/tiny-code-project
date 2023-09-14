#include "SeqList.h"

void SeqList::SeqList1()
{
	a = NULL;
	last = 0;
	Maxsize = 0;
    cout << "文件新建成功" << endl;
}

void SeqList::Stuadd()
{
    StuCheck();
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
    a[last] = s2;
    cout << "添加成功" << endl;
    last++;
}

void SeqList::StuFind()
{
    while (true)
    {
        cout << "1.学号 2.姓名";
        int x;
        cin >> x;
        bool flag = true;
        switch (x)
        {
        case '1':
        {
            cout << "请输入学号" << endl;
            string s;
            for (int i = 0; i < last; i++)
            {
                if (a[i].number == s)
                {
                    cout << "学号:" << a[i].number << endl;
                    cout << "姓名:" << a[i].name << endl;
                    cout << "生日:" << a[i].birthday << endl;
                    cout << "性别:" << a[i].sex << endl;
                    cout << "身体状况:" << a[i].healthy << endl;
                    flag = false;
                }
            }
            if (flag == false)cout << "未查询到该学号" << endl;
        }
        case '2':
        {
            cout << "请输入姓名" << endl;
            string s;
            for (int i = 0; i < last; i++)
            {
                if (a[i].name == s)
                {
                    cout << "学号:" << a[i].number << endl;
                    cout << "姓名:" << a[i].name << endl;
                    cout << "生日:" << a[i].birthday << endl;
                    cout << "性别:" << a[i].sex << endl;
                    cout << "身体状况:" << a[i].healthy << endl;
                    flag = false;
                }
            }
            if (flag == false)cout << "未查询到该姓名" << endl;
        }
        default:
            cout << "输入失败，重新输入" << endl;
        }

    }
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
        cout << "未查询到该学生信息，请检查输入数据" << endl;
    }
    else
    {
        cout << "删除成功" << endl;
    }

}
void SeqList::writeToFile()
{
    //ofstream file("Studenthealthy.txt", ios::out);
    //if (!file)
    //{
    //    cout << "文件打开失败" << endl;
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
    //cout << "文件写入成功" << endl;
    ofstream file("Studenthealthy.dat", ios::binary);
    if (!file)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    file.write(reinterpret_cast<char*>(a), last * sizeof(Student));
    file.close();
    cout << "文件写入成功" << endl;

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
    cout << "读取成功" << endl;*/
    StuCheck();
    ifstream file("Studenthealthy.dat", ios::binary);
    if (!file)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    // 获取文件大小
    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.seekg(0, ios::beg);
    // 计算对象数量
    int objNum = fileSize / sizeof(Student);
    // 创建临时对象数组
    Student* tmp = new Student[objNum];
    // 从文件流中读取数据到临时对象数组
    file.read(reinterpret_cast<char*>(tmp), fileSize);
    // 将临时对象数组赋值给实际的对象数组
    for (int i = 0; i < objNum; i++)
    {
        a[i] = tmp[i];
    }
    // 更新最后一个对象的索引
    last = objNum;
    // 关闭文件流，释放资源
    file.close();
    cout << "读取成功" << endl;

}
void SeqList::Stushow()
{
    for (int i = 0; i < last; i++)
    {
        cout << "学号:" << a[i].number << endl;
        cout << "姓名:" << a[i].name << endl;
        cout << "生日:" << a[i].birthday << endl;
        cout << "性别:" << a[i].sex << endl;
        cout << "身体状况:" << a[i].healthy << endl;
    }
}


void menu()
{
    cout << "****************************" << endl;
    cout << "*******1.新建学生健康档案*******" << endl;
    cout << "*******2.添加学生信息*******" << endl;
    cout << "*******3.插入学生信息*******" << endl;
    cout << "*******4.查找学生信息*******" << endl;
    cout << "*******5.删除指定学生*******" << endl;
    cout << "*******6.写入文件档案*******" << endl;
    cout << "*******7.读取文件档案*******" << endl;
    cout << "*******8.显示所有学生信息*******" << endl;
    cout << "*******9.退出*******" << endl;
}
