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


int childnum[50050]; // ノートiが持つ子ノードの数
vector<int> G[50050]; // グラフ
set<ll> st[50050];
ll N;

int calc_childnum(ll n,ll pre,ll& res_v){
    childnum[n] = 0;
    for(const int& next:G[n]){
        if(next == pre) continue;
        childnum[n] += calc_childnum(next, n,res_v);
    }
    res_v = max(res_v,(ll)(childnum[n]+1)*(N-(childnum[n]+1)));
    return childnum[n]+1;
}

void rec(ll n,ll pre,ll& res_v){
    ll left = N - (childnum[n]+1);
    ll M = childnum[n] + 1;
    st[n].clear();
    
    
    for(const int& next:G[n]){
        if(next == pre) continue;
        
        
        ll nextM = childnum[next]+1;
        res_v = max(res_v,left*nextM*(M-nextM));
        st[n].insert(nextM);
        if(nextM < M/2) continue;
        rec(next,n,res_v);
        
        auto it = st[next].lower_bound(M/2);
        if(it!=st[next].begin()) it--;
        while(it != st[next].end()){
            ll v = *it;
            st[n].insert(v);
            it++;
        }
    }
    
    auto it = st[n].lower_bound(M/2);
    if(it!=st[n].begin()){
        it--;
        ll v = *it;
        res_v = max(res_v,left * v * (M - v));
        it++;
    }
    if(it!=st[n].end()){
        ll v = *it;
        res_v = max(res_v,left * v * (M - v));
    }
    
    st[n].insert(childnum[n]+1);
}

string solution(vector<int>& A,vector<int>& B){
    string res;
    N = (int)A.size()+1;
    for(int i = 0; i < (int)A.size();i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    
    // Detect Tree Root
    ll root1 = -1,root2 = -1;
    queue<pii> q;
    vector<int> dist(N,INF);
    dist[0] = 0;
    q.push({0,0});
    while(q.size()){
        int n,c;
        tie(n,c) = q.front(); q.pop();
        if(dist[n] < c) continue;
        for(auto next:G[n]){
            if(dist[next] > dist[n] + 1){
                dist[next] = dist[n] + 1;
                q.push({next,dist[next]});
            }
        }
    }
    root1 = max_element(dist.begin(), dist.end()) - dist.begin();
    
    fill(dist.begin(),dist.end(),INF);
    dist[root1] = 0;
    q.push({root1,0});
    while(q.size()){
        int n,c;
        tie(n,c) = q.front(); q.pop();
        if(dist[n] < c) continue;
        for(auto next:G[n]){
            if(dist[next] > dist[n] + 1){
                dist[next] = dist[n] + 1;
                q.push({next,dist[next]});
            }
        }
    }
    root2 = max_element(dist.begin(), dist.end()) - dist.begin();
    
    // From root1
    // Case 3 : No cut
    ll res_v = N;
    
    // Case 2 : One cut
    calc_childnum(root1, -1,res_v);
    
    // Case 1 : Two cut
    rec(root1,-1,res_v);
    
    // From root2
    calc_childnum(root2, -1,res_v);
    rec(root2,-1,res_v);

    
    res = to_string(res_v);
    return res;
}

int main(){
    vector<int> A{0,1,1,3,3,6,7},B{1,2,3,4,5,3,5};
    cout << solution(A, B) << endl;
}
