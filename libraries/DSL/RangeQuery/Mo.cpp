/*
 * Mo's Algorithm
 * O(f(N)Q√N)
 * add(l,r) := クエリ[l,r)を追加
 * run(add,del,rem) := すべてのクエリ処理
 * add : id番目の要素を追加
 * del : id番目の要素を削除
 * rem : id番目のクエリを評価
 */

const int MAX_N = 500005;
struct Mo {
    using add_func = function<void(int&)>;
    using del_func = function<void(int&)>;
    using rem_func = function<void(int&)>;
    
    int BlockSZ;
    int Q;
    int L[MAX_N];
    int R[MAX_N];
    int order[MAX_N];
    Mo() : Q(0),BlockSZ((int)sqrt(MAX_N)){}
    
    // [l,r)  : 0-index
    void add(int l, int r) {
        L[Q] = l;
        R[Q] = r;
        order[Q] = Q;
        Q++;
    }
    
    void run(const add_func &add, const del_func &del, const rem_func &rem) {
        // assert(left.size() == order.size());
        sort(order, order+Q, [&](int l, int r) {
            int lblock = L[l] / BlockSZ, rblock = L[r] / BlockSZ;
            if(lblock != rblock) return L[l] < L[r];
            return (lblock&1) ? R[l] < R[r] : R[l] > R[r];
        });
        int nl = 0, nr = 0;
        for(int q = 0; q < Q;q++){
            int idx = order[q];
            while(nl > L[idx]){
                nl--;
                add(nl);
            }
            while(nr < R[idx]){
                add(nr);
                nr++;
            }
            while(nl < L[idx]){
                del(nl);
                nl++;
            }
            while(nr > R[idx]){
                nr--;
                del(nr);
            }
            rem(idx);
        }
    }
};


// verified : https://atcoder.jp/contests/abc174/tasks/abc174_f
/**
 * 微妙に速度が足りなかった為、グローバル配列化等で定数倍高速化によりAC
 * https://atcoder.jp/contests/abc174/submissions/15649670
 */
template<class Type>
Type solve(Type res = Type()){
    int N,Q; cin >> N >> Q;
    vector<int> c(N); for(auto& in:c) cin >> in;
    Mo mo;
    for(int i = 0; i < Q;i++){
        int l,r; cin >> l >> r;
        l--;
        mo.add(l,r);
    }
    
    vector<int> ans(Q);
    vector<int> cnt(N+1);
    int sum = 0;
    auto add = [&](int& id){
        if(cnt[c[id]] == 0) sum++;
        cnt[c[id]]++;
    };
    auto del = [&](int& id){
        cnt[c[id]]--;
        if(cnt[c[id]] == 0) sum--;
    };
    auto rem = [&](int& id){
        ans[id] = sum;
    };
    
    mo.run(add,del,rem);
    for(int i = 0; i < Q;i++){
        cout << ans[i] << '\n';
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
