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
 <url:https://yukicoder.me/problems/no/9>
 問題文============================================================
 HeliaはRPGゲームをしている。そのRPGゲームは味方のモンスターのレベル上げていきゲームを進めるゲームである。
 Heliaは手持ちにN匹のモンスターのパーティーがいてレベル上げしたいと思っている。
 
 レベル上げは、敵のモンスターと1対1で戦い、敵のレベルの半分小数切り捨てを獲得できる。
 （自分の戦ったモンスターのレベルに加算する）
 
 例えば、自分のモンスターのレベルが1で相手のモンスターのレベルが5の時、
 戦ったあと、自分のモンスターのレベルは3になる。
 戦いに関してはアイテムを駆使してでも勝つため、レベル差に関係なく勝てるとする。
 
 ここで、敵のモンスターが円状に時計回りに並んでいて、
 最初に戦うモンスターを決めると時計回りの順番に全員と一度だけ戦うことができる狩場がある。
 （最初に戦えるモンスターは自由に選べる）
 Heliaは、自分の手持ちのモンスターの中から、１戦毎、その時に一番レベルが低い、
 複数いる場合は、一番戦いをしてないモンスターを戦わせるとする。
 
 この狩場のモンスターを全て倒すとして、
 手持ちのパーティー中で戦闘回数が一番多い回数がもっとも低くなるよう狩場で最初に戦うモンスターを選んだとき、
 その中で一番戦闘回数が多い数を求めてください。
 
 =================================================================
 解説=============================================================
 全ての開始位置について
 愚直シミュレーションだとO(N^3)になって間に合わないが
 priority_queueなどで次に選ぶべきモンスターを洗濯すれば O(N^2 *logN)となる
 
 ================================================================
 */

ll solve(){
    ll res = LINF;
    ll N; cin >> N;
    vector<ll> A(N),B(N);
    for(auto& in:A) cin >> in;
    for(auto& in:B) cin >> in;
    
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++) pq.push({A[j],0});
        for(int j = 0; j < N;j++){
            pll p = pq.top(); pq.pop();
            p.first += B[(i+j)%N]/2; p.second++;
            pq.push(p);
        }
        ll t = 0;
        while(pq.size()){ t = max(t,pq.top().second); pq.pop(); }
        res = min(t,res);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
