# include <iostream>
# include <string>
# include <vector>

int main(){
    std::string s;
    //vectorは第2引数で初期化する値を決められる。この場合だと、{0, 0, 0, ..., 0} になっている
    std::vector<int> count_alphabets(26, 0); 
    std::cin >> s;
    for(int idx = 0;idx < 3;idx++){
        // idx 文字目のアルファベットが何番目のアルファベットなのかを計算(0スタート)
        int alphabet_number = s[idx] - 'a';
        count_alphabets[alphabet_number]++;
    }
    bool flag = false;
    char ans;
    for(int i = 0;i < 26;i++){
        // i 番目のアルファベットが 1 個だけ出現したら、 ans に i 番目のアルファベットを書き込む
        if(count_alphabets[i] == 1){
            flag = true;
            // 文字列型なので、int を char にキャスト
            ans = char('a' + i);
        }
    }
    if(flag == true){
        std::cout << ans << std::endl;
    }else{
        std::cout << -1 << std::endl;
    }
}
