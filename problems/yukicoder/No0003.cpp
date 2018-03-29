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
 <url:https://yukicoder.me/problems/no/3>
 問題文============================================================
 Carol は特殊なすごろくをしようとしている。
 
 1からNの番号がふられている一直線に並べられているN個のマスがある。
 1から開始のマスとして、ゴールはNが書かれているマスとする。
 
 その場に書かれている数字の2進数で表現した時の1のビット数 だけ「前」または「後」に進めることができる。
 (1未満とN+1以上のマスには移動することは出来ない、正確にNにならないとゴールできない）
 
 自然数Nを与えられた時、ゴールに到達できる最短の移動数（開始のマスへも移動にカウントする）を求めてください。
 到達できない場合は-1を出力してください。
 
 開始のマスがすでにゴールになっている場合もあリます。

 =================================================================
 解説=============================================================
 
 dijkstra やるだけ
 ================================================================
 */
int solve(){
    int res = 0;
    int N; cin >> N;
    vector<int> D(N+1,INF);
    queue<int> q;
    D[1] = 1; q.push(1);
    while(q.size()){
        int n = q.front(); q.pop();
        
        int cnt = __builtin_popcount(n);
        if(n > cnt){
            if(D[n-cnt] > D[n] + 1){
                D[n-cnt] = D[n]+1; q.push(n-cnt);
            }
        }
        if(n+cnt <= N){
            if(D[n+cnt] > D[n] + 1){
                D[n+cnt] = D[n] + 1; q.push(n+cnt);
            }
        }
    }
    res = D[N];
    return res==INF?-1:res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
