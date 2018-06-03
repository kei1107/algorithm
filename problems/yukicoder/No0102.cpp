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
 <url:https://yukicoder.me/problems/no/102>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 山から石を取って行くゲーム -> Nim
 
 今回の場合、問題の制約より、最後の石を取った方がかちなので
 すべての山のgrundy数(今回の場合は 山の数%n)のxorを取って0になるか否かで判定可能
 ================================================================
 */

string solve(){
    ll N1,N2,N3,N4; cin >> N1 >> N2 >> N3 >> N4;
    ll XOR = 0;
    XOR ^= (N1%4);
    XOR ^= (N2%4);
    XOR ^= (N3%4);
    XOR ^= (N4%4);
    if(!XOR){
        return "Jiro";
    }else{
        return "Taro";
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
