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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2253&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 移動経路がちょっと特殊なだけでBFSで解ける
 
 ================================================================
 */
int n,t;
map<pii,int> mp;
set<pii> s;

int dx[6] = {1,1,0,-1,-1,0};
int dy[6] = {0,1,1,0,-1,-1};
int solve(){
    mp.clear(); s.clear();
    int res = 0;
    for(int i = 0; i < n;i++){
        int x,y; cin >> x >> y;
        s.insert(make_pair(x,y));
    }
    int x,y; cin >> x >> y;
    using piii = pair<pii,int>;
    queue<piii> q; q.push({{x,y},1});
//    mp[make_pair(x,y)] = 1;
    while(q.size()){
        int T,X,Y; auto P = q.front(); q.pop();
        T = P.second; tie(X,Y) = P.first;
        if(mp[{X,Y}] == 0 || mp[{X,Y}] > T){
            mp[{X,Y}] = T;
        }else{
            continue;
        }
        if(T > t) continue;
        for(int k = 0; k < 6;k++){
            int nX = X + dx[k],nY = Y + dy[k];
            if(s.find({nX,nY}) != s.end()) continue;
            q.push({{nX,nY},T+1});
        }
    }
    res = (int)mp.size();
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> t >> n,t){
        cout << solve() << endl;
    }
    return 0;
}
