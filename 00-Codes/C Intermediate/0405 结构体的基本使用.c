#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//struct Person
//{
//	char name[64];
//	int age;
//};
//typedef struct Person myPerson;

typedef struct Person
{
	char name[64];
	int age;
}myPerson;

void test01()
{
	struct Person p = { "Tom", 18 };
	myPerson p2 = { "Jerry", 20 };
}


struct Person2
{
	char name[64];
	int age;
}myPerson2 = { "aaa", 20 };

void test02()
{
	printf("姓名:%s 年龄%d\n", myPerson2.name, myPerson2.age);
}

//匿名结构体
struct 
{
	char name[64];
	int age;
}myPerson3 = { "bbb", 30 };

void test03()
{
	printf("姓名:%s 年龄%d\n", myPerson3.name, myPerson3.age);
}

//结构体创建
void test04()
{
	//创建在栈上
	struct Person p = { "aaa", 10 };

	printf("姓名：%s  年龄： %d\n", p.name, p.age);

	//创建在堆区
	struct Person * p2 = malloc(sizeof(struct Person));
	strcpy(p2->name, "bbb");
	p2->age = 20;

	printf("姓名：%s  年龄： %d\n", p2->name, p2->age);

	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
}


void printArray( struct Person personArray[]  ,int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("姓名 ： %s ，年龄 : %d \n", personArray[i].name, personArray[i].age);
	}
}
//结构体变量数组创建
void test05()
{
	//在栈上分配内存
	struct Person persons[] =
	{
		{ "aaa", 10 },
		{ "bbb", 20 },
		{ "ccc", 30 },
		{ "ddd", 40 },
	};
	int len = sizeof(persons) / sizeof(struct Person);
	//printArray(persons, len);


	//在堆区分配内存
	struct Person * pArray = malloc(sizeof(struct Person) * 4);
	for (int i = 0; i < 4;i++)
	{
		sprintf(pArray[i].name, "name_%d", i + 1);
		pArray[i].age = 18 + i;
	}
	
	printArray(pArray, 4);

	if (pArray != NULL)
	{
		free(pArray);
		pArray = NULL;
	}

}


int main(){
	//test02();
	//test03();
	//test04();
	test05();


	system("pause");
	return EXIT_SUCCESS;
}