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





