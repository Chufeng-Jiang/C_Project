//#define _CRT_SECURE_NO_WARNINGS   //VS下使用传统库函数 会建议用_s更安全函数，如果不用会报错误 C4996
#include<stdio.h>   //标准   i input 输入   o  output  输出
#include<string.h>  //对字符串处理  strcat strstr strcmp strcpy
#include<stdlib.h>  //malloc   free



//1、typedef使用  可以简化 struct关键字
//可以起别名
//struct Person
//{
//	char name[64];
//	int age;
//};
//
////语法： typedef  原名   别名
//typedef struct Person  myPerson;


typedef struct Person
{
	char name[64];
	int age;
}myPerson;

void test01()
{
	struct Person p = { "aaa", 10 };

	myPerson p2 = { "bbb", 20 };

}


//2、区分数据类型
void test02()
{
	typedef char * PCHAR;
	PCHAR p1, p2;
	//char *p1, p2;

	char *p3, *p4;
}

//3、提高移植性
typedef int  MYINT;
void test03()
{
	MYINT a = 10;

	MYINT b = 10;

}



//main 函数 程序入口
int main1(){

	//char buf[1024];
	//strcpy(buf, "hello world");
	//printf("%s\n", buf);



	system("pause");  //阻塞  请按任意键继续
	
	return EXIT_SUCCESS; //返回成功退出  0
}