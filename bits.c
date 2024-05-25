/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
#include "bits.h"

//P1
/* 
 * tconst - return a constant value 0xFFFFFFE0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int tconst(void) {
	return ~(0x1F);
}

//P2
/* 
 * bitNand - return ~(x&y) using only ~ and | 
 *   Example: bitNand(4, 5) = -5, bitNand(3, 11) = -4
 *   Legal ops: ~ |
 *   Max ops: 6
 *   Rating: 2
 */
int bitNand(int x, int y) {
  return ~x | ~y;
}

//P3
/*
 * ezOverflow - determine if the addition of two signed positive numbers overflows,
 *      and return 1 if overflowing happens and 0 otherwise
 *   You can assume 0 <= x, 0 <= y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int ezOverflow(int x,int y) {
	return ((x + y) >> 31) & 1;
}

//P4
/* 
 * fastModulo - return x%(2^y)
 *   You can assume 0 <= x, 1 <= y <= 31
 *   Example: fastModulo(0x1234567,0xA) = 0x167
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 3
 */
int fastModulo(int x,int y) {
	return x & (~(~0x0 << y));
}

//P5
/*
 * findDifference - return a mask that marks the different bits of y compared to x
 *   Example: findDifference(12, 10) = findDifference(10, 12) = 6
 *   Legal ops: ~ & |
 *   Max ops: 9
 *   Rating: 3
 */
int findDifference(int x,int y) {
	return (~x & y) | (x & ~y);
}

//P6
/*
 * absVal - return the absolute value of x
 *   Examples: absVal(-10) = 10
 *			   absVal(5) = 5
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4
 */
int absVal(int x) {
  return ((x >> 31) + x) ^ (x >> 31);
}

//P7
/*
 * secondLowBit - return a mask that marks the position of the second least significant 1 bit.
 *   Examples: secondLowBit(0x00000110) = 0x00000100
 *			       secondLowBit(0xFEDC1A80) = 0x00000200
 *             secondLowBit(0)  = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowBit(int x) {
  int y = (x & (~x + 1)) ^ x;
	return y & (~y + 1);
}

//P8
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 20
 *  Rating: 5
 */
int byteSwap(int x, int n, int m) {
  return (((x >> (m << 3)) & 0xFF) << (n << 3)) | (((x >> (n << 3)) & 0xFF) << (m << 3)) | (~((0xFF << (m << 3)) | (0xFF << (n << 3))) & x);
}

//P9
/* 
 * byteCheck - Returns the number of bytes that are not equal to 0
 *   Examples: byteCheck(0xFE0A4100) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int byteCheck(int x) {
  return !!((x >> 24) & 0xFF) + !!((x >> 16) & 0xFF) + !!((x >> 8) & 0xFF) + !!(x & 0xFF);
}

//P10
/* 
 * fractions - return floor(x*7/16), for 0 <= x <= (1 << 28), x is an integer 
 *   Example: fractions(20) = 8
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 5
 */
int fractions(int x) {
  return ~(~((x << 2) + x + x + x) >> 4);
}

//P11
/* 
 * biggerOrEqual - if x >= y  then return 1, else return 0 
 *   Example: biggerOrEqual(4,5) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 6
 */
int biggerOrEqual(int x, int y) {
  return (!(((x >> 31) & 0x1) ^ ((y >> 31) & 0x1)) & !((x + ~y + 1) >> 31)) | ((((x >> 31) & 0x1) ^ ((y >> 31) & 0x1)) & !((x >> 31) & 0x1));
}


//P12
/*
 * hdOverflow - determine if the addition of two signed 32-bit integers overflows,
 *      and return 1 if overflowing happens and 0 otherwise
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 6
 */
int hdOverflow(int x,int y) {
	return ~(((~(x + y) >> 31) ^ ~(x >> 31)) & ((~(x + y) >> 31) ^ ~(y >> 31))) + 1;
}

