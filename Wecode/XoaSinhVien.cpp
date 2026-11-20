bool RemoveHead(LIST& L)
{
    if (L.pHead == NULL) return 0;
    NODE* t = L.pHead;
    if (L.pHead == L.pTail)
    {
        L.pHead = NULL;
        L.pTail = NULL;
    }
    else
    {
        L.pHead = L.pHead->pNext;
    }
    delete t;
    return 1;
}
bool RemoveAfterQ(LIST& L, NODE* q, string s)
{
    if (q == NULL || q->pNext == NULL) return 0;
    NODE* t = q->pNext;
    if (t->key.HoTen != s) return 0;
    if (q->pNext->pNext == NULL)
    {
        L.pTail = q;
    }
    q->pNext = q->pNext->pNext;
    delete t;
    return 1;
}
bool Xoa_TheoHoTen(LIST& L, string x)
{
    if (L.pHead == NULL) return 0;
    NODE* t = L.pHead;
    if (L.pHead->key.HoTen == x)
    {
        return RemoveHead(L);
    }
    while (t->pNext != NULL && t->pNext->key.HoTen != x)
    {
        t = t->pNext;
    }
    return RemoveAfterQ(L, t, x);
}
