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
