#include "SList.h"

int main()
{
	SLTNode* slist=NULL;
	SLTPushBack(&slist, 1);
	SLTPushBack(&slist, 2);
	SLTPushBack(&slist, 3);
	SLTPushBack(&slist, 4);
	SLTPushFrond(&slist, 5);
	SLTPrint(slist);
	SLTNode* find=	SListFind(slist,4);
	SListInsertAfter(find, 6);
	SLTPrint(slist);
	//SLTNode* dele = SListFind(slist,5);
	//SListEraseAfter(dele);
	SLTPrint(slist);
	SLTNode* dele2 = SListFind(slist,2);
	SLTNode* find2 = SListFind(slist, 2);
	SlistInsert(&slist, find2, 888);
	SLTErase(&slist,dele2);
	SLTPrint(slist);
	return 0;

}