#include<bits\stdc++.h>
using namespace std;

typedef long long int lli;

lli calcu(lli n){
   if(n%4==1) return -n;
   else if(n%4==2) return 1;
   else if(n%4==3) return n+1;
   else return 0;
}

int main(){

    lli t, x, n, fx;

    cin>>t;
    while(t--){
        cin>>x>>n;
        if(x%2) cout<<x-calcu(n)<<endl;
        else cout<<x+calcu(n)<<endl;
    }

    return 0;
}
