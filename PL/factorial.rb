def factorial n
  # fill your code after this
  result = 1
  while n>0
    result = result * n
    n = n - 1
  end
  return result
end
  # DO NOT EDIT AFTER THIS LINE
  # puts method is for printing
  # gets method is for getting input from user
puts factorial(Integer(gets.chomp))
