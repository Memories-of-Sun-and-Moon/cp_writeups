# D - Jumping Takahashi 2

## 解説

二分探索で S を決め打ちし、その S をもとに、ある頂点からすべての頂点を見れるか全探索で求める

**境界条件を適当にしてしまったがためにミスが発生した。以後気を付けたい。**

```C++
int N;
LL x[202], y[202], P[202];

bool calc(LL S){
    vector<vector<int>> Graph(N);
    REP(i, N)REP(j, N){
        if(i == j)continue;
        if(P[i] * S >= abs(x[i] - x[j]) + abs(y[i] - y[j])){
            Graph[i].push_back(j);
        }
    }
    bool ret = false;
    REP(i, N){
        vector<bool> isok(N, false);
        isok[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            REP(j, (int)Graph[cur].size()){
                int nxt = Graph[cur][j];
                if(isok[nxt])continue;
                isok[nxt] = true;
                q.push(nxt);
            }
        }
        bool flg = true;
        REP(j, N)if(!isok[j])flg = false;
        if(flg)ret = true;
    }
    return ret;
}

int main(){
    cin >> N;
    REP(i, N)cin >> x[i] >> y[i] >> P[i];
    LL l = 0, r = 1000000000LL * 4LL + 1LL;
    while(r - l > 1){
        LL mid = (l + r) / 2;
        if(calc(mid))r = mid;
        else l = mid;
    }
    cout << r << endl;
}
```
