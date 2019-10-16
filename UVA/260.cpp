#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char str[210][210];
int check[210][210];
bool result;
int dx[]={1,-1, 0, 0, 1,-1};
int dy[]={0, 0, 1,-1, 1,-1};


void dfs_black(int x, int y, int n)
{
    if(x<0 || x>=n || y<0 || y>=n || str[y][x]=='w' || result==false) return ;


    str[y][x]='w';

    if(y+1==n)
    {
        result=false;
        return ;
    }

    //cout<<x<<" "<<y<<endl;
    for(int i=0; i<6; i++)
        dfs_black(x+dx[i], y+dy[i], n);
    return ;
}

int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int n,i,j,k;
    k=1;
    while(cin>>n && n!=0)
    {
        result=true; //white won
        for(i=0; i<n; i++)
            cin>>str[i];
        /*for black
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                check[i][j]=0;
        */
        for(i=0; i<n; i++)
        {
            if(result==false) break;
            if(str[0][i]=='b')
                dfs_black(i,0,n);
        }

        if(result==true) cout<<k++<<" "<<'W'<<endl;
        else cout<<k++<<" "<<'B'<<endl;
    }
    return 0;
}
