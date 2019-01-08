#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 
 二部グラフ判定
 
 build : falseならば二部グラフではない
 make : 色1となる頂点をlvへ、色-1となる頂点をrvへ格納
 
 */
class BipartiteGraph{
public:
    vector<vector<ll>> G; // グラフ
    ll N; // 頂点数
    vector<int> color; // 頂点iの色(1 or -1);
    
    vector<ll> lv,rv;
    BipartiteGraph(int _N):N(_N){ G.resize(N); color.resize(N,0); }
    BipartiteGraph(ll _N):N(_N){ G.resize(N); color.resize(N,0); }
    
    void init(ll _N){
        N = _N;
        G.clear(); color.clear();
        G.resize(N); color.resize(N,0);
    }
    
    void add_edge(ll u,ll v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    bool dfs(ll v,int c){
        color[v] = c; // 頂点vをcで塗る
        for(int i = 0; i < G[v].size(); i++){
            // 隣接している頂点が同じ色ならfalse
            if(color[G[v][i]] == c) return false;
            // 隣接している頂点がまだ塗られていないなら-cで塗る
            if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
        }
        // すべての頂点を濡れたらtrue
        return true;
    }
    
    bool build(){
        for(int i = 0; i < N;i++){
            if(color[i] == 0){
                // まだ頂点iが塗られていなければ1で塗る
                if(!dfs(i,1)) return false;
            }
        }
        return true;
    }
    
    void make(){
        for(int i = 0; i < N;i++){
            if(color[i] == 1) lv.push_back(i);
            if(color[i] == -1) rv.push_back(i);
        }
    }
};

class Family {
    public:
    string isFamily(vector <int> parent1, vector <int> parent2) {
        int n = (int)parent1.size();
        BipartiteGraph BG(n);
        for(int i = 0; i < n;i++){
            if(parent1[i] == -1) continue;
            BG.add_edge(parent1[i], parent2[i]);
        }
        
        if(BG.build()) return "Possible";
        else return "Impossible";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,-1,-1,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1,-1,0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(3, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, isFamily(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    Family ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
