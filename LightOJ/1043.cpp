#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

int main(){

    ld a,b,c,ra;
    int t,tc;

    cin>>t;
    for(tc=1; tc<=t; tc++){

        cin>>a>>b>>c>>ra;

        ra = ra / (ra + 1.0);
        ld d = a * sqrt(ra);

        cout<<"Case "<<tc<<": ";
        cout<<fixed<<setprecision(10)<<d<<endl;
    }

    return 0;
}
