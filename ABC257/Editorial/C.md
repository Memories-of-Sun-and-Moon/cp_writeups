# C - Robot Takahashi

## 解説

### 二分探索を行って求めるやり方

W_i の値中心に二分探索を行う。STLのイテレータの境界に注意。

```C++
int N;
string S;
int W[202020];

int main(){
    cin >> N;
    cin >> S;
    REP(i, N)cin >> W[i];
    vector<int> W_list, Adults, Children;
    REP(i, N){
        if(S[i] == '0')Children.push_back(W[i]);
        else Adults.push_back(W[i]);
    }
    Children.push_back(INF<int>());
    Children.push_back(-1);
    sort(W, W + N);
    sort(ALL(Children));
    sort(ALL(Adults));

    int ans = 0;
    REP(i, N){
        int num = 0;
        num += lower_bound(ALL(Children), W_list[i]) - Children.begin() - 1;
        num += Adults.end() - lower_bound(ALL(Adults), W_list[i]);
        chmax(ans, num);
    }
    int num = 0;
    num += lower_bound(ALL(Children), INF<int>()) - Children.begin() - 1;
    chmax(ans, num);
    cout << ans << endl;
}
```

### 尺取り法を用いて求めるやり方

境界が W_i なので、簡単に尺取り法で求められる

```C++
```
