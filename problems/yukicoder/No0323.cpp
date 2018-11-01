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
 <url:https://yukicoder.me/problems/no/323>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 can_visit[x][y][sz] := 座標(x,y)に雪玉のサイズがszで到達可能か
 で拡張ダイクストラしてやればいい szは最大でも2000ぐらいにしてやれば十分
 ================================================================
 */

bool can_visit[50][50][2000];
string solve(){
    int H,W; cin >> H >> W;
    int A,B; pii S,G;
    cin >> A >> S.first >> S.second;
    cin >> B >> G.first >> G.second;
    vector<vector<char>> masu(H,vector<char>(W));
    for(auto& vec:masu) for(auto& in:vec) cin >> in;
    
    using Item = tuple<int,int,int>;
    queue<Item> q; q.push(Item(S.first,S.second,A));
    int d[4] = {1,0,-1,0};
    while(q.size()){
        int h,w,sz; tie(h,w,sz) = q.front(); q.pop();
        if(sz <= 0 || sz >= 2000) continue;
        if(can_visit[h][w][sz]) continue;
        can_visit[h][w][sz] = true;
        for(int k = 0; k < 4;k++){
            int nh = h + d[k];
            int nw = w + d[k^1];
            if(nh < 0 || nw < 0 || nh >= H || nw >= W) continue;
            int cost = (masu[nh][nw] == '*')?1:-1;
            q.push(Item(nh,nw,sz+cost));
        }
    }
    if(can_visit[G.first][G.second][B]) return "Yes";
    else return "No";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
