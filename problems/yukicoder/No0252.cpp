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
 <url:https://yukicoder.me/problems/no/252>
 問題文============================================================
 =================================================================
 解説=============================================================
 No150の答えを持ってきた。
 https://yukicoder.me/submissions/287200
 
 修正点として、
    最後の最小値を出す部分において、あらかじめ累積和を用意して高速化
    及び、ある要素を見たとき、それより前にproblemがいくつあるのかを用意して
    結果に盛り込んだ
 ================================================================
 */

ll solve(){
    ll res = LINF;
    string S; cin >> S;
    vector<ll> good(S.length()),problem(S.length());
    string sgood = "good",sproblem = "problem";
    for(int i = (int)sgood.length()-1; i < S.length();i++){
        int cnt = 0;
        int from = i - (int)(sgood.length() - 1);
        for(int j = 0; j < sgood.length();j++){
            if(sgood[j] == S[from+j]) cnt++;
        }
        good[i] = cnt;
    }
    for(int i = (int)sproblem.length()-1; i < S.length();i++){
        int cnt = 0;
        int from = i - (int)(sproblem.length() - 1);
        for(int j = 0; j < sproblem.length();j++){
            if(sproblem[j] == S[from+j]) cnt++;
        }
        problem[i] = cnt;
    }
    vector<ll> max_problem(S.length()+1);
    for(int i = (int)S.length()-1; i >= 0;i--){
        max_problem[i] = max(max_problem[i+1],problem[i]);
    }
    vector<ll> problem_num(S.length());
    for(int i = 1; i < S.length();i++){
        problem_num[i] = problem_num[i-1] + (problem[i]==7);
    }
    for(int i = (int)sgood.length()-1; i < S.length()-sproblem.length();i++){
        ll val =4-good[i]+7-max_problem[i+sproblem.length()] + problem_num[i];
        
        res = min(res,val);
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
