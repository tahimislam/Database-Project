
//Name: Md. Mainul Islam
//Project on Department Management System using C Language...

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

FILE *fp;                                                 //Declaring file data type and a pointer as Global variable for pointing file.

struct teacher                                            //Creating a structure for store teacher's information
{
    char name[100],t_user[100],t_pass[100];
    char adrs[100];
    char course[100];
    long long int phone;
} t;                                                      //Declaring a struct teacher type Global variable t.
long long int szt = sizeof(t);                            //Size of each teacher's information.

struct student                                            //Creating a structure for store student's information
{
    char name[100],s_user[100],s_pass[100];
    char adrs[100];
    int roll;
    long long int phone;
    char course[500];
} s;                                                      //Declaring a struct student type Global variable s.
long long int szs = sizeof(s);                            //Size of each student's information.



/* In above all the declared variables are Global,
so that all the functions in this program can access all these variables.*/



int my_marks(int r)
{
    system("cls");                                        //Clearing the Whole Console.

    int f=0;                                              //For checking the existence of the information.

    fp = fopen("Student.txt", "rb");                      //Opening file in read on binary mode.
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&s, szs, 1, fp)==1)                   //Reading from file.
        {
            if(r==s.roll)
            {
                f=1;
                printf("\n\nMarks: %s\n",s.course);
                break;
            }
        }
        fclose(fp);                                       //Closing the file.
        if(f==0)
            printf("\nSorry. Marks Not Found.\n\n");
        else
            printf("\n\nMarks Showed Successfully!\n");
    }
}

int student_panel(int r)
{
    while(1)
    {
        system("cls");                          //Clearing the Whole Console.

        printf("\n\t\t\t\t\t*****/ Welcome to Student's Panel \\*****\n\n\n");
        printf("1. Display My CT Marks\n\n");
        printf("0. Exit\n\n");
        int ch;
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            return 0;
            break;

        case 1:
            my_marks(r);                        //Function for showing student's CT marks and Passing student's roll through it for showing the Marks.
            break;
        }
        printf("\nPress Any Key To Continue...");
        getch();
    }
}

void cnt()
{
    int count=0;
    fp = fopen("Student.txt", "rb");
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&s, szs, 1, fp)==1)
            count++;                             //Counting the number of Students in the file.
        fclose(fp);
        printf("\n\nTotal Number of Students: %d\n\n",count);
    }
}

void stud_display()
{
    system("cls");                               //Clearing the Whole Console.

    printf("\n\t\t\t*****<<== All Students's Information ==>>*****\n\n");
    printf("%-20s %-10s %-10s %-15s %-30s\n\n","Name","Roll","Address","Phone","Courses");         //Creating columns.
    fp = fopen("Student.txt", "rb");
    if(fp==NULL)
        printf("\nSorry. File Not Found.\n\n");
    else
    {
        while(fread(&s, szs, 1, fp)==1)
            printf("%-20s %-10d %-10s %-15lld %-30s\n",s.name,s.roll,s.adrs,s.phone,s.course);

    }
    fclose(fp);
}

void marks()
{
    int rl;
    int f=0;                                     //For checking the existence of the information.

    printf("\nEnter Roll To Provide Marks: ");
    scanf("%d",&rl);
    fp = fopen("Student.txt", "rb+");            //Opening file in both read and write on binary mode.
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&s, szs, 1, fp)==1)
        {
            if(rl==s.roll)
            {
                f=1;
                printf("\nEnter Marks of the Course: ");
                fflush(stdin);
                gets(s.course);
                fseek(fp,-szs,1);               //Moving the file pointer to the required position so that the exact information will be changed.
                fwrite(&s, szs, 1, fp);
                fclose(fp);
                break;
            }
        }
        if(f==0)
            printf("\nRoll Not Found.\n\n");
        else
            printf("\nMarks Provided Successfully!\n\n");
    }
}

