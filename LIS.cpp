#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis, lis + n);
}
int main()
{
    int n, i, len;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter element of the array: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    len = lis(arr, n);
    cout << "Lenght of the Subsequence is: " << len << endl;
    return 0;
}

