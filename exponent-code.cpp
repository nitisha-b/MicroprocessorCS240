#include <HERA.h>   /* This is required for HERA projects */
#include <HERA-print.h>

void HERA_main()
{

CBON()
SET(R1, 3)                //base
SET(R2, 4)                //exponent
SET(R3, 1)                //result

LABEL(dont_skip)          //if the exponent is not zero, repeat

CALL(FP_alt, x_power)     //call the function

BNZ(dont_skip)            //check if r2 = 0

LABEL(x_power)            //function to calculate the exponent of x
  MUL(R3, R3, R1)         //multiply r1 with the previous result (r3)
  DEC(R2, 1)              //decrement the exponent by 1
  BZ(skip_to_bottom)      //if r2 = 0, branch to HALT()
  RETURN(FP_alt, PC_ret)
LABEL(skip_to_bottom)
HALT()
}

/*

HERA program is done.
Registers:
           r1 = 0x0003 = 03 = 3
           r2 = 0x0000 = 00 = 0
           r3 = 0x0051 = 0121 = 81 = 'Q'
           r4 = 0x0000 = 00 = 0
           r5 = 0x0000 = 00 = 0
           r6 = 0x0000 = 00 = 0
           r7 = 0x0000 = 00 = 0
           r8 = 0x0000 = 00 = 0
           r9 = 0x0000 = 00 = 0
          r10 = 0x0000 = 00 = 0

Flags: carry-block=TRUE  C=TRUE  V=FALSE Z=TRUE  S=FALSE


Hassem code: 

3160
e103
f100
e204
f200
e301
f300
ed0d
fd00
20cd
eb07
fb00
190b
c331
32c0
eb13
fb00
180b
21cd
0

*/