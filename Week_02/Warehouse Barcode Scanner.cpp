#include<iostream>
#include<vector>
using namespace std;
int Barcode_Scanner(const vector<int>& a, const int& q, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == q) return i + 1;
    }
    return -1;
}
void Input(vector<int>& a, int n)
{
    for (int i = 0; i < n; i++)
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
    vector<int>a(n);
    Input(a, n);
    int x;
    cin >> x;
    cout << Barcode_Scanner(a, x, n);
    return 0;
}