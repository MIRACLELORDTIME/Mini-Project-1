#include <stdio.h>
#include <stdlib.h>
#define MAX_SEATS 35

int main() {
    int seats[MAX_SEATS] = {0};
    int num_available_seats = MAX_SEATS;

    printf("Welcome to the bus reservation system!\n");

    while (1) {
        printf("\n");
        printf("Menu:\n");
        printf("1. Book a seat\n");
        printf("2. Cancel a seat\n");
        printf("3. Display available seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_available_seats == 0) {
                    printf("Sorry, all seats are booked.\n");
                    break;
                }

                int seat_num;
                printf("Enter seat number (1-35): ");
                scanf("%d", &seat_num);

                if (seat_num < 1 || seat_num > MAX_SEATS) {
                    printf("Invalid seat number.\n");
                    break;
                }

                if (seats[seat_num - 1] == 1) {
                    printf("Seat is already booked.\n");
                    break;
                }

                seats[seat_num - 1] = 1;
                num_available_seats--;
                printf("Seat booked successfully.\n");

                break;
            }
            case 2: {
                if (num_available_seats == MAX_SEATS) {
                    printf("No seats have been booked yet.\n");
                    break;
                }

                int seat_num;
                printf("Enter seat number (1-35): ");
                scanf("%d", &seat_num);

                if (seat_num < 1 || seat_num > MAX_SEATS) {
                    printf("Invalid seat number.\n");
                    break;
                }

                if (seats[seat_num - 1] == 0) {
                    printf("Seat is already empty.\n");
                    break;
                }

                seats[seat_num - 1] = 0;
                num_available_seats++;
                printf("Seat cancelled successfully.\n");

                break;
            }
            case 3: {
                printf("Number of available seats: %d\n", num_available_seats);
                for (int i = 0; i < MAX_SEATS; i++) {
                    if (seats[i] == 0) {
                        printf("Seat %d is available.\n", i + 1);
                    }
                }

                break;
            }
            case 4: {
                printf("Thank you for using the Bus Reservation System!\n");
                exit(0);

                break;
            }
            default: {
                printf("Invalid choice.\n");

                break;
            }
        }
    }

    return 0;
}
