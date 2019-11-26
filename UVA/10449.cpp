#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 210;
const ll inf = 1e17;

ll busy[N];
ll cost[N];
bool cycle[N];
vector < pair<ll,ll> > vp;


int main(){

    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    ll n,tc=1;
    while(cin>>n){

        for(ll i=1; i<=n; i++){
            cin>>busy[i];
        }

        ll r,u,v;
        vp.clear();
        cin>>r;
        for(ll i=1; i<=r; i++){
            cin>>u>>v;
            vp.push_back({u,v});
        }

        for(ll i=1; i<=n; i++){
            cost[i] = inf;
            cycle[i] = 0;
        }
        cost[1] = 0;

        for(ll i=1; i<=n; i++){
            for(ll j=0; j<r; j++){
                u = vp[j].first;
                v = vp[j].second;
                ll k = busy[v]-busy[u];
                k = k*k*k;

                if(cost[u]+k<cost[v]){
                    if(cost[u]!=inf)
                        cost[v] = cost[u]+k;
                    if(i==n){
                        cycle[u] = true;
                        cycle[v] = true;
                    }
                }
            }
        }

        cout<<"Set #"<<tc++<<"\n";

        ll q;
        cin>>q;
        for(ll i=1; i<=q; i++){
            cin>>u;

            if(cost[u]<3 || cost[u]==inf || cycle[u]) cout<<"?\n";
            else cout<<cost[u]<<"\n";
        }
    }


    return 0;
}
