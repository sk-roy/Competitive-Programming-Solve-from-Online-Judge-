#include<bits/stdc++.h>
using namespace std;

#define sz 800

int c[]={0,5,10,20,50,100,200};
int nm[sz];
int cn[sz][8];
int dp[sz][8];
bool ck[sz][8];




int main()
{
    freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int n,m,i,j,k,val,d,a,b;

    while(cin>>nm[1])
    {
        d=nm[0];
        for(i=2; i<=6; i++)
        {
            cin>>nm[i];
            d+=nm[i];
        }
        if(!d) break;

        scanf("%d.%d", &a,&b);
        val=a*100+b;


        for(i=0; i<sz; i++)
        {
            for(j=0; j<=6; j++)
            {
                dp[i][j]=INT_MAX;
                ck[i][j]=0;
                cn[i][j]=0;
            }
        }

        for(i=0; i<=6; i++)
        {
            dp[0][i]=0;
            ck[0][i]=1;
            cn[i][j]=0;
        }

        for(i=5; i<sz; i++)
        {
            for(j=1; j<=6; j++)
            {
                if(ck[i][j-1] && dp[i][j-1]<dp[i][j])
                {
                    dp[i][j]=dp[i][j-1];
                    ck[i][j]=1;
                    cn[i][j]=cn[i][j-1];
                }
                if(ck[i-c[j]][j-1] && 1<=nm[j] && dp[i-c[j]][j-1]+1<dp[i][j])
                {
                    dp[i][j]=dp[i-c[j]][j-1]+1;
                    ck[i][j]=1;
                    cn[i][j]=1;
                    cout<<"roy "<<i<<" "<<j<<" "<<dp[i][j] <<endl;
                }
                if(ck[i-c[j]][j] && cn[i-c[j]][j]+1<=nm[j] && dp[i-c[j]][j]+1<dp[i][j])
                {
                    dp[i][j]=dp[i-c[j]][j]+1;
                    ck[i][j]=1;
                    cn[i][j]=cn[i-c[j]][j]+1;
                    cout<<"sk "<<i<<" "<<j<<" "<<dp[i][j] <<endl;
                }
                //cout<<dp[i][j]<<" ";
            }
        }

        int k=INT_MAX;
        for(i=val; i<=val+200; i++)
        {
            k=min(k, dp[i][6]+dp[val-i][6]);
        }
        cout<<k<<endl;
    }

    return 0;
}
