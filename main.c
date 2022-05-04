#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include<time.h>
static char pass2[3][10];
static   char n[30];
void nsu_logo();
void courses();
void coursesn();
void students();
void teachers();
void parents();
void club();
void non();
void grade();
void groupstudy(char *file);
void teacFILE(int );

void stuFILE(int);
void parFILE(int);
void clubFILE(int);
void nonFILE(int);
void post(int y,int ref,char *temp);
int ECE(char arr[]);
int ECEs();

time_t curtime;
struct stud
{
    char name[30];
    char id[15];
} st[4];

struct student
{
    char name[40];
    char id[30];
} stu[50];

struct courses
{
    char c1[20];

    char c2[20];

    char c3[20];

    char c4[20];
    int  sec1[3];
    int  sec2[3];
    int sec3[3];
    int sec4[3];


} pc[30];
struct section
{
    char sec1[3];
    char sec2[3];
    char sec3[3];
    char sec4[3];
} sec[30];

struct teacher
{
    char name[20];
    char iname[20];
} pk[3];
struct students
{
    char name[40];
    int id;
};
struct non
{
    char user[100];
    char fname[15];
    char lname[15];
    char pass[100];
    char phone[11];
    char email[50];

} ak[50];


int main()
{
    int f=1;
    int x;
    int k;
    char arr[3];

    ;

    nsu_logo();
    printf("\n\n\nHello and Welcome to North south university.\n\n\n");
    //n();


    printf("1.Teacher\n2.Student\n3.Parents\n4.C.member\n5.Non user\n");
    //scanf ("%d",&x);
    int ii;

    while(f)
    {
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            teachers();


            break;
        case 2:
            students();
            break;
        case 3:
            parents();

            break;
        case 4:
            club();



            break;
        case 5:
            non();
            break;
        default:
            // printf("The program is closed!");
            break;
        }
        printf("\nBack to main menu:press 'm'\n");
        printf("OR Press any key to exit:\n");
        char c;
        fflush(stdin);
        scanf("%c",&c);
        if (c!='m' )
        {
            f=0;
        }
        else
            printf("1.Teacher\n2.Student\n3.Parents\n4.Club.\n5.guest user\n");
        //scanf ("%d",&x);
    }
    return 0;
}
static int flag[100];
void teachers()
{
    static int  f;
    int ff=1;
    char arr[3];
    char pass[10];
    //const char pass2[3][10];
    int check;
    int z;
    int y;

    // struct teacher pk[3];


    fflush(stdin);
    // printf("Have you verified your account:\n");
    printf("1.LOGIN\n2.VERIFY\n");
    scanf("%d",&check);
    if (check==1)
    {
        printf("Enter Your initial name :");
        fflush(stdin);
        gets(arr);
        int x;
        x=strlen(arr);
        if(x>3)
        {
            printf("You entered a wrong key!there are no initial name like this!");
        }
        else
        {

            y=ECE(arr);
            // printf("%d",y);
            if (flag[y]!=1)
            {
                printf("You are not verified.please Verify Your account first.");
            }
            else
            {


                if(y==-1)
                {

                    printf("initial name didn't match !");

                }
                else
                {
                    printf("Enter password:");


                    scanf("%s",pass);
                    z=strcmp(pass,pass2[y]);
                    if (z==0)
                    {
                        char *p;
                        //p=name(y);
                        printf("Welcome to the new world %s",pk[y].name);
                        teacFILE(y);
                    }
                    else
                        printf("Password does not match !");
                }
            }

        }
    }
    else if (check==2)
    {
        printf("Enter Your initial name :");
        fflush(stdin);
        gets(arr);
        int x;
        x=strlen(arr);
        if(x>3)
        {
            printf("you Entered a wrong key.there are no initial name like this!");
        }
        else
        {
            int d;
            printf("Your Department:\n");

            printf("1.ECE\n2.BBA\n3.LAW\n");
            scanf("%d",&d);
            switch (d)
            {
            case 1:
                y=ECE(arr);
                if(y==-1)
                {
                    printf("Your Initial name is not found !");
                }
                break;
            case 2:

            default:
                break;
            }



            if (flag[y]==1)
            {
                printf("You are already verified !");

            }

            else
            {
                if (y==-1)
                {
                    printf("\ninitial name is wrong!");
                }

                else
                {

                    printf("Welcome %s\n",pk[y].name);
                    int ran,rand2,rand3;
                    ran=rand()*123;
                    printf("We sent a verification code to Your official Email address.please Check and put down here:\n");
                    printf("%d",ran);
                    printf("\n");
                    scanf("%d",&rand2);
                    int k=1;
                    while (k)
                    {
                        if (ran==rand2)
                        {
                            int f=1;
                            while (f)
                            {

                                int strl;
                                printf("Enter a password:");
                                fflush(stdin);

                                gets(pass);
                                strl=strlen(pass);
                                if(strl<6)
                                {
                                    printf("Password is not strong enough!Re enter Your password.\n");
                                }
                                else
                                {
                                    f=0;

                                }
                            }

                            k=0;

                        }
                        else
                        {
                            //printf("verification text does not match!for resent please press Enter:");
                            printf("This is last time for your verification .or restart from main menu!\n");
                            ran=rand()*123;
                            printf("%d\n",rand);
                            scanf("%d",&rand2);


                        }
                        if (rand==rand2)
                        {

                            fflush(stdin);
                            printf("Enter a password:");
                            gets(pass);
                            k=0;
                        }
                    }


                    while (ff)
                    {
                        printf("Retype the password:");
                        scanf("%s",pass2[y]);
                        z=strcmp(pass,pass2[y]);
                        if (z==0)
                        {
                            printf("password match!\n");
                            printf("You are successfully verified! \n ");
                            printf("stay log in?\n1.yes\n2.no\n");
                            int d;
                            scanf("%d",&d);
                            if(d==1)
                            {
                                teacFILE(y);
                            }
                            else
                            {
                                ff=0;
                                flag[y]=1;
                            }

                        }
                        else printf("password don't match!");
                    }
                }
            }
            //puts(pass2[y]);


        }
    }
    else
    {
        printf("You entered a wrong key!");
    }
}
void nsu_logo()
{
    printf("\n            ****        ****     .**************     ****         ****");
    printf("\n            *****       ****     ***************     ****         ****");
    printf("\n            ******      ****     *****               ****         ****");
    printf("\n            *******     ****     *****               ****         ****");
    printf("\n            **** ***    ****     *****               ****         ****");
    printf("\n            ****  ***   ****     **************.     ****         ****");
    printf("\n            ****   ***  ****      **************     ****         ****");
    printf("\n            ****    *** ****               *****     ****         ****");
    printf("\n            ****     *******               *****     ****         ****");
    printf("\n            ****      ******               *****     ****         ****");
    printf("\n            ****       *****     ***************      ***************");
    printf("\n            ****        ****     **************'       *************");

}
int ECE(char arr[])
{
    FILE *fp;
    fp=fopen("teacher.txt","r");
    char name[30];
    char r[30];
    int i=0;
    //struct teacher pk[4];

    /*do
    {


        //puts(pk[i].name);
       fgets(pk[i].iname,10,fp);
      // printf("Hello\n");
       puts(pk[i].name);

       // fscanf(fp,"%s",pk[i].iname);
    	fgets(pk[i].name,30,fp);
    //    fgets(pk[i].iname,30,fp);
        //puts(pk[i].iname);
        //printf("%d",i);
        i++;



    }
    while (!feof(fp));
    	*/
    while (1)
    {

        if(feof(fp))
        {
            break;
        }
        //puts(pk[i].name);
        else
        {
            fgets(pk[i].iname,20,fp);
            // printf("Hello\n");
            //puts(pk[i].name);

            // fscanf(fp,"%s",pk[i].iname);
            fgets(pk[i].name,20,fp);
            //    fgets(pk[i].iname,30,fp);
            //puts(pk[i].iname);
            //printf("%d",i);
            i++;
        }

    }
    ;
    //printf("%d",i);
    int k;
//char arr[10];
//gets(arr);
    for (i=0; i<3 ; i++ )
    {
        k=strncmp(arr,pk[i].iname,3);
        arr[3]='\0';
        if(k==0)
        {
            break;
        }

    }
    ;




    fclose(fp);
    //int j;

    if (k!=0)
    {
        return -1;
    }
    else return i;
    fclose(fp);
}