//P13
/* 
 * overflowCalc - given binary representations of three 32-bit positive numbers and add them together, 
 *      return the binary representation of the part where bits are higher than 32.
 *   Examples: overflowCalc(0xffffffff,0xffffffff,0xffffffff) = 2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int overflowCalc(int x, int y, int z) {
  int xf = (x >> 31) & 1;
  int yf = (y >> 31) & 1;
  int zf = (z >> 31) & 1;
  int xb = x + (xf << 31);
  int yb = y + (yf << 31);
  int zb = z + (zf << 31);
  int xy = xb + yb;
  int xyf = (xy >> 31) & 1;
  int xyb = xy + (xyf << 31);
  int xyz = xyb + zb;
  int xyzf = (xyz >> 31) & 1;
  return (xf + yf + zf + xyf + xyzf) >> 1;
}

//P14
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 8
 */
int logicalShift(int x, int n) {
  return (x >> n) & ~(1 << 31 >> n << 1);
}

//P15
/* 
 * partialFill - given l, h, fill all even digits within the [l, h] interval with 1 (subscripts starting from 0)
 *   Can assume that 0 <= l <= 15, 16 <= h <= 31
 *   Examples: partialFill(13,16) = 0x00014000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 8
 */
int partialFill(int l, int h) {
  return (~(~0x0 << h << 1 >> l) << l) & ((0x55 << 24) + (0x55 << 16) + (0x55 << 8) + 0x55);
}

//P16
/* 
 * float_abs - Return bit-level equivalent of expression |f| (absolute value of f) for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 20
 *   Rating: 3
 */
unsigned float_abs(unsigned uf) {
  unsigned abs_value = uf & ~(1 << 31);
  if (abs_value > (0xFF << 23)) {
    return uf; 
  }
  return abs_value;
}

//P17
/* 
 * float_cmp - Return 1 if uf1 > uf2, and 0 otherwise.
 *   Both of the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When ant of the arguments is NaN, return 0.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 5
 */
unsigned float_cmp(unsigned uf1, unsigned uf2) {
  unsigned s1 = (uf1 >> 31) & 0x1;
  unsigned s2 = (uf2 >> 31) & 0x1;
  unsigned exp1 = (uf1 >> 23) & 0xFF;
  unsigned exp2 = (uf2 >> 23) & 0xFF;
  unsigned mantissa1 = uf1 & ~(1 << 31 >> 8);
  unsigned mantissa2 = uf2 & ~(1 << 31 >> 8);
  if((exp1 == 0xFF && mantissa1 != 0) || (exp2 == 0xFF && mantissa2 != 0)){
    return 0;
  }
  if(((uf1 == 0x0) && (uf2 == (1 << 31))) || ((uf2 == 0x0) && (uf1 == (1 << 31)))){
    return 0;
  }
  if(s1 == s2){
    return (uf1 > uf2 && !s1) || (uf1 < uf2 && s1);
  }
  if(s1 != s2){
    return s2;
  }
  return 0;
}

//P18
/* 
 * float_pow2 - Return bit-level equivalent of expression f*(2^n) for
 *   floating point argument f and integer argument n.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   You can assume 0 <= n <= 255
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 50
 *   Rating: 6
 */
unsigned float_pow2(unsigned uf, int n) {
  unsigned sign = uf & 0x80000000;  // 提取符号位
  unsigned exp = uf >> 23 & 0xFF;  // 提取指数位
  unsigned mantissa = uf & 0x007FFFFF; // 提取尾数位
  if(exp == 0xFF && mantissa != 0) return uf; 
  if (exp == 0) {
    if(mantissa == 0) return uf;
    for(n; n > 0; n--){
      mantissa = mantissa << 1;
      if((mantissa & 0x7FFFFF) != mantissa){
        mantissa = mantissa & 0x7FFFFF;
        break;
      }
    }
  }
  exp += n;
  if(exp >= 0xFF){
    exp = 0xFF;
    mantissa = 0;
  }
  return sign | (exp << 23) | mantissa;
}




//P19
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 7
 */
