#User function Template for python3

class Solution:
    def kTop(self,a, N, K):
        from collections import defaultdict
        ans=[]
        cnt=defaultdict(int)
        lst=[]
        for i,v in enumerate(a):
            cnt[v]+=1
            if cnt[v]==1:
                lst.append(v)
            lst.sort(key=lambda x:(-cnt[x],x))
            ans.append(lst[:min(K,i+1)])
        return ans


#{ 
 # Driver Code Starts


t=int(input())
for _ in range(0,t):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    ob = Solution()
    ans=ob.kTop(a,n,k)
    for line in ans:
        print(*line)



# } Driver Code Ends