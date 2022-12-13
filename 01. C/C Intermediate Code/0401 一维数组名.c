#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// int arr[]  可读性更高
void printArray(int arr[] , int len) //int arr[]等价于  int * arr
{
	for (int i = 0; i < len;i++)
	{
		printf("%d\n", arr[i]);
	}
}

void test01()
{

	//一维数组名是不是指针？
	int arr[5] = { 1, 2, 3, 4, 5 };

	printf("%d\n", sizeof(arr));

	//有两种特殊情况，一维数组名不是 指向第一个元素的指针
	//1、sizeof
	//2、对数组名取地址   得到数组指针 步长是整个数组长度

	
	//printf("%d\n", &arr);
	//printf("%d\n", &arr + 1);
	
	//int * p =  arr;
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);

	//arr数组名  它是一个指针常量 指针的指向不可以修改的，而指针指向的值可以改 int * const a ; 
	//arr[0] = 1000;
	//arr = NULL;

	//数组索引 可不可以为负数   答案：可以
	int * p = arr;
	p = p + 3;
	printf("%d\n",p[-1]);     //给人看的
	printf("%d\n", *(p - 1)); //给机器看的
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}