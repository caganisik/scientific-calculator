#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the function for definite integral calculation
double f(double x) {
    return x * x; // Example function: f(x) = x^2
}

double trapezoidal_rule(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n; // Width of each trapezoid
    double sum = 0.5 * (func(a) + func(b)); // Sum of the first and last terms

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }

    return sum * h;
}

// Define the function for derivative calculation
double derivative(double (*func)(double), double x) {
    double h = 1e-6; // Step size
    return (func(x + h) - func(x - h)) / (2 * h); // Central difference method
}

// Define the function for limit calculation
double limit(double (*func)(double), double x) {
    return func(x);
}

int main() {
    int choice, quantity, i;
    float num, sum = 0, subtract = 0, multiply = 1, num1, num2, result, residual;
    char answer;
    char continue_choice;

    printf("Welcome to Scientific Calculator.\n");

    do {
        printf("\n");
        printf("Which mathematical operation do you want to do?\n");

        printf("1-Sum\n");
        printf("2-Subtraction\n");
        printf("3-Multiplication\n");
        printf("4-Division\n");
        printf("5-Taking Percentage\n");
        printf("6-Taking the Square Root\n");
        printf("7-Exponential Operation\n");
        printf("8-Calculate definite integral\n");
        printf("9-Calculate indefinite integral (Not Implemented)\n");
        printf("10-Calculate limit\n");
        printf("11-Calculate derivative\n");
        printf("0-Exit\n");

        printf("\n");

        printf("Please enter a number from the menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
            	printf("Exiting the calculator...\n");
            	return 0;
			case 1:
                printf("How many numbers do you want to add? ");
                scanf("%d", &quantity);
                for (i = 1; i <= quantity; i++) {
                    printf("Enter the %d number: ", i);
                    scanf("%f", &num);
                    sum += num;
                }
                printf("The sum is: %.2f\n", sum);
                sum = 0; // Reset sum for next operation
                break;

            case 2:
                printf("How many numbers do you want to subtract? ");
                scanf("%d", &quantity);
                printf("Enter the first number: ");
                scanf("%f", &subtract);
                for (i = 2; i <= quantity; i++) {
                    printf("Enter the %d number: ", i);
                    scanf("%f", &num);
                    subtract -= num;
                }
                printf("The subtraction is: %.2f\n", subtract);
                subtract = 0; // Reset subtract for next operation
                break;

            case 3:
                printf("How many numbers do you want to multiply? ");
                scanf("%d", &quantity);
                for (i = 1; i <= quantity; i++) {
                    printf("Enter the %d number: ", i);
                    scanf("%f", &num);
                    multiply *= num;
                }
                printf("The multiplication is: %.2f\n", multiply);
                multiply = 1; // Reset multiply for next operation
                break;

            case 4:
                printf("Please enter the first number (dividend): ");
                scanf("%f", &num1);
                printf("Please enter the second number (divisor): ");
                scanf("%f", &num2);

                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("The division is: %.3f\n", result);

                    printf("\nDo you want to see the residual? (Y/N): ");
                    scanf(" %c", &answer);

                    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
                        printf("Invalid input. Please enter Y or N.\n");
                        printf("\nDo you want to see the residual? (Y/N): ");
                        scanf(" %c", &answer);
                    }

                    if (answer == 'Y' || answer == 'y') {
                        residual = fmod(num1, num2);
                        printf("The residual is: %.2f\n", residual);
                    }
                }
                break;

            case 5:
                printf("Enter the number: ");
                scanf("%f", &num1);
                printf("Enter the percentage: ");
                scanf("%f", &num2);
                result = (num1 * num2) / 100;
                printf("%.2f%% of %.2f is: %.2f\n", num2, num1, result);
                break;

            case 6:
                printf("Enter the number to find the square root: ");
                scanf("%f", &num1);
                if (num1 < 0) {
                    printf("Error: Cannot find the square root of a negative number.\n");
                } else {
                    result = sqrt(num1);
                    printf("The square root of %.2f is: %.2f\n", num1, result);
                }
                break;

            case 7:
                printf("Enter the base number: ");
                scanf("%f", &num1);
                printf("Enter the exponent: ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("%.2f raised to the power of %.2f is: %.2f\n", num1, num2, result);
                break;

            case 8: {
                    double a, b;
                    int n;

                    printf("Enter the lower limit of integration (a): ");
                    scanf("%lf", &a);
                    printf("Enter the upper limit of integration (b): ");
                    scanf("%lf", &b);
                    printf("Enter the number of subintervals (n): ");
                    scanf("%d", &n);

                    double integral_result = trapezoidal_rule(f, a, b, n);

                    printf("The integral of the function from %.2f to %.2f is approximately: %.6f\n", a, b, integral_result);
                }
                break;

            case 9:
                printf("Indefinite integral calculation is not implemented.\n");
                break;

            case 10: {
                    double x;
                    printf("Enter the point to calculate the limit at: ");
                    scanf("%lf", &x);
                    double limit_result = limit(f, x);
                    printf("The limit of the function at %.2f is: %.6f\n", x, limit_result);
                }
                break;

            case 11: {
                    double x;
                    printf("Enter the point to calculate the derivative at: ");
                    scanf("%lf", &x);
                    double derivative_result = derivative(f, x);
                    printf("The derivative of the function at %.2f is: %.6f\n", x, derivative_result);
                }
                break;

            default:
                printf("Invalid choice. Please restart the calculator.\n");
                break;
        }

        printf("Do you want to perform another operation? (Y/N): ");
        scanf(" %c", &continue_choice);

    } while (continue_choice == 'Y' || continue_choice == 'y');

    printf("Exiting the calculator...\n");

    return 0;
}

