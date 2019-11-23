#include<bits/stdc++.h>
using namespace std;
 
typedef long double ld;
 
int main(){
 
    int t,tc;
    ld a,b,c,d1,d2;
 
    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>a>>b>>c;
 
        d1 = (a*c) / b;
        d2 = (a+d1)*(c+d1) / (b-d1);
        ld d = d1+d2;
        if(a+b+c==0) d = 5;
        else if(d==0 || d1>=b) d = -1;
 
        //cout<<fixed<<setprecision(10)<<d1<<" "<<d2<<endl;
 
        cout<<"Case "<<tc<<": ";
        if(d==-1) cout<<-1<<endl;
        else cout<<fixed<<setprecision(10)<<d<<endl;
    }
 
 
    return 0;
}
