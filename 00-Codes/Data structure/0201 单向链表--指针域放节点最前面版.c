#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//节点结构体
struct LinkNode
{
	//只维护指针域
	struct LinkNode*next;
};

//链表结构体
struct LList
{
	struct LinkNode pHeader;
	int m_Size;
};

typedef void * LinkList;

//初始化链表
LinkList init_LinkList()
{
	struct LList * myList = malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.next = NULL;
	myList->m_Size = 0;

	return myList;
}

//插入
void insert_LinkList(LinkList list ,  int pos , void * data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList * myList = list;
	if (pos < 0 || pos >myList->m_Size - 1)
	{
		//无效位置进行尾插
		pos = myList->m_Size;
	}

	//用户数据前4个字节 由我们来使用
	struct LinkNode * myNode = data;

	//找插入节点的前驱节点
	struct LinkNode * pCurrent = &myList->pHeader;

	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}
	//pCurrent是前驱节点位置


	//更改指针指向
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	//更新链表长度
	myList->m_Size++;
}

//遍历链表
void foreach_LinkList(LinkList list, void(*myForeach)(void *))
{
	if (list == NULL)
	{
		return;
	}

	struct LList * myList = list;

	struct LinkNode * myNode = myList->pHeader.next;

	for (int i = 0; i < myList->m_Size;i++)
	{
		myForeach(myNode);
		myNode = myNode->next;
	}

}

//删除节点 按位置删除
void removeByPos_ListList( LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	struct LList * mylist = list;

	if (pos < 0 ||  pos > mylist->m_Size - 1)
	{
		return;
	}

	//找待删除节点的前驱位置
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	//记录待删除节点
	struct LinkNode * pDel = pCurrent->next;


	//更改指针指向
	pCurrent->next = pDel->next;

	//free(pDel); //数据是用户管理开辟的，用户管理释放

	//更新长度
	mylist->m_Size--;
}

//销毁数组
void destroy_LinkList( LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	free(list);
	list = NULL;

}






//测试

struct Person
{
	void * node;
	char name[64];
	int age;
};


void myPrintPerson(void * data)
{
	struct Person * p = data;
	printf("姓名： %s  年龄： %d \n", p->name, p->age);
}

void test01()
{

	//初始化链表
	LinkList mylist = init_LinkList();

	//创建数据
	struct Person p1 = { NULL,"aaa", 10 };
	struct Person p2 = { NULL,"bbb", 20 };
	struct Person p3 = { NULL,"ccc", 30 };
	struct Person p4 = { NULL,"ddd", 40 };
	struct Person p5 = { NULL,"eee", 50 };

	//插入节点
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 1, &p3);
	insert_LinkList(mylist, -1, &p4);
	insert_LinkList(mylist, 0, &p5);


	//遍历链表
	// eee bbb  ccc aaa ddd
	foreach_LinkList(mylist, myPrintPerson);

	//删除 aaa
	removeByPos_ListList(mylist, 3);
	printf("-----------------------\n");
	foreach_LinkList(mylist, myPrintPerson);

	//销毁数组
	destroy_LinkList(mylist);
	mylist = NULL;

}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}