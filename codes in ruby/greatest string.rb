t=gets.chomp.to_i
str=''
while t>0
    str=gets.chomp
    n=gets.chomp.to_i
    i=0
    while n>0 && i<Integer(str.length)
        if str[i] =='a' || str[i] =='e' || str[i] =='i' || str[i] =='o' ||str[i] =='u'
            j=str[i].ord + 1
            str[i]=j.chr
            n=n-1
        end
         i+=1
        
    end
    puts str
    t-=1
end
            