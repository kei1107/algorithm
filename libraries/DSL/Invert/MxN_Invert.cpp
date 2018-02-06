#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF (1<<30)
#define LINF (1LL<<60)

// ============================================== //

const int dx[5] = {-1,0,0,0,1};
const int dy[5] = {0,-1,0,1,0};

const int H = 5;
const int W = 6;
int tile[H][W];
int opt[H][W];
int flip[H][W];

int get(int x,int y){
    int c = tile[x][y];
    for(int d = 0; d < 5;d++){
        int x2 = x + dx[d],y2 = y + dy[d];
        if(0 <= x2 && x2 < H && 0 <= y2 && y2 < W){
            c += flip[x2][y2];
        }
    }
    return c%2;
}

int calc(){
    for(int i = 1; i < H;i++){
        for(int j = 0; j < W;j++){
            if(get(i-1,j) != 0){
                flip[i][j] = 1;
            }
        }
    }
    
    for(int j = 0; j < W;j++){
        if(get(H-1,j)!=0){
            return -1;
        }
    }
    
    int res = 0;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            res += flip[i][j];
        }
    }
    return res;
}

void solve(int x){
    int res = -1;

    for(int i = 0; i < (1<<W);i++){
        memset(flip,0,sizeof(flip));
        for(int j = 0; j < W;j++){
            flip[0][W-j-1] = i >> j & 1;
        }
        int num = calc();
        if(num >= 0 && (res < 0 || res > num)){
            res = num;
            memcpy(opt,flip,sizeof(flip));
        }
    }
    
    if(res < 0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << "PUZZLE #" << x << endl;
        for(int i = 0; i < H;i++){
            for(int j = 0; j < W;j++){
                cout << opt[i][j];
                if(j + 1 != W) cout << " ";
            }
            cout << endl;
        }
    }
}

// ================================================ //


// Verify : http://poj.org/problem?id=1222
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int Case; cin >> Case;
    for(int i = 1; i <= Case;i++){
        for(int i = 0; i < H;i++){
            for(int j = 0; j < W;j++){
                cin >> tile[i][j];
            }
        }
        solve(i);
    }
	return 0;
}
