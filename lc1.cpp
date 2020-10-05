#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
    List L3,p;
    L3=(PtrToNode)malloc(sizeof(struct Node));
    L3->Next=NULL;
    p=L3;
    while(L1->Next&&L2->Next)
    {
        if(L1->Next->Data<L2->Next->Data) 
        {
            p->Next=L1->Next;
            p->Next->Next=NULL;
            L1->Next=L1->Next->Next;
            p=p->Next;
        }
        else 
        {
            p->Next=L2->Next;
            p->Next->Next=NULL;
            L2->Next=L2->Next->Next;
            p=p->Next;
        }
    }
    if(L1->Next)
    {
        p->Next=L1->Next;
        L1->Next=NULL;
    }
    if(L2->Next)
    {
        p->Next=L2->Next;
        L2->Next=NULL;
    }
    return L3;
}