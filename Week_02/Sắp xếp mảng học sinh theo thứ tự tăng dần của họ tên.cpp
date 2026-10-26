void QuickSort(Hocsinh ls[], int b, int e) {
    if (b >= e) return;
    int i = b;
    int j = e;
    Hocsinh pivot = ls[(b + e) / 2];
    while (i < j)
    {
        while (ls[i].Hoten < pivot.Hoten)
        {
            i++;
        }
        while (ls[j].Hoten > pivot.Hoten)
        {
            j--;
        }
        if (i <= j)
        {
            Hocsinh t = ls[i];
            ls[i] = ls[j];
            ls[j] = t;
            i++;
            j--;
        }
    }
    QuickSort(ls, b, j);
    QuickSort(ls, i, e);
}