#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000003;
const ll N = 1e6+5;
ll fc[N+5];

void factorial()
{
    fc[0]=1;
    for(ll i=1; i<N; i++)
        fc[i]=(fc[i-1]*i)%mod;
}


ll expo(ll b, ll p)
{
    if(p==0) return 1;
    if(p%2==0) return expo((b*b)%mod, p/2);
    else return (b*expo((b*b)%mod, p/2))%mod;
}

int main()
{
    ll t,tc,n,k,ans;
    factorial();
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>k;
        ans= (fc[n]*expo(fc[k],mod-2))%mod;
        ans= (ans*expo(fc[n-k],mod-2))%mod;
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
    return 0;
}
