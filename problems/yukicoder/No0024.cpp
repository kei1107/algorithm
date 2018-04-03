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
 <url:https://yukicoder.me/problems/no/24>
 問題文============================================================
 太郎君と二郎君はゲームをしています。
 
 まず最初に二郎君は 0から9までの数字を1つ、心の中で思い浮かべます。
 
 太郎君は、重複しないような0から9までの数字から 4つ 二郎君に提示し、
 二郎君は心の中で思い浮かべた数字が、提示された4つの数字の中にあれば YES 、
 無ければ NO と答えます。
 これを1ターンとし、次のターンにまた太郎君は4つの数字を提示することを繰り返します。
 前に出した数字と同じ数字を提示しても構いません。
 
 入力に太郎君が提示した数字と、二郎君の答えが与えられるので、
 二郎君が思い浮かべたであろう数字を出力してください。
 必ず出力する数字が1つと確定できるような入力が与えられます。

 =================================================================
 解説=============================================================
 
 愚直シミュレーション
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> A(N),B(N),C(N),D(N);
    vector<string> R(N);
    vector<int> F(10,0);
    for(int i = 0; i < N;i++) cin >> A[i] >> B[i] >> C[i] >> D[i] >> R[i];
    for(int i = 0; i < N;i++){
        if(R[i] == "NO"){
            F[A[i]] = F[B[i]] = F[C[i]] = F[D[i]] = -INF;
        }else{
            F[A[i]]++;
            F[B[i]]++;
            F[C[i]]++;
            F[D[i]]++;
        }
    }
    return res = max_element(F.begin(), F.end()) - F.begin();
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
