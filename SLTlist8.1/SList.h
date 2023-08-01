#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SDty;

typedef struct SlistNode
{
	SDty Data;
	struct SlistNode* next;
}SLTNode;

void SLTPrint(SLTNode* Phead);
SLTNode* BuyListNode(SDty x);
void SLTPushBack(SLTNode** phead, SDty x);
void SLTPushFrond(SLTNode** phead, SDty x);
void SLTPopBack(SLTNode** phead);
void SLTPopFrond(SLTNode** phead);
SLTNode* SListFind(SLTNode* phead, SDty x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SLTNode** pos, SDty x);
//插入数值；
void SlistInsert(SLTNode** phead, SLTNode* pos, SDty x);
//删除pos位置的值;
void SLTErase(SLTNode** pphead, SLTNode* pos);
// 单链表删除pos位置之后的值
void SListEraseAfter(SLTNode* pos);
// 单链表的销毁
void SListDestroy(SLTNode* plist);
