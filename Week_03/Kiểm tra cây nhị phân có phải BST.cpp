bool checkBST(Node* root, long long minVal, long long maxVal)
{
    if (root == NULL) return 1;
    if (root->data <= minVal || root->data >= maxVal) return 0;
    else
    {
        checkBST(root->left, minVal, root->data);
        checkBST(root->right, root->data, maxVal);
    }
    return (checkBST(root->left, minVal, root->data) && (checkBST(root->right, root->data, maxVal)));
}
bool isValidBST(Node* root)
{
    return checkBST(root, -99999999, +99999999);

}