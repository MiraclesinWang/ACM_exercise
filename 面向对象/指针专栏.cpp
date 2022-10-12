#include <bits/stdc++.h>
using namespace std;

int main()
{
	int *ip = 1;   //报错 
	
	int a = 1;
	int *ip = &a;
	printf("%d\n", *ip);   //正常运行，输出1
	
	int *ip;
	*ip = 2;
	printf("%d\n", *ip);    //无法正常运行

	int a = 1;
	int *ip = &a;
	*ip = 2;
	printf("%d %d\n", *ip, a);   //正常运行，输出2 
	
	int *p = new int(3);
	printf("%d\n", *p);         //正常运行，输出3 
	
	int p = *new int;          //等价于int p; 
	p = 4;
	printf("%d\n", p);         //正常运行，输出4 

	int *p = new int[5];
	for(int i = 0; i < 3; i++) p[i] = i;
	for(int i = 0; i < 3; i++) printf("%d ", p[i]);    //正常运行，输出0 1 2
	
	
	struct student
	{
	  string name;
	  int score;
	};
	student* example3()
	{
	  //这里是用一个结构体指针接住结构体数组的首地址
	  //对于结构体指针，个人认为目前这种赋值方法比较方便
	  student *stlist = new student[3]{{"abc", 90}, {"bac", 78}, {"ccd", 93}};
	  return stlist;
	}

}
