#include<bits/stdc++.h>
using namespace std;

string s;
int ck[1005];
int dp[1005][1005];
int sr[1005];
int Right[1005][1005];

int roy(int l, int r)
{
    if(l>=r) return dp[l][r]= 1;
    if(dp[l][r] != -1) return dp[l][r];

    int k = 0;
    if(s[l]==s[r]) k |= roy(l+1, r-1);
    if(k) Right[l][sr[l]++] = r;

    roy(l+1, r);
    roy(l, r-1);
    return dp[l][r] = k;
}

void ini()
{
    for(int i=0; i<1005; i++)
    {
        sr[i] = 0;
        ck[i] = -1;
        for(int j=0; j<1005; j++)
            dp[i][j] = -1;
    }
}

int knapsack(int l, int r)
{
    if(dp[l][r]) return 1;
    if(ck[l] != -1) return ck[l];

    ck[l] = knapsack(l+1, r)+1;
    for(int k,i=0; i<sr[l]; i++)
    {
        k = Right[l][i];
        ck[l] = min(ck[l], knapsack(k+1, r)+1);
    }

    return ck[l];
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,tc;
    cin>>t;

    for(tc=1; tc<=t; tc++)
    {
        cin>>s;

        ini();
        roy(0, s.size()-1);

        int k = knapsack(0, s.size()-1);
        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
