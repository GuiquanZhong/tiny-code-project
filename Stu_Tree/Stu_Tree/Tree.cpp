#include"Tree.h"
int main()
{
    BinaryTree<char> bt;
    while (true) {
        menu();
        int choice;
        cout << "请输入要执行的操作的编号：";
        cin >> choice;
        switch (choice) {
        case 1:
            bt.createTree1();
            break;
        case 2:
            char x;
            cout << "请输入要插入的数据" << endl;
            cin >> x;
            bt.InsertTree(bt.getRoot(), x);
            break;
        case 3:
            cout << "前序遍历递归算法结果：";
            bt.preTree(bt.getRoot());
            cout << endl;
            break;
        case 4:
            cout << "前序遍历非递归算法结果：";
            bt.preTree1(bt.getRoot());
            cout << endl;
            break;
        case 5:
            cout << "中序遍历递归算法结果：";
            bt.inTree(bt.getRoot());
            cout << endl;
            break;
        case 6:
            cout << "中序遍历非递归算法结果：";
            bt.inTree1(bt.getRoot());
            break;
        case 7:
            cout << "后序遍历递归算法结果：";
            bt.postTree(bt.getRoot());
            cout << endl;
            break;
        case 8:
            cout << "后序遍历非递归算法结果：";
            bt.postTree1(bt.getRoot());
            break;
        case 9:
            cout << "树高为：" << bt.getTreeHeight(bt.getRoot()) << endl;
            break;
        case 10:
            cout << "叶子总数为：" << bt.getLeafCount(bt.getRoot()) << endl;
            break;
        case 11:
            cout << "输出二叉树：" << endl;
            bt.printTree(bt.getRoot(), 0);
            cout << endl;
            break;
        case 12:
            return 0;
        default:
            cout << "输入错误，请重新输入！" << endl;
        }
    }
}