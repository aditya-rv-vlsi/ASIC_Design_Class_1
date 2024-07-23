# ASIC_Design_Class_1
This is the Github repository of **Aditya R Venkateshwaran, MT2024502** for the ASIC Design Class of Aug 2024 to Dec 2024. The following items can be found in this repository, the name of the file indicative of the experiment number:

1. Documentation for each of the experiments conducted during the labs
2. Snapshots of the procedure of the experiments
3. Code files of the experiments

***
<details>
  <summary> Laboratory 1: Create a C program to find the sum of n natural numbers, compile it using gcc compiler. Verify the output of the C program after execution.</summary>
  <p> Step 1: Create a new sum1ton.c file in the desired directory (ASIC Class) in Linux environment.
  
  ![image](https://github.com/user-attachments/assets/a37c4825-dbf3-458a-ab23-fb4d47fb4c0d)
  
  Here, GEDIT text editor from Ubuntu is used. Write and save your C program in the text editor.
  
  ![image](https://github.com/user-attachments/assets/1ba473a9-6f80-4a4b-be7d-ebce1e5ea2a1)

  Step 2: Compile the code using GCC compiler in the terminal window of Ubuntu enivronment and ensure there are no errors during compilation.
  
  ![image](https://github.com/user-attachments/assets/8610ea53-4de6-4fa8-b3bb-af1f85dcb776)
  
  Step 3: After compilation, the executable (a.out) will be generated. Run the executable in terminal window to view the output.
  
  ![image](https://github.com/user-attachments/assets/0093d1ad-0ac6-48b1-a578-62a3863594fc)
  
  Final Output: In the above image we can observe the output to be 55 (Sum of numbers 1 to 10).</p>
</details>

***

<details>
  <summary>Laboratory 2: For the C program created in Laboratory 1, compile the same using the RISCV compiler, and verify the output of the C program after execution.</summary>

<p> 
  Step 1: For the file sum1ton.c created, type in the following commnand "riscv64-unknown-elf-    gcc -O1 -mabi=lp64 -mach=rv64i -o sum1ton.o sum1ton.c" and press enter. Subsequently, type     "ls -ltr sum1ton.o" to check if the file has been created. 
    
  ![image](https://github.com/user-attachments/assets/56e65f99-2c34-4831-a612-9bd64598013c)
  
  Step 2: Open a new terminal tab and write the following command as shown in the figure: 
  
  ![image](https://github.com/user-attachments/assets/6174745a-c5a6-4e9a-8fe4-89f2c6b81c92)
  
  Step 3: The assembly version of the C program appears. Type "/main" to jump to the area of      the code that corresponds to the main function (int main()) of the C program. 
  
  ![image](https://github.com/user-attachments/assets/5fdf05fe-8360-4daf-bbfa-c82432068ad3)
  
  Step 4: The starting address of the instruction in the main function is 10184, and the ending address is 101B0. Each subsequent instruction, after 10184, has an increment of 4. To find the number of instructions, subtract 10184 from 101B0, and divide by 4. In this case, the number of instructions are equal to 11, as shown in the figure. 
  
  ![image](https://github.com/user-attachments/assets/d88032c3-2865-4cae-bc2f-7e064c4ec5a2)
  ![image](https://github.com/user-attachments/assets/9bc622b1-597f-4805-9b76-4e01de645409)
  
  
  Step 5: Repeat Step 1, with the following change "riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -mach=rv64i -o sum1ton.o sum1ton.c" and press enter. Subsequently, repeat the rest of the procedure. 
  
  ![image](https://github.com/user-attachments/assets/95e90c78-24b1-479b-b67b-f6e594f1e668)
  
  To find the number of instructions, subtract 100B0 from 100DC, and divide by 4. In this case, the number of instructions are equal to 11, as shown in the figure.
  
  ![image](https://github.com/user-attachments/assets/3a8f94b5-438f-4c99-860e-12fce037b4fb)
  
  Final Output: The number of instructions obtained using the O1 and Ofast switching is equal to 11. 
  </p>

</details>

***

<details>
  <summary> Laboratory 3: Perform SPIKE Simulation, C Code compilation and RISC-V Object Dump and observation with -O1 and -Ofast for the C program written in Laboratory 1.</summary>
<p>
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
</p>
</details>
