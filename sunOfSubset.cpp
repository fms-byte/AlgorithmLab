#include <bits/stdc++.h>
using namespace std;
void isSubsetSum(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i]]);
            }
        }
    }

    vector<int> v;
    int i = n, j = sum;
    if (dp[i][j])
    {
        while (i > 0 && j > 0)
        {
            if (dp[i - 1][j] == 1)
            {
                i--;
            }
            else
            {
                v.push_back(arr[i]);
                j = j - arr[i];
                i--;
            }
        }

        reverse(v.begin(), v.end());

        for (int &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No subset with given sum";
    }
}
int main()
{
    int n, i, sum;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter element of the array: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Sum : ";
    cin >> sum;

    isSubsetSum(arr, n, sum);

    return 0;
}

