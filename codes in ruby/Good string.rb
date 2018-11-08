str ||=''
str=gets.chomp
len=Integer(str.length)
a=Array.new(26,0)

count=0
c=0
while c<len
    val=str[c].ord-97
    
    if a[val] == 0
        a[val]=1
    else
        count+=1
    end
    c+=1
end
puts count
