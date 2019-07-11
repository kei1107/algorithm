#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
/*
 Convex hull trick
 */
// CHT ４パターン テストは下部
// ===========================================================================
/*
 クエリが単調増加でない場合(特定パターンにマッチ)
 追加オーダー 少
 */
struct CHT{
    typedef pair<ll,ll> PT;
    typedef ll RT;
    vector<PT> deq; // first * x + second
    int s,t;
    CHT(int n):s(0),t(0){ deq.resize(n); }
    void add(RT a,RT b){  // a: 単調減少
        const PT p(a,b);
        while(s+1 < t && check(deq[t-2],deq[t-1],p)) t--;
        deq[t++] = p;
    }
    RT incl_query(RT x){  // x: 単調増加
        while(s+1 < t && f(deq[s],x) >= f(deq[s+1],x)) s++;
        return f(deq[s],x);
    }
    RT query(RT x){   // 条件なし
        RT low = s-1, high = t-1;
        while(low+1<high) {
            RT mid = (low+high)>>1;
            if (isright(deq[mid], deq[mid+1], x)) low = mid;
            else high = mid;
        }
        return f(deq[high], x);
    }
    
private:
    bool isright(const PT &p1,const PT &p2,RT x){
        return (p1.second-p2.second) >= x * (p2.first-p1.first);
    }
    bool check(const PT &p1,const PT &p2,const PT &p3){
        return (p2.first-p1.first)*(p3.second-p2.second) >= (p2.second-p1.second)*(p3.first-p2.first);
    }
    RT f(const PT &p,RT x){
        return p.first*x + p.second;
    }
};

// ===========================================================================
/*
 直線の係数が単調減少でない場合 // 典型タイプ
 追加オーダー　logN (標準)
 */

struct CHT2{
    typedef pair<ll,ll> PT;
    typedef ll RT;
    
    struct L{
        ll a,b;
        L(ll a, ll b): a(a),b(b){}
        bool operator<(const L &rhs) const{
            return a != rhs.a ? a > rhs.a : b < rhs.b;
        }
    };
    
    struct CP{
        ll n,d;
        L p;
        CP(ll _n,ll _d, const L &p):n(_n),d(_d),p(p){
            if(d < 0) { n *= -1; d *= -1;}
        }
        bool operator<(const CP &rhs) const{
            if(n == LINF || rhs.n == -LINF) return 0;
            if(n == -LINF || rhs.n == LINF) return 1;
            return n*rhs.d < rhs.n*d;
        }
    };
    typedef set<L>::iterator It;
    set<L> S;
    set<CP> C;
    
public:
    CHT2(){
        // 番兵
        S.insert({L(LINF,0), L(-LINF,0)});
        C.insert(cp(L(LINF,0),L(-LINF,0)));
    }
    // for debug
    void print() {
        cout << "S : "; for (auto it : S) printf("(%lld,%lld)", it.a, it.b); puts("");
        cout << "C : "; for (auto it : C) printf("(%lld,%lld)", it.n, it.d); puts("");
    }
    
