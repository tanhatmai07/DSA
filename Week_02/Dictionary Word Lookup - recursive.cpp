#include<iostream>
#include<vector>
using namespace std;
int findWord(const vector<string>& a, const string& q, int l, int r)
{
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (q == a[mid])
    {
        return mid + 1;
    }
    else if (q < a[mid])
    {
        return findWord(a, q, l, mid - 1);
    }
    else
    {
        return findWord(a, q, mid + 1, r);
    }

}
void Input(vector<string>& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string>a(n);
    Input(a);
    string x;
    cin >> x;
    cout << findWord(a, x, 0, n - 1);
}