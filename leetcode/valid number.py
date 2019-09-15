class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            f=float(s)
            return True
        except:
            return False
