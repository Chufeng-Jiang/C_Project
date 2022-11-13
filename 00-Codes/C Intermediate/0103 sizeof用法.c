#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、sizeof本质  是不是一个函数？？？不是函数 ，而是 操作符 
void test01()
{
	printf("size of int = %d\n", sizeof(int));

	double d = 3.14;
	
	printf("size of d = %d\n", sizeof d);
}

//2、sizeof 返回值类型 无符号整型 unsigned int
void test02()
{
	//unsigned int a = 10;
	////当unsigned int 和 int做运算，会转换成统一 unsigned int数据类型
	//if (a  - 20 > 0)
	//{
	//	printf("大于0\n");
	//}
	//else
	//{
	//	printf("小于0\n");
	//}

	if ( sizeof(int) - 5 >0)
	{
		printf("大于0\n");
	}
	else
	{
		printf("小于0\n");
	}

}

//sizeof 用途：统计数组长度 , 当数组名做函数参数时候，会退化为指针，指向数组中第一个元素的位置
void calculateArray(int arr[])
{
	printf("array length = %d\n", sizeof(arr));
}

void test03()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	calculateArray(arr);
	//printf("array length = %d\n", sizeof(arr));

}

int main(){

	//test01();
	//test02();
	test03();

	

	system("pause");
	return EXIT_SUCCESS;
}