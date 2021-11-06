#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;
const int mod = 1e9+7;

int main(){

    int arr[N];
    int t, n, profit;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n);
        profit = 0;
        for(int i=0; i<n; i++)
            profit = ( profit + max(0, arr[i]-n+i+1) ) % mod;
        cout<<profit<<endl;
    }

    return 0;
}
