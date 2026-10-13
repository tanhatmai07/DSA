void merge_2_Sorted_subArray(SanPham* a, int l, int mid, int r)
{
    if (l >= r) return;
    int size = r - l + 1;
    SanPham* temp = new SanPham[size];
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i].gia < a[j].gia)
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else if (a[i].gia > a[j].gia)
        {
            temp[k] = a[j];
            j++;
            k++;
        }
        else
        {
            if (a[i].ma <= a[j].ma)
            {
                temp[k] = a[i];
                i++;
                k++;
            }
            else
            {
                temp[k] = a[j];
                j++;
                k++;
            }
        }

    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (int idx = 0; idx < size; idx++)
    {
        a[l + idx] = temp[idx];
    }
    delete[]temp;

}
void mergeSort(SanPham* a, int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge_2_Sorted_subArray(a, l, mid, r);
}