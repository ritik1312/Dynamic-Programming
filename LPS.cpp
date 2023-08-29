#include <bits/stdc++.h>
using namespace std;

int t[101][101];

int LPS(string s) {
    int n=s.length();
    
    
    for(int l=n-1;l>=0;l--)
    {
        for(int r=0;r<n;r++)
        {
            if(l>r)
                t[l][r]=0;
            else if(l==r)
                t[l][r]=1;
            else if(s[l]==s[r])
                t[l][r] = 2+t[l+1][r-1];
            else
                t[l][r] = max(t[l+1][r],t[l][r-1]);
        }
    }
    return t[0][n-1];
}

int LCS(string text1, string text2) {
    int n1 = text1.length();
    int n2 = text2.length();

    for(int i=0;i<n1+1;i++)
        t[i][0]=0;
    for(int j=0;j<n2+1;j++)
        t[0][j] = 0;
    
    for(int i=1;i<n1+1;i++)
    {
        for(int j=1;j<n2+1;j++)
        {
            if(text1[i-1]==text2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
        }
    }
    return t[n1][n2];
}

int main()
{
    string str;
    cin >> str;
    int n= str.length();

    // 1.a) 1st method (direct)
    int lps = LPS(str);
    cout <<  lps << endl;

    // 1.b)  2nd method -> LPS(str) = LCS(str,reverse(str))
    string s = str;
    reverse(s.begin(),s.end());
    cout << LCS(str,s) << endl;

    // 2) Min no of deletions to convert a string into its LPS

    int no_of_del = n-lps;
    cout << no_of_del << endl;

    // 3) print LPS
    int i,j;
    i=n;
    j=n;
    string lps_str = "";
    while(i>0 && j>0)
    {
        if(str[i-1] == s[j-1])
        {
            lps_str+=str[i-1];
            i--;j--;
        }
        else
        {
            if(t[i-1][j] >= t[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(lps_str.begin(), lps_str.end());
    cout << lps_str;

}