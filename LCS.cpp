// Program to find Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;

void lcsAlgo(string S1, string S2, int m, int n)
{
    int LCS_table[m + 1][n + 1];


    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }

    int index = LCS_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }
    int LEN= strlen(lcsAlgo);
    cout << "Longest Common Subsequence: " << lcsAlgo << endl;
    cout<<"Length of the Common Subsequence: "<<LEN<<endl;
}

int main()
{
    int len1, len2;
    string text1, text2;

    cout << "Enter 1st String: ";
    cin >> text1;

    cout << "Enter 2nd String: ";
    cin >> text2;

    len1 = text1.length();
    len2 = text2.length();

    lcsAlgo(text1, text2, len1, len2);
    return 0;
}
