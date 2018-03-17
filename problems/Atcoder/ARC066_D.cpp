#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc066.contest.atcoder.jp/tasks/arc066_b>
問題文============================================================
正の整数 N が与えられます。
 2 つの整数 u,v(0≦u,v≦N) であって、ある非負整数 a,b が存在して、a xor b=u、a+b=v
 となるようなものが何通りあるかを求めてください。
 ここで、xor はビットごとの排他的論理和を表します。
 なお、答えは非常に大きくなることがあるので、10^9+7 で割った余りを求めてください。
 1≦N≦10^18
=================================================================

解説=============================================================
 解説を見た( http://kmjp.hatenablog.jp/entry/2017/01/11/1000 )
 
 制約の大きい数え上げは　桁dpやメモ化再帰の可能性が高い
 
 上からu,vの各桁の0,1を決めて行くメモ化再帰
 
 もいっこ
 OEISを用いる (http://piroz.hatenablog.com/entry/2016/12/19/005445 )
 
 testを実行して得られた数列を検索すると
 A007729 がそれらしい答えのものとわかる
 ここで、さらに調べるとこれは A002487 の部分和で表されることがわかる為、
 これをメモ化して行く
================================================================
*/
const ll MOD = 1e9+7;
ll N;

// test =======================================

void test(){
    set<pii> s;
    for(int n = 1; n < 20;n++){
        s.clear();
        for(int a = 0; a <= n; a++){
            for(int b = 0; a + b <= n; b++){
                s.insert(pii(a^b,a+b));
            }
        }
        cout << s.size() << endl;
    }
}
// ============================================
// solve 1 メモ化再帰 ===========================
ll memo[64][5][5];
void init(){
    for(int i = 0; i < 64;i++)for(int j = 0; j < 5;j++)for(int k = 0; k < 5;k++) memo[i][j][k] = -1;
}
ll dfs(int d,int a,int b){
    if(d < 0) return 1;
    ll& ret = memo[d][a][b];
    if(ret != -1) return ret;
    ret = 0;
    
    if(N&(1LL<<d)){ // d 桁目が 1
        ret += dfs(d-1,1,min(2,b*2+1));
        ret += dfs(d-1,a,min(2,b*2));
    }else{
        ret += dfs(d-1,a,min(2,b*2));
        if(a && b) ret += dfs(d-1,a,min(2,b*2-1));
    }
    if(b){
        if(N&(1LL<<d)){
            ret += dfs(d-1,1,min(2,b*2-1));
        }else{
            ret += dfs(d-1,a,min(2,b*2-2));
        }
    }
    ret %= MOD;
    return ret;
}
ll solve_1(){
    init();
    cin >> N;
    return dfs(60,0,0);
}

// ===========================================
// solve_2 OEIS ==============================

map<ll,ll> Memo;
ll f(ll n){
    ll& res = Memo[n];
    if(res != 0) return res;
    if(n <= 2) return res = n;
    res = f(n/2) + f((n-1)/2) + f((n+1)/2);
    res%=MOD;
    return res;
}
ll solve_2(){
    cin >> N;
    return f(N+1);
}

// =============================================

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
  // test();
  //  cout << solve_1() << endl;
    cout << solve_2() << endl;
	return 0;
}
