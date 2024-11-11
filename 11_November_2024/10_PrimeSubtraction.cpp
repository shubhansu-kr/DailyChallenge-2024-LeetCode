// https://leetcode.com/problems/prime-subtraction-operation/?envType=daily-question&envId=2024-11-11

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    bool isprime(int num){
    if (num <= 1) return false;       
    if (num <= 3) return true;        
    if (num % 2 == 0 || num % 3 == 0) 
        return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
    }

    bool replace(int ind,int maxi,vector<int>&nums){
        for(int j=maxi;j>0;j--){
            if(isprime(nums[ind]-j)){
                nums[ind]=j;
                return true;
            }
        }
        return false;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0){
            if(nums[i]>=nums[i+1]){
                if(!replace(i,nums[i+1]-1,nums)){
                    return false;
                }
            }
            i--;
        }
        return true;
    }
};

int main () {
    
    return 0;
}
