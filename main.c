#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <colorize.h>
#include <helper_windows.h>
#include <windows.h>
#include <unistd.h>

//#define _GNU_SOURCE
#define SECOND 1000000

// queue creation
typedef struct Node {
    char data[20];
    int wordlength;
    struct Node *next;
} Node;
Node *head;

void my_callback_on_key_arrival(char c);

int len_finder(char *word) {
    int strend = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        ++strend;
    }
    return strend;
}

bool true_compare(char *str1, char *str2) {
    if (len_finder(str1) != len_finder(str2) - 1) {
        return false;
    }
    for (int i = 0; i < len_finder(str1); ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

FILE *easy_difficulty_file_maker() {
    char buffer;
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                        't', 'u', 'v', 'w', 'x', 'y', 'z'};
    FILE *fptr = fopen("easy5.txt", "w");
    FILE *fptr2 = fopen("easy7.txt", "w");
    FILE *fptr3 = fopen("easy9.txt", "w");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            int choose = rand() % 25;
            buffer = letters[choose];
            fprintf(fptr, "%c", buffer);
        }
        fprintf(fptr, "\n");
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 7; ++j) {
            int choose = rand() % 25;
            buffer = letters[choose];
            fprintf(fptr2, "%c", buffer);
        }
        fprintf(fptr2, "\n");
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            int choose = rand() % 25;
            buffer = letters[choose];
            fprintf(fptr3, "%c", buffer);
        }
        fprintf(fptr3, "\n");
    }
    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);
    return fptr;
}

FILE *med_difficulty_file_maker() {
    char buffer;
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                        't', 'u', 'v', 'w', 'x', 'y', 'z'};
    FILE *fptr = fopen("med14.txt", "w");
    FILE *fptr1 = fopen("med17.txt", "w");
    FILE *fptr2 = fopen("med19.txt", "w");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 14; ++j) {
            int choose = rand() % 25;
            buffer = letters[choose];
            fprintf(fptr, "%c", buffer);
        }
        fprintf(fptr, "\n");
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 17; ++j) {
            int choose = rand() % 25;
            buffer = letters[choose];
            fprintf(fptr1, "%c", buffer);
        }
        fprintf(fptr1, "\n");
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 19; ++j) {
            int choose = rand() % 25;
            buffer = letters[choose];
            fprintf(fptr2, "%c", buffer);
        }
        fprintf(fptr2, "\n");
    }
    fclose(fptr);
    fclose(fptr1);
    fclose(fptr2);
    return fptr;
}

FILE *hard_difficulty_file_maker() {
    char buffer;
    char letters[33] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                        't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '&', '^', '%', '$', '@', '_'};
    FILE *fptr = fopen("hard5.txt", "w");
    FILE *fptr1 = fopen("hard10.txt", "w");
    FILE *fptr2 = fopen("hard16.txt", "w");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            int choose = rand() % 32;
            buffer = letters[choose];
            fprintf(fptr, "%c", buffer);
        }
        fprintf(fptr, "\n");
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int choose = rand() % 32;
            buffer = letters[choose];
            fprintf(fptr1, "%c", buffer);
        }
        fprintf(fptr1, "\n");
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 16; ++j) {
            int choose = rand() % 32;
            buffer = letters[choose];
            fprintf(fptr2, "%c", buffer);
        }
        fprintf(fptr2, "\n");
    }
    fclose(fptr);
    fclose(fptr1);
    fclose(fptr2);
    return fptr;
}

