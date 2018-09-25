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
 <url:https://yukicoder.me/problems/no/234>
 問題文============================================================
 =================================================================
 解説=============================================================
 https://oeis.org/search?q=1%2C11+128967&sort=&language=&go=Search
 
 OEIS先輩さすがっす。まじパネェーっす
 ================================================================
 */
//https://oeis.org/search?q=1%2C11+128967&sort=&language=&go=Search
string solve(){
    string res;
    int N; cin >> N;
    vector<string> ans ={
        "1",
        "11",
        "110",
        "2402",
        "128967",
        "16767653",
        "5436906668",
        "4406952731948",
        "8819634719356421",
        "43329348004927734247",
        "522235268182347360718818",
        "15436131339319739257518081878"};
    res = ans[N-1];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
