#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//可读性高
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	/*int arr2[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr3[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };*/


	//除了两种特殊情况外 ，二维数组名称是 指向第一个一维数组  数组指针
	//特殊情况1  sizeof
	//特殊情况2  对数组名取地址 &arr  获取的是二维数组的 数组指针 int(*p)[3][3] = &arr;
	//printf("%d\n", sizeof(arr));

	int(*pArray)[3] = arr;

	//访问二维数组中的 6 这个元素
	printf("%d\n", arr[1][2]);  //给人看
	printf("%d\n", *(*(pArray + 1) + 2)); //给机器看

}


//void printArray(int (*array)[3], int row, int col)
//void printArray(int array[][3], int row ,int col)
void printArray(int array[3][3], int row ,int col) //array[3][3] 等价于 一维数组指针   int (*array)[3]
{
	for (int i = 0; i < row; i ++)
	{
		for (int j = 0; j < col;j ++)
		{
			//printf("%d ", array[i][j]);
			printf("%d ", *(*(array + i) + j));
		}
		printf("\n");
	}
}

//二维数组做函数参数
void test02()
{
	int arr[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	printArray(arr, 3, 3);

}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}