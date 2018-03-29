#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
 <url:https://yukicoder.me/problems/no/409>
 問題文============================================================
 btkさんは毎日ドーナツを食べています．
 ある日，btkさんは N 日間ダイエットをすることを決意しました．
 btkさんは毎日違うお店でドーナツを買っていて，
 ダイエット開始から i 日目に訪れるお店でドーナツを食べるとDikg体重が増えることが分かっています．
 また，1 日ドーナツを食べるのをやめると，Akg痩せることができます.
 
 しかし，ドーナツを食べない日が続くとストレスが溜まります．
 ここで，ストレス値というパラメータを定義します． ダイエット開始時点でのストレス値は0です．
 1 日ドーナツを食べないとストレス値が 1 溜まり，
 1日の終了時にbtkさんの体重はB∗(ストレス値)B∗(ストレス値)kg増加します．
 ドーナツを食べるとストレス値は 0 に戻ります．
 
 各日において，ストレス値の変化後に体重が変化することに注意してください．
 
 ダイエット開始前のbtkさんの体重を W kgとしたとき，N 日間で何kgに痩せることができるでしょうか．

 =================================================================
 
 解説=============================================================
 
 Convex hull trick
 
 ストレスがj-1溜まっている時 : -A + B * j kg増える
 i日目にドーナツを食べた時 : Di kg増える
 
 考察1 **********************************************
 
 dp[i][j] := i日目でストレスがj溜まっている時の体重の最小
 
 初期条件 dp[0][0] = W, dp[0][1...N] = INF
 
 漸化式
 dp[i][0] = min(dp[i-1][j] + Di)   0 <= j <= N
 dp[i][j] = dp[i-1][j-1] - A + B*j
 
 => ans := min(dp[N][j])  0 <= j <= N
 
 O(N^2)
 
 ***************************************************
 
 考察2 **********************************************
 
 別の考え方　＝＞　最後にドーナツを食べた日のみに注目　（その間の増分は t日間食べていなければ -t*A + t*(t+1)/2 * B とO(1)で計算できる)
 
 dp[i] := i日目にドーナツを食べた時の最小値
 
 初期条件 dp[0] = W
 
 漸化式
 dp[i] = min(Di + dp[j] - (i - j - 1)*A + (i - j - 1)(i - j)/2 * B)   0 <= j <= i-1
 
 iに着目した時（iを定数とみなせれる時)
 
 dp[i] = Di -(i - 1)*A + (i^2 - i)/2*B + min(-jB*i + dp[j] + j*A + (j^2 + j)/2 * B)  0 <= j <= i-1
 
 min内部に関して
 aj = jB
 bj = dp[j] + j*A + (j^2 + j)/2 * B
 Ci := Di - (i-1)*A + (i^2 - i)/2*B
 とすると
 dp[i] = Ci + min(-aj * i + bj)  0 >= j <= i - 1
 
 
 y=−ax+b の形をした k−1 本の直線のうち
 x=k の時 y が最小となるものを選べばよいことになり
 Convex hull trick でもとまる
 
 ================================================================
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

ll N,A,B,W;
vector<ll> D;
vector<ll> dp;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> A >> B >> W;
    D.resize(N);
    for(auto &in:D) cin >> in;

    dp.resize(N+1,0);
    dp[0] = W;
//    CHT cht((int)N);
    CHT2 cht;
    for(ll i = 0; i< N;i++){
        cht.add(-B*i,dp[i] + B*(i*i-i)/2 + A*i);
        dp[i+1] = B*(i*i + i)/2 + D[i] - A*i + cht.query(i);
    }
    ll ans = LINF;
    for(ll i = 0; i <= N;i++){
        ans = min(ans , dp[i] - A*(N-i)+ B*(N-i)*(N-i+1)/2);
    }
    cout << ans << endl;
    return 0;
}

