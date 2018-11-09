len=gets.chomp.to_i
str=gets
short=str.gsub('w','vv').gsub('vv','w').length #gsub is kind of find and replace tool
long=str.gsub('w','vv').length
print "#{short} #{long}"
