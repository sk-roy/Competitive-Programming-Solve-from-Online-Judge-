#include<bits/stdc++.h>
using namespace std;

string s;
int dp[300][300];
int sweet[300];

int MatrixChain(int i, int j)
{
    if(i==j) return dp[i][j] = sweet[j]-sweet[i-1];

    if(dp[i][j] != -1) return dp[i][j];

    int m = sweet[j]-sweet[i-1];
    if(m==0) return dp[i][j] = 0;
    if(m*2>j-i+1) return dp[i][j] = j-i+1;

    dp[i][j] = 0;
    for(int k=i; k<j; k++)
    {
        m = MatrixChain(i, k) + MatrixChain(k+1, j);
        if(m>dp[i][j]) dp[i][j] = m;
    }
    return dp[i][j];
}

void ini(int n)
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;
}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        s='s'+s;

        ini(n);

        sweet[0]=0;
        for(int i=1; i<=n; i++)
        {
            sweet[i]=sweet[i-1];
            if(s[i]=='1') sweet[i]++;
        }

        k = MatrixChain(1,n);
        cout<<k<<endl;
    }

    return 0;
}
