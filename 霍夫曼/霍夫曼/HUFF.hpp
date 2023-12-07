#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
#define maxValue 999
#define leafNumber 50
#define totalNumber 99     //树节点个数=2*leafNumber-1
template<class T,class E>
struct HFNode
{
	T key;       //节点关键码
	E data;		 //节点其他数据
	string huff; //哈夫曼编码
	int lchild, rchild, parent;
};
template<class T, class E>
struct HFTree
{
	HFNode<T, E>elem[totalNumber];    //Huff树存储数组
	int num;    //实际外结点数
	int root=-1;	//根
	void createHFTree(E ch[], T fr[], int n);
	void encode();
	void decode();
	void printHFTree();
};

template<class T, class E>
void HFTree<T, E>::createHFTree(E ch[], T fr[], int n)
{
	int i, k, s1, s2; int min1, min2;
	for (i = 0; i < n; i++) {
		elem[i].data = ch[i];
		elem[i].key = fr[i];
		elem[i].huff = "";
	}
	for (i = 0; i < totalNumber; i++) {
		elem[i].parent = elem[i].lchild = elem[i].rchild = -1;
	}
	for (i = n; i < 2 * n - 1; i++) {
		min1 = min2 = maxValue;
		s1 = s2 = 0;
		for (k = 0; k < i; k++)
		{
			if (elem[k].parent == -1)            //未成为其他树的子树
				if (elem[k].key < min1) {			//新的最小权值
					min2 = min1; s2 = s1;			//原来的最小权值变次小权值
					min1 = elem[k].key;				//记忆新的最小权值
					s1 = k;
				}
				else if (elem[k].key < min2)
				{
					min2 = elem[k].key; s2 = k;
				}
		}
		elem[s1].parent = elem[s2].parent = i;
		elem[i].lchild = s1;
		elem[i].rchild = s2;
		elem[i].key = elem[s1].key + elem[s2].key;
	}
	num = n;
	root = 2 * n - 2;
	for (int i = 0; elem[i].lchild == -1 && elem[i].rchild == -1; i++)
	{
		string _code;   //临时变量存储倒序的编码
		int temp = i;
		int p = elem[temp].parent;
		while (p != -1)
		{
			if (elem[p].lchild == temp)_code += '0';
			else _code += '1';
			temp = p;
			p = elem[temp].parent;
		}
		reverse(_code.begin(), _code.end());
		elem[i].huff = _code;
	}
	ofstream outFile("hfmTree.txt",ios::out);
	for (int i = 0; i < n; i++)
	{
		outFile << elem[i].data << " " << elem[i].huff << endl;
	}
	outFile.close();
}


template<class T, class E>
void HFTree<T, E>::printHFTree()
{
	for (int i = 0; i < 2 * num - 1; i++)
	{
		E value = (i < num) ? elem[i].data : '-';
		if (i < 10) cout << " ";
		cout << i << ":" << value;
		if (elem[i].key < 10) cout << " ";
		cout << " " << elem[i].key;
		if (i < num)
			cout << " " << elem[i].lchild << " " << elem[i].rchild << " ";
		else
			cout << "  " << elem[i].lchild << " " << elem[i].rchild << " ";

		if (elem[i].parent != -1)
			cout << elem[i].parent;
		else
			cout << "-";
		cout <<" "<<elem[i].huff;
		cout << endl;
	}
	cout << "root=" << root << endl;
}

template<class T, class E>
void initialize(HFTree<T, E>& tree)
{
	cout << "请输入字符集大小：";
	int num; cin >> num;
	char* ch = new char[num];
	int* fr = new int[num];
	cout << "请输入" << num << "个字符" << endl;
	for (int i = 0; i < num; i++)cin >> ch[i];
	cout << "请输入" << num << "个权值" << endl;
	for (int i = 0; i < num; i++)cin >> fr[i];
	tree.createHFTree(ch, fr, num);
	tree.printHFTree();
}

template<class T, class E>
void HFTree<T, E>::encode() {
	// 从文件中读取霍夫曼树  
	ifstream inFile("ToBeTran.txt");
	ofstream outFile("CodeFile.txt");
	if (root != -1) {
		char ch;
		while (inFile.get(ch)) {
			if (ch == '\n') continue;
			for (int i = 0; i < num; i++) {
				if (elem[i].data == ch) {
					outFile << elem[i].huff;
					break;
				}
			}
		}
	}
	else {
		cout << "未建立霍夫曼树，将从hfmTree中读入" << endl;
		ifstream treeFile("hfmTree.txt");
		if (!treeFile) {
			cout << "无法打开文件hfmTree" << endl;
			return;
		}
		string line;
		int size = 0;
		getchar();
		while (getline(treeFile, line)) {
			elem[size].data = line[0];
			elem[size].huff = line.substr(2);
			size++;
		}
		num = size;
		char ch;
		while (inFile.get(ch)) {
			if (ch == '\n') continue;
			for (int i = 0; i < num; i++) {
				if (elem[i].data == ch) {
					outFile << elem[i].huff;
					break;
				}
			}
		}
		treeFile.close(); // 将关闭文件移到此处，使得在所有操作完成后都会关闭文件  
	}
	inFile.close(); // 同样，也将关闭文件的操作移到所有操作完成后  
	outFile.close(); // 同上  
}

template<class T, class E>
void HFTree<T, E>::decode() {
	// 从文件中读取霍夫曼树
	ifstream treeFile("hfmTree.txt");
	if (!treeFile) {
		cout << "无法打开文件hfmTree" << endl;
		return;
	}
	// 读取霍夫曼树的信息并重建
	int size = 0;
	string line;
	getchar();
	while (getline(treeFile, line)) {
		elem[size].data = line[0];
		elem[size].huff = line.substr(2);
		size++;
	}
	num = size;
	treeFile.close();
	// 打开输入文件和输出文件
	ifstream inFile("CodeFile.txt");
	ofstream outFile("DecodedFile.txt");
	char ch;
	int cur = root; // 从根节点开始
	while (getline(inFile, line)) {
		int left = 0, right = 0,len=1;
		while (right < line.size())
		{
			bool flag = true;
			while (flag&&right<line.size())
			{
				for (int i = 0; i < num; i++)
				{

					if (elem[i].huff == line.substr(left, len))
					{
						outFile << elem[i].data;
						flag = false;
						break;
					}
				}
				len++;
				right = left + len-1;
			}
			left = right;
			len=0;
		}
	}

	inFile.close();
	outFile.close();
}

int main()
{
	HFTree<int, char> tree;
	int choice;
	while (true) {
		cout << "*****请选择操作：*****" << endl;
		cout << "*****1. 初始化*****" << endl;
		cout << "*****2. 编码*****" << endl;
		cout << "*****3. 译码*****" << endl;
		cout << "*****0. 退出*****" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			initialize(tree);
			break;
		case 2:
			tree.encode();
			break;
		case 3:
			tree.decode();
			break;
		case 0:
			return 0;
		default:
			cout << "请输入正确的选择！" << endl;
			break;
		}
	}
	return 0;
}