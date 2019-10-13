#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll expo(ll b, ll p, ll m)
{
    if(p==0) return 1;
    if(p%2==0) return expo((b*b)%m, p/2, m)%m;
    else return (b*expo((b*b)%m, p/2, m)%m)%m;
}


int main()
{
    ll t,tc,n,k,mod,m,i,j;
    ll a;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>k>>mod;

        m=(expo(n,k-1,mod)*k)%mod;

        ll sum=0;
        for(i=0; i<n; i++)
        {
            cin>>a;
            sum=(sum+m*a)%mod;
        }
        cout<<"Case "<<tc<<": "<<sum<<endl;
    }
    return 0;
}

