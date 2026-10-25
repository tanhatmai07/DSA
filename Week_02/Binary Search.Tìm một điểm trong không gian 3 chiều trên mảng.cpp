#include<iostream>
#include<vector>
using namespace std;
struct point
{
    float x;
    float y;
    float z;
};
int compare(point a, point b)
{
    if (a.x == b.x && a.y == b.y && a.z == b.z) return 0;
    else if (a.x < b.x) return -1;
    else if (a.x == b.x)
    {
        if (a.y < b.y) return -1;
        else if (a.y == b.y)
        {
            if (a.z < b.z) return -1;
        }
    }
    return 1;
}
int binary_search(const vector<point>& a, const point& x)
{
    int l = 0;
    int r = a.size() - 1;
    int count = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        count++;
        if (compare(x, a[mid]) == 0) return count;
        if (compare(x, a[mid]) == -1)
        {
            r = mid - 1;
        }
        else if (compare(x, a[mid]) == 1)
        {
            l = mid + 1;
        }
    }
    return 0;
}
void  Input(vector<point>& a, vector<point>& q)
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    int m;
    cin >> m;
    q.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].x >> q[i].y >> q[i].z;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<point>a;
    vector<point>q;
    Input(a, q);
    for (int i = 0; i < q.size(); i++)
    {
        int kq = binary_search(a, q[i]);
        if (kq == 0)
            cout << "KHONG" << "\n";
        else cout << kq << "\n";
    }
    return 0;
}