#include<iostream>
#include<vector>
using namespace std;
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void QuickSort(vector<int>& a, int n)
{
    int pivot = a[n - 1];
    int p = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[p]);
            p++;
        }
    }
    swap(a[n - 1], a[p]);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << p;
}
void Input(vector<int>& a, int& n)
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
    QuickSort(a, n);
}