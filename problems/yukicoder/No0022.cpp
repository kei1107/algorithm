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
 <url:https://yukicoder.me/problems/no/22>
 問題文============================================================
 Orinoは、テキストの括弧の対応箇所を見つけるプログラムを書きたいと思っている。
 
 括弧の対応とは、
 
 1.与えられた文字列から、「(」の直後に「)」が来る文字があるとき、文字列からその２つの文字を削除する。
 2.削除された文字を新たな文字列として、1.の処理を繰り返し、文字列が空になるまで繰り返す。
 
 そして、初めに与えられた文字列として考えた時のi番目文字と一緒に削除されるj番目に対応する文字が「括弧の対応」であるとする。
 
 「(」と「)」のみで構成されるN文字の文字列が与えられ、
 さらに整数値K (1≤K≤N)が与えられる。
 
 このとき、K番目の文字と対応する文字の箇所の番目を求めてください。
 
 
 与えられる文字列は、すべての文字で括弧の対応があると保証されるとする。
 =================================================================
 解説=============================================================
 こういった、左右で対応付けられるようなものはstackで実装すると楽
 ================================================================
 */
ll solve(){
    ll res = 0;
    int N,K; cin >> N >> K;
    K--;
    string S; cin >> S;
    stack<int> st;
    for(int i = 0; i < N;i++){
        if(S[i] == '('){
            st.push(i);
        }else{
            if(i == K){
                return st.top()+1;
            }
            if(st.top() == K){
                return i+1;
            }
            st.pop();
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
