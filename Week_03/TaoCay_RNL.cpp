void InsertTree(TREE& T, int x)
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
        InsertTree(T->pLeft, x);
    else if (x > T->key)
        InsertTree(T->pRight, x);
}
void CreateTree(TREE& T)
{
    int x;
    while (cin >> x)
    {
        if (x == -1) break;
        InsertTree(T, x);
    }
}
void RNL(TREE T)
{
    if (T == NULL) return;
    RNL(T->pRight);
    cout << T->key << " ";
    RNL(T->pLeft);

}
void PrintTree(TREE T)
{
    if (T == NULL)
        cout << "Empty Tree.";
    else
    {
        RNL(T);
    }
}