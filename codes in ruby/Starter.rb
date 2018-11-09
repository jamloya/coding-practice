t=gets.chomp.to_i
while t>0
    n=gets.chomp.to_i
    n-=1
    a,b,c=n/3,n/5,n/15
    sum1=a*(3*2+(a-1)*3)
    sum2=b*(5*2+(b-1)*5)
    sum3=c*(15*2+(c-1)*15)
    sum=sum1+sum2-sum3
    sum=sum/2
    puts sum
    t-=1
end
