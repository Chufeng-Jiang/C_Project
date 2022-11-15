#include "Config.h"

int getFileLines(char* filePath)  // �������ļ�ָ��
{
	FILE* file = fopen(filePath, "r"); // �����ļ���ַ���ԡ������ķ�ʽ���ļ�

	if (file == NULL)
	{
		return -1;
	}

	char buf[1024] = { 0 };	 // ����һ����СΪ1024�ֽڵ�char�ͻ�����
	int lines = 0;			 //	��ʼ������Ϊ0

	// char *fgets( char *buf, int n, FILE *fp );
	// ���� fgets() �� fp ��ָ����������ж�ȡ n - 1 ���ַ�������Ѷ�ȡ���ַ������Ƶ������� buf��
	// �������׷��һ�� null �ַ�����ֹ�ַ����������������ڶ�ȡ���һ���ַ�֮ǰ������һ�����з� '\n' ���ļ���ĩβ EOF��
	// ��ֻ�᷵�ض�ȡ�����ַ����������з���
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
	// �ú����������ַ��� str �е�һ�γ����ַ� c ��λ�ã����δ�ҵ����ַ��򷵻� NULL��
	if (strchr(str, ':') == NULL)
	{
		return 0; //���ؼ� ������Ч��
	}

	return 1;
}

//�����ļ�,��Config.h������
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

	while (fgets(buf, 1024, file) != NULL)	  // һ�ζ�ȡ1023���ַ� -> ��������պ�fgets�µ�һ�в�Ϊnull�����ѭ��
	{
		if (isValidLines(buf))
		{
			//��Ч��Ϣ��ȥ����
			//ÿ�ζ�ȡ�������key��value����
			//heroName:aaaa\n
			memset(info[index].key, 0, 64);	 // info��ָ��ṹ��ConfigInfo��ָ�룬�ṹ��ConfigInfo �����������飬������ͷ�ļ���
			memset(info[index].value, 0, 64);

			char* pos = strchr(buf, ':');

			strncpy(info[index].key, buf, pos - buf); // �ѣ�ǰ��Ľ�ȡ����
			strncpy(info[index].value, pos + 1, strlen(pos + 1) - 1); // �ѣ�������ݽ�ȡ���������ǲ���ȡĩβ�Ļ���

			index++; //����+1
		}

		memset(buf, 0, 1024);
	}
	*configinfo = info; //	  configinfo�Ƕ���ָ�룬������޸ĺ�����ݵ�ַ���ظ�*configinfo 
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

//�ͷ��ڴ�
void freeConfigInfo(struct ConfigInfo* configinfo)
{
	if (configinfo != NULL)
	{
		free(configinfo);
		configinfo = NULL;
	}
}