void Insert(TREE& T, int x)
{
    if (T == NULL)
    {
        T = new TNODE;
        T->key = x;
        T->pLeft = NULL;
        T->pRight = NULL;
        return;
    }
    if (x < T->key)
    {
        Insert(T->pLeft, x);
    }
    else if (x > T->key)
    {
        Insert(T->pRight, x);
    }
}
void CreateTree(TREE& T)
{
    int x;
    while (cin >> x)
    {
        if (x == -1) break;
        Insert(T, x);
    }
}
int CountLeaf(TREE T)
{
    if (T == NULL) return 0;
    else if (T->pLeft == NULL && T->pRight == NULL) return 1;
    else
    {
        return CountLeaf(T->pLeft) + CountLeaf(T->pRight);
    }
}