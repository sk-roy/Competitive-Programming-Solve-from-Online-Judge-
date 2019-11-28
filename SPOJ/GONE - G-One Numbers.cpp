#include<bits/stdc++.h>
using namespace std;

const int N = 500;

bool p[N];
vector <int> v;
int vz;
int dp[12][100][2];

void seive(){
    for(int i=2; i<N; i++) p[i] = 1;
    for(int i=2; i*i<N; i++)
        if(p[i])
            for(int j=i*i; j<N; j+=i)
                p[j] = 0;
}

int roy(int i, int s, bool low){
    if(i==vz){
        if(low && p[s]) return 1;
        else return 0;
    }
    if(dp[i][s][low] != -1) return dp[i][s][low];

    int k = 0;
    for(int j=0; j<10; j++){
        if(!low && j>v[i]) break;
        k += roy(i+1, s+j, (low | (j<v[i])));
    }
    return dp[i][s][low] = k;
}


int solve(int n){
    v.clear();
    while(n){
        v.push_back(n%10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    vz = v.size();
    memset(dp, -1, sizeof(dp));

    int k = roy(0, 0, 0);
    return k;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    seive();
    int t,a,b,k;
    cin>>t;

    while(t--){
        cin>>a>>b;
        if(a>b) swap(a,b);

        k = solve(b+1) - solve(a);
        cout<<k<<endl;
    }

    return 0;
}
