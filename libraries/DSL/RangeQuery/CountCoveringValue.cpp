/**
 * 与えられた数列の区間中の種類数を求める
 * a : 数列
 * query : クエリ (l,r)  0-index
 */
template<class T>
struct BIT {
    T N;
    vector<T> bit;
    BIT(int N):N(N) { bit.resize(N + 1, 0);}
    void add(int x, T val){ while (x <= N) { bit[x] += val; x += x & -x;}}
    T sum(int x){ T ret = 0; if(x == 0) return ret; while (x) { ret += bit[x]; x &= (x - 1); } return ret;}
    T sum(int l,int r){ return sum(r) - sum(l-1);}
};
vector<int> CountCoveringValue(vector<int>& a, vector<pii>& query){
    int n = (int)a.size();
    int q = (int)query.size();
    
    vector<int> ans(q);
    
    using Item = tuple<int,int,int>;
    vector<Item> qinfo(q);
    for(int i = 0; i < q;i++){
        qinfo[i] = Item(query[i].second,query[i].first,i);
    }
    sort(qinfo.begin(),qinfo.end());
    
    BIT<int> bit(n);
    map<int,int> lastAppeared; // これを配列に変えることで高速化可能
    for(int i = 0; i < n;i++){
        lastAppeared[a[i]] = i;
    }
    for(auto p:lastAppeared){
        bit.add(p.second+1,1);
    }
    int nowr = -1;
    for(auto q:qinfo){
        int l,r,id; tie(r,l,id) = q;
        while(nowr < r){ // 更新を後でまとめることで高速化可能
            nowr++;
            int prev = lastAppeared[a[nowr]];
            lastAppeared[a[nowr]] = nowr;
            int v = lastAppeared[a[nowr]];
            bit.add(prev+1,-1);
            bit.add(v+1,1);
        }
        ans[id] = bit.sum(l+1,r+1);
    }
    return ans;
};

/// =================================================================
///　verified : https://atcoder.jp/contests/abc174/tasks/abc174_f
template<class Type>
Type solve(Type res = Type()){
    int N,Q; cin >> N >> Q;
    
    vector<int> a(N); for(auto& in:a) cin >> in;
    vector<pii> query(Q);
    for(int i = 0; i < Q;i++){
        int l,r; cin >> l >> r;
        l--; r--;
        query[i] = make_pair(l, r);
    }
    
    auto ans = CountCoveringValue(a, query);
    for(int i = 0; i < Q;i++){
        cout << ans[i] << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
