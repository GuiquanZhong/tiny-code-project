#pragma once//防止文件包含重复
#include <iostream>
using namespace std;


class Workermanager
{
public:
	Workermanager();//构造

	void Show_Menu();

	void ExitSystem();
	~Workermanager();//析构

};