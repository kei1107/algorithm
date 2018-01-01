#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF (1<<30)
#define LINF (1LL<<60)

struct TwoDimBIT {
    int H,W;
    vector<vector<ll>> bit;
    TwoDimBIT(int H,int W):H(H),W(W) {
        /* BITは[1..H][1..W]で扱う */
        bit.assign(H+1,vector<ll>(W+1,0));
    }
    
    void add(int a,int b,int val)
    {
        for(int x = a; x<= H; x+= x & -x){
            for(int y = b; y<=W;y+=y&-y){
                bit[x][y] += val;
            }
        }
    }
    
    int sum(int a,int b)
    {
        int ret = 0;
        for(int x = a; x > 0; x-= x& -x){
            for(int y = b; y > 0; y-= y&-y){
                ret += bit[x][y];
            }
        }
        return (ret);
    }
};
