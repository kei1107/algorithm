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
 <url:https://yukicoder.me/problems/no/11>
 問題文============================================================
 JenはW×H枚のカードでトランプゲームをしている。
 Jenは(表面を見ることができる)手札にあるいずれかのカードと、
 手札以外にあるカードのマッチするカードの枚数を知りたくなった。
 
 このトランプは、マークがW種類あり、数字は1からHで構成されており、組み合わせの重複はないとする。
 ここでマッチするとは、マークまたは数字のどちらかが一致するカードのことである。
 
 今、手札にはN枚のカードがあり、「手札のカード以外」のマッチするカードの枚数を求めてください。
 
 W×H が 2^32 以上となる場合があります。
 =================================================================
 解説=============================================================
 
 手持ちのマークの数が w 種類、数字が h 種類であるとすると,
 全カード中、同じマークの個数は w*H 個
           同じ数字の個数は  h*W 個
 
 このうち重複する個数は w*h 個
 自分の手持ち分で N 個
 
 よって w*H - h*W - w*h - N が答え
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll W,H,N; cin >> W >> H >> N;
    vector<ll> S(N),K(N);
    vector<int> Wc(W+1,0),Hc(H+1,0);
    for(int i = 0; i < N;i++){
        cin >> S[i] >> K[i];
        Wc[S[i]] = true;
        Hc[K[i]] = true;
    }
    ll w = accumulate(Wc.begin(),Wc.end(),0LL);
    ll h = accumulate(Hc.begin(),Hc.end(),0LL);
    res = w*H + h*W - w*h - N;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
