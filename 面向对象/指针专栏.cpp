#include <bits/stdc++.h>
using namespace std;

int main()
{
	int *ip = 1;   //���� 
	
	int a = 1;
	int *ip = &a;
	printf("%d\n", *ip);   //�������У����1
	
	int *ip;
	*ip = 2;
	printf("%d\n", *ip);    //�޷���������

	int a = 1;
	int *ip = &a;
	*ip = 2;
	printf("%d %d\n", *ip, a);   //�������У����2 
	
	int *p = new int(3);
	printf("%d\n", *p);         //�������У����3 
	
	int p = *new int;          //�ȼ���int p; 
	p = 4;
	printf("%d\n", p);         //�������У����4 

	int *p = new int[5];
	for(int i = 0; i < 3; i++) p[i] = i;
	for(int i = 0; i < 3; i++) printf("%d ", p[i]);    //�������У����0 1 2
	
	
	struct student
	{
	  string name;
	  int score;
	};
	student* example3()
	{
	  //��������һ���ṹ��ָ���ס�ṹ��������׵�ַ
	  //���ڽṹ��ָ�룬������ΪĿǰ���ָ�ֵ�����ȽϷ���
	  student *stlist = new student[3]{{"abc", 90}, {"bac", 78}, {"ccd", 93}};
	  return stlist;
	}

}
