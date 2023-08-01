#include "SList.h"

//打印链表
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
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//开辟空间，空间为结构体的大小。
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
//尾部删除
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
//单链表数据查找
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
//在pos后面插入一个数值
void SListInsertAfter(SLTNode* pos, SDty x)
{
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除pos后面那个数值
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* posnext = pos->next;
	pos->next = posnext->next;
	free(posnext);
	posnext = NULL;
}
//删除指定数值
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
//插入数值
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