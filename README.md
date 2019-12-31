# MicroprocessorCS240

Built a 16-bit HERA (Haverford Educational RISC Architecture) Microprocessor as a class project using Logisim. It performs a number of logical, arithmetic, flag, branching and memory operations. It sets 5 flags: sign, zero, overflow, carry and carry-block. 

#### Logical Operations: 
  SET, AND, OR, XOR, LSL (Logical Shift Left), LSR (Logical Shift Right) 

#### Arithmetic Operations: 
  ADD, SUB, MUL, INC, DEC, ASL (Arithmetic Shift Left), ASR (Arithmetic Shift Right)
 
#### Flag Operations: 
  FON - set the given flags to true, 
  FOFF - set the given flags to false, 
  FSET5 - set all flags to the given value,
  FSET4 - set all flags except carry-block to the given value,
  SAVEF - save flags to the register with the write address,
  RSTRF - restore flags from the current register 
  
 #### Memory instructions: 
  LOAD, STORE
  
 #### Function/Interrupt Instructions: 
  CALL, RETURN 
  
 #### Branching Instructions: 
  BR(b): Unconditional branch – true
  BL(b): Branch if signed result <0
  BGE(b): Branch if signed result >0
  BLE(b): Branch if signed result 60
  BG(b): Branch if signed result >0
  BULE(b): Branch if unsigned result 60
  BUG(b): Branch if unsigned result >0
  BZ(b): Branch if zero/if equal
  BNZ(b): Branch if not zero/not equal
  BC(b): Branch if carry/unsigned result >0
  BNC(b): Branch if not carry/unsigned result <0
  BS(b): Branch if sign (negative)
  BNS(b): Branch if not sign (non-negative)
  BV(b): Branch if overflow
  BNV(b): Branch if not overflow
 
