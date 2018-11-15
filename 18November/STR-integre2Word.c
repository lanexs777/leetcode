# 273
class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "zero";
        else return int_string(num).substr(1);
    }
    string int_string(int n) {
        if(n>=1000000000)   return int_string(n/1000000000)+" Billion"+int_string(n-1000000000*(n/1000000000));
        else if(n>=1000000) return int_string(n/1000000)+" Million"+int_string(n-1000000*(n/1000000));
        else if(n>=1000)    return int_string(n/1000)+" Thousand"+int_string(n-1000*(n/1000));
        else if(n>=100)     return int_string(n/100)+" Hundred"+int_string(n-100*(n/100));
        else if(n>=20)      return string(" ")+below_100[n/10-2]+int_string(n-10*(n/10));
        else if(n>=1)       return string(" ")+below_20[n-1];
        else return "";
    }
    string below_20[19] = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string below_100[9] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};
