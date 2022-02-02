/*

Definition :    Quick sort

Average Time Complexity: O(nLogn)

Auxiliary Space: O( nlogn )

*/


#include<bits/stdc++.h>
using namespace std;

int partition(int ar[], int start, int end)
{
    int pivot = ar[end];
    int i = (start - 1);
    for (int j = start; j <= end - 1; j++)
    {
        // If current element is smaller than the pivot
        if (ar[j] < pivot)
        {
            i++;
            swap(ar[i], ar[j]);
        }
    }
    swap(ar[i + 1], ar[end]);
    return (i + 1);
}

void Quick_sort(int ar[], int start, int end) {
    if (start < end)
    {
        int partitionIndex = partition(ar, start, end);
        Quick_sort(ar, start, partitionIndex - 1);
        Quick_sort(ar, partitionIndex + 1, end);
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
    Quick_sort(ar, 0, n - 1);
    print(ar, n);
}