    void add(ll a, ll b) {
        const L p(a,b);
        It pos = S.insert(p).first;
        if (check(*it_m1(pos), p, *it_p1(pos))) {
            // 直線(a,b)が不要
            S.erase(pos);
            return;
        }
        C.erase(cp(*it_m1(pos), *it_p1(pos)));
        {
            // 右方向の削除
            It it = it_m1(pos);
            while(it!=S.begin() && check(*it_m1(it), *it, p)) --it;
            C_erase(it, it_m1(pos));
            S.erase(++it,pos);
            pos = S.find(p);
        }
        {
            // 左方向の削除
            It it = it_p1(pos);
            while(it_p1(it)!=S.end() && check(p,*it, *it_p1(it))) ++it;
            C_erase(++pos, it);
            S.erase(pos, it);
            pos = S.find(p);
        }
        C.insert(cp(*it_m1(pos), *pos));
        C.insert(cp(*pos, *it_p1(pos)));
    }
    ll query(ll x) {
        const L &p = (--C.lower_bound(CP(x,1,L(0,0))))->p;
        return p.a*x + p.b;
    }
    
private:
    It it_p1(It a){return ++a;}
    It it_m1(It a){return --a;}
    void C_erase(It a, It b) {
        for (It it=a; it!=b; ++it) C.erase(cp(*it, *it_p1(it)));
    }
    CP cp(const L &p1, const L &p2) {
        if (p1.a == LINF) return CP(-LINF,1,p2);
        if (p2.a == -LINF) return CP(LINF,1,p2);
        return CP(p1.b-p2.b, p2.a-p1.a, p2);
    }
    bool check(const L &p1, const L &p2, const L &p3) {
        if (p1.a==p2.a && p1.b <= p2.b) return 1;
        if (p1.a == LINF || p3.a == -LINF) return 0;
        return (p2.a-p1.a)*(p3.b-p2.b) >= (p2.b-p1.b)*(p3.a-p2.a);
    }
};
// ===========================================================================
// LiChao_min ===== 優秀 //
using LL = long long;
struct LiChao_min {
    struct line {
        LL m, c;
        line(LL _m = 0, LL _c = 0) { m = _m; c = _c; }
        LL eval(LL x) { return m * x + c; }
    };
    struct node {
        node *l, *r; line f;
        node(line v) { f = v; l = r = NULL; }
    };
    typedef node* pnode;
    pnode root; LL sz;
#define mid ((l+r)>>1)
    void insert(line &v, LL l, LL r, pnode &nd) {
        if (!nd) { nd = new node(v); return; }
        LL trl = nd->f.eval(l), trr = nd->f.eval(r);
        LL vl = v.eval(l), vr = v.eval(r);
        if (trl <= vl && trr <= vr) return;
        if (trl > vl && trr > vr) { nd->f = v; return; }
        if (trl > vl) swap(nd->f, v);
        if (nd->f.eval(mid) < v.eval(mid)) insert(v, mid + 1, r, nd->r);
        else {swap(nd->f, v); insert(v, l, mid, nd->l);}
    }
    LL query(LL x, LL l, LL r, pnode &nd) {
        if (!nd) return LLONG_MAX;
        if (l == r) return nd->f.eval(x);
        if (mid >= x) return min(nd->f.eval(x), query(x, l, mid, nd->l));
        return min(nd->f.eval(x), query(x, mid + 1, r, nd->r));
    }
    /* -sz <= query_x <= sz */
    void init(LL _sz) { sz = _sz + 1; root = NULL; }
    void add_line(LL m, LL c) { line v(m, c); insert(v, -sz, sz, root); }
    LL query(LL x) { return query(x, -sz, sz, root); }
};


// kazuma convex_hull_trick class =================================== //
template <typename T, const T id>
class convex_hull_trick {
    struct line {
        T a, b;
        line(T a_ = 0, T b_ = 0) : a(a_), b(b_) {}
        T get(T x) { return a * x + b; }
    };
    struct node {
        line l;
        node *lch, *rch;
        node(line l_) : l(l_), lch(nullptr), rch(nullptr) {}
        ~node() {
            if (lch) delete lch;
            if (rch) delete rch;
        }
    };
private:
    const int n;
    const vector<T> pos;
    node *root;
    
public:
    convex_hull_trick(const vector<T>& pos_) : n((int)pos_.size()), pos(pos_), root(nullptr) {}
    ~convex_hull_trick() {
        if (root) delete root;
    }
    void insert(T a, T b) {
        line l(a, b);
        root = modify(root, 0, n - 1, l);
    }
    T get(T x) const {
        int t = (int)(lower_bound(pos.begin(), pos.end(), x) - pos.begin());
        assert(t < n && pos[t] == x);
        return sub(root, 0, n - 1, t);
    }
    
private:
    node* modify(node *p, int lb, int ub, line& l) {
        if (!p) return new node(l);
        if (p->l.get(pos[lb]) >= l.get(pos[lb]) && p->l.get(pos[ub]) >= l.get(pos[ub])) return p;
        if (p->l.get(pos[lb]) <= l.get(pos[lb]) && p->l.get(pos[ub]) <= l.get(pos[ub])) {
            p->l = l;
            return p;
        }
        int c = (lb + ub) / 2;
        if (p->l.get(pos[c]) < l.get(pos[c])) swap(p->l, l);
        if (p->l.get(pos[lb]) <= l.get(pos[lb]))
            p->lch = modify(p->lch, lb, c, l);
        else
            p->rch = modify(p->rch, c + 1, ub, l);
        return p;
    }
    T sub(node *p, int lb, int ub, int t) const {
        if (!p) return id;
        if (ub - lb == 0) return p->l.get(pos[t]);
        int c = (lb + ub) / 2;
        if (t <= c) return max(p->l.get(pos[t]), sub(p->lch, lb, c, t));
        return max(p->l.get(pos[t]), sub(p->rch, c + 1, ub, t));
    }
};

// ======== TEST =================================================//
// CHT CHT2 LiChao_min convex_hull_trick-class

