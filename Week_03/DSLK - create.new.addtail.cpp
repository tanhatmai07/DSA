#include <iostream>
using namespace std;

struct NODE
{
    int key;
    NODE* pNext;
};
struct LIST
{
    NODE* pHead;
    NODE* pTail;
};
void CreateEmptyList(LIST& L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
NODE* CreateNode(int x)
{
    NODE* t = new NODE;
    t->key = x;
    t->pNext = NULL;
    return t;
}
void AddTail(LIST& L, NODE* t)
{
    if (L.pHead == NULL)
    {
        L.pHead = t;
        L.pTail = t;
        return;
    }
    else
    {
        L.pTail->pNext = t;
        L.pTail = t;
    }
}
void CreateList(LIST& L)
{
    int x;
    while (cin >> x)
    {
        if (x == -1) break;
        else
        {
            NODE* t = CreateNode(x);
            AddTail(L, t);
        }
    }
}
void PrintList(NODE* pHead)
{
    if (pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    NODE* c = pHead;
    while (c != NULL)
    {
        cout << c->key << " ";
        c = c->pNext;
    }
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList(L.pHead);

    return 0;
}