void search_stud()
{
    char nam[100];
    int f=0;                                   //For checking the existence of the information.

    printf("\nEnter Name To Search: ");
    fflush(stdin);                             //Clearing the buffer.
    gets(nam);

    system("cls");                             //Clearing the Whole Console.

    printf("%-20s %-10s %-10s %-15s %-30s\n\n","Name","Roll","Address","Phone","Courses");      //Creating Columns.
    fp = fopen("Student.txt", "rb");
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&s, szs, 1, fp)==1)
        {
            if(strcmp(nam,s.name)==0)
            {
                f=1;
                printf("%-20s %-10d %-10s %-15lld %-30s\n",s.name,s.roll,s.adrs,s.phone,s.course);
                break;
            }
        }
        fclose(fp);
        if(f==0)
            printf("\nName Not Found.\n\n");
        else
            printf("\n\nName Found Successfully!\n");
    }
}

void teacher_panel()
{
    while(1)
    {
        system("cls");                         //Clearing the Whole Console.

        printf("\n\t\t\t\t\t*****/ Welcome to Teacher's Panel \\*****\n\n\n");
        printf("1. Display All Student's Information\n\n");
        printf("2. Provide Class Test Marks To Students\n\n");
        printf("3. Search Student\n\n");
        printf("4. Count The Number of Total Students\n\n");
        printf("0. Exit\n\n");
        int ch;
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            return;
            break;

        case 1:
            stud_display();                    //Function for displaying all the student's information.
            break;

        case 2:
            marks();                           //Function for providing CT marks to the student.
            break;

        case 3:
            search_stud();                     //Function for searching student by their name.
            break;

        case 4:
            cnt();                             //Function for counting total number of students.
            break;
        }
        printf("\nPress Any Key To Continue...");
        getch();
    }
}

void assign_course()
{
    char nam[100];
    int f=0;                                   //For checking the existence of the information.

    printf("\nEnter Name of The Teacher To Assign Courses: ");
    fflush(stdin);
    gets(nam);
    fp = fopen("Teacher.txt", "rb+");          //Opening file in both read and write on binary mode.
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&t, szt, 1, fp)==1)
        {
            if(strcmp(nam,t.name)==0)
            {
                f=1;
                printf("\nEnter New Course: ");
                fflush(stdin);
                gets(t.course);
                fseek(fp,-szt,1);              //Moving the file pointer to the required position so that the exact information will be changed.
                fwrite(&t, szt, 1, fp);
                fclose(fp);
                break;
            }
        }
        if(f==0)
            printf("\nName Not Found.\n\n");
        else
            printf("\nCourses Assigned Successfully!\n\n");
    }
}

void s_update()
{
    char nam[100];
    int f=0;                                   //For checking the existence of the information.

    printf("\nEnter Name To Update: ");
    fflush(stdin);
    gets(nam);

    system("cls");                             //Clearing the Whole Console.

    fp = fopen("Student.txt", "rb+");          //Opening file in both read and write on binary mode.
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&s, szs, 1, fp)==1)
        {
            if(strcmp(nam,s.name)==0)
            {
                f=1;
                printf("\nEnter New Name: ");
                fflush(stdin);
                gets(s.name);
                printf("\nEnter New Roll: ");
                scanf("%d",&s.roll);
                printf("\nEnter New Address: ");
                fflush(stdin);
                gets(s.adrs);
                printf("\nEnter New Contact Number: ");
                scanf("%lld",&s.phone);
                printf("\nEnter New Course: ");
                fflush(stdin);
                gets(s.course);
                fseek(fp,-szs,1);               //Moving the file pointer to the required position so that the exact information will be changed.
                fwrite(&s, szs, 1, fp);
                fclose(fp);
                break;
            }
        }
        if(f==0)
            printf("\nName Not Found.\n\n");
        else
            printf("\nInformation Updated Successfully!\n\n");
    }
}

void s_display()
{
    system("cls");                              //Clearing the Whole Console.

    printf("\n\t\t\t\t*****<<== All Students's Information ==>>*****\n\n");
    printf("%-20s %-10s %-10s %-15s %-30s %-10s %-10s\n\n","Name","Roll","Address","Phone","Courses","User ID","Password");   //Creating columns.
    fp = fopen("Student.txt", "rb");
    if(fp==NULL)
        printf("\nSorry. File Not Found.\n\n");
    else
    {
        while(fread(&s, szs, 1, fp)==1)
            printf("%-20s %-10d %-10s %-15lld %-30s %-10s %-10s\n",s.name,s.roll,s.adrs,s.phone,s.course,s.s_user,s.s_pass);

    }
    fclose(fp);

}

