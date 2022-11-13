#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void allocateSpace(int ** p)
{
	int *  temp = malloc(sizeof(int)* 10);
	for (int i = 0; i < 10;i++)
	{
		temp[i] = 100 + i;
	}
	*p = temp;

}

void printArray(int ** pArray, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%d\n", (*pArray)[i]);
	}
}

void freeSpace(int ** pArray)
{
	if (*pArray != NULL)
	{
		free(*pArray);
		*pArray = NULL;
	}
}


//void freeSpace(int * pArray) //同级指针释放内存
//{
//	if (pArray != NULL)
//	{
//		free(pArray);
//		pArray = NULL;
//	}
//}

void test01()
{
	int * p = NULL;
	allocateSpace(&p);

	printArray(&p, 5);

	freeSpace(&p, 5);
	
	//freeSpace(p, 5);
	// p=NULL; // 同级指针释放内存，需要最后手动设置p为空
	
	if (p == NULL)
	{
		printf("空指针\n");
	}
	else
	{
		printf("野指针\n");
	}
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}