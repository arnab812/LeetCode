class Solution {
public:
    string longestPalindrome(string s) {
      int ans=INT_MIN;
         int start=0;
         int end=0;
         string res;
         
        int n=s.size();
        int dp[n][n];
         memset(dp,0,sizeof(dp));
         
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g; j<n; i++,j++)
            {
                if(g==0)
                {
                    dp[i][j]=1;
                }
                
                else if(g==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=1;
                    }
                    
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        
                        
                    }
                    
                    else
                    {
                         dp[i][j]=0;
                    }
                }
                
             
               if(dp[i][j]==1 && ans<j-i)
               {
                   ans=j-i;
                   start=i;
                   end=j-i;
               }
                
            }
        }
       
        
        return s.substr(start, end+1 );
    }
};
