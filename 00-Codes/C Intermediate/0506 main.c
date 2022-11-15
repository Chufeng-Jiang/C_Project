#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Config.h"


int main() {

	char* filePath = "./config.txt";// 设置文件路径
	int len = getFileLines(filePath);	// 调用Config.c中的函数，把文件指针传过去
	printf("文件的有效行数为：%d\n", len);

	struct ConfigInfo* configInfo = NULL;
	parseFile(filePath, len, &configInfo);

	//测试根据key获取value
	printf("heroId = %s\n", getInfoByKey("heroId", configInfo, len));
	printf("heroName = %s\n", getInfoByKey("heroName", configInfo, len));
	printf("heroAtk = %s\n", getInfoByKey("heroAtk", configInfo, len));
	printf("heroDef = %s\n", getInfoByKey("heroDef", configInfo, len));
	printf("heroInfo = %s\n", getInfoByKey("heroInfo", configInfo, len));

	//释放空间
	freeConfigInfo(configInfo);
	configInfo = NULL;


	system("pause");
	return EXIT_SUCCESS;
}