#include "Config.h"

int getFileLines(char* filePath)  // 参数：文件指针
{
	FILE* file = fopen(filePath, "r"); // 接收文件地址，以“读”的方式打开文件

	if (file == NULL)
	{
		return -1;
	}

	char buf[1024] = { 0 };	 // 设置一个大小为1024字节的char型缓冲区
	int lines = 0;			 //	初始化行数为0

	// char *fgets( char *buf, int n, FILE *fp );
	// 函数 fgets() 从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buf，
	// 并在最后追加一个 null 字符来终止字符串。如果这个函数在读取最后一个字符之前就遇到一个换行符 '\n' 或文件的末尾 EOF，
	// 则只会返回读取到的字符，包括换行符。
	while (fgets(buf, 1024, file) != NULL)
	{
		if (isValidLines(buf))
		{
			lines++;
		}
		memset(buf, 0, 1024);
	}

	return lines;

	fclose(file);
}

int isValidLines(char* str)
{
	// char *strchr(const char *str, int c)
	// 该函数返回在字符串 str 中第一次出现字符 c 的位置，如果未找到该字符则返回 NULL。
	if (strchr(str, ':') == NULL)
	{
		return 0; //返回假 代表无效行
	}

	return 1;
}

//解析文件,在Config.h中声明
void parseFile(char* filePath, int lines, struct  ConfigInfo** configinfo)
{
	struct ConfigInfo* info = malloc(sizeof(struct ConfigInfo) * lines);

	if (info == NULL)
	{
		return;
	}

	FILE* file = fopen(filePath, "r");
	if (file == NULL)
	{
		return;
	}
	char buf[1024] = { 0 };
	int index = 0;

	while (fgets(buf, 1024, file) != NULL)	  // 一次读取1023个字符 -> 缓冲区清空后，fgets新的一行不为null则继续循环
	{
		if (isValidLines(buf))
		{
			//有效信息才去解析
			//每次读取，先清空key和value数组
			//heroName:aaaa\n
			memset(info[index].key, 0, 64);	 // info是指向结构体ConfigInfo的指针，结构体ConfigInfo 里有两个数组，定义在头文件里
			memset(info[index].value, 0, 64);

			char* pos = strchr(buf, ':');

			strncpy(info[index].key, buf, pos - buf); // 把：前面的截取出来
			strncpy(info[index].value, pos + 1, strlen(pos + 1) - 1); // 把：后的内容截取出来，但是不截取末尾的换行

			index++; //行数+1
		}

		memset(buf, 0, 1024);
	}
	*configinfo = info; //	  configinfo是二级指针，这里把修改后的数据地址传回给*configinfo 
}

char* getInfoByKey(char* key, struct ConfigInfo* configinfo, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (strcmp(key, configinfo[i].key) == 0)
		{
			return configinfo[i].value;
		}
	}

	return NULL;
}

//释放内存
void freeConfigInfo(struct ConfigInfo* configinfo)
{
	if (configinfo != NULL)
	{
		free(configinfo);
		configinfo = NULL;
	}
}