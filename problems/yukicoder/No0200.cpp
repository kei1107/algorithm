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
 <url:https://yukicoder.me/problems/no/200>
 問題文============================================================
 =================================================================
 解説=============================================================
 想定解はフローっぽいけど、貪欲法で解いた
 
 A君が勝てる組み合わせがある時、
    A君は勝てるうち最弱のカード、C君は負ける最強のカードを使う
 A君が勝てる組み合わせがない時、
    A君は最弱のカード、C君は最強のカードを使えば良い
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    ll A; cin >> A;
    vector<ll> B(A); for(auto&in:B) cin >> in;
    ll C; cin >> C;
    vector<ll> D(C); for(auto&in:D) cin >> in;
    sort(B.begin(),B.end()); sort(D.begin(),D.end());
    
    auto tB = B;
    auto tD = D;
    while(N--){
        if(tB.empty()) tB = B;
        if(tD.empty()) tD = D;
        
        
        bool update = false;
        ll c = tD.front();
        for(int i = 0; i < tB.size();i++){
            if(tB[i]>c){
                int j = 0;
                while(j!=tD.size()-1&&tB[i]>tD[j+1]) j++;
                res++;
                update = true;
                tB.erase(tB.begin()+i);
                tD.erase(tD.begin()+j);
                break;
            }
        }
        if(update) continue;
        
        tB.erase(tB.begin());
        tD.erase(tD.end()-1);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
