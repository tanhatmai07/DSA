#include<iostream>
#include<vector>
using namespace std;
void merge2sub(vector<int>& a, vector<int>& id, int l, int mid, int r)
{
    if (l >= r) return;
    int size = r - l + 1;
    vector<int>t(size);
    vector<int>tid(size);
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            t[k] = a[i];
            tid[k] = id[i];
            i++;
            k++;
        }
        else
        {
            t[k] = a[j];
            tid[k] = id[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        t[k] = a[i];
        tid[k] = id[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        t[k] = a[j];
        tid[k] = id[j];
        j++;
        k++;
    }
    for (int k = 0; k < size; k++)
    {
        a[l + k] = t[k];
        id[l + k] = tid[k];
    }
}
void mergeSort(vector<int>& a, vector<int>& id, int l, int r)
{
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(a, id, l, mid);
    mergeSort(a, id, mid + 1, r);
    merge2sub(a, id, l, mid, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int> id(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        id[i] = i;
    }
    mergeSort(a, id, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << id[i] << " ";
    }
    return 0;
}