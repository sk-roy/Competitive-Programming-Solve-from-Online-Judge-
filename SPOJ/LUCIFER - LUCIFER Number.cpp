#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool prime[205];
int dp[12][120][120][2];

void seive(){
    for(int i=2; i<200; i++) prime[i] = 1;
    for(int i=2; i*i<200; i++)
        if(prime[i])
            for(int j=i*i; j<200; j+=i)
                prime[j] = 0;
}

int vz;
vector <int> v;

int roy(int i, int even, int odd, bool low){
    //cout<<i<<" "<<even<<" "<<odd<<" "<<low<<endl;
    if(i==vz){
        if(low && even>odd && prime[even-odd]) return 1;
        else return 0;
    }
    if(dp[i][even][odd][low] != -1)
        return dp[i][even][odd][low];

    int k = 0, e=0, o=0;

    for(int j=0; j<10; j++){
        if(!low && j>v[i]) break;
        if((vz-i)%2) o = j;
        else e = j;
        k += roy(i+1, even+e, odd+o, (low | (j<v[i])) );
    }

    return dp[i][even][odd][low] = k;
}

int solve(int n){
    //cout<<n<<endl;
    v.clear();
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    vz = v.size();
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));

    int k = roy(0, 0, 0, 0);
    return k;
}

int main(){
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,a,b;
    seive();

    cin>>t;
    while(t--){
        cin>>a>>b;
        b = solve(b+1);
        //cout<<b<<" ";
        a = solve(a);
        //cout<<a<<endl;
        cout<<b-a<<endl;
    }

    return 0;
}
