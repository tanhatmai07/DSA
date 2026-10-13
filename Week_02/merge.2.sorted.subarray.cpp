void merge_2_Sorted_subArray(int a[], int l, int mid, int r)
{
    if (l >= r) return;
    std::vector<int>temp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }

        else
        {
            temp.push_back(a[j]);
            j++;
        }

    }
    while (i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back(a[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++)
    {
        a[l + k] = temp[k];
    }
}