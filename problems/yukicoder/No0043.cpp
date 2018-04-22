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
 <url:https://yukicoder.me/problems/no/43>
 問題文============================================================
 N個の野球チームがある。
 K君はその０番目のチームに所属している。
 すべてのチームが総当たりで試合をすることになった。
 総当たりではすべてのチームがそれぞれ１試合ずつ試合を行う。
 試合は勝ち負けが確定し引き分けは無いものとする。
 順位は勝ち数が多い順で１位から決定していく。
 勝ち数が同じであれば同じ順位のチームが複数のこともある。
 また、順位は１位から決定し数字が抜けることは無い。
 例えば１位が２チームでも次の順位は２位になる。
 １位が２チームであるから次の順位が３位になるということは無い。
 現在の勝ち負けの勝敗表が渡される。
 もし残りの試合があれば残りの試合について試合の勝ち負けのパターンを考慮する。
 K君の０番目のチームが最高で何位になりえるかを答えよ。
 =================================================================
 解説=============================================================
 
 未対決部分を全パターン埋めていって、
 最高何位になるかを計算すれば良い
 
 ================================================================
 */

ll check(ll N,vector<vector<char>>& s){
    vector<ll> x(N);
    for(int i = 0; i < N;i++){
        x[i] = count(s[i].begin(),s[i].end(),'o');
    }
    ll a = x[0];
    sort(x.begin(),x.end()); x.erase(unique(x.begin(),x.end()),x.end());
    return x.size() - (lower_bound(x.begin(),x.end(),a) - x.begin());
}
ll dfs(ll N,vector<vector<char>>& s){
    ll ret = INF;
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            if(s[i][j] == '-'){
                s[i][j] = 'o'; s[j][i] = 'x';
                ret = min(ret,dfs(N,s));
                s[i][j] = 'x'; s[j][i] = 'o';
                ret = min(ret,dfs(N,s));
                s[i][j] = s[j][i] = '-';
                return ret;
            }
        }
    }
    ret = check(N,s);
    return ret;
}
ll solve(){
    ll res = INF;
    ll N; cin >> N;
    vector<vector<char>> s(N,vector<char>(N));
    for(auto& array:s) for(auto& in:array) cin >> in;
    res = dfs(N,s);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
