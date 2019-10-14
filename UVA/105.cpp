#include<bits/stdc++.h>
using namespace std;



int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int i,j,k,n,m,l,r,h,e,s;
    int a[20000];
    for(i=0; i<20000; i++)
        a[i]=0;
    s=20000;
    e=0;
    while(cin>>l>>h>>r)
    {
        for(i=l; i<r; i++)
            a[i]= max(a[i],h);
        s=min(s,l);
        e=max(e,r);
    }
    cout<<s<<" "<<a[s]<<" ";
    for(i=s+1; i<e; i++)
    {
        if(a[i]!=a[i-1])
            cout<<i<<" "<<a[i]<<" ";
    }
    cout<<e<<" "<<0<<endl;

    return 0;
}
