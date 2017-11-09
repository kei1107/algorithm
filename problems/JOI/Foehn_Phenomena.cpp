#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2016/2017-ho/2017-ho.pdf>
 問題文============================================================
 IOI 国では海から陸に向かって常に風が吹いている．
 風は地点 0 から地点 1 ，地点 2,… という経路を通りながら地点 N まで吹く．
 地点 N には JOI 君の家が建てられている．
 地点 0 の標高は A0=0 であり，地点 i(1≦i≦N) の標高は Ai である．
 
 風は地表面に沿って吹き，高度の変化に応じて風の温度が変化する．
 海に接している地点 0 での風の温度は 0 度であり，すべての i(0≦i≦N−1)に対して，
 地点 i から地点 i+1 にかけての風の温度の変化はその時点における Ai と Ai+1 にのみ依存しており，
 以下のようになっている．
 
 Ai<Ai+1 のとき，標高が 1 上がるごとに風の温度は S 度下がる．
 Ai≧Ai+1 のとき，標高が 1 下がるごとに風の温度は T 度上がる．
 IOI 国の領土では地殻変動が盛んである．
 あなたは，Q 日間の地殻変動のデータを入手した．
 j 日目(1≦j≦Q) には，Lj≦k≦Rj(1≦Lj≦Rj≦N) を満たす地点の標高 Ak が Xj だけ変化する．
 Xj が非負のときは，標高が Xjだけ上がることを意味し，Xj が負のときは，標高が |Xj| だけ下がることを意味する．
 
 あなたの仕事は，各地殻変動が起こった後の，JOI 君の家に吹く風の温度を求めることである．
 =================================================================
 解説=============================================================
 区間更新だでセグ木だね。
 ある地点を見たとき、右隣との高さの差による値をもつセグ木を作れば、
 0..NまでのRSQとなる。
 ここで、高さの差が正負により値を加算する時の処理がS,Tと変化することに注意
 ================================================================
 */

struct SegTree {
    int N;
    ll init_v = 0;
    vector<ll> node, lazy;
    
    SegTree(int _N) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
        lazy.resize(2 * N - 1, init_v);
    }
    
    void lazy_evaluate(int k) {
        node[k] += lazy[k]; // add のため加算
        if (k < N - 1) {
            lazy[2 * k + 1] += lazy[k] / 2; // add のため加算
            lazy[2 * k + 2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    
    /* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
    ll update(int a, int b, ll x) { return update(a, b, 0, 0, N, x); }
    ll update(int a, int b, int k, int l, int r, ll x) {
        if (r <= a || b <= l) {
            lazy_evaluate(k); // nodeを参照する前には必ず更新
            return node[k];
        }
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x; // 参照区間が指定区間を完全に含んでいれば, 参照区間長*加算値分nodeに加算される
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            ll vl = update(a, b, 2 * k + 1, l, (l + r) / 2, x);
            ll vr = update(a, b, 2 * k + 2, (l + r) / 2, r, x);
            return node[k] = vl + vr;
        }
    }
    
    /* [a,b) 引数の範囲に注意!! */
    ll query(int a, int b) { return query(a, b, 0, 0, N); }
    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) {
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return vl + vr;
        }
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,Q,S,T; cin >> N >>Q >> S >> T;
    vector<ll> A(N+1);
    for(auto& a: A) cin >> a;
    SegTree rsq((int)N);
    for(int i = 0; i < N;i++){
        if(A[i] < A[i+1]){
            rsq.update(i,i+1,(A[i] - A[i+1])*S);
        }else{
            rsq.update(i,i+1,(A[i] - A[i+1])*T);
        }
    }
    for(int i = 0; i < Q;i++){
        ll l,r,x; cin >> l >> r >> x;
        ll L = rsq.query(l-1,l), R = rsq.query(r,r+1);
        
        ll newL = L/(L < 0? S:T) - x;
        ll newR = R/(R < 0? S:T) + x;
        rsq.update(l-1,l, -L + newL * (newL < 0 ? S:T));
        rsq.update(r,r+1, -R + newR * (newR < 0 ? S:T));
        cout << rsq.query(0,N) << endl;
    }
    return 0;
}
