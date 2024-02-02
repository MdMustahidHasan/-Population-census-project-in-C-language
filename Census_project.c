#include <stdio.h>
#include <string.h>
#include<stdlib.h>


struct person {

    int nid [17];
    char name[30];
    int age[8];
    char gender [10];
    char occupation[20];
  char district[15];

     char division[15];

    }s;
FILE *fp;
long sz = sizeof(s);


int main()
{
	login();
    menu();
  return 0;
}


void login()
{
    char username[15];
    char password[12];
    int a=0;
printf("\n \n\t\t\t\t\t\tPOPULATION CENSUS PROJECT \t \t " );
  printf("\n\n\t\t\t\t\t\t<<<<< LOGIN FORM  >>>>\n\n  ");
    printf("\t Username:  ");
    scanf("%s",&username);

    printf("\t Password:  ");
    scanf("%s",&password);

    if(strcmp(username,"admin")==0){
        if(strcmp(password,"1234")==0){

        printf("\n    Welcome....Login Successful   !!!\n");
         printf("\n    Press any key to continue......");

}else{
    printf("\n wrong password");
    getch();
    system("cls");
    login();

}
    }else{
    printf("\nUser doesn't exist");
     getch();
     system("cls");
    login();

}


getch ();

}

void menu()
{
system("CLS");
    int choice;
    printf("\n \n \t \t POPULATION CENSUS PROJECT \t \t " );
    printf("\n\n\n\t\t\  Welcome To The Main Menu  \t \t ");
    printf("\n\n\t\
           1-->Enter a new person information \n\t\
           2-->Modify information of existing account\n\t\
           3-->View all person list\n\t\
           4-->View all person of a particular Division\n\t\
           5--> Removing existing account\n\t\
           6-->Logout  ");
    printf ("\n\n \t\t Enter your choice:  ");
    scanf("%d",&choice);


      switch(choice)
    {

  case 1:entry();
        break;
      case 2:modify();
        break;
     case 3:view();
       break;
     case 4:particular_division();
        break;
     case 5:removing();
        break;
    case 6:logout();
        break;

        default:menu();
    }

}

