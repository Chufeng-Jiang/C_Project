#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void selectSort( �����ַ , ����Ԫ�ص��ڴ��С , Ԫ�ص����� , �ص�����int(*myCompare)(void * ,void *) )
void selectSort( void * pAddr , int elesize , int len , int(*myCompare)(void * ,void *) )
{
	char * temp = malloc(elesize); // ���ٵ���Ԫ�ش�С�Ŀռ�

	for (int i = 0; i < len;i++)
	{
		int minOrMax = i; //������Сֵ ���� ���ֵ �±�
		
		for (int j = i + 1; j < len;j++)
		{
			//����� jԪ�ص�ַ
			char * pJ = (char*)pAddr + elesize * j; //ͨ��ƫ�������㵱ǰԪ�ص�λ��
			char * pMinOrMax = (char*)pAddr + elesize * minOrMax; //ͨ��ƫ����������������СԪ�ص�λ��
			//if ( pAddr[j] < pAddr[minOrMax])

			/* �Ӵ�С
			if ( *num1 > *num2)
			{
			return 1;
			}
			return 0;
			*/

			if (  myCompare(pJ,pMinOrMax )) // ͨ���ص��������Ƚ�����Ԫ��
			{
				minOrMax = j; //������Сֵ�������ֵ�±�
			}
		}

		if ( i != minOrMax)
		{
			//����i��minOrMax �±�Ԫ��
			char * pI = (char*)pAddr + i*elesize;

			char * pMinOrMax = (char*)pAddr + minOrMax * elesize;
			
			//����:��һ��������һ��ָ��,ָ�򿽱�Ŀ������;�ڶ���������һ��ָ��,ָ�򱻿������ڴ�����;������������һ����,ָ���������ݵ��ڴ��С
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

int myCompareInt(void * data1, void * data2) // ����������int��ָ��
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

	int len = sizeof(arr) / sizeof(int); // ��Ԫ�ص�����
	
	selectSort(arr, sizeof(int), len, myCompareInt); // ѡ�����򣬻ص�����

	for (int i = 0; i < len;i++) // ��ӡ����
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
	//�������� ��������
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
		printf("������%s ����:%d\n", pArray[i].name, pArray[i].age);
	}

}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}