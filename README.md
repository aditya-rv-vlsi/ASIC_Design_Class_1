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
    Laboratory 4: 
    Task 1: Identify various RISC-V instruction type (R, I, S, B, U, J) and exact 32-bit instruction code in the instruction type format for below RISC-V instructions

    
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



    Task 2: Use the RISC-V Core Verilog netlist and testbench given, for functional simulation experiment. Upload waveform snapshots for the commands. 
  </summary>

**Task 1:**
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

**Task 2:**

Enter the following instructions in the Terminal:

![image](https://github.com/user-attachments/assets/931599ce-b260-4f2e-aeb4-50340d50453e)

The instructions given to me are hardcoded into the memory, in accordance to the 32 bit format for RISC-V Architechture

always @(posedge reset) begin
    
        MEM[0] <= 32'h00D60B67; // add r11, r12, r13
        
        MEM[1] <= 32'h40C586B3; // sub r13, r11, r12
        
        MEM[2] <= 32'h00D5EC67; // and r12, r11, r13
        
        MEM[3] <= 32'h05563233; // or r8, r12, r5
        
        MEM[4] <= 32'h0045C833; // xor r8, r11, r4
        
        MEM[5] <= 32'h042A28BC; // slt r30, r20, r4
        
        MEM[6] <= 32'h00058AF9; // addi r31, r21, 5
        
        MEM[7] <= 32'h009D548B; // sw r21, r19, 4
        
        MEM[8] <= 32'h00A55B4D; // srl r26, r21, r20
        
        MEM[9] <= 32'h130208C7; // bne r0, r19, 20
        
        MEM[10] <= 32'h00000FFF; // beq r0, r0, 15
        
        MEM[11] <= 32'h0015577F; // lw r23, r21, 2
        
        MEM[12] <= 32'h00A55935; // sll r25, r21, r20
    
    end


Here's the table formatted for GitHub with the provided data: Standard ISA vs Hardcoded ISA
|Sl. No|Operation |Standard RISCV ISA |Hardcoded ISA |
|------|----------|-------------------|--------------|
|1 |ADD r11, r12, r13 |32'h00d6b33	|32'h00d6b300|
|2 |SUB r13, r11, r12 |32'h40b6d33	|32'h40b6d380|
|3 |AND r12, r11, r13 |32'h00d6f33	|32'h00d6f400|
|4 |OR r8, r12, r5 |32'h0056c33	|32'h0056c400|
|5 |XOR r8, r11, r4 |32'h0046c33	|32'h0046c500|
|6 |SLT r30, r20, r4 |32'h004a0f33	|32'h004a0f00|
|7 |ADDI r31, r21, 5 |32'h005af93	|32'h005af200|
|8 |SW r21, r19, 4 |32'h004bb3	|32'h0040b300|
|9 |SRL r26, r21, r20 |32'h014b6d33	|32'h014b6d00|
|10 |BNE r0, r19, 20 |32'h014be63	|32'h014be200|
|11 |BEQ r0, r0, 15 |32'h00fbe63	|32'h00fbe000|
|12 |LW r23, r21, 2	|32'h002b8513	|32'h002b8100|
|13 |SLL r25, r21, r20	|32'h014b6933	|32'h014b6900|


    The respective instructions along with the relevant waveforms are as shown below: 

    1. ADD r11, r12, r13

![image](https://github.com/user-attachments/assets/046be833-6cd7-4f5d-b841-6b4e68559b0d)

    2. SUB r13, r11, r12

![image](https://github.com/user-attachments/assets/ee195b5d-fe98-4129-bf70-859241e5f1cf)

    3. AND r12, r11, r13

![image](https://github.com/user-attachments/assets/7fd4ef82-e131-4293-8818-98fa30e3f605)

    4. OR r8, r12, r5

![image](https://github.com/user-attachments/assets/cd54c929-990b-43ae-bd4f-a049653ab231)

    5. XOR r8, r11, r4

![image](https://github.com/user-attachments/assets/00eaa52e-8e55-4905-91e1-f07c9fb9af06)

    6. SLT r30, r20, r4

![image](https://github.com/user-attachments/assets/baee2b52-d2f9-4e73-adab-a2a7a9911b97)

    7. ADDI r31, r21, 5

![image](https://github.com/user-attachments/assets/ae9ed1da-bb9f-42db-9516-27e66ae0d50c)

    8. SW r21, r19, 4

![image](https://github.com/user-attachments/assets/6874a8f3-d65f-4e01-8745-14cc0709ad0e)

    9. SRL r26, r21, r20

![image](https://github.com/user-attachments/assets/920555d0-ce19-4ba9-9e58-9c06cd9b657d)

    10. BNE r0, r19, 20

![image](https://github.com/user-attachments/assets/969044cb-f332-49ce-8530-9fe2589316c9)

    11. BEQ r0, r0, 15

![image](https://github.com/user-attachments/assets/8be0aba5-fc67-41a4-8e15-61eafc7e8034)

    12. LW r23, r21, 2

![image](https://github.com/user-attachments/assets/148160b1-8c8e-49f8-8211-f25358c5a328)

    13. SLL r25, r21, r20

![image](https://github.com/user-attachments/assets/425a7071-213e-4d05-9d69-6a7a3b0847a8)


Final Output

![image](https://github.com/user-attachments/assets/54d92552-37f3-4aa4-bbd5-643e162b2ccc)
</details>

***

<details>
  <summary>Laboratory 5: The application that I chose is an 8-bit Counter with the following features:
    
   1. Bidirectional Counting.
   2. User can input start and stop values.
   3. Provision for wrap around, in case of underlow/overflow of counter value.

   The following tasks have been performed:
   
   1. Uploading of C program.
   2. Compile with GCC, RISCV-GCC and Spike.
   3. Uploading of relevant screenshots.
   </summary>
   
**Step 1:** Create a file by the name counter_8bit.c using gedit editor, type in the code, and save the file.
![image](https://github.com/user-attachments/assets/96002e3c-effe-41a9-921a-178e22652a9b)

```
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>  // For usleep()

void delay(unsigned int milliseconds) {
    volatile unsigned int count;
    unsigned int end = milliseconds * 1000;  // Adjust multiplier as necessary for your system
    for (count = 0; count < end; count++) {
        // Busy-wait loop
    }
}

// Function to print an 8-bit integer in binary format
void printBinary(uint8_t num) {
    for (int i = 7; i >= 0; i--) {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
}

// Function to print the counter value in both decimal and binary
void printCounter(uint8_t counter) {
    printf("Counter: %03u, Binary: ", counter);
    printBinary(counter);
    printf("\n");
}

// Bidirectional counter function
void bidirectionalCounter(uint8_t startValue, uint8_t stopValue, int direction) {
    uint8_t counter = startValue;
    printf("\nDirection: %s\n",(direction?"Up":"Down"));
    printf("Starting from: %u\n",startValue);
   
    while (1) {
        // Print the current counter value
        printCounter(counter);

        // Check if we reached the stop value
        if (counter == stopValue) {
            printf("Reached stop value: %u\n", stopValue);
            break;
        }

        // Adjust the counter based on the direction
        if (direction == 1) { // Counting up
            counter++;
            if (counter == 0) { // Overflow condition
                printf("Counter overflowed, wrapping around...\n");
            }
        } else if (direction == 0) { // Counting down
            counter--;
            if (counter == 255) { // Underflow condition
                printf("Counter underflowed, wrapping around...\n");
            }
	}

        // Delay for better readability (Sleep for 100 milliseconds)
        //usleep(100 * 1000);
	delay(100);
    }
}

int main() {
    uint8_t startValue, stopValue;
    int direction;

    printf("This is an 8 bit bidirectional counter\n");
    // Get the initial value of the counter from the user
    printf("Enter the start 8-bit value (0-255): ");
    scanf("%hhu", &startValue);

    // Get the stop value of the counter from the user
    printf("Enter the stop 8-bit value (0-255): ");
    scanf("%hhu", &stopValue);

    // Get the direction of counting from the user
    do{
        printf("\n0 - Down Count\n");
        printf("1 - Up   Count\n");
        printf("Do not enter any other number\n");
        printf("Enter direction: ");
        scanf("%d", &direction);    
    }while(direction>1||direction<0);
   
    // Start the bidirectional counter
    bidirectionalCounter(startValue, stopValue, direction);

    return 0;
}
```

**Step 2:** Run the file using the GCC Compiler, and change the name of the executable file to counter_8bit.out
![image](https://github.com/user-attachments/assets/e628de13-6c3e-4839-ab3b-738b40a98adc)

**Step 3:** Run the executable file, and test it for various kinds of inputs, thereby demonstrating the up and down counting, overflow and underflow when counter reaches maximum and minimum value respectively.
![image](https://github.com/user-attachments/assets/45d363c9-acdd-4755-90ff-527e2f6ace35)
![image](https://github.com/user-attachments/assets/11ccaf16-5c1c-4523-a983-13c2a7f9aa02)
![image](https://github.com/user-attachments/assets/24121153-1e2f-4844-ad14-2daf7143953b)
![image](https://github.com/user-attachments/assets/4a14c26f-fa8f-4963-8eef-71f4abe4c328)
![image](https://github.com/user-attachments/assets/8b2931f7-2162-4808-aa65-53fad1967f09)
![image](https://github.com/user-attachments/assets/59537f9d-4cbc-4eff-aefb-dd3f827980a6)

**Step 4:** Now, proceed for performing the simulation using the RISCV-GCC compiler, using the O1 switch.
![image](https://github.com/user-attachments/assets/8f5c7c53-8a68-4453-bbed-5de42f6d2cd8)

**Step 5:** Perform the object dump for the file counter_8bit.o
![image](https://github.com/user-attachments/assets/e150ab74-b81a-420e-ab57-3be203e596d8)
![image](https://github.com/user-attachments/assets/df3e3719-bf43-4a3c-82d2-adbabe406f9d)

Type /main to reach to the code section that corresponds to the main function of the C program.

![image](https://github.com/user-attachments/assets/42469ddf-7d86-4b05-b2fc-7536aefcb209)
![image](https://github.com/user-attachments/assets/9bb69963-66ba-40cf-8a85-b17e93bccce2)

The number of instructions can be found out by doing the calculation (10438-10358)/4 = 38 (hexadecimal), which is 56 instructions (decimal).

![image](https://github.com/user-attachments/assets/c38919bc-e1a8-4ed7-9bc3-ba17f3a0f08b)

**Step 6:** Now, perform the simulation using spike compiler, and compare the output obtained using spike with that of the GCC compiler.
![image](https://github.com/user-attachments/assets/5d716ff5-260b-40e4-933a-df73420fe576)
![image](https://github.com/user-attachments/assets/a8d1afbf-d535-4fbb-9a31-2ede8f61f6bc)

**Step 7:** Type in the command "spike -d pk counter_8bit.o" and verify the contents of each register. In this screenshot, I have depicted the change in the value of the stack pointer, when the first instruction is executed at the starting address as mentioned in Step 5.

![image](https://github.com/user-attachments/assets/92bab34d-3adc-4530-98d8-2c09c27d97f4)

![image](https://github.com/user-attachments/assets/39b26eab-72f8-40cb-9fb4-df9ff004c47f)

The difference in stack pointer values can be observed as per the calculation depicted in the screenshot.

</details>

***

<details>
  <summary>Laboratory 6: Build 5-stage pipeplined RISC-V processor using Makerchip IDE and TL Verilog
   </summary>
	
**1. Combinational Logic - Calculator**
	
Implementation of a basic combinational calculator.

```
   $val1[31:0] = $rand1[3:0];
   $val2[31:0] = $rand2[3:0];
   
   $sum[31:0] =  $val1[31:0] +  $val2[31:0];
   $diff[31:0] =  $val1[31:0] -  $val2[31:0];
   $prod[31:0] =  $val1[31:0] *  $val2[31:0];
   $quot[31:0] =  $val1[31:0] /  $val2[31:0];
   
   $out[31:0] = $sel[1] ? ($sel[0] ? $quot[31:0] : $prod[31:0])
                        : ($sel[0] ? $diff[31:0] : $sum[31:0]);
```

The screenshot of the implementation of the above code shows the generated block diagram as well as the waveform for the circuit.

![image](https://github.com/user-attachments/assets/196e3e4a-c788-4bbd-9258-95e99c636c00)

**2. Sequential Logic**
A new operator is introduced  >>no_of_clock_cycles $variable name. It provides the value of the mentioned signal, a certain number of clock cycles prior, as mentioned in the code.

We have a reset signal which will reset the output to 0 when it is pulled high.

```
$num[15:0] = *reset ? 0             // 0 if reset
                    : >>1$num + 1;  // otherwise add previous and 1
```

![image](https://github.com/user-attachments/assets/43c8fe37-4154-4b84-abdf-6eedaf996983)

The screenshot shows the implementation of the counter logic, along with the generated waveform.

**3. Pipelined Logic**
The calculator has been implemented following a pipelined design so that the circuit can be operated at higher clock frequencies. The multiplexer introduced to select the operation is shifted to the next clock cycle so that the calculator logic can operate at higher frequencies.

![image](https://github.com/user-attachments/assets/38f394df-56e9-47e5-906f-40e457f8d2e0)

```
|calc
      @1
         $reset = *reset;
   
         $val1[31:0] = >>2$out[31:0];
         $val2[31:0] = $rand2[3:0];
         $sel[1:0] = $rand3[1:0];
   
         $sum[31:0] = $val1[31:0] + $val2[31:0];
         $diff[31:0] = $val1[31:0] - $val2[31:0];
         $prod[31:0] = $val1[31:0] * $val2[31:0];
         $quot[31:0] = $val1[31:0] / $val2[31:0];
            
         $count = $reset ? 0 : >>1$count + 1;
         
      @2
         $valid = !$count;
         $calc_reset = $reset | $valid;
         $out[31:0] = $calc_reset ? 32'b0
                                  : ($sel[1] ? ($sel[0] ? $quot[31:0] 
                                                        : $prod[31:0])
                                             : ($sel[0] ? $diff[31:0] 
                                                        : $sum[31:0]));
```
**4. Validity**

When generating waveforms, we typically get results for all clock cycles. While there may be no compilation errors, logical errors can still occur, which are difficult to debug by simply analyzing the waveforms. Additionally, there can be "don't care" conditions that are insignificant and should be ignored. To handle this, we use Validity.

The global clock runs continuously, but sometimes certain processes don't need to execute during every clock cycle. However, they might still run due to the clock signal, consuming unnecessary power. In complex circuits, this can lead to significant power waste. To reduce power consumption, we use clock gating, which stops the clock during such cycles. Validity helps us manage this process.

```
$reset = *reset;
   |calc
      @1
         $clk_aditya *clk;
         $reset = *reset;
         $valid = $reset? 0: (>>1$valid + 1); $valid_or_reset = $valid || $reset;
   ?$valid
      @1
         $val1[31:0] =>>2$result[31:0];
         $val2[31:0] = $rand2 [3:0];
      @2
         $out [31:0] = $valid_or_reset ? 32'b0:(($sel[1:0] == 2'b00) ? ($val1[31:0]+$val2[31:0]) : (($sel[1:0] == 2'b01) ? ($val1[31:0]-$val2[31:0]) : (($sel[1:0] == 2'b10) ? ($val1[31:0]*$val2[31:0]):($val1[31:0]+$val2[31:0]))));
```


![image](https://github.com/user-attachments/assets/83691d6b-1f64-4577-8b14-6fa581406b77)

**5. Total Distance Calculator**

![image](https://github.com/user-attachments/assets/4e2f5235-9129-4bb5-b219-be1bebff70e5)


**6. Implementation of a 5 staged pipelined RISC-V Core**

![image](https://github.com/user-attachments/assets/969aa4c4-0eee-472b-82a4-877fddf464b5)

**TL Verilog Program**
```
\m4_TLV_version 1d: tl-x.org
\SV
   // Template code can be found in: https://github.com/stevehoover/RISC-V_MYTH_Workshop
   
   m4_include_lib(['https://raw.githubusercontent.com/BalaDhinesh/RISC-V_MYTH_Workshop/master/tlv_lib/risc-v_shell_lib.tlv'])

\SV
   m4_makerchip_module   // (Expanded in Nav-TLV pane.)
\TLV

   /*This program sums the numbers from 1 to 10 in the same order
     Registers Used:
     r10 (a0): In: 0, Out: final sum
     r12 (a2): 10
     r13 (a3): 1 to 10
     r14 (a4): Sum
     External to function:*/
   m4_asm(ADD, r10, r0, r0)              // Initialize r10 (a0) to 0.
   // Function:
   m4_asm(ADD, r14, r10, r0)             // Initialize sum register a4 with 0x0
   m4_asm(ADDI, r12, r10, 1011)          // Store count of 10 in register a2.
   m4_asm(ADD, r13, r10, r0)             // Initialize intermediate sum register a3 with 0
   // Loop:
   m4_asm(ADD, r14, r13, r14)            // Incremental addition
   m4_asm(ADDI, r13, r13, 1)             // Increment intermediate register by 1
   m4_asm(BLT, r13, r12, 1111111111000)  // If a3 is less than a2, branch to label named <loop>
   m4_asm(ADD, r10, r14, r0)             // Store final result to register a0 so that it can be read by main program
   m4_asm(SW, r0, r10, 10000)            // Store r10 result in dmem
   m4_asm(LW, r17, r0, 10000)            // Load contents of dmem to r17
   m4_asm(JAL, r7, 00000000000000000000) // Done. Jump to itself (infinite loop). 
   m4_define_hier(['M4_IMEM'], M4_NUM_INSTRS)

   |cpu
      @0
         $reset = *reset;
         $clk_aditya = clk;
         //PC fetch - branch, jumps and loads introduce 2 cycle bubbles in this pipeline
         $pc[31:0] = >>1$reset ? '0 : (>>3$valid_taken_br ? >>3$br_tgt_pc :
                                       >>3$valid_load     ? >>3$inc_pc[31:0] :
                                       >>3$jal_valid      ? >>3$br_tgt_pc :
                                       >>3$jalr_valid     ? >>3$jalr_tgt_pc :
                                                     (>>1$inc_pc[31:0]));
         // Access instruction memory using PC
         $imem_rd_en = ~ $reset;
         $imem_rd_addr[M4_IMEM_INDEX_CNT-1:0] = $pc[M4_IMEM_INDEX_CNT+1:2];
         
         
      @1
         //Obtain instruction from Instruction Memory
         $instr[31:0] = $imem_rd_data[31:0];
         
         //Increment PC
         $inc_pc[31:0] = $pc[31:0] + 32'h4;
         
         //Decoding R,I,S,B,U,J type of instructions based on opcode [6:0]
         //Only [6:2] is used here because this implementation is for RV64I which does not use [1:0]
	 $is_r_instr = $instr[6:2] == 5'b01011 ||
                       $instr[6:2] ==? 5'b011x0 ||
                       $instr[6:2] == 5'b10100;         
	
	 $is_i_instr = $instr[6:2] ==? 5'b0000x ||
                       $instr[6:2] ==? 5'b001x0 ||
                       $instr[6:2] == 5'b11001;
         
         
         $is_s_instr = $instr[6:2] ==? 5'b0100x;
         
         $is_u_instr = $instr[6:2] ==? 5'b0x101;
         
         $is_b_instr = $instr[6:2] == 5'b11000;
         
         $is_j_instr = $instr[6:2] == 5'b11011;
         
         //Immediate value decoding
         $imm[31:0] = $is_i_instr ? { {21{$instr[31]}} , $instr[30:20]} :
                      $is_s_instr ? { {21{$instr[31]}} , $instr[30:25] , $instr[11:8] , $instr[7]} :
                      $is_b_instr ? { {20{$instr[31]}} , $instr[7] , $instr[30:25] , $instr[11:8] , 1'b0} :
                      $is_u_instr ? { $instr[31] , $instr[30:12] , { 12{1'b0}} } :
                      $is_j_instr ? { {12{$instr[31]}} , $instr[19:12] , $instr[20] , $instr[30:21] , 1'b0} :
                      >>1$imm[31:0];
         
         //Generating valid signals for each instruction field
         $rs1_or_funct3_valid    = $is_r_instr || $is_i_instr || $is_s_instr || $is_b_instr;
         $rs2_valid              = $is_r_instr || $is_s_instr || $is_b_instr;
         $rd_valid               = $is_r_instr || $is_i_instr || $is_u_instr || $is_j_instr;
         $funct7_valid           = $is_r_instr;
         
         //Decoding other instruction fields
         ?$rs1_or_funct3_valid
            $rs1[4:0]    = $instr[19:15];
            $funct3[2:0] = $instr[14:12];
         
         ?$rs2_valid
            $rs2[4:0]    = $instr[24:20];
         
         ?$rd_valid
            $rd[4:0]     = $instr[11:7];
         
         ?$funct7_valid
            $funct7[6:0] = $instr[31:25];
         
         $opcode[6:0] = $instr[6:0];
         
         //Decoding instruction in subset of base instruction set based on RISC-V 32I
         $dec_bits[10:0] = {$funct7[5],$funct3,$opcode};
         
         //Branch instructions
         $is_beq   = $dec_bits ==? 11'bx_000_1100011;
         $is_bne   = $dec_bits ==? 11'bx_001_1100011;
         $is_blt   = $dec_bits ==? 11'bx_100_1100011;
         $is_bge   = $dec_bits ==? 11'bx_101_1100011;
         $is_bltu  = $dec_bits ==? 11'bx_110_1100011;
         $is_bgeu  = $dec_bits ==? 11'bx_111_1100011;
         
         //Jump instructions
         $is_auipc = $dec_bits ==? 11'bx_xxx_0010111;
         $is_jal   = $dec_bits ==? 11'bx_xxx_1101111;
         $is_jalr  = $dec_bits ==? 11'bx_000_1100111;
         
         //Arithmetic instructions
         $is_addi  = $dec_bits ==? 11'bx_000_0010011;
         $is_add   = $dec_bits ==  11'b0_000_0110011;
         $is_lui   = $dec_bits ==? 11'bx_xxx_0110111;
         $is_slti  = $dec_bits ==? 11'bx_010_0010011;
         $is_sltiu = $dec_bits ==? 11'bx_011_0010011;
         $is_xori  = $dec_bits ==? 11'bx_100_0010011;
         $is_ori   = $dec_bits ==? 11'bx_110_0010011;
         $is_andi  = $dec_bits ==? 11'bx_111_0010011;
         $is_slli  = $dec_bits ==? 11'b0_001_0010011;
         $is_srli  = $dec_bits ==? 11'b0_101_0010011;
         $is_srai  = $dec_bits ==? 11'b1_101_0010011;
         $is_sub   = $dec_bits ==? 11'b1_000_0110011;
         $is_sll   = $dec_bits ==? 11'b0_001_0110011;
         $is_slt   = $dec_bits ==? 11'b0_010_0110011;
         $is_sltu  = $dec_bits ==? 11'b0_011_0110011;
         $is_xor   = $dec_bits ==? 11'b0_100_0110011;
         $is_srl   = $dec_bits ==? 11'b0_101_0110011;
         $is_sra   = $dec_bits ==? 11'b1_101_0110011;
         $is_or    = $dec_bits ==? 11'b0_110_0110011;
         $is_and   = $dec_bits ==? 11'b0_111_0110011;
         
         //Store instructions
         $is_sb    = $dec_bits ==? 11'bx_000_0100011;
         $is_sh    = $dec_bits ==? 11'bx_001_0100011;
         $is_sw    = $dec_bits ==? 11'bx_010_0100011;
         
         //Load instructions - support only 4 byte load
         $is_load  = $dec_bits ==? 11'bx_xxx_0000011;
         
         $is_jump = $is_jal || $is_jalr;
         
      @2
         //Get Source register values from reg file
         $rf_rd_en1 = $rs1_or_funct3_valid;
         $rf_rd_en2 = $rs2_valid;
         
         $rf_rd_index1[4:0] = $rs1[4:0];
         $rf_rd_index2[4:0] = $rs2[4:0];
         
         //Register file bypass logic - data forwarding from ALU to resolve RAW dependence
         $src1_value[31:0] = $rs1_bypass ? >>1$result[31:0] : $rf_rd_data1[31:0];
         $src2_value[31:0] = $rs2_bypass ? >>1$result[31:0] : $rf_rd_data2[31:0];
         
         //Branch target PC computation for branches and JAL
         $br_tgt_pc[31:0] = $imm[31:0] + $pc[31:0];
         
         //RAW dependence check for ALU data forwarding
         //If previous instruction was writing to reg file, and current instruction is reading from same register
         $rs1_bypass = >>1$rf_wr_en && (>>1$rd == $rs1);
         $rs2_bypass = >>1$rf_wr_en && (>>1$rd == $rs2);
         
      @3
         //ALU
         $result[31:0] = $is_addi  ? $src1_value +  $imm :
                         $is_add   ? $src1_value +  $src2_value :
                         $is_andi  ? $src1_value &  $imm :
                         $is_ori   ? $src1_value |  $imm :
                         $is_xori  ? $src1_value ^  $imm :
                         $is_slli  ? $src1_value << $imm[5:0]:
                         $is_srli  ? $src1_value >> $imm[5:0]:
                         $is_and   ? $src1_value &  $src2_value:
                         $is_or    ? $src1_value |  $src2_value:
                         $is_xor   ? $src1_value ^  $src2_value:
                         $is_sub   ? $src1_value -  $src2_value:
                         $is_sll   ? $src1_value << $src2_value:
                         $is_srl   ? $src1_value >> $src2_value:
                         $is_sltu  ? $sltu_rslt[31:0]:
                         $is_sltiu ? $sltiu_rslt[31:0]:
                         $is_lui   ? {$imm[31:12], 12'b0}:
                         $is_auipc ? $pc + $imm:
                         $is_jal   ? $pc + 4:
                         $is_jalr  ? $pc + 4:
                         $is_srai  ? ({ {32{$src1_value[31]}} , $src1_value} >> $imm[4:0]) :
                         $is_slt   ? (($src1_value[31] == $src2_value[31]) ? $sltu_rslt : {31'b0, $src1_value[31]}):
                         $is_slti  ? (($src1_value[31] == $imm[31]) ? $sltiu_rslt : {31'b0, $src1_value[31]}) :
                         $is_sra   ? ({ {32{$src1_value[31]}}, $src1_value} >> $src2_value[4:0]) :
                         $is_load  ? $src1_value +  $imm :
                         $is_s_instr ? $src1_value + $imm :
                                    32'bx;
         
         $sltu_rslt[31:0]  = $src1_value <  $src2_value;
         $sltiu_rslt[31:0] = $src1_value <  $imm;
         
         //Jump instruction target PC computation
         $jalr_tgt_pc[31:0] = $imm[31:0] + $src1_value[31:0]; 
         
         //Branch resolution
         $taken_br = $is_beq ? ($src1_value == $src2_value) :
                     $is_bne ? ($src1_value != $src2_value) :
                     $is_blt ? (($src1_value < $src2_value) ^ ($src1_value[31] != $src2_value[31])) :
                     $is_bge ? (($src1_value >= $src2_value) ^ ($src1_value[31] != $src2_value[31])) :
                     $is_bltu ? ($src1_value < $src2_value) :
                     $is_bgeu ? ($src1_value >= $src2_value) :
                     1'b0;
         
         $valid = ~(>>1$valid_taken_br || >>2$valid_taken_br || >>1$is_load || >>2$is_load || >>2$jump_valid || >>1$jump_valid);
         
         $valid_taken_br = $valid && $taken_br;
         
         $valid_load = $valid && $is_load;
         
         $jump_valid = $valid && $is_jump;
         $jal_valid  = $valid && $is_jal;
         $jalr_valid = $valid && $is_jalr;
         
         //Destination register update - ALU result or load result depending on instruction
         $rf_wr_en = (($rd != '0) && $rd_valid && $valid) || >>2$valid_load;
         $rf_wr_index[4:0] = $valid ? $rd[4:0] : >>2$rd[4:0];
         $rf_wr_data[31:0] = $valid ? $result[31:0] : >>2$ld_data[31:0];
         
      @4
         //Data memory access for load, store
         $dmem_addr[3:0]     =  $result[5:2];
         $dmem_wr_en         =  $valid && $is_s_instr;
         $dmem_wr_data[31:0] =  $src2_value[31:0];
         $dmem_rd_en         =  $valid_load;
         
      
         //Write back data read from load instruction to register
         $ld_data[31:0]      =  $dmem_rd_data[31:0];
      
   
   // Assert these to end simulation (before Makerchip cycle limit).
   //Checks if sum of numbers from 1 to 10 is obtained in reg[17]
   *passed = |cpu/xreg[17]>>10$value == (1+2+3+4+5+6+7+8+9+10);
   //Run for 200 cycles without any checks
   //*passed = *cyc_cnt > 200;
   *failed = 1'b0;
   
   // Macro instantiations for:
   //  o instruction memory
   //  o register file
   //  o data memory
   //  o CPU visualization
   |cpu
      m4+imem(@1)    // Args: (read stage)
      m4+rf(@2, @3)  // Args: (read stage, write stage) - if equal, no register bypass is required
      m4+dmem(@4)    // Args: (read/write stage)
      m4+cpu_viz(@4) // For visualisation, argument should be at least equal to the last stage of CPU logic
                     // @4 would work for all labs
\SV
   endmodule
```
**Generated Block Diagram**
1. Entire Processor
   
![image](https://github.com/user-attachments/assets/fd7fcde0-7369-4d8c-8cb5-d576176eb96d)


2. Stage 0: Program Counter\
   
![image](https://github.com/user-attachments/assets/b4474f79-ac26-452c-b638-940d17578e0e)


3. Stage 1: Instruction Fetch

![image](https://github.com/user-attachments/assets/5805fa2b-4346-4c40-9072-e32bde6f847d)


4. Stage 2: Instruction Decode
   
![image](https://github.com/user-attachments/assets/4b9224a5-431c-4c11-98ad-e3f086a00df2)


5. Stage 3: Instruction Execute
   
![image](https://github.com/user-attachments/assets/0d992f37-4275-4a9e-bc28-9a6fb6929d50)


7. Stage 4: Memory Access and Stage 5: Writeback
   
![image](https://github.com/user-attachments/assets/1abe25e5-bf45-451f-b2ad-20a5eb7faff8)

8. XREG
   
![image](https://github.com/user-attachments/assets/3c238e51-aa9c-4495-aa51-fb4166f94405)


**Generated Waveforms**

![image](https://github.com/user-attachments/assets/e63a77ad-eace-412c-ae39-ec4d1e2e6058)

The below screenshot depict the addition of numbers 1 to 10 into the register R14, after every 5 clock cycles starting from 12th clock cycle

Also, the below code which acts as the testbench can also be viewed in these screenshots at register 17.
```
*passed = |cpu/xreg[17]>>10$value == (1+2+3+4+5+6+7+8+9+10);
```

![image](https://github.com/user-attachments/assets/788e235d-99ff-4217-8893-b04cbe9c4d4c)



**Visualization**

We can view the changing of values in each of the registers as the program is executed.
![image](https://github.com/user-attachments/assets/e082d633-c815-4d02-a615-3a3e19b42a9d)

</details>

***

<details>
  <summary>Laboratory 7: Using the TL Verilog Program written in the previous laboratory, convert the TL Verilog Program to Verilog Program using Sandpiper. Write a testbench using sample testbench for rvmyth. Use iverilog to simulate and gtkwave to view the output waveforms. Plot below signals from gtkwave 

1) Clock signal appended with your name
2) Reset signal
3) 10-bit output which shows the gradual addition of 1 to 10

The above waveforms should match with your TLV waveform.
   </summary>

  
**Step 1:** Install These Required Packages:

```
sudo apt install make python python3 python3-pip git iverilog gtkwave docker.io
sudo chmod 666 /var/run/docker.sock
cd ~
pip3 install pyyaml click sandpiper-saas
python3 -m venv .venv
source ~/.venv/bin/activate
```

**Step 2:** git clone ```https://github.com/manili/VSDBabySoC.git``` - clone this repo containing VSDBabySoC design files and testbench.

**Step 3:** cd /home/vsduser/VSDBabySoC/src/module

**Step 4:** ```sandpiper-saas –I /home/vsduser/VSDBabySoC/src/module/adi_riscv.tlv -o rvmyth.v --bestsv --noline -p Verilog --outdir /home/vsduser/VSDBabySoC/src/module```
![image](https://github.com/user-attachments/assets/8384c21a-8408-487c-9e81-96642ee50c85)
This command translates .tlv definition of the RISCV processor created using Makerchip into .v definition.

![image](https://github.com/user-attachments/assets/b65cb070-8fb4-4644-b843-443bc7268697)


**Step 5:** ```iverilog –g2005-sv –o pre_synth_sim.out –DPRE_SYNTH_SIM testbench.v –I /home/vsduser/VSDBabySoC/src/include –I /home/vsduser/VSDBabySoC/src/module –s vsdbabysoc_tb ```

This command compiles and simulates the rvmyth.v design.

![image](https://github.com/user-attachments/assets/e4cf2195-69be-4a5b-9283-17befad02745)


**Step 6:** Run the vvp and gtkwave commands as shown in previous screenshots to view the output waveforms. 

**Output Waveform**
1. Sandpiper-saas and iverilog

![image](https://github.com/user-attachments/assets/7f663f28-320f-4303-a08e-818b19fbed6b)

<li>clk_aditya: This is the clock input to the RISC-V design.</li>
<li>reset: This is the input reset signal to the RISC-V design.</li>
<li>OUT[9:0]: This is the 10-bit output port of the RISC-V design, which corresponds to the RISC-V register #14 (xreg[14]).</li>

2. TL-Verilog and Makerchip

![image](https://github.com/user-attachments/assets/c459a9cd-f592-41b6-8eec-3829cdc472f5)

![image](https://github.com/user-attachments/assets/788e235d-99ff-4217-8893-b04cbe9c4d4c)

The output of iverilog and Makerchip (TL-Verilog) are found to be the same.

</details>

***

<details>
  <summary>Laboratory 8: Using the Verilog Program written in the previous laboratory, convert the digital output from the Verilog Program file to an analog output using DAC and PLL. Use iverilog to simulate and gtkwave to view the output waveforms. Plot below signals from gtkwave: 
	  
	<li> 1) Clock signal appended with your name</li>
	<li> 2) Reset signal</li>
	<li> 3) 10-bit output which shows the gradual addition of 1 to 10</li>
	<li> 4) DAC output analog waveform</li>
	<li> 5) PLL clock input signal</li>
	<li> 6) Your laptop username identifier and dates is clear</li> 

   </summary>

**Step 1:** Install yosys

```
sudo apt-get update
git clone https://github.com/YosysHQ/yosys.git
cd yosys
sudo apt install make (If make is not installed please install it) 
sudo apt-get install build-essential clang bison flex \
    libreadline-dev gawk tcl-dev libffi-dev git \
    graphviz xdot pkg-config python3 libboost-system-dev \
    libboost-python-dev libboost-filesystem-dev zlib1g-dev
make config-gcc
make 
sudo make install
```

**Step 2:** Install iverilog

```
sudo apt-get update
sudo apt-get install iverilog
```

**Step 3:** Install gtkwave

```
sudo apt-get update
sudo apt install gtkwave
```

**Step 4:** Clone files from the repository for BabySoC Simulation

```
git clone https://github.com/Subhasis-Sahu/BabySoC_Simulation/
```

**Step 5:** Install Sandpiper-saas and python

```
sudo apt install make python python3 python3-pip git iverilog gtkwave
cd ~
sudo apt-get install python3-venv
python3 -m venv .venv
source ~/.venv/bin/activate
pip3 install pyyaml click sandpiper-saas
```

**Step 6:** Compile using iverilog, run using vvp, and view the waveform generated using GTKWave.

```
cd BabySoC_Simulation
iverilog -o ./pre_synth_sim.out -DPRE_SYNTH_SIM src/module/testbench.v -I src/include -I src/module/
vvp ./pre_synth_sim.out
gtkwave pre_synth_sim.vcd
```

![image](https://github.com/user-attachments/assets/05536599-38b7-462e-8afe-4dc7fef82758)

**Output Waveform**
<li>CPU_clk_aditya_a0: This is the clock input to the RISC-V design.</li>
<li>reset: This is the input reset signal to the RISC-V design.</li>
<li>OUT[9:0]: This is the 10-bit output port of the RISC-V design, which corresponds to the RISC-V register #14 (xreg[14]).</li>
<li>OUT: This is the analog output from the DAC corresponding to the 10 bit digital input (given from the RISC-V design.</li>
<li>VCO_IN: Clock signal of the PLL.</li>

![image](https://github.com/user-attachments/assets/a9b1a008-c427-4887-8f85-c83f6554d8a9)
![image](https://github.com/user-attachments/assets/4625d0b6-4a84-4544-8fe7-bddb79c4b3a5)

It can be observed that once the addition output reaches 0x37 (55 in decimal), the output is reset to 0, and the addition process repeats itself.

![image](https://github.com/user-attachments/assets/85209f47-bc7a-4203-9674-41e21016205c)
![image](https://github.com/user-attachments/assets/3a824176-e3ba-44b3-86c8-53d876ce9e70)

**Note:** Additional waveforms depicting entire duration added to the repo upon subsequent instruction in class.

![image](https://github.com/user-attachments/assets/a342edbf-af5e-4ab1-908c-4be20145c103)

</details>

***
<details>
  <summary> Laboratory 9: Complete RTL Synthesis workshop and upload screenshots of the tasks carried out.</summary>

  <details>
	  <summary>Initial Setup</summary>
  Enter the following commands in the Ubuntu terminal as depicted in the screenshot
	  
```
sudo -i
sudo apt-get install git
ls
cd /home/aditya
mkdir VLSI
cd VLSI
git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git
cd sky130RTLDesignAndSynthesisWorkshop/verilog_files
ls
```
	  
![image](https://github.com/user-attachments/assets/8777ca74-07c7-4065-a1af-4e24337f044d)

![image](https://github.com/user-attachments/assets/9ffbc965-2be0-46d4-8ebf-d7d2d571d8fd)

We can observe the list of files present in the directory. 

![image](https://github.com/user-attachments/assets/6f4c562f-d2dc-4535-ba26-410d2282d64b)

  </details>
  
  <details>
	  <summary>Day 1:</summary>
		  
  <li>
	  Introduction to iverilog and GTKWave: This tutorial involved learning about how to simulate the design and testbench for a 2x1 multiplexer, using iverilog, and displaying the waveform on GTKWave.
	  
	
      ![image](https://github.com/user-attachments/assets/ae5b3203-97fc-48df-9c8d-e906ab818aeb)
   	  
      ![image](https://github.com/user-attachments/assets/d0f40acb-90b8-4376-83c7-2e02c1af1424)

  ```
  //Design 
  module good_mux (input i0, input i1, input sel, output reg y);
	  always@(*)
	  begin
	  	if(sel)
			y<=i1;
		else
			y<=i0;
	  end
  endmodule
  //Testbench
  module tb_good_mux;
	reg i0,i1,sel;
	wire y;

     	good_mux uut(.sel(sel),.i0(i0),.i1(i1),.y(y));

	initial begin
		$dumpfile("tb_good_mux.vcd");
		$dumpvars(0,tb_good_mux);
		sel=0;
		i0=0;
		i1=0;
		#300 $finish;
	end
	always #75 sel = ~sel;
	always #10 i0 = ~i0;
	always #55 i1 = ~i1;
  endmodule
  ```
  </li>
  <li>
	  Introduction to Yosys: This tutorial involved the use of Yosys for synthesising the design we created in Verilog, viewing its netlists and the cells that are generated for the purpose of creating the circuit. The following commands are used:

   ```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog good_mux.v
4. synth -top good_mux
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. show
7. write_verilog -noattr good_mux_netlist.v
8. gvim good_mux_netlist.v
  ```

1. Opens Yosys Tool
2. Reads the technology library file (Liberty format) required for synthesis using the specified path.
3. Loads the Verilog file good_mux.v for synthesis.
4. Performs synthesis on the design, with good_mux as the top module.
5. Optimizes the synthesized design using the ABC tool and the specified technology library.
6. Displays the synthesized design as a schematic.
7. Writes the synthesized netlist to the file good_mux_netlist.v without attributes.
8. Opens the netlist file good_mux_netlist.v in the gvim text editor.

```
//Generated Netlist
module good_mux(i0, il, sel, y);
	wire _0_;
	wire _1_;
	wire _2_;
	wire_3_;
	input i0; wire i0;
	input il; wire il;
	input sel; wire sel;
	output y; wire y;
	
	sky130_fd_sc_hd__mux2_1 _4_ (.AO(_0_),.A1(_1_),.S(_2_),.X(_3_));
	
	assign_0_ = 10;
	assign 1 = il;
	assign 2 = sel;
	assign y = _3_;
endmodule
```

![image](https://github.com/user-attachments/assets/e62bdc94-a02c-453e-adf2-99e7047e66b7)

![image](https://github.com/user-attachments/assets/3621042d-9789-4bb3-b66f-71f2f03df78b)

![image](https://github.com/user-attachments/assets/7a2dba22-e0a8-4575-88af-f3316952b6f2)

![image](https://github.com/user-attachments/assets/77e9b19e-365c-498a-b23a-55f9a174c580)

![image](https://github.com/user-attachments/assets/7ffa1ad6-3994-46cc-885a-eb5b5ddce25b)

![image](https://github.com/user-attachments/assets/03d0b4d4-42be-498c-82e1-020a2ab56fae)

![image](https://github.com/user-attachments/assets/6fd94223-82b3-4997-a83a-db94a6508217)

![image](https://github.com/user-attachments/assets/4a42f1e0-786f-49be-af5f-7fd8f7f438ad)

![image](https://github.com/user-attachments/assets/0ecdb6cf-cf44-4cec-8732-001488c982da)

![image](https://github.com/user-attachments/assets/94c76080-b1fe-4c7c-86af-7782b39101a0)

![image](https://github.com/user-attachments/assets/b7eafdaf-61d3-45ad-b09f-63c3f917c343)

  </li>
  
  </details>

  <details>
	  <summary>Day 2:</summary>
  
<li>
	   Yosys Synthesis for Multiple Modules: This tutorial involved the synthesis of a design file that has more than one module.

```
//Design

module sub_module2 (input a, input b, output y);
	assign y = a | b;
endmodule

module sub_module1 (input a, input b, output y);
	assign y = a&b;
endmodule

module multiple_modules (input a, input b, input c, output y);
	wire net1;
	sub_module1 u1(.a(a),.b(b),.y(net1)); //net1 = a&b
	sub_module2 u2(.a(net1),.b(c),.y(y)); //y = netic,ie y = a&b + c;
endmodule
```

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog multiple_modules.v
4. synth -top multiple_modules
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. show
7. write_verilog -noattr multiple_modules_netlist.v
8. gvim multiple_modules_netlist.v
```

   </li>

```
//Generated Netlist
module multiple_modules (a, b, c, y);
	input a; wire a;
	input b; wire b;
	input c; wire c;
	wire net1;
	output y; wire y;

	sub_modulel ul (.a(a),.b(b),.y(net1));
	sub_module2 u2 (.a(net1),.b(c),.y (y));
endmodule

module sub_modulel (a, b, y);
	wire _0_;
	wire _1_;
	wire _2_;
	input a; wire a;
	input b; wire b;
	output y; wire y;
	
	sky130_fd_sc_hd_and2_0_3_(.A(_1_),.B(_0_),.X(_2_));
	
	assign _1_ = b;
	assign _0_ = a;
	assign y = _2_;
endmodule

module sub_module2 (a, b, y);
	wire _0_;
	wire _1_;
	wire _2_;
	input a; wire a;
	input b; wire b;
	output y;wire y;

	sky130_fd_sc_hd_or2_0_3_ (A(_1_), .B( 0 ), .X( 2 ));
	assign _1_ = b;
	assign _0_ = a;
	assign y = _2_;
endmodule
```


![image](https://github.com/user-attachments/assets/d4e15e80-521d-4421-b403-5c539c6f6419)

![image](https://github.com/user-attachments/assets/f8ecbbc6-1f71-4a49-a3cd-d06bd4760b62)

![image](https://github.com/user-attachments/assets/4b63f6e1-23d2-42f5-8627-fdb4d697382e)

![image](https://github.com/user-attachments/assets/7e9b0cd5-09b5-48cd-93a2-5d55912a9d50)

<li>
	Use of Module Level Synthesis: This method is preferred when multiple instances of same module are used. The synthesis is carried out once and is replicate multiple times, and the multiple instances of the same module are stitched together in the top module. This method is helpful when making use of divide and conquer algorithm

 ```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog multiple_modules.v
4. synth -top sub_module1
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. show
```
![image](https://github.com/user-attachments/assets/16d03a83-5c76-4f37-8d16-1f61caa6b9cc)

![image](https://github.com/user-attachments/assets/8830a132-281b-41d7-8a91-07650d70e43a)

![image](https://github.com/user-attachments/assets/a206cede-1922-4e6b-8e1d-56d824eea294)

</li>

<li>
	Use of Flattening: Merges all hierarchical modules in the design into a single module to create a flat netlist.
 ```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog multiple_modules.v
4. synth -top multiple_modules
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. flatten
7. show
8. write_verilog -noattr multiple_modules_netlist.v
9. gvim multiple_modules_netlist.v
```

```
//Generated Netlist
module multiple_modules (a, b, c, y);
	wire _0_; wire _1_;
	wire _2_; wire _3_;
	wire _4_; wire _5_;
	input a; wire a;
	input b; wire b;
	input c; wire c;
	wire net1;
	wire \ul.a;
	wire \ul.b;
	wire \ul.y;
	wire \u2.a;
	wire \u2.b;
	wire \u2.y;
	output y; wire y;
	
	sky130_fd_sc_hd_and2_0 _6_ (.A(1),.B(0),.X(_2_));
	sky130_fd_sc_hd_or2_0 _7_(.A(4),.B(_3_),.X(5));

	assign 4 = \u2.b ;
	assign 3 = \u2.a ;
	assign \u2.y = _5_;
	assign \u2.a = net1;
	assign \u2.b = c;
	assign y = \u2.y;
	assign 1 = \u1.b;
	assign 0 = \ul.a ;
	assign \ul.y = _2_;
	assign \ul.a = a;
	assign \u1.b = b;
	assign net1 = \u1.y;
endmodule
```

![image](https://github.com/user-attachments/assets/661565e9-fa5b-4821-ac2f-10bd779b2d2f)

![image](https://github.com/user-attachments/assets/8f88f1ff-6c93-4e3b-a896-544c019cf397)

</li>

<li>
	Simulation of D-Flipflop using Iverilog and GTKWave: Performed simulations for 3 types of D-Flipflops - Asynchronous Reset, Asynchronous Set and Synchronous Reset.

Asynchronous Reset

```
iverilog dff_asyncres.v tb_dff_asyncres.v
./a.out
gtkwave tb_dff_asyncres.vcd
```

```
//Design
module dff_asyncres(input clk, input async_reset, input d, output reg q);
	always@(posedge clk, posedge async_reset)
	begin
		if(async_reset)
			q <= 1'b0;
		else
			q <= d;
	end
endmodule
//Testbench
module tb_dff_asyncres; 
	reg clk, async_reset, d;
	wire q;
	dff_asyncres uut (.clk(clk),.async_reset (async_reset),.d(d),.q(q));

	initial begin
		$dumpfile("tb_dff_asyncres.vcd");
		$dumpvars(0,tb_dff_asyncres);
		// Initialize Inputs
		clk = 0;
		async_reset = 1;
		d = 0;
		#3000 $finish;
	end
		
	always #10 clk = ~clk;
	always #23 d = ~d;
	always #547 async_reset=~async_reset; 
endmodule
```

![image](https://github.com/user-attachments/assets/27de48d3-f468-412e-9270-07c14601cecc)

![image](https://github.com/user-attachments/assets/c460d114-b811-4ccc-b4f8-84e3402ebaf7)

      From the waveform, it can be observed that the Q output changes to zero when the asynchronous reset is set high, independent of the positive/negative clock edge.

Asynchronous Set

```
iverilog dff_async_set.v tb_dff_async_set.v
./a.out
gtkwave tb_dff_async_set.vcd
```

```
//Design
module dff_async_set(input clk, input async_set, input d, output reg q);
	always@(posedge clk, posedge async_set)
	begin
		if(async_set)
			q <= 1'b1;
		else
			q <= d;
	end
endmodule
//Testbench
module tb_dff_async_set; 
	reg clk, async_set, d;
	wire q;
	dff_async_set uut (.clk(clk),.async_set (async_set),.d(d),.q(q));

	initial begin
		$dumpfile("tb_dff_async_set.vcd");
		$dumpvars(0,tb_dff_async_set);
		// Initialize Inputs
		clk = 0;
		async_set = 1;
		d = 0;
		#3000 $finish;
	end
		
	always #10 clk = ~clk;
	always #23 d = ~d;
	always #547 async_set=~async_set; 
endmodule
```

![image](https://github.com/user-attachments/assets/149d288a-97e1-43a8-8871-bedd91fb7bac)

![image](https://github.com/user-attachments/assets/947cf6da-f236-4cea-b2e8-620fee2dfe78)

From the waveform, it can be observed that the Q output changes to one when the asynchronous set is set high, independent of the positive/negative clock edge.

Synchronous Reset

```
iverilog dff_syncres.v tb_dff_syncres.v
./a.out
gtkwave tb_dff_syncres.vcd
```

```
//Design
module dff_syncres(input clk, input sync_reset, input d, output reg q);
	always@(posedge clk)
	begin
		if(sync_reset)
			q <= 1'b0;
		else
			q <= d;
	end
endmodule
//Testbench
module tb_dff_syncres; 
	reg clk, syncres, d;
	wire q;
	dff_asyncres uut (.clk(clk),.sync_reset (sync_reset),.d(d),.q(q));

	initial begin
		$dumpfile("tb_dff_syncres.vcd");
		$dumpvars(0,tb_dff_syncres);
		// Initialize Inputs
		clk = 0;
		sync_reset = 1;
		d = 0;
		#3000 $finish;
	end
		
	always #10 clk = ~clk;
	always #23 d = ~d;
	always #547 sync_reset=~async_reset; 
endmodule
```
      
![image](https://github.com/user-attachments/assets/78430bfa-a730-4ef5-9d26-49e3517b7584)

![image](https://github.com/user-attachments/assets/a8ca2d39-44d4-462d-9ab3-b9211dc6e758)

From the waveform, it can be observed that the Q output changes to zero when the synchronous reset is set high, only at the positive clock edge.

</li>

<li>
	Synthesis of D-Flipflop using Yosys: Synthesized 3 types of D-Flipflops - Asynchronous Reset, Asynchronous Set and Synchronous Reset.
	
Asynchronous Reset
	
```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog dff_asyncres.v
4. synth -top dff_asyncres
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
8. write_verilog -noattr dff_asyncres_netlist.v
9. gvim dff_asyncres_netlist.v
```

```
//Generated Netlist   		
module dff_asyncres (clk, async_reset, d, q);
	wire _0_;
	wire _1_;
	wire _2_;
	input async_reset;
	input clk;
	input d;
	output q;
	
	sky130_fd_sc_hd__clkinv_1 _3_ (.A(_0_),.Y(_1_));
	sky130_fd_sc_hd__dfrtp_1 _4_ (.CLK(clk),.D(d),.RESET_B(_2_),.Q(q));
	assign _0_ = async_reset;
	assign _2_ = _1_;
endmodule
```

![image](https://github.com/user-attachments/assets/6f67adf6-ebc1-49a4-b8b0-ae1a09f76897)

![image](https://github.com/user-attachments/assets/20a15008-6b31-49e5-b2c4-9ae3d1bfdb55)

![image](https://github.com/user-attachments/assets/d3723b64-5e45-4589-996b-20d327de7485)

Asynchronous Set		
  
```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog dff_async_set.v
4. synth -top dff_async_set
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
8. write_verilog -noattr dff_async_set_netlist.v
9. gvim dff_async_set_netlist.v
```

```
//Generated Netlist   		
module dff_async_set (clk, async_set, d, q);
	wire _0_;
	wire _1_;
	wire _2_;
	input async_set;
	input clk;
	input d;
	output q;
	
	sky130_fd_sc_hd__clkinv_1 _3_ (.A(_0_),.Y(_1_));
	sky130_fd_sc_hd__dfrtp_1 _4_ (.CLK(clk),.D(d),.RESET_B(_2_),.Q(q));
	assign _0_ = async_set;
	assign _2_ = _1_;
endmodule
```

![image](https://github.com/user-attachments/assets/2e048513-b8cd-460a-972c-b119e13efef6)

![image](https://github.com/user-attachments/assets/eb6a5cdd-911c-41b6-939e-5e35686ccd32)

![image](https://github.com/user-attachments/assets/f37b4790-3647-4441-ad3f-466a34e98cd3)

Synchronous Reset
  
```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog dff_syncres.v
4. synth -top dff_syncres
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
8. write_verilog -noattr dff_syncres_netlist.v
9. gvim dff_syncres_netlist.v
```

```
//Generated Netlist   		
module dff_syncres (clk, sync_reset, d, q);
	wire _0_;
	wire _1_;
	wire _2_;
	input sync_reset;
	input clk;
	input d;
	output q;
	
	sky130_fd_sc_hd__clkinv_1 _3_ (.A(_0_),.Y(_1_));
	sky130_fd_sc_hd__dfrtp_1 _4_ (.CLK(clk),.D(d),.RESET_B(_2_),.Q(q));
	assign _0_ = sync_reset;
	assign _2_ = _1_;
endmodule
```

![image](https://github.com/user-attachments/assets/18154798-941b-485a-964c-be8bba5e15de)

![image](https://github.com/user-attachments/assets/77d3b495-0921-4eab-82c4-4c830914516c)

![image](https://github.com/user-attachments/assets/c3b424e1-c096-47d8-92e1-c54265a7fd36)

</li>

<li>
	Multiplication by 2: This tutorial, we get to know that specific multiplier hardware is not required for multiplication of a number by 2. It can simply be achieved by concatenating the number itself with a zero in the LSB.
 
```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog mult_2.v
4. synth -top mul2
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. show
7. write_verilog -noattr mul2_net.v
8. gvim mul2_net.v
```

```
//Design
module mul2(input [2:0]a, output [3:0]y);
	assign y=a*2;
endmodule
```

```
//Generated Netlist
module mul2(a,y);
	input [2:0]a; wire [2:0]a;
	output [3:0]y; wire [3:0]y;

	assign y = {a,1'h0};
endmodule
```

![image](https://github.com/user-attachments/assets/363e6e5f-f149-4aee-b099-5ac296d5a5f9)

![image](https://github.com/user-attachments/assets/8ee2e9b1-2555-4bf6-a5f2-738a3df609f8)

</li>

<li>
	Multiplication by 9: This tutorial, we get to know that specific multiplier hardware is not required for multiplication of a number by 9. It can simply be achieved by concatenating the number with itself.
 
```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog mult_9.v
4. synth -top mult9
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. show
7. write_verilog -noattr mul9_net.v
8. gvim mul9_net.v
```

```
//Design
module mul2(input [2:0]a, output [5:0]y);
	assign y=a*9;
endmodule
```

```
//Generated Netlist
module mul9(a,y);
	input [2:0]a; wire [2:0]a;
	output [5:0]y; wire [5:0]y;

	assign y = {a,a};
endmodule
```

![image](https://github.com/user-attachments/assets/7c8bdc00-111c-45ac-88d2-cd7a2cf04fd1)

![image](https://github.com/user-attachments/assets/c7eabb0a-48f5-417e-810c-928e4787ea87)

</li>

    
  </details>

  <details>
	  <summary>Day 3:</summary>
Optimization of Various Designs

<li>
	Design infers 2 input AND Gate:

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog opt_check.v
4. synth -top opt_check
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. show
```

5. Removes unused or redundant logic in the design and purges any dangling wires or gates.
 
```
//Design
module opt_check(input a, input b, output y);
	assign y = a?b:0;
endmodule
```

![image](https://github.com/user-attachments/assets/3d6a54bf-3ec3-4095-a20a-1f7862c3ca32)

![image](https://github.com/user-attachments/assets/fcb82f85-0790-451b-90d6-4c30e2794809)

![image](https://github.com/user-attachments/assets/b40e05e1-29db-44eb-a7b3-f92fb600f90a)

</li>

<li>
	Design infers 2 input OR Gate:

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog opt_check2.v
4. synth -top opt_check2
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. show
```

```
//Design
module opt_check2(input a, input b, output y);
	assign y = a?1:b;
endmodule
```

![image](https://github.com/user-attachments/assets/9c69e45d-e424-4be4-9e0e-971e88f7ba74)

![image](https://github.com/user-attachments/assets/45223852-6776-4739-a70e-b0d96e3686b4)

![image](https://github.com/user-attachments/assets/68b48765-8b90-4cf9-a1f0-66615b9c08bd)

</li>	

<li>
	Design infers 3 input AND Gate:

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog opt_check3.v
4. synth -top opt_check3
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. show
```

```
//Design
module opt_check2(input a, input b, input c, output y);
	assign y = a?(b?c:0):0;
endmodule
```

![image](https://github.com/user-attachments/assets/169f2928-8098-4907-8178-2e75e5843005)

![image](https://github.com/user-attachments/assets/5d21faca-631d-4fb3-847f-2b741d26d39b)


</li>

<li>
	Design infers 2 input XNOR Gate (3 input Boolean Logic)

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog opt_check4.v
4. synth -top opt_check4
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. show
```

```
//Design
module opt_check2(input a, input b, input c, output y);
	assign y = a ? (b ? ~c : c) : ~c;
endmodule
```

![image](https://github.com/user-attachments/assets/ba9df5f9-cdcc-47db-a390-3aee5b93fe1d)

![image](https://github.com/user-attachments/assets/eda292b5-e49b-4754-8fcf-2d8cd6ffa09a)

![image](https://github.com/user-attachments/assets/c417d6af-feda-4062-9962-76bbbdaaf495)

</li>

<li>
	Multiple Module Optimization-1

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog multiple_module_opt.v
4. synth -top multiple_module_opt
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. show
```

```
//Design

module sub_module1(input a, input b, output y);
	assign y = a & b;
endmodule

module sub_module2 (input a, input b output y);
	assign y = a^b;
endmodule

module multiple_module_opt(input a, input b input c, input d output y);
	wire n1,n2, n3;

	sub_module1 U1 (.a(a), .b(1'b1), .y(n1));
	sub_module2 U2 (.a(n1), .b(1'b0), .y(n));
	sub_module2 U3 (.a(b), .b(d), .y(n3));

	assign y = c | (b & n1);
endmodule
```

![image](https://github.com/user-attachments/assets/88629e12-376e-4c2a-80b0-48ed974a0c34)

![image](https://github.com/user-attachments/assets/5ef44a01-5ebc-47ba-a633-f596bbfad2e0)

</li>

<li>
	Multiple Module Optimization-2

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog multiple_module_opt2.v
4. synth -top multiple_module_opt2
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. show
```

```
//Design
module sub_module(input a input b output y);
	assign y = a & b;
endmodule

module multiple_module_opt2(input a, input b input c, input d, output y);
	wire n1,n2, n3;

	sub_module U1 (.a(a), .b(1'b0), y(n));
	sub_module U2 (.a(b), .b(c), .y(n2));
	sub_module U3 (.a(n2), .b(d), .y(n));
	sub_module U4 (.a(n3), .b(n1), .y(y));
endmodule
```

<li>
	D-Flipflop Constant 1 with Asynchronous Reset (active low)
	
```
iverilog dff_const1.v tb_dff_const1.v
./a.out
gtkwave tb_dff_const1.vcd
```

```
//Design
module dff_const1(input clk, input reset, output reg q); 
always @(posedge clk, posedge reset)
begin
	if(reset)
		q <= 1'b0;
	else
		q <= 1'b1;
end
endmodule
//Testbench
module tb_dff_const1; 
	reg clk, reset;
	wire q;

	dff_const1 uut (.clk(clk),.reset(reset),.q(q));

	initial begin
		$dumpfile("tb_dff_const1.vcd");
		$dumpvars(0,tb_dff_const1);
		// Initialize Inputs
		clk = 0;
		reset = 1;
		#3000 $finish;
	end

	always #10 clk = ~clk;
	always #1547 reset=~reset;
endmodule
```
 
![image](https://github.com/user-attachments/assets/02b17971-01cb-4fc4-8315-21f9e17fa47d)

![image](https://github.com/user-attachments/assets/c5545f8c-5036-446e-94e6-64a6f177ea99)

From the waveform, it can be observed that the Q output is always high when reset is zero, and reset doesn't depend on clock edge.
  
```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog dff_const1.v
4. synth -top dff_const1
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
```

![image](https://github.com/user-attachments/assets/10affe8a-44c6-4e2b-a861-5239a7fc891f)

![image](https://github.com/user-attachments/assets/b1c25388-b970-4884-aaac-5ac1eee3dbf0)

</li>

<li>
	D-Flipflop Constant 2 with Asynchronous Reset (active high)

```
iverilog dff_const2.v tb_dff_const2.v
./a.out
gtkwave tb_dff_const2.vcd
```

```
//Design
module dff_const2(input clk, input reset, output reg q); 
always @(posedge clk, posedge reset)
begin
	if(reset)
		q <= 1'b1;
	else
		q <= 1'b1;
end
endmodule
//Testbench
module tb_dff_const2; 
	reg clk, reset;
	wire q;

	dff_const2 uut (.clk(clk),.reset(reset),.q(q));

	initial begin
		$dumpfile("tb_dff_const1.vcd");
		$dumpvars(0,tb_dff_const1);
		// Initialize Inputs
		clk = 0;
		reset = 1;
		#3000 $finish;
	end

	always #10 clk = ~clk;
	always #1547 reset=~reset;
endmodule
```
 
![image](https://github.com/user-attachments/assets/a16f3a0c-92cf-4c77-bb2e-d85fac9a92e0)

![image](https://github.com/user-attachments/assets/144e8a14-8939-4dd4-95a0-12ac6c06f4f3)

From the waveform, it can be observed that the Q output is always high irrespective of reset.
  
```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog dff_const2.v
4. synth -top dff_const2
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
```

![image](https://github.com/user-attachments/assets/8d5c6e91-e19a-4c5b-8c40-860f7f03b0b2)

![image](https://github.com/user-attachments/assets/042aefa3-f668-44c8-af58-a847229745fd)

</li>

<li>
	D-Flipflop Constant 3 with Asynchronous Reset (active low)

```
//Design
module dff_const3(input clk, input reset, output reg q); 
	reg q1;

	always @(posedge clk, posedge reset)
	begin
		if(reset)
		begin
			q <= 1'b1;
			q1 <= 1'b0;
		end
		else
		begin	
			q1 <= 1'b1;
			q <= q1;
		end
	end
endmodule
```

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog dff_const3.v
4. synth -top dff_const3
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
```

![image](https://github.com/user-attachments/assets/1af1fed7-1bdb-4322-a181-e86dc215895b)

![image](https://github.com/user-attachments/assets/d3060b67-555b-497c-8fea-998b09aadbac)

This module defines a D flip-flop, for a positive edge of reset, q is set to 1 and q1 is set to 0. On each clock cycle, q1 is set to 1, and q is updated with the value of q1.


When synthesized, the design will result in a flip-flop where q becomes 1 after the first clock cycle post-reset and stays 1 afterward.

</li>

<li>
	D-Flipflop Constant 4 with Asynchronous Reset (active high)

```
//Design
module dff_const4(input clk, input reset, output reg q); 
	reg q1;

	always @(posedge clk, posedge reset)
	begin
		if(reset)
		begin
			q <= 1'b1;
			q1 <= 1'b1;
		end
		else
		begin	
			q1 <= 1'b1;
			q <= q1;
		end
	end
endmodule
```

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog dff_const4.v
4. synth -top dff_const4
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
```

![image](https://github.com/user-attachments/assets/cc66ffbe-41bd-4586-a380-e998318b0700)

![image](https://github.com/user-attachments/assets/8c71b1d1-f523-4d79-ae2f-ed1bdbd72794)

This module defines a D flip-flop that sets both q and q1 to 1 on a positive edge of reset. On each clock cycle, q1 remains 1, and q is updated with the value of q1 (which is always 1).

When synthesized, the design will result in a flip-flop where q is always 1, regardless of the reset or clock state.

</li>

<li>
	D-Flipflop Constant 5 with Asynchronous Reset

```
//Design
module dff_const5(input clk, input reset, output reg q); 
	reg q1;

	always @(posedge clk, posedge reset)
	begin
		if(reset)
		begin
			q <= 1'b0;
			q1 <= 1'b0;
		end
		else
		begin	
			q1 <= 1'b1;
			q <= q1;
		end
	end
endmodule
```

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog dff_const5.v
4. synth -top dff_const5
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
```

![image](https://github.com/user-attachments/assets/a9a40c85-1617-41fd-a020-30be33af4883)

![image](https://github.com/user-attachments/assets/20961f54-39d7-469f-9950-9a753ba71660)

This module defines a D flip-flop that resets both q and q1 to 0 on a positive edge of reset. On each clock cycle, it sets q1 to 1 and then updates q with the value of q1 (which will always be 1 after the first cycle).

When synthesized, the design will result in a flip-flop where q is always 1 after the first clock cycle post-reset.

</li>

<li>
	Counter Optimization 1:

```
//Design	
module counter_opt (input clk, input reset, output q);
	reg [2:0] count;
	assign q = count[0];
	
	always @(posedge clk,posedge reset)
	begin
		if(reset)
			count <= 3'b000;
		else
			count <= count + 1;
	end
endmodule
```

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog counter_opt.v
4. synth -top counter_opt
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
```

![image](https://github.com/user-attachments/assets/a5754bb9-dd7c-41e8-8893-1d705f3a9536)

![image](https://github.com/user-attachments/assets/e8871085-5083-4bcc-81a2-9c67b0eba6e4)
 
</li>

<li>
	Counter Optimization 2:

```
//Design	
module counter_opt2 (input clk, input reset, output q);
	reg [2:0] count;
	assign q = (count[2:0] == 3'b100);
	
	always @(posedge clk,posedge reset)
	begin
		if(reset)
			count <= 3'b000;
		else
			count <= count + 1;
	end
endmodule
```

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog counter_opt2.v
4. synth -top counter_opt2
5. dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
7. show
```

![image](https://github.com/user-attachments/assets/1915bab8-3075-4ba7-bfa3-2aa0e2b9184e)

![image](https://github.com/user-attachments/assets/5ed4c2ef-3367-4499-a9cc-900694e12fcb)
 
</li>

</li>

  </details>

  <details>
	  <summary>Day 4:</summary>
<li>
	Design of 2x1 MUX using Ternary Operator:

```
//Design
module ternary_operator_mux(input i0, input i1, input sel, output y);
	assign y = sel?i1:i0;
endmodule
```

```
iverilog ternary_operator_mux.v tb_ternary_operator_mux.v
./a.out
gtkwave tb_ternary_operator_mux.vcd
```

These commands perform iverilog and GTKWave simulation.

![image](https://github.com/user-attachments/assets/388e8b04-2b11-4e3a-9d7a-9d14a9012956)

![image](https://github.com/user-attachments/assets/666392dd-07a6-4574-9a14-3e1e6077ccf3)

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog ternary_operator_mux.v
4. synth -top ternary_operator_mux
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. write_verilog -noattr ternary_operator_mux_net.v
8. !gvim ternary_operator_mux_net.v
9. show
```

```
//Generated Netlist
module ternary_operator_mux(i0, il, sel, y);
	wire _0_;
	wire _1_;
	wire _2_;
	wire _3_;
	input i0; wire i0;
	input il; wire il;
	input sel; wire sel;
	output y; wire y;
	
	sky130_fd_sc_hd_mux2_1 _4_ (.AO(_0_),.A1(_1_),.S(_2_),.X(_3_));

	assign _0_ = i0;
	assign _1_ = il;
	assign _2_ = sel;
	assign y = _3_;
endmodule
```

![image](https://github.com/user-attachments/assets/5ef7e02d-7804-41dd-b797-565d7d1e0cf9)

```
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v ternary_operator_mux.v tb_ternary_operator_mux.v
./a.out
gtkwave tb_ternary_operator_mux.vcd
```

![image](https://github.com/user-attachments/assets/2609947f-a356-4d6b-a7c5-7891464ec069)

![image](https://github.com/user-attachments/assets/b7ddc329-1778-439d-860e-6e6e9e20afc9)

These waveforms correspond to the GATE LEVEL SYNTHESIS for the Ternary Operator MUX.

</li>	

<li>
	Design of a Bad 2x1 MUX:

```
//Design
module bad_mux(input i0, input i1, input sel, output reg y);
	always@(sel)
	begin
		if(sel)
			y <= i1;
		else
			y <= i0;
	end
endmodule
```

```
iverilog bad_mux.v tb_bad_mux.v
./a.out
gtkwave tb_bad_mux.vcd
```

![image](https://github.com/user-attachments/assets/116638fb-2dbd-46ce-aaae-b1bd6e3d59c4)

![image](https://github.com/user-attachments/assets/c236a53d-986b-416e-97b2-61626896808e)

From the waveform it can be observed that the output y changes only when there is a change in select line, completely ignoring the change in i0 and i1, which should also change the output y. Thus, this design is that of a bad MUX.

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog bad_mux.v
4. synth -top bad_mux
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. write_verilog -noattr bad_mux_net.v
8. !gvim bad_mux_net.v
9. show
```

```
//Generated Netlist
module bad_mux(i0, il, sel, y);
	wire _0_;
	wire _1_;
	wire _2_;
	wire _3_;
	input i0; wire i0;
	input il; wire il;
	input sel; wire sel;
	output y; wire y;
	
	sky130_fd_sc_hd_mux2_1 _4_ (.AO(_0_),.A1(_1_),.S(_2_),.X(_3_));

	assign _0_ = i0;
	assign _1_ = il;
	assign _2_ = sel;
	assign y = _3_;
endmodule
```

![image](https://github.com/user-attachments/assets/cc266d85-8e21-49d1-843c-96167c8ec292)

```
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v bad_mux.v tb_bad_mux.v
./a.out
gtkwave tb_bad_mux.vcd
```

![image](https://github.com/user-attachments/assets/2609947f-a356-4d6b-a7c5-7891464ec069)

![image](https://github.com/user-attachments/assets/b7ddc329-1778-439d-860e-6e6e9e20afc9)

These waveforms correspond to the GATE LEVEL SYNTHESIS for the Bad MUX.

</li>

<li>
	Blocking Caveat:

```
//Design
module blocking_caveat(input a, input b, input c, output reg d);
	reg x;

	always@(*)
	begin
		d = x & c;
		x = a | b;
	end
endmodule
```

```
iverilog blocking_caveat.v tb_blocking_caveat.v
./a.out
gtkwave tb_blocking_caveat.vcd
```

![image](https://github.com/user-attachments/assets/6811ccd8-9db9-436c-930f-6b50382c6831)

![image](https://github.com/user-attachments/assets/daf727a1-8d0c-4e5e-b626-71167015f194)

![image](https://github.com/user-attachments/assets/1ed038db-69e3-4f36-856b-964fbac274e9)


As depicted by the purple box in the waveform, when A and B go zero, the OR gate output should be zero (X equal to zero), and the AND gate output should also be zero (same as D output). But, the AND gate input of X takes the previous value of A|B equal to one, based on the design created by the blocking statement, hence the discrepancy in the output.

```
1. yosys
2. read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
3. read_verilog blocking_caveat.v
4. synth -top blocking_caveat
5. abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
6. opt_clean -purge
7. write_verilog -noattr blocking_caveat_net.v
8. !gvim blocking_caveat_net.v
9. show
```

```
//Generated Netlist
module blocking_caveat(a,b,c,d);
	wire _0_;
	wire _1_;
	wire _2_;
	wire _3_;
	wire _4_;
	input a; wire a;
	input b; wire b;
	input c; wire c;
	input d; wire d;
	output d; wire d;
	
	sky130_fd_sc_hd__o21a_1 _5_ (.A1(_2_),.A2(_1_),.B1(_3_),.X(_4_));

	assign _2_ = b;
	assign _1_ = a;
	assign _3_ = c;
	assign d = _4_;
endmodule
```

![image](https://github.com/user-attachments/assets/c6303c2a-5344-4e36-8250-3c5515c08c76)

```
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v blocking_caveat.v tb_blocking_caveat.v
./a.out
gtkwave tb_blocking_caveat.vcd
```

![image](https://github.com/user-attachments/assets/f1c71b28-c316-4250-9f23-d49187985694)

![image](https://github.com/user-attachments/assets/59ae3cd0-be44-4689-a71b-d851209aa5b6)

These waveforms correspond to the GATE LEVEL SYNTHESIS for the Blocking Caveat.

</li>

  </details>
</details>
