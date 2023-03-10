
#include <stdio.h>
#include <stdlib.h>

void find_odd_average(){
    
    int input_value;
    int element_count = 1;
    printf("Please enter positive numbers (end -1 to stop entering):\n");
    printf("%d: ", element_count);
    scanf("%d", &input_value);
    int odd_numbers = 0;
    int odd_numbers_total = 0;
    element_count += 1;
    while(input_value != -1){
        
        printf("%d: ", element_count);
        scanf("%d", &input_value);
        if(input_value % 2 == 1){
            odd_numbers += 1;
            odd_numbers_total += input_value;
        }
        element_count += 1;
    }
    float average_odd = (float)odd_numbers_total / (float)odd_numbers;
    printf("Average off odd numbers: %.2f", average_odd );
}
int find_max_distance(int num_inputs){
    
    int element_count = 1;
    int first_input;
    printf("%d : ", element_count);
    scanf("%d", &first_input);
    element_count += 1;
    int distance = -1;
    while(element_count != num_inputs + 1){
        int second_input;
        printf("%d : ", element_count);
        scanf("%d", &second_input);
        int distance_calc = abs(second_input - first_input);
        if(distance_calc >= distance){
            distance = distance_calc;
        }
        first_input = second_input;
        element_count += 1;
    }
    return distance;
}
int main()
{
    int input_distance = 5;
    printf("Please enter %d numbers:\n", input_distance);
    int ret_val = find_max_distance(input_distance);
    printf("Max dist between two consecutive nums: %d\n", ret_val);
    find_odd_average();

    return 0;
}
