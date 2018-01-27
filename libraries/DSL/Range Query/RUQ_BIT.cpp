#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

struct BIT {
    int N;
    vector<ll> bit1;
    vector<ll> bit2;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit1.resize(N + 1, 0);
        bit2.resize(N + 1, 0);
    }
    
    void add1(int x, int val){
        while (x <= N) {
            bit1[x] += val;
            x += x & -x;
        }
    }
    void add2(int x, int val){
        while (x <= N) {
            bit2[x] += val;
            x += x & -x;
        }
    }
    
    // [l,r]
    void RangeAdd(int l,int r,int val){
        // Update BIT1
        add1(l,val);
        add1(r+1,-val);
        
        // Update BIT2
        add2(l,val*(l-1));
        add2(r+1,-val*r);
    }
    
    int sum1(int x){
        int ret = 0;
        while (x) {
            ret += bit1[x];
            x &= (x - 1);
        }
        return (ret);
    }
    
    int sum2(int x){
        int ret = 0;
        while (x) {
            ret += bit2[x];
            x &= (x - 1);
        }
        return (ret);
    }
    
    int sum(int x){
        return sum1(x)*x - sum2(x);
    }
    // [l,r]
    int RangeSum(int l,int r){
        return sum(r) - sum(l-1);
    }
};
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    BIT bit(5);
    bit.RangeAdd(1,5,5);
    cout << bit.RangeSum(3,4) << endl;
    bit.RangeAdd(3,5,10);
    cout << bit.RangeSum(1, 5) << endl;
    cout << bit.RangeSum(2, 5) << endl;
    return 0;
}

// =============================
#define MAX_N 100050

ll bit0[MAX_N],bit1[MAX_N];
ll sum(ll *b,int i){
    int s = 0;
    while (i > 0) {
        s += b[i];
        i -= (i & -i);
    }
    return s;
}

void add(ll *b,int i,ll x){
    while (i <= MAX_N) {
        b[i] += x;
        i += (i & -i);
    }
}

//[0,n]
ll sum(int i){
    return sum(bit1, i)*i + sum(bit0, i);
}

//(l,r]
ll range_sum(int l,int r){
    return sum(r) - sum(l);
}

//[l,r]
void range_add(int l,int r,ll x){
    add(bit0, l, -x*(l-1));
    add(bit1, l,  x);
    add(bit0, r,  x*r);
    add(bit1, r, -x);
}