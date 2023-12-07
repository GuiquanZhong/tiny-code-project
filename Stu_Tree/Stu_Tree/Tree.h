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
    //创建二叉树
    void createTree(TreeNode<T>*& root);
    //插入节点
    TreeNode<T>* InsertTree(TreeNode<T>* root, T x);
    //递归前序遍历
    void preTree(TreeNode<T>* root);
    //非递归前序遍历
    void preTree1(TreeNode<T>* root);
    //递归中续遍历
    void inTree(TreeNode<T>* root);
    //非递归中序遍历
    void inTree1(TreeNode<T>* root);
    //递归后续遍历
    void postTree(TreeNode<T>* root);
    //非递归后续遍历
    void postTree1(TreeNode<T>* root);
    //获取树高
    int getTreeHeight(TreeNode<T>* root);
    //获取叶子总数
    int getLeafCount(TreeNode<T>* root);
    //输出二叉树
    void printTree(TreeNode<T>* root, int level);

};

template<class T>
void BinaryTree<T>::createTree(TreeNode<T>*& root)
{
    T x;
    cout << "请输入数据(前序输入，输入#号视为NULL）" << endl;
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
         cout << "节点存在" << endl;
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
         //一直遍历到左子树最下边，边遍历边保存根节点到栈中
         while (p)
         {
             cout << p->data << " ";
             s.push(p);
             p = p->left;
         }
         //当p为空时，说明已经到达左子树最下边，这时需要出栈了
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
         //边遍历边打印，并存入栈中，以后需要借助这些根节点进入右子树
         while (p)
         {
             s.push(p);
             p = p->left;
         }
         //当p为空时，说明根和左子树都遍历完了，该进入右子树了
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
    cout << "1------建立一棵二叉树" << endl;
    cout << "2------插入数据" << endl;
    cout << "3------前序遍历递归算法" << endl;
    cout << "4------前序遍历非递归算法" << endl;
    cout << "5------中序遍历递归算法" << endl;
    cout << "6------中序遍历非递归算法" << endl;
    cout << "7------后序遍历递归算法" << endl;
    cout << "8------后序遍历非递归算法" << endl;
    cout << "9------求树高" << endl;
    cout << "10------求叶子总数" << endl;
    cout << "11-----输出二叉树" << endl;
    cout << "12-----退出" << endl;
}

