#include<bits/stdc++.h>
using namespace std;

char s[105];
vector < pair <int,int> > vp[3] =
{{{0,1},{1,0},{2,2}},
{{0,0},{1,1},{1,2},{2,1}},
{{0,2},{2,0}}};

struct no{
    bool ch[3];
};
no dp[105][105];

void ini(int n)
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = {0,0,0};
}

no MatrixChainOrder(int i, int j)
{
    if(i==j)
    {
        dp[i][j].ch[s[i]-'X']=1;
        return dp[i][j];
    }
    if(dp[i][j].ch[0]==1 || dp[i][j].ch[1]==1 || dp[i][j].ch[2]==1)
    {
        //cout<<"Roy"<<endl;
        return dp[i][j];
    }

    for(int k=i; k<j; k++)
    {
        no m1 = MatrixChainOrder(i, k);
        no m2 = MatrixChainOrder(k+1, j);

        for(int ii=0; ii<3; ii++)
        {
            if(dp[i][j].ch[ii]) continue;
            for(int jj=0; jj<vp[ii].size(); jj++)
            {
                if(m1.ch[vp[ii][jj].first] && m2.ch[vp[ii][jj].second])
                {
                    dp[i][j].ch[ii]=1;
                    break;
                }
            }
        }
        if(dp[i][j].ch[0]==1 && dp[i][j].ch[1]==1 && dp[i][j].ch[2]==1) break;
    }
    return dp[i][j];
}


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w",stdout);

    int t;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%s", s);
        //cout<<s<<endl;
        int n = strlen(s);
        ini(n);
        no m = MatrixChainOrder(0, n-1);

        if(m.ch[2]) printf("Z\n");
        else if(m.ch[1]) printf("Y\n");
        else printf("X\n");
    }

    return 0;
}
