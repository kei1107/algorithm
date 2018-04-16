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
 <url:https://csacademy.com/contest/round-75/task/boaty-mcboatface/>
 問題文============================================================
 Boaty McBoatface started its travel to the East.
 The goal is to move DD kilometers to the East. The boat travels at a speed of V_1
 kilometers per hour. The East Wind just started and it'll last for another TT hours.
 The wind moves Boaty to the West with V_2 kilometers per hour.
 
 How many hours will take Boaty to reach its destination? Print this number rounded up.
 
 =================================================================
 解説=============================================================
 
 実際にシミュレーションするだけ
 
 ================================================================
 */

ll solve(){
    ll D,T,V1,V2; cin >> D >> T >> V1 >> V2;
    ll res = 0;
    
    ll difV = V1 - V2;
    if(difV*T >= D){
        res = (D + difV - 1)/difV;
        return res;
    }
    D = D - difV*T;
    res = (D + V1-1)/V1 + T;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
