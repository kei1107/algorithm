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
 <url:https://csacademy.com/contest/round-75/task/electric-cars/>
 問題文============================================================
 There are NN electric cars, each of them being characterised by one integer CC,
 representing the capacity of the battery.
 In order to charge the car's battery,
 each car will come to the only charging station which can charge 11 unit of energy per second.
 If multiple cars want to charge at the same time,
 the charging station will only charge one car, the car that appears first in the input.
 
 Knowing for each car the time TT when it arrives at the charging station,
 compute the time when the car will be fully charged. Find this value for each car.
 
 =================================================================
 解説=============================================================
 
  index番号についてpriority_queueを用いる
 
 最初、時間順にindexを見ていく、
 この時、今見ているindexの時間を超えないように
 priority_queueに入っているクエリを順番に処理していく
 （priority_queueにindex番号だけではなく、残余バッテリーも保管しておくと良い）
 
 処理できるだけ処理を行ったら、今見ているindex番号を新たにqueueに加える、
 という動作をN回繰り返す。
 
 その後queueにまだクエリが残っているようであれば、
 あとは新たに車が入ってくることがないので、queue から出てくる順番nに処理していけば良い
 ================================================================
 */

struct Car{
    ll id, T, Cap;
    bool operator < (const Car& o) const{
        return id < o.id;
    }
    bool operator > (const Car& o) const{
        return id > o.id;
    }
};

void solve(){
    ll N; cin >> N;
    vector<Car> Cars(N);
    for(int i = 0; i < N;i++){
        ll C,T; cin >> C >> T;
        Cars[i].id = i;
        Cars[i].Cap = C;
        Cars[i].T = T;
    }
    
    sort(Cars.begin(),Cars.end(),[](const Car& c1,const Car& c2){
        return c1.T < c2.T;
    });
    
    priority_queue<Car,vector<Car>,greater<Car>> pq;
    vector<ll> ans(N);
    
    ll nowT = 0;
    for(auto& c: Cars){
        ll nextT = c.T;
        while(pq.size() && nextT != nowT){
            auto p = pq.top(); pq.pop();
            
            ll difT = min(p.Cap,nextT - nowT);
            p.Cap -= difT;
            nowT += difT;
            if(p.Cap == 0){
                ans[p.id] = nowT;
            }else{
                pq.push(p);
            }
        }
        
        pq.push(c);
        nowT = nextT;
    }
    while(pq.size()){
        auto p = pq.top(); pq.pop();
        ans[p.id] = nowT + p.Cap;
        nowT += p.Cap;
    }
    
    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
