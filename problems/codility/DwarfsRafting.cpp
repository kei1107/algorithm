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

int solution(int N, string &S, string &T) {
    auto masu = make_v<int>(N,N);
    {
        stringstream ss(S);
        string s;
        while(ss>>s){
            if(s.length()==2){
                masu[s[0]-'0'-1][s[1]-'A'] = 1;
            }else{
                masu[10*(s[0]-'0') + (s[1]-'0')-1][s[2]-'A'] = 1;
            }
        }
    }
    {
        stringstream ss(T);
        string t;
        while(ss>>t){
            if(t.length()==2){
                masu[t[0]-'0'-1][t[1]-'A'] = 2;
            }else{
                masu[10*(t[0]-'0') + (t[1]-'0')-1][t[2]-'A'] = 2;
            }
        }
    }
    
    vector<int> free(4),state(4);
    {
        for(int i = 0; i < N/2;i++){
            for(int j = 0; j < N/2; j++){
                if(masu[i][j]!=1) free[0]++;
                if(masu[i][j]==2) state[0]++;
            }
        }
        for(int i = N/2; i < N;i++){
            for(int j = 0; j < N/2; j++){
                if(masu[i][j]!=1) free[1]++;
                if(masu[i][j]==2) state[1]++;
            }
        }
        for(int i = N/2; i < N;i++){
            for(int j = N/2; j < N; j++){
                if(masu[i][j]!=1) free[2]++;
                if(masu[i][j]==2) state[2]++;
            }
        }
        for(int i = 0; i < N/2;i++){
            for(int j = N/2; j < N; j++){
                if(masu[i][j]!=1) free[3]++;
                if(masu[i][j]==2) state[3]++;
            }
        }

    }

    int ret = 0;
    for(int i = 0; i < 2;i++){
        ret += min(free[i],free[i+2])*2;
        if(min(free[i],free[i+2]) < max(state[i],state[i+2])) return -1;
    }
    int dwarfs = accumulate(state.begin(),state.end(),0);
    ret -= dwarfs;
    return ret;
}
