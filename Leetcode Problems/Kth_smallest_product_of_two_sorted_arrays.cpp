#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// More Efficient Solution

class Solution {
public:
    using ll = long long;
    bool isPossible(ll x, vector<int>& nums1, vector<int>& nums2, ll k){
        int n1 = nums1.size();
        int n2 = nums2.size();
        ll count=0;
        for(int i=0;i<n1;i++){
            if(nums1[i]<0){
                ll rem = ceil((double)x/nums1[i]);
                int ind = lower_bound(nums2.begin(), nums2.end(), rem)-nums2.begin();
                count += (n2-ind);
            }else if(nums1[i]>0){
                ll rem = floor((double)x/nums1[i]);
                int ind = upper_bound(nums2.begin(), nums2.end(), rem)-nums2.begin();
                count += ind;
            }else{
                if(x>=0){
                    count += n2;
                }
            }
            if(count>=k) return true;
        }
        return count>=k;
    }
    ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        ll low = -1e10;
        ll high = 1e10;
        ll ans=0;
        while(low<=high){
            ll mid = low+(high-low)/2;
            if(isPossible(mid, nums1, nums2, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};

/*class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProducts(nums1, nums2, mid) < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    long long countProducts(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;
        for (int num1 : nums1) {
            if (num1 == 0) {
                if (target >= 0) count += nums2.size();
                continue;
            }

            int low = 0, high = nums2.size();
            while (low < high) {
                int mid = (low + high) / 2;
                long long prod = 1LL * num1 * nums2[mid];
                if (prod <= target) {
                    if (num1 > 0) low = mid + 1;
                    else high = mid;
                } else {
                    if (num1 > 0) high = mid;
                    else low = mid + 1;
                }
            }

            count += (num1 > 0) ? low : (nums2.size() - low);
        }
        return count;
    }
};
*/