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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1165&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

int N;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
void solve(){
    vector<pll> box(N);
    for(int i = 1; i < N;i++){
        int n,d; cin >> n >> d;
        box[i] = {box[n].first+dy[d],box[n].second+dx[d]};
    }
    
    //cout << box << endl;
    auto H = minmax_element(box.begin(),box.end(),[](const pll& c1,const pll& c2){return c1.first < c2.first;});
    auto W = minmax_element(box.begin(),box.end(),[](const pll& c1,const pll& c2){return c1.second < c2.second;});
    cout << W.second->second - W.first->second + 1 << " " << H.second->first - H.first->first + 1 << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N,N){
        solve();
    }
    return 0;
}
