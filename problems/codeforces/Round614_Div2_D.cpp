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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll x0,y0,ax,ay,bx,by,xs,ys,t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;

    vector<pll> ps;
    ll nx = x0, ny = y0;

    ll TMAX = 1e17;
    while(true){
        ll nc = abs(nx-xs) + abs(ny-ys);

        if(nc <= TMAX){
            ps.emplace_back(nx,ny);
        }else{
            break;
        }
        ll nextx = ax*nx + bx;
        ll nexty = ay*ny + by;

//        ll nextc = abs(nextx-xs) + abs(nexty-ys);
//        if(nc <= 2*t){
//            ps.emplace_back(nx,ny);
//        }else{
//            if(nc < nextc){
//                break;
//            }else{
//                ps.emplace_back(nx,ny);
//            }
//        }

        nx = nextx;
        ny = nexty;
    }

    int n = (int)ps.size();
    // cout << n << endl;
    auto calc = [&](int i,int j){
        return abs(ps[i].first-ps[j].first) + abs(ps[i].second-ps[j].second);
    };

    for(int i = 0; i < n;i++){
        {
            ll nowt = abs(ps[i].first-xs) + abs(ps[i].second - ys);
            if(nowt > t) continue;
            ll num = 1;
            for(int j = i-1; j >= 0; j--){
                nowt += calc(j,j+1);
                if(nowt > t) break;
                num++;
            }
            if(nowt < t){
                nowt += calc(0,i);
                for(int j = i+1; j < n;j++){
                    nowt += calc(j,j-1);
                    if(nowt > t) break;
                    num++;
                }
            }
            res = max(res,num);
        }
        {
            ll nowt = abs(ps[i].first-xs) + abs(ps[i].second - ys);
            if(nowt > t) continue;
            ll num = 1;
            for(int j = i+1; j < n; j++){
                nowt += calc(j,j-1);
                if(nowt > t) break;
                num++;
            }
            if(nowt < t){
                nowt += calc(n-1,i);
                for(int j = i-1; j >= 0;j--){
                    nowt += calc(j,j+1);
                    if(nowt > t) break;
                    num++;
                }
            }
            res = max(res,num);
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
