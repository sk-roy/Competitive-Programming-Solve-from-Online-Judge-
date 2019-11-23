#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

int main(){

    int t,tc;
    ll ax,ay,bx,by,cx,cy,dx,dy,a,b,c,dist,area;

    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>ax>>ay>>bx>>by>>cx>>cy;

        dx = cx-(bx-ax);
        dy = ay+(cy-by);

        area = abs(ax*by + bx*cy + cx*dy + dx*ay
                - (ay*bx) - (by*cx) - (cy*dx) - (dy*ax)) / 2;

        cout<<"Case "<<tc<<": ";
        cout<<dx<<" "<<dy<<" "<<area<<endl;
    }


    return 0;
}
