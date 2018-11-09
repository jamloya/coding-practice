n=gets.chomp.to_i
a=gets
b=gets
x={}
y={}
i=0
loop do
    if i==n
        break
    end
    if !x.include? a[i]
        x[a[i]]=1
    else
        x[a[i]]+=1
    end
    i+=1
end
i=0
loop do
    if i==n
        break
    end
    if !y.include? b[i]
        y[b[i]]=1
    else
        y[b[i]]+=1
    end
    i+=1
end
if x == y
    puts "YES"
else
    puts "NO"
end