void non()
{
    printf("Welcome To The North south University\n");
    printf("Have you account on North south university FES ?Please sign up first for more action!\n");
    printf("1.Sign up\n2.Sign in(if already have an account)\n");
    FILE *fp;
    int s,i,j;
    static int ref[10];
    //ref[0]=0;
    scanf("%d",&s);
    char sname[30];
    char spass[30];
     i=0;
      fp=fopen("nonuser.txt","r");
      while(1)
            {
                if(feof(fp))
                {
                    break;
                }


                    fscanf(fp,"%s %s %s %s %s",ak[i].email,ak[i].pass,ak[i].fname,ak[i].lname,ak[i].user);
                    i++;

            }
    //struct non a[10];
    switch (s)
    {
    case 1:


        printf("");
        //printf("%d",i);
        int Prove = rand();
        int Robot;
        printf("\nPlease prove You Are Not a Robot for Further Process");
        printf("\nCaptcha: %d",Prove);
        printf("\nEnter The Captcha: ");
        scanf("%d",&Robot);


        if(Prove==Robot)
        {
            char user[25];
            printf("Enter User name(no space):");
            fflush(stdin);
            gets(user);
            printf("Enter Email address :");
            static char email[30];

            gets(email);

            int x,z,y;
            x=strlen(email);

            // printf("%d ",x);
            int i=0;
            /*while (fscanf(fp,"%s %s %s %s %s",ak[i].email,ak[i].pass,ak[i].fname,ak[i].lname,ak[i].user)!=EOF)
            {

            	y=strlen(ak[i].email);
            	if(x>y)
            	{
            	z=strncmp(ak[i].email,email,x);
            	email[x]='\0';

            	}
            	else{
            		z=strncmp(ak[i].email,email,y);
            	ak[i].email[y]='\0';
            	}
            	i++;
            }*/

            ;

            fclose(fp);
            int fl=0,fl2=1;
           for (i=0;i<30 ;i++ )
           {
              for (j=0;j<x ;j++ )
                  {
                      if(email[j]==ak[i].email[j])
                      {
                          fl++;
                      }
                  }
                  if(fl==x)
                  {
                      printf("sorry This email id has been used!");
                      fl2=0;
                      break;
                  }


           }
               ;



            /* for (i=0; i<10 ; i++ )
             {

                 if(ref[i]!=i-1)
                 {
                     printf("%d ",i);
                     break;
                 }

             }*/
            // int z;

            if (fl2==1)
            {

                fflush(stdin);

                // strcpy(ak[i].email,email);
                printf("    %s     ",ak[i].email);

                printf("\n\nEnter First Name: ");

                gets(ak[i].fname);

                // char Name_Last[25];
                printf("\nEnter Last Name: ");
                gets(ak[i].lname);

                //char EmailorPhone[40];
                printf("\nEnter Your Phone Number(+88): ");
                fflush(stdin);
                gets(ak[i].phone);
                int y=strlen(ak[i].phone);
                if(y==11)
                {




                    int Verification_Code;
                    Verification_Code = rand();
                    printf("\n\nA Verification Code Has Been Sent to Your Email ");
                    printf("\nThe Code is: %d",Verification_Code);

                    int Verifying_Verification_Code;
                    printf("\nEnter The Code: ");
                    fflush(stdin);
                    scanf("%d",&Verifying_Verification_Code);


                    if(Verification_Code==Verifying_Verification_Code)
                    {



                        char Gender;
                        printf("\n\nEnter Your Gender 'M' for 'Male' and 'F' for 'Female': ");
                        fflush(stdin);
                        scanf("%c",&Gender);


                        if(Gender == 'M' || Gender=='F')
                        {



                            char Password[30];
                            printf("\n\nEnter Password: ");
                            fflush(stdin);
                            gets(Password);


                            printf("\nConfirm Password: ");
                            fflush(stdin);
                            gets(ak[i].pass);

                            int initial;

                            int z;
                            z=strcmp(ak[i].pass,Password);
                            if(z==0)
                            {

                                printf("%s %s...\nYour Account Done.\n",ak[i].fname,ak[i].lname);

                                fp=fopen("nonuser.txt","a+");
                                printf("%s\n",ak[i].email);
                                printf("%s\n",ak[i].pass);
                                printf("%s\n",ak[i].fname);

                                fprintf(fp,"%s\n%s\n%s\n%s\n%s\n",email,ak[i].pass,ak[i].fname,ak[i].lname,ak[i].user);

                                fclose(fp);

                                // ref[i]=i-1;
                            }
                            else
                            {
                                printf("Password don't match!");





                            }
                        }
                        else
                        {
                            printf("\n\nGender Don't Match. Try Again?\n");
                            //signup();
                        }
                    }
                    else
                    {
                        printf("\n\nWrong Verification Code");
                        //signup();
                    }
                }


            }
            else
            {
                printf("This email id has been used!");
            }
        }
        else
        {
            printf("\n\nCaptcha Don't Match. Try Again?\n");
            // signup();
        }








        break;

    case 2:
        printf("Enter Your Email address:\n");
        char email[50];
        char passw[50];
        fflush(stdin);
        gets(email);
        int x;
        x=strlen(email);
        printf("Enter Your password:");
        fflush(stdin);
        gets(passw);
        int  y=strlen(passw);
        int i,z,k,d,j;
        int fl1=0;
        int  fl2=0;
        int cmp=0;
        struct non b[30];
       // FILE*fp=
      for (i=0;i<30 ;i++ )
      {
          for (j=0;j<x ;j++ )
          {
             if( email[j]==ak[i].email[j])
             {
                 fl1++;

             }

          }
           if(fl1!=x)
             {
                 break;
             }
             else
             {
                  for (j=0;j<y ;j++ )
            {
                if(passw[j]==ak[i].pass[j])
                {
                    fl2++;

                }

            }
               if(fl2!=y)
               {
                  break;
               }
               else
               {
                   cmp=1;
                   break;

             }


      }
          ;


        ;
        /*if(z==0 && k==0)
        {
        	d=i;
        	break;
        }*/


        if(cmp!=1)
        {
            printf("Something is wrong!");

        }
        else
        {
            printf("%d\n",i);
            printf("Welcome to New world %s",ak[i].fname);
            printf("\nSelect a option which one you wanted to know about\n");
            printf("\n1.Teachers\n2.NSU Clubs\n3.NSU Clubs Activities\n");
            int jj;
            scanf("%d",jj);
            if(jj==1)
            {
                int tc;
                FILE *fp;
                char str[100];
                printf("\n1.Dr. Rezaul Bari\n2.Dr. M. Rokonuzzaman\n3.Dr. Kazi Mohammad Abdus Salam\n4.Dr. Arshad M Chowdhury\n5.Dr. Mohammad Rashedur Rahman\n6.Dr. Hafiz Abdur Rahman\n7.Dr. Hasan Uz Zaman\n8.Dr. Shazzad Hosain\n9.Dr. Nova Ahmed\n10.Dr. Rajesh Palit\n11.Dr. Atiqur Rahman\n12.Dr. Asad Jamil\n13.Dr. Lamia Iftekhar\n14.Dr. Nabil Shovon Ashra\n15.Dr. Rashed Selim Topu\n");
                scanf("%d",&tc);

                if(tc==1)
                {
                    fp=fopen("bari.txt","r");
                }
                else if(tc==2)
                {
                    fp=fopen("rokonuzzam.txt","r");
                }
                else if(tc==3)
                {
                    fp=fopen("kazi.txt","r");
                }
                else if(tc==4)
                {
                    fp=fopen("arshad.txt","r");
                }
                else if(tc==5)
                {
                    fp=fopen("rashedur.txt","r");
                }
                else  if(tc==6)
                {
                    fp=fopen("hafiz.txt","r");
                }
                else if(tc==7)
                {
                    fp=fopen("hasan.txt","r");
                }
                else if(tc==8)
                {
                    fp=fopen("shazzad.txt","r");
                }
                else if(tc==9)
                {
                    fp=fopen("nova.txt","r");
                }
                else if(tc==10)
                {
                    fp=fopen("rajesh.txt","r");
                }

                else if(tc==11)
                {
                    fp=fopen("atiqur.txt","r");
                }
                else if(tc==12)
                {
                    fp=fopen("asad.txt","r");
                }
                else if(tc==13)
                {

                    fp=fopen("lamia.txt","r");
                }
                else if(tc==14)
                {
                    fp=fopen("nabil.txt","r");
                }
                else if(tc==15)
                {
                    fp=fopen("rsl.txt","r");
                }
                while(!feof(fp))
                {
                    fgets(str,100,fp);
                    printf("%s",str);

                }

                fclose(fp);
            }
            else if(jj==2)
            {
                int ss;
                FILE *fpc;
                char ssttrr[3000];
                printf("\n1.NSU IEEE CLUB\n2.NSU SOCIAL SERVICE CLUB\n3.NSU ETHICS CLUB\n");
                scanf("%d",&ss);
                if(ss==1)
                {
                    fpc=fopen("ieee.txt","r");
                }
                else if(ss==2)
                {
                    fpc=fopen("nsuss.txt","r");
                }
                else if(ss==3)
                {
                    fpc=fopen("ethics.txt","r");
                }
                while(!feof(fpc))
                {
                    fgets(ssttrr,100,fpc);
                    printf("%s",ssttrr);
                }
                fclose(fpc);
            }
            else if(jj==3)
            {
               int pp;
               FILE *fpacm;
               char strstr[300];
               printf("\n1.NSU ACM STUDENT CHAPTER\n2.NSU IEEE\n3.NSUSC\n4.NSU PROBLEM SOLVER\n");
               scanf("%d",&pp);
               if(pp==1)
               {
                   fpacm=fopen("acm.txt","r");
               }
               else if(pp==2)
               {
                   fpacm=fopen("ieee.txt","r");
               }
               else if(pp==3)
               {
                   fpacm=fopen("nsusc.txt","r");
               }
               else if(pp==4)
               {
                   fpacm=fopen("nsups.txt","r");
               }
               while(!feof(fpacm))
               {
                   fgets(strstr,100,fpacm);
                   printf("%s",strstr);
                   fclose(fpacm);
               }
            }

        }







        break;
    default:
        break;
    }

}
}

