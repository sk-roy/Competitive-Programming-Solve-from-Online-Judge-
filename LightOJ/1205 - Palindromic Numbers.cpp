#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector <ll> v;
ll dp[20][20][2][2][2];

ll sk(ll i, ll j, bool lw, bool hi, bool noLd){
    if(i>j){
        if(!lw && hi) return 0;
        else return 1;
    }
    if(dp[i][j][lw][hi][noLd] != -1) return dp[i][j][lw][hi][noLd];

    ll m, sum = 0;
    bool llw, hhi, nnoLd;
    for(ll k=0; k<10; k++){
        if(!lw && k>v[i]) break;
        llw = lw | (k<v[i]);
        if(k>v[j]) hhi = 1;
        else if(k<v[j]) hhi = 0;
        else hhi = hi;
        nnoLd = noLd | (k!=0);
        m = sk(i+1, j-(ll)nnoLd, llw, hhi, nnoLd);
        sum += m;
    }

    return dp[i][j][lw][hi][noLd] = sum;
}


ll solve(ll n){
    if(n<0) return 0;
    if(n<10) return n+1;

    v.clear();
    while(n){
        v.push_back(n%10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));

    ll k = sk(0, v.size()-1, 0, 0, 0);
    return k;
}


int main(){
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,tc,a,b;

    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>a>>b;
        if(a>b) swap(a,b);

        b = solve(b);
        a = solve(a-1);
        ll k = b-a;

        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
