#pragma once
#include<iostream>
#include<stack>
using namespace std;

template<class T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) 
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


template<class T>
class BinaryTree {
private:

public:
    TreeNode<T>* root;
    BinaryTree()
    {
        root = nullptr;
    }
    TreeNode<T>* getRoot() {
        return root;
    }
    void createTree1()
    {
         createTree(root);
    }
    //����������
    void createTree(TreeNode<T>*& root);
    //����ڵ�
    TreeNode<T>* InsertTree(TreeNode<T>* root, T x);
    //�ݹ�ǰ�����
    void preTree(TreeNode<T>* root);
    //�ǵݹ�ǰ�����
    void preTree1(TreeNode<T>* root);
    //�ݹ���������
    void inTree(TreeNode<T>* root);
    //�ǵݹ��������
    void inTree1(TreeNode<T>* root);
    //�ݹ��������
    void postTree(TreeNode<T>* root);
    //�ǵݹ��������
    void postTree1(TreeNode<T>* root);
    //��ȡ����
    int getTreeHeight(TreeNode<T>* root);
    //��ȡҶ������
    int getLeafCount(TreeNode<T>* root);
    //���������
    void printTree(TreeNode<T>* root, int level);

};

template<class T>
void BinaryTree<T>::createTree(TreeNode<T>*& root)
{
    T x;
    cout << "����������(ǰ�����룬����#����ΪNULL��" << endl;
    cin >> x;
    if (x =='#')return;
    root = new TreeNode<T>(x);
    createTree(root->left);
    createTree(root->right);
}

template<class T>
TreeNode<T>* BinaryTree<T>::InsertTree(TreeNode<T>* root,T x)
{

     TreeNode<T>* node = new TreeNode<T>(x);
     if (root == NULL)return node;
     if (x < root->data)
     {
         root->left = InsertTree(root->left, x);
     }
     else if (x > root->data)
     {
         root->right = InsertTree(root->right, x);
     }
     else
     {
         cout << "�ڵ����" << endl;
     }
     free(node);
     return root;
}



template<class T>
void BinaryTree<T>::preTree(TreeNode<T>* root)
{
    if (root == nullptr)
    {
        cout << "#"<<" ";
        return;
    }
    cout << root->data << " ";
    preTree(root->left);
    preTree(root->right);
}

template<class T>
 void BinaryTree<T>::preTree1(TreeNode<T>* root)
{
     if (root == NULL)return;
     TreeNode<T>* p = root;
     stack<TreeNode<T>* >s;
     while (!s.empty() || p)
     {
         //һֱ���������������±ߣ��߱����߱�����ڵ㵽ջ��
         while (p)
         {
             cout << p->data << " ";
             s.push(p);
             p = p->left;
         }
         //��pΪ��ʱ��˵���Ѿ��������������±ߣ���ʱ��Ҫ��ջ��
         if (!s.empty())
         {
             p = s.top();
             s.pop();
             p = p->right;
         }
     }
 
}

template<class T>
 void BinaryTree<T>::inTree(TreeNode<T>* root)
{
     if (root == nullptr)
     {
         cout << "#" << " ";
         return;
     }
     inTree(root->left);
     cout << root->data << " ";
     inTree(root->right);
}
 template<class T>
 void BinaryTree<T>::inTree1(TreeNode<T>* root)
{
     if (root == NULL)return;
     TreeNode<T>* p = root;
     stack<TreeNode<T>* >s;
     while (!s.empty() || p)
     {
         //�߱����ߴ�ӡ��������ջ�У��Ժ���Ҫ������Щ���ڵ����������
         while (p)
         {
             s.push(p);
             p = p->left;
         }
         //��pΪ��ʱ��˵���������������������ˣ��ý�����������
         if (!s.empty())
         {
             p = s.top();
             s.pop();
             cout << p->data << " ";
             p = p->right;
         }
     }
}

template<class T>
 void BinaryTree<T>::postTree(TreeNode<T>* root)
{
     if (root == nullptr)
     {
         cout << "#"<<" ";
         return;
     }
     postTree(root->left);
     postTree(root->right);
     cout << root->data << " ";
}

 template<class T>
 void BinaryTree<T>::postTree1(TreeNode<T>* root)
 {
     if (root == NULL)
         return;
     stack<TreeNode<T>*>s;
     TreeNode<T>* cur = root, *pre = NULL;
     s.push(root);
     while (!s.empty())
     {
         cur = s.top();
         if ((cur->left == NULL && cur->right == NULL) || ((pre == cur->left || pre == cur->right) && pre != NULL))
         {
             cout << cur->data << " ";
             s.pop();
             pre = cur;
         }
         else
         {
             if (cur->right != NULL)
             {
                 s.push(cur->right);
             }
             if (cur->left != NULL)
             {
                 s.push(cur->left);
             }
         }
     }
     cout << endl;
 }

template<class T>
 int BinaryTree<T>::getTreeHeight(TreeNode<T>* root)
{
     if (root == nullptr)
     {
         return 0;
     }
     int lefthigh = getTreeHeight(root->left);
     int righthigh = getTreeHeight(root->right);
     return max(lefthigh, righthigh) + 1;
    
}

template<class T>
 int BinaryTree<T>::getLeafCount(TreeNode<T>* root)
{
     if (root == NULL)
     {
         return 0;
     }
     if (root->left == NULL && root->right == NULL)return 1;
     return getLeafCount(root->left) + getLeafCount(root->right);
}

template<class T>
void BinaryTree<T>::printTree(TreeNode<T>* root, int level)
{
    if (root == NULL)
        return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        cout<<" ";
    cout << root->data << endl;
    printTree(root->left, level + 1);
}

void menu()
{
    cout << "1------����һ�ö�����" << endl;
    cout << "2------��������" << endl;
    cout << "3------ǰ������ݹ��㷨" << endl;
    cout << "4------ǰ������ǵݹ��㷨" << endl;
    cout << "5------��������ݹ��㷨" << endl;
    cout << "6------��������ǵݹ��㷨" << endl;
    cout << "7------��������ݹ��㷨" << endl;
    cout << "8------��������ǵݹ��㷨" << endl;
    cout << "9------������" << endl;
    cout << "10------��Ҷ������" << endl;
    cout << "11-----���������" << endl;
    cout << "12-----�˳�" << endl;
}

