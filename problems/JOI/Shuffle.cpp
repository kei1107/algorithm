#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
 <url:https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t5/2009-yo-t5.html>
 問題文============================================================
 シャッフル(x,y)
 n(<=10^9) 枚のカードを，
 一番上から x 枚目までのカードからなる山A，
 x+1 枚目から y 枚目のカードからなる山B，
 y+1 枚目から n 枚目のカードからなる山C の3つの山に分ける．
 そして，山Aの上に山Bを重ね，さらにその上に山Cを重ねる．
 
 という動作をm(<=5000)回した時
 
 上から数えて p 枚目から q 枚目のカードの中に含まれている番号が r 以下のカードの枚数を出力せよ．
 
 =================================================================
 解説=============================================================
 
 制約が大きいので、カードの順番の情報を貪欲に持っておくことができない。
 
 よって、カードの持ち方を工夫して一定の束として持っておくことを考える
 例えば、入力１の場合だと
 初期状態　[1,9]
 shuffle(3,5) => [6,3枚], [3,2枚] , [1,3枚]
 といった風になる。こうすれば一回のシャッフルで束が高々３つに増えるといった操作になり、
 シャッフルの回数が最大5000回だということに注目すれば 最大の束の数は 3*5000 枚となり、十分管理できる。
 
 あとはシャッフルごとに束をシミュレートして行き、最後に答えの枚数を数え上げれば間に合う
 
 TL 10sだし、シミュレートはO(n)で十分間に合う
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n,m;
    while(cin >> n,n){
        cin >> m;
        int p,q,r; cin >> p >> q >> r;
        queue<pii> sec; sec.push(pii(1,n));
        
        vector<pii> A,B,C;
        int CntA,CntB,CntC;
        for(int _ = 0; _ < m; _++){
            A.clear(); B.clear(); C.clear();
            int x,y; cin >> x >> y;
            CntA = x; CntB = y-x; CntC = n-y;
            while(!sec.empty()){
                pii s = sec.front(); sec.pop();
                while(s.second != 0){
                    if(CntA != 0){
                        A.push_back(pii(s.first,min(CntA,s.second)));
                        if(CntA >= s.second){
                            CntA -= s.second;
                            s.first += s.second; s.second = 0;
                        }else{
                            s.first += CntA;
                            s.second -= CntA; CntA = 0;
                        }
                    }else if(CntB != 0){
                        B.push_back(pii(s.first,min(CntB,s.second)));
                        if(CntB >= s.second){
                            CntB -= s.second;
                            s.first += s.second; s.second = 0;
                        }else{
                            s.first += CntB;
                            s.second -= CntB; CntB = 0;
                        }
                    }else{
                        C.push_back(pii(s.first,min(CntC,s.second)));
                        if(CntC >= s.second){
                            CntC -= s.second;
                            s.first += s.second; s.second = 0;
                        }else{
                            s.first += CntC;
                            s.second -= CntC; CntC = 0;
                        }
                    }
                }
            }
            
            for(auto s:C) sec.push(s);
            for(auto s:B) sec.push(s);
            for(auto s:A) sec.push(s);
        }
        
        int ans = 0;
        int l = 1;
        while(!sec.empty()){
            pii s = sec.front(); sec.pop();
            for(int i = 0; i < s.second; i++){
                if(p <= l && l <= q){
                    if(i + s.first <= r){
                        ans++;
                    }
                }
                l++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
