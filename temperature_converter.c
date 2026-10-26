
#include <stdio.h>

int main(void) {
    double temp, result;
    int choice;

    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter temperature: ");
    scanf("%lf", &temp);

    switch (choice) {
        case 1:
            result = temp * 9.0 / 5.0 + 32;
            break;
        case 2:
            result = (temp - 32) * 5.0 / 9.0;
            break;
        case 3:
            result = temp + 273.15;
            break;
        case 4:
            result = temp - 273.15;
            break;
        case 5:
            result = (temp - 32) * 5.0 / 9.0 + 273.15;
            break;
        case 6:
            result = (temp - 273.15) * 9.0 / 5.0 + 32;
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    if ((choice == 3 || choice == 5) && result < 0) {
        printf("Temperature is below absolute zero\n");
        return 0;
    }

    if ((choice == 4 || choice == 6) && temp < 0) {
        printf("Kelvin cannot be negative\n");
        return 0;
    }

    printf("Converted temperature = %.2f\n", result);
    return 0;
}