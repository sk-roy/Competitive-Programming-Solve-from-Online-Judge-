#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, vz;
vector <ll> v;
ll dp[10][95][95][2];

ll roy(ll i, ll n, ll s, bool lw){
    //cout<<i<<" "<<n<<endl;
    if(i==vz){
        if(!n && !s && lw) return 1;
        else return 0;
    }
    if(dp[i][n][s][lw] != -1) return dp[i][n][s][lw];

    ll m = 0;
    for(ll j=0; j<10; j++){
        if(j>v[i] && !lw) break;
        ll nn = ((n*10) + j) % k;
        ll ss = (s+j) % k;
        m += roy(i+1, nn, ss, (lw | (j<v[i])));
    }

    return dp[i][n][s][lw] = m;
}

ll solve(ll n){

    if(k>90) return 1;

    v.clear();
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    vz = v.size();
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));

    ll m = roy(0, 0, 0, 0);
    return m;
}

int main(){
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,tc;
    ll a,b;

    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>a>>b>>k;
        //cout<<a<<" "<<b<<" "<<k<<endl;
        b = solve(b+1);
        a = solve(a);

        cout<<"Case "<<tc<<": "<<b-a<<endl;
    }

    return 0;
}
