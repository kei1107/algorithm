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


class MultiplicationTable2 {
public:
    int minimalGoodSet(vector <int> table) {
        int nn = (int)table.size();
        int n = sqrt(nn);
        vector<vector<int>> mat(n,vector<int>(n));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                mat[i][j] = table[i*n+j];
            }
        }
        
        int res = n;
        vector<int> flag(n);
        for(int i = 0; i < n;i++){
            fill(flag.begin(),flag.end(),false);
            flag[i] = true;
            
            while(true){
                bool update = false;
                
                for(int j = 0; j < n;j++){
                    if(!flag[j]) continue;
                    for(int k = 0; k < n;k++){
                        if(!flag[k]) continue;
                        
                        if(!flag[mat[j][k]] || !flag[mat[k][j]]){
                            update = true;
                            flag[mat[j][k]] = flag[mat[k][j]] = true;
                            break;
                        }
                    }
                    if(update) break;
                }
                if(!update) break;
            }
            res = min(res,accumulate(flag.begin(),flag.end(),0));
        }
        
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,1,2,3,
        1,0,3,2,
        2,0,1,3,
        1,2,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalGoodSet(Arg0)); }
    void test_case_1() { int Arr0[] = {0,1,2,3,
        1,2,3,0,
        2,3,0,1,
        3,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimalGoodSet(Arg0)); }
    void test_case_2() { int Arr0[] = {1,1,1,1,
        2,2,2,2,
        3,3,3,3,
        0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimalGoodSet(Arg0)); }
    void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, minimalGoodSet(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    MultiplicationTable2 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
