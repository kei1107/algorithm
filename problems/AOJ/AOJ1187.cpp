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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1187&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 条件に合うようなデータ構造を作ってシミュレーション
 ================================================================
 */
int M,T,P,R;
struct Team{
    int id;
    int correct;
    int penalty;
    vector<int> accept;
    vector<int> wrong;
    Team(){};
    Team(int id,int P):id(id),accept(P),wrong(P),correct(0),penalty(0){}
    void AC(int P,int time){
        if(accept[P]) return;
        accept[P] = 1;
        penalty += wrong[P]*20 + time;
        correct++;
        return;
    }
    void WA(int P){
        wrong[P]++;
    }
    bool operator < (const Team& o)const {
        return correct!=o.correct?correct>o.correct:penalty!=o.penalty?penalty<o.penalty:id>o.id;
    }
};
void solve(){
    vector<Team> info(T);
    for(int i = 0; i < T;i++) info[i] = Team(i,P);
    for(int i = 0; i < R;i++){
        int tid,pid,time,msg;
        cin >> time >> tid >> pid >> msg;
        tid--; pid--;
        if(msg == 0){
            info[tid].AC(pid,time);
        }else{
            info[tid].WA(pid);
        }
    }
    sort(info.begin(),info.end());
    info.push_back(Team(INF,P)); info.rbegin()->penalty = INF;
    for(int i = 0; i < T;i++){
        cout << info[i].id+1;
        if(i+1==T) {cout << endl;}
        else if(info[i].correct > info[i+1].correct) cout << ",";
        else if(info[i].penalty < info[i+1].penalty) cout << ",";
        else cout << "=";
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> M >> T >> P >> R,M){
        solve();
    }
    return 0;
}
