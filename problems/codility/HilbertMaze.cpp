#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}


typedef pii Point;
int operator - (Point l,Point r){
    return abs(l.first-r.first) + abs(l.second - r.second);
}
struct Maze{
    Point lowerLeft,upperRight;
};
enum Orientation{
    Up, Right, Down, Left
};

Orientation mazeOrientations[] = {Up , Up , Left, Right, Up, Up, Left, Right};

Orientation operator + (Orientation left,Orientation right){
    return Orientation((int(left) + int(right))%4);
}

struct OrientedMaze{
    Maze maze;
    Orientation orientation;
    
    OrientedMaze smallerMaze(Point point){
        int midX = (maze.lowerLeft.first + maze.upperRight.first)/2;
        int midY = (maze.lowerLeft.second + maze.upperRight.second)/2;
        
        if(point.first <= midX && point.second <= midY){
            
            return OrientedMaze{Maze{maze.lowerLeft,Point(midX,midY)},mazeOrientations[(7-(int)orientation)%4] + orientation};
        }
        
        if(point.first <= midX && point.second > midY){
            return OrientedMaze{Maze{Point(maze.lowerLeft.first,midY),Point(midX,maze.upperRight.second)},mazeOrientations[(4-(int)orientation)%4] + orientation};
        }
        
        if(point.first > midX && point.second <= midY){
            return OrientedMaze{Maze{Point(midX,maze.lowerLeft.second),Point(maze.upperRight.first,midY)},mazeOrientations[(6-(int)orientation)%4] + orientation};
        }
        
        if(point.first > midX && point.second > midY){
            return OrientedMaze{Maze{Point(midX,midY),maze.upperRight},mazeOrientations[(5-(int)orientation)%4] + orientation};
        }
        
        return OrientedMaze{Maze{Point(),Point()},Up};
        
    }
    
    Point moveOut(Point point){
        if(point.first == maze.lowerLeft.first || point.first == maze.upperRight.first || point.second == maze.lowerLeft.second || point.second == maze.upperRight.second) return point;
        
        int midX = (maze.lowerLeft.first + maze.upperRight.first)/2;
        int midY = (maze.lowerLeft.second + maze.upperRight.second)/2;
        
        switch(orientation){
            case Up:
                return point.second <= midY ? Point(midX,maze.lowerLeft.second) : Point(midX,maze.upperRight.second);
                break;
            case Right:
                return point.first <= midX ? Point(maze.lowerLeft.first,midY) : Point(maze.upperRight.first,midY);
                break;
            case Left:
                return point.first >= midX ? Point(maze.upperRight.first,midY) : Point(maze.lowerLeft.first,midY);
                break;
            case Down:
                return point.second >= midY ? Point(midX,maze.upperRight.second) : Point(midX,maze.lowerLeft.second);
                break;
        }
        return Point();
    }
};

int solution(int N, int A, int B, int C, int D){
    
    Point pointF = {A,B};
    Point pointS = {C,D};
    
    if(pointF == pointS) return 0;
    
    int basicMazeSize = 1<<(N+1);
    Maze basicMaze{Point(0,0),Point(basicMazeSize,basicMazeSize)};
    
    vector<OrientedMaze> mazesF{OrientedMaze{basicMaze,Up}},mazesS{OrientedMaze{basicMaze,Up}};
    
    int i = 1;
    while(i < N){
        mazesF.push_back(mazesF.back().smallerMaze(pointF));
        mazesS.push_back(mazesS.back().smallerMaze(pointS));
        i += 1;
    }
    
    vector<Point> moveOutF{pointF},moveOutS{pointS};
    
    for(int i = (int)mazesF.size()-1; i >= 0; i--){
        moveOutF.push_back(mazesF[i].moveOut(moveOutF.back()));
        moveOutS.push_back(mazesS[i].moveOut(moveOutS.back()));
    }
    
    int commonPoint = -1;
    i = 0;
    while(i < (int)moveOutF.size() && commonPoint == -1){
        if(moveOutF[i] == moveOutS[i]){
            commonPoint = i;
        }
        i += 1;
    }
    
    int distance = 0;
    
    if(commonPoint > -1){
        int sz = (int)moveOutS.size();
        for(int _ = commonPoint; _ < sz; _++){
            moveOutF.pop_back();
            moveOutS.pop_back();
        }
        distance = moveOutF.back() - moveOutS.back();
    }else{
        Point endPointF = moveOutF.back();
        Point endPointS = moveOutS.back();
        
        int minXF = min(endPointF.first,basicMazeSize - endPointF.first);
        int minXS = min(endPointS.first,basicMazeSize - endPointS.first);
        
        int minYF = min(endPointF.second,basicMazeSize - endPointF.second);
        int minYS = min(endPointS.second,basicMazeSize - endPointS.second);
        
        int minX = 2 * min(minXF,minXS) * (endPointF.second == endPointS.second ? 0 : 1);
        int minY = 2 * min(minYF,minYS) * (endPointF.first == endPointS.first ? 0 : 1);
        distance = (endPointF - endPointS) + minX + minY;
    }
    i = (int)moveOutF.size() - 2;
    
    while(i > -1){
        distance += (moveOutF[i] - moveOutF[i+1]) + (moveOutS[i] - moveOutS[i+1]);
        i--;
    }
    return distance;
}
