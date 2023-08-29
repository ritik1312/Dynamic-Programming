#include <bits/stdc++.h>
#include "subset_sum.h"

using namespace std;
int main()
{
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];

    int tot_sum = 0;
    for(int i=0;i<n;i++)
        tot_sum+=v[i];
    
    if(tot_sum%2==1)
        cout << false;
    else
        cout << is_subset_sum(tot_sum/2);
    return 0;
}