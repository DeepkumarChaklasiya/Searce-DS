/*

Definition :    Heap sort

Time Complexity: O(nLogn)

Auxiliary Space: O(1)


*/


#include<bits/stdc++.h>
using namespace std;

void heapify(int ar[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is greater than root

    if (left < n && ar[left] > ar[largest])
        largest = left;

    // If right child is greater than root
    if (right < n && ar[right] > ar[largest])
        largest = right;

    // If root is not largest

    if (largest != i) {

        swap(ar[i], ar[largest]);
        heapify(ar, n, largest);
    }
}
/*Function to implement the heap sort*/
void Heap_sort(int ar[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(ar, n, i);

    // One by one extract an element
    for (int i = n - 1; i >= 0; i--) {
        swap(ar[i], ar[0]);
        heapify(ar, i, 0);
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
    Heap_sort(ar, n);
    print(ar, n);
}