#User function Template for python3

class Solution:

    def removeKdigits(self, S, k):
        # code here
        stack = []
        for e in S:
            while stack and k > 0 and e < stack[-1]:
                k -= 1
                stack.pop()
            stack.append(e)
        while k > 0:
            stack.pop()
            k -= 1
        i = 0
        while i < len(stack) and stack[i] == '0':
            i += 1
        if i == len(stack):
            return "0"
        return "".join(stack[i:])


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()
        K = int(input())

        obj = Solution()

        ans = obj.removeKdigits(S, K)

        print(ans)


# } Driver Code Ends