void teacFILE(int y)
{
    //FILE *fp;
    int i;
    // fp=fopen("teacher.txt","r");
    char att[4];

    static int f[40];
    int d;
    static int q[100],m[100],bq[100];

    int fk=1;
    int x;
    printf("%s please choose your option\n",pk[y].name);
    while(fk)
    {

        printf("\n1.Courses\n2.Grade submission\n3.Message\n4.Faculty launch\n5.main menu\n");

        scanf("%d",&d);


        switch (d)
        {
        case 1:

            coursesn(y,0);

            int c;
            scanf("%d",&c);
            char *cou;
            char *sect;
            char *n;
            switch (c)
            {


            case 1:
                printf("");

                // strcpy(n,pk[y].iname);
                n=pk[y].iname;
                printf("%s",n);

                cou=pc[y].c1;

                sect=sec[y].sec1;
                courses(cou,sect,0,n,y);






                break;
            case 2:
                cou=pc[y].c2;

                sect=sec[y].sec2;
                courses(cou,sect,0,y);

                break;
            case 3:
                cou=pc[y].c3;

                sect=sec[y].sec3;
                courses(cou,sect,0,y);
                break;
            case 4:
                cou=pc[y].c3;

                sect=sec[y].sec3;
                courses(cou,sect,0,y);
                break;
            default:
                break;
            }


            break;
        case 2:

           /* if(f[y]!=1)
            {
                printf("Please Update Your course Outline.\n");
                printf("Quiz:\n");
                scanf("%d",&q[y]);
                printf("Mid term:\n");
                scanf("%d",&m[y]);
                printf("Best Quiz:\n");
                scanf("%d",&bq[y]);
                printf("Your Course Outline has been update!\n");

                f[y]=1;

            }
            else
            {
                printf("Total quizzes  %d\n",q[y]);
                printf("Total mid term %d\n",m[y]);
                printf("Best quizzes:%d\n",bq[y]);
                printf("For Exit press 1;\n");
                scanf("%d",&x);
                if(x==1)
                {
                    fk=0;
                }
                else fk=1;
            }
*/


            break;
        case 3:
            /*FILE *fti;
            char tempk[100];
            fti=fopen("discuss.txt","a+");
            int i=0;
            do
            {
            //fgets(fti,90,tempk);
            fscanf(fti,"%s",tempk);
            printf("%s",tempk);
            i++;
            } while (!feof(fti));
            fclose(fti);*/
            //printf("%s",temp);*/
            break;
        case 4:
            printf("Online!\n");
            for (i=0; i<3 ; i++ )
            {
                printf("%d.%s\n",i+1,pk[i].name);
            }
            printf("Dear respected teacher ,It's a open place to share your idea with your coulige.\n");

            FILE*fp;
            char fkk[3];
            char discuss[40][100];
            strncpy(fkk,pk[y].iname,3);
            fkk[3]='\0';

            int f=1;
            while(f)
            {
                int x;
                printf("press 1 for continue.press 2 for exit");
                scanf("%d",&x);
                if(x==2)
                {
                    f=0;
                }
                else
                {
                    char tempk[100];
                    fp=fopen("discuss.txt","r");
                    int i=0;

                    /*do
                    {

                    	fgets(tempk,90,fp);

                    	printf("%s",tempk);
                    	i++;
                    } while (!feof(fp));*/
                    /*for (;!feof(fp) ; )
                    {
                    	fgets(tempk,90,fp);

                    	printf("%s",tempk);
                    }*/
                    while(1)
                    {

                        if(feof(fp))
                        {
                            break;
                        }
                        fgets(tempk,90,fp);

                        printf("%s",tempk);
                    }
                    ;
                    fclose(fp);

                    fp=fopen("discuss.txt","a+");

                    printf("%s :",fkk);
                    fflush(stdin);
                    gets(discuss[y]);

                    fprintf(fp,"%s : %s\n",fkk,discuss[y]);

                    fclose(fp);
                    //FILE *fti;

                }
            }

            break;

        default:
            fk=0;
            break;
        }

    }

}