void s_reg()
{
    system("cls");                              //Clearing the Whole Console.

    fp = fopen("Student.txt", "ab");            /*Opening file in append on binary mode so that if the file does not exist it
                                                   will be created and we can write in it.*/
    printf("\nEnter Student's Name: ");
    fflush(stdin);
    gets(s.name);
    printf("\nEnter Roll: ");
    scanf("%d",&s.roll);
    printf("\nEnter Address: ");
    fflush(stdin);
    gets(s.adrs);
    printf("\nEnter Contact Number: ");
    scanf("%lld",&s.phone);
    printf("\nEnter Courses: ");
    fflush(stdin);
    gets(s.course);
    printf("\nSet User ID: ");
    scanf("%s",&s.s_user);
    printf("\nSet Password: ");
    scanf("%s",&s.s_pass);

    fwrite(&s, szs, 1, fp);
    printf("\nRegistration Successful!\n");
    fclose(fp);
}

void t_update()
{
    char nam[100];
    int f=0;                                   //For checking the existence of the information.

    printf("\nEnter Name To Update: ");
    fflush(stdin);
    gets(nam);

    system("cls");                             //Clearing the Whole Console.

    fp = fopen("Teacher.txt", "rb+");          //Opening file in both read and write on binary mode.
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&t, szt, 1, fp)==1)
        {
            if(strcmp(nam,t.name)==0)
            {
                f=1;
                printf("\nEnter New Name: ");
                fflush(stdin);
                gets(t.name);
                printf("\nEnter New Address: ");
                fflush(stdin);
                gets(t.adrs);
                printf("\nEnter New Contact Number: ");
                scanf("%lld",&t.phone);
                printf("\nEnter New Course: ");
                fflush(stdin);
                gets(t.course);
                fseek(fp,-szt,1);              //Moving the file pointer to the required position so that the exact information will be changed.
                fwrite(&t, szt, 1, fp);
                fclose(fp);
                break;
            }
        }
        if(f==0)
            printf("\nName Not Found.\n\n");
        else
            printf("\nInformation Updated Successfully!\n\n");
    }
}

void t_display()
{
    system("cls");                             //Clearing the Whole Console.

    printf("\n\t\t\t*****<<== All Teacher's Information ==>>*****\n\n");
    printf("%-20s %-20s %-15s %-20s %-10s %-10s\n\n","Name","Address","Phone","Courses","User ID","Password");      //Creating Columns.
    fp = fopen("Teacher.txt", "rb");
    if(fp==NULL)
        printf("\nSorry. File Not Found.\n\n");
    else
    {
        while(fread(&t, szt, 1, fp)==1)
            printf("%-20s %-20s %-15lld %-20s %-10s %-10s\n",t.name,t.adrs,t.phone,t.course,t.t_user,t.t_pass);

    }
    fclose(fp);

}

void t_reg()
{
    system("cls");                            //Clearing the Whole Console.

    fp = fopen("Teacher.txt", "ab");          /*Opening file in append on binary mode so that if the file does not exist it
                                               will be created and we can write in it.*/
    printf("\nEnter Teacher's Name: ");
    fflush(stdin);                            //Clearing the buffer.
    gets(t.name);
    printf("\nEnter Address: ");
    fflush(stdin);
    gets(t.adrs);
    printf("\nEnter Contact Number: ");
    scanf("%lld",&t.phone);
    printf("\nEnter Course: ");
    fflush(stdin);
    gets(t.course);
    printf("\nSet User ID: ");
    scanf("%s",&t.t_user);
    printf("\nSet Password: ");
    scanf("%s",&t.t_pass);

    fwrite(&t, szt, 1, fp);                    //Writing the given inputs from the console to the file.

    printf("\nRegistration Successful!\n");
    fclose(fp);                                //Closing the file.
}

