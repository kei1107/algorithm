#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337>
 問題文============================================================
 =================================================================
 解説=============================================================
 座圧を行えば愚直な数え上げができる。
 平面の枠を明確にするための追加処理を忘れなようにする
 ================================================================
 */

ll solve(ll n){
    ll res = 0;
    vector<ll> x1(n),x2(n),y1(n),y2(n);
    vector<ll> xs(2*n),ys(2*n);
    for(int i = 0; i < n;i++){
        ll l,t,r,b; cin >> l >> t >> r >> b;
        l *= 2; t *= 2; r *= 2; b *= 2;
        x1[i] = l; y1[i] = b;
        x2[i] = r; y2[i] = t;
        xs[2*i] = l; xs[2*i+1] = r;
        ys[2*i] = b; ys[2*i+1] = t;
    }
    xs.push_back(-INF); xs.push_back(INF);
    ys.push_back(-INF); ys.push_back(INF);
    for(int i = 0; i < n;i++){
        for(int j = -1; j <= 1;j+=2){
            xs.push_back(x1[i]+j);
            xs.push_back(x2[i]+j);
            ys.push_back(y1[i]+j);
            ys.push_back(y2[i]+j);
        }
    }
    sort(xs.begin(),xs.end()); xs.erase(unique(xs.begin(),xs.end()),xs.end());
    sort(ys.begin(),ys.end()); ys.erase(unique(ys.begin(),ys.end()),ys.end());
    for(int i = 0; i < n;i++){
        x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin() + 2;
        x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin() + 2;
        y1[i] = lower_bound(ys.begin(), ys.end(), y1[i]) - ys.begin() + 2;
        y2[i] = lower_bound(ys.begin(), ys.end(), y2[i]) - ys.begin() + 2;
    }

    vector<vector<int>> masu(xs.size()+5,vector<int>(ys.size()+5,0));
    for(int i = 0; i < n; i++){
        for(ll j = x1[i]; j <= x2[i]; j++){
            masu[j][y1[i]] = masu[j][y2[i]] = i+1;
        }
        for(ll k = y1[i]; k <= y2[i];k++){
            masu[x1[i]][k] = masu[x2[i]][k] = i+1;
        }
    }
    for(int i = 0; i < xs.size()+5;i++) masu[i][0] = masu[i][ys.size()+4] = -1;
    for(int j = 0; j < ys.size()+5;j++) masu[0][j] = masu[xs.size()+4][j] = -1;
    
    int d[5] = {1,0,-1,0,1};
    for(int i = 0; i < xs.size()+5;i++){
        for(int j = 0; j < ys.size()+5;j++){
            if(masu[i][j] != 0) continue;
            
            res++;
            queue<pii> q; q.push({i,j});
            while(q.size()){
                int x,y; tie(x,y) = q.front(); q.pop();
                if(masu[x][y] != 0) continue;
                masu[x][y] = -1;
                for(int k = 0; k < 4;k++){
                    int nx = x + d[k],ny = y + d[k+1];
                    q.push({nx,ny});
                }
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll n;
    while(cin >> n,n){
        cout << solve(n) << endl;
    }
    return 0;
}
