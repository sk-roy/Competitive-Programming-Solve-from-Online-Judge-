#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int t,tc,n,m;
    cin>>t;

    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>m;
        cout<<"Case "<<tc<<": "<<(n/2)*m<<endl;
    }
    return 0;
}

