#include "functions.hpp"


#define FILE_PATH "data\\data.txt"
#define TEMP_FILE_PATH "data\\tempdata.txt" 



int main()
{
    system("cls");
    printf("Welcome\n");
    Sleep(1000);
    system("cls");
    int choice;
    do{
        printf("1.\tAdd new students\n2.\tShow all students\n3.\tDelete all data\n4.\tSearch for a student by ID\n5.\tDelete a student by ID\n6.\tQuit\n\n\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1  :        system("cls");     AddStudent(FILE_PATH);                      break;
            case 2  :        system("cls");     ShowStudent(FILE_PATH);                     break;
            case 3  :        system("cls");     DeleteAll(FILE_PATH);                       break;
            case 4  :        system("cls");     SearchStudent(FILE_PATH);                   break;
            case 5  :        system("cls");     DeleteOne(FILE_PATH, TEMP_FILE_PATH);       break;
            case 6  :        system("cls");     exit(0);                                    break;
            default :        system("cls");     Default();                                  break;
        }
    }while(1);
}
