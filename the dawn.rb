n=gets.chomp.to_i
i=Integer(Math.sqrt(n))
k=n%i
while k!=0
i=i-1
k=n%i
end

j=n/i
puts Integer(i+j)
        
n=gets.chomp.to_i
i=Integer(Math.sqrt(n))
k=n%i
while k!=0
i=i-1
k=n%i
end

j=n/i
puts Integer(i+j)
        
