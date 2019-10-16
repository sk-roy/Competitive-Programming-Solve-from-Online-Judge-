#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<stdio.h>
#include<map>
using namespace std;
#define mx 30

int low[mx],disc[mx],visited[mx];
bool edge[mx][mx];
int group,n,timer;
stack <int> stk;
map <string, int> mp;
map <int, int> check;
vector <string> v;


int tarjan(int u)
{
    visited[u]=1;
    low[u]=disc[u]=++timer;
    stk.push(u);
    for(int i=1; i<=n; i++)
    {
        if(edge[u][i] && visited[i]==0)
            low[u]=min(low[u],tarjan(i));
        else if(edge[u][i] && visited[i]==1)
            low[u]=min(low[u],disc[i]);
    }

    if(low[u]==disc[u])
    {
        group++;
        int comma=0;
        while(1)
        {
            int k=stk.top();
            stk.pop();
            low[k]=low[u];
            visited[k]=2;

            if(!check[k])
            {
                if(comma>0) cout<<", ";
                comma++;
                cout<<v[k];
                check[k]=1;
            }

            if(k==u) break;
        }
        cout<<endl;
    }
    return low[u];
}


void initial()
{
    while(!stk.empty()) stk.pop();
    mp.clear();
    check.clear();
    v.clear();
    timer=0;
    group=0;
    for(int i=1; i<=n; i++)
    {
        visited[i]=0;
        for(int j=1; j<=n; j++)
            edge[i][j]=0;
    }
}

int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int i,t,k,tc=1;
    string s1,s2;
    while(cin>>n>>t)
    {
        if(n==0 && t==0) break;
        initial();
        v.push_back("sujit");
        //cout<<"Roy"<<endl;
        for(i=1; i<=t; i++)
        {
            cin>>s1>>s2;
            if(!mp[s1])
            {
                v.push_back(s1);
                mp[s1]=v.size()-1;
            }
            if(!mp[s2])
            {
                v.push_back(s2);
                mp[s2]=v.size()-1;
            }

            edge[mp[s1]][mp[s2]]=1;
        }

        if(tc>1) cout<<endl;

        cout<<"Calling circles for data set "<<tc++<<":"<<endl;


        if(t>0)
        for(i=1; i<=n; i++)
        {
            if(!visited[i])
                tarjan(i);
        }

        //cout<<endl;



        /*
        cout<<"Name: ";
        for(i=1; i<v.size(); i++)
            cout<<v[i]<<" ";
        cout<<endl;

        cout<<"Low: ";
        for(i=1; i<=n; i++)
            cout<<low[i]<<" ";
        cout<<endl;




        for(i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                cout<<edge[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        */


    }
    return 0;
}

