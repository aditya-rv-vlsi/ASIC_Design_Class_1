# ASIC_Design_Class_1
This is the Github repository of **Aditya R Venkateshwaran, MT2024502** for the ASIC Design Class of Aug 2024 to Dec 2024. The following items can be found in this repository, the name of the file indicative of the experiment number:

1. Documentation for each of the experiments conducted during the labs
2. Snapshots of the procedure of the experiments
3. Code files of the experiments

***
<details>
  <summary> Laboratory 1: Create a C program to find the sum of n natural numbers, compile it using gcc compiler. Verify the output of the C program after execution.</summary>
 
  **Step 1:** Create a new sum1ton.c file in the desired directory (ASIC Class) in Linux environment.
  
  ![image](https://github.com/user-attachments/assets/a37c4825-dbf3-458a-ab23-fb4d47fb4c0d)
  
  Here, GEDIT text editor from Ubuntu is used. Write and save your C program in the text editor.
  
  ![image](https://github.com/user-attachments/assets/1ba473a9-6f80-4a4b-be7d-ebce1e5ea2a1)

  **Step 2:** Compile the code using GCC compiler in the terminal window of Ubuntu enivronment and ensure there are no errors during compilation.
  
  ![image](https://github.com/user-attachments/assets/8610ea53-4de6-4fa8-b3bb-af1f85dcb776)
  
  **Step 3:** After compilation, the executable (a.out) will be generated. Run the executable in terminal window to view the output.
  
  ![image](https://github.com/user-attachments/assets/0093d1ad-0ac6-48b1-a578-62a3863594fc)
  
  **Final Output:** In the above image we can observe the output to be 55 (Sum of numbers 1 to 10).
</details>

***

<details>
  <summary>Laboratory 2: For the C program created in Laboratory 1, compile the same using the RISCV compiler, and verify the output of the C program after execution.</summary>


  **Step 1:** For the file sum1ton.c created, type in the following commnand "riscv64-unknown-elf-    gcc -O1 -mabi=lp64 -mach=rv64i -o sum1ton.o sum1ton.c" and press enter. Subsequently, type     "ls -ltr sum1ton.o" to check if the file has been created. 
    
  ![image](https://github.com/user-attachments/assets/56e65f99-2c34-4831-a612-9bd64598013c)
  
  **Step 2:** Open a new terminal tab and write the following command as shown in the figure: 
  
  ![image](https://github.com/user-attachments/assets/6174745a-c5a6-4e9a-8fe4-89f2c6b81c92)
  
 **Step 3:** The assembly version of the C program appears. Type "/main" to jump to the area of      the code that corresponds to the main function (int main()) of the C program. 
  
  ![image](https://github.com/user-attachments/assets/5fdf05fe-8360-4daf-bbfa-c82432068ad3)
  
  **Step 4:** The starting address of the instruction in the main function is 10184, and the ending address is 101B0. Each subsequent instruction, after 10184, has an increment of 4. To find the number of instructions, subtract 10184 from 101B0, and divide by 4. In this case, the number of instructions are equal to 11, as shown in the figure. 
  
  ![image](https://github.com/user-attachments/assets/d88032c3-2865-4cae-bc2f-7e064c4ec5a2)
  ![image](https://github.com/user-attachments/assets/9bc622b1-597f-4805-9b76-4e01de645409)
  
  
  **Step 5:** Repeat Step 1, with the following change "riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -mach=rv64i -o sum1ton.o sum1ton.c" and press enter. Subsequently, repeat the rest of the procedure. 
  
  ![image](https://github.com/user-attachments/assets/95e90c78-24b1-479b-b67b-f6e594f1e668)
  
  To find the number of instructions, subtract 100B0 from 100DC, and divide by 4. In this case, the number of instructions are equal to 11, as shown in the figure.
  
  ![image](https://github.com/user-attachments/assets/3a8f94b5-438f-4c99-860e-12fce037b4fb)
  
  **Final Output:** The number of instructions obtained using the O1 and Ofast switching is equal to 11. 

</details>

***

<details>
  <summary> Laboratory 3: Perform SPIKE Simulation, C Code compilation and RISC-V Object Dump and observation with -O1 and -Ofast for the C program written in Laboratory 1.</summary>

**Step 1:** In the terminal window, compile the C program sum1ton.c and obtain the executable file. Then, run the executable file and observe the output.

**Step 2:** Now, enter the command "riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c", indicating the use of O1 switch and press enter to compile. 

Subsequently, type the command "spike pk sum1ton.o" and press enter to obtain the output of the program using SPIKE simulator and observe the output.

![image](https://github.com/user-attachments/assets/2fe1dfff-bf63-47e7-b092-0f8f28816178)

We can observe that the output of simulation using GCC and SPIKE are the same.

**Step 3:** Perform RISC-V Object Dump by typing the following command "riscv-64-unknown-elf-objdump -d sum1ton.o | less and press enter.

![image](https://github.com/user-attachments/assets/fc7fbc88-d2cd-4e95-8aca-84a166fa860a)

**Step 4:** It can be observed that the number of instructions are equal to (0x101B0-0x10184)/4 = 0xB, which is 11 instructions.

![image](https://github.com/user-attachments/assets/bceeb4bd-74d8-458e-8d11-f751b99bb129)

**Step 5:** Now, repeat Step 2 to Step 4 by using Ofast switch.

![image](https://github.com/user-attachments/assets/12e7b2fa-4a7c-48e6-99c9-a3dd63e5ff50)
![image](https://github.com/user-attachments/assets/feba6e97-c1d0-44b6-82af-a55562700cad)
![image](https://github.com/user-attachments/assets/e3fb4e4f-ca87-4d5f-b008-4041027eccca)

It can be observed that the number of instructions are equal to (0x100DC-0x100B0)/4 = 0xB, which is 11 instructions.
</details>

***

<details>
  <summary>
    Identify various RISC-V instruction type (R, I, S, B, U, J) and exact 32-bit instruction      code in the instruction type format for below RISC-V instructions
    1. ADD r11, r12, r13
    2. SUB r13, r11, r12
    3. AND r12, r11, r13
    4. OR r8, r12, r5
    5. XOR r8, r11, r4
    6. SLT r30, r20, r4
    7. ADDI r31, r21, 5
    8. SW r21, r19, 4
    9. SRL r26, r21, r20
    10. BNE r0, r19, 20
    11. BEQ r0, r0, 15
    12. LW r23, r21, 2
    13. SLL r25, r21, r20
  </summary>
 
The instructions format of a processor is the way in which machine language instructions are structured and organized for a processor to execute. It is made up of series of 0s and 1s, each containing information about the location and operation of data.
There are 6 instruction formats in RISC-V:

<li>R-format</li>
<li>I-format</li>
<li>S-format</li>
<li>B-format</li>
<li>U-format</li>
<li>J-format</li>


![image](https://github.com/user-attachments/assets/04fbc6f6-5f98-48b0-a346-292e0c9c115e)

<li>The first field in all the instruction format is known as opcode, also referred as operation code. It is of length 7 bits and is used to determine the type of instruction format.</li>
<li>RV32 instructions are word-aligned, which means that address is always defined in the multiple of 4 bytes.</li>

## 1. R-type Instruction

In R-type instruction, R stands for register which means that operations are carried on the Registers and not on memory location. This instruction type is used to execute various arithmetic and logical operations. The entire 32 bits instruction is divided into 6 fields as shown below.

![image](https://github.com/user-attachments/assets/2ffba883-3d7d-4dce-b152-258a85fc1815)

<li>RD: also known referred as Destination Register. It is of length 5 bits and is used to store the final result of operation.</li>
<li>func3: Also referred as function 3. Here the ‘3’ represents the size of this field. This field tells the detail about the operation, i.e., the type of arithmetic and logical that is performed.</li>
<li>RS1 and RS2: These are the source registers each of length 5 bits, mainly used to store and manipulate the data during the execution of instructions.</li>
<li>func7: Also referred as function 7. Here ‘7’ represents the size of the field. The function of func7 field is same as that of func3 field.</li>

## 2. I-type Instruction

In I-type instruction, I stand for immediate which means that operations use Registers and Immediate value for their execution and are not related with memory location. This instruction type is used in immediate and load operations. The entire 32 bits instruction is divided into 5 fields as shown below.

![image](https://github.com/user-attachments/assets/b4f0e45a-7c24-4864-978b-a4a9b658cc44)

<li>RD: also known referred as Destination Register. It is of length 5 bits and is used to store the final result of operation.</li>
<li>func3: Also referred as function 3. Here the ‘3’ represents the size of this field. This field tells the detail about the operation, i.e., the type of arithmetic and logical that is performed.</li>
<li>RS1: This is the source register of length 5 bits, mainly used to store and manipulate the data during the execution of instructions.</li>
<li>The only difference between R-type and I-type is rs2 and func7 field of R-type has been replaced by 12-bits signed immediate, imm[11:0].</li>

## 3. S-type Instruction
   
In S-type instruction, S stand for store which means it is store type instruction that helps to store the value of register into the memory. Mainly, this instruction type is used for store operations. The entire 32 bits instruction is divided into 6 fields as shown below.

![image](https://github.com/user-attachments/assets/3c04cfaf-34b3-4a6c-9704-ed45d55c3401)

<li>S-type instructions encode a 12-bit signed immediate, with the top seven bits imm[11:5] in bits [31:25] of the instruction and the lower five bits imm[4:0] in bits [11:7] of the instruction.</li>
<li>Doesn’t have RD fields which states that these instructions are not used to write value to a register, but to write/store a value to a memory.</li>
<li>The value to be stored is defined in RS1 field and address to which we have to store this value is calculated using RS1 and immediate field.</li>li>
<li>The width of the operation and types of instruction is defined by func3, it can be a word, half-word or byte.</li>

## 4. B-type Instruction
   
In B-type instruction, B stand for branching which means it is mainly used for branching based on certain conditions. The entire 32 bits instruction is divided into 8 fields as shown below.

![image](https://github.com/user-attachments/assets/ae38579f-e051-4a5a-bbe1-42b68d629f98)

<li>Encodes a 12-bit signed immediate, with the most significant bit imm[12] in bit [31] of the instruction, six bits imm[10:5] in bits [25:30] of the instruction, four bits imm[4:1] in bits [11:8] and one bit imm[11] on bit[7].</li>
<li>RS1 and RS2: There are two source registers on which various operations are performed based on certain conditions, and those conditions are defined by func3 field.</li>
<li>After performing operations on the source register based on the conditions, it is evaluated that if the condition is true, Program Counter value gets updated by PC = Present PC Value + Immediate Value, and if the condition is false then PC will be given as PC = Present PC value + 4 bytes, which states that PC will move to next instruction set.</li>

## 5. U-type Instruction
   
In U-type instruction, U stand for Upper Immediate instructions which means it is simply used to transfer the immediate data into the destination register. The entire 32 bits instruction is divided into 3 fields as shown below.

![image](https://github.com/user-attachments/assets/e155a78d-489a-4b86-9e9f-9904401dfcc7)

<li>Consists of only two instructions, i.e., LUI and AUIPC.</li>
<li>Eg:lets take the instruction lui rd, imm and understand this instruction. lui x15, 0x13579 : This instruction will be executed and the immediate value 0x13579 will be written in the MSB of the rd x15, and it will look like x15 = 0x13579000.</li>

## 6. J-type Instruction
   
In J-type instruction, J stand for jump, which means that this instruction format is used to implement jump type instruction. The entire 32 bits instruction is divided into 6 fields as shown below.

![image](https://github.com/user-attachments/assets/06de5c85-ff12-4cc5-b301-758817730e78)

<li>Consists of a single instruction, JAL.</li>
<li>Encodes 20 bits signed immediate which is divided into four fields.</li>
<li>Often used to perform jump to the desired memory location. </li>
<li>The address of the desired memory location is defined in the instruction. </li>
<li>Also used to implement loops.</li>

## Instruction Table

|Sl. No | Instruction| Type |Description of the Instruction |Format                            | Binary Representation          |
|--------|----------------|---------------------------------------|------|-----------------------------------|--------------------------------|
|1| ADD r11, r12, r13  |R|Perform Addition between the values stored in registers R12 and R13, and store the result in register R11|funct7_rs2_rs1_funct3_rd_opcode|0000000_01101_01100_000_01011_0110011|
|2| SUB r13, r11, r12  |R|Perform Subtraction between the value stored in register R12 from R11, and store the result in register R13|funct7_rs2_rs1_funct3_rd_opcode|0100000_01100_01011_000_01101_0110011|
|3| AND r12, r11, r13  |R|Perform Logical AND between the values stored in registers R11 and R13, and store the result in register R12 |funct7_rs2_rs1_funct3_rd_opcode|0000000_01101_01011_111_01100_0110011|
|4| OR r8, r12, r5     |R|Perform Logical OR between the values stored in registers R5 and R12, and store the result in register R8|funct7_rs2_rs1_funct3_rd_opcode|0000000_00101_01100_110_01000_0110011|
|5| XOR r8, r11, r4    |R|Perform Logical XOR between the values stored in registers R4 and R11, and store the result in register R8|funct7_rs2_rs1_funct3_rd_opcode|0000000_00100_01011_100_01000_0110011|
|6| SLT r30, r20, r4   |R|Compare if the data in register R30 is less than that of R20, If yes, set destination register as 1, else, set it as 0|funct7_rs2_rs1_funct3_rd_opcode|0000000_00100_10100_010_111100110011|
7| ADDI r31, r21, 5   |I|Perform addition between data in register R21 and Immediate value (5), and store the result in register R31|imm[11:0]_rs1_funct3_rd_opcode|000000000101_10101_000_11111_0010011|
|8| SW r21, r19, 4     |S|Store Word (32 bits or 4 bytes) from the address pointed by the sum of address held in register R19 and the immediate value (4) and store it in register R21 |imm[11:5]_rs2_rs1_funct3_imm[4:0]_opcode|0000000_10011_10101_010_00100_0100011|
|9| SRL r26, r21, r20  |R| Perform Shift Logical Right on data present in register R21, based on the data present in register R20, and store the result in register R26|funct7_rs2_rs1_funct3_rd_opcode|0000000_10100_10101_101_11010_0110011 |
|10| BNE r0, r19, 20    |B|Branch if the contents of registers R0 and R19 are not equal, to the address denoted by the sum of the address held by the program counter (PC) and the immediate value (20)|imm[12'|'10:5]_rs2_rs1_funct3_imm[4:1|11]_opcode|000000_10011_00000_001_01000_1100011|
|11| BEQ r0, r0, 15     |B| Branch if the contents of registers R0 and R0 are equal, to the address denoted by the sum of the address held by the program counter (PC) and the immediate value (15)|[12|10:5] rs2 rs1_funct3_imm[4:1'|'11]_opcode|000000_00000_00000_000_01111_1100011|
|12| LW r23, r21, 2     |I|Load Word (32 bits or 4 bytes) from the address pointed by the sum of address held in register R21 and the immediate value (2) and store it in register R23|imm[11:0]_rs1_funct3_rd_opcode|000000000010_10101_010_10111_0000011|
|13| SLL r25, r21, r20  |R| Perform Shift Logical Left on data present in register R21, based on the data present in register R20, and store the result in register R25|funct7 rs2 rs1 funct3 rd opcode   | 0000000_10100_10101_001_11001_0110011|

</details>



