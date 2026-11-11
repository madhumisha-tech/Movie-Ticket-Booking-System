#include <stdio.h>

int main() {

    char theatres[3][30] = {
        "PVR Cinemas", "INOX", "AGS Cinemas"
    };

    char movies[3][30] = {
        "Jana nayagan", "The Odessey", "Obsession"
    };

    char timings[3][15] = {
        "10:00 AM", "2:00 PM", "6:30 PM"
    };

    // Seats for each theatre and movie
    int seats[3][3] = {
        {50, 50, 50}, // PVR
        {40, 40, 40}, // INOX
        {60, 60, 60}  // AGS
    };

    int theatreChoice, movieChoice;
    int tickets, option;

    do {

        printf("\n========== WELCOME TO MOVIE BOOKERS ==========\n");

        printf("\nSelect Theatre\n");

        for (int i = 0; i < 3; i++) {
            printf("%d. %s\n", i + 1, theatres[i]);
        }

        printf("Enter Theatre Number: ");
        scanf("%d", &theatreChoice);

        if (theatreChoice < 1 || theatreChoice > 3) {
            printf("Invalid Theatre!\n");
            continue;
        }

        printf("\nMovies Available in %s\n",
               theatres[theatreChoice - 1]);

        for (int i = 0; i < 3; i++) {

            printf("%d. %s | Time: %s | Seats: %d\n",
                   i + 1,
                   movies[i],
                   timings[i],
                   seats[theatreChoice - 1][i]);
        }

        printf("\nEnter Movie Number: ");
        scanf("%d", &movieChoice);

        if (movieChoice < 1 || movieChoice > 3) {

            printf("Invalid Movie!\n");

        } else {

            printf("Enter Number of Tickets: ");
            scanf("%d", &tickets);

            if (tickets > 0 &&
                tickets <= seats[theatreChoice - 1][movieChoice - 1]) {

                seats[theatreChoice - 1][movieChoice - 1] -= tickets;

                printf("\n===== Booking Successful =====\n");

                printf("Theatre : %s\n",
                       theatres[theatreChoice - 1]);

                printf("Movie : %s\n",
                       movies[movieChoice - 1]);

                printf("Timing : %s\n",
                       timings[movieChoice - 1]);

                printf("Tickets : %d\n", tickets);

                printf("Remaining Seats : %d\n",
                       seats[theatreChoice - 1][movieChoice - 1]);

            } else {

                printf("Sorry! Seats not available.\n");
            }
        }

        printf("\n1. Book Again");
        printf("\n2. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &option);

    } while (option == 1);

    printf("\nThank You! Visit Again.\n");

    return 0;
}
