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
 <url:https://atcoder.jp/contests/arc049/tasks/arc049_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 三分探索でx,y座標を探索する
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    using Point = complex<double>;
    vector<double> x(N),y(N),c(N);
    for(int i = 0; i < N;i++){
        cin >> x[i] >> y[i] >> c[i];
    }
    
    auto calcx = [&](double mx){
        auto calcy = [&](double my){
            double ret = 0;
            for(int i = 0; i < N;i++){
                ret = max(ret,c[i]*max(abs(mx-x[i]),abs(my-y[i])));
            }
            return ret;
        };
        double ly = -1e6,ry = 1e6;
        for(int unchiy = 0; unchiy < 100; unchiy++){
            double my1 = ly + (ry-ly)/3;
            double my2 = ly + (ry-ly)/3*2;
            
            if(calcy(my1) < calcy(my2)){
                ry = my2;
            }else{
                ly = my1;
            }
        }
        return calcy((ly+ry)/2);
    };
    
    double lx = -1e6,rx = 1e6;
    for(int unchix = 0; unchix < 100; unchix++){
        double mx1 = lx + (rx-lx)/3;
        double mx2 = lx + (rx-lx)/3*2;

        if(calcx(mx1) < calcx(mx2)){
            rx = mx2;
        }else{
            lx = mx1;
        }
    }
    res = calcx((lx+rx)/2);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
