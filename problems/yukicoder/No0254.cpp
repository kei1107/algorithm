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
 <url:https://yukicoder.me/problems/no/254>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 隣接した文字が相異なるものを並べなければならないが
 回文を作りたいので結局
 
 ababababab....
 みたいにすれば条件を満たす。
 
 ここで↑のような回文を作ったときaの個数、bの個数を cnta,cntbとしたとき (cnta < cntb かつ (cntb-cnta) <= 1)
 回文の個数
    C(cnta,2) + cnta  +  C(cntb,2) + cntb
 となる。
 よって、Nを超えないギリギリのcntaとcntbを選んで
 あとは、足りない分を1単語しか回文しか作らない文字列で埋めればいい
 ex.cdecdecde...
 ================================================================
 */

string solve(){
    const ll MAXS = 1e5+1;
    vector<ll> cnt(MAXS,0);
    for(ll i = 1; i < MAXS;i++){
        cnt[i] = i + i*(i-1)/2;
    }
    string res;
    ll N; cin >> N;
    ll l = 0;
    while(cnt[l+1] + cnt[l+2] <= N) l++;
    ll r = l+1;
    if(2*cnt[l+1] <= N) l++;
    for(int i = 0; i < l;i++){
        res += "ab";
    }
    if(l!=r)res += "a";
    N -= cnt[l]+cnt[r];
    while(N!=0){
        if(N%3==0){
            res += "c";
        }
        if(N%3==1){
            res += "d";
        }
        if(N%3==2){
            res += "e";
        }
        N--;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
