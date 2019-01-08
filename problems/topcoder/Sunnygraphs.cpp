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
class Sunnygraphs {
public:
    long long count(vector <int> a) {
        ll res = 0;
        
        int n = (int)a.size();
        vector<vector<int>> G(n);
        for(int i = 0; i < n;i++) G[i].push_back(a[i]);
        vector<int> zero(n),one(n);
        queue<int> q; q.push(0);
        while(q.size()){
            int v = q.front(); q.pop();
            zero[v] = true;
            for(auto next:G[v]){
                if(!zero[next]) q.push(next);
            }
        }
        q.push(1);
        while(q.size()){
            int v = q.front(); q.pop();
            one[v] = true;
            for(auto next:G[v]){
                if(!one[next]) q.push(next);
            }
        }
        
        int cnt[4] = {};
        for(int i = 0; i < n;i++){
            cnt[zero[i]+2*one[i]]++;
        }
        
        res += ((1LL<<cnt[1])-1)*((1LL<<cnt[3])-1);
        res += ((1LL<<cnt[2])-1)*((1LL<<cnt[3])-1);
        res += ((1LL<<cnt[1])-1)*((1LL<<cnt[2])-1)*(1LL<<cnt[3]);
        
        if(cnt[3]>=2){
            res += (1LL<<cnt[3]);
        }
        res *= (1LL<<cnt[0]);
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
    void test_case_1() { int Arr0[] = {2,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(1, Arg1, count(Arg0)); }
    void test_case_2() { int Arr0[] = {2,3,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(2, Arg1, count(Arg0)); }
    void test_case_3() { int Arr0[] = {2,2,3,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 30LL; verify_case(3, Arg1, count(Arg0)); }
    void test_case_4() { int Arr0[] = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2198754820096LL; verify_case(4, Arg1, count(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    Sunnygraphs ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
