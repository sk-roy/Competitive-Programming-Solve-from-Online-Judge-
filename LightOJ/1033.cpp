#include<bits/stdc++.h>
using namespace std;

int dp[105][105];
string s;

void ini()
{
    for(int i=0; i<105; i++)
        for(int j=0; j<105; j++)
            dp[i][j] = -1;
}

int roy(int l, int r)
{
    if(l>=r) return 0;
    if(dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 500;
    if(s[l]==s[r]) dp[l][r] = min(dp[l][r], roy(l+1, r-1));
    dp[l][r] = min(dp[l][r], roy(l+1, r)+1);
    dp[l][r] = min(dp[l][r], roy(l, r-1)+1);

    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,tc,k;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>s;

        ini();
        k = roy(0, s.size()-1);
        //k = s.size() - k;
        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
