**Laboratory 2:** For the C program created in Laboratory 1, compile the same using the RISCV compiler, and verify the output of the C program after execution.
(To be completed)
**Step 1:** For the file sum1ton.c created, type in the following commnand "riscv64-unknown-elf-gcc -O1 -mabi=lp64 -mach=rv64i -o sum1ton.o sum1ton.c" and press enter.
Subsequently, type "ls -ltr sum1ton.o" to check if the file has been created.
![Lab 2__Step_1](https://github.com/user-attachments/assets/b4bbf159-b1d6-4649-85ab-8ee0a0a750c9)

**Step 2:** Open a new terminal tab and write the following command as shown in the figure: 
![Lab 2__Step_2](https://github.com/user-attachments/assets/dc4fafbc-251d-4427-a7de-30b8a4117bb4)


**Step 3:** The assembly version of the C program appears. Type "/main" to jump to the area of the code that corresponds to the main area of the C program.
![Lab 2__Step_3](https://github.com/user-attachments/assets/5431b935-a7dd-48bb-9d39-66f73be05c1a)

**Step 4:**

Final Output: In the above image we can observe the output to be 55 (Sum of numbers 1 to 10).
