/*
At any building, we can just find out the water stored above it and sum up all of them to get the total rain water trapped.
To find the height of water above each building, we have to find the maximum height of buildings to its left and right.
Now, water stored willl have a height of min(max to right, max to left) as water will flow out if we take the other way round.
Water above each building will be min(max to right, max to left) - height of that building.
Sum up the amount of water stored in all the buildings ans that will be the ans;
*/

class Solution {
public:
    int trap(vector<int>& height) {
        //@any i, find max height to the left and max height to its right (store in vectors mxr and mxl);
        //height above each building = min(mxr[i], mxl[i]) - height[i];
        //water trapped = sigma(height of water above each building);
        int n = height.size();
        vector<int> mxr(n);   //max height to right
        vector<int> mxl(n);   //max height to left
        
        //max to left (mxl vector)
        int prevmxl = INT_MIN;
        for (int i = 0; i<n; i++) {
            mxl[i] = max(prevmxl, height[i]);
            prevmxl = mxl[i];
        }
        
        //max to right (mxr vector)
        int prevmxr = INT_MIN;
        for (int i = n-1; i>=0; i--) {
            mxr[i] = max(prevmxr, height[i]);
            prevmxr = mxr[i];
        }
        int sum = 0;
        vector<int> water(n);
        for (int i = 0; i<n; i++) {
            water[i] = min(mxr[i], mxl[i]) - height[i];
            sum+=water[i];
        }
        return sum;
    }
};
