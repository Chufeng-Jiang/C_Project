#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//变量的修改方式
void test01()
{
	//1、直接修改
	int a = 10;
	a = 20;

	//2、间接修改 
	int * p = &a;
	*p = 30;
	printf("a = %d\n", a);

}


struct Person
{
	char a; //0 ~ 3
	int b;  //4 ~ 7
	char c; //8 ~ 11
	int d;  //12 ~ 15
};
void test02()
{
	struct Person p = { 'a', 10, 'b', 20 };

	//直接修改 d属性
	p.d = 1000;

	//间接修改 d属性
	//struct Person * pp = &p;
	////pp->d = 1000;

	//printf("%d\n", pp);
	//printf("%d\n", pp+1);


	char * pp = &p;

	*(int*)(pp + 12) = 2000;

	printf("d属性为： %d\n", *(int*)(pp + 12));
	printf("d属性为： %d\n", *(int*)((int*)pp + 3));
}


int main(){
	//test01();
	test02();


	system("pause");
	return EXIT_SUCCESS;
}