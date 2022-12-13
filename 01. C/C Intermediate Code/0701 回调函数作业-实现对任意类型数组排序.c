#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void selectSort( 数组地址 , 单个元素的内存大小 , 元素的数量 , 回调函数int(*myCompare)(void * ,void *) )
void selectSort( void * pAddr , int elesize , int len , int(*myCompare)(void * ,void *) )
{
	char * temp = malloc(elesize); // 开辟单个元素大小的空间

	for (int i = 0; i < len;i++)
	{
		int minOrMax = i; //定义最小值 或者 最大值 下标
		
		for (int j = i + 1; j < len;j++)
		{
			//定义出 j元素地址
			char * pJ = (char*)pAddr + elesize * j; //通过偏移量计算当前元素的位置
			char * pMinOrMax = (char*)pAddr + elesize * minOrMax; //通过偏移量计算最大或者最小元素的位置
			//if ( pAddr[j] < pAddr[minOrMax])

			/* 从大到小
			if ( *num1 > *num2)
			{
			return 1;
			}
			return 0;
			*/

			if (  myCompare(pJ,pMinOrMax )) // 通过回调函数来比较两个元素
			{
				minOrMax = j; //更新最小值或者最大值下标
			}
		}

		if ( i != minOrMax)
		{
			//交换i和minOrMax 下标元素
			char * pI = (char*)pAddr + i*elesize;

			char * pMinOrMax = (char*)pAddr + minOrMax * elesize;
			
			//参数:第一个参数是一个指针,指向拷贝目标区域;第二个参数是一个指针,指向被拷贝的内存区域;第三个参数是一个数,指定拷贝内容的内存大小
			memcpy(temp, pI, elesize);
			memcpy(pI, pMinOrMax, elesize);
			memcpy(pMinOrMax, temp, elesize);

		}

	}

	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}

}

///////////////////////////////////////////////////////////////////////////////////////

int myCompareInt(void * data1, void * data2) // 传进来的是int型指针
{
	int * num1 = data1; 
	int * num2 = data2;

	if ( *num1 > *num2)
	{
		return 1;
	}
	return 0;
}

void test01()
{
	int arr[] = { 10, 30, 20, 60, 50, 40 };

	int len = sizeof(arr) / sizeof(int); // 求元素的数量
	
	selectSort(arr, sizeof(int), len, myCompareInt); // 选择排序，回调函数

	for (int i = 0; i < len;i++) // 打印数组
	{
		printf("%d\n", arr[i]);
	}

}

/////////////////////////////////////////////////////////////////////////
struct Person
{
	char name[64];
	int age;
};

int myComparePerson(void * data1, void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	//if ( p1->age < p2->age)
	//{
	//	return  1;
	//}
	//return 0;
	//按照年龄 升序排序
	return  p1->age < p2->age;

}

void test02()
{
	struct Person pArray[] =
	{
		{ "aaa", 10 },
		{ "bbb", 40 },
		{ "ccc", 20 },
		{ "ddd", 30 },
	};
	int len = sizeof(pArray) / sizeof(struct Person);
	selectSort(pArray, sizeof(struct Person), len, myComparePerson);

	for (int i = 0; i < len;i++)
	{
		printf("姓名：%s 年龄:%d\n", pArray[i].name, pArray[i].age);
	}

}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}