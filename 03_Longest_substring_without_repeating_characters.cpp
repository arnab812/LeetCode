int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0 || n==1)
            return n;
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int maxi = INT_MIN;
        while(j!=n)
        {
            if(mp.find(s[j])==mp.end() || (mp.find(s[j])!=mp.end() && mp[s[j]]==0)) //if not present in map or if present then have value 0, that means it is not in the substring
            {
                mp[s[j]]++;
                j++;
                maxi = max(maxi,j-i); // calculating the max value of substring whenever j increases.
            }
            else if(mp.find(s[j])!=mp.end() && mp[s[j]]>0) // if present in map then must have value greater than 0 to have in substring.
            {
                mp[s[i]]--;
                i++;
            }
        }
        return maxi;
        
    }
