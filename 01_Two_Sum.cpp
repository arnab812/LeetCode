#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    class Solution 
    {
        public:
        vector<int> twoSum(vector<int> & nums, int target)
        { 
            // "twoSum" is a function, which requires a vector of int as the answer. 'nums' is an array.
            // the vector (the initial one) will store the pair of index (with the help of 'nums') which will give the sum as target. [pair]
            
            vector<int> ans;
            // declaring a hash-table 
            unordered_map<int, int> mpp; // hash-table -> key : value
            
            // traversing the 'nums' array -> 
            for(int i = 0; i < nums.size(); i++)
            {
                if(mpp.find(target - nums[i]) != mpp.end()) // condition signifies that the element  *****                                                        // is found -> 
                {
                    ans.push_back(mpp[target - nums[i]]); // gets the value or index and stores in the 'ans' vector.                                               // the vector
                    ans.push_back(i); // current index.
                }
                // else -> [when the element is not found]
                mpp[nums[i]] = i; // 'i' is the index. 
                //   key  :  value
            }
            // Once the iteration is over, we can get the pair.
            return ans;
            // Else, we can return 'ans', which is an empty vector, suggesting there is no possible pair.
        }
    };

    return 0;
}

/*

***** Notes :-
                1. Vectors in C++
                2. Pairs
                3. Hash map.
                4. vector<int> vs vector <int> & 
                   When you pass vector<int> then function gets a copy of that vector.
                   You can do anything you want with it in the function and your original data would not change.
                   When you pass vector<int>& then function gets the reference which means that any changes in the function would modify the original data.
                5. ***** C++ map find() function is used to find an element with the given key value k.
                   If it finds the element then it returns an iterator pointing to the element. Otherwise,
                   it returns an iterator pointing to the end of the map, i.e., map::end().

*/
