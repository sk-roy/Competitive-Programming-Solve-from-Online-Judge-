#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);


    int n,t,tc;
    vector <int> v,vd;
    string s;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>s;
        n=0;
        vd.clear();
        for(int i=0; i<=s.size(); i++)
        {
            if(i==s.size() || s[i]=='.') vd.push_back(n), n=0;
            else n = n*10 + s[i]-'0';
        }

        cin>>s;
        n=0;
        v.clear();
        for(int i=0; i<=s.size(); i++)
        {
            if(i==s.size() || s[i]=='.') v.push_back(n), n=0;
            else n = n*2 + s[i]-'0';
        }


        if(v==vd) cout<<"Case "<<tc<<": Yes\n";
        else cout<<"Case "<<tc<<": No\n";

    }

    return 0;
}
