v=gets.chomp.to_i
n=gets
if n.nil?
    puts 0
else
    ans,a=0,0
    n.split.each do |x|
    x=x.chomp.to_i
    ans=ans+x
    if ans<0
        ans=0
    elsif  ans>a
        a=ans
    end
    end
    p a
end
