n=gets.chomp.to_i
if n%3==0 || n%5==0
    if n%3==0
        if n%5 ==0
            puts "AngelHack!"
        else
            puts "Angel"
        end
    else
        puts "Hack"
    end
else
    puts n
end
    