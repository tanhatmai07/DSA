#include<iostream>
using namespace std;
struct node
{
    int key;
    node* next;
};
struct LIST {
    node* head;
    node* tail;
};
void CreateEmptyList(LIST& l)
{
    l.head = NULL;
    l.tail = NULL;
}
node* CreateNode(int x)
{
    node* t = new node;
    t->key = x;
    t->next = NULL;
    return t;
}
void AddTail(LIST& l, node* t)
{
    if (l.head == NULL)
    {
        l.head = t;
        l.tail = t;
        return;
    }
    else
    {
        l.tail->next = t;
        l.tail = t;
    }
}
void CreateList(LIST& l)
{
    int x;
    while (cin >> x)
    {
        if (x == -1) break;
        node* t = CreateNode(x);
        AddTail(l, t);
    }
}
void PrintList(LIST l)
{
    if (l.head == NULL)
    {
        cout << "Empty List.";
        return;
    }
    node* c = l.head;
    while (c != NULL)
    {
        cout << c->key << " ";
        c = c->next;
    }
}
void RemoveX(LIST& l, int x)
{
    if (l.head == NULL) return;
    else if ((l.head == l.tail) && l.head->key == x)
    {
        delete l.head;
        l.head = NULL;
        l.tail = NULL;
        return;
    }
    else
    {
        if (l.head->key == x)
        {
            node* t = l.head;
            l.head = l.head->next;
            if (l.head == NULL)
                l.tail = NULL;
            delete t;
            return;
        }
        node* c = l.head;
        while (c->next != NULL)
        {
            if (c->next->key == x)
            {
                node* t = c->next;
                c->next = c->next->next;
                if (t == l.tail) l.tail = c;
                delete t;
                return;
            }
            c = c->next;
        }
    }
}
int main() {
    LIST L;
    int X;
    CreateEmptyList(L);

    CreateList(L);
    std::cin >> X;
    RemoveX(L, X);
    PrintList(L);

    return 0;
}
