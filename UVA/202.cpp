#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int n,m,i,j,k,a,b;
    vector < pair<int,int> > v[10];
    vector <int> vc;

    while(cin>>n>>m)
    {
        int nn=n;
        for(i=0; i<10; i++)
            v[i].clear();
        vc.clear();

        vc.push_back(n/m);
        n=n%m;
        n*=10;
        bool done =false;
        int kk,ii;

        while(n)
        {
            //cout<<n<<" ";
            if(n<m) k=0;
            else
            {
                k=n/m;
                n=n%m;
            }
            for(i=0; i<v[k].size(); i++)
            {
                if(v[k][i].first==n)
                {
                    done=true;
                    kk=k;
                    ii=v[k][i].second;
                    break;
                }
            }
            if(done) break;

            vc.push_back(k);
            v[k].push_back({n,vc.size()-1});
            n*=10;
            //cout<<vc.back()<<endl;
            //system("pause");
        }


        cout<<nn<<"/"<<m<<" = ";
        int sz= vc.size();
        for(i=0; i<min(51, sz); i++)
        {
            if(done && i==ii) cout<<'(';
            cout<<vc[i];
            if(!i) cout<<".";
        }
        if(done && sz-ii>=50) cout<<"...";
        if(!done) cout<<"(0";
        cout<<')'<<endl;
        if(done) kk=max(1, sz-ii);
        else kk=1;
        cout<<"   "<<kk<<" = number of digits in repeating cycle"<<endl;
        cout<<endl;
    }


    return 0;
}
