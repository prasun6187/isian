// Write a C program to store student information such as his/her name, parents,
// address including house number/name, street name, locality, District and PIN number,
// student’s age, sex, and marks in different subjects.
// Access the structure to compute the total marks of each student
// and report the details of the student(s) securing the highest total. Use nested structure (structure within a structure)

#include<stdio.h>
#include<string.h>

#define MAX_SUB 20
int n;
typedef struct std
{
	struct prsnl
	{
		char name[20];
		char father[20];
		char mother[20];
		char sex[10];
		int age;
	}
	personal;
	struct adrs
	{
		char house_no[20];
		char street_name[20];
		char locality[20];
		char district[20];
		int pin_no;
	}
	address;
	struct mrks
	{
		int sub[MAX_SUB];
		int total;
	}
	marks;
}
student;
int main (void)
{
	printf("How many students: ");
	int i = 0, s;
	scanf("%i", &n);
	student record[n];
	printf("Number of Subjects: ");
	scanf("%i", &s);
	do
	{
		printf("Enter the following details of Student %i\n", i + 1);
		printf("Name: ");
		scanf(" %[^\n]s", record[i].personal.name);
		printf("Father's Name: ");
		scanf(" %[^\n]s", record[i].personal.father);
		printf("Mother's Name: ");
		scanf(" %[^\n]s", record[i].personal.mother);
		printf("Sex: ");
		scanf(" %[^\n]s", record[i].personal.sex);
		printf("Age: ");
		scanf("%i", &record[i].personal.age);
		printf("House No/Name: ");
		scanf(" %[^\n]s", record[i].address.house_no);
		printf("Street Name: ");
		scanf(" %[^\n]s", record[i].address.street_name);
		printf("Locality: ");
		scanf(" %[^\n]s", record[i].address.locality);
		printf("District: ");
		scanf(" %[^\n]s", record[i].address.district);
		printf("PIN no: ");
		scanf("%i", &record[i].address.pin_no);
		record[i].marks.total = 0;
		for (int j = 0; j < s; j ++)
		{
			printf("Subject %i marks: ", j + 1);
			scanf("%i", &record[i].marks.sub[j]);
			record[i].marks.total += record[i].marks.sub [j];
		}
		printf("Thanks!\n");
		i ++;
	}
	while (i < n);
	int maximum = record[0].marks.total;
	for (i = 1; i < n; i ++)
	{
		if (record[i].marks.total > maximum)
		{
			maximum = record[i].marks.total;
		}
	}
	int counter = 1;
	for (int k = 0; k < n ; k ++)
	{
		if (record[k].marks.total == maximum)
		{
			printf("\nThe details of the topper no %i is as following: \n", counter);
			printf("Name: %s\n", record[k].personal.name);
			printf("Father's Name: %s\n", record[k].personal.father);
			printf("Mother's Name: %s\n", record[k].personal.mother);
			printf("Sex: %s\n", record[k].personal.sex);
			printf("Age: %i\n", record[k].personal.age);
			printf("House No/Name: %s\n", record[k].address.house_no);
			printf("Street Name: %s\n", record[k].address.street_name);
			printf("Locality: %s\n", record[k].address.locality);
			printf("District: %s\n", record[k].address.district);
			printf("PIN no: %i\n", record[k].address.pin_no);
			for (int j = 0; j < s; j ++)
			{
				printf("Subject %i marks: %i\n", j + 1, record[k].marks.sub[j] );
			}
			printf("Total Marks Obtained: %i\n", record[k].marks.total);
			counter ++;
		}
	}
	return 0;
}
