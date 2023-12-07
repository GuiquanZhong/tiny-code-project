#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
#define maxValue 999
#define leafNumber 50
#define totalNumber 99     //���ڵ����=2*leafNumber-1
template<class T,class E>
struct HFNode
{
	T key;       //�ڵ�ؼ���
	E data;		 //�ڵ���������
	string huff; //����������
	int lchild, rchild, parent;
};
template<class T, class E>
struct HFTree
{
	HFNode<T, E>elem[totalNumber];    //Huff���洢����
	int num;    //ʵ��������
	int root=-1;	//��
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
			if (elem[k].parent == -1)            //δ��Ϊ������������
				if (elem[k].key < min1) {			//�µ���СȨֵ
					min2 = min1; s2 = s1;			//ԭ������СȨֵ���СȨֵ
					min1 = elem[k].key;				//�����µ���СȨֵ
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
		string _code;   //��ʱ�����洢����ı���
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
	cout << "�������ַ�����С��";
	int num; cin >> num;
	char* ch = new char[num];
	int* fr = new int[num];
	cout << "������" << num << "���ַ�" << endl;
	for (int i = 0; i < num; i++)cin >> ch[i];
	cout << "������" << num << "��Ȩֵ" << endl;
	for (int i = 0; i < num; i++)cin >> fr[i];
	tree.createHFTree(ch, fr, num);
	tree.printHFTree();
}

template<class T, class E>
void HFTree<T, E>::encode() {
	// ���ļ��ж�ȡ��������  
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
		cout << "δ������������������hfmTree�ж���" << endl;
		ifstream treeFile("hfmTree.txt");
		if (!treeFile) {
			cout << "�޷����ļ�hfmTree" << endl;
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
		treeFile.close(); // ���ر��ļ��Ƶ��˴���ʹ�������в�����ɺ󶼻�ر��ļ�  
	}
	inFile.close(); // ͬ����Ҳ���ر��ļ��Ĳ����Ƶ����в�����ɺ�  
	outFile.close(); // ͬ��  
}

template<class T, class E>
void HFTree<T, E>::decode() {
	// ���ļ��ж�ȡ��������
	ifstream treeFile("hfmTree.txt");
	if (!treeFile) {
		cout << "�޷����ļ�hfmTree" << endl;
		return;
	}
	// ��ȡ������������Ϣ���ؽ�
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
	// �������ļ�������ļ�
	ifstream inFile("CodeFile.txt");
	ofstream outFile("DecodedFile.txt");
	char ch;
	int cur = root; // �Ӹ��ڵ㿪ʼ
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
		cout << "*****��ѡ�������*****" << endl;
		cout << "*****1. ��ʼ��*****" << endl;
		cout << "*****2. ����*****" << endl;
		cout << "*****3. ����*****" << endl;
		cout << "*****0. �˳�*****" << endl;
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
			cout << "��������ȷ��ѡ��" << endl;
			break;
		}
	}
	return 0;
}