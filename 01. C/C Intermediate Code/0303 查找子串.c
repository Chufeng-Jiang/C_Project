#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	算法优化
	memcmp(str , subStr ,3 ) == 0;
*/
int myStrstr(char * str , char * subStr)
{
	int num = 0;
	while (*str != '\0')
	{
		if (*str != *subStr)
		{
			num++;
			str++;
			continue;
		}

		//创建两个临时指针 做二次对比
		char * tmpStr = str;
		char * tmpSubstr = subStr;

		while (*tmpSubstr != '\0')
		{
			if (*tmpStr != *tmpSubstr)
			{
				//匹配失败
				num++;
				str++;
				break;
			}
			tmpStr++;
			tmpSubstr++;
		}
		if (*tmpSubstr == '\0')
		{
			//匹配成功
			return num;
		}

	}

	return -1;
}

void test01()
{
	char * str = "abdnfcdefgdfasdfaf";

	int ret = myStrstr(str, "dnf");

	if ( ret != -1)
	{
		printf("找到了子串，位置为：%d\n", ret);
	}
	else
	{
		printf("未找到子串\n");
	}

}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}