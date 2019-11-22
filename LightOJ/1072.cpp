#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld pi = acos(-1.0);

int main(){

    int t,tc;
    ld R,r,n;

    cin>>t;
    for(tc=1; tc<=t; tc++){

        cin>>R>>n;
        r = (R*sin(pi/n))/(sin(pi/n)+1.0);

        cout<<"Case "<<tc<<": ";
        cout<<fixed<<setprecision(10)<<r<<endl;
    }

    return 0;
}
