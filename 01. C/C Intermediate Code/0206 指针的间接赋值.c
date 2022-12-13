#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//间接赋值三大条件
// 一个普通变量  和 指针变量   或  一个实参和一个形参
// 建立关系
// * 操作内存

void changeValue(int *a) // int * a = &a2;
{
	*a = 1000;
}

void test01()
{
	int  a = 10;
	int * p = NULL;


	p = &a;

	*p = 100;

	int a2 = 10;
	changeValue(&a2);

	printf("%d\n", a2);
	printf("%d\n", &a2);
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}