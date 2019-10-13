#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
ll n,c,mx,mt;


ll profit(ll t)
{
    ll k= ll(t*(c-(n*t)));
    if(k>=mx)
    {
        if(k>mx) mt=t;
        else if(k==mx) mt=min(mt,t);
        mx=k;
    }
    return k;
}

void binary(ll l, ll r)
{
    //cout<<l<<" "<<r<<endl;
    if(l==r) return ;
    ll m=(l+r)/2;

    ll k,kl,kr;
    k=profit(m);
    if(m!=l) kl=profit(m-1);
    kr=profit(m+1);

   // cout<<kl<<" "<<k<<" "<<kr<<endl;
   // cout<<m-1<<" "<<m<<" "<<m+1<<endl;

    if(kr>=k) binary(m+1,r);
    if(m!=l && kl>=k) binary(l,m-1);

    return ;
}


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    ll t,tc;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>c;

        //if(tc==11) cout<<n<<" "<<c<<endl;
        //else continue;

        mt=0;
        mx=0;

        if(n)
        {
            profit(0);
            profit(c/n);
            binary(0, c/n);
        }

        cout<<"Case "<<tc<<": "<<mt<<endl;
    }

    return 0;
}

