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
 <url:https://yukicoder.me/problems/no/673>
 問題文============================================================
 A君は毎年かならず1月1日にカブトムシをB匹買います。
 12月31日の大晦日に数を数えると1月1日にいた匹数からC倍に増えます。
 1年目の1月1日にB匹のカブトムシを買うと大晦日にB ×C匹です。
 2年目の1月1日にはB ×C+B匹になり大晦日に(B ×C+B) ×C匹になります。
 D年目の大晦日のカブトムシは何匹になっているか？
 
 ただし、答えは1000000007で割った余りを出力すること。
 
 入力
 B C D
 B、C、Dはすべて正の整数。
 1≤ B,C,D ≤1000000000000=10^12。
 =================================================================
 解説=============================================================
 
 計算すれば
 
 D年目の大晦日のカブトムシは
 Cが1であれば B*D
 Cが1でなければ B*(C + C^2 + .... + C^D)  (1)
 
 Cが1出ないときに関してのべる
 (1)は次のように変形できる
    B*(C+C^2+...+C^D) = B*C*(C^D-1)/(C-1)
 これは繰り返し二乗法とフェルマーの小定理で解ける
 
 
 ================================================================
 */

const ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}

ll solve(){
    ll res = 1;
    ll B,C,D; cin >> B >> C >> D;
    
    if(C == 1){
     //   B%=MOD; D%=MOD;
        B%=MOD; D%=MOD;
        (res = B*D)%=MOD;
        return res;
    }
    (res *= (C%MOD))%=MOD;
    (res *= (powmod(C%MOD,D)-1))%=MOD;
    (res *= (inversemod((C-1)%MOD)))%=MOD;
    B%=MOD;
    (res *= B)%=MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
