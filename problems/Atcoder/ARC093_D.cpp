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
 <url:https://arc093.contest.atcoder.jp/tasks/arc093_b>
 問題文============================================================
 2 つの整数 A,B が与えられます。
 
 各マスが白または黒に塗られたグリッドであって以下の条件を満たすものを、
 出力の項で指定されたフォーマットに従って一つ出力してください。
 
 グリッドの大きさを縦 h 行横 w 列としたとき、h および w はともに 100 以下である。
 白く塗られたマスの集合はちょうど A 個の連結成分に分かれている (連結成分という単語の定義については後の注釈を参照)。
 黒く塗られたマスの集合はちょうど B 個の連結成分に分かれている。
 制約の項で指定される条件のもとで解は必ず一つ以上存在することが証明できます。 解が複数ある場合、どれを出力しても構いません。
 =================================================================
 
 解説=============================================================
 
 100x100 全てを使って、
 上半分を白、下半分を黒で塗りつぶす
 
 あとは
 黒の数を増やしたい => 上半分をぽちぽち塗りつぶす
 白の数を増やしたい => 下半分をぽちぽち塗りつぶす
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll A,B; cin >> A >> B;
    if(A == 0){
        cout << 1 << " " << 1 << endl;
        cout << "#" << endl;
        return 0;
    }
    if(B == 0){
        cout << 1 << " " << 1 << endl;
        cout << "." << endl;
        return 0;
    }
    vector<vector<char>> masu(110,vector<char>(110,'.'));
    for(int i = 0; i < 50;i++){
        for(int j = 0; j < 100;j++){
            masu[i][j] = '.';
        }
    }
    for(int i = 50; i < 100;i++){
        for(int j = 0; j < 100;j++){
            masu[i][j] = '#';
        }
    }
    A--; B--;
    [&]{
        for(int i = 0; i < 25;i++){
            for(int j = 0; j < 100; j+=2){
                if(B!=0){
                    B--;
                    masu[2*i][j] = '#';
                }else{
                    return;
                }
            }
        }
    }();
    [&]{
        for(int i = 0; i < 25;i++){
            for(int j = 0; j < 100; j += 2){
                if(A!=0){
                    A--;
                    masu[2*i+51][j] = '.';
                }else{
                    return;
                }
            }
        }
    }();
    cout << 100 << " " << 100 <<endl;
    for(int i = 0;i  < 100;i++){
        for(int j = 0; j < 100;j++){
            cout << masu[i][j];
        }
        cout << endl;
    }
    return 0;
}

