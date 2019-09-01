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
 <url:https://atcoder.jp/contests/abc139/tasks/abc139_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 解説AC：https://img.atcoder.jp/abc139/editorial.pdf
 
 偏角ソートを行えば、使うエンジン群を区間として見ることができる。
 よってO(N^3)で全ての区間をみていけばいい
 ================================================================
 */

double sq_calc(ll X,ll Y){
    return sqrt(X*X+Y*Y);
}
template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    
    using pdd = pair<double,double>;
    vector<pdd> ps(N);
    for(int i = 0; i < N;i++){
        cin >> ps[i].first >> ps[i].second;
    }
    auto update = [&](double X,double Y){
        res = max(res,sq_calc(X,Y));
    };
    
    sort(ps.begin(),ps.end(),[](const pdd& l,const pdd& r){
        return atan2(l.second,l.first) < atan2(r.second,r.first);
    });
    
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            
            double X = 0,Y = 0;
            for(int k = i;; (k += 1)%=N){
                X += ps[k].first;
                Y += ps[k].second;
                
                if(k == j) break;
            }
            update(X,Y);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
