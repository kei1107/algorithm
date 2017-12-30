#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:>
 問題文============================================================
 
 =================================================================
 
 解説=============================================================
 座標圧縮＋二次元imos
 ================================================================
 */

/* Coordinate_Compression : 座標圧縮*/
class CC {
public:
    ll N;
    vector<ll> xs; // 復元用:xs[x1 or x2の添え字] := 元の座標
    
    CC(ll N) :N(N) {}
    // x1, x2を座標圧縮し, 座標圧縮した際の幅を返す
    int compress(vector<ll>& x1, vector<ll>& x2, ll MIN_W = -1e10, ll MAX_W = 1e10) {
        for (int i = 0; i < N;i++) {
            ll tx1 = x1[i], tx2 = x2[i];
            if (MIN_W <= tx1 && tx1 <= MAX_W) xs.push_back(tx1);
            if (MIN_W <= tx2 && tx2 <= MAX_W) xs.push_back(tx2);
        }
        
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        
        for (int i = 0; i < N;i++) {
            x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
            x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
        }
        
        return (int)xs.size(); // xs.sizeは最大でも6*N
    }
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int y,int x,vector<vector<int>>& masu,int H,int W){
    masu[y][x] = 1;
    for(int i = 0; i < 4;i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny >= 0 && ny < H && nx >= 0 && nx < W && masu[ny][nx] == 0) dfs(ny,nx,masu,H,W);
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll w,h;
    while(cin >> w >> h){
        if(w == 0 && h == 0) break;
        
        ll N; cin >> N;
        vector<ll> x1(N+1), y1(N+1), x2(N+1), y2(N+1);
        x1[N] = 0; y1[N] = 0; x2[N] = w; y2[N] = h;
        for (int i = 0; i < N;i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        CC CCx(N+1), CCy(N+1);
        ll W = CCx.compress(x1, x2, 0, w);
        ll H = CCy.compress(y1, y2, 0, h);
        
        vector<vector<int>> masu(H-1,vector<int>(W-1,0));
        for(int i = 0; i < N;i++){
            for(int j = x1[i]; j < x2[i];j++){
                for(int k = y1[i]; k < y2[i];k++){
                    masu[k][j] = 1;
                }
            }
        }
        
        // visualize
        /*
        for(int i = 0; i < H-1;i++){
            for(int j = 0; j < W-1;j++){
                cout << masu[i][j] << " " ;
            }
            cout << endl;
         }
         */
        
        ll ans = 0;
        for(int i = 0; i < H -1;i++){
            for(int j = 0; j < W-1;j++){
                if(masu[i][j] == 1)continue;
                dfs(i,j,masu,H-1,W-1);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
