#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll t,tc,n,m,i,k,j,x,y;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n;

        k=sqrt(n);
        m=k*k;

        if(n==m) x=k, y=1;
        else if(m+k+1>=n) x=k+1, y= n-m;
        else x=(k+1)*(k+1)+1-n, y= k+1;

        if(k%2 != 0) swap(x,y);

        cout<<"Case "<<tc<<": "<<x<<" "<<y<<endl;

    }


    return 0;
}
