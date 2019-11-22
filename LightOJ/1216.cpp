#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld pi = acos(-1.0);

int main(){

    ld R,r,p,h,v;

    int t,tc;
    cin>>t;

    for(tc=1; tc<=t; tc++){

        cin>>R>>r>>h>>p;

        R = r + (R-r)*p/h;
        v = (pi * p * (R*R + R*r + r*r)) / 3.0;

        cout<<"Case "<<tc<<": ";
        cout<<fixed<<setprecision(10)<<v<<endl;
    }

    return 0;
}
