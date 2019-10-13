#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;


int main()
{
    vector <ll> v;
    ll t,tc;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        ll n,i,m;
        cin>>n;
        m=(n*10)/9;
        v.clear();
        for(i=m+1; ; i++)
        {
            if(n==i-(i/10)) v.push_back(i);
            else break;
        }
        for(i=m; ; i--)
        {
            if(n==i-(i/10)) v.push_back(i);
            else break;
        }
        sort(v.begin(),v.end());

        cout<<"Case "<<tc<<": ";
        for(i=0; i<v.size(); i++)
        {
            if(i) cout<<" ";
            cout<<v[i];
        }
        cout<<endl;
    }
}