unsigned float_i2f(int x) {
  int count = 0;
  int mantissa, exp, temp;
  int mask = 0x80000000;
  int sign = x & mask;
  int last_7_Bits, the_8th_Bit, the_9th_Bit;
  unsigned result;
  if (x == 0)
    return x;
  if (x == 0x80000000 | x == 0x80000001)
    return 0xcf000000;
  // 找到最高位的1舍去，后面的即为尾数部分
  if (sign)
    x = -x;
  temp = x << 1;
  while (!(temp & mask)) {
    count++;
    temp = temp << 1;
  }

  last_7_Bits = temp & 0x7F;
  the_8th_Bit = temp & 0x80;
  the_9th_Bit = temp & 0x100;
  if ((the_8th_Bit && last_7_Bits) || (the_9th_Bit && the_8th_Bit && (! last_7_Bits))) {
    temp = ((temp >> 8) & 0xFFFFFF) + 1;
    if (temp & 0x1000000)
      count--;
  }
  else
    temp = temp >> 8;
  
  exp = 157 - count;
  mantissa = temp & 0x7FFFFF;
  result = (sign | (exp << 23) | mantissa);
  return result;
}



#ifdef NOT_SUPPOSED_TO_BE_DEFINED
#   __          __  _                          
#   \ \        / / | |                         
#    \ \  /\  / /__| | ___ ___  _ __ ___   ___ 
#     \ \/  \/ / _ \ |/ __/ _ \| '_ ' _ \ / _ \
#      \  /\  /  __/ | (_| (_) | | | | | |  __/
#       \/  \/ \___|_|\___\___/|_| |_| |_|\___|
#                                              

#  ██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗     ██████╗  █████╗ ██████╗ ████████╗
#  ██║  ██║██╔═══██╗████╗  ██║██╔═══██╗██╔══██╗    ██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝
#  ███████║██║   ██║██╔██╗ ██║██║   ██║██████╔╝    ██████╔╝███████║██████╔╝   ██║   
#  ██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗    ██╔═══╝ ██╔══██║██╔══██╗   ██║   
#  ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║    ██║     ██║  ██║██║  ██║   ██║   
#  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝    ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   
#                                                                                   
#endif

//P20
/*
 * oddParity - return the odd parity bit of x, that is, 
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples:oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Challenge: You will get 1 extra point if you use less than or equal to 34 ops
 *   Rating: 2
 */
int oddParity(int x) {
  x = (x >> 16) ^ x;
  x = (x >> 8) ^ x;
  x = (x >> 4) ^ x;
  x = (x >> 2) ^ x;
  x = (x >> 1) ^ x;
  return !(x & 1);
}

//P21
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Challenge: You will get 1 extra point if you use less than or equal to 34 ops
 *   Rating: 2
 */
int bitReverse(int x) {
  int mask16 = (0xFF << 8) + 0xFF;// 0000 0000 0000 0000 1111 1111 1111 1111
  int mask8 = (0xFF << 16) + 0xFF; // 0000 0000 1111 1111 0000 0000 1111 1111
  int mask4 = (mask8 << 4) ^ mask8; // 0000 1111 0000 1111 0000 1111 0000 1111
  int mask2 = (mask4 << 2) ^ mask4; // 0011 0011 0011 0011 0011 0011 0011 0011
  int mask1 = (mask2 << 1) ^ mask2; // 0101 0101 0101 0101 0101 0101 0101 0101
  // Swap adjacent pairs of bits using masks
  x = ((x >> 1) & mask1) | ((x & mask1) << 1);
  x = ((x >> 2) & mask2) | ((x & mask2) << 2);
  x = ((x >> 4) & mask4) | ((x & mask4) << 4);
  x = ((x >> 8) & mask8) | ((x & mask8) << 8);
  x = ((x >> 16) & mask16) | (x << 16);
  return x;
}


//P22
/*
 * mod7 - calculate x mod 7 without using %.
 *   Example: mod7(99) = 1    99 mod (8 - 1)
 *            mod7(-101) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 100
 *   Challenge: You will get 2 extra point if you use less than or equal to 56 ops
 *   Rating: 2
 */
int mod7(int x) {
  int sign = x >> 31;
  int absX = (x + sign) ^ sign;
  int mask = 0x7;
  int result = 0;
  int temp = absX;
  result += temp & mask;
  temp = (temp >> 3) & (~(1 << 31 >> 2));
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  temp = temp >> 3;
  result += temp & mask;
  result = (result & mask) + (result >> 3);
  result = (result & mask) + (result >> 3);
  result = (result & mask) + (result >> 3);
  result = (!(result ^ 0x7) + ~0x0) & result;
  return (result + sign) ^ sign;
}
