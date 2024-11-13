#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
    char name[15];
    int code;
    int quantity;
    double rate;

} product;
product item;
FILE *f;
int i,j,k;

void add();
void readfile();

int main() {
	//f=fopen("file.txt","r")
        do {
    	printf("\n===============================INVENTORY===============================\n");
        printf("\n\n\n\n\t\t\t 1) Add an item\n");
        printf("\t\t\t 2) See Inventory\n");
        printf("\t\t\t 0) Exit\n\t\t\t ");
        scanf("%d",&j);
        switch(j) {
            case 1:
                add();
                break;
            case 2:
            	readfile();
            	break;
            default:
                if(j != 0) {
                    printf("Enter correct number\n");
                    printf("\nPress any key to try again.");
                    getch();  
                }
                break;
        }
        system("cls");  
    } while(j != 0);  
    
    printf("\n\n--------------------------------THANKS!!------------------------------------\n\n");
    return 0;
}
void add(){
	system("cls");
	printf("**ITEM ADDITION** \n");
	f=fopen("file.txt","a+");
	printf(" Enter name : ");
	getchar();
	fgets(item.name,sizeof (item.name),stdin);
	item.name[strcspn(item.name, "\n")] = '\0';
	printf("enter code : ");
	scanf("%d",&item.code);
	printf("enter quantity : ");
	scanf("%d",&item.quantity);
	printf("enter rate : ");
	scanf("%lf",&item.rate);
	fprintf(f, "%-10d | %-20s | %-8.2f | %-8d\n", item.code, item.name, item.rate, item.quantity);
	printf("item added \nPress any key to continue . ");
	getch();
	fclose(f);
	
	
}
void readfile(){
	char temp[500];
	f=fopen("file.txt","r");
	if (f == NULL){
		printf("\t\t\t error opening file");
	}
	printf("CODE       | NAME                | RATE     | QUANTITY\n");
    printf("----------------------------------------------------------\n");
	while (fgets(temp,sizeof (temp),f)){
		printf("%s\n",temp);
	}
	printf("Press any key to continue . ");
	getch();
	fclose(f);
}
