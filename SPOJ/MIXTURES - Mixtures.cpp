#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 100;
const int N = 205;

int color[N][N];
int smoke[N][N];
int c[N];

int MatrixChainMulti(int l, int r, int n){
    if(l==r)
    {
        smoke[l][r]=0;
        return color[l][r] = c[l];
    }
    //cout<<l<<" "<<r<<endl;
    if(color[l][r]!=-1) return color[l][r];

    smoke[l][r] = INT_MAX;
    for(int k=l; k<r; k++){
        int a = MatrixChainMulti(l,k,n);
        int b = MatrixChainMulti(k+1,r,n);
        int s = smoke[l][k] + smoke[k+1][r] + (a*b);

        if(s<smoke[l][r]){
           smoke[l][r] = s;
           color[l][r] = (a+b)%mod;
        }
        //cout<<
    }
    return color[l][r];
}


void ini(int n){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            color[i][j]=-1;
}

void roy(int n){

    for(int i=1; i<=n; i++) cin>>c[i];
    ini(n);

    MatrixChainMulti(1,n,n);

    cout<<smoke[1][n]<<endl;

    return ;
}

int main(){
    //freopen("input.txt", "r", stdin);

    int n;
    while(cin>>n){
        roy(n);
    }
    return 0;
}
