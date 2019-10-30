#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector < vector<ll> > Matrix;
const ll mod = 1e9;
ll b[20];
ll c[20];

Matrix Multiply(Matrix A, Matrix B)
{
    Matrix C(A.size(), vector <ll> (B[0].size()));
    for(int i=0; i<A.size(); i++)
        for(int j=0; j<B[0].size(); j++)
        {
            C[i][j] = 0;
            for(int k=0; k<B.size(); k++)
                C[i][j] = (C[i][j] + (A[i][k]*B[k][j])%mod )%mod;
        }
    return C;
}

Matrix expo(Matrix M, ll p)
{
    if(p==1) return M;
    if(p&1) return Multiply(M, expo(M, p-1));
    else return expo(Multiply(M, M), p/2);
}


ll solve(ll n, ll k)
{
    Matrix M(k, vector <ll> (k));
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
        {
            if(i==0) M[i][j] = c[j];
            else if(i-1==j) M[i][j] = 1;
            else M[i][j] = 0;
        }

    M = expo(M, n-k);
    ll ans = 0;
    for(int i=0; i<k; i++)
        ans = (ans + (M[0][i]*b[k-i-1])%mod )%mod;

    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,k,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>k;
        for(int i=0; i<k; i++) cin>>b[i];
        for(int i=0; i<k; i++) cin>>c[i];
        for(int i=0; i<k; i++) b[i] %= mod;
        for(int i=0; i<k; i++) c[i] %= mod;
        cin>>n;

        if(n<=k) ans = b[n-1];
        else ans = solve(n, k);

        cout<<ans<<endl;
    }

    return 0;
}
