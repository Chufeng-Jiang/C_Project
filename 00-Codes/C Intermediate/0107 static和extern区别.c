#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//static 静态变量
// 特点：在运行前分配内存，程序运行结束 生命周期结束  ，在本文件内都可以使用静态变量
// 全局作用域 a
static int a = 10;

void test01()
{
	//局部作用域 b
	static int b = 20;
}


int main(){

	//告诉编译器 下面代码中出现 g_a 不要报错，是外部链接属性，在其他文件中
	extern int g_a;

	printf("g_a = %d\n", g_a);

	system("pause");
	return EXIT_SUCCESS;
}