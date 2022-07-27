# Difference Array

## 解説

$a_i = 0$ となる項を除いて計算をすると， $1$ 回操作をするごとに，配列の総和は， $|配列の長さ| - 1$ 以上減る．配列の長さ，配列の総和の制約より， $0$ を含むパートを省略できれば，愚直にシミュレートすることで求めることができる．

操作の途中で $0, 0, 0, \cdots , 0, a_i, a_{i + 1}, a_{i + 2}, \cdots , a_{n}$ のような形になるが，後ろから数えて $2$ 番目以降の $0$ は，その回の操作には影響しないので省略する．

```C++
int n;
int a[505050];
int b[505050];
void solve(){
    cin >> n;
    REP(i, n)cin >> a[i];

    for(int i = n - 1;i >= 1;i--){
        int pre = a[i], tmp = -1;
        bool flg = false;
        for(int j = i - 1;j >= 0;j--){
            if(a[j] == 0)flg = true;
            tmp = a[j];
            a[j] = pre - a[j];
            pre = tmp;
            if(flg){
                sort(a + j, a + i + 1);
                break;
            }
        }
        if(!flg)sort(a, a + i + 1);
    }
    cout << a[0] << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}
```
