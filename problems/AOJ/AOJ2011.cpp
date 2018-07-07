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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2011>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 i日目にj番の人がどの地図を取得しうるかどうかを保持しておき、
 ある一人が全ての地図を揃えうることができる状態があればその最もの早い日を出力する
 ================================================================
 */

int n;
ll solve(){
    ll res = -1;
    vector<vector<int>> schedule(31);
    for(int i = 0; i < n;i++){
        int f; cin >> f;
        for(int j = 0; j < f; j++){
            int d; cin >> d;
            schedule[d].push_back(i);
        }
    }
    
    vector<ll> maps(n);
    for(int i = 0; i < n;i++){
        maps[i] = (1LL<<i);
    }
    for(int i = 1; i <= 30; i++){
        int sz = (int)schedule[i].size();
        ll S = 0;
        for(int j = 0; j < sz;j++){
            S |= (maps[schedule[i][j]]);
        }
        for(int j = 0; j < sz;j++){
            maps[schedule[i][j]] |= S;
            if(maps[schedule[i][j]] == (1LL<<n)-1){
                res = i;
                break;
            }
        }
        if(res != -1) break;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n,n){
        cout << solve() << endl;
    }
    return 0;
}
