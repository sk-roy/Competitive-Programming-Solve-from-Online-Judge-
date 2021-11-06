#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int n, l, b, man, li, bi;
    cin>>l>>b;
    cin>>n;
    man = 0;
    while(n--){
        cin>>li>>bi;
        man += max((li/l)*(bi/b), (li/b)*(bi/l));
    }
    cout<<man<<endl;

    return 0;
}
