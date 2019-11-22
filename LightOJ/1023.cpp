#include<bits/stdc++.h>
using namespace std;


int main(){

    int t,tc,n,k;
    vector <char> vc;

    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>n>>k;

        vc.clear();
        for(int i=0; i<n; i++)
            vc.push_back('A'+i);

        cout<<"Case "<<tc<<":\n";
        do{
            for(int i=0; i<n; i++)
                cout<<vc[i];
            cout<<endl;
            k--;
            if(!k) break;
        }while(next_permutation(vc.begin(), vc.end()));
    }

    return 0;
}
