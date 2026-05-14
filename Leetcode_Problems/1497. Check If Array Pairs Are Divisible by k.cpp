// Given an array of integers arr of even length n and an integer k.

// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

// Return true If you can find a way to do that or false otherwise.

 

// Example 1:

// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// Output: true
// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
// Example 2:

// Input: arr = [1,2,3,4,5,6], k = 7
// Output: true
// Explanation: Pairs are (1,6),(2,5) and(3,4).
// Example 3:

// Input: arr = [1,2,3,4,5,6], k = 10
// Output: false
// Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
 

// Constraints:

// arr.length == n
// 1 <= n <= 105
// n is even.
// -109 <= arr[i] <= 109
// 1 <= k <= 105
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto x: arr){
            x=((x%k)+k)%k;
            mp[x]++;
        }
        if(mp.find(0)!=mp.end()){
            if(mp[0]%2!=0) return false;
            mp.erase(0);
        }
        for(auto x: mp){
            int ele=x.first;
            int rem=k-ele;
            if(mp.find(rem)==mp.end()) return false;
            if(mp[ele]!=mp[rem]) return false;
        }
       
        return true;
    }
};