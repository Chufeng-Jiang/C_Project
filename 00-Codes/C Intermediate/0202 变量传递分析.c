#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * func()
{
	char * p =  malloc(10); //堆区数据，只要没有释放，都可以使用
	int c = 10;//在func中可以使用，test01和main都不可以使用
	return p;
}

void test01()
{
	int b = 10; // 在test01 、func 可以使用，在main中不可以用

	func();
}

int main(){

	int a = 10; //在main 、test01 、 func中都可以使用

	test01();


	system("pause");
	return EXIT_SUCCESS;
}