void students()
{
    printf("1.Login\n2.Verify\n");
    int s;
    int yy;
    static	char flag[40];

    static password[40][20];
    scanf("%d",&s);
    switch (s)
    {
    case 1:
        printf("Enter ID : ");
        char temp[30];
        fflush(stdin);
        gets(temp);
        ;
        yy=ECEs(temp);
        if(yy==-1)
        {
            printf("There are No student ID like this!");

        }
        else
        {
            if(flag[yy]!=1)
            {
                printf("You are not Verified.Please Verify first.\n");

            }
            else
            {
                char temppass[30];
                printf("Enter password:");
                gets(temppass);
                int x;
                x=strcmp(temppass,password[yy]);
                if(x!=0)
                {
                    printf("Wrong password!please try again .\n");

                }
                else
                {
                    printf("Welcome to new world %s",stu[yy].name);
                    stuFILE(yy);
                }
            }
        }

        break;

    case 2:
        printf("Enter ID:\n");
        fflush(stdin);

        gets(n);
        //scanf("%d",&n);
        yy=ECEs(n);
        if(yy==-1)
        {
            printf("You Entered a wrong ID!");
        }
        else
        {
            //printf("%d ",yy);
            printf("welcome %s\n",stu[yy].name);
            printf("A Verification code has been sent your email Address .check and put down here.\n");
            int r;
            r=rand()*12;
            printf("%d\n",r);
            int r1;
            scanf("%d",&r1);

            if(r1==r)
            {
                char pass[20];
                printf("Enter a password:\n");
                scanf("%s",pass);
                printf("Confirm Password:\n");
                scanf("%s",password[yy]);
                int z;
                z=strcmp(pass,password[yy]);
                {
                    if(z==0)
                    {
                        flag[yy]=1;
                        printf("You are successfully verified !\n");

                        printf("Stay log in?\n");
                        printf("1.YES\n2.NO\n");
                        int check;
                        scanf("%d",&check);
                        if(check==1)
                        {
                            printf("Welcome to new world %s",stu[yy].name);
                            stuFILE(yy);
                        }
                        else if(check==2)
                        {
                            printf("");
                        }
                        else
                            printf("You entered a wrong key!");
                    }
                    else
                        printf("Password mismatch!");
                }


            }
            else
            {
                printf("Verification code mismatch!");
            }
        }
        break;

    default:
        break;
    }


}
int ECEs(char d[])
{


    FILE*fp;
    fp=fopen("D:\\mission nsu\\student.txt","r");

    int i=0;
    int k;
    int z;

    while(1)
    {
        //printf("%d \n",i);
        int x;
        x=strlen(stu[i].id);
        fgets(stu[i].id,35,fp);
        //printf("%s\n",stu[i].id);
        fgets(stu[i].name,35,fp);
        //printf("%s",stu[i].name);
        i++;
        if(feof(fp))
        {
            break;
        }
    }

    //gets(arr);
    for (i=0; i<40 ; i++ )
    {
        k=strncmp(d,stu[i].id,10);
        d[10]='\0';
        if(k==0)
        {
            break;
        }

    }
    ;




    fclose(fp);
    //int j;

    if (k!=0)
    {
        return -1;
    }
    else return i;
    // fclose(fp);
}
//static int i;
void courses(char *cou,char *sec,int ref,char*name,int  in)


