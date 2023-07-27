#include "Source.h"

int main()
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 2);
	SeqListPrint(&sl);
	SeqListPushBack(&sl, 134);
	SeqListPushFront(&sl, 24);
	SeqListPushFront(&sl, 34);
	SeqListPushFront(&sl, 544);
	SeqListPushFront(&sl, 22134);
	SeqListPrint(&sl);
	SeqListPopFront(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListInsert(&sl, 3, 40);
	SeqListPrint(&sl);
	SeqListErase(&sl, 3);
	SeqListPrint(&sl);
	int x = 0;
	printf("������Ҫ�޸ĵ�����");
	scanf("%d", &x);
	int b = SeqListFind(&sl, x);
	if (b!=-1)
	{
		SeqlistModify(&sl, b);
	}
	SeqListPrint(&sl);
	SeqListDestroy(&sl);
	
	
 }