void entry ()
{
    system("CLS");
fp = fopen("project.txt","ab");

printf("Enter NID  / Birth certificate number: ");
fflush(stdin);
gets(s.nid);
printf("Enter Name : ");
fflush(stdin);
gets(s.name);
printf("Enter Age : ");
fflush(stdin);
gets(s.age);
printf("Enter Gender (Male/Female/Other) : ");
fflush(stdin);
gets(s.gender);

printf("Enter Occupation: ");
fflush(stdin);
gets(s.occupation);

printf("Enter District: ");
fflush(stdin);
gets(s.district);

 printf("Enter your DIVISION name from  Barishal, Chattogram, Dhaka, Khulna, Mymensingh, Rajshahi, Rangpur, Sylhet :");
fflush(stdin);
gets(s.division);

fwrite(&s, sz, 1, fp);
printf("Record save successfully");
fclose(fp);


int press;
  printf("\n\n\n\t\t  PRESS 1 to a new Entry   PRESS 2 to go to the Main menu  and PRESS  3 to Logout......  ");
    scanf("%d",&press);

    if (press==1)
          entry();
    else if (press == 2)
        menu ();
    else if (press==3)
            system("CLS");
            printf("\n Press any key to Logout........" );


}




  void modify()
  {
          system("CLS");

      int nidd[20];
      int f=0;

      printf("\n Enter NID/Birth registration number to modify : ");
fflush(stdin);
gets(nidd);


     fp = fopen ("project.txt","rb+");
     while (fread(&s,sz,1,fp)==1)
    {
         if (strcmpi(nidd,s.nid)==0)
         {
             f=1;
printf ("\n Record Found--->\n\n");
printf("Enter Updated NID  / Birth certificate number  : ");
fflush(stdin);
gets(s.nid);
printf("Enter Updated Name : ");
fflush(stdin);
gets(s.name);
printf("Enter Updated Age : ");
fflush(stdin);
gets(s.age);
printf("Enter Updated Gender (Male/Female/Other) : ");
fflush(stdin);
gets(s.gender);

printf("Enter Updated Occupation: ");
fflush(stdin);
gets(s.occupation);

printf("Enter Updated District : ");
fflush(stdin);
gets(s.district);

 printf("Enter Updated DIVISION name from  Barishal, Chattogram, Dhaka, Khulna, Mymensingh, Rajshahi, Rangpur, Sylhet :");
fflush(stdin);
gets(s.division);


fseek(fp,-sz,1);
fwrite(&s,sz,1,fp);
fclose(fp);

break;
         }
    }

if (f==0)
      {
          printf("\n\nRecord not found\n");
      } else
      {
            printf("\n Record modified successfully" );
      }

int press;
  printf("\n\n\n\t\t  PRESS 1 to try again   PRESS 2 to go to the Main menu  and PRESS  3 to Logout...  ");
    scanf("%d",&press);

    if (press==1)
          modify();
    else if (press == 2)
        menu ();
    else if (press==3)
            system("CLS");
            printf("\n Press any key to Logout......" );


  }

 void view ()
 {
     system("CLS");
     printf ("\n ==> Person info ----->>\n\n");
    int a=0;

     printf ("%-15s %-30s%-10s%-10s%-15s%-15s%-15s%s \n","NID","Name","Age","Gender","Occupation","District","Division");
     fflush(stdin);
      fp = fopen ("project.txt","rb");
     while (fread(&s,sz,1,fp)==1)
    {
         fflush(stdin);
      printf ("%-15s %-30s%-10s%-10s%-15s%-15s%-15s%s\n ",s.nid,s.name,s.age,s.gender,s.occupation,s.district ,s.division);
      fflush(stdin);
      a++;
 }
 printf("\n\n\tTOTAL NUMBER OF PEOPLE  :  %d",a);
  fclose(fp);

  int press;
  printf("\n\n\n\t\t  PRESS 1 to try again   PRESS 2 to go to the Main menu  and PRESS  3 to Logout....  ");
    scanf("%d",&press);

    if (press==1)
          view();
    else if (press == 2)
        menu ();
    else if (press==3)
            system("CLS");
            printf("\n Press any key to Logout......." );
 }


 void particular_division()
 {
         system("CLS");

      int div[20];
      int f=0;
      int a=0;
         printf("  \n(Barishal, Chattogram, Dhaka, Khulna, Mymensingh, Rajshahi, Rangpur, Sylhet ) \n");
      printf("\n Enter the particular Division name  : ");
fflush(stdin);
gets(div);

    printf ("%-15s %-30s%-10s%-10s%-15s%-15s%-15s%s \n","NID","Name","Age","Gender","Occupation","District","Division");
     fp = fopen ("project.txt","rb");
     while (fread(&s,sz,1,fp)==1)
    {
        if (strcmpi(div,s.division)==0)
         {
             f=1;

        printf ("%-15s %-30s%-10s%-10s%-15s%-15s%-15s%s\n ",s.nid,s.name,s.age,s.gender,s.occupation,s.district ,s.division);
        a++;
         break;
         }
    }
    printf("\n\n\tTOTAL NUMBER OF PEOPLE  :  %d",a);
fclose (fp);

if (f==0)
      {
          printf("\n\nDivision not found\n");
      }

int press;
  printf("\n\n\n\t\t  PRESS 1 to try again   PRESS 2 to go to the Main menu  and PRESS  3 to Logout.....  ");
    scanf("%d",&press);

    if (press==1)
          particular_division();
    else if (press == 2)
        menu ();
    else if (press==3)
            system("CLS");
            printf("\n Press any key to Logout.......\n" );

 }

 void removing()
 {
        system("CLS");

      int nid_no[20];
      int f=0;

      printf("\n Enter NID/Birth registration number that you want to DELETE : ");
fflush(stdin);
gets(nid_no);

FILE *ft;

     fp = fopen ("project.txt","rb");
     ft = fopen("temp.txt","ab");
     while (fread(&s,sz,1,fp)==1)
    {
         if (strcmpi(nid_no,s.nid)==0)
         {
             f=1;
         }
         else {
            fwrite (&s,sz,1,ft) ;
         }
 }
 fclose(fp);
 fclose(ft);
 remove ("project.txt");
 rename ("temp.txt","project.txt");

 if (f==0)
      {
          printf("\n\n Person not found !!! \n");
      } else
      {
            printf("\n Person Deleted successfully" );
      }

int press;
  printf("\n\n\n\t\t  PRESS 1 to try again   PRESS 2 to go to the Main menu  and PRESS  3 to Logout....  ");
    scanf("%d",&press);

    if (press==1)
          removing();
    else if (press == 2)
        menu ();
    else if (press==3)
            system("CLS");
            printf("\n Press any key to Logout.......\n\n" );


  }

 void logout ()
 {

            printf("\n Press any key to Logout.......\n\n" );
 }
