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
 <url:https://yukicoder.me/problems/no/226>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dpと思ったけど、構築ゲーだった。
 
 一番上の行or一番下の行の数字を決めれば自ずと下or右の数字が決まる。
 よって、各行、各列に対して決めうちができる。
 
 注意点として一抹模様の時、余分に数えてしまうので、ここだけ処理する
 ================================================================
 */

const ll MOD = 1000000007;

ll calc(vector<vector<char>>& S){
    int H = (int)S.size();
    int W = (int)S[0].size();
    ll ret = 1;
    for(int i = 0; i < W;i++){
        ll ok = 0;
        for(int state = 0; state < 2;state++){
            if(S[0][i] == 0 && state == 1) continue;
            if(S[0][i] == 1 && state == 0) continue;
            [&]{
                int ng = state;
                for(int j = 1; j < H; j++){
                    if(S[j][i] == ng) return;
                    ng = !ng;
                }
                ok++;
            }();
        }
        (ret *= ok)%=MOD;
    }
    return ret;
}

ll itimatu(vector<vector<char>>& S){
    int H = (int)S.size();
    int W = (int)S[0].size();
    ll ret = 0;
    for(int state = 0; state < 2;state++){
        [&]{
            for(int i = 0; i < H;i++){
                for(int j = 0;j < W;j++){
                    if((i+j)%2==0){
                        if(S[i][j]==!state) return;
                    }else{
                        if(S[i][j]==state) return;
                    }
                }
            }
            ret++;
        }();
    }
    return ret;
}
ll solve(){
    ll res = 0;
    int H,W; cin >> H >> W;
    vector<vector<char>> S(H,vector<char>(W));
    for(auto& svec:S) for(auto& in:svec){ cin >> in; in -= '0';}
    (res += calc(S))%=MOD;
    auto rotateS = vector<vector<char>>(W,vector<char>(H));
    for(int h = 0; h < H;h++){
        for(int w = 0; w < W;w++){
            rotateS[w][h] = S[h][w];
        }
    }
    (res += calc(rotateS))%=MOD;
    (res += MOD-itimatu(S))%=MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
