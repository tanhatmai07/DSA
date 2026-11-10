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
        Insert(T->pLeft, x);
    else if (x > T->key)
        Insert(T->pRight, x);
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
bool IsCompleteBST(TREE T)
{
    queue<TNODE*>q;
    q.push(T);
    bool foundnull = false;
    TNODE* cur = T;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == NULL)
        {
            foundnull = true;
        }
        else
        {
            if (foundnull == true) return false;
            else
            {
                q.push(cur->pLeft);
                q.push(cur->pRight);
            }
        }
    }
    return true;
}