#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
void Insert(Node*& root, int x)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = x;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if (x < root->data) Insert(root->left, x);
    else if (x > root->data) Insert(root->right, x);
}
int CountLeaf(Node* t)
{
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 1;
    return CountLeaf(t->left) + CountLeaf(t->right);
}
int main()
{
    int n;
    cin >> n;
    Node* root = NULL;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        Insert(root, x);
    }
    cout << CountLeaf(root);
}