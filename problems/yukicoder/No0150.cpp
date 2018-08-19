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
 <url:https://yukicoder.me/problems/no/150>
 問題文============================================================
 =================================================================
 解説=============================================================
 適当に境界を決めて
 その境界よりも左側でgoodを作るときの最小操作回数
 その境界よりも右側でproblemを作るときの最小操作回数
 を求めればいい
 
 このとき事前にある要素iをみたとき、その直近の文字とgood,problemとのハミング距離を
 求めておけば良い
 ================================================================
 */
ll solve(){
    ll res = LINF;
    string S; cin>> S;
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
    
//    cout << good << endl;
//    cout << problem << endl;

    for(int i = (int)sgood.length()-1; i < S.length()-sproblem.length();i++){
        ll maxv = 0;
        for(int j = i + (int)sproblem.length(); j < S.length();j++){
            maxv = max(maxv,problem[j]);
        }
        res = min(res,4-good[i]+7-maxv);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll T; cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
