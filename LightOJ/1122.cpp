#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d[12];
ll dp[12][12];
ll m;

ll roy(ll n, ll prev)
{
    if(n==0) return 1;
    if(dp[n][prev] != -1) return dp[n][prev];

    dp[n][prev] = 0;
    for(ll i=max((ll)1, prev-2); i<=min((ll)9, prev+2); i++)
        if(d[i]) dp[n][prev] += roy(n-1, i);

    return dp[n][prev];
}


void ini()
{
    for(int i=0; i<12; i++) d[i] = 0;
    for(int i=0; i<12; i++)
        for(int j=0; j<12; j++)
            dp[i][j] = -1;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,tc,n,k,a;
    cin>>t;

    for(tc=1; tc<=t; tc++)
    {
        ini();

        cin>>m>>n;
        for(ll i=0; i<m; i++)
        {
            cin>>a;
            d[a]=1;
        }

        k = 0;
        for(ll i=1; i<=9; i++)
            if(d[i]) k+= roy(n-1, i);

        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
