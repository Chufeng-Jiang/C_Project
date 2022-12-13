#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma  comment( lib,"./mydll.lib")

int main(){

	printf("10 - 20 = %d\n", mySub(10, 20));


	system("pause");
	return EXIT_SUCCESS;
}