
#include<stdio.h>

#include <stdlib.h>              
                                 

void returnfunc(void);

void mainmenu(void);

void addstudent(void);

void deletestudent(void);

void editstudent(void);

void searchstudent(void);

void viewstudent(void);

void closeapplication(void);

void Password(void);
//void functions-breaking programs into smaller chunks.


FILE *fp,*ft,*fs;
//file-handling


int s;
char findstudent;
//globalvariables


struct student
{

int id;
char name[20];
char address[20];
char course[10];
int contact;

};
//defining primary structure of how data stores inside our txt file


struct student a;

int main()
{
Password();
getch();
return 0;
}
//login authentication


void mainmenu()
//mainemenu for the program
{

system("cls");

int i;
printf("\t\t\tStudent Management System \n");
printf("<1> Enter or Add Record \n");
printf("<2> Delete Records\n");
printf("<3> Search Records\n");
printf("<4> View Record's list\n");
printf("<5> Modify Record\n");
printf("<6> Close Application\n\n");
printf("Enter your choice:\n");

switch(getch())
//linking parts together into a single menu
{
	
case '1':
addstudent();
break;

case '2':
deletestudent();
break;

case '3':
searchstudent();
break;

case '4':
viewstudent();
break;

case '5':
editstudent();
break;

case '6':
{
exit(0);
}
default:
{

printf("\aInvalid Entry!!Please enter correct option");

if(getch()) 
mainmenu();
//use of recursion
}

}

} 



void addstudent(void)    

{
	FILE *fptr;
	fptr=fopen("stf.txt","a");//append mode
	printf("\nEnter ID of student:");
	scanf("%d",&a.id);
	printf("Enter name of student:");
	scanf("%s",a.name);
	printf("\nEnter address of student:");
	scanf("%s",a.address);
	printf("\nEnter contact info of student:");
	scanf("%d",&a.contact);
	printf("\nEnter course of student:");
	scanf("%s",a.course);
	fprintf(fptr,"%d %s %s %d %s\n",a.id,a.name,a.address,a.contact,a.course);
	fclose(fptr);

printf("The record is sucessfully saved\n");
printf("Save any more?(Y / N):");
if(getch()=='n')
mainmenu();
else
system("cls");
addstudent();//recursion

}



void deletestudent()    

{
		FILE *fptr;
	fptr=fopen("stf.txt","r");
	struct student s[100];
	int count=0,i=0,choice;
	while(!feof(fptr))//until end of file
	{
		fscanf(fptr,"%d %s %s %d %s\n",&s[i].id,s[i].name,s[i].address,&s[i].contact,s[i].course);
		
		printf("%d %s %s %d %s\n",s[i].id,s[i].name,s[i].address,s[i].contact,s[i].course);
		count++;//to count total no. of 'students' present in the data file.
		i++;
		
	}
	fclose(fptr);
	printf("Enter the ID of student you want to delete\n");
	scanf("%d",&choice);
	fptr=fopen("stf.txt","w");
	for(i=0;i<count;i++)
	{
		if(s[i].id==choice)
		{
			continue;//w mode deletes(overwrites) data with matched id
		}
		else
		{
		
		fprintf(fptr,"%d %s %s %d %s\n",s[i].id,s[i].name,s[i].address,s[i].contact,s[i].course);
		}
	}
		fclose(fptr);
printf("Record Successfully Deleted\n");
printf("\n\tDelete another record?(Y/N)");
if(getch()=='n')
mainmenu();
else
system("cls");
deletestudent();//recursion
}




void searchstudent()

