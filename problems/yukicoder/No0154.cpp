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
 <url:https://yukicoder.me/problems/no/154>
 問題文============================================================
 =================================================================
 解説=============================================================
 チョチョっと書いて通ると思ったら通らなくて焦った。
 
 とりあえずw(-w-w-...)-g-rを一気に判定するのは面倒そう
 けど g-rの判定 wを無視してstackとか使えば楽に判定可能
 
 この判定が通れば、少なくとも g-rの順序は守られたならびになっている
 よって、あとは順番に
 gの前にwが少なくとも1個以上存在するか
 最後のg-rペアのg以降にwが出ないかなどをチェックすれば良い
 ================================================================
 */

string solve(){
    string S; cin >> S;
    if(S.length() < 3) return "impossible";
    stack<char> st;
    for(auto c:S){
        if(c == 'W') continue;
        if(c == 'G') st.push(c);
        if(c == 'R'){
            if(st.empty()) return "impossible";
            st.pop();
        }
    }
    if(!st.empty()) return "impossible";
    
    size_t run_bas = count(S.begin(),S.end(),'R');
    size_t last_bas = 0;
    size_t w_bas = 0;
    for(auto c:S){
        if(c == 'W'){
            if(run_bas-last_bas == 0) return "impossible";
            w_bas++;
        }
        if(c == 'G'){
            if(!w_bas) return "impossible";
            w_bas--;
            last_bas++;
        }
        if(c == 'R'){
            run_bas--;
            last_bas--;
        }
    }
    
    return "possible";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
