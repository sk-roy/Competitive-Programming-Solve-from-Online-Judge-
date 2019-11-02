#include<bits/stdc++.h>
using namespace std;

int n,w;
int y[105];
int dp[105][105];

int roy(int ii, int baki)
{
    if(ii==n || baki==0) return 0;
    if(dp[ii][baki] != -1) return dp[ii][baki];

    int m = 1;
    for(int i=ii+1; i<n; i++)
    {
        if(y[ii]+w>=y[i]) m++;
        else break;
    }
    dp[ii][baki] = max(roy(ii+1, baki), roy(ii+m, baki-1)+m);
    return dp[ii][baki];
}

void ini()
{
    for(int i=0; i<105; i++)
        for(int j=0; j<105; j++)
            dp[i][j] = -1;
}

int main()
{
    int t,tc,x,k;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>w>>k;
        for(int i=0; i<n; i++)
            cin>>x>>y[i];

        sort(y,y+n);
        ini();
        int m = roy(0, k);

        cout<<"Case "<<tc<<": "<<m<<endl;
    }

    return 0;
}
