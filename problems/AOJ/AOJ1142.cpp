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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1142&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 全通り、実際に試してその個数を数え上げれば良い
 ================================================================
 */
ll solve(){
    ll res = 0;
    string S; cin >> S;
    set<string> trains;
    for(int i = 0; i <= S.length();i++){
        string sub1 = S.substr(0,i),sub2 = S.substr(i);
        trains.insert(sub1+sub2); trains.insert(sub2+sub1);
        reverse(sub1.begin(),sub1.end());
        trains.insert(sub1+sub2); trains.insert(sub2+sub1);
        reverse(sub2.begin(),sub2.end());
        trains.insert(sub1+sub2); trains.insert(sub2+sub1);
        reverse(sub1.begin(),sub1.end());
        trains.insert(sub1+sub2); trains.insert(sub2+sub1);
    }
    return res = trains.size();
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
