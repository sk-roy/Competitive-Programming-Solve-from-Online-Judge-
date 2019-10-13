#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 100000007


int main()
{
    ll n,t,tc,k,i,j,m,w;
    ll dp[1005];
    ll a[55],c[55];

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>w;
        for(i=0; i<n; i++) cin>>a[i];
        for(i=0; i<n; i++) cin>>c[i];

        for(i=0; i<=w; i++) dp[i]=0;
        dp[0]=1;

        for(i=0; i<n; i++)
        {
            for(k=w; k>=a[i]; k--)
            {
                for(j=1; j<=c[i]; j++)
                {
                    if(a[i]*j<=k)
                        dp[k]=(dp[k]+dp[k-a[i]*j])%mod;
                }
            }
        }
        /*
        for(i=0; i<=w; i++)
            cout<<dp[i]<<" ";
        cout<<endl;
        */
        cout<<"Case "<<tc<<": "<<dp[w]<<endl;
    }
    return 0;
}
