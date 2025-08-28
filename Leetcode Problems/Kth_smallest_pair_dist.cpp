#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Random Approach

class Solution {
public:
    
    int helper(vector<int>&nums,int k,int mid)          // mid means target
    {
        int count = 0;
        int j = 0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            while(j<n && (nums[j]-nums[i])<=mid)
            {
                j++;
            }
            
            count += (j-i-1);               // (j-i-1) ae ind. i thi start thati valid pairs che
        }

        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int low = 0;
        int high = nums[n-1]-nums[0];
        int ans = -1;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            int count = helper(nums,k,mid);

            if(count>=k)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }
};

// Binary Search + DP Approach

/*class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int arraySize = nums.size();

        // Largest element in the sorted array
        int maxElement = nums[arraySize - 1];

        // Maximum possible distance
        int maxPossibleDistance = maxElement * 2;

        // Initialize arrays for prefix counts and value counts
        vector<int> prefixCount(maxPossibleDistance, 0);
        unordered_map<int, int> valueCount;

        // Populate the prefixCount array
        int index = 0;
        for (int value = 0; value < maxPossibleDistance; ++value) {
            while (index < arraySize && nums[index] <= value) {
                ++index;
            }
            prefixCount[value] = index;
        }

        // Populate the valueCount map
        for (int i = 0; i < arraySize; ++i) {
            ++valueCount[nums[i]];
        }

        // Binary search for the k-th smallest distance
        int low = 0, high = maxElement;
        while (low < high) {
            int mid = (low + high) / 2;

            // Count pairs with distance <= mid
            int count = countPairs(nums, prefixCount, valueCount, mid);

            // Adjust binary search bounds based on count
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

private:
    // Count number of pairs with distance <= m
    int countPairs(vector<int>& nums, vector<int>& prefixCount,
                   unordered_map<int, int>& valueCount, int maxDistance) {
        int count = 0;
        int arraySize = nums.size();
        int index = 0;

        while (index < arraySize) {
            int currentValue = nums[index];
            int valueCountForCurrent = valueCount.at(currentValue);

            // Calculate pairs involving current value with distance <=
            // maxDistance
            int pairsWithLargerValues =
                prefixCount[currentValue + maxDistance] -
                prefixCount[currentValue];
            int pairsWithSameValues =
                valueCountForCurrent * (valueCountForCurrent - 1) / 2;

            count += pairsWithLargerValues * valueCountForCurrent +
                     pairsWithSameValues;

            // Skip duplicate values
            while (index + 1 < arraySize && nums[index] == nums[index + 1]) {
                ++index;
            }
            ++index;
        }
        return count;
    }
};*/

// Bucket Sort Approach

/*class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int arraySize = nums.size();

        // Find the maximum element in the array
        int maxElement = *max_element(nums.begin(), nums.end());

        // Initialize a bucket array to store counts of each distance
        vector<int> distanceBucket(maxElement + 1, 0);

        // Populate the bucket array with counts of each distance
        for (int i = 0; i < arraySize; ++i) {
            for (int j = i + 1; j < arraySize; ++j) {
                // Compute the distance between nums[i] and nums[j]
                int distance = abs(nums[i] - nums[j]);

                // Increment the count for this distance in the bucket
                ++distanceBucket[distance];
            }
        }

        // Find the k-th smallest distance
        for (int dist = 0; dist <= maxElement; ++dist) {
            // Reduce k by the number of pairs with the current distance
            k -= distanceBucket[dist];

            // If k is less than or equal to 0, return the current distance
            if (k <= 0) {
                return dist;
            }
        }
        return -1;  // Return -1 if no distance found, should not reach here
    }
};*/

int main(){
    Solution sol;
    vector<int> nums = {1,5};
    cout<<sol.smallestDistancePair(nums, 1);
    return 0;
}