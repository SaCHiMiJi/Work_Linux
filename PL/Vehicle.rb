class Vehicle
  attr_accessor :num_of_wheels
  def initialize(x)
    @num_of_wheels = x
  end
end

# Define a class of 10-wheel truck named TenWheeler after this line
class TenWheeler < Vehicle
  attr_accessor :color
  def initialize(x, num_of_wheels=10)
    super(num_of_wheels)
    @color = x
  end
end
# End subclass definition
# DO NOT EDIT AFTER THIS LINE
truck1 = TenWheeler.new(gets.chomp)
puts truck1.color
puts truck1.num_of_wheels
