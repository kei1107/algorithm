class Node {
public:
    int location;
    int p, l, r;
    Node() {}
};
 
class Point {
public:
    int id, x, y;
    Point() {}
    Point(int id, int x, int y) : id(id), x(x), y(y) {}
    bool operator < (const Point &p)const {
        return id < p.id;
    }
 
    void print() {
        printf("%d\n", id);
    }
};
 
static const int MAX = 1000000;
static const int NIL = -1;
 
int N;
Point P[MAX];
Node T[MAX];
int np;
 
bool lessX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}
 
bool lessY(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}
 
int makeKDTree(int l, int r, int depth) {
    if (!(l < r))return NIL;
    int mid = (l + r) / 2;
    int t = np++;
    if (depth % 2 == 0) {
        sort(P + l, P + r, lessX);
    } else {
        sort(P + l, P + r, lessY);
    }
    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth + 1);
    T[t].r = makeKDTree(mid + 1, r, depth + 1);
 
    return t;
}
 
void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans) {
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;
 
    if (sx <= x && x <= tx && sy <= y && y <= ty) {
        ans.push_back(P[T[v].location]);
    }
 
    if (depth % 2 == 0) {
        if (T[v].l != NIL) {
            if (sx <= x) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (x <= tx) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    } else {
        if (T[v].l != NIL) {
            if (sy <= y) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (y <= ty) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    }
}