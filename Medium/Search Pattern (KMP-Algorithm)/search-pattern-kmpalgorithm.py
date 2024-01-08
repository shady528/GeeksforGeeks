#User function Template for python3

class Solution:
    def search(self, pat, txt):
        # code here
        ans = []
        low =0
        high = len(pat)
        while high<=len(txt):
            if txt[low]==pat[0]:
                if txt[low:high] == pat:
                    ans.append(low+1)
            high+=1
            low+=1

        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        if len(ans)==0:
            print(-1,end="")
        for value in ans:
            print(value,end = ' ')
        print()
# } Driver Code Ends