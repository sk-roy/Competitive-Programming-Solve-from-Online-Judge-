#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector < vector<ll> > Matrix;
ll mod;

Matrix Multi(Matrix A, Matrix B)
{
    Matrix C(A.size(), vector <ll> (B[0].size()));
    for(int i=0; i<A.size(); i++)
        for(int j=0; j<B[0].size(); j++)
        {
            C[i][j] = 0;
            for(int k=0; k<A[0].size(); k++)
                C[i][j] = (C[i][j] + (A[i][k]*B[k][j])%mod)%mod;
        }
    return C;
}

Matrix expo(Matrix M, ll p)
{
    if(p==1) return M;

    if(p&1) return Multi(M, expo(M, p-1));
    else return expo(Multi(M,M), p/2);
}


ll solve(ll n)
{
    Matrix M = {{1,1},{1,0}};

    M = expo(M, n-1);
    return M[0][0];
}


ll f(ll n)
{
    if(n<2) return n%mod;
    else return (f(n-1)+f(n-2))%mod;
}

int main()
{
    ll n,m,k;
    while(cin>>n>>m)
    {
        mod = 1;
        for(int i=0; i<m; i++) mod*=2;

        if(n<6) cout<<f(n)<<endl;
        else cout<<solve(n)<<endl;
    }

    return 0;
}
