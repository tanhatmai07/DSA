#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Xuat(vector<int>& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

void QuickSort(vector<int>& a, int l, int r)
{
    if (l >= r) return;
    cout << "Truoc: ";
    Xuat(a);
    cout << "\n";
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    cout << "Left=" << l << " - Right=" << r << " - Pivot=" << pivot << "\n";
    while (i < j)
    {
        while (a[i] > pivot) i++;
        while (a[j] < pivot) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    cout << "Sau: ";
    Xuat(a);
    cout << "\n\n";
    QuickSort(a, l, j);
    QuickSort(a, i, r);
}
void Nhap(vector<int>& a, int n)
{
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    Nhap(a, n);
    cout << "Mang truoc khi sap xep:\n";
    Xuat(a);
    cout << "\n\n";
    cout << "Sap xep:\n";
    QuickSort(a, 0, n - 1);
    cout << "Mang sau khi sap xep:\n";
    Xuat(a);
    return 0;
}