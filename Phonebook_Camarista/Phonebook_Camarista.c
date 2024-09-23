#include <stdio.h>
#include <stdlib.h>

struct PhonebookEntry {
    char name[50];
    char contactNumber[15];
};

struct PhonebookEntry phonebook[100];
int entryCount = 0;

int main()
{
    int choice;
    printf("Enter any key to start: ");

    do{
    getchar(); system("cls");
    printf("1 Add Entry\n");
    printf("2 View Entry\n");
    printf("3 Edit Entry\n");
    printf("4 Delete Entry\n");
    printf("5 Search Entry\n");
    printf("6 Exit\n");
    printf("\n  Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
    case 1: AddEntry(); break;
    case 2: ViewEntry(); break;
    case 3: EditEntry(); break;
    case 4: DeleteEntry(); break;
    case 5: SearchEntry(); break;
    case 6: break;
    default:
        getchar();system("cls");
        printf("Invalid input!\nChoose Again\n\n"); break;
        }
    }while(choice != 6);

return 0;
}

void AddEntry(){
    int answer = 'N';
    do{
    getchar();system("cls");
    printf("Enter Name: ");
    scanf("%[^\n]", phonebook[entryCount].name);
    printf("Enter Contact Number: ");
    scanf("%s", phonebook[entryCount].contactNumber);
    entryCount++;
    printf("Entry Successfully Added!\n");
    printf("\n\nDo another process? Y or N\n");
    scanf(" %c", &answer);
    }while(answer == 'Y' || answer == 'y');
}

void ViewEntry(){
    getchar();system("cls");
    printf("Phonebook Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s: %s\n", i + 1, phonebook[i].name, phonebook[i].contactNumber);
    }
    printf("Enter any key to continue: ");
    getchar();system("cls");
}

void EditEntry(){

 int entryNumber;
    getchar();system("cls");
    printf("Phonebook Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s: %s\n", i + 1, phonebook[i].name, phonebook[i].contactNumber);
    }
    printf("Enter Entry Number To Be Edited: ");
    scanf("%d", &entryNumber);
    if (entryNumber >= 1 && entryNumber <= entryCount) {
        printf("Enter Name: ");
        scanf("%s", phonebook[entryNumber - 1].name);
        printf("Enter Contact Number: ");
        scanf("%s", phonebook[entryNumber - 1].contactNumber);
        printf("Entry Successfully Edited!\n");
    } else {
        printf("Invalid entry number.\n");
    }}

void DeleteEntry(){
int entryNumber;
    getchar();system("cls");
    printf("Phonebook Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s: %s\n", i + 1, phonebook[i].name, phonebook[i].contactNumber);
    }
    printf("Enter Entry Number To Be Deleted: ");
    scanf("%d", &entryNumber);
    if (entryNumber >= 1 && entryNumber <= entryCount) {
        // Shift entries to remove the deleted one
        for (int i = entryNumber - 1; i < entryCount - 1; i++) {
            strcpy(phonebook[i].name, phonebook[i + 1].name);
            strcpy(phonebook[i].contactNumber, phonebook[i + 1].contactNumber);
        }
        entryCount--;
        printf("Entry Successfully Deleted!\n");
    } else {
        printf("Invalid entry number.\n");
    }
}

void SearchEntry(){
char searchName[50];
    printf("Enter Name to Search: ");
    scanf("%s", &searchName);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Found entry:\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Contact Number: %s\n", phonebook[i].contactNumber);

        }
    }

    printf("Entry not found.\n");
    printf("\nEnter any key to continue: ");
            getchar(); system("cls"); return;
}
