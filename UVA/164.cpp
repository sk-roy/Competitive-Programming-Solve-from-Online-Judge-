#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
string a,b,c;
vector <int> v;
int dp[25][25];

int recursion(int i, int j)
{
    if(i==a.size()) return dp[i][j]= b.size()-j;
    if(j==b.size()) return dp[i][j]= a.size()-i;

    if(dp[i][j]!=-5) return dp[i][j];

    if(a[i]==b[j]) dp[i][j]=recursion(i+1,j+1);
    else
    {
        dp[i][j]= min(recursion(i+1,j),recursion(i,j+1))+1;
        dp[i][j]= min(dp[i][j] ,recursion(i+1,j+1)+1);
    }

    return dp[i][j];
}

void print(int i, int j, int d)
{
    if(i==a.size())
    {
        for(; j<b.size(); j++)
        {
            c.push_back('I');
            c.push_back(b[j]);
            v.push_back(i+1-d);
            d--;
        }
        return ;
    }
    if(j==b.size())
    {
        for( ; i<a.size(); i++)
        {
            c.push_back('D');
            c.push_back(a[i]);
            v.push_back(i+1-d);
            d++;
        }
        return ;
    }

    if(a[i]==b[j]) print(i+1,j+1,d);
    else
    {
        if(dp[i][j]==dp[i+1][j]+1)
        {
            //cout<<i<<" "<<d<<endl;
            c.push_back('D');
            c.push_back(a[i]);
            v.push_back(i+1-d);
            print(i+1,j,d+1);
        }
        else if(dp[i][j]==dp[i][j+1]+1)
        {
            c.push_back('I');
            c.push_back(b[j]);
            v.push_back(i+1-d);
            print(i,j+1,d-1);
        }
        else if(dp[i][j]==dp[i+1][j+1]+1)
        {
            c.push_back('C');
            c.push_back(b[j]);
            v.push_back(i+1-d);
            print(i+1,j+1,d);
        }
    }

    return ;
}





int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);


    int i,j,k;
    while(cin>>a && a!="#")
    {
        cin>>b;

        for(i=0; i<a.size()+2; i++)
            for(j=0; j<b.size()+2; j++)
                dp[i][j]=-5;

        k=recursion(0,0);
        //cout<<k<<endl;


        c.clear();
        v.clear();

        print(0,0,0);

        j=0;
        for(i=0; i<v.size(); i++,j+=2)
        {
            cout<<c[j]<<c[j+1];
            if(v[i]<10) cout<<0;
            cout<<v[i];
        }
        cout<<"E"<<endl;


    }


    return 0;
}
