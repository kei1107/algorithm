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
 <url:https://yukicoder.me/problems/no/86>
 問題文============================================================
 yuki君は旅行先でテレビを見ようとした。
 旅行先のテレビのリモコンには、ボタンが縦N段、横M列の長方形状に計N×M個並んでおり、それぞれを押すとテレビの表示が対応するチャンネルに切り替わる。
 しかし、この地方のテレビでは視聴可能なチャンネルと視聴できないチャンネルとがあった。
 
 yuki君は視聴可能なチャンネルだけをすべて巡回したくなった。
 ただし、yuki君は旅行で疲れているので、複雑な順番でボタンを押したくない。
 そこで、yuki君は以下のルールで順にボタンを押す事を考えた。
 
 最初は任意の視聴可能なチャンネルのボタンを押すことができる。
 そして次に押すボタンを上下左右いずれかに隣接するボタンのうちから１つ選択する。
 
 以降、隣接するボタンを順に押していく。その際、次に押すボタンは、前と同じ向きに移動した先にあるボタンか、
 向きを左に90度回転した先にあるボタンのいずれかを選択する。
 （たとえば、今押したボタンが１つ前に押したボタンの上にある場合、次に押せるのはもう１つ上にあるボタンか、
 左にあるボタンのどちらかである。）
 
 視聴できないチャンネルのボタンは押してはならない。
 
 視聴可能なチャンネルのボタンを全てちょうど１回ずつ押し、最後に最初に押したボタンを押す。
 （例外として、最初に押したボタンだけは最後と合わせ２回押してよい）
 
 入力としてN, M, 各ボタンに対応するチャンネルの視聴可否が与えられたとき、
 上記ルールをすべて満たすボタンの押し順が存在するか答えよ。
 =================================================================
 解説=============================================================
 
 何回かシミュレーションすると、この問題は
    まっすぐ進めるようであれば進み続ける
    まっすぐ進めないのであればその時に左に曲がる
 しか全箇所を探索しうる動き方になりうるパターンが存在しないことがわかる。
 
 よって、全箇所から実際に動き始める方向を決めて探索すれば良い
 (操作パターンを簡単にしたことによって、移動経路パターンはかなり減っているため通る)
 ================================================================
 */

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

void dfs(pii p,int dir,int dep,vector<vector<int>>& visited,vector<vector<char>>& masu,const pii& from,const int& cnt,bool& ok){
    if(dep == cnt-1){
        for(int i = 0; i <= 1; i++){
            int ny = p.first + dy[(dir+i)%4], nx = p.second + dx[(dir+i)%4];
            if(from == pii(ny,nx)) ok = true;
        }
        return;
    }
    visited[p.first][p.second] = 1;
    for(int i = 0; i <= 1;i++){
        int ny = p.first + dy[(dir+i)%4], nx = p.second + dx[(dir+i)%4];
        if(visited[ny][nx] == 1) continue;
        if(masu[ny][nx] == '#') continue;
        
        dfs({ny,nx},(dir+i)%4,dep+1,visited,masu,from,cnt,ok);
        break;
    }
    visited[p.first][p.second] = 0;
    return;
}
string solve(){
    ll N,M; cin >> N >> M;
    vector<vector<char>> masu(N+2,vector<char>(M+2,'#'));
    
    int cnt = 0;
    for(int i = 1; i <= N;i++) for(int j = 1; j <= M;j++){
        cin >> masu[i][j];
        if(masu[i][j] == '.') cnt++;
    }
    
    bool ok = false;
    vector<vector<int>> visited(N+2,vector<int>(M+2,0));
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= M;j++){
            if(masu[i][j] == '#') continue;
            for(int k = 0; k < 4;k++){
                pii from = {i,j};
                dfs({i,j},k,0,visited,masu,{i,j},cnt,ok);
                if(ok) return "YES";
            }
        }
    }
    
    return "NO";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