{


//printf("hi %s",sec);
    int jjj;
    FILE *fp;
    static char temp[100];
    static char temp2[100];
    static char temp3[100];
    static char sample1[30];
    //	char folder[]="F:\\\\mission nsu\\\\";
    strcpy(temp,"D:\\\\mission nsu\\\\");
    //printf("%s\n",temp);
    strcat(temp,cou);

    strcpy(temp2,temp);
    strcat(temp2,"\\\\");


    //printf("%s",temp2);
    static char taskk[40];
    strcat(temp2,sec);
    strcat(temp2,"\\\\");
    static char fname[40];
    strcpy(fname,temp2);
    //strcat(fname,sec);
    strcat(fname,"grade.txt");
    static char postt[30];
    strcpy(taskk,temp2);
    strcpy(postt,temp2);

   strcpy(sample1,temp2);
   strcat(sample1,"g.txt");
   //printf("%s\n",sample1);
    strcat(postt,"post\\\\post.txt");
    //printf("%s\n",taskk);
    strcat(taskk,"task\\\\");
    // printf("%s\n",taskk);
    strcpy(temp3,temp2);
    strcat(temp2,sec);






    //printf("%s",temp2);
    //char

    // strcat(temp3,"res.txt");
   // printf("%s",temp3);
    char temp4[20];
    strcpy(temp4,temp2);
    strcat(temp4,"time.txt");

    strcat(temp2,"stu.txt");
    //printf("%s\n",temp2);
    //strcpy(temp,cou);
    //strcat(temp,s[y].sec1);
    strcat(temp,"a.txt");
    //printf("%s",temp);

    fp=fopen(temp4,"a+");
    char fac[40];
    char time[40];
    char loc[40];
    char cre[30];
    while(1)
    {
        if(feof(fp))
        {
            break;
        }
        fgets(fac,40,fp);
        fgets(cre,30,fp);
        fflush(stdin);
        fgets(time,40,fp);
        fgets(loc,40,fp);

    }
    fclose(fp);
    if(ref!=1)
    {
        printf("%s\n",cre);
        printf("\n%s\n",time);
        printf("\n%s\n\n\n\n",loc);

    }
    else
    {
        printf("\n%s\n",fac);
        printf("%s\n",cre);
        printf("%s\n",time);
        printf("\n%s\n\n\n\n",loc);
    }

    fp=fopen(temp,"a+");
    int i=0;

    char cool[1000];
    while(1)
    {
        fgets(cool,1000,fp);
        printf("%s",cool);
        if(feof(fp))
        {
            break;
        }
    }
    fclose(fp);
    fp=fopen(temp2,"a+");

    int d;
    if(ref!=1)
    {

        printf("\n1.Attendance\n2.Task\n3.Time line\n4.Grade submission\n");
        scanf("%d",&d);
    }
    else
    {
        printf("\n1.Class circumstance\n2.task\n3.Time line\n4.Grade\n5.group study\n");
        scanf("%d",&d);
    }
    int y;


    //printf("%s",temp2);


    switch (d)
    {
    case 1:
        if(ref==1|| ref!=1 )
        {
            i=0;
            int pp;
            static char tempr[4][40];
            struct student in[40];
            FILE*re=fopen("student.txt","r");
            int inr=0;
            //printf("%s\n",stu[0].name);
           // int l=strlen(stu[0].name);
            //printf("%d\n",l);
            //printf("%s\n",name);


            while(1)
            {
                //fgets(st[i].id,11,fp);
                fflush(stdin);
                fscanf(fp,"%s",st[i].id);
                fgets(st[i].name,26,fp);
                //printf("%s %s",st[i].id,st[i].name);
                i++;
                if(feof(fp))
                {
                    break;
                }
            }
            int length;
            length=strlen(n);
            int l;
            int j=0;
            int z;

             int fll=0,ff=0;
            if(ref==1)
            {

                        ;
                for (jjj=0;jjj<4 ;jjj++ )
                {
                   // printf("%c",st[j].name[i]);
                   /*for (j=0;j<length ;j++ )
                   {
                       if(name[j]==st[i].name[j])
                    {
                        fll++;
                        printf("%d\n",fll);
                    }
                   }*/
                       ;
                   /*if(name[i]==st[j].name[i])
                    {
                        fll++;
                        //printf("%d\n",fll);
                    }*/
                    z=strcmp(n,st[jjj].id);
                    if(z==0)
                    {
                        break;
                    }

                }


                    ;
            }
            //printf("%d\n",length);
            fclose(fp);

            static  char clas[4][4];
            fp=fopen("i.txt","r");
            int i=0;
            while(1)
            {
                if(feof(fp))
                {
                    break;
                }
                fscanf(fp,"%s",clas[i]);
                printf("%s\n",clas[i]);
                i++;

            }
            fclose(fp);
            printf("CLASS 1.\nCLASS 2.\nCLASS 3.\nCLASS 4.\n");
            int cl;
            scanf("%d",&cl);
            // printf("%s",clas[cl]);
            //int asci=cl+48;
            if(ref!=1)
            {

                printf("Do You want to comment this class\n1.yes\n2.no\n");
                int d;
                scanf("%d",&d);
                // printf("%s\n",temp3);
                if(d==1)
                {
                    pp=cl;
                }
                else
                {
                    pp=5;
                }

            }
            if(ref!=1)
            {



            //strcpy(temp3,tempr);
            int fl=0;
            if(cl==1)
            {
                strcat(temp3,clas[0]);
                strcat(temp3,".txt");
                strcpy(tempr[0],temp3);
                //printf("%s\n",temp3);
                fp=fopen(temp3,"r");
                if(fp!=NULL)
                {
                    printf("Class 1 done.");
                    if(ref==1)
                    {
                        char cn[20];
                        char cn2[20];
                        char c[4];
                        for (i=0; i<6 ; i++ )
                        {
                            fscanf(fp,"%s",cn);
                            fscanf(fp,"%s",cn2);
                            fscanf(fp,"%c",c[i]);
                            printf("%c",c[i]);
                        }

                    }
                }
                else
                {
                    fp=fopen(temp3,"w+");
                    //printf("%d\n",ftell(fp));
                    i=0;
                    int sum=0;
                    //for (i=1; i<=4 ; i++ )

                    char cname[30];
                    printf("      class %d\n",cl);
                    fprintf(fp,"class %d\n",cl);
                    printf("class name:");
                    fflush(stdin);
                    gets(cname);
                    fprintf(fp,"class name:%s\n",cname);
                    if(cl%pp==0)
                    {
                        printf("\n ID                 NAME                      ATTENDENCE      comments\n\n");
                    }
                    else if(cl%pp!=0)
                    {
                        printf("\n ID                 NAME                      ATTENDENCE\n\n");
                    }

                    int j;

                    for (j=0; j<4 ; j++ )
                    {

                        //printf("\n ID                 NAME                      ATTENDENCE      comments\n\n");
                        printf("\n");
                        printf("%s    %s",st[j].id,st[j].name);
                        char att[4];
                        char com[50];
                        scanf("%s",&att[j]);
                        fprintf(fp,"%c\n",att[j]);

                        if(cl%pp==0)
                        {
                            fflush(stdin);
                            gets(com);
                            fprintf(fp,"%s\n",com);
                        }

                        if(att[j]=='p')
                        {
                            sum++;
                            //printf("\n%d ",sum);
                        }

                    }
                    //float res;
                    //res=((float)sum/4)*100;
                    printf("\nToDaY Present:%.2lf%%",((float)sum/4)*100);
                    sum=0;
                    fclose(fp);
                }
            }
            else
            {
                for (i=0; i<cl ; i++ )
                {
                    strcat(temp3,clas[i]);
                    //printf("%s\n",temp3);
                    strcat(temp3,".txt");
                    fp=fopen(temp3,"r");
                    strcpy(tempr[cl-1],temp3);

                    if(fp!=NULL)
                    {
                        printf("class %d done!\n",i+1);
                        if(cl==i+1)
                        fl=1;
                        break;
                    }
                    else
                    {
                        printf("class %d incomplete.\n",i+1);

                        {
                            if(i+1==cl)
                                fl=2;
                            printf("%d ",i);
                        }

                    }
                }
                if(fl==2)
                {
                    if(fl==2)
                    {
                        printf("Please complete previous class!  ");
                    }
                    else
                    {
                        printf("This class also has completed!");
                    }


                }
                else
                {
                    strcat(temp3,clas[cl-1]);
                    strcat(temp3,".txt");
                    fp=fopen(temp3,"r");
                    printf("%s\n",temp3);
                    fp=fopen(temp3,"w+");
                    //printf("%d\n",ftell(fp));
                    i=0;
                    int sum=0;
                    //for (i=1; i<=4 ; i++ )

                    char cname[30];
                    printf("      class %d\n",cl);
                    fprintf(fp,"class %d\n",cl);
                    printf("class name:");
                    fflush(stdin);
                    gets(cname);
                    fprintf(fp,"class name:%s\n",cname);
                    if(cl%pp==0)
                    {
                        printf("\n ID                 NAME                      ATTENDENCE      comments\n\n");
                    }
                    else if(cl%pp!=0)
                    {
                        printf("\n ID                 NAME                      ATTENDENCE\n\n");
                    }

                    int j,sum1=0;
                    for (j=0; j<4 ; j++ )
                    {

                        //printf("\n ID                 NAME                      ATTENDENCE      comments\n\n");
                        printf("\n");
                        printf("%s    %s",st[j].id,st[j].name);
                        char att[4];
                        char com[50];
                        scanf("%s",&att[j]);
                        fprintf(fp,"%c\n",att[j]);

                        if(cl%pp==0)
                        {
                            fflush(stdin);
                            gets(com);
                            fprintf(fp,"%s\n",com);
                        }

                        if(att[j]=='p')
                        {
                            sum1++;
                            //printf("\n%d ",sum);
                        }
                    }

                    //float res;
                    //res=((float)sum/4)*100;
                    printf("\nToDaY Present:%.2lf%%",((float)sum1/4)*100);
                    sum=0;
                    fclose(fp);


                }
            };


            }
            fclose(fp);
            i=0;
           //int j=0;
           if(ref==1)
           {



        printf("%s\n",tempr[cl-1]);
        i=0;
       fp=fopen(tempr[cl-1],"r");
       char cna[20];
       char cn2[20];
        printf("Welcome to class circumstance %s\n\n",name);
       static char cl1[4][5];
       static char comm[4][40];
       if(fp!=NULL)
       {
           while(1)
        {
          if(feof(fp))
          {
              break;
          }
          fgets(cna,20,fp);
          printf("%s\n",cna);
          fgets(cn2,20,fp);
           printf("%s\n",cn2);
           for (i=0;i<4 ;i++ )
           {
                fscanf(fp,"%s",cl1[i]);
        //fgets(cl1[i],5,fp);
             //printf("%s\n",cl1[i]);
           }

           if(cl1[j]=='p')
           {
               printf("Present");
           }

          else
          {
              printf("Absent");
          }



        }
       }
           }

            //printf("%s\n",cl1[0]);
        }
        else
        {
            //printf("CLASS 1\nCLASS 2");
            printf("hiii");
        }

        break;
    case 2:
        printf("");
        int d;
        if(ref!=1)
        {
            printf("1.New task\n2.Review all task\n3.Search Task\n");

            scanf("%d",&d);
        }
        else
        {
            printf("1.Review Task\n");
            scanf("%d",&d);
            if(d==1)
            {
                d=2;
                //printf("hi");
            }

        }
        static char taskn[30][30];
        switch (d)
        {
        case 1:
            if(ref!=1)

            {


                printf("Task code:\n");
                static char t[20];
                fflush(stdin);



                gets(t);

                ;


                printf("Write a question:\n");
                char que [200];
                fflush(stdin);
                gets(que);
                FILE *fl=fopen("tflag.txt","a+");

                //y=strlen(temp3);

                //int k=y-5;

                // temp3[y-5]='\0';
                que[200]='\0';
                strcat(taskk,t);
                strcat(taskk,"t.txt");


                strcpy(taskn[i],taskk);


                printf("%s",taskn[0]);

                fp=fopen(taskk,"a+");
                printf("%s\n",taskk);

                // fprintf(fp,"Task code:%s\n",t);
                fprintf(fp,"%s\n",que);
                fprintf(fl,"%d ",ftell(fp));
                fclose(fp);
                printf("Your question has been updated.\n");
                i++;
            }
            /*else
            {
            	char tp[10];
            	fp=fopen(taskn[0],"a+");
            	/*while(1)
            	{
            		if(feof(fp))
            		{
            			break;
            		}
            		else {
            	fgets(tp,200,fp);
            	printf("%s\n",tp);
            		}
            	}
            	char sp[200];
            	while( fscanf(fp,"%s",sp)!=EOF)
            	{

            		printf("%s\n",tp);
            		printf("%s",sp);
            	}

            }*/

            break;
        case 2:
            printf("");
            FILE*fl=fopen("tflag.txt","a+");
            printf("hello");

            int f[15];
            int i=0;
            char ta[50];
            while(1)
            {
                if(feof(fl))
                {
                    break;
                }
                fscanf(fl,"%d",&f[i]);
                printf("%s\n",taskn[i]);

                fp=fopen(taskn[i],"a+");
                while(1)
                {
                    if(feof(fp))
                    {
                        break;
                    }
                    fgets(ta,50,fp);
                    printf("%s",ta);
                    if(ftell(fp)==f[i])
                    {
                        int d;
                        static char subb[30];
                        strcpy(subb,taskn[i]);
                        int y=strlen(subb);
                        subb[y-4]='\0';
                        strcat(subb,"tt.txt");
                        FILE *tt;

                        if(ref!=1)
                        {

                            printf("1.submission\n2.skip\n");
                            scanf("%d",&d);
                            char  submission[100];
                            if(d==1)
                            {
                                tt=fopen(subb,"r");
                                while(1)
                                {
                                    if(feof(tt))
                                    {
                                        break;
                                    }
                                    fgets(submission,100,tt);
                                    printf("%s",submission);
                                }
                                fclose(tt);
                            }
                        }
                        else
                        {
                            printf("1.submit solution \n2.skip\n");
                            scanf("%d",&d);
                            char soul[300];
                            if(d==1)
                            {
                                tt=fopen(subb,"a+");
                                gets(soul);

                                fprintf(tt,"%s\n",name);
                                fprintf(tt,"%s\n",soul);
                                fclose(tt);
                                printf("done");

                            }

                        }


                    }
                }

                i++;
            }

//

            fclose(fl);


        default:
            break;

        }

        break;




        //fp=fopen(t)

    case 3:	/*printf("welcome to news feed.\n");
									printf("1.Time line\n2.Write a post.\n")

									printf("Write A post Here:\n");
									char post[200];
									//fflush(stdin);
									gets(post);
									int k;
									k=strlen(temp3);
									temp3[k-7]='\0';
									strcat(temp3,"post.txt");
									printf("\n%s\n",temp3);
									fp=fopen(temp3,"a+");
									//fprintf(fp,"%s:\n%s\n",pc[y].iname,post);
									fclose(fp);*/
        //printf("%s",pk[kk].name);
        printf("WELCOME TO NEWS FEED\n\n ");
        //printf("%s",name);
        //="F:\\\\mission nsu\\\\post\\\\post.txt";
        //printf("%s",postt);

        char read [1000];
        int k;
        static  char flag[30];
        strcpy(flag,postt);
        int len=strlen(flag);
        flag[len-4]='\0';
        strcat(flag,"fl.txt");
        printf("1.WRIGHT A POST\n2.READ NEWS FEED\n");
        int ppp;
        scanf("%d",&ppp);

        switch (ppp)
        {
        case 1://

            fp=fopen(postt,"a+");
            char postk[200];
            fflush(stdin);
            gets(postk);
            //time_t rawtime;
            //  struct tm *info;
            //char buffer[10];
            //time( &curtime );
            //info = localtime( &rawtime );
            //printf("%s", asctime(info));

            //	time(&curtime);
            //printf("Current time = %s", ctime(&curtime));
            // char *timee;
            // timee=asctime(info);
            // printf("%s",timee);


            printf("%s",flag);
            FILE*fa=fopen(flag,"a+");



            if(ref==1 || ref==0)
            {
                fprintf(fp,"\n%s",name);
                // fprintf(flag,"%d ",ftell(fp));
                // int y=ftell(fp);


            }
            else
            {
                fprintf(fp,"%s\n",name);
                // int y=ftell(fp);

                //fprintf(flag,"%d ",ftell(fp));
            }

            fprintf(fp,"%s\n",postk);
            //int fl=ftell(fp);

            fprintf(fa,"%d ",ftell(fp));
            fclose(fa);
            // char putul[20]="comments";
            //fprintf(fp,"1.comments.2.skip");
            // fprintf(fp,"\n");
            //fclose(fa);
            k=strlen(postk);
            fclose(fp);


            printf("\nYour post successfully updated!\n ");
            break;
        case 2:
            // fp=fopen(postt,"a+");
            //char pn[5];
            printf("");

            char readpost[100];
            int z=strlen(name);

            int y;
            y=strlen(name);
            //  int sum=0;
            //int d,y;
            //y=strlen(readpost);
            //printf("%d",y);
            char ikk[4];
            FILE*in;
            in=fopen("i.txt","r");
            i=0;
            static char ptr[20][20];
            int sum=0;
            while(1)
            {
                if(feof(in))
                {
                    break;
                }
                //fgets(ikk,3,in);
                fscanf(in,"%s",ikk);

                strcpy(ptr[i],ikk);
                //	printf("%s  ",ptr[i]);

                i++;
            }
            fclose(in);

            i=0;

            FILE*fn=fopen(flag,"a+");
            fp=fopen(postt,"a+");
            int fl;
            while(1)
            {
                if(feof(fn))
                {
                    break;
                }
                fscanf(fn,"%d",&fl);
                //printf("%d\n",fl);
                //i++;

                while(1)
                {
                    if(feof(fp))
                    {
                        break;
                    }

                    fgets(readpost,200,fp);

                    printf("%s",readpost);
                    int d;
                    if(ftell(fp)==fl)
                    {
                        printf("1.Comments\n2.Skip\n");

                        scanf("%d",&d);
                        if(d==1 || d==2)
                        {
                            sum+=1;
                            int k;
                            k=sum-1;
                            //printf("%d\n",k);
                            //printf(" %s \n",ptr[k]);
                            char txt[20]="i.txt";
                            y=strlen(postt);
                            static char temp[20];
                            strcpy(temp,ptr[k]);
                            //printf("%s\n",temp);
                            strcat(temp,txt);
                            //printf("%s\n",temp);
                            postt[y-4]='\0';
                            //printf("%s\n",postt);

                            strcat(postt,temp);
                            //printf("%s\n",postt);
                            //strcat(postt,".txt");
                            //printf("%s\n",postt);
                            if(d==1)
                            {
                                char comments[50];
                                char rcomments[50];
                                FILE*ne;
                                ne=fopen(postt,"a+");
                                while(1)
                                {
                                    if(feof(ne))
                                    {
                                        break;
                                    }
                                    fgets(rcomments,50,ne);
                                    printf("%s\n",rcomments);

                                }
                                fclose(ne);
                                printf("1.Skip\n2.Wright a comments\n");
                                int co;
                                scanf("%d",&co);
                                if(co!=1)

                                {
                                    ne=fopen(postt,"a+");
                                    fflush(stdin);
                                    gets(comments);
                                    fprintf(ne,"%s%s\n",name,comments);
                                    printf("Your comments has been done!");
                                    fclose(ne);
                                }

                            }
                        }

                        //i++;
                        break;
                    }
                    if(d==3)
                    {
                        break;
                    }
                }
                // fclose(fp);
                i++;

            }
            fclose(fn);
            fclose(fp);




            break;

        default:
            break;

//grade(in,fname);

        }


        break;
    case 4:
        printf("%s\n",fname);


        if(ref!=1)
        {
            grade(in,fname);

        }
        if(ref==1)
        {
           static int q[4][4];
            static   int m[4][4];
           static int f[4];
          static  int k;
            fp=fopen(fname,"r");
            i=0;
            if(fp!=NULL)
            {
                while(1)
                {
                   if(feof(fp))
                   {
                       break;
                   }
                   for (i=0;i<4 ;i++ )
                   {
                       for (k=0;k<4 ;k++ )
                           ;
                        fscanf(fp,"%d",&q[i][k]);

                   }



                for (i=0;i<4 ;i++ )
                {
                    for (k=0;k<2 ;k++ )
                    {
                        fscanf(fp,"%d",&m[i][k]);
                    }


                }
                for (i=0;i<4 ;i++ )
                {
                    fscanf(fp,"%d",&f[i]);
                }
                    ;


                }
                 for (k=0;k<4 ;k++ )
                   {
                       printf("quizz %d:%d\n",i+1,q[jjj][k]);
                   }
                 for (k=0;k<2 ;k++ )
                   {
                       printf("MID %d:%d\n",k+1,q[jjj][k]);
                   }

                printf("Final marks:%d\n",f[jjj]);
            }
        }
        break;
    case 5:
        printf("%s\n",sample1);
        if(ref==1)
        {


        }
        break;


    default:
        break;
    }

}





