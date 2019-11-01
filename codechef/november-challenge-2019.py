def binaryToDecimal(binary): 
      
    binary1 = binary 
    decimal, i, n = 0, 0, 0
    while(binary != 0): 
        dec = binary % 10
        decimal = decimal + dec * pow(2, i) 
        binary = binary//10
        i += 1
    return (decimal)

get_bin = lambda x: format(x, 'b')
t=int(input())
for i in range(0,t):
    n=int(input())
    res=[]
    while n:
        res.append(binaryToDecimal(int(input())))
        n-=1
        
    for j in res[1:]:
        res[0]=res[0]^j
    count=0;
    for k in get_bin(res[0]):
        if k=='1':
            count+=1
    print(count)
    
    
        
        
