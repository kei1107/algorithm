#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 dpの結果にdpをかます
 dp[AorBでの消費ドングリ] := BorAでの取得ドングリ
 最初のA->Bで上のdpをやって最大までドングリを増やしたあとB->Aでもう一度同じdpをすればいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> A(3),B(3);
    for(int i = 0; i < 3;i++){
        cin >> A[i];
    }
    for(int i = 0; i < 3;i++){
        cin >> B[i];
    }

    res = N; // Aで完結

    { // A - B - A
        vector<ll> dp(N+1,-INF); // dp[使用料] = 増分
        dp[0] = 0;
        for(int i = 0; i < N; i++){
            if(dp[i] == -INF) continue;
            for(int j = 0; j < 3;j++){
                if(i+A[j] > N) continue;
                dp[i+A[j]] = max(dp[i+A[j]],dp[i]+B[j]);
            }
        }
        ll MAXN = 0;
        for(int i = 0; i <= N;i++){
            MAXN = max(MAXN,(N-i)+dp[i]);
            res = max((ll)res,(N-i)+dp[i]);
        }

        vector<ll> dp2(MAXN+1,-INF); // dp[使用料] = 増分
        dp2[0] = 0;
        for(int i = 0; i < MAXN; i++){
            if(dp2[i] == -INF) continue;
            for(int j = 0; j < 3;j++){
                if(i+B[j] > MAXN) continue;
                dp2[i+B[j]] = max(dp2[i+B[j]],dp2[i]+A[j]);
            }
        }
        for(int i = 0; i <= MAXN;i++){
            res = max((ll)res,(MAXN-i)+dp2[i]);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
