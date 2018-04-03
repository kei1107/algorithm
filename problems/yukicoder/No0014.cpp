#include "bits/stdc++.h"
using namespace std;
typedef int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/14>
 問題文============================================================
 
 最小公倍数を習ったばかりのLarryは、最小公倍数ソートというのを思いついた。
 
 ここで「最小公倍数ソート」とは、
 N個の整数（重複を含む）が与えられ、それぞれai (1≤i≤N)とする。
 a1を固定し、a2〜aNをそれぞれa1に対して最小公倍数を取り、最小公倍数が小さい順に並べ変えるソートのことであるとする。
 （最小公倍数の最小が複数ある場合は、元の数が少ない方が優先される）
 
 Larryは、
 この時出来た配列を新たにa1…aNの名前をつけなおして操作を続ける。
 次にa2を固定し(a1も固定したまま）、a3〜aNを「最小公倍数ソート」していく。
 次にa3を固定し...と続けていった時にaNまで行った時になる数列を求めてください。
 
 （C/C++だと愚直な解法でぎりぎり通ってしまいますが、計算量が抑えられる方法があるので★４になってます。）
 
 =================================================================
 解説=============================================================
 
 愚直解法
    typedef long long ll => typedef int ll
    cin => scanf
    cout => printf
 
 で通る
 
 約数等から高速に判断ができそうだけど、面倒なので愚直にいった
 ================================================================
 */

/*
 gcd : 最大公約数
 lcm : 最小公倍数
 */
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

void solve(){
    ll N; scanf("%d",&N); // cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N;i++) scanf("%d",&a[i]);
    for(int i = 0; i < N;i++){
        if(i!=0) putchar(' ');
        printf("%d",a[i]);
        if(i == N-1) break;
        ll next = i + 1, Max = lcm(a[i],a[i+1]);
        for(int j = i + 2; j < N;j++){
            ll T = lcm(a[i],a[j]);
            if(T < Max){
                next = j; Max = T;
            }else if(T == Max && a[j] < a[next]){
                next = j; Max = T;
            }
        }
        swap(a[i+1],a[next]);
    }
    putchar('\n');
    return;
}
int main(void) {
   //cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
