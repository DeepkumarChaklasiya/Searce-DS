/*

Definition :    Counting sort

Time Complexity: O(n+k)

Auxiliary Space: O(n+k)

                ; n=size of array and k = range of array (difference between max and min element)

*/


#include<bits/stdc++.h>
using namespace std;

void Count_sort(int ar[], int n)
{
    int minn = ar[0], maxx = ar[0];
    for (int i = 1; i < n; i++)
    {
        minn = min(minn, ar[i]);
        maxx = max(maxx, ar[i]);
    }
    int difference = maxx - minn + 1;
    int fre[difference], output[n];
    memset(fre, 0, sizeof(fre));
    for (int i = 0; i < n; i++)
    {
        fre[ar[i] - minn]++;
    }
    for (int i = 1; i < difference; i++) fre[i] += fre[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[fre[ar[i] - minn] - 1] = ar[i];
        fre[ar[i] - minn]--;
    }
    for (int i = 0; i < n; i++) ar[i] = output[i];
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
    Count_sort(ar, n);
    print(ar, n);
}