#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
    char name[15];
    int code;
    double rate;

} product;
product item;
FILE *f;
int i,j,k;

void add();

int main() {
	//f=fopen("file.txt","r")
    printf("\n===============================INVENTORY===============================\n");
    do {
        printf("\n\n\n\n\t\t\t[1]Add an item\n");
        printf("\n\t\t\t[0]Exit\n\t\t\t ");
        scanf("%d",&j);
        switch(j) {
            case 1:
                add();
                break;
            default:
                if(j != 0) {
                    printf("Enter correct number\n");
                    printf("\nPress any key to try again.");
                    getch();  // Wait for key press
                }
                break;
        }
        system("cls");  // Clear screen for next menu
    } while(j != 0);  // Exit loop if user selects '0'
    
    printf("\n\n--------------------------------GOOD BYE!!------------------------------------\n\n");
    return 0;
}
void add(){
	system("cls");
	f=fopen("file.txt","a+");
	printf("enter name : ");
	getchar();
	fgets(item.name,sizeof (item.name),stdin);
	item.name[strcspn(item.name, "\n")] = '\0';
	printf("enter code : ");
	scanf("%d",&item.code);
	printf("enter rate : ");
	scanf("%lf",&item.rate);
	fprintf(f,"%s %d %2f",item.name,item.code,item.rate);
	printf("item added \nPress any key to continue . ");
	getch();
	fclose(f);
	
	
}
