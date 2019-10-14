#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int a[21],b[21];
int dp[21][21];
int n;


int calcu(int i, int j)
{
    if(i>=n || j>=n) return 0;
    if(dp[i][j]!=-5) return dp[i][j];

    if(a[i]==b[j]) dp[i][j]=calcu(i+1,j+1)+1;
    else dp[i][j]= max( calcu(i+1,j), calcu(i,j+1) );
    return dp[i][j];
}


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int i,j,k;
    bool buffer=true;
    string s;

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>k;
        a[k-1]=i+1;
    }

    while(getline(cin,s))
    {
        if(buffer)
        {
            getline(cin,s);
            buffer=false;
        }
        //getline(cin,s);

        if(s.size()>2)
        {
            k=j=0;
            for(i=0; i<=s.size(); i++)
            {
                if(s[i]==NULL || s[i]==' ')
                {
                    if(k!=0) b[k-1]=j+1;
                    j++;
                    k=0;
                }
                else
                {
                    k*=10;
                    k+=(int)s[i]-48;
                }
            }

            //k=0;
            for(i=0; i<n; i++)
            {
                //if(a[i]==b[i]) k++;
                for(j=0; j<n; j++)
                    dp[i][j]=-5;
            }

            cout<<calcu(0,0)<<endl;
        }
        else
        {
            n=0;
            for(i=0; i<s.size(); i++)
            {
                n*=10;
                n+=(int)s[i]-48;
            }
            for(i=0; i<n; i++)
            {
                cin>>k;
                a[k-1]=i+1;
            }
            buffer=true;
        }
    }

    return 0;
}
