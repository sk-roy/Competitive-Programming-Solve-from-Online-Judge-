#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n)
{
    ll i,k,p,m,sum=0;
    p=n/2;
    sum+=(p-1)*2;
    //cout<<"Ans: "<<sum<<endl;
    for(i=3; i*i<=n; i++)
    {
        k=n/i;
        sum+=(k-1)*i;

        m=((p+1)*p/2)-((k+1)*k/2);
        sum+=m*(i-2);
        p=k;
        //cout<<"Ans: "<<sum<<endl;
    }
    i--;
    k=n/i;
    m=((k+1)*k/2)-((i+1)*i/2);
    sum+=m*(i-1);

    //cout<<"I: "<<i<<endl;
    //if(i*i!=n) sum+=(i+1)*(i-1);
    return max((ll)0,sum);
}


int main()
{
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        ll n;
        cin>>n;
        cout<<"Case "<<tc<<": "<<solve(n)<<endl;
    }
    return 0;
}


