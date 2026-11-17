NODE* SeparateHead(LIST& L)
{
    if (L.pHead == NULL)
        return NULL;
    else if (L.pHead == L.pTail)
    {
        NODE* t = L.pHead;
        L.pHead = NULL;
        L.pTail = NULL;
        return t;
    }
    else
    {
        NODE* t = L.pHead;
        L.pHead = L.pHead->pNext;
        t->pNext = NULL;
        return t;
    }
}