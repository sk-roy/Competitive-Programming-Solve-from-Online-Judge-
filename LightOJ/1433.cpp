#include<bits/stdc++.h>
using namespace std;
 
typedef long double ld;
 
int main(){
 
    //freopen("input.txt", "r", stdin);
 
    ld ox,oy,ax,ay,bx,by;
    int t,tc;
 
    cin>>tc;
    for(t=1; t<=tc; t++){
        cin>>ox>>oy>>ax>>ay>>bx>>by;
 
        ld a = sqrt((ox-ax)*(ox-ax) + (oy-ay)*(oy-ay));
        ld b = sqrt((ox-bx)*(ox-bx) + (oy-by)*(oy-by));
        ld c = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
 
        ld angle = acos((a*a + b*b - c*c) / (2.0*a*b));
        ld arc = angle * a;
 
        cout<<"Case "<<t<<": ";
        cout<<fixed<<setprecision(10)<<arc<<endl;
    }
 
    return 0;
}
