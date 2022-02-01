/*

Definition :    Merge sort

Time Complexity: O(nLogn)

Auxiliary Space: O(n)


*/


#include<bits/stdc++.h>
using namespace std;

void merge(int ar[], int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int LeftArray[n1], RightArray[n2];

    for (int i = 0; i < n1; i++)
        LeftArray[i] = ar[start + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = ar[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            ar[k] = LeftArray[i];
            i++;
        }
        else
        {
            ar[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        ar[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ar[k] = RightArray[j];
        j++;
        k++;
    }
}

void Merge_sort(int ar[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        Merge_sort(ar, start, mid);
        Merge_sort(ar, mid + 1, end);
        merge(ar, start, mid, end);
    }
}
void print(int ar[], int n)
{
    cout << "After Sorting :\n";
    for (int i = 0; i < n; i++) cout << ar[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    Merge_sort(ar, 0, n - 1);
    print(ar, n);
}