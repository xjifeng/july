#include "Source.h"

//初始化数组
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)*4);
	if (ps->a==NULL)
	{
		perror("malloc failed");
			exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}
//数据删除
void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a= NULL;
	ps->size=ps->capacity = 0;
}
//检查是否需要扩容
void SeqListCheck(SeqList* ps) 
{
	if (ps->size == ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, ps->capacity * 2 * (sizeof(SLDateType)));//扩容内存，原有的基础上增加2倍
		if (tmp == NULL)
		{
			perror("Realloc failed");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}
//数据打印
void SeqListPrint(SeqList* ps)
{
	int i = 0;
	for ( i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//数据的新增
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	/*SeqListCheck(ps);*/
	/*ps->a[ps->size] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}
//数据尾部删除
void SeqListPopBack(SeqList* ps)
{
	/*assert(ps->size > 0);
	ps->size--;*/
	SeqListErase(ps, ps->size-1);
}
//头部插入数据
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	//SeqListCheck(ps);//检查空间是否足够
	//int end = ps->size - 1;
	//while (end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}
	//ps->a[0] = x;
	//ps->size++;
	SeqListInsert(ps, 0, x);
}
//头部删除数据
void SeqListPopFront(SeqList* ps)
{
	//int start = 1;
	//while (start<ps->size)
	//{
	//	ps->a[start - 1] = ps->a[start];
	//	++start;
	//}
	//ps->size--;
	SeqListErase(ps, 0);

}
//从某个地方插入数据
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheck(ps);
	int end = ps->size - 1;
	while (end>=pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
//删除某个地方的数据；
void SeqListErase(SeqList* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin<ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}
//查找数据；
int SeqListFind(SeqList* ps, SLDateType x)
{
	int i;
	for ( i = 0; i < ps->size; i++)
	{
		if (ps->a[i]==x)
		{
			return i;
		}
	}
	return -1;
}
void SeqlistModify(SeqList* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	printf("修改成多少呢?");
	int c = 0;
	scanf("%d", &c);
	ps->a[pos] = c;
}