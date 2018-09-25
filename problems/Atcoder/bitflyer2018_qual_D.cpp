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
 <url:https://beta.atcoder.jp/contests/bitflyer2018-qual/tasks/bitflyer2018_qual_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 ハンコのマス(i,j)が黒であれば、
 左上を(i,j)、右下を(H-(N-i),W-(M-j))とする領域が黒く塗られる。
 よって、ほぼ全ての領域が黒く塗られるため、見るべき領域は
 [1-N],[H-N+1,H],[1-M],[W-M+1,W]の領域だけでよく求まる。
 ================================================================
 */

ll sum[2005][2005];
ll solve(){
    ll res = 0;
    ll H,W; cin >> H >> W;
    ll N,M; cin >> N >> M;
    vector<string> A(N); for(auto& in:A) cin >> in;
    
    ll Y = min(2*N-1,H),X = min(2*M-1,W);
    
    bool f1 = false,f2 = false;
    if(2*N-1<H) f1 = true;
    if(2*M-1<W) f2 = true;
    
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= M;j++){
            if(A[i-1][j-1]=='#'){
                sum[i][j]++;
                sum[i+Y-N+1][j+X-M+1]++;
                sum[i+Y-N+1][j]--;
                sum[i][j+X-M+1]--;
            }
        }
    }
    for(int i = 1; i <= 2*N+2;i++){
        for(int j = 1; j <= 2*M+2;j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    for(int j = 1; j <= 2*M+2;j++){
        for(int i = 1; i <= 2*N+2;i++){
            sum[i][j] += sum[i-1][j];
        }
    }
    
    for(int i = 1; i <= Y;i++){
        for(int j = 1; j <= X;j++){
            if(sum[i][j]==0) continue;
            ll add = 1;
            if(f1&&i==N) add*= (H-2*(N-1));
            if(f2&&j==M) add*= (W-2*(M-1));
            res += add;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
