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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1186&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 先にありえる長方形を列挙しておき、
 与えられた入力に対してその中から探索すれば良い
 ================================================================
 */

int H,W;
vector<pair<int,pii>> rect;
void init(){
    for(int h = 1; h < 500; h++){
        for(int w = h+1; w < 500; w++){
            rect.push_back({h*h+w*w,{h,w}});
        }
    }
    sort(rect.begin(),rect.end());
}
void solve(){
    pair<int,pii> info = {H*H+W*W,{H,W}};
    auto p = upper_bound(rect.begin(),rect.end(),info)->second;
    cout << p.first << " " << p.second << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init();
    while(cin >> H >> W,H){
        solve();
    }
    return 0;
}
