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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day3/problems/A>
 問題文============================================================
 =================================================================
 解説=============================================================
 全探索
 ================================================================
 */

ll ans = 0;

bool check(string S){
    ll now = 0;
    ll cnt = 0;
    for(int i = 0; i < S.length();i++){
        if(S[i] == '.'){
            if(now < 0 || now > 255) return false;
            if(now == 0 && cnt == 0) return false;
            if(now == 0 && cnt >= 2) return false;
            now = 0;
            cnt = 0;
        }else{
            if(now == 0 && cnt == 1) return false;
            now = now*10 + S[i] - '0';
            cnt++;
        }
    }
  //  cout << S << endl;
    return true;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    string S; cin >> S;
    ll ans = 0;
    for(int i = 1; i < S.length(); i++){
        for(int j = i; j < S.length(); j++){
            for(int k = j; k < S.length(); k++){
                string T = S;
                T.insert(k,".");
                T.insert(j, ".");
                T.insert(i, ".");
         //       cout << T << endl;
                T += ".";
                ans += check(T);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