{

system("cls");

FILE *fptr;
fptr=fopen("stf.txt","r");  
struct student s[100];
int count=0,i=0,choice,loop;
char t;

system("cls");

printf("Enter the ID:");
scanf("%d",&choice);
while(!feof(fptr))
{
fscanf(fptr,"%d %s %s %d %s",&s[i].id,s[i].name,s[i].address,&s[i].contact,s[i].course);
				if(s[i].id==choice)
				{
					printf("The record is available");
			printf("\n ID \t\t NAME \t\tADDRESS \t\t CONTACT \t\t COURSE\n");
			printf("%d\t\t %s \t\t%s\t\t\t %d\t\t %s\n",s[i].id,s[i].name,s[i].address,s[i].contact,s[i].course);
			loop='t';
		i++;
}		
	}
fclose(fptr);	
	
		
if (loop!='t')
{
printf("Record Not Found\n");	
}	
printf("Try another search?(Y/N)");
if(getch()=='y')
searchstudent();
else
mainmenu();


}







void viewstudent(void)  

{

system("cls");

printf("\n ID \t\t NAME \t\tADDRESS \t\t CONTACT \t COURSE\n");


	FILE *fptr;
	fptr=fopen("stf.txt","r");
	struct student s[100],update;
	int count=0,i=0,choice;
	while(!feof(fptr))
	{
		fscanf(fptr,"%d %s %s %d %s\n",&s[i].id,s[i].name,s[i].address,&s[i].contact,s[i].course);
		
		printf("%d\t\t %s \t\t%s\t\t %d\t\t %s\n",s[i].id,s[i].name,s[i].address,s[i].contact,s[i].course);
		count++;
		i++;
		
	}

returnfunc();

}



void editstudent(void)  

{

system("cls");
printf("\nEdit Records\n");


{
	FILE *fptr;
	fptr=fopen("stf.txt","r");
	struct student s[100],update;
	int count=0,i=0,choice;
	while(!feof(fptr))
	{
		fscanf(fptr,"%d %s %s %d %s\n",&s[i].id,s[i].name,s[i].address,&s[i].contact,s[i].course);
		
		printf("%d %s %s %d %s\n",s[i].id,s[i].name,s[i].address,s[i].contact,s[i].course);
		count++;
		i++;
		
	}
	fclose(fptr);
	printf("Enter the ID of student you want to update\n");
	scanf("%d",&choice);
	printf("Enter the details of student again");
	printf("\nEnter ID of student:");
	scanf("%d",&update.id);
	printf("Enter name of student:");
	scanf("%s",update.name);
	printf("\nEnter address of student:");
	scanf("%s",update.address);
	printf("\nEnter contact info of student:");
	scanf("%d",&update.contact);
	printf("\nEnter course of student:");
	scanf("%s",update.course);
	fptr=fopen("stf.txt","r+");
	for(i=0;i<count;i++)
	{
		if(s[i].id==choice)
		{
			fprintf(fptr,"%d %s %s %d %s\n",update.id,update.name,update.address,update.contact,update.course);
			printf("Successfully Updated\n");//strucure 'update' to temporarily hold data 
		}
		else
		{
			fprintf(fptr,"%d %s %s %d %s\n",s[i].id,s[i].name,s[i].address,s[i].contact,s[i].course);
		}
	}
		fclose(fptr);


	
printf("Edit any more?(Y / N):");

if(getch()=='n')

mainmenu();

else

system("cls");

editstudent();

}
	



returnfunc();

}


void returnfunc(void)

{

{

printf("Press ENTER to return to main menu");

}

a:

if(getch()==13) 

mainmenu();

else

goto a;

}



void Password(void)

{

char password[10]={"pass"};
system("cls");

char ch,pass[10];
int i=0,j;

	printf("\t\t\t\tWelcome\n\t\t\t\t  To \n\t\t\t  College Management System \n");
	printf("\t \n\n\n Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){

putch('*');

pass[i] = ch;

i++;

}

}

pass[i] = '\0';

if(strcmp(pass,password)==0)

{
printf("\n\n\n\t\tPassword matched!!");
printf("\n\n\tPress any key to continue.....");
getch();
mainmenu(); 
}

else

{ 
printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");
getch();
Password(); 
}

}




















