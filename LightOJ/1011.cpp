#include<bits/stdc++.h>
using namespace std;

const int N = 16;
int n;
int a[N][N];
int dp[1<<N][N];

int setOne(int mask, int p) { return mask | (1<<p); }
bool checkBit(int mask, int p) { return mask & (1<<p); }

int bitMask(int mask, int p)
{
    if(p==n) return 0;
    if(dp[mask][p] != -1) return dp[mask][p];

    dp[mask][p] = 0;
    for(int i=0; i<n; i++)
    {
        if(checkBit(mask, i)==0)
        {
            int m = bitMask(setOne(mask,i), p+1) + a[p][i];
            if(dp[mask][p]<m) dp[mask][p] = m;
        }
    }
    return dp[mask][p];
}


void ini()
{
    for(int i=0; i<(1<<n); i++)
        for(int j=0; j<n; j++)
            dp[i][j] = -1;
}

int main()
{
    int t,tc;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>a[i][j];

        ini();
        int k = bitMask(0, 0);

        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
