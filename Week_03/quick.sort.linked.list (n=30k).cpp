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
        {
            AddTail(L2, p);
        }
        else
        {
            AddTail(L1, p);
        }
        p = next;
    }
    L.pHead = NULL;
    L.pTail = NULL;
}
void Join(LIST& L, LIST& L1, NODE*& pivot, LIST& L2)
{
    if (L1.pHead != NULL)
    {
        L.pHead = L1.pHead;
        L1.pTail->pNext = pivot;
    }
    else
    {
        L.pHead = pivot;
    }
    if (L2.pHead != NULL)
    {
        pivot->pNext = L2.pHead;
        L.pTail = L2.pTail;
    }
    else
    {
        pivot->pNext = NULL;
        L.pTail = pivot;
    }

}
void quicksort_ascending(LIST& L)
{
    if (L.pHead == NULL || L.pHead == L.pTail) return;
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    NODE* pivot = NULL;
    Partition(L, L1, pivot, L2);
    quicksort_ascending(L1);
    quicksort_ascending(L2);
    Join(L, L1, pivot, L2);
}