#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

int main(){

    int t,tc;
    ld a,b,c,d,x,h,area;

    cin>>t;

    for(tc=1; tc<=t; tc++){
        cin>>a>>b>>c>>d;
        if(c>a) swap(a,c);

        x = ((a-c)*(a-c) - b*b + d*d) / (2*(a-c));
        h = sqrt(d*d - x*x);

        area = (a+c)*h / 2.0;

        cout<<"Case "<<tc<<": ";
        cout<<fixed<<setprecision(8)<<area<<endl;
    }

    return 0;
}