void stuFILE(int yy)
{
    printf("%s please choose your option!\n",stu[yy].name);
    printf("\n1.Courses\n2.Message\n3.Notification\n");
    int d;
    scanf("%d",&d);
    /*FILE*fp;
    fp=fopen("coursesECEs","r");
    int i;
    struct courses stuc[30];

    i=0;
    while(1)
    {
    	if(feof(fp))
    	{
    		break;
    	}
    	fscanf(fp,"%s",stuc[i].c1);
    	fscanf(fp,"%s",stuc[i].sec1);
    	i++;

    }*/
    int r;
    r=1;
    ;
    switch (d)
    {
    case 1:
        printf("");
        coursesn(yy,r);
        int c;

        char *cou;
        char *sect;
        char*na;
        scanf("%d",&c);

        switch (c)
        {
        case 1:
            cou=pc[yy].c1;
            sect=sec[yy].sec1;
            na=stu[yy].name;
            courses(cou,sect,1,na,yy);

            break;
        case 2:
            break;
        case 3:
            break;

        default:
            break;

        }

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;


    default:
        break;
    }
}


void coursesn(int y,int ref)
{
    FILE*fp;
    if(ref!=1)
    {
        fp=fopen("courseECE.txt","r");
    }
    else
    {
        fp=fopen("coursesECEs.txt","r");
    }

    int i=0;

    while(fscanf(fp,"%s %s %s %s",pc[i].c1,pc[i].c2,pc[i].c3,pc[i].c4)!=EOF)
    {
        i++;
    }//ll
    fclose(fp);
    /*while(1)
    {
    	if(feof(fp))
    }*/

    //FILE*fp;
//	if()
    if(ref!=1)
    {
        fp=fopen("D:\\mission nsu\\section.txt","r");
    }
    else
        fp=fopen("sections.txt","r");




    i=0;
    int d[13];

    while(fscanf(fp,"%d %d %d %d",&pc[i].sec1[i],&pc[i].sec2[i],&pc[i].sec3[i],&pc[i].sec4[i])!=EOF)
    {

        i++;

    }



    fclose(fp);
    if(pc[y].sec1[y]!=0)
    {
        printf("1.%s sec %d\n",pc[y].c1,pc[y].sec1[y]);
        if(pc[y].sec2[y]!=0)
        {
            printf("2.%s sec %d\n",pc[y].c2,pc[y].sec2[y]);
            if(pc[y].sec3[y]!=0)
            {
                printf("3.%s sec %d\n",pc[y].c3,pc[y].sec3[y]);
            }
            if(pc[y].sec4[y]!=0)
            {
                printf("4.%s sec %d\n",pc[y].c4,pc[y].sec4[y]);
            }




        }


    }


    FILE *section=fopen("section.txt","r");

    i=0;
    while(1)
    {
        fscanf(section,"%s",sec[i].sec1);
        fscanf(section,"%s",sec[i].sec2);
        fscanf(section,"%s",sec[i].sec3);
        fscanf(section,"%s",sec[i].sec4);
        i++;
        if(feof(section))
        {
            break;
        }

    }
    fclose(section);
}
void parents()
{

    static  char idp[20][10];
    static  char pa[20][15];
    static char uname[20][20];
    FILE*fp;
    fp=fopen("ECEP.txt","a+");
    int i=0;
    while(1)
    {
        if(feof(fp))
        {
            break;
        }
        fscanf(fp,"%s",idp[i]);
        //printf("%s\n",idp);
        fscanf(fp,"%s",pa[i]);
        //printf("%s\n",pa);
        fscanf(fp,"%s",uname[i]);
        i++;
        //printf("%s\n",uname);
    }
    fclose(fp);

    printf("1.Login\n2.Verify\n");
    int d;
    scanf("%d",&d);
    if(d==1)
    {
        char  niid[15];
        char passs[20];
        printf("Enter your child id:");
        static char cid[15];
        fflush(stdin);
        gets(cid);
        int k;
        k=ECEs(cid);
        if(k<0)
        {
            printf("ID not found!");

        }
        else
        {
            printf("Enter your ID:\n");
            gets(niid);
            printf("Enter  Password:\n");
            gets(passs);
            int  z,zz;
            for (i=0; i<20 ; i++ )
            {


                ;
                z=strcmp(niid,idp[i]);
                //printf("%s\n",idp[i]);
                int y=strlen(idp[i]);
                //printf("%d\n",y);

                // printf("%s\n",pa[i]);

                if(z==0)
                {
                    zz=strcmp(passs,pa[i]);
                    if(zz=0)
                    {
                        printf("Welcome to new world %s",uname[i]);
                        printf("Parents of %s",stu[k].name);
                    }
                }

            }

        }



    }

    else if(d==2)
    {
        printf("Enter your child id:");
        static char cid[15];
        fflush(stdin);
        gets(cid);
        char check[15];
        strcpy(check,cid);
        check[7]='\0';
        //printf("%s\n",check);
        //printf("%s\n",check);
        int jj=0,ch;
        for (jj=0; jj<20 ; jj++ )
        {
            ;
            ch=strcmp(check,idp);

            if(ch==0)
            {
                printf("You  are already verified!");
                break;
            }
        }
        if(ch!=0)
        {


            int k;
            k=ECEs(cid);
            if(k<0)
            {
                printf("ID not found!");

            }
            else
            {
                printf("\nAre you parents of %s\n",stu[k].name);
                printf("SESSION:");
                if(stu[k].id[3]=='1')
                    printf("Spring");
                else  if(stu[k].id[3]=='2')
                    printf("Summer");
                else
                    printf("Fall");
                int i;
                for (i=0; i<2 ; i++ )
                {
                    printf("%c",stu[k].id[i]);

                }
                printf("\n\n\n1.Yes\n2.no\n");
                printf("\n");
                int che;
                scanf("%d",&che);
                if(che==1)
                {
                    printf("We sent a verification code  to your parents.please check and put down here..:\n");
                    int ran=rand();
                    printf("%d\n\n",ran);
                    int randc;
                    scanf("%d",&randc);
                    char use[15];
                    if(ran==randc)
                    {
                        printf("Set a user name:\n");
                        fflush(stdin);
                        gets(use);
                        printf("Your id number is:");
                        static char nid[15];
                        strcpy(nid,stu[k].id);
                        nid[7]='\0';
                        printf("%s\n",nid);

                        printf("\n%s\n",nid);
                        printf("\nYou need this id to login your account.so please  don't forget .\n ");
                        printf("Enter a password:\n");
                        char pas[20];

                        fflush(stdin);
                        gets(pas);
                        printf("confirm password:\n");
                        char pas2[20];
                        gets(pas2);
                        int  z=strcmp(pas,pas2);

                        if(z==0)
                        {
                            printf("You are verified.\nStay login?\n1.Yes\n2.No\n");
                            fp=fopen("ECEP.txt","a+");
                            fprintf(fp,"%s\n",nid);
                            fprintf(fp,"%s\n",pas2);
                            fprintf(fp,"%s\n",use);
                            fclose(fp);
                            int v;
                            scanf("%d",&v);
                            if(v==1)
                            {
                                printf("Courses of your son:\n");
                                coursesn(k,1);
                                int i;
                                scanf("%d\n",&i);
                                if(i==1)
                                {
                                    courses("cse115",4,1,1,1);
                                }

                            }
                            else printf("Not done");
                        }
                        else
                        {
                            printf("Password mismatch !1.Try again\n2.Exit\n");
                            int f;
                            scanf("%d",&f);
                            if(f==1)
                            {
                                parents();
                            }
                        }
                        ;

                        ;
                    }
                    else
                    {
                        printf("Verification code mismatch !1.Try again\n2.Exit\n");
                        int f;
                        scanf("%d",&f);
                        if(f==1)
                        {
                            parents();
                        }
                    }
                }
                ;
            }
        }
    }
}

 void grade (int y,char *filename)

