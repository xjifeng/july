#include "SList.h"

//��ӡ����
void SLTPrint(SLTNode* Phead)
{
	SLTNode* cur = Phead;
	while (cur!=NULL)
	{
		printf("%d->", cur->Data);
		cur = cur->next;
	}
	printf("NULL\n");
	
}
SLTNode* BuyListNode(SDty x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//���ٿռ䣬�ռ�Ϊ�ṹ��Ĵ�С��
	if (newnode == NULL)
	{
		perror("malloc faild");
	exit(-1);
	}
	newnode->Data = x;
	newnode->next = NULL;
	return newnode;
}
void SLTPushBack(SLTNode** phead, SDty x)
{
	SLTNode* newnode = BuyListNode(x);
	if (*phead ==NULL)
	{
		*phead = newnode;
	}
	else
	{
		SLTNode* tail = *phead;
		while (tail->next !=NULL)
		{
			tail = tail->next; 
		}
		tail->next = newnode;
	}
}
void SLTPushFrond(SLTNode** phead, SDty x)
{
	SLTNode* newnode = BuyListNode(x);

	newnode->next = *phead;
	*phead = newnode;
}
//β��ɾ��
void SLTPopBack(SLTNode** phead)
{
	if ((*phead)->next==NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SLTNode* tailprev = NULL;
		SLTNode* tail = *phead;
		while (tail->next)
		{
			tailprev = tail;
			tail = tail->next;
		}
		free(tail);
		tailprev->next = NULL;
	}
}
void SLTPopFrond(SLTNode** phead)
{
	assert(*phead);
	SLTNode* newhead = (*phead)->next;
	free(*phead);
	*phead = newhead;
}
//���������ݲ���
SLTNode* SListFind(SLTNode* phead, SDty x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->Data == x)
		{
			return cur;
		}
		cur = cur->next;
		
	}
	return NULL;
}
//��pos�������һ����ֵ
void SListInsertAfter(SLTNode* pos, SDty x)
{
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//ɾ��pos�����Ǹ���ֵ
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* posnext = pos->next;
	pos->next = posnext->next;
	free(posnext);
	posnext = NULL;
}
//ɾ��ָ����ֵ
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead);
	assert(pos);
	if (*pphead==pos)
	{
		SLTPopFrond(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next!=pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}
//������ֵ
void SlistInsert(SLTNode** phead, SLTNode* pos, SDty x)
{
	assert(phead);
	assert(pos);
	if (pos==*phead)
	{
		SLTPopFrond(phead,x);
	}
	else
	{
		SLTNode* prev = *phead;
		while (prev->next!=pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuyListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
	
}