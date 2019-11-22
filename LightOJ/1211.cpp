#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){

    ll t,tc,x1,y1,z1,x2,y2,z2,n;
    ll mxx,mxy,mxz,mnx,mny,mnz;

    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>n;

        mxx = mxy = mxz = -1e10;
        mnx = mny = mnz = 1e10;

        for(ll i=0; i<n; i++){

            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            mxx = max(mxx, x1);
            mxy = max(mxy, y1);
            mxz = max(mxz, z1);
            mnx = min(mnx, x2);
            mny = min(mny, y2);
            mnz = min(mnz, z2);
        }

        ll volume;

        if(mxx>=mnx || mxy>=mny || mxz>=mnz) volume = 0;
        else volume = abs(mxx-mnx) * abs(mxy-mny) * abs(mxz-mnz);

        cout<<"Case "<<tc<<": "<<volume<<endl;
    }

    return 0;
}
