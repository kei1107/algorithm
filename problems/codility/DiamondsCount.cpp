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

int table[4000][4000];
int solution(vector<int> &X, vector<int> &Y){
    fill(*table,*table + 4000*4000,false);
    ll res = 0;
    int N = (int)X.size();
    for(int i = 0; i < N;i++) table[X[i]][Y[i]] = true;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N;j++){
            pii p1 = {X[i],Y[i]},p2 = {X[j],Y[j]};
            pii vec = {p2.first-p1.first,p2.second-p1.second};
            if(vec.first == 0 || vec.second == 0) continue;
            pii p3,p4;
            
            {
                p3 = {p2.first-vec.first,p2.second+vec.second};
                p4 = {p1.first-vec.first,p1.second+vec.second};
                if(p3.first >= 0 && p3.second >= 0 && p4.first >= 0 && p4.second >= 0){
                    
                    if(table[p3.first][p3.second] && table[p4.first][p4.second]){
                        res++;
                    }
                }
            }
            {
                p3 = {p2.first+vec.first,p2.second-vec.second};
                p4 = {p1.first+vec.first,p1.second-vec.second};
                if(p3.first >= 0 && p3.second >= 0 && p4.first >= 0 && p4.second >= 0){
                    
                    if(table[p3.first][p3.second] && table[p4.first][p4.second]){
                        res++;
                    }
                }
            }
        }
    }
    res/=4;
    return (int)res;
}

int main(){
    vector<int> X = {1,1,2,2,2,3,3},Y = {3,4,1,3,5,3,4};
    cout << solution(X, Y) << endl;
    X = vector<int>{1,2,3,3,2,1}; Y = vector<int>{1,1,1,2,2,2};
    cout << solution(X, Y) << endl;
}
