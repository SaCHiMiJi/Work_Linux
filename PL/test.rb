class Human
  @@species = "Homo sapien"
  attr_accessor :name, :age

  def initialize(personName)
    @name = personName
  end
end

john = Human.new("John")
puts john.name
john.name = "Johny"
puts john.name
