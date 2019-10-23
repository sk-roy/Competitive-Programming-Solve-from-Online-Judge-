#include<bits/stdc++.h>
using namespace std;

vector <int> v;
int M[20][20];
int K[20][20];

int MatrixChainOrder(int i, int j)
{
    if(i==j) return M[i][j] = 0;
    if(M[i][j] != -1) return M[i][j];

    M[i][j] = INT_MAX;
    for(int k=i; k<j; k++)
    {
        MatrixChainOrder(i, k);
        MatrixChainOrder(k+1, j);
        int m = M[i][k] + M[k+1][j] + v[i-1]*v[k]*v[j];
        if(m<M[i][j])
        {
            M[i][j] = m;
            K[i][j] = k;
        }
    }

    return M[i][j];
}

string Order(int i, int j)
{
    if(i==j)
    {
        if(i==10) return "A10";
        char c = char('0'+i);
        string s = "A";
        s += c;
        return s;
    }
    string s1 = Order(i, K[i][j]);
    string s2 = Order(K[i][j]+1, j);
    return '(' + s1 + " x " + s2 + ')';
}

void ini()
{
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            M[i][j] = -1;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n,x,y,tc=1;

    while(cin>>n && n)
    {
        v.clear();
        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            if(!i) v.push_back(x);
            v.push_back(y);
        }

        ini();
        MatrixChainOrder(1,n);
        string s = Order(1,n);

        cout<<"Case "<<tc++<<": "<<s<<endl;
    }

    return 0;
}
