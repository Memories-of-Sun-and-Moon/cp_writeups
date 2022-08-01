#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

struct INIT{
    INIT(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
}INIT;

struct UnionFind {
	UnionFind(size_t size){
        for(int i = 0;i < (int)size;i++){
            par.emplace_back(i);
            rnk.emplace_back(0);
        }
    }
	vector<int> par, rnk;

    int root(int x){
        if(par[x] == x)return x;
        else return par[x] = root(par[x]);
    }

    bool is_root(int x){
        return root(x) == x;
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y)return;
        if(rnk[x] < rnk[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rnk[x] == rnk[y])rnk[x]++;
        }
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
};

int n, q;
int l[202020], r[202020];

int main(){
    cin >> n >> q;
    UnionFind uf(n + 1);
    REP(i, q){
        cin >> l[i] >> r[i];
        l[i]--;
        uf.unite(l[i], r[i]);
    }

    cout << (uf.same(0, n) ? "Yes" : "No") << endl;
}