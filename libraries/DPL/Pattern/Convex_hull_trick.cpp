/*
 クエリが単調増加でない場合(特定パターンにマッチ)
 追加オーダー 少
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

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
     */
    // CHT2 solve   Time : 658ms  memory : 31744KB
    CHT2 cht;
    for(ll j = 0; j < N;j++){
        cht.add(-2*j,a[j] + j*j);
    }
    for(ll i = 0; i < N;i++){
        cout << i*i + cht.query(i) << endl;
    }
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
//    CHT_test();
//    CHT2_test();
//    CHT2_test2();
//    CHT2_test3();
    Colocon2018_C();
	return 0;
}
