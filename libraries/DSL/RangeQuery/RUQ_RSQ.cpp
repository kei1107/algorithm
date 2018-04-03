/*
 update(s,t,x): [s,t) をxに変更する。
 find(s,t): [s,t) の総和を出力する。
 */

const ll INIT = 0;
const ll NIL = LLONG_MAX;
struct SegTree {
    int N;
    ll init_v;
    vector<ll> node, lazy;
    
    SegTree(int _N):init_v(INIT) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
        lazy.resize(2 * N - 1, NIL);
    }
    SegTree(int _N, vector<ll>& a){
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
        lazy.resize(2 * N - 1, NIL);
        for(int i = 0; i < _N; i++){ node[i+N-1] = a[i]; }
        build();
    }
    void build(){ for(int k = N - 2; k >= 0; k--){ node[k] = node[2 * k + 1] + node[2 * k + 2];} }
    
    void lazy_evaluate(int k) {
        if (lazy[k] == NIL) return;
        node[k] = lazy[k];
        if (k < N - 1) {
            lazy[2 * k + 1] = lazy[k]/2;
            lazy[2 * k + 2] = lazy[k]/2;
        }
        lazy[k] = NIL;
    }
    
    /* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
    ll update(int a, int b, ll x) { return update(a, b, 0, 0, N, x); }
    ll update(int a, int b, int k, int l, int r, ll x) {
        if (r <= a || b <= l) {
            lazy_evaluate(k); // nodeの値を見るときは必ず遅延評価を更新する
            return node[k]; // updateでは全体の中の最小を見つける必要があるため, [l,r)外になっても値を参照
        }
        if (a <= l && r <= b) {
            lazy[k] = (r-l)*x;
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

//==========================================//
//                  test                    //
//==========================================//

inline void InitRand(){ srand((unsigned int)time(NULL)); }
inline ll myrand(){ return abs(rand()*rand() + 2311*rand() + 1333); }
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N = 8; N =100000;
    SegTree seg(N);
    
    vector<int> a(N, 0);
    InitRand();
    int Q = 10; Q = 100000;
    
    for(int i = 0; i < Q; i++){
        bool q = myrand() % 2;
        if (q == 0) { // 0 : update
            int L = myrand() % N, R = myrand() % N;
            if (R < L)swap(L, R);
            int val = myrand() % Q - Q / 2;
            cout << q << " " << L << " " << R << " " << val << endl;
            seg.update(L,R+1,val);
            for(int j = L; j <= R;j++) a[j] = val;
        }
        else if (q == 1) { // 1 : sum
            int L = myrand() % N, R = myrand() % N;
            if (R < L)swap(L, R);
            cout << q << " " << L << " " << R << endl;
            ll sum = seg.query(L,R+1);
            ll greedy = accumulate(a.begin()+L,a.begin()+(R+1),0LL);
            cout << "sum    : " << sum << endl;
            cout << "greedy : " << greedy << endl;
            assert(sum == greedy);
        }
    }
    
    return 0;
}
