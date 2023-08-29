#include <bits/stdc++.h>
using namespace std;

// Recursive approach
int t[101][101];
    
    // int lcs(string s1,string s2,int n1, int n2)
    // {
    //     if(n1==0 || n2==0)
    //         return 0;
    //     if(t[n1][n2]!=-1)
    //         return t[n1][n2];
    //     if(s1[n1-1] == s2[n2-1])
    //         return t[n1][n2] = 1+lcs(s1,s2,n1-1,n2-1);
    //     else
    //         return t[n1][n2] = max(lcs(s1,s2,n1-1,n2) , lcs(s1,s2,n1,n2-1));
    // } 


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
    string s1,s2;
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();

// LCS
    int lcs = LCS(s1,s2);
    cout << lcs << endl;

//shortest common supersequence
    int scs = n1+n2-lcs;
    cout << scs << endl;

// Min no of insertions and deletitions to convert string 1 into string 2

    int no_of_del = n1-lcs;     // conert s1 to LCS
    int no_of_ins = n2-lcs;     // convert LCS to s2
    cout << no_of_ins << " " << no_of_del << endl;

// print LCS
    int i,j;
    i=n1;
    j=n2;
    string lcs_str = "";
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            lcs_str+=s1[i-1];
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
    reverse(lcs_str.begin(), lcs_str.end());
    cout << lcs_str;
    return 0;
}