char *random_word() {
    int file_selection;
    FILE *fptr;
    file_selection = rand() % 8;
    int word_selection;
    static char str[20];
    if (file_selection == 0) {
        fptr = fopen("easy5.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 7, SEEK_SET);
        fscanf(fptr, "%s", str);
    } else if (file_selection == 1) {
        fptr = fopen("easy7.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 9, SEEK_SET);
        fscanf(fptr, "%s", str);
    } else if (file_selection == 2) {
        fptr = fopen("easy9.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 11, SEEK_SET);
        fscanf(fptr, "%s", str);
    } else if (file_selection == 3) {
        fptr = fopen("med14.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 16, SEEK_SET);
        fscanf(fptr, "%s", str);
    } else if (file_selection == 4) {
        fptr = fopen("med17.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 19, SEEK_SET);
        fscanf(fptr, "%s", str);
    } else if (file_selection == 5) {
        fptr = fopen("med19.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 21, SEEK_SET);
        fscanf(fptr, "%s", str);
    } else if (file_selection == 6) {
        fptr = fopen("hard5.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 7, SEEK_SET);
        fscanf(fptr, "%s", str);
    } else if (file_selection == 7) {
        fptr = fopen("hard10.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 12, SEEK_SET);
        fscanf(fptr, "%s", str);
    } else if (file_selection == 8) {
        fptr = fopen("hard16.txt", "a+");
        word_selection = rand() % 9;
        fseek(fptr, word_selection * 18, SEEK_SET);
        fscanf(fptr, "%s", str);
    }
    fclose(fptr);
    return str;
}


Node **deleteHead() {
    Node *temp;
    temp = (Node *) malloc(sizeof(Node));
    temp = head;
    head = (head->next);
    free(temp);
    return &head;
}

Node *head_maker() {
    head = (Node *) malloc(sizeof(Node));
    char str[20];
    strcpy(str, random_word());
    strcpy(head->data, random_word());
    head->wordlength = len_finder(str);
    head->next = NULL;
    return head;
}

void appendNode() {
    Node *new_node = (Node *) malloc(sizeof(Node));
    Node *last = head;
    char str[20];
    strcpy(str, random_word());
    strcpy(new_node->data, str);
    new_node->wordlength = len_finder(str);
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->next = NULL;
}


void list_maker() {
    for (int i = 0; i < 18; ++i) {
        appendNode();
    }
}

void register_option() {
//    FILE *ptr;
//    ptr = fopen("info.txt", "w");
//    fclose(ptr);
    FILE *fptr;
    system("cls");
    fptr = fopen("info.txt", "a+");
    fseek(fptr, 0, SEEK_END);
//    user
    setcolor(15);
    printf("Enter User name : ");
    char user[10];
    scanf("%s", user);
//    fprintf(fptr,"fptr");
    fprintf(fptr, "%s,", user);
//    pass
    printf("Enter Password ip to 10 characters : ");
    char password[10];
    scanf("%s", password);
    fprintf(fptr, "%s,", password);
//    name
    printf("Enter Name : ");
    char name[10];
    scanf("%s", name);
    fprintf(fptr, "%s,", name);
//    age
    printf("Enter Age : ");
    char age[3];
    scanf("%s", age);
    fprintf(fptr, "%s\n", age);
    fclose(fptr);
    system("cls");
//    return fptr;
}

void signin_menu() {
    int option;
    int flag_for_register = 0;
    gotoxy(0,0);
    setcolor(3);
    printf("1.Sign In");
    gotoxy(0,2);
    setcolor(2);
    printf("2.Sign Up");
    gotoxy(0,4);
    setcolor(15);
    printf("Select: ");
    scanf("%d", &option);
    system("cls");
    if (option == 2) {
        while (option == 2) {
            register_option();
            system("cls");
            gotoxy(0,0);
            setcolor(3);
            printf("1.Sign In");
            gotoxy(0,2);
            setcolor(2);
            printf("2.Sign Up");
            gotoxy(0,4);
            setcolor(15);
            printf("Select: ");
            scanf("%d", &option);
        }
    }
    if (option == 1) {
        while (flag_for_register == 0) {
            FILE *fptr;
            fptr = fopen("info.txt", "r");
//        char user[10];
//        char pass[10];
            char buff[100];
            char user_inp[10], pass_inp[10];
            system("cls");
            printf("Enter username : ");
            scanf("%s", user_inp);
            printf("Enter Pass : ");
            scanf("%s", pass_inp);
            while (feof(fptr) == 0) {
                fscanf(fptr, "%s\n", buff);
//        printf("%s\n", buff);
//        fseek(fptr, len_finder(buff) + 1, SEEK_CUR);
                char *usertoken = strtok(buff, ",");
                char *passtoken = strtok(0, ",");
//            printf("%s %s %d %d\n", usertoken, passtoken, strcmp(usertoken, user_inp), strcmp(passtoken, pass_inp));
                if (strcmp(usertoken, user_inp) == 0) {
                    if (strcmp(passtoken, pass_inp) == 0) {
//                    printf("User : %s\npass : %s", usertoken, passtoken);
                        flag_for_register = 1;
                        break;
                    }
                }
            }
            if (flag_for_register == 0) {
                setcolor(4);
                printf("Invalid!");
                setcolor(15);
                sleep(1);
                system("cls");
            }
        }


    }

}

int play_menu() {
    int difficulty = 0;
    gotoxy(35,0);
    setcolor(15);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Login Date : %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min,
           tm.tm_sec);
    while (difficulty != 1 && difficulty != 2 && difficulty != 3 && difficulty != 4) {
        gotoxy(0, 0);
        setcolor(2);
        printf("1.EASY");
        gotoxy(0, 2);
        setcolor(6);
        printf("2.MEDIUM");
        gotoxy(0, 4);
        setcolor(4);
        printf("3.HARD");
        gotoxy(0, 6);
        setcolor(3);
        printf("4.EXIT");
        gotoxy(0, 9);
        setcolor(15);
        printf("Select difficulty : ");
        scanf("%d", &difficulty);
        system("cls");
    }
    if (difficulty == 4) {
        gotoxy(0, 0);
        setcolor(3);
        printf("Goodbye!");
        usleep(SECOND * 2);
        exit(0);
    }
    return difficulty;
}

void loading() {
    setcolor(2);
    printf("Loading ...");
    gotoxy(0, 1);
    for (int i = 0; i < 15; ++i) {
        printf("> ");
        usleep(SECOND / 10);
        printf("> ");
        usleep(SECOND / 10);
        printf("> ");
        usleep(SECOND / 10);
        printf("\x1b[2K");
        gotoxy(0, 1);
    }
    system("cls");
    setcolor(3);
    printf("Go!");
    setcolor(15);
    sleep(1);
    system("cls");
}

void loading0() {
    setcolor(2);
    gotoxy(0, 1);
    for (int i = 0; i < 10; ++i) {
        printf("Loading ");
        printf(". ");
        usleep(SECOND / 10);
        printf(". ");
        usleep(SECOND / 10);
        printf(". ");
        usleep(SECOND / 10);
        system("cls");
//        printf("\x1b[2K");
        gotoxy(0, 1);
    }
    system("cls");
    setcolor(3);
    printf("Created by Borhan_em");
    setcolor(15);
    sleep(2);
    system("cls");
}

int points = 0;

void pointdisplay() {
    gotoxy(30, 25);
    printf("Points : %d", points);
}

void frame_printer() {
    setcolor(1);
//    ofoghi 1
    gotoxy(0, 0);
    for (int i = 0; i < 30; ++i) {
        printf("%c", 196);
    }
//    ofoghi 2
    gotoxy(0, 22);
    for (int i = 0; i < 31; ++i) {
        printf("%c", 196);
    }
//    amoodi 1
    for (int j = 0; j < 22; ++j) {
        gotoxy(0, j);
        printf("%c", 179);
    }
//    amoodi 2
    for (int j = 0; j < 22; ++j) {
        gotoxy(30, j);
        printf("%c", 179);
    }
    gotoxy(0, 0);
    printf("%c", 218);
    gotoxy(30, 0);
    printf("%c", 191);
    gotoxy(0, 22);
    printf("%c", 192);
    gotoxy(30, 22);
    printf("%c", 217);
//    gotoxy(0,);
    setcolor(15);
}

void str_printer(int difficulty);

void deleteList() {
    Node *prev = head;
    while (head) {
        head = (head)->next;
        free(prev);
        prev = head;
    }
}

void play() {
    easy_difficulty_file_maker();
    med_difficulty_file_maker();
    hard_difficulty_file_maker();
//    files made
//    head made
//    deleteList();
    head_maker();
    list_maker();
//    list made
    int difficulty = play_menu();
    loading();
    str_printer(difficulty);
}

void str_printer(int difficulty) {
    Node *current = head;
    static int time = SECOND;
    static int time_counter = 0;
    frame_printer();
    static int i = 0;
    gotoxy(1, 2);
    while (current->next != NULL) {
        current = head;
        ++time_counter;
        if (time_counter == 10) {
            time_counter = 0;
            if (difficulty == 1) {
                time *= 0.8;
            } else if (difficulty == 2) {
                time *= 0.7;
            } else if (difficulty == 3) {
                time *= 0.6;
            }
        }
//        system("cls");
        for (int j = 0; j < i; ++j) {
            gotoxy(1, i - j);
            printf("\x1b[2K");
//            system("cls");
        }
        frame_printer();
        gotoxy(1, i + 1);
        printf("%s", current->data);
        for (int j = 0; j < i; ++j) {
//            usleep(time);
            current = current->next;
            gotoxy(1, i - j);
            printf("%s", current->data);
        }
        ++i;
        usleep(time);
    }
    system("cls");
    gotoxy(0, 0);
    setcolor(4);
    printf("YOU LOST\nScore : %d\nDifficulty : %d", points, difficulty);
    setcolor(15);
    usleep(SECOND * 5);
    system("cls");
    play();
//    sleep(100000000);
}


int main() {
    srand(time(0));
    easy_difficulty_file_maker();
    med_difficulty_file_maker();
    hard_difficulty_file_maker();
//    files made
    head_maker();
//    head made
    list_maker();
//    list made
    loading0();
    signin_menu();
    system("cls");
    setcolor(2);
    printf("Success!");
    sleep(1);
    setcolor(15);
    system("cls");
    int difficulty = play_menu();
    loading();

    HANDLE thread_id = start_listening(my_callback_on_key_arrival);


    str_printer(difficulty);
    WaitForSingleObject(thread_id, INFINITE);
    return 0;
}


void my_callback_on_key_arrival(char c) {
    if (c == '4') {
        system("cls");
        gotoxy(0, 0);
        setcolor(3);
        printf("Goodbye!");
        usleep(SECOND * 2);
        exit(0);
    }
    static int i = 1;
    static int j = 0;
    ++i;
    gotoxy(0, 25);
    printf("%d", len_finder(head->data));
    gotoxy(10, 25);
    pointdisplay();
    gotoxy(i - 1, 24);
    setcolor(15);
    printf("%c", c);
    if (c == 13) {
        gotoxy(0, 24);
        printf("\x1b[2K");
        i = 1;
    } else if (c == 8) {
//        gotoxy(i-1,24);
        printf(" \b");
        i -= 2;
    }
    if (head->data[j] != c) {
        --points;
        printf("\b");
        setcolor(6);
        printf("%c", c);
        setcolor(15);
    } else {
        printf("\b");
        setcolor(4);
        printf("%c", c);
        setcolor(15);
    }

    ++j;
    if (i == len_finder(head->data) + 1) {
        gotoxy(0, 24);
        deleteHead();
        appendNode();
        i = 1;
        ++points;
        printf("\x1b[2K");
        gotoxy(10, 25);
        printf("\x1b[2K");
        j = 0;
    }
}