#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}

int solution(int K, vector<int> &C, vector<int> &D){
    int res = 0;
    map<int,int> Cm,Dm;
    for(auto v:C) Cm[v]++;
    for(auto v:D) Dm[v]++;
    
    for(auto it = Cm.begin(); it != Cm.end(); it++){
        res += it->second/2;
        it->second %= 2;
        
        if(it->second&&Dm[it->first]&&K){
            Dm[it->first]--;
            it->second--;
            K--;
            res++;
        }
    }

    for(auto it = Dm.begin(); it != Dm.end(); it++){
        ll v1 = K/2*2;
        ll v2 = it->second/2*2;
        ll v = min(v1,v2);
        
        K -= v;
        it->second -= v;
        res += v/2;
    }
    
    return res;
}

int main(){
    vector<int> C = {1,2,1,1}, D = {1,4,3,2,4};
    //cout << solution(2,C,D) << endl;
    vector<int> C2 = {1,2,3,4}, D2 = {3,2,1,5};
    cout << solution(0,C2,D2) << endl;

}
