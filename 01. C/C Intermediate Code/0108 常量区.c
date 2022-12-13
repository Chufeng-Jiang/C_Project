#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、const修饰的变量 
//全局变量
const int a = 10; //常量区 ,间接修改 语法通过，运行失败，原因：受到常量区的保护
void test01()
{
	//a = 100;

	int * p = &a;
	*p = 100;
	printf("%d\n", a);

}

void test02()
{
	const int b = 10; //存放在栈上，通过间接修改是可以成功的

	//b = 20;

	int * p = &b;
	*p = 20;
	printf("%d\n", b);

	//在C语言中 const修饰的局部变量  称为伪常量,不可以初始化数组
	//int arr[b];
}


//2、字符串常量

void test03()
{
	char * p1 = "hello world";
	char * p2 = "hello world";
	char * p3 = "hello world";
	printf("%d\n", &"hello world");
	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", p3);
}

void test04()
{
	char * str = "hello world";
	str[0] = 'x';

}

int main(){
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}