void admin_panel()
{
    while(1)
    {
        system("cls");                 //Clearing the Whole Console.

        printf("\n\t\t\t\t\t*****/ Welcome to Admin Panel \\*****\n\n\n");
        printf("1. Teacher Registration\n\n");
        printf("2. Update Teacher's Information\n\n");
        printf("3. Display All Teacher's Information\n\n");
        printf("4. Student Registration\n\n");
        printf("5. Update Student's Information\n\n");
        printf("6. Display All Student's Information\n\n");
        printf("7. Assign Courses To Teacher\n\n");
        printf("0. Exit\n\n");
        int ch;
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            return;
            break;

        case 1:
            t_reg();                   //Function for registering teacher's information.
            break;

        case 2:
            t_update();                //Function for updating teacher's information.
            break;

        case 3:
            t_display();               //Function for displaying all the teacher's information.
            break;

        case 4:
            s_reg();                   //Function for registering student's information.
            break;

        case 5:
            s_update();                //Function for updating student's information.
            break;

        case 6:
            s_display();               //Function for displaying all the student's information.
            break;

        case 7:
            assign_course();           //Function for assigning courses to the teachers.
            break;
        }
        printf("\nPress Any Key To Continue...");
        getch();
    }
}

void admin()
{
    char username[100],password[100];

    printf("\nEnter User ID: ");
    scanf("%s",&username);
    printf("\nEnter Password: ");
    scanf("%s",&password);
    if(strcmp(username,"Tahim")==0 && strcmp(password,"1234")==0)
    {
        printf("\nCongratulations! Log in Successful.\n\n");
        printf("\nPress Any Key To Continue...");
        getch();
        admin_panel();                     //Function for doing Admin's activity.
    }
    else
    {
        printf("\nSorry. Invalid User ID or Password.\n\n");
        printf("\nPress Any Key To Continue...");
        getch();
    }
}

void teacher()
{
    char username[100],password[100];
    int f=0;                               //For checking the existence of the information.

    printf("\nEnter User ID: ");
    scanf("%s",&username);
    printf("\nEnter Password: ");
    scanf("%s",&password);
    fp = fopen("Teacher.txt", "rb");
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&t, szt, 1, fp)==1)
        {
            if(strcmp(username,t.t_user)==0 && strcmp(password,t.t_pass)==0)
            {
                f=1;
                printf("\nCongratulations! Log in Successful.\n\n");
                printf("\nPress Any Key To Continue...");
                getch();
                fclose(fp);
                break;

            }
        }
        if(f==0)
        {
            printf("\nSorry. Invalid User ID or Password.\n\n");
            printf("\nPress Any Key To Continue...");
            getch();
        }
        else
            teacher_panel();          //Function for doing teacher's activity.
    }
}

void student()
{
    char username[100],password[100];
    int f=0;                          //For checking the existence of the information.
    int r;                            //For storing the roll of the student for further use.
    printf("\nEnter User ID: ");
    scanf("%s",&username);
    printf("\nEnter Password: ");
    scanf("%s",&password);
    fp = fopen("Student.txt", "rb");
    if(fp==NULL)
        printf("\nSorry. File not found.\n\n");
    else
    {
        while(fread(&s, szs, 1, fp)==1)
        {
            if(strcmp(username,s.s_user)==0 && strcmp(password,s.s_pass)==0)
            {
                f=1;
                printf("\nCongratulations! Log in Successful.\n\n");
                printf("\nPress Any Key To Continue...");
                getch();
                r=s.roll;
                fclose(fp);
                break;

            }
        }
        if(f==0)
        {
            printf("\nSorry. Invalid User ID or Password.\n\n");
            printf("\nPress Any Key To Continue...");
            getch();
        }
        else
            student_panel(r);          //Function for doing student's activity and Passing student's roll through it for showing CT Marks.
    }
}

int main()
{
    int ch;
    while(1)
    {
        system("cls");                 //Clearing the Whole Console.

        printf("\n\n\t\t*******/ WELCOME TO DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING, KUET \\*******\n\n\n");
        printf("1. Admin Panel\n\n");
        printf("2. Teacher's Panel\n\n");
        printf("3. Student's Panel\n\n");
        printf("0. Exit\n\n\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 0:
            return 0;
            break;

        case 1:
            admin();             //Function for admin login.
            break;

        case 2:
            teacher();           //Function for teacher login.
            break;

        case 3:
            student();           //Function for student login.
            break;
        }
    }

    return 0;
}
