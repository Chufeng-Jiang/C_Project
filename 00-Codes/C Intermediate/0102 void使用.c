#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、void 无类型，不可以通过void创建变量，原因无法给void无类型变量分配内存
void test01()
{
	//void  a = 10;
}

//2、用途： 限定函数返回值,限定函数参数
void test02(void)
{
	//return 10;
}

//3、void *   万能指针  不管几级指针,任意类型指针都是4个字节
void test03()
{
	//printf("size of void* = %d\n", sizeof(void *));
	void * p = NULL;

	int * pInt = NULL;
	char * pChar = NULL;

	pChar = (char *)pInt;

	pChar = p; //万能指针  可以不通过强制类型转换就转成其他类型指针

}

int main(){
	
	//test02(10);
	test03();


	system("pause");
	return EXIT_SUCCESS;
}