#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、不能向NULL或者非法内存拷贝数据
void test01()
{
	//char *p = NULL;
	////给p指向的内存区域拷贝内容
	//strcpy(p, "1111"); //err

	//char *q = 0x1122;
	////给q指向的内存区域拷贝内容
	//strcpy(q, "2222"); //err		

}


//指针操作超越变量作用域
int * doWork()
{
	int a = 10;
	int * p = &a;
	return p;
}

//2、野指针出现情况
void test02()
{
	//2.1 指针变量未初始化
	/*int * p;
	printf("%d\n",*p);*/



	//2.2 指针释放后未置空
	char * str  = malloc(100);
	free(str);
	//记住释放后 置空，防止野指针出现
	//str = NULL;

	//free(str);
	//2.3 空指针可以重复释放、野指针不可以重复释放

	//2.4 指针操作超越变量作用域
	int * p = doWork();
	printf("%d\n", *p);
	printf("%d\n", *p);
}

int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}
