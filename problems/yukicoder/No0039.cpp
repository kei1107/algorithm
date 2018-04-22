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
 <url:https://yukicoder.me/problems/no/39>
 問題文============================================================
 2桁以上9桁以下の数字Nが与えられる。
 数字Nはいずれの桁にも数字の0を含まない。
 どの桁の数字も1から9の数字で構成される。
 いま、2つの桁の数字を自由に選んで、
 1回だけ入れ替えることが許される。
 入れ替えないという選択もできる。
 最も大きな数字を作ろうとするとき、
 その最も大きな数字はいくつか？
 =================================================================
 解説=============================================================
 各桁入れ替えの全探索
 ================================================================
 */

string solve(){
    string res = "";
    string N; cin >> N;
    res = max(res,N);
    for(int i = 0; i< N.length();i++){
        for(int j = i+1;j < N.length();j++){
            swap(N[i],N[j]);
            res = max(res,N);
            swap(N[i],N[j]);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
