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
class GridSortMax {
    public:
    string findMax(int n, int m, vector <int> grid) {
        string res;
        vector<vector<int>> G(n,vector<int>(m));
        auto NGG = G;
        for(int i = 0; i < n;i++) for(int j = 0; j < m;j++) G[i][j] = grid[i*m+j];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                int target = i*m + j + 1;
                
                int ni = -1, nj = -1;
                for(int ii = 0; ii < n; ii++){
                    for(int jj = 0; jj < m; jj++){
                        if(G[ii][jj] == target) {
                            ni = ii;
                            nj = jj;
                        }
                    }
                }
                bool ng = false;
                if(i != ni){
                    for(int k = 0; k < m;k++){
                        ng |= NGG[i][k] && G[i][k] < target;
                        ng |= NGG[ni][k] && G[ni][k] < target;
                    }
                }
                if(j != nj){
                    for(int k = 0; k < n;k++){
                        ng |= NGG[k][j] && G[k][j] < target;
                        ng |= NGG[k][nj] && G[k][nj] < target;
                    }
                }
                res += to_string(!ng);
                if(ng) continue;
                
                if(i != ni){
                    for(int k = 0; k < m;k++){
                        swap(G[i][k],G[ni][k]);
                    }
                }
                if(j != nj){
                    for(int k = 0; k < n;k++){
                        swap(G[k][j],G[k][nj]);
                    }
                }
                NGG[i][j] = true;
            }
        }
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {
 1,2,
 3,4
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1111"; verify_case(0, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {
 2,1,
 3,4
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1100"; verify_case(1, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {
 4,2,
 3,1
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1001"; verify_case(2, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 10; int Arr2[] = {10,6,2,3,5,7,1,9,4,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1111111111"; verify_case(3, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {
 5,2,10,7,9,
 3,4,14,11,1,
 15,12,6,8,13
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "101100100100000"; verify_case(4, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 6; int Arg1 = 2; int Arr2[] = {
 3,9,
 5,1,
 10,6,
 2,7,
 8,11,
 12,4
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "100000101010"; verify_case(5, Arg3, findMax(Arg0, Arg1, Arg2)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    GridSortMax ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
