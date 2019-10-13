#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
const ll N = 1e6+5;

ll two[N+5];
ll five[N+5];

void factorize()
{
    ll n;
    two[0]=0;
    five[0]=0;
    for(ll i=1; i<N; i++)
    {
        two[i]=two[i-1];
        five[i]=five[i-1];
        n=i;
        while(n%2==0) two[i]++, n/=2;
        n=i;
        while(n%5==0) five[i]++, n/=5;
    }
    return ;
}

ll Two(ll n)
{
    ll k =0;
    while(n%2==0) k++, n/=2;
    return k;
}
ll Five(ll n)
{
    ll k=0;
    while(n%5==0) k++, n/=5;
    return k;
}

int main()
{
    factorize();

    ll t,tc,tw,fv,ans;
    ll n,r,p,q;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>r>>p>>q;
        tw=two[n] - two[r] - two[n-r] + (Two(p)*q);
        fv=five[n] - five[r] - five[n-r] + (Five(p)*q);
        ans= min(tw,fv);
        ans= max(0ll,ans);
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }

    return 0;
}
