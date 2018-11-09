str=gets.chomp
rev=str.reverse
count=0
a=Array.new
i=0
loop do
    if i==Integer(str.length)
        break
    end
    if str[i]==rev[i]
        count+=1
    else
        a.push(count)
        count=0
    end
    i+=1
end
a.sort!
i=a.size
if a[i-1]>=2
    puts "YES "
    puts a[i-1]
else
    puts "NO"
end
