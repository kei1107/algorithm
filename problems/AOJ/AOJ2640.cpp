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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2640>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 実際に移動ルートを確認して見ると、１パターンしか移動しようがないことがわかる。
 よって右手法のイメージで移動経路をシミュレートする。
 ここで元の場所＋元の向きに戻ってきた場合、Gに到達せずにループすることになる
 ================================================================
 */

ll solve(){
    ll res = 0;
    int N,M; cin >> N >> M;
    vector<vector<char>> masu(N+2,vector<char>(M+2,'#'));
    vector<vector<int>> flag(N+2,vector<int>(M+2,0));
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,-1,0,1};
    map<char,int> mp;
    mp['v'] = 0; mp['<'] = 1; mp['^'] = 2; mp['>'] = 3;
    pii S;
    int dir = 0;
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= M; j++){
            cin >> masu[i][j];
            if(mp.count(masu[i][j])){
                dir = mp[masu[i][j]];
                masu[i][j] = '.';
                S = {i,j};
            }
        }
    }
    int y = S.first, x = S.second;
    int from_dir = dir;
    bool f = false;
    while(true){
        if(y == S.first && x == S.second && dir == from_dir && f) return -1;
        f = true;
        flag[y][x] = 1;
        if(masu[y][x] == 'G') break;
        
        int migi = (dir+1)%4;
        int migiy = y + dy[migi],migix = x + dx[migi];
        int maey = y + dy[dir],maex = x + dx[dir];
        
        if(masu[migiy][migix] != '#'){
            dir = migi;
            y = migiy; x = migix;
        }else if(masu[maey][maex] != '#'){
            y = maey; x = maex;
        }else {
            dir = (dir +3)%4;
        }
    }
    for(auto vec:flag) res += accumulate(vec.begin(),vec.end(),0);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
