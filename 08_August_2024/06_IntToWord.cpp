// https://leetcode.com/problems/integer-to-english-words/?envType=daily-question&envId=2024-08-07

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
string words(int n){
    vector<string> lastDigit = {
            "", "One ", "Two ", "Three ", "Four ", "Five ", 
            "Six ", "Seven ", "Eight ", "Nine ", "Ten ", 
            "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", 
            "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", 
            "Nineteen "
        };
        vector<string> tens = {
            "","Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", 
            "Sixty ", "Seventy ", "Eighty ", "Ninety "
        };
        string ans;
        if(n>99){
            string temp="";
            temp+=lastDigit[n/100] + "Hundred ";
            if((n%100) <= 19){
                temp+=lastDigit[n%100];
            }else{
            temp+=tens[(n/10)%10];
            temp+=lastDigit[n%10];
            }
            ans = temp; 
        }
        else if(n>=20 && n<=99){
            string temp="";
            temp+=tens[n/10];
            temp+=lastDigit[n%10];
            ans = temp;
        }else{
            ans = lastDigit[n];
        }
        
        return ans;
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        string ans="";
        int billions = num/1000000000;
        int millions = (num/1000000)%1000;
        int thousand = (num/1000)%1000;
        int hundred = num%1000;

        if(billions) ans+= words(billions) + "Billion ";
        if(millions) ans+= words(millions) + "Million ";
        if(thousand) ans+= words(thousand) + "Thousand ";
        if(hundred) ans+= words(hundred);
        
        if (!ans.empty()) {
            ans.erase(ans.size() - 1);
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    
    return 0;
}