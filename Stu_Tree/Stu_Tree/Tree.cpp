#include"Tree.h"
int main()
{
    BinaryTree<char> bt;
    while (true) {
        menu();
        int choice;
        cout << "������Ҫִ�еĲ����ı�ţ�";
        cin >> choice;
        switch (choice) {
        case 1:
            bt.createTree1();
            break;
        case 2:
            char x;
            cout << "������Ҫ���������" << endl;
            cin >> x;
            bt.InsertTree(bt.getRoot(), x);
            break;
        case 3:
            cout << "ǰ������ݹ��㷨�����";
            bt.preTree(bt.getRoot());
            cout << endl;
            break;
        case 4:
            cout << "ǰ������ǵݹ��㷨�����";
            bt.preTree1(bt.getRoot());
            cout << endl;
            break;
        case 5:
            cout << "��������ݹ��㷨�����";
            bt.inTree(bt.getRoot());
            cout << endl;
            break;
        case 6:
            cout << "��������ǵݹ��㷨�����";
            bt.inTree1(bt.getRoot());
            break;
        case 7:
            cout << "��������ݹ��㷨�����";
            bt.postTree(bt.getRoot());
            cout << endl;
            break;
        case 8:
            cout << "��������ǵݹ��㷨�����";
            bt.postTree1(bt.getRoot());
            break;
        case 9:
            cout << "����Ϊ��" << bt.getTreeHeight(bt.getRoot()) << endl;
            break;
        case 10:
            cout << "Ҷ������Ϊ��" << bt.getLeafCount(bt.getRoot()) << endl;
            break;
        case 11:
            cout << "�����������" << endl;
            bt.printTree(bt.getRoot(), 0);
            cout << endl;
            break;
        case 12:
            return 0;
        default:
            cout << "����������������룡" << endl;
        }
    }
}