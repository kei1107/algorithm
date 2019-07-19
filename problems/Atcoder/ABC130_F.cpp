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
 <url:https://atcoder.jp/contests/abc130/tasks/abc130_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 xmax-xmin と　ymax-ymin の値はそれぞれ下向きの凸性を持つ。
 よって、三分探索で求めることができる。
 
 （数ケースだけ落ちるなどをしたので、複数個の出力候補を比較している）
 ================================================================
 */

typedef long double ld;
template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<ld> x(N),y(N);
    vector<char> d(N);
    for(int i = 0; i < N;i++){
        cin >> x[i] >> y[i] >> d[i];
    }
    
    ld l = 0, r = INF;
    
    auto calc = [&](ld m){
        ld ret;
        ld xmax = -LINF;
        ld xmin = LINF;
        ld ymax = -LINF;
        ld ymin = LINF;
        
        for(int i = 0; i < N;i++){
            switch (d[i]) {
                case 'R':
                    xmax = max(xmax,x[i]+m);
                    xmin = min(xmin,x[i]+m);
                    ymax = max(ymax,y[i]);
                    ymin = min(ymin,y[i]);
                    break;
                case 'L':
                    xmax = max(xmax,x[i]-m);
                    xmin = min(xmin,x[i]-m);
                    ymax = max(ymax,y[i]);
                    ymin = min(ymin,y[i]);
                    break;
                case 'U':
                    xmax = max(xmax,x[i]);
                    xmin = min(xmin,x[i]);
                    ymax = max(ymax,y[i]+m);
                    ymin = min(ymin,y[i]+m);
                    break;
                case 'D':
                    xmax = max(xmax,x[i]);
                    xmin = min(xmin,x[i]);
                    ymax = max(ymax,y[i]-m);
                    ymin = min(ymin,y[i]-m);
                    break;
                default:
                    break;
            }
        }
        
        ret = (xmax - xmin) * (ymax - ymin);
        return ret;
    };
    
    int num = 200;
    while(num--){
        ld m1 = l + (r-l)/3;
        ld m2 = l + (r-l)/3*2;
        
        ld ret1 = calc(m1);
        ld ret2 = calc(m2);
        
        if(ret1 <= ret2){
            r = m2;
        }else{
            l = m1;
        }
    }
    ld m1 = l + (r-l)/3;
    ld m2 = l + (r-l)/3*2;
    res = min({calc(l),calc(m1),calc(m2),calc(r)});
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ld>() << endl;
    return 0;
}
