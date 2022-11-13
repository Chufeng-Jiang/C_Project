#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、栈的生长方向
void test01()
{
	int a = 10;  //栈底  高地址
	int b = 10;
	int c = 10;
	int d = 10;  //栈顶  低地址


	printf("%d\n", &a);
	printf("%d\n", &b);
	printf("%d\n", &c);
	printf("%d\n", &d);

}


//2、内存存放方向
void test02()
{
	int a = 0x11223344;

	char * p = &a;

	printf("%x\n", *p);    //44  低位字节数据  低地址
	printf("%x\n", *(p+1)); //33  高位字节数据  高地址
}

int main(){


	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}