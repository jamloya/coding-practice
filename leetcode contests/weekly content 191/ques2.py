class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        hs=0
        hs1=0
        vs=0
        vs1=0
        horizontalCuts.sort()
        verticalCuts.sort()
        for i in horizontalCuts:
            hs1=max(hs1,i-hs)
            hs=i
            
        hs1=max(hs1,h-horizontalCuts[-1])
        for i in verticalCuts:
            vs1=max(vs1,i-vs)
            vs=i
            
        vs1=max(vs1,w-verticalCuts[-1])
        return (hs1*vs1)% 1000000007
