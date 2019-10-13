#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t,tc;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        int n;
        cin>>n;
        int k,m=0;
        for(int i=0; i<n; i++)
        {
            cin>>k;
            m += max(0,k);
        }
        cout<<"Case "<<tc<<": "<<m<<endl;
    }

    return 0;
}
