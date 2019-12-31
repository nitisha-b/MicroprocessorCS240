# Microprocessor

Built a 16-bit HERA (Haverford Educational RISC Architecture) Microprocessor as a class project using Logisim. It performs a number of logical, arithmetic, flag, branching and memory operations. It sets 5 flags: sign, zero, overflow, carry and carry-block. 

## Operations: 

### Logical Operations: 
  SET, AND, OR, XOR, LSL (Logical Shift Left), LSR (Logical Shift Right) 

### Arithmetic Operations: 
  ADD, SUB, MUL, INC, DEC, ASL (Arithmetic Shift Left), ASR (Arithmetic Shift Right)
 
### Flag Operations: 
  FON - set the given flags to true, <br> 
  FOFF - set the given flags to false, <br> 
  FSET5 - set all flags to the given value, <br> 
  FSET4 - set all flags except carry-block to the given value, <br> 
  SAVEF - save flags to the register with the write address, <br> 
  RSTRF - restore flags from the current register <br> 
  
 ### Memory instructions: 
  LOAD, STORE
  
 ### Function/Interrupt Instructions: 
  CALL, RETURN 
  
 ### Branching Instructions: 
  BR(b): Unconditional branch – true <br> 
  BL(b): Branch if signed result <0 <br> 
  BGE(b): Branch if signed result >0 <br> 
  BLE(b): Branch if signed result 60 <br> 
  BG(b): Branch if signed result >0 <br> 
  BULE(b): Branch if unsigned result 60 <br> 
  BUG(b): Branch if unsigned result >0 <br> 
  BZ(b): Branch if zero <br> 
  BNZ(b): Branch if not zero <br> 
  BC(b): Branch if carry/unsigned result >0 <br> 
  BNC(b): Branch if not carry/unsigned result <0 <br> 
  BS(b): Branch if sign (negative) <br> 
  BNS(b): Branch if not sign (non-negative) <br> 
  BV(b): Branch if overflow <br> 
  BNV(b): Branch if not overflow <br> 
 
## Walkthrough/ Demo: 

<img src= "https://recordit.co/4NoozTjP25" width=500 alt="Demo of the game">