{

    static int f[20];
    static int q[20];
    static int m[20];
    static int bq[20];
    static int qp[20],mp[20],fpp[20],op[20];
    static  float arr[5];

    //printf("%s ",filename);
    if(f[y]!=1)
    {
        printf("Please Update Your course Outline.\n");
        printf("Quiz:\n");
        scanf("%d",&q[y]);

        printf("Best Quiz:\n");
        scanf("%d",&bq[y]);
        printf("total  Quiz marks[as percentage]:");
        scanf("%d",&qp[y]);
        printf("Mid term:\n");
        scanf("%d",&m[y]);
        printf("total  mid marks[as percentage]:");
        scanf("%d",&mp[y]);
        printf("total  final marks[as percentage]:");
        scanf("%d",&fpp[y]);
        printf("Others[as  percentage]:");
        scanf("%d",&op);

        printf("Your Course Outline has been update!\n");

        f[y]=1;

    }
    else
    {
        int x,fk;
        printf("Total quizzes  %d[%d%%]\n",q[y],qp[y]);
        printf("Total mid term %d[%d%%]\n",m[y],mp[y]);
        printf("Best quizzes:%d\n",bq[y]);
        printf("Final [%d%%]\n",fpp[y]);
        printf("Other [%d%%]\n",op[y]);
        printf("1.Update marks\n2.Exit\n");
        scanf("%d",&x);
        FILE*fp=fopen(filename,"a+");
        if(x==2)
        {
            fk=0;
        }
        else
        {
            fk=1;
            int i,j;
            float qui,mid,fin;

            float tqm,tmm,tfm;

            printf("Each quiz marks:");
            scanf("%f",&tqm);
            printf("Each mid marks:");
            scanf("%f",&tmm);
            printf("Final marks:");
            scanf("%f",&tfm);

            for (i=0; i<4 ; i++ )
            {
                printf("%s   %s\n",st[i].id,st[i].name);
                for (j=1; j<=q[y] ; j++ )
                {
                    // printf("Total marks:");
                    printf("quiz %d \n",j);
                    scanf("%f",&qui);
                    fprintf(fp,"%f ",qui);

                    arr[j-1]=qui;





                }
                float temp;
                int fn=1;
                int jj;
                while(fn)
                {
                    fn=0;

                    for (jj=0; jj<q[y] ; jj++ )
                    {
                        if(arr[jj]<arr[jj+1])
                        {

                            temp=arr[jj];
                            arr[jj]=arr[jj+1];
                            arr[jj+1]=temp;
                            fn=1;
                        }
                    }

                }

                ;
                fprintf(fp,"\n");
                for (j=1; j<=m[y] ; j++ )
                {
                    printf("mid %d \n",j);
                    scanf("%f",&mid);
                    fprintf(fp,"%.2f ",mid);

                }
                fprintf(fp,"\n");
                for (j=1; j<=f[y] ; j++ )
                {
                    printf("Final score :",j);
                    //printf("Out of:");
                    scanf("%f",&fin);
                    fprintf(fp,"%.2f\n",fin);

                }

            }
            fclose(fp);
            ;


        }
    }


}

