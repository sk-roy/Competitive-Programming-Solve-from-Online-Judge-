#include<bits/stdc++.h>
using namespace std;
 
typedef long double ld;
const ld pi = acos(-1.0);
 
ld dist(ld xa, ld ya, ld xb, ld yb){
    return sqrt( (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) );
}
 
ld Area(ld r, ld xb, ld yb, ld xc, ld yc){
    ld c = dist(xb,yb,xc,yc);
    ld angle = acos( (2*r*r - c*c) / (2.0*r*r) );
    ld area = (angle*r*r) / 2.0;
    return abs(area);
}
 
int main(){
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int t,tc;
    ld xa,ya,ra,xb,yb,rb;
 
    cin>>t;
 
    for(tc=1; tc<=t; tc++){
        cin>>xa>>ya>>ra>>xb>>yb>>rb;
 
        ld d = dist(xa,ya,xb,yb);
        if(d>(ra+rb)){
            cout<<"Case "<<tc<<": "<<0<<endl;
            continue;
        }
        if(d+ra<=rb || d+rb<=ra){
            ld area = pi * min(ra,rb) * min(ra,rb);
            cout<<"Case "<<tc<<": "<<area<<endl;
            continue;
        }
 
        ld angleA = acos((d*d + ra*ra - rb*rb) / (2.0*d*ra));
        ld angleB = acos((d*d + rb*rb - ra*ra) / (2.0*d*rb));
 
        ld aArea = ra*ra * angleA;
        ld bArea = rb*rb * angleB;
 
        //cout<<aArea<<"--->"<<bArea<<endl;
        ld s = (ra+rb+d) / 2.0;
 
        ld totalArea = sqrt(s*(s-ra)*(s-rb)*(s-d)) * 2.0;
 
        ld conflictArea = abs(aArea + bArea - totalArea);
 
        //cout<<aArea<<" "<<bArea<<" "<<totalArea<<endl;
 
        cout<<"Case "<<tc<<": ";
        cout<<fixed<<setprecision(10)<<conflictArea<<endl;
    }
 
 
    return 0;
}
