// CALL & RETURN with parameters on the stack (from FIG 7.11 & 7.12 in HERA 2.4 docs)

#include <HERA.h>		/* This is required for HERA projects */
#include <HERA-print.h>	/*  This is needed to use print_reg and print for debugging in HERA-C */

// adapted from HERA 2.4 documentation, p. 48-49, Figs 7.11 & 7.12 by JD
// removed call to "printint"
// https://drive.google.com/file/d/1axJs9ylIUmgDzGeApYJcK1g52eFu-Xy6/view

void HERA_main()
{
// Example main program: x = 5; two_x_plus_y(x+5, 2)
	CBON()
// Assume we start with a size-zero stack frame, i.e., SP=FP
	SET(r1, 5) // use r1 for x, set x=5
// call two_x_plus_y(x+5, 2)
	MOVE(FP_alt, SP) // New frame (for foo) should be current SP
	INC(SP, 5) // foo has 2 parameters, start with stack size 5
	MOVE(R2, R1) // R2 is x, we’ll increment it to x+5
	INC(R2, 5)
	STORE(R2, 3,FP_alt) // parameter 1 = x+5
	SET(r2, 2)
	STORE(r2, 4,FP_alt) // parameter 2 = 2
	CALL(FP_alt, two_x_plus_y)
	LOAD(R2, 3,FP_alt) // retrieve returned value into R2
	DEC(SP, 5) // free up memory from foo’s frame
	HALT()

// Translation of a high-level-language function two_x_plus_y:
// int two_x_plus_y(x : int, y : int) : int = x+x+y
	LABEL(two_x_plus_y)
// FIRST, make space to save r1 and r2 and then save PC_ret, FP_alt, and them
	INC(SP, 2)
	STORE(PC_ret, 0,FP) // Return address, i.e. PC+1 from before CALL
	STORE(FP_alt, 1,FP) // Control Link, i.e. FP from before the CALL
	STORE(r1, 5,FP) // skip FP+3 and FP+4, where a and b will be...
	STORE(r2, 6,FP) // ... and save r1 and r2 in FP+5/FP+6
// Load "x" and "y" from stack frame (calling func. put them there)
	LOAD(r1, 3,FP) // r1 = x
	LOAD(r2, 4,FP) // r2 = y
// Compute the result
	ADD(r1, r1,r1) // r1 = x+x
	ADD(r1, r1,r2) // r1 = x+x+y
// Store the result where the caller of two_x_plus_y will find it
	STORE(r1, 3,FP)
// FINALLY, restore registers (including PC_ret and FP_alt) and return
	LOAD(r2, 6,FP) // Restore r2
	LOAD(r1, 5,FP) // Restore r1
	LOAD(PC_ret, 0,FP) // Restore PC_ret to provide R.A. for return
	LOAD(FP_alt, 1,FP) // Restore FP_alt (D.L.) to provide old FP for return
	DEC(SP, 2)
	RETURN(FP_alt, PC_ret)

/*
+++ Hassem assembly code +++

3160
e105
f100
9cf0
3f84
9210
3284
623c
e202
f200
624c
ed11
fd00
20cd
423c
3fc4
0000
3f81
6d0e
6c1e
615e
626e
413e
424e
a111
a112
613e
426e
415e
4d0e
4c1e
3fc1
21cd



+++ HERA-C-Run output +++

Welcome to the HERA-C HERA 2.4.0 simulator, October 2018 edition.
  Please report bugs to davew@cs.haverford.edu

Starting HERA program at HERA_main() ...



HERA program is done.
Registers:
           r1 = 0x0005 = 05 = 5
           r2 = 0x0016 = 026 = 22
           r3 = 0x0000 = 00 = 0
           r4 = 0x0000 = 00 = 0
           r5 = 0x0000 = 00 = 0
           r6 = 0x0000 = 00 = 0
           r7 = 0x0000 = 00 = 0
           r8 = 0x0000 = 00 = 0
           r9 = 0x0000 = 00 = 0
          r10 = 0x0000 = 00 = 0

Flags: carry-block=TRUE  C=TRUE  V=FALSE Z=TRUE  S=FALSE

Stack is (empty)


RAM:
0	000e
1	0000
2	0000
3	0016
4	0002
5	0005
6	0002
7 … 	0000 …

*/

