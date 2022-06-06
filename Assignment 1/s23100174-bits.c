/* 
 * CS:APP Data Lab 
 * 
 * < M.Shozab Hussain and 23100174 >
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	x= ~x;
	y= ~y;
	
  return ~(x | y); // De Morgan's rule has been applied
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	int mask= 0xFF ;
	n= n << 3;
	x= x >> n;
  return mask & x;
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
	int mask= 0x55;			// initialises a mask of 01010101
	mask = mask | (mask << 8); 	// the mask becomes 0101010101010101
    	mask = mask | (mask << 16); 	// the mask now becomes 01010101010101010101010101010101
	x= x&mask;			// now if x has at least one even bit set to 1, it will return a number
    return !!x;				// the double negation of a number will be 1
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int mask= 0xAA;			// initialises a mask of 10101010
	mask = mask | (mask << 8);	// the mask becomes 1010101010101010
    	mask = mask | (mask << 16);	// the mask becomes 10101010101010101010101010101010
	x= x&mask ;			// now all the even bits are set to 0 while all the odd bits are set to 1
	x= x ^ mask;			// now all the odd bits that are 1 will be set to zero, hence if all odd bits are 1 then whole number will be 0
	x= !x ;				// if 0 then it will return 1, indicating that all the odd bits are indeed 1
  return x; 
  
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {	// 0x87654321 = 10000111011001010100001100100001
	int mask= 0x1;			// initialises a mask of 0001
	mask = mask << 31 ;		// the mask becomes 10000000000000000000000000000000
	mask = mask >> n;		// the mask becomes 11111000000000000000000000000000
	mask = mask << 1 ;		// the mask becomes 11110000000000000000000000000000
	mask = ~mask ;			// the mask becomes 00001111111111111111111111111111
	x= x >> n;			// the x becomes 00001000011101100101010000110010
	x= x & mask;			// the x becomes 00001000011101100101010000110010

  return x;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
	
	int y= x;
	int mask= 0x1;			// initialises a mask 0001
	int mask1= 0xFF;		// initialises a mask1 1111
	mask = mask << 31 ;		// mask becomes 10000000000000000000000000000000
	mask = mask >> n;		// mask becomes 11111000000000000000000000000000
	mask = mask << 1 ;		// mask becomes 11110000000000000000000000000000
	mask = ~mask ;			// the mask becomes 00001111111111111111111111111111
	y= y >> n;			// the x becomes 00001000011101100101010000110010
	y= y & mask;			// the x becomes 00001000011101100101010000110010 (basically uptil this point we have logically shifted x)
	mask1 = mask1 | (mask1 << 8);	// mask1 becomes 1111111111111111
    	mask1 = mask1 | (mask1 << 16);	// mask1 becomes 11111111111111111111111111111111
	mask1 = mask1 << n ;		// mask1 becomes 11111111111111111111111111110000
	mask1 = ~mask1;			// mask1 becomes 00000000000000000000000000001111
	x= x & mask1;			// we will now extract the least n bytes from x (in this case least 4 bytes i-e 0001 )
	n= ((~n)+1);			// n is now -n ;
	n= 32+n;			// n is now 32-n ;
	x= x << n ;			// those extracted least n bytes will be shifted to towards the front of the number
	x= x | y;			// now this will produce a number a those shifted bytes in front of the number x
	
  return x;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	int x= 0x8;	//initialises a number 10000 
	x= x<< 28;	//the number becomes 10000000000000000000000000000000 and this is the minimum number
  return x;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) { 	// considering the example of 5,3
	int mask=x ;		// mask is now equal to x which is 00000000000000000000000000000101
	n= (~n) + 1;		// n is now -n
	n= 32 + n;		// n is now 32-n (in this case 29)
	mask= mask << n;	// mask becomes 10100000000000000000000000000000 
	mask = mask >> n;	// the nth bit of x is extended over the whole bit pattern, we have now truncated x into n bits
	x= x^mask ;		// now if x wil not be matched with it's mask which is in n bits so xor will give 1 which will then be returned as 0
	
 return !x;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
	int y= (~x) + 1; // we will take two's complement of x so all the bits after least 1 will be toggled
	
	
  return (y & x); // all bits of x and y after the least 1 are opposite, hence the & operation will return a all zeroes after the least 1
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	
	int sbx = x;		// initialises an integar to store the sign bit of x
	int mask ;		// initialises an integar to store a mask
	sbx = sbx >> 31;	// the sign bit of x is extended over the bit pattern
				// if 0x11111111 then x is neg and so mask=1 and if 0 then x is positive and mask =0
	mask = !!(sbx);		// mask is assigned the value of sign bit of x
	mask = mask << n;	// mask is now multiplied with n, if x is neg then mask=n and if x is positive then mask=0
	mask = mask + sbx ;	// if x is neg, then mask=n-1 and if x is postive then mask=0
	x= x + mask;		// if x is neg, then x=x+n-1 and if x is positive then x= x+0
	x= x >> n ;		// x is divided by 2^n
	return x;

}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
	int mask= 1;		// initialises a mask of 0001
	mask = mask << 31;	// the mask becomes 10000000000000000000000000000000
	x= x & mask ;		// if number negative then x= 10000000000000000000000000000000 or if positive then 0000000000000000000000000000000 
	x= !!x;			// will convert x into either 0 or 1, if neg then 1 and if positive then 0
  return !(x);			// will return 0 if x is neg and 1 if x is positve 
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int z;
	int mask= 1;		// initialises a mask with 0001
	int sbx = !!(x>>31);	// stores the sign bit of x, 1 if neg and 0 if positive
	int sby = !!(y>>31);	// stores the sign bit of y, 1 if neg and 0 if positive
	int diffs = sbx ^ sby ;	// If both are positive or both are negative, then diff =0 otherwise diff=1
	int a = diffs & sbx;	// if both have different signs and x is negative, then this makes y positive and greater than x, in this case a will 					store 1
	x= (~x)+1;		// converts x into -x
	z= x+y;			// stores -x+y, if both are positive then it will stores -x+y and if both are negative then it will store -(-x)+(-y) 
	mask = mask << 31;	// mask to extract the sign bit
	z= z & mask ;		// if both are positive or netgative and y is greater then it will stores 0 otherwise 1
	z= !diffs & !z;		// if both have same signs and y is greater, then it will store 1 otherwise 0
	
  return a | z;			// will return 1 if a returns 1 or z returns 1
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
	
	int  tmin = 1<<31;	// stores the value of tmin and if we negate it then it will return the value of tmax
	int  sbx = x;		// stores the sign bit of x
	int sumx;
  	int check;
  	int a;
	int b;
	sbx = sbx >> 31;	// extends the sign bit of x over the whole bit pattern, 0xFFFFFFFF if neg and 0x0 if positive 
	sumx = x + x;		// basically multiply x by 2 ;
	check = x ^ sumx ;	// if 2x<tmax or 2x>tmin then it will give 0 otherwise if 2x>tmax or 2x<tmin then x wil overflow so check will give 1
	check = check >> 31;	// if x is does not overflow, then it will give 0x0 otherwise 0xFFFFFFFF
	a = sbx ^ ~tmin;	// if x is neg then it will store 0x800000000(tmin) and if x is postive then it wil store tmax 
	a = a & check; 		// if x overflows then check= true so it will return a which contains either tmin or tmax
	b= ~check & sumx ;	// if x doesn't overflows then check != true so it will return b which contains 2x

return (a) | (b);
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {			// if x is a power of 2, then it will have only one bit set to 1 while all other bits will be set to 0
	int nonzero;			// check for checking if number is zero or not
	int ispos; 			// check for checking if number is postive or not	
	int check= x + (~1 + 1 );	// this will store the value of x-1
	check = check & x ;		// if x is a power of two, then x-1 cannot be a power of two and hence & operation will give 0 give x is a 						power of two
	check = !check ;		// will give 1 if a power of two and 0 if not
	nonzero = !!x;			// will store 0 if zero and 1 if non zero
	ispos = !(x >> 31);		// will store 0 if neg and 1 if positive
	
 return nonzero & ispos & check;	// will return 1 if x is non zero and positive and a power of two

}
