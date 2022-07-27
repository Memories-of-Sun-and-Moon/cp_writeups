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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    REP(i, n)cin >> a[i] >> b[i], a[i]--, b[i]--;
    vector<vector<int>> numidx(n, vector<int>());
    REP(i, n){
        if(a[i] == b[i]){
            cout << "NO" << endl;
            return;
        }
        numidx[a[i]].push_back(i);
        numidx[b[i]].push_back(i);
    }
    REP(i, n)if(numidx[i].size() >= 3){
        cout << "NO" << endl;
        return;
    }

    vector<vector<int>> Graph(n, vector<int>());

    REP(i, n){
        Graph[numidx[i][0]].push_back(numidx[i][1]);
        Graph[numidx[i][1]].push_back(numidx[i][0]);
    }

    vector<int> color(n, -1);
    REP(i, n){
        if(color[i] != -1)continue;
        queue<pair<int, int>> q;
        q.push({i, 0});
        while(!q.empty()){
            int p = q.front().first;
            int col = q.front().second;
            q.pop();
            color[p] = col;
            REP(j, (int)Graph[p].size()){
                int nxt = Graph[p][j];
                if(color[nxt] == col){
                    cout << "NO" << endl;
                    return;
                }
                if(color[nxt] == -1){
                    q.push({nxt, !col});
                }
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int t;
int main(){
    cin >> t;
    while(t--)solve();
}