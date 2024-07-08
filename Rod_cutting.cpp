   int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1,0);
        
        
        for(int i=1;i<=W;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(wt[j-1] <= i)
                  dp[i] = max(val[j-1] + dp[i-wt[j-1]] , dp[i]);
            }
        }
        
        return dp[W];
        
    }


    int cutRod(int price[], int n) {
        int len[n];
        
        for(int i=0;i<n;i++)
         len[i] = i+1;
         
        return knapSack(n,n,price,len);
    }
