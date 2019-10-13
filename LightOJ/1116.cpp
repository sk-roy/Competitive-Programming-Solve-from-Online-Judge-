#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);


    ll t,tc,n,m,k;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n;
        m=n;
        while(n%2==0) n/=2;
        m/=n;

        cout<<"Case "<<tc<<": ";
        if(m==1) cout<<"Impossible"<<endl;
        else cout<<n<<" "<<m<<endl;
    }

    return 0;
}
