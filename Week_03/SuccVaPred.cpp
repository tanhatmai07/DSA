void predecessor(Node* root, int x, bool& out_found, int& out_val)
{
    out_found = false;;
    Node* cur = root;
    while (cur != NULL)
    {
        if (cur->data < x)
        {
            out_found = true;
            out_val = cur->data;
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
}
void successor(Node* root, int x, bool& out_found, int& out_val)
{
    out_found = false;
    Node* cur = root;
    while (cur != NULL)
    {
        if (cur->data > x)
        {
            out_found = true;
            out_val = cur->data;
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
}