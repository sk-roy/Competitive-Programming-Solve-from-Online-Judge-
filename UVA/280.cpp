#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
using namespace std;
vector <int> way[101];
bool visited[101];


void dfs(int u)
{

    if(visited[u]) return ;
    visited[u]=1;

    for(int i=0; i<way[u].size(); i++)
    {
        int v=way[u][i];
        if(!visited[v]) dfs(v);
    }

    return ;
}


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int n,i,j,k,s,ss,u,v;
    vector <int> vc;

    while(cin>>n && n!=0)
    {
        for(i=1; i<=n; i++)
            way[i].clear();
        //cout<<"Roy"<<endl;
        while(cin>>u && u!=0)
            while(cin>>v && v!=0)
                way[u].push_back(v);

        //cout<<"Roy2"<<endl;
        cin>>ss;
        for(i=0; i<ss; i++)
        {
            cin>>s;

            for(j=1; j<=n; j++)
                visited[j]=0;
            for(j=0; j<way[s].size(); j++)
                dfs(way[s][j]);
            vc.clear();
            for(j=1; j<=n; j++)
                if(!visited[j]) vc.push_back(j);
            cout<<vc.size();
            if(vc.size()) cout<<" ";
            for(j=0; j<vc.size(); j++)
            {
                if(j!=0) cout<<" ";
                cout<<vc[j];
            }
            cout<<endl;
        }

    }


    return 0;
}
