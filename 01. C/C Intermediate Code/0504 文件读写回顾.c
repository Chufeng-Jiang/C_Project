#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//按照字符读写文件：fgetc(), fputc()

void test01()
{
	//写文件

	FILE * f_write = fopen("./test01.txt", "w+");

	if (f_write == NULL)
	{
		return;
	}

	char buf[] = "this is first test";
	for (int i = 0; i < strlen(buf);i++)
	{
		fputc(buf[i], f_write);
	}

	fclose(f_write);

	//读文件
	FILE * f_read = fopen("./test01.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	char ch;
	while ( (ch = fgetc(f_read)) != EOF  )  // EOF  Enf of File
	{
		printf("%c", ch);
	}
	fclose(f_read);
}


//按照行读写文件：fputs(), fgets()
void test02()
{
	//写文件
	FILE * f_write = fopen("./test02.txt", "w");
	if (f_write == NULL)
	{
		return;
	}
	char * buf[] =
	{
		"锄禾日当午\n",
		"汗滴禾下土\n",
		"谁知盘中餐\n",
		"粒粒皆辛苦\n",
	};

	for (int i = 0; i < 4;i++)
	{
		fputs(buf[i], f_write);
	}

	fclose(f_write);

	//读文件
	FILE * f_read = fopen("./test02.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	while ( !feof(f_read ))
	{
		char buf[1024] = { 0 };
		fgets(buf, 1024, f_read);
		printf("%s", buf);
	}

	fclose(f_read);
}

//按照块读写文件：fread(), fwirte()
struct Hero
{
	char name[64];
	int age;
};
void test03()
{
	//写文件  wb二进制方式
	FILE * f_write = fopen("./test03.txt", "wb");
	if (f_write == NULL)
	{
		return;
	}

	struct Hero heros[4] = 
	{
		{ "亚瑟" , 18 },
		{ "赵云", 28 },
		{ "妲己", 19 },
		{ "孙悟空", 99 },
	};

	for (int i = 0; i < 4;i++)
	{
		//参数1 数据地址  参数2  块大小   参数3  块个数   参数4  文件指针
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}

	fclose(f_write);

	//读文件  
	FILE * f_read = fopen("./test03.txt", "rb");  // read binary
	if (f_read == NULL)
	{
		return;
	}

	struct Hero temp[4];
	//参数1 数据地址  参数2  块大小   参数3  块个数   参数4  文件指针
	fread(&temp, sizeof(struct Hero), 4, f_read);

	for (int i = 0; i < 4;i++)
	{
		printf("姓名:%s  年龄：%d \n", temp[i].name, temp[i].age);
	}
	fclose(f_read);
}

//按照格式化读写文件：fprintf(), fscanf()
void test04()
{
	//写文件
	FILE * f_write = fopen("./test04.txt", "w");
	if (f_write == NULL)
	{
		return;
	}

	fprintf(f_write, "hello world %d年 %d月 %d日", 2018, 7, 5);

	//关闭文件
	fclose(f_write);


	//读文件
	FILE * f_read = fopen("./test04.txt", "r");
	if (f_read == NULL)
	{
		return;
	}

	char buf[1024] = { 0 };
	while (!feof(f_read))
	{
		fscanf(f_read, "%s", buf);
		printf("%s\n", buf);
	}

	fclose(f_read);
}

//按照随机位置读写文件
void test05()
{
	FILE * f_write = fopen("./test05.txt", "wb");
	if (f_write == NULL)
	{
		return;
	}

	struct Hero heros[4] =
	{
		{ "亚瑟", 18 },
		{ "赵云", 28 },
		{ "妲己", 19 },
		{ "孙悟空", 99 },
	};

	for (int i = 0; i < 4; i++)
	{
		//参数1 数据地址  参数2  块大小   参数3  块个数   参数4  文件指针
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}

	fclose(f_write);


	//读取妲己数据
	FILE * f_read = fopen("./test05.txt", "rb");
	if (f_read == NULL)
	{
		//error 宏 
		
		//printf("文件打开失败\n");
		perror("文件打开失败");
		return;
	}

	//创建临时结构体
	struct Hero temp;

	//改变文件光标位置
	fseek(f_read, sizeof(struct Hero) *2, SEEK_SET);

	fseek(f_read, -(long)sizeof(struct Hero) * 2, SEEK_END);

	rewind(f_read); //将文件光标置首

	fread(&temp, sizeof(struct Hero), 1, f_read);

	printf("姓名： %s 年龄： %d\n", temp.name, temp.age);

	fclose(f_read);

}


int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	system("pause");
	return EXIT_SUCCESS;
}