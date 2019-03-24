#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "struct.cpp"



FILE *file;



/*struct etudiants 
{
    char nom[10], prenom[10];
    float note;
    int ID;
};
struct etudiants et;*/



void AddStudent(char path[60])
{
    int StudentNumber, i;
    int ID;
    int used = 1;
    printf("Enter the number of students : ");
    scanf("%d", &StudentNumber);
    for(i=0; i<StudentNumber; i++)
    {
        file = fopen(path, "ab+");
        printf("Student N%d\n", i+1);
        do{
            printf("ID (must be a number) : ");
            scanf("%d", &ID);
            while(1)
            {
                fread(&et, sizeof(et), 1, file);
                if(feof(file))
                {
                    et.ID = ID;
                    used = 0;
                    break;
                }
                if(et.ID == ID)
                {
                    printf("ID already exist, please chose another one\n");
                    break;
                }
            }
        }while(used == 1);
        printf("Name : ");
        getchar();
        gets(et.nom);
        printf("First Name : ");
        gets(et.prenom);
        printf("Score : ");
        scanf("%f", &et.note);
        fwrite(&et, sizeof(et), 1, file);
        fclose(file);
        system("cls");
    }
}



void ShowStudent(char path[60])
{
    int i;
    int found = 0;
    file = fopen(path, "rb");
    while(1)
    {
        fread(&et, sizeof(et), 1, file);
        if(feof(file))
            break;
        found = 1;
        for(i=0; i<10; i++)
        {
            printf("-");
        }
        printf("\nID : %d\n", et.ID);
        printf("First Name : %s\n", et.prenom);
        printf("Name : %s\n", et.nom);
        printf("Score : %.2f\n", et.note);
        for(i=0; i<10; i++)
        {
            printf("-");
        }
    }
    if(found == 0)
    {
        printf("No results found, the file is empty.\n");
    }
    getch();
    system("cls");
}


 
void DeleteAll(char path[60])
{
    file = fopen(path, "wb");
    fclose(file);
}



void SearchStudent(char path[60])
{
    int ID, found = 0, i;
    file = fopen(path, "rb");
    printf("enter the ID you wanna search : ");
    scanf("%d", &ID);
    while(1)
    {
        fread(&et, sizeof(et), 1, file);
        if(feof(file))
            break;
        if(et.ID == ID)
        {
            found = 1;
            for(i=0; i<10; i++)
            {
                printf("-");
            }
            printf("\nID : %d\n", et.ID);
            printf("First Name : %s\n", et.prenom);
            printf("Name : %s\n", et.nom);
            printf("Score : %d\n", et.note);
            for(i=0; i<10; i++)
            {
                printf("-");
            }            
        }
    }
    if(found == 0)
    {
        printf("No student found !\n");

    }
    getch();
    system("cls");
}



void Default()
{
    printf("Wrong choice buddy, read the menu carefully !\n");
    getch();
    system("cls");
}



void DeleteOne(char path[60], char temp_path[60])
{
    FILE *tempfile;
    int found = 0, ID, i;
    file = fopen(path, "rb");
    printf("Enter the id of the student you want to delete : ");
    scanf("%d", &ID);
    while(1)
    {
        fread(&et, sizeof(et), 1, file);
        if(feof(file))
        {
            break;
        }
        if(et.ID == ID)
        {
            found = 1;
            for(i=0; i<10; i++)
            {
                printf("-");
            }
            printf("\nID : %d\n", et.ID);
            printf("First Name : %s\n", et.prenom);
            printf("Name : %s\n", et.nom);
            printf("Score : %d\n", et.note);
            for(i=0; i<10; i++)
            {
                printf("-");
            }
        }
    }
    fclose(file);
    if(found == 0)
    {
        printf("No student found ! Check the ID again.\n");
    }
    else
    {
        printf("\nThis student's data will be deleted in 10s\n\n");
        for(i=10; i>0; i--)
        {
            printf("\r       ");
            printf("\r%d", i);
            Sleep(1000);
        }
        file = fopen(path, "rb");
        tempfile = fopen(temp_path, "wb");
        while(1)
        {
            fread(&et, sizeof(et), 1, file);
            if(feof(file))
            {
                break;
            }
            if( !(et.ID == ID) )
            {
                fwrite(&et, sizeof(et), 1, tempfile);
            }
        }
        fclose(file);
        fclose(tempfile);
        file = fopen(path, "wb");
        tempfile = fopen(temp_path, "rb");
        while(1)
        {
            fread(&et, sizeof(et), 1, tempfile);
            if(feof(tempfile))
            {
                break;
            }
            fwrite(&et, sizeof(et), 1, file);
        }
        fclose(file);
        fclose(tempfile);
        remove(temp_path);
    }
    system("cls");
}
