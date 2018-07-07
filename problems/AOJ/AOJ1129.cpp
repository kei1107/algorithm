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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1129&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 制約が小さいので愚直で間に合う
 ================================================================
 */

int n,r;

ll solve(){
    vector<int> s(n);
    iota(s.begin(),s.end(),1); reverse(s.begin(), s.end());
    for(int i = 0; i < r;i++){
        int a,b; cin >> a >> b; a--;
        vector<int> s1(s.begin()+a,s.begin()+a+b),s2(s.begin(),s.begin()+a),s3(s.begin()+a+b,s.end());
        s.clear();
        for(auto v:s1) s.push_back(v);
        for(auto v:s2) s.push_back(v);
        for(auto v:s3) s.push_back(v);
    }
    return *s.begin();
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n >> r,n|r){
        cout << solve() << endl;
    }
    return 0;
}
