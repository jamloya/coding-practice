t=gets.chomp.to_i
str ||=''
b ||=''
while t>0
    str=gets.chomp
    b=str.reverse
    if str===b
        puts "Palindrome"
    else
        len=Integer(str.length)
        c=0
        i=1
        while c<len
            j=str[c].ord-96
            i=i*j
            c+=1
        end
        puts i
    end
    t-=1
end
            
