#include <stdio.h>
#include <string.h>

#define LIM 1024

void options(int *input);
void second_input(int list_index_input, char add_to_list[], char todo_list[][LIM]);

int main(int argc, char* argv[]){

    char todo_list[LIM][LIM] = { {"\n\t TODO LIST\n"} };
    char add_to_list[LIM];
    
    int index = 0, input, list_index_input;

    do {
    options(&input);
    if(input == 1){
        for(; index < LIM; index++){
            if(  todo_list[index][0] != '\0'){
                printf("%s\n", todo_list[index]);
            }
        }
        index = 0;
    }
    else if(input == 2){
        second_input(list_index_input, add_to_list, todo_list);
    }
    else if (input == 3){
        printf("Please Select a number to delete to the list 1-1023: ");
        scanf(" %d", &list_index_input);

        sprintf(todo_list[list_index_input], "\0", list_index_input);
    }
    else if (input == 4){
        printf("\nQuitting.. ");
        break;
    }
    else{
        printf("Invalid Input please try again! \n");
    }

    } while(input != 4);

    return 0;
}

void options(int *input){
    printf("\nWhat would you like to do? \n");
    printf("1) Look at List\n");
    printf("2) Add to List\n");
    printf("3) Delete from List\n");
    printf("4) Quit: ");

    scanf("%d", input);
}

void second_input(int list_index_input, char add_to_list[], char todo_list[][LIM]){
    printf("Please Select a number to add to the list 1-1023: ");
    scanf(" %d", &list_index_input);

    //scanf("%*[^\n]%*c"); works on some compilers only, explained it at README-c.md

    fgets(add_to_list, LIM, stdin); // explained it at README-c.md
    fgets(add_to_list, LIM, stdin);

    sprintf(todo_list[list_index_input], "%d-) ", list_index_input);// Converts

    if(list_index_input <= 9)
        strcpy(&todo_list[list_index_input][4], add_to_list);
    else if (list_index_input <= 99)
        strcpy(&todo_list[list_index_input][5], add_to_list);
    else if (list_index_input <= 999)
        strcpy(&todo_list[list_index_input][6], add_to_list);
    else
        strcpy(&todo_list[list_index_input][7], add_to_list);
}

