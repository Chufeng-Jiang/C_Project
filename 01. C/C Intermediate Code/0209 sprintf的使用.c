#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	char buf[1024];
	//memset(buf, 0, 1024);
	//sprintf(buf, "今天 %d 年 %d月  %d日", 2018, 6, 30);

	//printf("%s\n", buf);


	//2. 拼接字符串
	//memset(buf, 0, 1024);
	//char str1[] = "hello";
	//char str2[] = "world";
	//int len = sprintf(buf, "%s%s", str1, str2); //返回值是字符串长度 不包含\0
	//printf("buf:%s len:%d\n", buf, len);

	//3. 数字转字符串
	//memset(buf, 0, 1024);
	//int num = 100;
	//sprintf(buf, "%d", num);
	//printf("buf:%s\n", buf);


	int num = 100;
	//设置宽度 右对齐
	memset(buf, 0, 1024);
	sprintf(buf, "%8d", num);
	printf("buf:%s\n", buf);
	////设置宽度 左对齐
	memset(buf, 0, 1024);
	sprintf(buf, "%-8d", num);
	printf("buf:%sa\n", buf);
	//转成16进制字符串 小写
	memset(buf, 0, 1024);
	sprintf(buf, "0x%x", num);
	printf("buf:%s\n", buf);

	//转成8进制字符串
	memset(buf, 0, 1024);
	sprintf(buf, "0%o", num);
	printf("buf:%s\n", buf);



}

int main(){

	test01();
		

	system("pause");
	return EXIT_SUCCESS;
}