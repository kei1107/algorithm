#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

// 平方分割＋2dBIT

// example : <https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3141>

const ll MAX_N = 200010;
const ll MAX_M = 100010;
const ll BatchSize = 450; // 450*450 = 200250
const ll H = MAX_N/BatchSize+1;
const ll W = MAX_N/BatchSize+1;
ll n,m;
ll a[MAX_N];
ll b[MAX_M];

ll xv[MAX_N];
ll yv[MAX_N];
ll bit[H+1][W+1];
void init(){
    memset(bit,0,sizeof(bit));
    memset(xv,0,sizeof(xv));
    memset(yv,0,sizeof(yv));
}

void add(ll a,ll b,ll val){
    for(ll x = a; x<=H; x+= x&-x){
        for(ll y = b; y<=W;y+=y&-y){
            bit[x][y] += val;
        }
    }
}
ll Sum(ll a,ll b){
    ll ret = 0;
    for(ll x = a; x > 0; x-= x& -x){
        for(ll y = b; y > 0; y-= y&-y){
            ret += bit[x][y];
        }
    }
    return (ret);
}

// (1,1) - (x,y)間の点個数計算
ll BatchSum(ll x,ll y){
    ll batch_x = x/BatchSize+1, batch_y = y/BatchSize+1;
    ll res = 0;

    // Batchでまとめて計算できる部分をBITにて計算
    if(batch_x != 1 && batch_y != 1) res += Sum(batch_x-1,batch_y-1);
    
    // Batchにてまとめれない部分を貪欲計算
    for(ll i = (batch_x-1)*BatchSize; i < x;i++){
        if(yv[i] == 0)continue;
        if(yv[i] < y){
            res++;
        }
    }
    for(ll i = (batch_y-1)*BatchSize; i < y;i++){
        if(xv[i] == 0)continue;
        if(xv[i] < BatchSize*(batch_x-1)){
            res++;
        }
    }
    return res;
}

// (x,y)の左上＋右下区間の点個数の取得
ll calc(ll x,ll y){
    ll res = 0;
    ll s1 = BatchSum(x,n+1), s2 = BatchSum(n+1,y), s3 = BatchSum(x,y);
    res = s1 + s2 - 2*s3;
    return res;
}

// Batch単位での点情報の更新
void update(ll x,ll y,ll val){
    ll batch_x = x/BatchSize + 1;
    ll batch_y = y/BatchSize + 1;
    if(val == 1){ yv[x] = y; xv[y] = x; }
    else{ yv[x] = 0; xv[y] = 0; }
    add(batch_x,batch_y,val);
}

void solve(){
    ll ans = 0;
    for(int i = 1; i <= n;i++){
        ans += calc(i,a[i]);
        update(i,a[i],1);
    }
    for(int i = 1; i <= m;i++){
        cout << ans << endl;
        ans -= calc(xv[b[i]],b[i]);
        update(xv[b[i]],b[i],-1);
    }
}

int main(void) {
    while(cin >> n >> m){
        init();
        for(int i = 1; i <= n;i++) scanf("%lld",&a[i]);
        for(int i = 1; i <= m;i++) scanf("%lld",&b[i]);
        solve();
    }
    return 0;
}
