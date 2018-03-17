#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://ddcc2016-qual.contest.atcoder.jp/tasks/ddcc_2016_qual_c>
問題文============================================================
 N 枚のカードが 1 列に並べられており、i(1≦i≦N) 番目のカードには整数 Ai が書かれています。
 
 この N 枚のカードを使ったロト 2 という宝くじがあります。
 ロト 2 は 1 番から N 番までの番号から異なる 2 つの番号 i, j(i<j) を選び、
 選ばれた 2 つの番号のカードにそれぞれ書かれた値の積 AiAjが K の倍数となるとき当選するというルールで行われます。
 
 AiAj が K の倍数となるような i と j の組合せ (i, j) を良い組合せと呼ぶことにします。
 良い組合せは何通りあるか求めなさい。
 
=================================================================

解説=============================================================
貪欲に２つの番号を見ていったら N^2 で間に合わない
 
 しかし、ここで重要なのは K の約数である。
 よって、あらかじめKの約数と gcd(K,Ai) を列挙しておき、
 その約数のみに注目すれば確認すべき要素が少なくなるので頑張れば間に合う
 （このコード自体もっと最適化できるけど間に合ったからそのままで）
================================================================
*/

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

ll solve(){
    ll ret = 0;
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(auto &in:A) cin >> in;
    
    vector<ll> a(N);
    for(int i = 0; i < N;i++){
        a[i] = gcd(A[i],K);
    //    cout << a[i] << " \n"[i==N-1?1:0];
    }
    
    set<ll> s(a.begin(),a.end());
    vector<ll> vs(s.begin(),s.end());
    map<ll,vector<ll>> mp1;
    
    for(int i = 0; i < (int)vs.size();i++){
        for(int j = i+1;j < (int)vs.size();j++){
            if(vs[i]*vs[j] % K == 0){
                mp1[vs[i]].push_back(vs[j]);
                mp1[vs[j]].push_back(vs[i]);
            }
        }
    }
    for(int i = 0; i < (int)vs.size();i++){
        if(vs[i] * vs[i] % K == 0){
            mp1[vs[i]].push_back(vs[i]);
        }
    }
    
    map<ll,ll> mp2;
    for(ll i = N - 1; i>= 0;i--){
        for(auto v: mp1[a[i]]){
            ret += mp2[v];
        }
        mp2[a[i]]++;
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
