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

struct LCA {
	int n;
	vector<vector<int>>g;
	int root;
	vector<int>depth;
	vector<vector<int>>par;

	void dfs(int v, int p, int d) {
		par[v][0] = p;
		depth[v] = d;
		for (int i = 0; i<g[v].size(); i++) {
			if (g[v][i] == p)continue;
			dfs(g[v][i], v, d + 1);
		}
	}

	LCA(int N,vector<int>* G,int Root) {
		n = N;
		g.resize(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < G[i].size(); j++) {
				g[i].emplace_back(G[i][j]);
			}
		}
		depth.resize(N);
		par.resize(N);
		for (int i = 0; i < N; i++)par[i].resize(31);
		root = Root;
		dfs(root, -1, 0);
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < N; j++) {
				if (par[j][i] == -1)par[j][i + 1] = -1;
				else par[j][i + 1] = par[par[j][i]][i];
			}
		}
	}

	int get(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int i = 30; i >= 0; i--) {
			if (((depth[v] - depth[u]) >> i) & 1) {
				v = par[v][i];
			}
		}
		if (u == v)return u;

		for (int i = 30; i >= 0; i--) {
			if (par[u][i] != par[v][i]) {
				u = par[u][i];
				v = par[v][i];
			}
		}
		return par[u][0];
	}
};

int n;
vector<int> g[202020];

void solve(){
    int k;
    cin >> k;
    vector<int> p(k);
    REP(i, k)cin >> p[i], p[i]--;
    vector<int> d(n, -1);

    queue<int> q;
    q.push(0);
    d[0] = 0;
    while(q.size()){
        int cur = q.front();
        q.pop();
        REP(j, (int)g[cur].size()){
            int nxt = g[cur][j];
            if(d[nxt] == -1){
                d[nxt] = d[cur] + 1;
                q.push(nxt);
            }
        }
    }
    int maxd = -1, maxi = -1;
    REP(i, k){
        if(d[p[i]] > maxd){
            maxd = d[p[i]];
            maxi = p[i];
        }
    }
    LCA lca(n, g, maxi);
    vector<pair<int, int>> v;
    REP(i, k)v.push_back({lca.depth[p[i]], p[i]});
    sort(ALL(v));
    REP(i, k - 1){
        int fir = v[i].second;
        int sec = v[i + 1].second;
        if(lca.depth[lca.get(fir, sec)] == lca.depth[fir])continue;
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int q;

int main(){
    cin >> n;
    REP(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    cin >> q;
    while(q--){
        solve();
    }
}