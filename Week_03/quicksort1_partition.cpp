void Partition(LIST& L, LIST& L1, NODE*& pivot, LIST& L2)
{
    pivot = L.pHead;
    NODE* p = pivot->pNext;
    pivot->pNext = NULL;
    while (p != NULL)
    {
        NODE* next = p->pNext;
        p->pNext = NULL;
        if (p->info > pivot->info)
            AddTail(L2, p);
        else if (p->info <= pivot->info)
            AddTail(L1, p);
        p = next;
    }
    L.pHead = NULL;
    L.pTail = NULL;
}