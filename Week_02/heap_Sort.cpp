#include<iostream>
#include<vector>
using namespace std;
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void Heapify(vector<int>&a,int n,int i)
{
    int largest=i;
    int cl=2*i+1;
    int cr=2*i+2;
    if(cl<n && a[cl]>a[largest]) largest=cl;
    if(cr<n && a[cr]>a[largest]) largest=cr;
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        Heapify(a,n,largest);
    }
}
void BuildHeap(vector<int>&a, int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        Heapify(a,n,i);
    }
}
void Output(vector<int>&a,int n)
{
    for(int i=0;i<a.size();i++)
    {
        if(i==n && n!= a.size())
        {
            cout<<"| ";
        }
        cout<<a[i]<<" ";
       
    }
     cout<<"\n";
}
void HeapSort(vector<int>&a, int n)
{
    cout<<"Mang truoc khi sap xep:\n";
    Output(a,n);
    cout<<"\n\n";
    cout<<"Sap xep:\n";
    BuildHeap(a,n);
    cout<<"Mang sau khi BuildHeap: ";
    Output(a,n);
    for(int i=n-1;i>=1;i--)
    {
        cout<<"Swap "<<a[0]<<" va "<<a[i]<<"\n\n";
        swap(a[i],a[0]);
        Heapify(a,i,0);
        cout<<"Mang sau khi heapify voi n = "<<i<<": ";
        Output(a,i);
    }
    cout<<"Mang sau khi sap xep:\n";
    Output(a,n);
}
void Nhap(vector<int> &a, int n)
{
    
    for(vector<int>::iterator i=a.begin();i<a.end();i++)
    {
        cin>>*i;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    Nhap(a,n);
    HeapSort(a,n);
    return 0;
}