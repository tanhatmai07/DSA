#include<iostream>
using namespace std;
struct NODE
{
    int key;
    NODE* next;
};
struct LIST {
    NODE* head;
    NODE* tail;
};
void CreateEmptyList(LIST& L)
{
    L.head = NULL;
    L.tail = NULL;
}
NODE* CreateNode(LIST& L, int x)
{
    NODE* t = new NODE;
    t->key = x;
    t->next = NULL;
    return t;
}
void AddTail(LIST& L, NODE* t)
{
    if (L.head == NULL)
    {
        L.head = t;
        L.tail = t;
        return;
    }
    else
    {
        L.tail->next = t;
        L.tail = t;
    }
}
void CreateList(LIST& L)
{
    int x;
    while (cin >> x)
    {
        if (x == -1) break;
        NODE* t = CreateNode(L, x);
        AddTail(L, t);
    }
}
void RemoveTail(LIST& L)
{
    if (L.head == NULL) return;
    else if (L.head == L.tail)
    {
        delete L.head;
        L.head = NULL;
        L.tail = NULL;
        return;
    }
    else
    {
        NODE* c = L.head;
        while (c->next->next != NULL)
        {
            c = c->next;
        }
        NODE* t = L.tail;
        c->next = NULL;
        delete t;
        L.tail = c;
    }
}
void PrintList(LIST L)
{
    if (L.head == NULL)
    {
        cout << "Empty List.";
    }
    else
    {
        NODE* c = L.head;
        while (c != NULL)
        {
            cout << c->key << " ";
            c = c->next;
        }
    }
}
int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    RemoveTail(L);
    PrintList(L);

    return 0;
}
