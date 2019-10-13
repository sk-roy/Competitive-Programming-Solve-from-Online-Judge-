#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e6+1;
bool flag[N+5];
ll pm[N+5];
ll tp;
const ll mod = 1e9+7;


void seive()
{
    for(ll i=2; i*i<N; i++)
        if(!flag[i])
            for(ll j=i*i; j<N; j+=i)
                flag[j]=1;
    tp=0;
    for(ll i=2; i<N; i++)
        if(!flag[i]) pm[tp++]=i;
}


ll expo(ll b, ll p)
{
    if(p==0) return (ll)1;
    if(p%2==0) return expo((b*b)%mod, p/2);
    else return (b*expo((b*b)%mod, p/2))%mod;
}


int main()
{
    //freopen("0input.txt", "r", stdin);
   // freopen("0output.txt", "w", stdout);


    seive();
    ll n,m,i,j,sum;
    ll k,t,tc;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>m;

        sum=1;
        for(i=0; pm[i]*pm[i]<=n; i++)
        {
            k=0;
            while(n%pm[i]==0)
            {
                k++;
                n/=pm[i];
            }
            sum *= ((expo(pm[i],(m*k)+1)-1+mod)*expo(pm[i]-1,mod-2))%mod;
            sum %= mod;
            //cout<<pm[i]<<" "<<k<<" "<<sum<<endl;
        }
        if(n!=1)
        {
            sum *= ((expo(n%mod, m+1)-1+mod)*expo((mod+n-1)%mod, mod-2))%mod;
            sum %= mod;
            //cout<<n<<" "<<1<<" "<<sum<<endl;
        }

        cout<<"Case "<<tc<<": "<<sum<<endl;
    }


    return 0;
}
