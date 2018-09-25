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
 <url:https://yukicoder.me/problems/no/153>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 grundy数　やるだけ
 ================================================================
 */

string solve(){
    int N; cin >> N;
    
    vector<int> grundy(N+1);
    grundy[1] = 0;
    for(int i = 2; i <= N;i++){
        set<int> s;
        s.insert(grundy[i/2]^grundy[(i+1)/2]);
        if(i>=3) s.insert(grundy[i/3]^grundy[(i+1)/3]^grundy[(i+2)/3]);
        while(s.count(grundy[i])) grundy[i]++;
    }
    if(grundy[N]) return "A";
    else return "B";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
