#include<bits/stdc++.h>
using namespace std;

int dp[25][5];
int a[25][5];

int roy(int i, int n, int prev)
{
    if(i==n) return 0;
    if(dp[i][prev] != -1) return dp[i][prev];

    int k = 1e5;
    if(prev != 0) k = min(k, roy(i+1, n, 0)+a[i][0]);
    if(prev != 1) k = min(k, roy(i+1, n, 1)+a[i][1]);
    if(prev != 2) k = min(k, roy(i+1, n, 2)+a[i][2]);

    return dp[i][prev] = k;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,tc,n,m;
    cin>>t;

    for(tc=1; tc<=t; tc++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i][0]>>a[i][1]>>a[i][2];

        for(int i=0; i<25; i++)
            for(int j=0; j<5; j++)
                dp[i][j] = -1;

        int k = roy(0, n, 5);

        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
