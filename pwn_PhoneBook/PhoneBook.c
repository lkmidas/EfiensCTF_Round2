#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 10

typedef struct Contact
{
	char name[8];
	int  used;
	char number[12];
} Contact;

void getFlag(void)
{
	system("/bin/cat flag.txt");
	exit(0);
}

void menu(void)
{
	puts("====================================");
	puts("1. Add a new contact");
	puts("2. Delete a contact");
	puts("3. View a contact");
	puts("4. Quit");
	puts("====================================");
	printf("Your choice: ");
}

void readString(char *buffer, int size)
{
	int out = read(0,buffer,size);
	if (out <= 0)
	{
		puts("read error");
		exit(1);
	}
	if (buffer[out-1]=='\n')
		buffer[out-1] = '\0';
}

int readChoice(char* buffer, int size)
{
	readString(buffer,size);
	return atoi(buffer);
}

void addContact(Contact *phoneBook)
{
	int index = 0;
	while(1)
	{
		if(index > SIZE)
		{
			puts("Full");
		}
		if(phoneBook[index].used == 0)
			break;
		index++;
	}
	printf("Enter the name: ");
	readString(phoneBook[index].name,8);
	printf("Enter the phone number: ");
	readString(phoneBook[index].number,12);
	phoneBook[index].used = 1;
	puts("Done");
}

void viewContact(Contact *phoneBook)
{
	printf("Index: ");
	char buffer[16];
	int index = readChoice(buffer,16);
	if ((index < 0) || (index >= SIZE) || (phoneBook[index].used != 1))
	{
		puts("Invalid index");
	}
	else
	{
		printf("Name: %s\n",phoneBook[index].name);
                printf("Number: %s\n",phoneBook[index].number);
	}
}

void deleteContact(Contact *phoneBook)
{
	printf("Index: ");
	char buffer[16];
	int index = readChoice(buffer,16);
	if ((index < 0) || (index >= SIZE) || (phoneBook[index].used != 1))
	{
		puts("Invalid index");
	}
	else
	{
		memset(&phoneBook[index],'\0',sizeof(Contact));
                puts("Done");
	}
}

void handler(void)
{
	puts("Welcome to my phone book application");
	char choice[16];
	Contact phoneBook[SIZE];
	memset(&phoneBook,'\0',SIZE*sizeof(Contact));
	while(1)
	{
		menu();
		switch(readChoice(choice,16))
		{
			case 1:
				addContact(&phoneBook);
				break;
			case 2:
				deleteContact(&phoneBook);
				break;
			case 3:
				viewContact(&phoneBook);
				break;
			case 4:
				return;
			default:
				puts("Invalid choice");
		}
	}
}

int main(void)
{
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	char input[16];
	do
	{
		handler();
		puts("Do you really want to quit (y/n)");
		readString(input,16);
	}
	while(!strcmp(input,"y"));
	return 0;
}
