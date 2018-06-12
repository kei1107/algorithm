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
 <url:https://beta.atcoder.jp/contests/arc081/tasks/arc081_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 解説を見た。頭が足りない。。
 <https://atcoder.jp/img/arc081/editorial.pdf>
 
 実装時の注意点としては、格子点での処理となる為、
 ヒストグラムの　height * width の widthが実装によって ±1されることに注意
 
 自分は実装より width = r - l とした時 lが0でなければ +1 するようにした
 ================================================================
 */

struct Rectangle {
    ll h;
    ll p;  // position from left
};
ll max_area_of_histgram(ll n, vector<ll>& height) {
    stack<Rectangle> S;
    ll maxv = 0;
    
    for (int i = 0; i <= n; i++) {
        Rectangle rect;
        rect.h = height[i];
        rect.p = i;
        
        if (S.empty()) {
            S.push(rect);
        }
        else if (S.top().h < rect.h) {
            S.push(rect);
        }
        else if (S.top().h > rect.h) {
            ll now = i;
            while ((!S.empty()) && (S.top().h >= rect.h)) {
                Rectangle pre = S.top(); S.pop();
                // 格子点での処理であり、自分は格子点の左下を1としているので pre.pが0でなければ 範囲+1できる
                ll area = 1LL * pre.h * (i - pre.p + (pre.p != 0));
                maxv = max(maxv, area);
                now = pre.p;
            }
            rect.p = now;
            S.push(rect);
        }
    }
    return maxv;
}

ll calc(vector<vector<char>>& S){
    ll ret = 0;
    int H = (int)S.size(), W = (int)S[0].size();
    vector<ll> height(H+1,0);
    for(int j = W-1; j >= 0; j--){
        for(int i = 0; i < H; i++){
            if(j == W-1){
                height[i] = 1;
                continue;
            }
            if(i == 0) height[i]++;
            else{
                int cnt = 0;
                for(int k = -1; k < 1; k++) for(int l = 0; l < 2;l++) cnt += (S[i+k][j+l]=='#');
                if(cnt&1){
                    height[i] = 1;
                }else{
                    height[i]++;
                }
            }
        }
        ret = max(ret,max_area_of_histgram(H, height));
    }
    return ret;
}
ll solve(){
    ll res = 0;
    ll H,W; cin >> H >> W;
    vector<vector<char>> S(H,vector<char>(W));
    for(auto& vec:S) for(auto& in:vec) cin >> in;
    res = max({H,W,calc(S)});
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
