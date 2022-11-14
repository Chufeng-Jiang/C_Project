#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//数组指针的定义方式
//1、先定义数组类型，再通过类型定义数组指针
void test01()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	typedef int(ARRARY_TYPE)[5];//ARRARY_TYPE 代表存放5个int类型元素的数组 的数组类型
	
	/*ARRARY_TYPE arr2;
	for (int i = 0; i < 5;i++)
	{
		arr2[i] = 100 + i;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr2[i]);
	}*/

	ARRARY_TYPE * arrP = &arr;
	// *arrP == arr == 数组名
	for (int i = 0; i < 5;i++)
	{
		printf("%d\n", (*arrP)[i]);
	}

}

void test02()
{
	//先定义数组指针类型，再通过类型定义数组指针
	int arr[5] = { 1, 2, 3, 4, 5 };

	typedef int(*ARRARY_TYPE)[5];

	ARRARY_TYPE arrP = &arr;

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*arrP)[i]);
	}

}

void test03()
{
	//直接定义数组指针变量

	int arr[5] = { 1, 2, 3, 4, 5 };

	int(* p )[5] = &arr;

	for (int i = 0; i < 5;i++)
	{
		printf("%d\n", (*p)[i]);
	}

}

int main(){

	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}