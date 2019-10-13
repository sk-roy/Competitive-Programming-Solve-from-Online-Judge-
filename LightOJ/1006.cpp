#include<bits/stdc++.h>
using namespace std;

long long int dp[10005];

long long int a, b, c, d, e, f;
long long int fn( long long int n ) {
    if(dp[n]!=-1) return dp[n];
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return dp[n]= ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )%10000007;
}

int main() {
    long long int n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%d %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        for(long long int i=0; i<=n; i++)
            dp[i]=-1;
        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
