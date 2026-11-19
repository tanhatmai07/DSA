NODE* CreateNode(SINHVIEN x)
{
    NODE* t = new NODE;
    t->key = x;
    t->pNext = NULL;
    return t;
}
void CreateEmptyList(LIST& L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
void AddTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
        return;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void NhapDS(LIST& L, int n)
{
    CreateEmptyList(L);
    for (int i = 0; i < n; i++)
    {
        SINHVIEN sv;
        NhapSinhVien(sv);
        NODE* p = CreateNode(sv);
        AddTail(L, p);
    }
}
void XuatDS(LIST L)
{
    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    NODE* c = L.pHead;
    while (c != NULL)
    {
        XuatSinhVien(c->key);
        cout << "\n";
        c = c->pNext;
    }
}