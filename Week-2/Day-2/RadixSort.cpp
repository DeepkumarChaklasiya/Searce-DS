/*

Definition :   Radix sort

Time Complexity:    O(n*k)

Auxiliary Space: O(n+k)

                ; n=size of array and k = number of maximum digits

*/


#include<bits/stdc++.h>
using namespace std;

int Max(int ar[], int n)
{
    int maxx = ar[0];
    for (int i = 1; i < n; i++) maxx = max(maxx, ar[i]);
    return maxx;
}

void Count_sort(int ar[], int n, int place)
{
    int fre[10], output[n];
    memset(fre, 0, sizeof(fre));
    for (int i = 0; i < n; i++)
    {
        fre[(ar[i] / place) % 10]++;
    }
    for (int i = 1; i < 10; i++) fre[i] += fre[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[fre[(ar[i] / place) % 10] - 1 ] = ar[i];
        fre[(ar[i] / place) % 10]--;
    }
    for (int i = 0; i < n; i++) ar[i] = output[i];
}
void Radix_sort(int ar[], int n) {
    int max = Max(ar, n);
    for (int place = 1; max / place > 0; place *= 10)
        Count_sort(ar, n, place);
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
    Radix_sort(ar, n);
    print(ar, n);
}