void CHT_test(){
    CHT cht(3);
    // y = 2*x + 3 , y = -x + 4
    cht.add(2,3);
    cht.add(-1,4);
    cout << cht.query(1) << endl; // 3
}

void CHT2_test(){
    CHT2 cht;
    // y = 2*x + 2 , y = -x + 4 , y = 3*x + 4
    cht.add(2,2);
    cht.add(-1,4);
    cht.add(3,4);
    cout << cht.query(-1) << endl; // 0
    cht.print();
}

void CHT2_test2(){
    CHT2 cht;
    // y = 2*x + 2 , y = x + 3, y = -x + 10, y = -2*x + 15
    vector<pii> ap{
        {2,2},
        {1,3},
        {-1,10},
        {-2,15}
    };
    for(auto p:ap){
        cht.add(p.first,p.second);
    }
    for(int i = 0; i < 8;i++){
        cout << cht.query(i) << " " ;
    }
    cout << endl;
    cht.print();
}

void CHT2_test3(){
    // y = 2*x + 2 , y = x + 3, y = -x + 10, y = -2*x + 15
    vector<pii> ap{
        {2,2},
        {1,3},
        {-1,10},
        {-2,15}
    };
    const int N = (int)ap.size();
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    do{
        CHT2 cht;
        for(int i = 0; i < N;i++){
            cout << "(" << ap[v[i]].first << "," << ap[v[i]].second << ") ";
            cht.add(ap[v[i]].first,ap[v[i]].second);
        }
        cout << endl;
        for(int i = 0; i < 8;i++){
            cout << cht.query(i) << " " ;
        }
        cout << endl;
        cht.print();
    }while(next_permutation(v.begin(),v.end()));
}

void Colocon2018_C(){
    // <https://beta.atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c>
    /*
     i番のすぬけキャノンですぬけ号を撃破するのに最小限必要なエネルギー
     
     ans := min(a_j + (j - i)^2)   j : 0..N-1
     = min(a_j + j^2 -2*i*j + i^2)
     = i^2 + min(-2*i*j + a_j + j^2)
     
     n本の -2*i*j + (a_j + j^2) について各iでの最も小さい直線上の値を求めれば良い
     */
    int N; cin >> N;
    vector<ll> a(N);
    for(auto& in:a) cin >> in;
    // CHT solve    Time : 356ms   memory : 7040KB
    /*
     CHT cht(N);
     for(ll j = 0; j < N;j++){
     cht.add(-2*j,a[j] + j*j);
     }
     for(ll i = 0; i < N;i++){
     cout << i*i + cht.query(i) << endl;
     }
     //*/
    // CHT2 solve   Time : 658ms  memory : 31744KB
    /*
     CHT2 cht;
     for(ll j = 0; j < N;j++){
     cht.add(-2*j,a[j] + j*j);
     }
     for(ll i = 0; i < N;i++){
     cout << i*i + cht.query(i) << endl;
     }
     //*/
    
    // Li chao solve TIme : 401ms memory : 13056KB
    /*
     LiChao_min cht;
     cht.init(1e12);
     for(ll j = 0; j < N;j++){
     cht.add_line(-2*j,a[j] + j*j);
     }
     for(ll i = 0; i < N;i++){
     cout << i*i + cht.query(i) << endl;
     }
     //*/
    
    // kazuma: CHT(入力値を与えておく) :421ms memory : 16128KB
    vector<ll> val(N); iota(val.begin(),val.end(),0);
    convex_hull_trick<ll,LLONG_MIN> cht(val);
    for (ll  j = 0; j < N; j++) {
        cht.insert(2 * j, -a[j] - j*j);
    }
    for (ll  i = 0; i < N; i++) {
        cout << i*i + -cht.get(i) << endl;
    }
}
using VL = vector<LL>;
using VVL = vector<vector<LL>>;
void csa_squared_ends() {
    int N, K;
    cin >> N >> K;
    VL a(N);
    for(auto& in:a) cin >> in;
    VVL dp(K + 1, VL(N + 1, LINF));
    dp[0][0] = 0;
    for(int k = 0; k < K;k++){
        LiChao_min cht;
        cht.init(1e6);
        for(int i = 0; i < N;i++){
            cht.add_line(-2*a[i],a[i]*a[i]+dp[k][i]);
            dp[k+1][i+1] =( a[i] * a[i] + cht.query(a[i]));
        }
    }
    cout << dp[K][N] << endl;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //    CHT_test();
    //    CHT2_test();
    //    CHT2_test2();
    //    CHT2_test3();
    Colocon2018_C();
    //csa_squared_ends();
    return 0;
}
