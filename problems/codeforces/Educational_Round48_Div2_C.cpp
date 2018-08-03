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
 <url:http://codeforces.com/contest/1016/problem/C>
 問題文============================================================
 
 2xnのマスが与えられる。
 
 マスには数字が書かれており、
 これまでに移動した回数*マスの数字　の値を得ることができる。
 全てのマスを一回だけ訪れ、かつ、得る値を最大にしたい。
 
 また、始点は左上のマスとし、終点はどこで終わっても良い
 =================================================================
 解説=============================================================
 
 始点から時計回り、反時計回り、蛇のようにぐねぐね、
 途中まで蛇のようにぐねぐねしてその後（反）時計回りするパターンが考えられるので全部試す。
 
 最後のパターンに関しては累積和を使って、全ての場合に対してO(1)で求めることができる
 
 ================================================================
 */
ll solve(){
    ll res = 0;
    ll n; cin >> n;
    vector<ll> a(n),b(n);
    for(auto& in:a) cin >> in;
    for(auto& in:b) cin >> in;

    // ====
    ll cnt = 0;
    ll sum = 0;
    for(int i = 0; i < n;i++){
        sum += cnt*a[i];
        cnt++;
    }
    for(int i = n-1;i>=0;i--){
        sum += cnt*b[i];
        cnt++;
    }
    res = max(res,sum);

    // ====
    cnt = sum = 0;
    cnt++;
    for(int i = 0; i < n;i++){
        sum += cnt*b[i];
        cnt++;
    }
    for(int i = n-1; i >= 1; i--){
        sum += cnt*a[i];
        cnt++;
    }
    res = max(res,sum);
    // ====
    cnt = sum = 0;
    for(int i = 0; i < n;i++){
        if(i%2 == 0){
            sum += (cnt*a[i] + (cnt+1)*b[i]);
            cnt += 2;
        }else{
            sum +=(cnt*b[i] + (cnt+1)*a[i]);
            cnt+=2;
        }
    }
    res = max(res,sum);
    // ====

    vector<ll> S(n+1);
    vector<ll> A1(n+1),A2(n+1);
    for(ll i = n-1; i >= 0; i--){
        S[i] = S[i+1] + a[i] + b[i];
    }
    for(ll i = n-1; i >= 0; i--){
        ll X = n-i;
        X = 2*(X-1) + 1;
        A1[i] = A1[i+1] + S[i+1] + X*b[i];
        A2[i] = A2[i+1] + S[i+1] + X*a[i];
    }
//
//    cout << S << endl;
//    cout << A1 << endl;
//    cout << A2 << endl;
//
    res = 0;
    cnt = sum = 0;
    ll T = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            res = max(res,sum+cnt*S[i]+A1[i]);
            sum += (cnt*a[i] + (cnt+1)*b[i]);
            cnt += 2;
        }else{
            res = max(res,sum+cnt*S[i]+A2[i]);
            sum +=(cnt*b[i] + (cnt+1)*a[i]);
            cnt+=2;
        }
    }
    // ====

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
