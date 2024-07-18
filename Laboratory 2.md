**Laboratory 2:** For the C program created in Laboratory 1, compile the same using the RISCV compiler, and verify the output of the C program after execution.
(To be completed)

**Step 1:** For the file sum1ton.c created, type in the following commnand "riscv64-unknown-elf-gcc -O1 -mabi=lp64 -mach=rv64i -o sum1ton.o sum1ton.c" and press enter.
Subsequently, type "ls -ltr sum1ton.o" to check if the file has been created.
![Lab 2__Step_1](https://github.com/user-attachments/assets/b4bbf159-b1d6-4649-85ab-8ee0a0a750c9)

**Step 2:** Open a new terminal tab and write the following command as shown in the figure: 
![Lab 2__Step_2](https://github.com/user-attachments/assets/dc4fafbc-251d-4427-a7de-30b8a4117bb4)


**Step 3:** The assembly version of the C program appears. Type "/main" to jump to the area of the code that corresponds to the main function (int main()) of the C program.
![Lab 2__Step_3](https://github.com/user-attachments/assets/5431b935-a7dd-48bb-9d39-66f73be05c1a)

**Step 4:** The starting address of the instruction in the main function is 10184, and the ending address is 101B0. Each subsequent instruction, after 10184, has an increment of 4. To find the number of instructions, subtract 10184 from 101B0, and divide by 4. In this case, the number of instructions are equal to 11, as shown in the figure.
![Lab 2__Step_4](https://github.com/user-attachments/assets/44545716-936d-468d-a5e1-5bcc2840ae94)

![image](https://github.com/user-attachments/assets/664ea548-ca3b-4876-b9fd-f830a0db0ec2)


**Step 5:** Repeat Step 1, with the following change "riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -mach=rv64i -o sum1ton.o sum1ton.c" and press enter. Subsequently, repeat the rest of the procedure.
![Lab 2__Step_5](https://github.com/user-attachments/assets/1055b581-d653-475f-b871-2308520957f8)

To find the number of instructions, subtract 100B0 from 100DC, and divide by 4. In this case, the number of instructions are equal to 11, as shown in the figure.

![image](https://github.com/user-attachments/assets/a5f5f964-0177-4782-954f-bfe48b2865c2)


Final Output: The number of instructions obtained using the O1 and Ofast switching is equal to 11.
