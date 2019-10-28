#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector < vector<ll> > Matrix;
ll mod;
ll a[20], f[20];

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


ll solve(ll n, ll d)
{
    Matrix M(d, vector <ll> (d));

    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
        {
            if(i==0) M[i][j] = a[j+1];
            else if(i-1==j) M[i][j] = 1;
            else M[i][j] = 0;
        }
    }


    M = expo(M, n-d);
    ll m = 0;
    for(int i=0; i<d; i++)
        m = (m+ (M[0][i]*f[d-i]) %mod) %mod;
    return m;
}



int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m,k,d;
    while(cin>>d>>n>>mod && !(d==0 && n==0 && mod==0))
    {
        for(int i=1; i<=d; i++) cin>>a[i];
        for(int i=1; i<=d; i++) cin>>f[i];


        if(n<=d) cout<<f[n]<<endl;
        else cout<<solve(n, d)<<endl;
    }

    return 0;
}

