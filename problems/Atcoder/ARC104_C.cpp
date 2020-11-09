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
 <url:https://atcoder.jp/contests/arc104/tasks/arc104_c>
 問題文============================================================
 C - Fair Elevator 
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> A(N),B(N);
    for(int i = 0; i < N;i++) cin >> A[i] >> B[i];

    vector<int> state(2*N+1);
    for(int i = 0; i < N;i++){
        if(A[i] != -1){
            if(state[A[i]]!=0){
                return "No";
            }
            state[A[i]] = -(i+1);
        }
        if(B[i] != -1){
            if(state[B[i]]!=0){
                return "No";
            }
            state[B[i]] =  (i+1);
        }
    }

    vector<int> dp(2*N+1);
    dp[0] = true;

    for(int i = 0; i <= 2*N;i++){
        if(!dp[i]) continue;

        int l = i+1;
        for(int r = l+1; r <= 2*N; r++){
            // (l,r)をペアにする
            int diff = r-l;

            if(r-1+diff > 2*N) break;

            bool ok = true;
            for(int m = l; m < r; m++){
                // 矛盾がないかどうか確認する

                int lid = m, rid = lid + diff;

                if(state[lid] > 0 || state[rid] < 0){
                    // 左端がB，右端がAになっている場合
                    ok = false; 
                    break;
                }


                if(state[lid] == 0 || state[rid] == 0){
                    // 左端・右端のどちらかが未定の場合，都合よく番号を入れればいい
                    // pass

                }else{
                    // 両方　値がある場合

                    if(state[lid]+state[rid] == 0 && state[lid] < 0 && state[rid] > 0){
                        // 同じペアであればok
                        // pass
                    }else{
                        // 異なれば ng

                        ok = false;
                        break;
                    }
                }          
            }

            if(ok){
                dp[r-1+diff] = true;
            }
        }
    }

    if(dp[2*N]) return "Yes";
    else return "No";
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}