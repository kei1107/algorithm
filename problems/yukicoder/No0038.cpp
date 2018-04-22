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
 <url:https://yukicoder.me/problems/no/38>
 問題文============================================================
 赤と青と白のブロックが各１０個ずつある。
 ブロックは左から右に一列に並べられている。
 並べるときには次のような決まりがある。
 
 赤いブロックよりちょうどKr個左に赤いブロックがあってはならない。
 赤いブロックよりちょうどKr個右に赤いブロックがあってはならない。
 青いブロックよりちょうどKb個左に青いブロックがあってはならない。
 青いブロックよりちょうどKb個右に青いブロックがあってはならない。
 白いブロックについては特に制限は無い。
 
 最初にKr、Kbの数値とブロックの並びが与えられる。
 赤のブロックをR、青のブロックをB、白のブロックをWとする。
 最初の状態は上記に示した条件を満たしていないかもしれない。
 よって、操作として次のような操作が許される。
 
 ・赤か青のブロックをいくつか抜いて列の間を詰める。
 
 例えば、「RWBRWWB」であれば、
 左端のRだけ抜いて「WBRWWB」という列を作ることができる。
 左から4つめのRと右端のBを抜いて「RWBWW」という列も作れる。
 RとBはいくつでも選んで抜くことができる。
 ただし、Wのブロックを抜くことはできない。
 このような操作を行うことで条件を満たす最長の列を残したい。
 どのようにRとBのブロックを抜くかは自由である。
 残すことが可能な最長の列の長さはどれだけか？
 
 
 =================================================================
 解説=============================================================
 ================================================================
 */

ll solve(){
    ll Kr,Kb; cin >> Kr >> Kb;
    string S; cin >> S;
    ll res = 0;
    for(int i = 0; i < (1<<10);i++){
        for(int j = 0; j < (1<<10);j++){
            int r = 0, b = 0;
            string s = "";
            for(int k = 0; k < 30;k++){
                if(S[k] == 'W') s += 'W';
                else if(S[k] == 'R'){
                    if((i>>r)&1) s+='R';
                    r++;
                }else if(S[k] =='B'){
                    if((j>>b)&1) s+='B';
                    b++;
                }
            }
            [&]{
                for(int k = 0; k < s.length();k++){
                    if(s[k] == 'W') continue;
                    if(s[k] == 'R'){
                        if(k + Kr < s.length()){
                            if(s[k+Kr] == 'R') return;
                        }
                    }
                    if(s[k] == 'B'){
                        if(k + Kb < s.length()){
                            if(s[k+Kb] == 'B') return;
                        }
                    }
                }
                res = max(res,(ll)s.length());
            }();
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
