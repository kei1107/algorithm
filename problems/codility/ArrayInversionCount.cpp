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
 1-index
 
 add : x に valを加算
 sum : [1,x] の総和を出力
 */
struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    ll sum(int x){
        if(x == 0) return 0;
        ll ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
};
int solution(vector<int>& A){
    int res = 0;
    int N = (int)A.size();
    vector<int> B = A;
    sort(B.begin(),B.end());
    BIT bit(N);
    for(int i = 0; i < N;i++){
        A[i] = (int)(lower_bound(B.begin(),B.end(),A[i]) - B.begin() + 1);
        bit.add(A[i],1);
    }
    for(int i = 0; i < N;i++){
        res += bit.sum(A[i]-1);
        bit.add(A[i],-1);
        if(res > INF){
            res = -1;
            break;
        }
    }
    return res;
}

int main(){
    vector<int> A={-1,6,3,4,7,4};
    cout << solution(A) << endl;
}
