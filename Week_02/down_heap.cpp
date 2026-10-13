#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Heapify(vector<int>& a, int n, int i)
{
	int largest = i;
	int cl = 2 * i + 1;
	int cr = 2 * i + 2;
	if (cl<n && a[cl]>a[largest]) largest = cl;
	if (cr<n && a[cr]>a[largest]) largest = cr;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		Heapify(a, n, i);
	}
}
void BuildHeap(vector<int>& a, int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		Heapify(a, n, i);
	}
}
void removeMax(vector<int>& a, int &n)
{
	if (n <= 0) return;
	swap(a[0], a[n - 1]);
	a.pop_back();
	n--;
	if (n > 0) Heapify(a, n, 0);
}
void removeAllMax(vector<int>& a, int& n)
{
	if (n <= 0) return;
	int maxval = a[0];
	while (n > 0 && a[0] == maxval)
	{
		removeMax(a, n);
	}
}
void decreaseMax(vector<int>& a, int n,int k)
{
	a[0] -= k;
	if (n > 0)Heapify(a, n, 0);
}
void decreaseAllMax(vector<int>& a, int &n, int k)
{
	int maxval = a[0];
	while (n > 0 && a[0] == maxval)
	{
		decreaseMax(a, n, k);
	}
}
void XuLi(vector<int>& a, int &n, int m)
{
	BuildHeap(a, n);
	for (int i = 0; i < m; i++)
	{
		int type, k;
		cin >> type >> k;
		if (type == -1) removeMax(a,n);
		else if (type == -2) removeAllMax(a,n);
		else if (type == -3) decreaseMax(a,n,k);
		else decreaseAllMax(a,n,k);
	}
}
void Input(vector<int>& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void Output(vector<int>&a, int n)
{
	while (n > 0)
	{
		cout << a[0]<<"\n";
		swap(a[0], a[n - 1]);
		a.pop_back();
		n--;
		if (n > 0) Heapify(a, n, 0);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<int>a(n);
	Input(a, n);
	XuLi(a, n, m);
	Output(a, n);
	return 0;
}
