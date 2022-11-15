#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//提供一个函数，实现可以打印任意类型的数组 

void printAllArray(void * pArray , int eleSize, int len , void(*myPrint)(void*) )
{
	char * p = pArray;

	for (int i = 0; i < len;i++)
	{
		//获取数组中每个元素的首地址
		char * eleAddr = p + eleSize * i;
		//printf("%d\n", *(int *)eleAddr);
		//交还给用户做打印操作
		myPrint(eleAddr);
	}

}

void myPrintInt(void * data)
{
	int * num = data;
	printf("%d\n", *num);
}

void test01()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int len = sizeof(arr) / sizeof(int);
	printAllArray(arr, sizeof(int), len, myPrintInt);
}

struct Person
{
	char name[64];
	int age;
};

void myPrintperson(void * data)
{
	struct Person * p = data;
	printf("姓名：%s  年龄：%d \n", p->name, p->age);
}


//查找数组中的元素是否存在
//参数1  数组首地址   参数2  每个元素的大小  参数3  数组元素个数  参数4 查找数据
int findArrayEle(void * pArray, int eleSize, int len, void * data ,  int(*myCompare)(void* ,void* )  )
{
	char * p = pArray;

	for (int i = 0; i < len;i++)
	{
		//每个元素的首地址
		char * eleAddr = p + eleSize * i;

		//if ( 数组中的变量的元素 == 用户传入的元素)
		if ( myCompare(eleAddr,data)  )
		{
			return 1;
		}
	}

	return 0;

}

int myComparePerson(void * data1,void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	//if ( strcmp( p1->name , p2->name) == 0  &&  p1->age == p2->age)
	//{
	//	return 1;
	//}
	//return  0;

	return   strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;

}

void test02()
{
	struct Person personArray[] =
	{
		{ "aaa", 10 },
		{ "bbb", 20 },
		{ "ccc", 30 },
		{ "ddd", 40 },
	};
	int len = sizeof(personArray) / sizeof(struct Person);
	printAllArray(personArray, sizeof(struct Person), len, myPrintperson);

	//查找数组中指定的元素是否存在
	struct Person p = { "ccc", 30 };

	int ret = findArrayEle(personArray, sizeof(struct Person), len, &p, myComparePerson);

	if (ret)
	{
		printf("找到了元素\n");
	}
	else
	{
		printf("未找到\n");
	}
}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}