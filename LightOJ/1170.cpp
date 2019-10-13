#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e8+7;
const ll N = 1e6+10;
ll c[N+5];
vector <ll> p;
map <ll,bool> done;

void roy()
{
    ll k;
    for(ll i=2; i<2e5; i++)
    {
        if(done[i]) continue;
        k=i*i;
        while(k<2e10)
        {
            p.push_back(k);
            if(k<2e5) done[k]=1;
            k*=i;
        }
    }
    sort(p.begin(), p.end());
    return ;
}

ll catalan(ll n)
{
    if(n<2) return c[n]=1;

    if(c[n]>0) return c[n];

    for(ll i=0; i<n; i++)
    {
        c[n]+=(catalan(i)*catalan(n-i-1))%mod;
        c[n]%=mod;
    }

    return c[n];
}

ll binary(ll l, ll r, ll a)
{
    if(l==r) return l;
    ll m=(l+r)/2;

    if(p[m]>=a) return binary(l, m, a);
    else return binary(m+1, r, a);
}


int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("0output.txt", "w", stdout);

    roy();

    ll t,tc,a,b;

    for(ll i=0; i<N; i++) c[i]=0;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>a>>b;

        a=binary(0,p.size()-1,a);
        b=binary(0,p.size()-1,b+1);
        ll k=b-a;

        c[k]=catalan(k);

        if(k==0) cout<<"Case "<<tc<<": "<<0<<endl;
        else cout<<"Case "<<tc<<": "<<c[k]<<endl;
    }
    return 0;
}
