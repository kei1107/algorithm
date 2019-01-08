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
class EmoticonsDiv1 {
    public:
    int printSmiles(int smiles) {
        int res = INF;
        vector<vector<int>> dist(2500,vector<int>(1500,INF));
        dist[1][0] = 0;
        queue<pii> q; q.push({1,0});
        while(q.size()){
            pii p = q.front(); q.pop();
            if(p.first >= 1000) continue;
            if(dist[p.first+p.second][p.second] > dist[p.first][p.second] + 1){
                dist[p.first+p.second][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first+p.second,p.second});
            }
            if(dist[p.first][p.first] > dist[p.first][p.second] + 1){
                dist[p.first][p.first] = dist[p.first][p.second] + 1;
                q.push({p.first,p.first});
            }
            if(p.first!=1 && dist[p.first-1][p.second] > dist[p.first][p.second] + 1){
                dist[p.first-1][p.second] = dist[p.first][p.second] + 1;
                q.push({p.first-1,p.second});
            }
        }
        for(int i = smiles; i < 2500; i++){
            for(int j = 0; j < 1500;j++){
                res = min(res,dist[i][j]+(i-smiles));
            }
        }
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, printSmiles(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; verify_case(1, Arg1, printSmiles(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; verify_case(2, Arg1, printSmiles(Arg0)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 8; verify_case(3, Arg1, printSmiles(Arg0)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 8; verify_case(4, Arg1, printSmiles(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    EmoticonsDiv1 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
