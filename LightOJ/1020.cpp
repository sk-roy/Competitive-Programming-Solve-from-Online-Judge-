#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t,tc,n;
    string s;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>s;
        if(s=="Alice")
        {
            if(n%3==1) cout<<"Case "<<tc<<": "<<"Bob\n";
            else cout<<"Case "<<tc<<": "<<"Alice\n";
        }
        else
        {
            if(n%3==0) cout<<"Case "<<tc<<": "<<"Alice\n";
            else cout<<"Case "<<tc<<": "<<"Bob\n";
        }
    }

    return 0;
}
