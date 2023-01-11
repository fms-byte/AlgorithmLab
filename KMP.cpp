//Implementation of KMP pattern searching algorithm
#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int *lps)
{

    int len = 0;

    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


void KMPSearch(string pat, string txt)
{
    int i, j, M, N;
    M = pat.length();
    N = txt.length();

    int lps[M];

    computeLPSArray(pat, M, lps);

    i = 0;
    j = 0;
    int c=0;
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            cout << "Pattern found at index : " << i - j+1 << endl;
            j = lps[j - 1];
            c++;
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    cout<<"\nPattern found "<<c<<" times in Text."<<endl;
}

int main()
{
    string text, pattern;

    cout << "Text: ";
    cin >> text;

    cout << "Pattern: ";
    cin >> pattern;

    KMPSearch(pattern, text);
    return 0;
}
