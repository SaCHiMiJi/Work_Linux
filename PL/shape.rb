class Shape
  def pi
    Math::PI
  end

  def area
    raise NotImplementedError ,
    "Subclasses must implement the 'area' method."
  end

  def circumference
    raise NotImplementedError ,
    "Subclasses must implement the 'circumference' method."
  end
end
# Implement your two subclasses here # ...
class Rectangle < Shape
  attr_accessor :w, :h
  def initialize(w,h)
    @w=w
    @h=h
  end

  def area
    return w*h
  end

  def circumference
    return (w*2)+(h*2)
  end

end

class Circle < Shape
  attr_accessor:r
  def initialize(r)
    @r=r
  end
  def area
    return pi*r**2
  end

  def circumference
    return 2*pi*r
  end
end
# DO NOT EDIT AFTER THIS LINE
rectangle = Rectangle.new(Integer(gets.chomp), Integer(gets.chomp))
circle = Circle.new(Integer(gets.chomp))
puts rectangle.area
puts rectangle.circumference
puts circle.area
puts circle.circumference
