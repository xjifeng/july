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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SLTNode** pos, SDty x);
//������ֵ��
void SlistInsert(SLTNode** phead, SLTNode* pos, SDty x);
//ɾ��posλ�õ�ֵ;
void SLTErase(SLTNode** pphead, SLTNode* pos);
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SLTNode* pos);
// �����������
void SListDestroy(SLTNode* plist);
