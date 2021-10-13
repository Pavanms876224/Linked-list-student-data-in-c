#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define Max 100
struct student
{
    int rollnumber;
    char name[Max];
    char phone[Max];
    float percentage;
    struct student* next;
}* head;


void insert(int rollnumber, char *name, char *phone, float percentage)
{
    struct student *s = (struct student*)malloc(sizeof(struct student));
    s->rollnumber = rollnumber;
    strcpy(s->name, name);
    strcpy(s->phone,phone);
    s->percentage = percentage;
    s->next = NULL;

    if (head == NULL)
        head = s;
    else
    {
        s->next = head;
        head = s;
    }
}
void display()
{
    struct student *p = head;
    while (p!=NULL)
    {
        printf("Roll number = %d \n",p->rollnumber);
        printf("Name = %s \n",p->name);
        printf("Phone = %s \n",p->phone);
        printf("Percentage = %f \n",p->percentage);
        p = p->next;
    }
}
void search(int rollnumber)
{
    struct student *p = head;
    while (p!=NULL && p->rollnumber!=rollnumber)
    {
        if (p->rollnumber == rollnumber)
        {
            printf("Roll number = %d \n",p->rollnumber);
            printf("Name = %s \n",p->name);
            printf("Phone = %s \n",p->phone);
            printf("Percentage = %f \n",p->percentage);
        }
        p = p->next;
    }
    printf("Student with roll number %d not found\n",rollnumber);
}
void delete_element(int rollnumber)
{
    struct student* p = head;
    struct student* q = head;

    while (p!=NULL)
    {
        if (p->rollnumber == rollnumber)
        {
            printf("Record found \n");
            if (p == q)
            {
                head = head->next;
                free(p);
            }
            else
            {
                q->next = p->next;
                free(p);
            }
            printf("Record deleted successfully \n");
        }
        q=p;
        p = p->next;
    }
    printf("Record not found \n");
}
int main()
{
    head = NULL;
    int rollnumber;
    char name[Max];
    char phone[Max];
    float percentage;
    int choice;
    printf("Enter 1: Insert data \nEnter 2: To Display data \nEnter 3: To search \n");
    do
    {
        printf("Enter the choice \n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter roll number \n");
            scanf("%d",&rollnumber);

            getchar();
            printf("Enter name \n");
            gets(name);

            printf("Enter phone \n");
            scanf("%s",phone);

            printf("Enter percentage \n");
            scanf("%f",&percentage);

            insert(rollnumber, name, phone, percentage);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the roll number to search \n");
            scanf("%d",&rollnumber);
            search(rollnumber);
            break;

        case 4:
            printf("Enter the roll number to delete \n");
            scanf("%d",&rollnumber);
            delete_element(rollnumber);
            break;
        }
    }while (choice !=0);
}
