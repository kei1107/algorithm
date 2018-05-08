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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2326>
 問題文============================================================
 
 A,B,Pが与えられる
 
 [A,B]の範囲に置いて、昇順かつ辞書順となるような空でない数列はいくつ存在するか？
 その総和のPの剰余を述べよ
 =================================================================
 解説=============================================================
 
 単純なdpだと
 dp[i] := A+iが数列の最後となる時の場合の数
 と言った感じで O(N^2)でできるが、間に合わない
 
 
 ここで考え方を変える
 ある数字を見ている時、自分よりも辞書順かつ数値的に小さいものから値をもらってきたくなる
 なんとなくBITでできそうである。
 
 よって、まず、数字を辞書順でsortしておいたあと、
 その辞書順の値を順番に見て行く、その値をxとしたとき
 [A,x]までで存在する値の総和 + 1
 をBITに詰めて行けば良い
 
 答えは [A,B]までの総和となる
 
 ================================================================
 */

/*
 1-index
 
 add : x に valを加算
 sum : [1,x] の総和を出力
 */
ll MOD;
struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        val %=MOD;
        while (x <= N) {
            (bit[x] += val)%=MOD;
            x += x & -x;
        }
    }
    
    ll sum(int x){
        ll ret = 0;
        while (x) {
            (ret += bit[x])%=MOD;
            x &= (x - 1);
        }
        return (ret);
    }
};
ll solve(ll A,ll B,ll P){
    ll res = 0;
    MOD = P;
    vector<string> S(B-A+1);
    for(ll x = A; x <= B;x++) S[x-A] = to_string(x);
    sort(S.begin(),S.end());
    BIT bit(B-A+2);
    for(int i = 0; i < S.size(); i++){
        ll x = atoll(S[i].c_str()) - (A-1);
        ll Sum = 0;
        if(x!=1) Sum = bit.sum(x-1);
        bit.add(x,Sum+1);
    }
    
    res = bit.sum(B-A+2);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll A,B,P;
    while(cin>>A>>B>>P,A|B|P){
        cout << solve(A,B,P) << endl;
    }
    return 0;
}
