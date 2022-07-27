# Split Into Two Sets

## 解説

**$a_i = b_i$ が入力として与えられるので，注意**

**また，同じ数字が $3$ つ以上与えられたとき，必ず ``NO`` となるので，注意**

以下，同じ数字は $2$ つ以下しか与えられないものとする．

ドミノの添え字を頂点としたグラフを考える．

同じ数字が書いてある $2$ ドミノ間に辺を張り，二部グラフができれば ``YES``

そうでなければ ``NO`` となる

```C++
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
```