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
 <url:https://yukicoder.me/problems/no/161>
 問題文============================================================
 =================================================================
 解説=============================================================
 優先度的に、勝てる勝負には手が出せるなら勝ちたい
 その次に引き分けれる勝負にはできるだけ引き分けたい
 
 こうすると、まず相手の出す手に対して勝てる手が１通りなので貪欲に見ていく
 次に引き分ける手も１通りなので貪欲に見ていけば良い
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll G,C,P; cin >> G >> C >> P;
    string S; cin >> S;
    vector<int> flag(S.length());
    for(int i = 0; i < S.length();i++){
        if(flag[i])continue;
        if(S[i] == 'C'){
            if(G){
                G--;
                res+=3;
                flag[i] = true;
            }
        }
        if(S[i] == 'G'){
            if(P){
                P--;
                res+=3;
                flag[i] = true;
            }
        }
        if(S[i] == 'P'){
            if(C){
                C--;
                res+=3;
                flag[i] = true;
            }
        }
    }
    for(int i = 0; i < S.length();i++){
        if(flag[i])continue;
        if(S[i] == 'C'){
            if(C){
                C--;
                res++;
                flag[i] = true;
            }
        }
        if(S[i] == 'G'){
            if(G){
                G--;
                res++;
                flag[i] = true;
            }
        }
        if(S[i] == 'P'){
            if(P){
                P--;
                res++;
                flag[i] = true;
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
