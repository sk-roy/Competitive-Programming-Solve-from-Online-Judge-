#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+5;
bool flag[N+5];
int pm[N+5];
int tp;


void seive()
{
    for(int i=2; i*i<N; i++)
        if(!flag[i])
            for(int j=i*i; j<N; j+=i)
                flag[j]=1;
    tp=0;
    for(int i=2; i<N; i++)
        if(!flag[i]) pm[tp++]=i;
}


ll divisor(ll n)
{
    ll k;
    ll d=1;
    for(int i=0; (ll)pm[i]*pm[i]<=n; i++)
    {
        k=0;
        while(n%(ll)pm[i]==0)
        {
            k++;
            n/=pm[i];
        }
        d*=k+1;
    }
    if(n!=1) d*=2;
    return d;
}


int main()
{
    seive();
    ll t,tc,n;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n;
        cout<<"Case "<<tc<<": "<<divisor(n)-1<<endl;
    }
    return 0;
}
