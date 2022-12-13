#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma pack(show) //查看当前对齐模数 ，对齐模数是可以改的，改成2的N次方

//第一个属性开始  从0开始偏移
//第二个属性开始  要放在 该类型的大小  与  对齐模数比  取小的值  的整数倍
//所有属性都计算完后，再整体做二次偏移，将整体计算的结果 要放在  结构体最大类型 与对齐模数比  取小的值的 整数倍上 

typedef struct _STUDENT{
						 //对齐模数为1
	int a;    //0 ~ 3      0 ~ 3
	char b;   //4 ~ 7      4  //char的大小是1
	double c; //8 ~ 15     5 ~ 12
	float d;  //16 ~ 19    13 ~ 16
			 //结构体最大类型是double 8，对齐模数是8，整体是20个字节，但20不是8的整数倍，24才是，所以要整体偏移
}Student;


void test01()
{
	printf("sizeof  student  = %d\n", sizeof(Student)); // 答案不是20，是24，内存二次偏移

}

//结构体嵌套结构体时候，子结构体放在该结构体中最大类型 和对齐模数比 的整数倍上即可
typedef struct _STUDENT2{
	char a;  // 0 ~ 7
	Student b; // 8  ~ 31
	double c;  //32 ~ 39
}Student2;

void test02()
{
	printf("sizeof  student  = %d\n", sizeof(Student2));
}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}