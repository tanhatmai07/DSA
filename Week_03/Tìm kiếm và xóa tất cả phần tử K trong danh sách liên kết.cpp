void TimKiemVaXoa(LIST& L, int k)
{
    NODE* check = L.pHead;
    while (check != NULL && check->info != k)
    {
        check = check->pNext;
    }
    if (check == NULL)
    {
        cout << "-1";
        return;
    }
    while (L.pHead != NULL && L.pHead->info == k)
    {
        NODE* temp = L.pHead;
        L.pHead = L.pHead->pNext;
        delete temp;
    }
    if (L.pHead == NULL)
    {
        L.pTail = NULL;
    }
    else
    {
        NODE* pre = L.pHead;
        while (pre != NULL && pre->pNext != NULL)
        {
            if (pre->pNext->info == k)
            {
                NODE* temp = pre->pNext;
                pre->pNext = temp->pNext;
                if (temp == L.pTail)
                {
                    L.pTail = pre;
                }
                delete temp;
            }
            else
            {
                pre = pre->pNext;
            }
        }
    }
    PrintList(L);
}