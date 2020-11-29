# BigInteger

Big Integer library for c++. Implements basic operations which are described below.

## Prerequisites:
* source code must use namespace `std` and `string` header.
* Every funtion returns the value in the form of string. 

## Operations available:

#### Addition
Adds two big integers. </br>
`string addition(string, string)`

#### Subtraction
Substracts second paramter from first.</br>
`string subtraction(string, string)`

#### Multiplication
Multiplies two big integers</br>
`string multiply(string, string)`

#### Divide
Divides two big integers. First parameter is dividend and the second is divisor.</br>
`string divide(string, string)`

#### Factorial
Calculates factorial of given integer. Parameter passes must not overflow int. </br>
`string factorial(int)`

#### GCD
Calculates GCD of two big integers.</br>
`string gcd(string, string)`

#### Fast Exponentiation
Does expoenentiation on given big integer. First parameter is base and the second is expoent value. Exponent value must not overflow long long.</br>
`string fast_expo(string, long long)`


#### Conversion from Binary to Decimal
Converts given binary string into its decimal value. </br>
`string to_decimal(string)`

#### Conversion from Decimal to Binary
Converts given decimal integer string into binary. </br>
`string to_binary(string)`


#### Compare Two Big Integers
Returns `true` if first parameter is greater than second otherwise false.</br>
`bool comp(string, string)`

#### Compare Two Big Integers in Binary 
Returns `true` if first parameter is greater than second otherwise false.</br>
`bool bin_comp(string, string)`


