#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//利用递归实现字符串逆序遍历
void reversePrint(char * p)
{
	if (*p =='\0')
	{
		return;
	}

	reversePrint(p + 1);

	printf("%c\n", *p);

}

void test01()
{
	char * str = "abcdefg";
	reversePrint(str);
}


int fibonacci(int pos)
{
	if (pos == 1 ||  pos ==2)
	{
		return 1;
	}

	return fibonacci(pos - 1) + fibonacci(pos - 2);
}

void test02()
{
	//斐波那契数列
	// 1 1 2 3 5 8 13 21  34  55...
	printf("第9为数字为：%d\n", fibonacci(9));
	printf("第10为数字为：%d\n", fibonacci(10));
	printf("第20为数字为：%d\n", fibonacci(20));

}


int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}