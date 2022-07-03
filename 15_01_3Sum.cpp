class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
          sort(arr.begin(),arr.end());
     set<vector<int>> v;
     for(int i=0;i<n-1;i++){
        vector<int> v1;
        int c=arr[i];
        int a=i+1,b=n-1;
        while(a<b){
          if(arr[a]+c+arr[b]==0){
             v1.push_back(c);
             v1.push_back(arr[a]);
             v1.push_back(arr[b]);
             v.insert(v1);
             v1.clear();
             b--;
          }
          else if(arr[a]+c+arr[b]>0)
          {
            b--;
          }
          else{
            a++;
          }
        }
     }

     vector<vector<int>> ans;

     for(auto x:v){
        vector<int> aa;
        for(auto y:x){
           aa.push_back(y);
        }
        ans.push_back(aa);
     }
        return ans;
    }
};
