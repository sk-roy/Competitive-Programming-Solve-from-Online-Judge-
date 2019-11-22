#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld pi = acos(-1.0);

int main(){

    int t,tc;
    ld r1,r2,r3;

    cin>>t;

    for(tc=1; tc<=t; tc++){

        cin>>r1>>r2>>r3;

        ld a = (r1+r2);
        ld b = (r3+r2);
        ld c = (r1+r3);

        ld s = (a+b+c)/2.0;
        ld totalArea = sqrt(s*(s-a)*(s-b)*(s-c));

        ld a1 = acos((a*a + c*c - b*b) / (2.0*a*c));
        ld a2 = acos((a*a + b*b - c*c) / (2.0*a*b));
        ld a3 = acos((b*b + c*c - a*a) / (2.0*b*c));

        ld nonBlue = (r1*r1*a1 + r2*r2*a2 + r3*r3*a3) / 2.0;
        ld blueArea = totalArea - nonBlue;

        cout<<"Case "<<tc<<": ";
        cout<<fixed<<setprecision(10)<<blueArea<<endl;
    }


    return 0;
}