void club()
{
    printf("hello club authority .please  sign in and  update news\n");
    printf("1.ACM STUDENTS CHAPTER\n2.IEEE\n3.NSUSSC\n4.NSU PROVLEM SOLVER\n");
    FILE*fp=fopen("club.txt","a+");
    int i=0;
    char  pass[4][20];
    for (i=0; i<4 ; i++ )
    {
        fgets(pass[i],30,fp);
        // printf("%s",pass[i]);
    }
    int  d;
    scanf("%d",&d);
    switch (d)
    {
    case 1:
        printf("Enter password:\n");
        char pas[30];
        int  i;
        fflush(stdin);
        gets(pas);
        int y=strlen(pas);
        int ff=0;
        for (i=0; i<y ; i++ )
        {
            if(pas[i]==pass[d-1][i])
            {
                ff++;
                printf("%d\n",ff);
            }
        }
        if(ff==y)
        {
            printf("1.UPDATE A NEWS\n");
            int  k;
            scanf("%d",&k);
            char news[100];
            if(k==1)
            {
                fflush(stdin);
                gets(news);
                FILE*acm=fopen("acm.txt","a+");
                fprintf(acm,"%s\n",news);
            }

        }

        else printf("password wrong!");
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;

    default:
        break;
    }



}


void  groupstudy(char file[])
{
    printf("%s",file);
}

