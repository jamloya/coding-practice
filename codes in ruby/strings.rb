t=gets.chomp.to_i
n,m=0,0
while t>0
    a=gets.chomp
    a=a.split()
    a.each do 
        n=a[0]
        m=a[1]
    end
    if ((n==m) ||  ((n=="4" && m=="2") || n=="2" && m=="4"))
        puts "YES"
    else
        puts"NO"
    end
    t-=1
end
