#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//calloc
void test01()
{
	//int * p = malloc(sizeof(int)* 10);

	int * p = calloc(10, sizeof(int)); //calloc 分配在堆区，与malloc不同的是 calloc会初始化数据为0

	for (int i = 0; i < 10;i++)
	{
		printf("%d\n", p[i]);
	}

	if ( p != NULL)
	{
		free(p);
		p = NULL;
	}

}


//realloc  重新分配内存
void test02()
{
	int * p = malloc(sizeof(int)* 10);

	for (int i = 0; i < 10;i++)
	{
		p[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}

	printf("%d\n", p);

	//如果重新分配的内存比原来大，那么不会初始化新空间为0
	p = realloc(p, sizeof(int)* 20);

	printf("%d\n", p);

	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", p[i]);
	}

	//如果重新分配的内存比原来小，那么释放后序空间，只有权限操作申请空间
	p = realloc(p, sizeof(int)* 5);
	printf("%d\n", p);
	printf("%d\n", p[0]);
	printf("%d\n", p[5]);
}




int main(){



	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}