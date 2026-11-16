#include<iostream>
using namespace std;
struct NODE
{
    NODE* next;
    int key;
};
struct LIST
{
    NODE* head;
    NODE* tail;
};
void CreateEmptyList(LIST& L)
{
    L.head = NULL;
    L.tail = NULL;
}
NODE* CreateNode(int x)
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
void AddHead(LIST& L, NODE* t)
{
    if (L.head == NULL)
    {
        L.head = t;
        L.tail = t;
        return;
    }
    else
    {
        t->next = L.head;
        L.head = t;
    }
}
void CreateList(LIST& L)
{
    int type;
    int x;
    while (cin >> type)
    {
        if (type == -1) break;
        else
        {
            cin >> x;
            if (type == 0)
            {
                NODE* t = CreateNode(x);
                AddHead(L, t);
            }
            else if (type == 1)
            {
                NODE* t = CreateNode(x);
                AddTail(L, t);
            }
        }
    }
}
void PrintList(LIST& L)
{
    if (L.head == NULL)
    {
        cout << "Empty List.";
        return;
    }
    NODE* c = L.head;
    while (c != NULL)
    {
        cout << c->key << " ";
        c = c->next;
    }
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList(L);

    return 0;
}
