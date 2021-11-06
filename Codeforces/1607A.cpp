#include<bits/stdc++.h>
using namespace std;


int main(){

    int t,time, temp;
    string series, word;
    int position[300];
    cin>>t;
    while(t--){
        cin>>series;
        cin>>word;
        time = 0;
        for(int i=0; i<26; i++){
            position[series[i]] = i;
        }
        for(int i=1; i<word.size(); i++){
            time += abs( position[word[i]] - position[word[i-1]] );
        }
        cout<<time<<endl;
    }

    return 0;
}
