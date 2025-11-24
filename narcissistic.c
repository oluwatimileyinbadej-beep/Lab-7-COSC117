#include <stdio.h>
#include <stdbool.h>

int get_int(char message[]);
int int_pow(int base, int power);
int int_log(int base, int number);
int get_num_digits(int number);
bool is_narcissistic(int n);
void append(int value, int arr[], int count[]);

int main(void){
        // ask user for the maximum number of digits
        int max_num_digits = get_int("What is the maximum number of digits (from 1 to 7) do you want to check for Narcissistic numbers: ");

        // validate that the maximum number of digits is within [1,7]
        if (max_num_digits > 7 || max_num_digits < 1) {
                printf("The number you provided (%d) is invalid.\n", max_num_digits);
                return 1;
        }

        // maximum number to check
        int max_number = int_pow(10, max_num_digits) - 1;

        // create an integer array that is can store up to 256 values.
        int results[256] = {0};

        // initialize the count. It is an array of a single element.
        int count_narcissistic[1] = {0};

        // TODO: check all the numbers from 1 to the maximum, and store the narcissistic numbers to results
        for (int i = 1; i <= max_number; i ++)
        {
                if (is_narcissistic(i))
                        append(i, results)

        }
        
        return 0;
        
        // print out the summary
        printf("There are %d Narcissistic numbers less than or equal to %d digits long.\n", count_narcissistic[0], max_num_digits);
        
        // final interaction with user
        int index = get_int("Which one of them do you want to see (index from 0)? ");
        
        // TODO: check if user's number is within the range ([0, largest_index]), and prints response accordingly
        if (index >= 0 && index < count_narcissistic)
        {
                printf("The Narcissitic number at index %d is %d\n", index);

        }
        else {
                printf("Error! You have to specify an index with 0, %d.\n");
        }
        
        return 0;
}

int get_int(char message[]){
        int n = 0;
        printf("%s",message);
        scanf("%d", &n);
        return n;
}

int int_pow(int base, int power){
        int n = 1;
        for(int i =0; i<power; i++) n*=base;
        return n;
}

int int_log(int base, int n){
        if (base <= 1 || n <= 0)
                return -1; // invalid input
        int result = 0;
        int value = 1;

        while (value <= n / base) {
                value *= base;
                result++;
        }

        return result;
}

int get_num_digits(int number){
        return int_log(10, number) + 1;
}

bool is_narcissistic(int n){
        int original_n = n;    
        int num_digits = get_num_digits(n);
        int sum = 0

        for (int i = 0; i < num_digits; i++;)
        {
                int last_digit = n % 10;
                int powered_digit = int_pow(num_digits);
                sum += powered_digit;
                n /= 10
        }
                return sum == original_n;
        // YOUR CODE HERE
}

void append(int value, int arr[], int count[]){
                arr [count[0]] = value; // Assigns the value to the current end of the arr
                count[0]++ // Increments the count of elements
}