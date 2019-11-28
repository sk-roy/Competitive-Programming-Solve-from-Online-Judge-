#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll vz;
vector <ll> v;
ll dp[20][200][2];

ll roy(ll i, ll s, bool lw){

    if(i==vz) {
        if(lw) return s;
        else return 0;
    }
    if(dp[i][s][lw] != -1) return dp[i][s][lw];

    ll k = 0;
    for(ll j=0; j<10; j++){
        if(j>v[i] && !lw) break;
        k += roy(i+1, s+j, (lw | (j<v[i])) );
    }

    return dp[i][s][lw] = k;
}

ll solve(ll n){
    v.clear();
    while(n){
        v.push_back(n%10);
        n /= 10;
    }
    vz = v.size();
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));

    ll k = roy(0, 0, 0);
    return k;
}

int main(){
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,a,b,k;
    cin>>t;

    while(t--){
        cin>>a>>b;
        if(a+b==-2) break;

        k = solve(b+1) - solve(a);
        cout<<k<<endl;
    }

    return 0;
}

