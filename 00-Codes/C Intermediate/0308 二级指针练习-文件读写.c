#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//获取有效行数
int getFileLines(FILE * pFile)
{
	if (pFile == NULL)
	{
		return -1;
	}

	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf,1024,pFile) != NULL)
	{
		//printf("%s", buf);
		lines++;
	}

	//将文件光标置首
	fseek(pFile, 0, SEEK_SET);
	return lines;

}

//读取数据放入到pArray中
void readFileData(FILE * pFile, int len, char ** pArray)
{
	if (pFile == NULL)
	{
		return;
	}
	if (len <= 0 )
	{
		return;
	}
	if ( pArray ==NULL)
	{
		return;
	}
	char buf[1024] = { 0 };
	int index = 0;
	while (fgets(buf, 1024, pFile) != NULL)
	{
		/*
		aaaaaaaaaa
		bbbb
		cccccc
		*/
		int currentLen = strlen(buf) +1 ;
		char * currentStrP = malloc(sizeof(char)* currentLen);
		strcpy(currentStrP, buf);
		pArray[index++] = currentStrP;

		memset(buf, 0, 1024);
	}

}

void showFileData(char ** pArray, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%d行的数据为 %s", i + 1, pArray[i]);
	}
	
}

void test01()
{
	//打开文件
	FILE * pFile =	fopen("./test.txt", "r");
	if (pFile == NULL)
	{
		printf("文件打开失败\n");
		return;
	}

	//统计有效行数
	int len =  getFileLines(pFile);
	//printf("文件的有效行数为：%d\n", len);
	char ** pArray =  malloc(sizeof(char *)* len);

	//读取文件中的数据并且放入到 pArray中
	readFileData(pFile, len, pArray);

	//读取数据
	showFileData(pArray , len);

	//释放堆区内容
	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
	free(pArray);
	pArray = NULL;
	//关闭文件
	fclose(pFile);
}

int main(){


	test01();


	system("pause");
	return EXIT_SUCCESS;
}