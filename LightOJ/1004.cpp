#include<bits/stdc++.h>
using namespace std;

int n;
int dp[205][205];
int dc[205][205];
int mt[205][205];


void recur(int i, int j)
{
    int m,k;
    if(i<=n) m=i;
    else m=2*n-i;
    if(i>2*n-1 || j>m || j<1) return ;
    if(i==2*n-1 && j==1)
    {
        dp[i][j]=mt[i][j];
        dc[i][j]=1;
        //return ;
    }

    if(dp[i][j]!=0) return ;

    if(i>=n) k=-1;
    else k=1;
    recur(i+1,j);
    recur(i+1,j+k);

    dc[i][j]=1;
    dp[i][j]= mt[i][j];
    if(dc[i+1][j] && dc[i+1][j+k])
        dp[i][j]+= max(dp[i+1][j], dp[i+1][j+k]);
    else if(dc[i+1][j]) dp[i][j]+= dp[i+1][j];
    else if(dc[i+1][j+k]) dp[i][j]+= dp[i+1][j+k];
    else dc[i][j]=0;
    //cout<<i<<" "<<j<<" "<<dc[i][j]<<" "<<dp[i][j]<<endl;
    return ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t,tc,i,j,k,m;
    scanf("%d", &t);

    for(tc=1; tc<=t; tc++)
    {
        scanf("%d", &n);
        for(i=1; i<=n; i++)
            for(j=1; j<=i; j++)
                scanf("%d", &mt[i][j]);

        for(i=n+1; i<2*n; i++)
            for(j=1; j<=(2*n)-i; j++)
                scanf("%d", &mt[i][j]);

        for(i=1; i<(2*n); i++)
            for(j=1; j<n+2; j++)
            {
                dp[i][j]=0;
                dc[i][j]=0;
            }

        recur(1,1);
        //cout<<"Case "<<tc<<": "<<dp[1][1]<<endl;
        printf("Case %d: %d\n", tc, dp[1][1]);
    }
    return 0;
}
