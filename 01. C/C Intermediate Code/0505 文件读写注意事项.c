#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//注意事项1
void test01()
{
	FILE * f_read = fopen("./test.txt", "r");
	if (f_read == NULL)
	{
		return;
	}

	char ch;

#if 0
	//aaaaaaaaaEOF
	//         |
	while ( !feof(f_read))
	{
		ch = fgetc(f_read);

		if (feof(f_read))
		{
			break;
		}

		printf("%c", ch);
	}
#endif 

	while ( ( ch = fgetc(f_read)) != EOF)
	{
		printf("%c", ch);
	}

	fclose(f_read);

}

//注意事项2 
struct Hero
{
	char * name; //如果属性开辟到堆区，不要存指针到文件中，要将指针指向的内容存放到文件中
	int age;
};


int main(){
	test01();
	//printf(" aaaaa\n");
	//printf("%caaaaa\n",EOF);
	system("pause");
	return EXIT_SUCCESS;
}