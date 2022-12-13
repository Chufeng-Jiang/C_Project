#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//配置信息 结构体
struct ConfigInfo
{
	char key[64];
	char value[64];
};

//获取有效行数
int getFileLines(char* filePath);

//检测当前行是否是有效信息
int isValidLines(char* str);

//解析文件
void parseFile(char* filePath, int lines, struct  ConfigInfo** configinfo);

//根据key获取对应value
char* getInfoByKey(char* key, struct ConfigInfo* configinfo, int len);

//释放内存
void freeConfigInfo(struct ConfigInfo* configinfo);