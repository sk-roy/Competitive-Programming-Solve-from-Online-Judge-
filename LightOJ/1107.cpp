#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
    int x1,x2,x,y,y1,y2,t,tc,m;
 
    cin>>t;
    for(tc=1; tc<=t; tc++){
 
        cin>>x1>>y1>>x2>>y2;
        cin>>m;
        cout<<"Case "<<tc<<":\n";
        for(int i=0; i<m; i++){
            cin>>x>>y;
            if(x1<x && x<x2 && y1<y && y<y2) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
 
    return 0;
}
 
