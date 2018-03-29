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
 <url:https://yukicoder.me/problems/no/5>
 問題文============================================================
 Ellenは数字のブロックで遊ぼうとしている。
 
 数字が書かれているブロックはそれぞれ高さ1で幅はWi である。
 （同じ幅のブロックが複数存在することがある。）
 
 それらのブロックを高さ1,幅Lの箱の中に入れる。
 
 Ellenは大きな箱にどれだけブロックがたくさん入るか気になったが。
 組み合わせがたくさんあって大変なことに気づいて、すぐに夜になってしまいそうである。
 
 あなたは、代わりに大きな箱に最大何個のブロックが入るかを求めてください。
 
 =================================================================
 解説=============================================================
 
 幅の小さい順に入れていくのが最適
 
 ================================================================
 */
ll solve(){
    ll res = 0;
    ll L,N; cin >> L >> N;
    vector<ll> W(N); for(auto& in:W) cin >> in;
    sort(W.begin(),W.end());
    
    ll sum = 0;
    for(int i = 0; i < N;i++){
        if(sum + W[i] <= L){
            sum += W[i];
            res++;
        }else{
            break;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
