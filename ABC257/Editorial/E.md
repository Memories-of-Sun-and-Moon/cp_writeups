# E - Addition and Multiplication 2

## 解説

桁数を最適化→その中で数値を最適化、という順番で考えたい。

### 桁数の最適化

桁数は N/(最小コスト) （切り捨て）となる。

### 2 数値の最適化

上位の桁から決めていく。1桁ずつ、「残りの桁をすべて最小コストの桁で埋めたときに、コスト N を超えないか」を調べ、条件を満たす数字がその桁となる。これを9から降順に調べる。

```C++
int N;
int C[10];

int main(){
    cin >> N;
    for(int i = 1;i <= 9;i++)cin >> C[i];
    LL minl = *min_element(C + 1, C + 10);
    int len = N / minl;

    string ans = "";

    REP(i, len){
        for(int j = 9;j >= 1;j--){
            if(minl * (len - i - 1) + C[j] <= N){
                N -= C[j];
                ans += char('0' + j);
                break;
            }
        }
    }
    cout << ans << endl;
}
```
