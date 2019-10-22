#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll dp[200][200];
ll ok[200][200];
vector <ll> v;
vector <char> c;

ll Min_MatrixChain(ll i, ll j)
{
    if(i==j) return dp[i][j] = v[i];
    if(ok[i][j] == 2) return dp[i][j];

    for(ll k=i; k<j; k++)
    {
        ll m1 = Min_MatrixChain(i, k);
        ll m2 = Min_MatrixChain(k+1, j);
        ll m;
        if(c[k]=='*') m = m1*m2;
        else m = m1+m2;

        if(k==i) dp[i][j] = m;
        else dp[i][j] = min(dp[i][j], m);
    }
    ok[i][j] = 2;
    return dp[i][j];
}

ll Max_MatrixChain(ll i, ll j)
{
    if(i==j) return dp[i][j] = v[i];
    if(ok[i][j] == 2) return dp[i][j];

    for(ll k=i; k<j; k++)
    {
        ll m1 = Max_MatrixChain(i, k);
        ll m2 = Max_MatrixChain(k+1, j);
        ll m;
        if(c[k]=='*') m = m1*m2;
        else m = m1+m2;

        if(k==i) dp[i][j] = m;
        else dp[i][j] = max(dp[i][j], m);
    }
    ok[i][j] = 2;
    return dp[i][j];
}

void ini(ll n)
{
    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
            ok[i][j] = 1;
}

int main()
{
    int t;
    string s;
    cin>>t;

    while(t--)
    {
        cin>>s;
        v = {5};
        c = {'c'};
        for(ll i=0; i<s.size(); i++)
        {
            if(i&1) c.push_back(s[i]);
            else v.push_back(s[i]-'0');
        }

        ini(v.size());
        ll mx = Max_MatrixChain(1, v.size()-1);
        ini(v.size());
        ll mn = Min_MatrixChain(1, v.size()-1);

        cout<<mx<<" "<<mn<<endl;
    }

    return 0;
}
