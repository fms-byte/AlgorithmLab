// Program of String Matching using Naive Approach
#include <bits/stdc++.h>
using namespace std;

void search(string pat, string txt)
{
    int i, j, M, N, cnt = 0, c = 0;
    M = pat.length();
    N = txt.length();
    cout << "Index Matching at : " << endl;
    for (i = 0; i <= N - M; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] == pat[j])
                cnt++;
        }
        if (cnt == M)
        {
            for (int j = 0; j < M; j++)
            {
                cout << i + j << " ";
                break;
            }
            cout << endl;
            c++;
        }
        cnt = 0;
    }
    cout << "Number of Total Matching : " << c << endl;
}

int main()
{
    string text, pattern;

    cout << "Text: ";
    cin >> text;

    cout << "Pattern: ";
    cin >> pattern;

    search(pattern, text);
    return 0;
}
