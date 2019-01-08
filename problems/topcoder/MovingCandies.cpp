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

int dir[4] = {1,0,-1,0};
int dist[21][21][401];
using Item = tuple<int,int,int>;
class MovingCandies {
    public:
    int minMoved(vector <string> t) {
        fill(**dist,**dist+21*21*401,INF);
        int res = INF;
        int h = (int)t.size(),w = (int)t[0].size();
        if(t[0][0]=='.') dist[0][0][1] = 0;
        else dist[0][0][0] = 1;
        queue<Item> q; q.push(Item(0,0,(t[0][0]=='.')));
        while(q.size()){
            int y,x,cnt; tie(y,x,cnt) = q.front(); q.pop();
            if(cnt == w*h) continue;
            for(int k = 0; k < 4;k++){
                int ny = y + dir[k];
                int nx = x + dir[k^1];
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(t[ny][nx] == '.'){
                    if(dist[ny][nx][cnt+1] > dist[y][x][cnt]){
                        dist[ny][nx][cnt+1] = dist[y][x][cnt];
                        q.push(Item(ny,nx,cnt+1));
                    }
                }else{
                    if(dist[ny][nx][cnt] > dist[y][x][cnt]+1){
                        dist[ny][nx][cnt] = dist[y][x][cnt]+1;
                        q.push(Item(ny,nx,cnt));
                    }
                }
            }
        }

        int candy = 0;
        for(const string& str:t) candy += count(str.begin(),str.end(),'#');
        
        for(int i = 0; i <= w*h;i++){
            if(dist[h-1][w-1][i] + i <= candy) res = min(res,i);
        }
        if(res == INF) res = -1;
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"#...###",
"#...#.#",
"##..#.#",
".#....#"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minMoved(Arg0)); }
	void test_case_1() { string Arr0[] = {
"#...###",
"#...#.#",
"##..###",
".#....#"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minMoved(Arg0)); }
	void test_case_2() { string Arr0[] = {
".#..",
"##..",
"..#.",
"..#.",
"..##",
"..##"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minMoved(Arg0)); }
	void test_case_3() { string Arr0[] = {
".....",
".###.",
"####.",
"....."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minMoved(Arg0)); }
	void test_case_4() { string Arr0[] = {
".#...#.###.#",
"#.#.##......",
".#.#......#.",
"..#.......#.",
"##.........."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, minMoved(Arg0)); }
	void test_case_5() { string Arr0[] = {
"###.#########..#####",
".#######.###########"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, minMoved(Arg0)); }
	void test_case_6() { string Arr0[] = {
"..",
".."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, minMoved(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    MovingCandies ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
