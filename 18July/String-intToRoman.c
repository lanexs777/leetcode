#12
// 本題關鍵是找出他的分界點，當數字到某值時應該轉換表示方式
// 分界點是 1 4 5 9  10 40 50 90 100 400 500 900 1000

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while (num != 0){
            // 1000
            if (num / 1000 != 0){
                int copy = num / 1000;
                num = num % 1000;
                for (int i = 0; i < copy; i++){
                    ans += "M";
                }
            }
            // 900
            else if (num / 900 != 0){
                int copy = num / 900;
                num = num % 900;
                for (int i = 0; i < copy; i++){
                    ans += "CM";
                }
            }
            // 500
                else if (num / 500 != 0){
                int copy = num / 500;
                num = num % 500;
                for (int i = 0; i < copy; i++){
                    ans += "D";
                }
            }
            // 400
            else if (num / 400 != 0){
                int copy = num / 400;
                num = num % 400;
                for (int i = 0; i < copy; i++){
                    ans += "CD";
                }
            }
            // 100
                else if (num / 100 != 0){
                int copy = num / 100;
                num = num % 100;
                for (int i = 0; i < copy; i++){
                    ans += "C";
                }
            }
            // 90
                else if (num / 90 != 0){
                int copy = num / 90;
                num = num % 90;
                for (int i = 0; i < copy; i++){
                    ans += "XC";
                }
            }
            // 50
                else if (num / 50 != 0){
                int copy = num / 50;
                num = num % 50;
                for (int i = 0; i < copy; i++){
                    ans += "L";
                }
            }
            // 40
                else if (num / 40 != 0){
                int copy = num / 40;
                num = num % 40;
                for (int i = 0; i < copy; i++){
                    ans += "XL";
                }
            }
            // 10
                else if (num / 10 != 0){
                int copy = num / 10;
                num = num % 10;
                for (int i = 0; i < copy; i++){
                    ans += "X";
                }
            }
            // 9
                else if (num / 9 != 0){
                int copy = num / 9;
                num = num % 9;
                for (int i = 0; i < copy; i++){
                    ans += "IX";
                }
            }
            // 5
                else if (num / 5 != 0){
                int copy = num / 5;
                num = num % 5;
                for (int i = 0; i < copy; i++){
                    ans += "V";
                }
            }
            // 4
                else if (num / 4 != 0){
                int copy = num / 4;
                num = num % 4;
                for (int i = 0; i < copy; i++){
                    ans += "IV";
                }
            }
            // 1 
                else {
                    int copy = num / 1;
                    num = num % 1;
                    for (int i = 0; i < copy; i++){
                        ans += "I";
                }
        }
    }
        return ans;
    }
};
