require "numb"
require "pp"

# http://mathworld.wolfram.com/InfinitaryDivisor.html
# http://mathworld.wolfram.com/UnitaryDivisorFunction.html
N=24
data = (1..N).map do |x| 
  [
   x,
   x.divisors, 
   x.divisors.inject(:+)-x.sum_of_infinitary_divisors, 
   x.divisors.inject(:+)-x.sum_of_unitary_divisors,
   x.divisors.inject(:+)-x.sum_of_unitary_divisors==0
  ] 
end

pp data#.select{|x| ! x[4]}
