#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll c[50][50];

void pascal()
{
    c[0][0]=1;
    for(ll n=1; n<32; n++)
    {
        c[n][0]=c[n][n]=1;
        for(ll k=1; k<n; k++)
            c[n][k]=c[n-1][k]+c[n-1][k-1];
    }
    return ;
}

int main()
{
    pascal();
    ll t,tc,n,k,m;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>k;

        if(k>n)
        {
             cout<<"Case "<<tc<<": 0"<<endl;
             continue;
        }

        m=1;
        for(ll i=0; i<k; i++)
            m*=n-i;

        m*=c[n][n-k];

        cout<<"Case "<<tc<<": "<<m<<endl;
    }

    return 0;
}
