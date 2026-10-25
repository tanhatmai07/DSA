#include<iostream>
#include<vector>
using namespace std;
int binarySearch(const vector<int>& a, const int& x)
{
    int l = 0;
    int r = a.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (a[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
void Input(vector<int>& a)
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
    int x;
    cin >> x;
    int n;
    cin >> n;
    vector<int>a(n);
    Input(a);
    cout << binarySearch(a, x);
    return 0;
}