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
 <url:https://yukicoder.me/problems/no/674>
 問題文============================================================
 A君は0日からD−1日までのD日間の間で仕事の予定が入ります。
 D日間の前後に仕事は無く最初はD日間の間にも仕事の予定はありません。
 
 これから仕事の予定がQ個入ります。
 i番目の仕事の予定はD日間の間でAi日目からBi日目までという形で入ります。
 仕事の予定が1つ以上入っている日はかならず出勤することになります。
 仕事が1つも無い日は出勤しません。
 
 例えば、0日目から3日目まで仕事の予定が入っていて4日目に仕事が無いと4連勤となります。
 仕事が入るたびにD日間の間に最大何連勤が存在するかを答えよ。

 Dは期間の日数。Dは整数。1≤D≤1000000000000000000=10^18。
 Qは仕事の予定の数。Qは整数。1≤Q≤30000=3×10^4。
 Ai、Biはi番目の指示での日目。Ai、Biは整数。0≤Ai≤Bi≤D−1。
 =================================================================
 解説=============================================================
 Dの値が大きいけれどQが高々30000なので、
 区間で処理する
 
 queueを使って区間を挿入したとき併合できるものがあれば併合する。
 なければそのまま挿入するなどをすれば良い。
 
 
 
 が、時間がギリギリだった。1977ms(よくよく考えたら同じ解法でもっと早くできるし、詰めがが甘かった）
 あとで解説読んだら想定解法は座圧＋平方分割でした。
 まぁ正解すれば正義。
 
 また、今回はqueueを使ったがsetを用いても同様の区間の処理が高速に行えることを知れた
 
 set<pair<long long,long long>>を用意し,初期集合として {-LINF,LINF},{LINF,LINF}を入れておく
 
 次にクエリをinsertし、その後、そのクエリを lower_boundなどを用いて場所を検索、
 前後に関して併合を行えば良い
 ================================================================
 */

void solve(){
    ll D,Q; scanf("%lld%lld",&D,&Q); // cin >> D >> Q;
    vector<ll> A(Q),B(Q);
    for(int i = 0; i < Q;i++){
        scanf("%lld%lld",&A[i],&B[i]);
    }
    queue<pll> q;
    for(int i = 0; i < Q;i++){
        int qs = (int)q.size();
        pll ap = {A[i],B[i]};
        
        bool f = false;
        for(int j = 0; j < qs; j++){
            auto p = q.front(); q.pop();
            if(f){ q.push(p); continue;}
            
            if(p.second+1 < ap.first){
                q.push(p);
                continue;
            }
            if(p.first-1 > ap.second){
                q.push(ap);
                q.push(p);
                f = true;
                continue;
            }
            
            ap.first = min(p.first,ap.first);
            ap.second = max(p.second,ap.second);
        }
        if(!f) q.push(ap);
        
        ll ans = -1;
        qs = int(q.size());
        while(qs--){
            auto p = q.front(); q.pop();
            ans = max(ans,p.second - p.first + 1);
            q.push(p);
        }
        
        printf("%lld\n",ans);
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
