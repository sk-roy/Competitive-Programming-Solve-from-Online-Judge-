#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll expo(ll b, ll p)
{
    if(p==0) return 1;
    if(p%2==0) return expo(b*b, p/2);
    else return b*expo(b*b, p/2);
}


int main()
{
   // freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    ll t,tc,n,p,x,k;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n;
        ll ans=1;
        bool done=false;
        for(p=32; (p>1 && !done); p--)
        {
            for(ll i=2; !done ; i++)
            {
                k= expo(i,p);
                //cout<<i<<" "<<p<<" "<<k<<endl;
                if(k==n || (k==abs(n) && p%2==1))
                {
                    done=true;
                    ans=p;
                }
                if(k>abs(n)) break;
            }
        }

        cout<<"Case "<<tc<<": "<<ans<<endl;
    }

    return 0;
}
