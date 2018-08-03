#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1590>
 問題文============================================================
 =================================================================
 解説=============================================================
 時間の早い順にクエリを見ていく、
 その時、これまでで辿りつけうる島をチェックしておく、
 島のチェックは橋を使う使わないを後で都合つければいい
 ================================================================
 */


ll solve(){
    ll res = -1;
    ll N,M; cin >> N >> M;
    vector<vector<pll>> G(N);
    using Event = tuple<ll,ll,ll>;
    vector<Event> E;
    for(int i = 0; i < M;i++){
        ll a,b,c; cin >> a >> b >> c;
        a--; b--;
        E.push_back(Event(a,b,c));
    }
    sort(E.begin(),E.end(),[](const Event & e1,const Event& e2){
        return std::get<2>(e1) < std::get<2>(e2);
    });
    
    
    vector<int> flag(N); flag[0] = 1;
    vector<Event> event;
    int idx = 0;
    ll nowT = 0;
    while(idx < M){
        ll a,b,c; tie(a,b,c) = E[idx++];
        if(nowT == c) {
            event.push_back(Event(a,b,c));
        }else{
            nowT = c;
            bool update = false;
            while(true){
                update = false;
                for(int i = 0; i < event.size();i++){
                    ll u,v,T; tie(u,v,T) = event[i];
                    if(flag[u]){
                        if(flag[v]){
                            if(v == N-1) res = max(res,T);
                            continue;
                        }else{
                            flag[v] = 1;
                            update = true;
                        }
                    }
                }
                if(update) continue;
                break;
            }
            event.clear();
            event.push_back(Event(a,b,c));
        }
    }
    bool update = false;
    while(true){
        update = false;
        for(int i = 0; i < event.size();i++){
            ll u,v,T; tie(u,v,T) = event[i];
            if(flag[u]){
                if(flag[v]){
                    if(v == N-1) res = max(res,T);
                    continue;
                    //event.erase(event.begin()+i);
                }else{
                    flag[v] = 1;
                    update = true;
                }
            }
        }
        if(update) continue;
        break;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
