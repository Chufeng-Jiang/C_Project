#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  MYADD(x,y)  ((x) + (y))

//1、宏函数需要加小括号修饰，保证运算的完整性
//2、通常会将频繁、短小的函数  写成宏函数
//3、宏函数 会比普通函数在一定程度上 效率高，省去普通函数入栈、出栈时间上的开销
// 优点： 以空间 换时间


void test01()
{
	printf("%d\n", MYADD(10, 20) * 20 ); //  ((10) + (20)) * 20

}

int main(){
	test01();

	 

	system("pause");
	return EXIT_SUCCESS;
}