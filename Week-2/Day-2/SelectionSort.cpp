/*

Definition :    Selection sort

Time Complexity: O(n^2)

Auxiliary Space: O(1)


*/


#include<bits/stdc++.h>
using namespace std;

void Selection_sort(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[minind])  minind = j;
        }
        swap(ar[i], ar[minind]);
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
    Selection_sort(ar, n);
    print(ar, n);
}