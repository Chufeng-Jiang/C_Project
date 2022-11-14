#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mySort(int arr[] , int len)
{

	for (int i = 0; i < len;i++)
	{
		int min = i; //记录最小值的下标为i
		for (int j = i + 1; j < len;j++)
		{
			if (arr[min]> arr[j])
			{
				//更新真实最小值下标
				min = j;
			}
		}
		//判断真实最小值下标 是否与开始认定的i相等，如果不等，交换元素
		if (i != min)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

}

void printArray(int arr[], int len)
{
	for (int  i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void test01()
{
	//从小到大 排序 利用选择排序
	int arr[] = { 2, 5, 1, 3, 4 };

	int len = sizeof(arr) / sizeof(int);
	mySort(arr, len);

	printArray(arr, len);

}

//void selectSort(char ** pArr, int len)
void selectSort(char * pArr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		int max = i;
		for (int j = i + 1; j < len;j++)
		{
			//if (pArr[max] < pArr[j])
			if ( strcmp(pArr[max],pArr[j]) == -1)
			{
				max = j;
			}
		}
		if ( i != max)
		{
			char * tmp = pArr[i];
			pArr[i] = pArr[max];
			pArr[max] = tmp;
		}
	}

}

void printArray2(char ** pArr, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%s\n", pArr[i]);
	}
}

void test02()
{
	//对指针数组进行排序，排序的算法利用 选择排序   从大到小
	char * pArray[] = { "aaa", "fff", "bbb", "ddd", "ccc", "eee" };

	int len = sizeof(pArray) / sizeof(char*);
	selectSort(pArray, len);

	printArray2(pArray, len);
}

int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}