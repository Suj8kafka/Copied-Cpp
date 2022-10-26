#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<dos.h>
#define computer 150
#define food 100

struct teacherr
{
	int teachercode;
	char tname[35],qual[20],exp[10],taug[10],sub[25],salary1[20],con1[12],user2[12],pass2[12];
};
struct teacherr tea;

struct studentre
{
	char name[35],clas[3],dob[12],gender[10],con[12],gmail[30],user1[12],pass1[12];
	int code;
};
struct studentre str;

struct studentad
{
	char sname[35],clas1[3],fac[12],fath[35],moth[35],dob1[12],address[35],cont[12],prs[35],prp[4];
	int code;
};
struct studentad stad;

struct marksheet
{
	char name[35],sec[8];
	int opt,c,c_th,dig,dig_th,dra,dra_th,fun,fun_th,eng,eng_th,elc,elc_th,nep,nep_th,cm,sci,sci_th,web,web_th;
	int clas;
};
struct marksheet mrs;

char usernames[10];

void teacher_menu();
void student_menu();
void teacher_signin();
void student_signin();
void teacher_registration();;
void student_registration();
void teachers_workplace();
void student_workplace();
void student_admission();
void salary();
void teachers_information();
void delete_teacher();
void marksheet();
void studentbill();
void modify_teacher();
void backup();
void teachers_record();
void student_record();
void student_information();
void teacher_recovery();
void student_code();
void teacher_code();


void teacher_menu()
{
	/* Teacher Meanu */
	char temenu[1];
	system("cls");
	printf(" ******************************** TEACHER MENU ********************************");
	printf(" \n \n 1. Sign In ");
	printf(" \n 2. Teacher's Registration ");
	printf(" \n 3. Account Recovery");
	printf(" \n 4. Exit ");
	printf("\n \n Enter your choice < 1-3 > : ");
	gets(temenu);
	if(strcmp(temenu,"1")==0)
		teacher_signin();
	else if(strcmp(temenu,"2")==0)
		teacher_registration();
	else if(strcmp(temenu,"3")==0)
		teacher_recovery();
	else if(strcmp(temenu,"4")==0)
	{
		printf("\n Process is Terminated. \n Thank You!!");
		getch();
		exit(0);
	}
	else
	{
		printf("\n Wrong Input!! \n Press Enter to REDO : ");
		getch();
		teacher_menu();
	}
	return;
}


void student_menu()
{
	/* Student Menu */
	char stmenu[1];
	system("cls");
	printf(" ******************************** STUDENT MENU ********************************");
	printf(" \n \n 1. Sign In ");
	printf(" \n 2. Student's Registration ");
	printf(" \n 3. Account Recovery ");
	printf(" \n 4. Exit ");
	printf("\n \n Enter your choice < 1-3 > : ");
	gets(stmenu);
	if(strcmp(stmenu,"1")==0)
		student_signin();
	else if(strcmp(stmenu,"2")==0)
		student_registration();
	else if(strcmp(stmenu,"3")==0)
	//	student_recovery();
		exit(0);
	else if(strcmp(stmenu,"4")==0)
	{
		printf("\n Process is Terminated. \n Thank You!!");
		getch();
		exit(0);
	}
	else
	{
		printf("\n Wrong Input!! \n Press Enter to RE-DO : ");
		getch();
		student_menu();
	}
	return;
}


void teacher_signin()
{
	/* Sign in Page for Techer */
	char tuser[10],tpass[10];
	int wrong,isf=0,choice;
	FILE *teacher;
	teacher=fopen("\\TTR.txt","rb");
	system("cls");
	printf(" *************************** TEACHER SIGN IN PAGE ***************************** ");
	printf("\n \n \n 1. USERNAME : ");
	scanf("%s",&tuser);
	printf("\n 2. PASSWORD : ");
	scanf("%s",&tpass);
	while(fread(&tea,sizeof(tea),1,teacher)==1)
	{
		if(strcmp(tuser,tea.user2)==0)
		if(strcmp(tpass,tea.pass2)==0)
		{
			isf=1;
			break;
		}
	}
	if(isf==1)
	{
		printf("\n \n ## You have Succesfully SIGNINED ## \n Press Enter to Go to Teacher Workplace : ");
		getch();
		teachers_workplace();
	}
	else
	{
		printf("\n \n !!! NO MATCH FOUND !!!");
		printf("\n \n Press  1 for RE-ENTER, \n \t2 for REGISTERATION \n \t3 for Account Recovery \n \t4 for Exit : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: teacher_signin(); break;
			case 2: teacher_registration(); break;
			case 3: teacher_recovery(); break;
			case 4: printf("\n Process is Terminated. \n Thank You!!");
				getch();
				exit(0);
				break;
			default:printf("\n Wrong Input!! \n Press Enter to RE-DO : ");
				getch();
				student_menu();
		}
	}
	return;
}


void student_signin()
{
	/* Sign in Page for Student */
	char suser[10],spass[10];
	int ssl,isfo=0,choice1;
	FILE *studentr;
	studentr=fopen("\\STR.txt","rb");
	system("cls");
	printf(" ***************************** STUDENT SIGN IN PAGE ***************************** ");
	printf("\n \n 1. USERNAME : ");

	scanf("%s",&suser);
	printf("\n 2. PASSWORD : ");

	scanf("%s",&spass);
	while(fread(&str,sizeof(str),1,studentr)==1)
	{
		if(strcmp(suser,str.user1)==0)
		if(strcmp(spass,str.pass1)==0)
		{
			isfo=1;
			break;
		}
	}
	if(isfo==1)
	{
		strcpy(usernames,str.user1);
		printf("\n USERNAME : %s",usernames);
		printf("\n \n ## You have Succesfully SIGNINED ## \n Press Enter to Continue... : ");
		getch();
		select1:
		printf("\n \n \n To continue work you need to admission yourself !! \n Have you Done your Admission Press 1 for YES and 2 for No : ");
		scanf("%d",&ssl);
		switch(ssl)
		{
			case 1: printf("\n \n Press Enter to go to Student Workplace : ");
				getch();
				student_workplace();
				break;
			case 2: printf("\n \n Press Enter to go to Admission Page : ");
				getch();
				student_admission();
				break;
			default:printf("\n  Wrong Input !! \n Press Enter to RE-DO : ");
				getch();
				goto select1;
		}
	}
	else
	{
		printf("\n \n !!! NO MATCH FOUND !!!");
		printf("\n \n Press 1 to RE-ENTRY, 2 for REGISTERATION and 3 for EXIT : ");

		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1: student_signin(); break;
			case 2: student_registration(); break;
			default:printf("\n Process is Terminated. \n Thank You!!");
				getch();
				exit(0);
				break;
		}
	}
	return;
}


void student_registration()
{
	/* Student Registeration Praogram */
	char waste[2];
	int srl,last;
	system("cls");
	FILE *studentr;
	studentr=fopen("\\STR.txt","ab+");
	if(studentr==NULL)
	{
		printf("\n !!! CANN'T OPEN FILE !!!");
	}
	else
	{
		while(fread(&str,sizeof(str),1,studentr)==1)
		{
			str.code++;
		}
		printf(" ************************** STUDENT REGISTRATION ***************************");
		printf("");
		gets(waste);
		printf("\n \n \n 1. Name of the Student : ");
		gets(str.name);
		fflush(stdin);
		printf("\n 2. Class Studying IN : ");
		gets(str.clas);
		fflush(stdin);
		printf("\n 3. Date of Birth (DD/MM/YYYY) : ");
		gets(str.dob);
		fflush(stdin);
		printf("\n 4. Gender (Male,Female,Not) : ");
		gets(str.gender);
		fflush(stdin);
		printf("\n 5. Contact : ");
		gets(str.con);
		fflush(stdin);
		printf("\n 6. G-MAIL : ");
		gets(str.gmail);
		fflush(stdin);
		printf("\n 7. Username (less than 10 digits) : ");
		gets(str.user1);
		fflush(stdin);
		printf("\n 8. Password (less than 10 digits greater than 5) : ");
		gets(str.pass1);
		fflush(stdin);
	}
	reentry1:
	printf("\n \n \n Press 1 for CONFIRM REGISTRATION and 2 for RE-ENTRY and 3 for EXIT : ");

	scanf("%d",&last);
	switch(last)
	{
		case 1:{
				fwrite(&str,sizeof(str),1,studentr);
				fclose(studentr);
				printf("\n You have succesfully created your account.");
				break;
			}
		case 2: student_registration(); break;
		case 3: {
				printf("\n Process is Terminated. \n Thank You!!");
				getch();
				exit(0);
				break;
			}
		default:{
				printf("\n Wrong Input !! \n Press enter to REDO : ");
				getch();
				goto reentry1;
			}
	}
	srl:
	printf("\n Press 1 to ADMISSION and 2 for EXIT : ");

	scanf("%d",&srl);
	switch(srl)
	{
		case 1: student_admission(); break;
		case 2: {
				printf("\n The Process is Terminamated. \n Thank You !!");
				getch();
				exit(0);
				break;
			}
		default:{
				printf("\n Wrong Input !! \n Press Enter to REDO : ");
				getch();
				goto srl;
			}
	}
	return;
}


void teacher_registration()
{
	/* Teacher Registration Program */
	char waste1[2];
	int trlt,last1;
	system("cls");
	tea.teachercode=1;
	FILE *teacher;
	teacher=fopen("\\TTR.txt","ab+");
	if(teacher==NULL)
	{
		printf("\n !!! CANN'T OPEN FILE !!!");
	}
	else
	{
		while(fread(&tea,sizeof(tea),1,teacher)==1)
		{
			tea.teachercode++;
		}
		printf(" *************************** TEACHER REGISTERATION ****************************");
		printf("");
		gets(waste1);
		printf("\n \n 1. Name of the Teacher : ");
		gets(tea.tname);
		printf("\n 2. Qualification : ");
		gets(tea.qual);
		printf("\n 3. Experience : ");
		gets(tea.exp);
		printf("\n 4. Number of Year Teaching in School : ");
		gets(tea.taug);
		printf("\n 5. Teaching Subject : ");
		gets(tea.sub);
		printf("\n 6. Salary : ");
		gets(tea.salary1);
		printf("\n 7. Contact : ");
		gets(tea.con1);
		printf("\n 8. Username (less than 10 digits) : ");
		gets(tea.user2);
		printf("\n 9. Password (less than 10 digits greater than 5) : ");
		gets(tea.pass2);
	}
	select3:
	printf("\n \n \n Press 1 for CONFIRM REGISTRATION 2 for RE-ENTRY and 3 for EXIT : ");

	scanf("%d",&last1);
	switch(last1)
	{
		case 1: {
				fwrite(&tea,sizeof(tea),1,teacher);
				system("cls");
				printf("\n YOU HAVE SUCCESFULLY CREATED YOUR ACCOUNT ");
				getch();
				printf("\n \n \n !!!!!!!!!! IMPORTANT !!!!!!!!!!");
				printf("\n \n YOUR SCHOOL CODE : \" NSST%d \"",tea.teachercode);
				fclose(teacher);
				break;
			}
		case 2: teacher_registration(); break;
		case 3:	{
				printf("\n Process is Terminated. \n Thank You!!");
				getch();
				exit(0);
				break;
			}
		default:
			{
				printf("\n Wrong Input !! \n Press Enter to RE-DO : ");
				getch();
				goto select3;
			}
	}
	trl:
	printf("\n \n \n \n Press 1 to SIGNIN and Work and 2 for Exit : ");
	scanf("%d",&trlt);
	switch(trlt)
	{
		case 1: teacher_signin();
		case 2: {
				printf("\n The Process is Terminamated. \n Thank You !!");
				getch();
				exit(0);
				break;
			}
		default:
			{
				printf("\n Wrong Input !! \n Press Enter to REDO : ");
				getch();
				goto trl;
			}

	}
	return;
}


void student_admission()
{
	/* Student Admission */
	char waste2[2];
	int admission_selection;
	system("cls");
	FILE *studenta;
	studenta=fopen("\\STA.txt","ab+");
	student_code();
	printf(" *************************** STUDENT ADMISSION ****************************");
	printf("");
	gets(waste2);
	printf("\n \n \n *** YOUR SCHOOL CODE  : NHSS%d",stad.code);
	printf("\n 1. Name of Student : ");
	gets(stad.sname);
	printf("\n 2. Class : ");
	gets(stad.clas1);
	printf("\n 3. Faculty (Diploma/English/General) : ");
	gets(stad.fac);
	printf("\n 4. Father's Name : ");
	gets(stad.fath);
	printf("\n 5. Mother's Name : ");
	gets(stad.moth);
	printf("\n 6. Date of Birth (DD/MM/YYYY) : ");
	gets(stad.dob1);
	printf("\n 7. Address : ");
	gets(stad.address);
	printf("\n 8. Contact : ");
	gets(stad.cont);
	printf("\n 9. Previous School : ");
	gets(stad.prs);
	printf("\n 10. Previous Percentage : ");
	gets(stad.prp);
	redo2:
	printf("\n \n \n Press 1 for CONFIRM 2 for RE-ENTRY and 3 for EXIT : ");
	scanf("%d",&admission_selection);
	switch(admission_selection)
	{
		case 1: {
				fwrite(&stad,sizeof(stad),1,studenta);
				fclose(studenta);
				printf("\n You have succesfully created your account.");
				printf("\n ## You have Succesfully Admissioned ## \n Press Enter to go to SIGNIN Page : ");
				getch();
				student_signin();
				break;
			}
	       case 2: student_admission(); break;
	       case 3:  {
				printf("\n The Process is Terminamated. \n Thank You !!");
				getch();
				exit(0);
				break;
			}
	       default: {
				printf("\n Wrong Input !! \n Press Enter to REDO : ");
				getch();
				goto redo2;
			}
	}
	return;
}

void student_code()
{
	FILE *studentr;
	studentr=fopen("\\STR.txt","rb");
	int is3=0;
	while(fread(&str,sizeof(str),1,studentr)==1)
	{
		if(strcmp(usernames,str.user1)==0)
		{
			is3=1;
			break;
		}
	}
	if(is3==1)
	{
		stad.code=str.code;
	}
	return;
}


void teachers_workplace()
{
	/* Teacher's Workplace */
	int teacherw;
	system("cls");
	printf(" *********************** TEACHER'S WORKPLACE ***********************");
	printf("\n \n \n 1. Salary Sheet");
	printf("\n \n 2. Search Account");
	printf("\n \n 3. Delete Account");
	printf("\n \n 4. Modify Account");
	printf("\n \n 5. View Record");
	printf("\n \n 6. Go to Sign In");
	printf("\n \n 7. Code");
	printf("\n \n 8. Exit");
	printf("\n \n \n Press numbers from <1-8> to go to above options : ");

	scanf("%d",&teacherw);
	switch(teacherw)
	{
		case 1: salary(); break;
		case 2: teachers_information(); break;
		case 3: delete_teacher(); break;
		case 4: modify_teacher(); break;
		case 5: teachers_record(); break;
		case 6: teacher_signin(); break;
		case 7: teacher_code(); break;
		case 8: {
				printf("\n The Process is Terminamated. \n Thank You !!");
				getch();
				exit(0);
				break;
			}
		default:{
				printf("\n Wrong Input !! \n Press Enter to REDO : ");
				getch();
				teachers_workplace();
				break;
			}
	}
	return;
}


void student_workplace()
{
	/* Student Workplace */
	int studentw;
	system("cls");
	printf(" *********************STUDENT'S WORKPLACE *************************");
	printf("\n \n \n 1. Mark Sheet");
	printf("\n \n 2. Bill of Student");
	printf("\n \n 3. View Record");
	printf("\n \n 4. Search Account");
	printf("\n \n 5. Delete Account");
	printf("\n \n 6. Mofify Account");
	printf("\n \n 7. Go to Sign In");
	printf("\n \n 8. Exit");
	printf("\n \n \n Press numbers from <1-7> to go to above options : ");

	scanf("%d",&studentw);
	switch(studentw)
	{
		case 1: marksheet(); break;
		case 2: studentbill(); break;
		case 3: student_record(); break;
		case 4: student_information(); break;
		case 7: student_signin(); break;
		case 8: {
				printf("\n The Process is Terminamated. \n Thank You !!");
				getch();
				exit(0);
				break;
			}
		default:
			{
				printf("\n Wrong Input !! \n Press Enter to REDO : ");
				getch();
				student_workplace();
				break;
			}
	}
	return;
}


void marksheet()
{
	system("cls");
	FILE *mr;
	mr=fopen("\\MRS.txt","wb+");
	char wa[2];
	int i=1,nos,msc;
	printf(" ************************* MARKSHEET INPUTS *********************");
	printf("\n \n 1. Class : ");
	scanf("%d",&mrs.clas);
	printf("\n 2. Section : ");
	scanf("%s",&mrs.sec);
	fprintf(mr,"%d",mrs.clas);
	fprintf(mr,"\t %s",mrs.sec);
	fprintf(mr,"\n");
	printf("\n 3. Number of Students : ");
	scanf("%d",&nos);
	system("cls");
	printf("\n ### ENTER THE NAME OF THE STUDENT ###");
	printf("\n \n Roll.No    Name\n");
	while(i<=nos)
	{
		printf("\n   %d.       ",i);
		i++;
		scanf("\t %s",&mrs.name);
		fprintf(mr,"\t %s",mrs.name);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    English\n");
	printf("\n            TH  PR");
	while(i<=nos)
	{
		printf("\n   %d.       ",i);
		i++;
		scanf("%d  %d",&mrs.eng,&mrs.eng_th);
		fprintf(mr,"\t %d %d",mrs.eng,mrs.eng_th);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    Nepali\n");
	printf("\n            TH  PR");
	while(i<=nos)
	{
		printf("\n   %d.       ",i);
		i++;
		scanf("%d  %d",&mrs.nep,&mrs.nep_th);
		fprintf(mr,"\t %d %d",mrs.nep,mrs.nep_th);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    C.Maths\n");
	while(i<=nos)
	{
		printf("\n   %d.         ",i);
		i++;
		scanf("%d",&mrs.cm);
		fprintf(mr,"\t %d",mrs.cm);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    Science\n");
	printf("\n            TH   PR");
	while(i<=nos)
	{
		printf("\n   %d.       ",i);
		i++;
		scanf("%d   %d",&mrs.sci,&mrs.sci_th);
		fprintf(mr,"\t %d %d",mrs.sci,mrs.sci_th);
	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    Digital\n");
	printf("\n            TH   PR");
	while(i<=nos)
	{
		printf("\n   %d.       ",i);
		i++;
		scanf("%d   %d",&mrs.dig,&mrs.dig_th);
		fprintf(mr,"\t %d %d",mrs.dig,mrs.dig_th);
	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    Computer Fundamental\n");
	printf("\n               TH      PR");
	while(i<=nos)
	{
		printf("\n   %d.          ",i);
		i++;
		scanf("%d      %d",&mrs.fun,&mrs.fun_th);
		fprintf(mr,"\t %d %d",mrs.fun,mrs.fun_th);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    Electrical\n");
	printf("\n            TH     PR");
	while(i<=nos)
	{
		printf("\n   %d.       ",i);
		i++;
		scanf("%d    %d",&mrs.elc,&mrs.elc_th);
		fprintf(mr,"\t %d %d",mrs.elc,mrs.elc_th);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    OPT. Maths\n");
	while(i<=nos)
	{
		printf("\n   %d.           ",i);
		i++;
		scanf("%d",&mrs.opt);
		fprintf(mr,"\t %d",mrs.opt);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    Web Programming\n");
	printf("\n               TH    PR");
	while(i<=nos)
	{
		printf("\n   %d.          ",i);
		i++;
		scanf("%d %d",&mrs.web,&mrs.web_th);
		fprintf(mr,"\t %d %d",mrs.web,mrs.web_th);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    C Programming\n");
	printf("\n             TH       PR");
	while(i<=nos)
	{
		printf("\n   %d.        ",i);
		i++;
		scanf("%d      %d",&mrs.c,&mrs.c_th);
		fprintf(mr,"\t %d %d",mrs.c,mrs.c_th);

	}
	i=1;
	system("cls");
	fprintf(mr,"\n");
	printf("\n ### ENTER THE MARKS OF STUDENTS ###");
	printf("\n \n Roll.No    Drawing\n");
	printf("\n            TH   PR");
	while(i<=nos)
	{
		printf("\n   %d.       ",i);
		i++;
		scanf("%d   %d",&mrs.dra,&mrs.dra_th);
		fprintf(mr,"\t %d %d",mrs.dra,mrs.dra_th);

	}

	/*PRINTING*/
	FILE *mp;
	mp=fopen("\\MARKS.docx","wb+");
	fprintf(mp,"\n \n");
	fprintf(mp,"\t \t \t Shree Nrishing Secondary School\n");
	fprintf(mp,"\n \t \t  Birgunj-14, Pipramath, Ph.No-9801800559\n");
	fprintf(mp,"\n \t \t \t First Terminal Exam 2076\n");
	fprintf(mp,"\n \t \t \t \t Grade-Sheet\n");
	fprintf(mp,"\n \nTHE GRADE IS SECURED BY...%s...OF CLASS...%d%s...ROLL... ...ARE GIVEN BELOW:\n\n\n",mrs.name,mrs.clas,mrs.sec);
	fprintf(mp,"\nSN.NO   SUBJECT \t \t   TH  PR    TOTAL  GRADE POINTS");
	fprintf(mp,"\n \n1.      English \t \t   ");



	/* SCANING */
	float en,eth,n,nth,sth,s,dth,dpr,fth,ft,elth,el,wth,w,cth,cp,drth,dp,c,o;
	float to,to2,to3,to4,to5,to6,to7,to8,to9,total;
//	date da;
	fread(&mrs,sizeof(mrs),1,mr);

	if(mrs.eng<=100 && mrs.eng>=90)
	{
		en=4.0;
		fprintf(mp,"A+");
	}
	else if(mrs.eng<90 && mrs.eng>=80)
	{
		en=3.6;
		fprintf(mp,"A");
	}
	else if(mrs.eng<80 && mrs.eng>=70)
	{
		en=3.2;
		fprintf(mp,"B+");
	}
	else if(mrs.eng<70 && mrs.eng>=60)
	{
		en=2.8;
		fprintf(mp,"B");
	}
	else if(mrs.eng<60 && mrs.eng>=50)
	{
		en=2.4;
		fprintf(mp,"C+");
	}
	else if(mrs.eng<50 && mrs.eng>=40)
	{
		en=2.0;
		fprintf(mp,"C");
	}
	else if(mrs.eng<40 && mrs.eng>=30)
	{
		en=1.6;
		fprintf(mp,"D+");
	}
	else if(mrs.eng<30 && mrs.eng>=20)
	{
		en=1.2;
		fprintf(mp,"D");
	}
	else
	{
		en=0.8;
		fprintf(mp,"E");
	}

	if(mrs.eng_th<=100 && mrs.eng_th>=90)
	{
		eth=4.0;
		fprintf(mp,"  A+");
	}
	else if(mrs.eng_th<90 && mrs.eng_th>=80)
	{
		eth=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.eng_th<80 && mrs.eng_th>=70)
	{
		eth=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.eng_th<70 && mrs.eng_th>=60)
	{
		eth=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.eng_th<60 && mrs.eng_th>=50)
	{
		eth=2.4;
		fprintf(mp,"  C+");
	}
	else if(mrs.eng_th<50 && mrs.eng_th>=40)
	{
		eth=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.eng_th<40 && mrs.eng_th>=30)
	{
		eth=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.eng_th<30 && mrs.eng_th>=20)
	{
		eth=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		eth=0.8;
		fprintf(mp,"   E");
	}

	to=(eth+en)/2;
	if(to<=4.0 && to>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to<=3.6 && to>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to<=3.2 && to>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to<=2.8 && to>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to<=2.4 && to>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to<=2.0 && to>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to<=1.6 && to>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to<=1.2 && to>0.8)
		fprintf(mp,"\t    D \t   1.2");
	else
		fprintf(mp,"\t    E \t   0.8");

	fprintf(mp,"\n \n2.      Nepali \t \t \t   ");

	if(mrs.nep<=100 && mrs.nep>=90)
	{
		n=4.0;
		fprintf(mp,"A+");
	}
	else if(mrs.nep<90 && mrs.nep>=80)
	{
		n=3.6;
		fprintf(mp,"A");
	}
	else if(mrs.nep<80 && mrs.nep>=70)
	{
		n=3.2;
		fprintf(mp,"B+");
	}
	else if(mrs.nep<70 && mrs.nep>=60)
	{
		n=2.8;
		fprintf(mp,"B");
	}
	else if(mrs.nep<60 && mrs.nep>=50)
	{
		n=2.4;
		fprintf(mp,"C+");
	}
	else if(mrs.nep<50 && mrs.nep>=40)
	{
		n=2.0;
		fprintf(mp,"C");
	}
	else if(mrs.nep<40 && mrs.nep>=30)
	{
		n=1.6;
		fprintf(mp,"D+");
	}
	else if(mrs.nep<30 && mrs.nep>=20)
	{
		n=1.2;
		fprintf(mp,"D");
	}
	else
	{
		n=0.8;
		fprintf(mp,"E");
	}

	if(mrs.nep_th<=100 && mrs.nep_th>=90)
	{
		nth=4.0;
		fprintf(mp,"  A+");
	}
	else if(mrs.nep_th<90 && mrs.nep_th>=80)
	{
		nth=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.nep_th<80 && mrs.nep_th>=70)
	{
		nth=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.nep_th<70 && mrs.nep_th>=60)
	{
		nth=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.nep_th<60 && mrs.nep_th>=50)
	{
		nth=2.4;
		fprintf(mp,"  C+");
	}
	else if(mrs.nep_th<50 && mrs.nep_th>=40)
	{
		nth=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.nep_th<40 && mrs.nep_th>=30)
	{
		nth=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.nep_th<30 && mrs.nep_th>=20)
	{
		nth=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		nth=0.8;
		fprintf(mp,"   E");
	}

	to2=(nth+n)/2;
	if(to2<=4.0 && to2>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to2<=3.6 && to2>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to2<=3.2 && to2>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to2<=2.8 && to2>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to2<=2.4 && to2>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to2<=2.0 && to2>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to2<=1.6 && to2>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to2<=1.2 && to2>0.8)
		fprintf(mp,"\t    D \t  1.2");
	else
		fprintf(mp,"\t    E \t   0.8");

	fprintf(mp,"\n \n3.      C.Maths \t \t   ");
	if(mrs.cm<=100 && mrs.cm>=90)
	{
		fprintf(mp,"A+ \t \t   A+  \t   4.0");
		c=4.0;
	}
	else if(mrs.cm<90 && mrs.cm>=80)
	{
		fprintf(mp,"A \t \t   A \t    3.6");
		c=3.6;
	}
	else if(mrs.cm<80 && mrs.cm>=70)
	{
		fprintf(mp,"B+ \t \t   B+ \t    3.2");
		c=3.2;
	}
	else if(mrs.cm<70 && mrs.cm>=60)
	{
		fprintf(mp,"B \t \t   B \t   2.8");
		c=2.8;
	}
	else if(mrs.cm<60 && mrs.cm>=50)
	{
		fprintf(mp,"C+ \t \t    C+ \t    2.4");
		c=2.4;
	}
	else if(mrs.cm<50 && mrs.cm>=40)
	{
		fprintf(mp,"C \t \t    C \t    2.0");
		c=2.0;
	}
	else if(mrs.cm<40 && mrs.cm>=30)
	{
		fprintf(mp,"D+ \t \t    D+ \t    1.6");
		c=1.6;
	}
	else if(mrs.cm<30 && mrs.cm>=20)
	{
		fprintf(mp,"D \t \t    D \t   1.2");
		c=1.2;
	}
	else
	{
		fprintf(mp,"E \t \t    E \t  0.8");
		c=0.8;
	}

	fprintf(mp,"\n \n4.      Science \t \t  ");
	if(mrs.sci<=100 && mrs.sci>=90)
	{
		s=4.0;
		fprintf(mp," A+");
	}
	else if(mrs.sci<90 && mrs.sci>=80)
	{
		s=3.6;
		fprintf(mp," A");
	}
	else if(mrs.sci<80 && mrs.sci>=70)
	{
		s=3.2;
		fprintf(mp," B+");
	}
	else if(mrs.sci<70 && mrs.sci>=60)
	{
		s=2.8;
		fprintf(mp," B");
	}
	else if(mrs.sci<60 && mrs.sci>=50)
	{
		s=2.4;
		fprintf(mp," C+");
	}
	else if(mrs.sci<50 && mrs.sci>=40)
	{
		s=2.0;
		fprintf(mp," C");
	}
	else if(mrs.sci<40 && mrs.sci>=30)
	{
		s=1.6;
		fprintf(mp," D+");
	}
	else if(mrs.sci<30 && mrs.sci>=20)
	{
		s=1.2;
		fprintf(mp," D");
	}
	else
	{
		s=0.8;
		fprintf(mp," E");
	}

	if(mrs.sci_th<=100 && mrs.sci_th>=90)
	{
		sth=4.0;
		fprintf(mp,"  A+");
	}
	else if(mrs.sci_th<90 && mrs.sci_th>=80)
	{
		sth=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.sci_th<80 && mrs.sci_th>=70)
	{
		sth=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.sci_th<70 && mrs.sci_th>=60)
	{
		sth=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.sci_th<60 && mrs.sci_th>=50)
	{
		sth=2.4;
		fprintf(mp,"   C+");
	}
	else if(mrs.sci_th<50 && mrs.sci_th>=40)
	{
		sth=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.sci_th<40 && mrs.sci_th>=30)
	{
		sth=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.sci_th<30 && mrs.sci_th>=20)
	{
		sth=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		sth=0.8;
		fprintf(mp,"   E");
	}

	to3=(sth+s)/2;
	if(to3<=4.0 && to3>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to3<=3.6 && to3>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to3<=3.2 && to3>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to3<=2.8 && to3>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to3<=2.4 && to3>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to3<=2.0 && to3>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to3<=1.6 && to3>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to3<=1.2 && to3>0.8)
		fprintf(mp,"\t    D \t   1.2");
	else
		fprintf(mp,"\t    E \t   0.8");

	fprintf(mp,"\n \n5.      Digital \t \t  ");

	if(mrs.dig<=100 && mrs.dig>=90)
	{
		dth=4.0;
		fprintf(mp," A+");
	}
	else if(mrs.dig<90 && mrs.dig>=80)
	{
		dth=3.6;
		fprintf(mp," A");
	}
	else if(mrs.dig<80 && mrs.dig>=70)
	{
		dth=3.2;
		fprintf(mp," B+");
	}
	else if(mrs.dig<70 && mrs.dig>=60)
	{
		dth=2.8;
		fprintf(mp," B");
	}
	else if(mrs.dig<60 && mrs.dig>=50)
	{
		dth=2.4;
		fprintf(mp," C+");
	}
	else if(mrs.dig<50 && mrs.dig>=40)
	{
		dth=2.0;
		fprintf(mp," C");
	}
	else if(mrs.dig<40 && mrs.dig>=30)
	{
		dth=1.6;
		fprintf(mp," D+");
	}
	else if(mrs.dig<30 && mrs.dig>=20)
	{
		dth=1.2;
		fprintf(mp," D");
	}
	else
	{
		dth=0.8;
		fprintf(mp," E");
	}

	if(mrs.dig_th<=100 && mrs.dig_th>=90)
	{
		dpr=4.0;
		fprintf(mp,"  A+");
	}
	else if(mrs.dig_th<90 && mrs.dig_th>=80)
	{
		dpr=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.dig_th<80 && mrs.dig_th>=70)
	{
		dpr=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.dig_th<70 && mrs.dig_th>=60)
	{
		dpr=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.dig_th<60 && mrs.dig_th>=50)
	{
		dpr=2.4;
		fprintf(mp,"  C+");
	}
	else if(mrs.dig_th<50 && mrs.dig_th>=40)
	{
		dpr=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.dig_th<40 && mrs.dig_th>=30)
	{
		dpr=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.dig_th<30 && mrs.dig_th>=20)
	{
		dpr=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		dpr=0.8;
		fprintf(mp,"   E");
	}

	to4=(dth+dpr)/2;
	if(to4<=4.0 && to4>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to4<=3.6 && to4>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to4<=3.2 && to4>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to4<=2.8 && to4>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to4<=2.4 && to4>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to4<=2.0 && to4>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to4<=1.6 && to4>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to4<=1.2 && to4>0.8)
		fprintf(mp,"\t    D \t  1.2");
	else
		fprintf(mp,"\t    E \t   0.8");

	fprintf(mp,"\n \n6.      Computer Fundamental  ");
	if(mrs.fun<=100 && mrs.fun>=90)
	{
		ft=4.0;
		fprintf(mp,"A+");
	}
	else if(mrs.fun<90 && mrs.fun>=80)
	{
		ft=3.6;
		fprintf(mp,"A");
	}
	else if(mrs.fun<80 && mrs.fun>=70)
	{
		ft=3.2;
		fprintf(mp,"B+");
	}
	else if(mrs.fun<70 && mrs.fun>=60)
	{
		ft=2.8;
		fprintf(mp,"B");
	}
	else if(mrs.fun<60 && mrs.fun>=50)
	{
		ft=2.4;
		fprintf(mp,"C+");
	}
	else if(mrs.fun<50 && mrs.fun>=40)
	{
		ft=2.0;
		fprintf(mp,"C");
	}
	else if(mrs.fun<40 && mrs.fun>=30)
	{
		ft=1.6;
		fprintf(mp,"D+");
	}
	else if(mrs.fun<30 && mrs.fun>=20)
	{
		ft=1.2;
		fprintf(mp,"D");
	}
	else
	{
		ft=0.8;
		fprintf(mp,"E");
	}

	if(mrs.fun_th<=100 && mrs.fun_th>=90)
	{
		fth=4.0;
		fprintf(mp,"  A+");
	}
	else if(mrs.fun_th<90 && mrs.fun_th>=80)
	{
		fth=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.fun_th<80 && mrs.fun_th>=70)
	{
		fth=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.fun_th<70 && mrs.fun_th>=60)
	{
		fth=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.fun_th<60 && mrs.fun_th>=50)
	{
		fth=2.4;
		fprintf(mp,"  C+");
	}
	else if(mrs.fun_th<50 && mrs.fun_th>=40)
	{
		fth=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.fun_th<40 && mrs.fun_th>=30)
	{
		fth=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.fun_th<30 && mrs.fun_th>=20)
	{
		fth=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		fth=0.8;
		fprintf(mp,"   E");
	}

	to5=(ft+fth)/2;
	if(to5<=4.0 && to5>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to5<=3.6 && to5>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to5<=3.2 && to5>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to5<=2.8 && to5>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to5<=2.4 && to5>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to5<=2.0 && to5>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to5<=1.6 && to5>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to5<=1.2 && to5>0.8)
		fprintf(mp,"\t    D \t   1.2");
	else
		fprintf(mp,"\t    E \t   0.8");

	fprintf(mp,"\n \n7.      Electrical \t \t   ");

	if(mrs.elc<=100 && mrs.elc>=90)
	{
		el=4.0;
		fprintf(mp,"A+");
	}
	else if(mrs.elc<90 && mrs.elc>=80)
	{
		el=3.6;
		fprintf(mp,"A");
	}
	else if(mrs.elc<80 && mrs.elc>=70)
	{
		el=3.2;
		fprintf(mp,"B+");
	}
	else if(mrs.elc<70 && mrs.elc>=60)
	{
		el=2.8;
		fprintf(mp,"B");
	}
	else if(mrs.elc<60 && mrs.elc>=50)
	{
		el=2.4;
		fprintf(mp,"C+");
	}
	else if(mrs.elc<50 && mrs.elc>=40)
	{
		el=2.0;
		fprintf(mp,"C");
	}
	else if(mrs.elc<40 && mrs.elc>=30)
	{
		el=1.6;
		fprintf(mp,"D+");
	}
	else if(mrs.elc<30 && mrs.elc>=20)
	{
		el=1.2;
		fprintf(mp,"D");
	}
	else
	{
		el=0.8;
		fprintf(mp,"E");
	}

	if(mrs.elc_th<=100 && mrs.elc_th>=90)
	{
		elth=4.0;
		fprintf(mp,"  A+");
	}
	else if(mrs.elc_th<90 && mrs.elc_th>=80)
	{
		elth=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.elc_th<80 && mrs.elc_th>=70)
	{
		elth=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.elc_th<70 && mrs.elc_th>=60)
	{
		elth=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.elc_th<60 && mrs.elc_th>=50)
	{
		elth=2.4;
		fprintf(mp,"   C+");
	}
	else if(mrs.elc_th<50 && mrs.elc_th>=40)
	{
		elth=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.elc_th<40 && mrs.elc_th>=30)
	{
		elth=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.elc_th<30 && mrs.elc_th>=20)
	{
		elth=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		elth=0.8;
		fprintf(mp,"   E");
	}

	to6=(elth+el)/2;
	if(to6<=4.0 && to6>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to6<=3.6 && to6>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to6<=3.2 && to6>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to6<=2.8 && to6>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to6<=2.4 && to6>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to6<=2.0 && to6>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to6<=1.6 && to6>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to6<=1.2 && to6>0.8)
		fprintf(mp,"\t    D \t   1.2");
	else
		fprintf(mp,"\t    E \t   0.8");


	fprintf(mp,"\n \n8.      Opt.Maths \t \t   ");

	if(mrs.opt<=100 && mrs.opt>=90)
	{
		fprintf(mp,"A+ \t \t    A+ \t   4.0");
		o=4.0;
	}
	else if(mrs.opt<90 && mrs.opt>=80)
	{
		fprintf(mp,"A \t \t    A \t   3.6");
		o=3.6;
	}
	else if(mrs.opt<80 && mrs.opt>=70)
	{
		fprintf(mp,"B+ \t \t    B+ \t   3.2");
		o=3.2;
	}
	else if(mrs.opt<70 && mrs.opt>=60)
	{
		fprintf(mp,"B \t \t    B \t   2.8");
		o=2.8;
	}
	else if(mrs.opt<60 && mrs.opt>=50)
	{
		fprintf(mp,"C+ \t \t    C+ \t   2.4");
		o=2.4;
	}
	else if(mrs.opt<50 && mrs.opt>=40)
	{
		fprintf(mp,"C \t \t    C \t   2.0");
		o=2.0;
	}
	else if(mrs.opt<40 && mrs.opt>=30)
	{
		fprintf(mp,"D+ \t \t    D+ \t   1.6");
		o=1.6;
	}
	else if(mrs.opt<30 && mrs.opt>=20)
	{
		fprintf(mp,"D \t \t    D \t   1.2");
		o=1.2;
	}
	else
	{
		fprintf(mp,"E \t \t    E \t  0.8");
		o=0.8;

	}

	fprintf(mp,"\n \n9.      Web Programming \t   ");

	if(mrs.web<=100 && mrs.web>=90)
	{
		w=4.0;
		fprintf(mp,"A+");
	}
	else if(mrs.web<90 && mrs.web>=80)
	{
		w=3.6;
		fprintf(mp,"A");
	}
	else if(mrs.web<80 && mrs.web>=70)
	{
		w=3.2;
		fprintf(mp,"B+");
	}
	else if(mrs.web<70 && mrs.web>=60)
	{
		w=2.8;
		fprintf(mp,"B");
	}
	else if(mrs.web<60 && mrs.web>=50)
	{
		w=2.4;
		fprintf(mp,"C+");
	}
	else if(mrs.web<50 && mrs.web>=40)
	{
		w=2.0;
		fprintf(mp,"C");
	}
	else if(mrs.web<40 && mrs.web>=30)
	{
		w=1.6;
		fprintf(mp,"D+");
	}
	else if(mrs.web<30 && mrs.web>=20)
	{
		w=1.2;
		fprintf(mp,"D");
	}
	else
	{
		w=0.8;
		fprintf(mp,"E");
	}

	if(mrs.web_th<=100 && mrs.web_th>=90)
	{
		wth=4.0;
		fprintf(mp,"  A+");
	}
	else if(mrs.web_th<90 && mrs.web_th>=80)
	{
		wth=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.web_th<80 && mrs.web_th>=70)
	{
		wth=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.web_th<70 && mrs.web_th>=60)
	{
		wth=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.web_th<60 && mrs.web_th>=50)
	{
		wth=2.4;
		fprintf(mp,"  C+");
	}
	else if(mrs.web_th<50 && mrs.web_th>=40)
	{
		wth=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.web_th<40 && mrs.web_th>=30)
	{
		wth=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.web_th<30 && mrs.web_th>=20)
	{
		wth=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		wth=0.8;
		fprintf(mp,"   E");
	}

	to7=(wth+w)/2;
	if(to7<=4.0 && to7>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to7<=3.6 && to7>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to7<=3.2 && to7>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to7<=2.8 && to7>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to7<=2.4 && to7>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to7<=2.0 && to7>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to7<=1.6 && to7>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to7<=1.2 && to7>0.8)
		fprintf(mp,"\t    D \t   1.2");
	else
		fprintf(mp,"\t    E \t   0.8");


	fprintf(mp,"\n \n10.     'C' Programing \t   ");

	if(mrs.c<=100 && mrs.c>=90)
	{
		cp=4.0;
		fprintf(mp,"A+");
	}
	else if(mrs.c<90 && mrs.c>=80)
	{
		cp=3.6;
		fprintf(mp,"A");
	}
	else if(mrs.c<80 && mrs.c>=70)
	{
		cp=3.2;
		fprintf(mp,"B+");
	}
	else if(mrs.c<70 && mrs.c>=60)
	{
		cp=2.8;
		fprintf(mp,"B");
	}
	else if(mrs.c<60 && mrs.c>=50)
	{
		cp=2.4;
		fprintf(mp,"C+");
	}
	else if(mrs.c<50 && mrs.c>=40)
	{
		cp=2.0;
		fprintf(mp,"C");
	}
	else if(mrs.c<40 && mrs.c>=30)
	{
		cp=1.6;
		fprintf(mp,"D+");
	}
	else if(mrs.c<30 && mrs.c>=20)
	{
		cp=1.2;
		fprintf(mp,"D");
	}
	else
	{
		cp=0.8;
		fprintf(mp,"E");
	}

	if(mrs.c_th<=100 && mrs.c_th>=90)
	{
		cth=4.0;
		fprintf(mp,"  A+");
	}
	else if(mrs.c_th<90 && mrs.c_th>=80)
	{
		cth=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.c_th<80 && mrs.c_th>=70)
	{
		cth=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.c_th<70 && mrs.c_th>=60)
	{
		cth=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.c_th<60 && mrs.c_th>=50)
	{
		cth=2.4;
		fprintf(mp,"  C+");
	}
	else if(mrs.c_th<50 && mrs.c_th>=40)
	{
		cth=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.c_th<40 && mrs.c_th>=30)
	{
		cth=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.c_th<30 && mrs.c_th>=20)
	{
		cth=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		cth=0.8;
		fprintf(mp,"   E");
	}

	to8=(cp+cth)/2;
	if(to8<=4.0 && to8>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to8<=3.6 && to8>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to8<=3.2 && to8>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to8<=2.8 && to8>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to8<=2.4 && to8>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to8<=2.0 && to8>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to8<=1.6 && to8>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to8<=1.2 && to8>0.8)
		fprintf(mp,"\t    D \t   1.2");
	else
		fprintf(mp,"\t    E \t   0.8");


	fprintf(mp,"\n \n11.     Drawing \t \t   ");

	if(mrs.dra<=100 && mrs.dra>=90)
	{
		dp=4.0;
		fprintf(mp,"A+");
	}
	else if(mrs.dra<90 && mrs.dra>=80)
	{
		dp=3.6;
		fprintf(mp,"A");
	}
	else if(mrs.dra<80 && mrs.dra>=70)
	{
		dp=3.2;
		fprintf(mp,"B+");
	}
	else if(mrs.dra<70 && mrs.dra>=60)
	{
		dp=2.8;
		fprintf(mp,"B");
	}
	else if(mrs.dra<60 && mrs.dra>=50)
	{
		dp=2.4;
		fprintf(mp,"C+");
	}
	else if(mrs.dra<50 && mrs.dra>=40)
	{
		dp=2.0;
		fprintf(mp,"C");
	}
	else if(mrs.dra<40 && mrs.dra>=30)
	{
		dp=1.6;
		fprintf(mp,"D+");
	}
	else if(mrs.dra<30 && mrs.dra>=20)
	{
		dp=1.2;
		fprintf(mp,"D");
	}
	else
	{
		dp=0.8;
		fprintf(mp,"E");
	}

	if(mrs.dra_th<=100 && mrs.dra_th>=90)
	{
		drth=4.0;
		fprintf(mp,"   A+");
	}
	else if(mrs.dra_th<90 && mrs.dra_th>=80)
	{
		drth=3.6;
		fprintf(mp,"   A");
	}
	else if(mrs.dra_th<80 && mrs.dra_th>=70)
	{
		drth=3.2;
		fprintf(mp,"  B+");
	}
	else if(mrs.dra_th<70 && mrs.dra_th>=60)
	{
		drth=2.8;
		fprintf(mp,"   B");
	}
	else if(mrs.dra_th<60 && mrs.dra_th>=50)
	{
		drth=2.4;
		fprintf(mp,"  C+");
	}
	else if(mrs.dra_th<50 && mrs.dra_th>=40)
	{
		drth=2.0;
		fprintf(mp,"   C");
	}
	else if(mrs.dra_th<40 && mrs.dra_th>=30)
	{
		drth=1.6;
		fprintf(mp,"  D+");
	}
	else if(mrs.dra_th<30 && mrs.dra_th>=20)
	{
		drth=1.2;
		fprintf(mp,"   D");
	}
	else
	{
		drth=0.8;
		fprintf(mp,"   E");
	}

	to9=(dp+drth)/2;
	if(to9<=4.0 && to9>3.6)
		fprintf(mp,"\t    A+ \t   4.0");
	else if(to9<=3.6 && to9>3.2)
		fprintf(mp,"\t    A \t   3.6");
	else if(to9<=3.2 && to9>2.8)
		fprintf(mp,"\t    B+ \t   3.2");
	else if(to9<=2.8 && to9>2.4)
		fprintf(mp,"\t    B \t   2.8");
	else if(to9<=2.4 && to9>2.0)
		fprintf(mp,"\t    C+ \t   2.4");
	else if(to9<=2.0 && to9>1.6)
		fprintf(mp,"\t    C \t   2.0");
	else if(to9<=1.6 && to9>1.2)
		fprintf(mp,"\t    D+ \t   1.6");
	else if(to9<=1.2 && to9>0.8)
		fprintf(mp,"\t    D \t   1.2");
	else
		fprintf(mp,"\t    E \t   0.8");

	total=(to+to2+to3+to4+to5+to6+to7+to8+to9+c+o)/11;
	fprintf(mp,"\n \n \t \t \t \t \t \t Grade Points Average : %1.2f",total);

	if(total<=4.0 && total>3.6)
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : A+");
	else if(total<=3.6 && total>3.2)
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : A");
	else if(total<=3.2 && total>2.8)
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : B+");
	else if(total<=2.8 && total>2.4)
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : B");
	else if(total<=2.4 && total>2.0)
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : C+");
	else if(total<=2.0 && total>1.6)
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : C");
	else if(total<=1.6 && total>1.2)
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : D+");
	else if(total<=1.2 && total>0.8)
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : D");
	else
		fprintf(mp,"\n \t \t \t \t \t \t Average Grade : E");

//	getdate(&da);
//	fprintf(mp,"\n \t \t \t \t \t \t Date of Issue : %d-%d-%d",da.da_year,da.da_mon,da.da_day);

	fprintf(mp,"\n \n \n ---------- \t \t \t ------------- \t \t \t ---------");
	fprintf(mp,"\n Checked By \t \t \t Class Teacher \t \t \t Principle");

	printf("\n \n ### You have Succesfully creates All the marksheet ###");
	printf("\n \n Press 1 to go to Student's Workplace and 2 for Exit : ");
	scanf("%d",&msc);
	if(msc==1)
		student_workplace();
	else
	{
		printf("\n The Process is Terminamated. \n Thank You !!");
		getch();
		exit(0);
	}
	getch();
	return ;
}


void studentbill()
{
	/* Student Bill */
	char bsname[30],sec[9],waste4[10],mon[12];
	int bsclas,bsroll,exit3;
	long mf,bm,tax1,total1,t1,left;
//	date d;
	system("cls");
	printf("***************************** BILL INPUTS *****************************");
	printf("");
	gets(waste4);
	printf("\n \n A. Name of Student : ");
	gets(bsname);
	printf("\n B. Class : ");
	scanf("%d",&bsclas);
	printf("");
	gets(waste4);
	printf("\n C. Section : ");
	gets(sec);
	printf("\n D. Roll : ");
	scanf("%d",&bsroll);
	printf("");
	gets(waste4);
	printf("\n E. Bill of the Month : ");
	gets(mon);
	printf("\n F. Monthly Fee : ");
	scanf("%ld",&mf);
	printf("\n G. Left Month Fee: ");
	scanf("%ld",&bm);
	tax1=mf*0.01;
	t1=mf+tax1+computer;
	total1=t1*bm;
	left=total1-t1;
	system("cls");
	printf("\t \t \t Narshing Secondary School");
	printf("\n \t \t \t   Piramath - 14,Birgunj");
	printf("\n \t\t Model School Techincal & Vocational Education");
	printf("\n \t \t \t \t Bill of Student");
	printf("\n \n 1. Name of Student : ");
	puts(bsname);
	printf(" 2. Class : %d",bsclas);
	printf("\n 3. Section : %s",sec);
	printf("\n 4. Roll : %d",bsroll);
//	getdate(&d);
//	printf("\n \n ^^ Bill For the Month : %s \t Date : %d/%d/%d ^^",mon,d.da_year,d.da_mon,d.da_day);
	printf("\n \n \n A. Monthly Fee  :  %ld",mf);
	printf("\n B. Tax          :  %ld",tax1);
	printf("\n C. Computer Fee :  %d",computer);
	printf("\n D. This Month   :  %ld",t1);
	printf("\n E. Previous Due :  %ld",left);
	printf("\n \n    TOTAL        :  %ld",total1);
	printf("\n \n Press 1 to go to Student's Workplace and 2 for Exit : ");
	scanf("%d",&exit3);
	if(exit3==2)
	{
		printf("\n The Process is Terminamated. \n Thank You !!");
		getch();
		exit(0);
	}
	else
		student_workplace();
	return;
}



void salary()
{
	/* SALARY */
	double salary,pf,tax,advance,bt,total,bonous,de;
	int service,exit2;
	system("cls");
	printf("************************* SALARY INPUTS *******************************");
	printf("\n \n FILL THE DETAILS");
	printf("");
	gets(tea.tname);
	printf("\n \n Name of Teacher : ");
	gets(tea.tname);
	printf("\n Qualification : ");
	gets(tea.qual);
	printf("\n Subject : ");
	gets(tea.sub);
	printf("\n 4. Salary : ");
	scanf("%lf",&salary);
	printf("\n 5. Service Year : ");
	scanf("%d",&service);
	printf("\n 6. Advance : ");
	scanf("%lf",&advance);
	printf("\n 7. Bonous : ");
	scanf("%lf",&bonous);
	if(service>=1)
		pf=salary*0.1;
	else
		pf=0;
	if(salary>0 && salary<=1000)
		tax=0.01*salary;
	else if(salary>=1001 && salary<=10000)
		tax=0.05*salary;
	else if(salary>=10001 && salary<=50000)
		tax=0.15*salary;
	else if(salary>=50001 && salary<=100000)
		tax=0.25*salary;
	else
	{
		tax=0.20*salary;
	}
	bt=(bonous/100)*salary;
	total=(salary+bonous+food)-(tax+pf+advance);
	de=total/30;
	system("cls");
	printf("\t \t \t Narshing Secondary School");
	printf("\n \t \t \t   Piramath - 14,Birgunj");
	printf("\n \t\tModel School Techincal & Vocational Education");
	printf("\n \t \t \t Salary Sheet for Teachers");
	printf("\n \n \n I. Name of Teacher : %s",tea.tname);
	printf("\n II. Qualification : %s",tea.qual);
	printf("\n III. Subject : %s",tea.sub);
	printf("\n \n Fields of CALCULATION");
	printf("\n \n 1. Salary :   %.2lf",salary);
	printf("\n 2. Bonous :   %.2lf",bt);
	printf("\n 3. PF :       %.2lf",pf);
	printf("\n 4. Tax :      %.2lf",tax);
	printf("\n 5. Advance :  %.2lf",advance);
	printf("\n \n   Total :    %.2lf",total);
	printf("\n \n   ** Daily Earning : %.2lf **",de);
	printf("\n \n Press 1 to go to Teacher's Workplace and 2 for Exit : ");
	scanf("%d",&exit2);
	if(exit2==2)
	{
		printf("\n The Process is Terminamated. \n Thank You !!");
		getch();
		exit(0);
	}
	else
		teachers_workplace();
	return;
}


void teachers_information()
{
	/* Teacher Information Search */
	char ctname[40],waste[2];
	system("cls");
	int is=0,last3;
	FILE *teacher;
	teacher=fopen("\\TTR.txt","rb");
	printf("************************ TEACHER SEARCH INPUTS ***********************");
	printf("\n \n ### Enter the Teachers Name ###");
	gets(waste);
	printf("\n \n Name of Teacher : ");
	gets(ctname);
	while(fread(&tea,sizeof(tea),1,teacher)==1)
	{
		if(strcmp(ctname,tea.tname)==0)
		{
			is=1;
			break;
		}
	}
	if(is==1)
	{
		printf("\n \n \n !!! MATCH FOUND !!!");
		printf("\n \n INFORMATION");
		printf("\n \n 1. Name of Teacher : %s ",tea.tname);
		printf("\n 2. Qualification : %s",tea.qual);
		printf("\n 3. Number of Years Teaching in School : %s ",tea.exp);
		printf("\n 4. Teaching Subject : %s ",tea.taug);
		printf("\n 5. Salary : %s ",tea.sub);
		printf("\n 6. Salary : %s ",tea.salary1);
		printf("\n 7. Contact : %s ",tea.con1);
		printf("\n 8. Username : %s",tea.user2);
		fclose(teacher);
		printf("\n \n Press 1 to go to TEACHER WORKPLACE and 2 for EXIT : ");
		scanf("%d",&last3);
		if(last3==1)
			teachers_workplace();
		else
		{
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}
	else
	{
		printf("\n !!! No Result Found !!!");
		printf("\n \n Press 1 to RE-ENTER 2 for TEACHER WORKPLACE and 3 for EXIT : ");
		scanf("%d",&last3);
		if(last3==1)
			teachers_information();
		else if(last3==2)
			teachers_workplace();
		else
		{
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}
	return;
}


void delete_teacher()
{
	/* Teacher Delete Account */
	char dtname[35],waste[2];
	int is1=1,last4;
	system("cls");
	FILE *teacher;
	FILE *temp;
	teacher=fopen("\\TTR.txt","rb");
	temp=fopen("\\TEM.txt","wb");
	printf("************************ TEACHER DELETE ACCOUNT INPUTS ***********************");
	printf("\n \n ### Enter the Teachers Name ###");
	gets(waste);
	printf("\n \n Name of Teacher : ");
	gets(dtname);
	while(fread(&tea,sizeof(tea),1,teacher)==1)
	{
		if(strcmp(dtname,tea.tname)==0)
		{
			is1=0;
			continue;
		}
		else
		{
			fwrite(&tea,sizeof(tea),1,temp);
		}
	}
	if(is1==1)
	{
		printf("\n \n RECORD NOT FOUND");
		printf("\n Press 1 to RE-DO, 2 for TEACHER WORKPLACE and 3 for Exit : ");
		remove("\\TEM.txt");
		scanf("%d",&last4);
		if(last4==1)
			delete_teacher();
		else if(last4==2)
			teachers_workplace();
		else
		{
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}
	else
	{
		printf("\n \n RECORD SUCCESFULLY DELETED");
		fclose(teacher);
		fclose(temp);
		remove("\\TTR.txt");
		rename("\\TEM.txt","\\TTR.txt");
		printf("\n Press 1 for SIGN IN and 2 for Exit : ");
		scanf("%d",&last4);
		if(last4==1)
			teacher_menu();
		else
		{
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}

	return ;
}

void backup()
{
	FILE *backup;
	FILE *teacher;
	teacher=fopen("\\TTR.txt","r");
	backup=fopen("\\BACKUP.txt","w");
	while(fread(&tea,sizeof(tea),1,teacher)==1)
	{
		fwrite(&tea,sizeof(tea),1,backup);
	}
	fclose(teacher);
	fclose(backup);
	return ;
}

void modify_teacher()
{
	/* Modify Teacher */
	char mtname[35],waste[2];
	int is1=1,last4,last6;
	backup();
	FILE *teacher;
	FILE *temp;
	teacher=fopen("\\TTR.txt","rb");
	temp=fopen("\\TEM.txt","wb");
	system("cls");
	printf(" ************************ TEACHER MODIFY ACCOUNT INPUTS ***********************");
	printf("\n \n ### Enter the Teachers Name ###");
	gets(waste);
	printf("\n \n Name of Teacher : ");
	gets(mtname);
	while(fread(&tea,sizeof(tea),1,teacher)==1)
	{
		if(strcmp(mtname,tea.tname)==0)
		{
			is1=0;
			continue;
		}
		else
		{
			fwrite(&tea,sizeof(tea),1,temp);
		}
	}
	if(is1==1)
	{
		printf("\n \n RECORD NOT FOUND");
		remove("\\TEM.txt");
		printf("\n Press 1 to RE-DO, 2 for TEACHER WORKPLACE and 3 for Exit : ");
		scanf("%d",&last4);
		if(last4==1)
			modify_teacher();
		else if(last4==2)
		{
			remove("\\BACKUP.txt");
			teachers_workplace();
		}
		else
		{
			remove("\\BACKUP.txt");
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}
	else
	{
		printf("\n \n ### Record FOUND ####");
		printf("\n Press Enter to continue.....: ");
		getch();
		fclose(teacher);
		fclose(temp);
		remove("\\TTR.txt");
		rename("\\TEM.txt","\\TTR.txt");
	}
	system("cls");
	modify:
	teacher=fopen("\\TTR.txt","ab+");
	printf("\n \n ### NEW RECORD INPUTS ###");
	printf("\n \n \n 1. Name of the Teacher : ");
	gets(tea.tname);
	printf("\n 2. Qualification : ");
	gets(tea.qual);
	printf("\n 3. Experience : ");
	gets(tea.exp);
	printf("\n 4. Number of Year Teaching in School : ");
	gets(tea.taug);
	printf("\n 5. Teaching Subject : ");
	gets(tea.sub);
	printf("\n 6. Salary : ");
	gets(tea.salary1);
	printf("\n 7. Contact : ");
	gets(tea.con1);
	printf("\n 8. Username (less than 10 digits) : ");
	gets(tea.user2);
	printf("\n 9. Password (less than 10 digits greater than 5) : ");
	gets(tea.pass2);
	printf("\n \n \n Press 1 for CONFIRM REGISTRATION 2 for RE-ENTRY and 3 for EXIT : ");

	scanf("%d",&last6);
	switch(last6)
	{
		case 1: {
				fwrite(&tea,sizeof(tea),1,teacher);
				fclose(teacher);
				printf("\n You have succesfully Modified your record");
				break;
			}
		case 2: goto modify;
		default:{
				remove("\\TTR.txt");
				rename("\\BACKUP.txt","\\TTR.txt");
				printf("\n Process is Terminated. \n Thank You!!");
				getch();
				exit(0);
				break;
			}

	}
	printf("\n \n Press 1 to go to TEACHER WORKPLACE and 2 for EXIT : " );
	scanf("%d",&last6);
	if(last6==1)
		teachers_workplace();
	else
	{
		printf("\n Process is Terminated. \n Thank You!!");
		getch();
		exit(0);
	}
	return ;
}


void teachers_record()
{
	/* Record Viewing */
	int sc;
	system("cls");
	FILE *teacher;
	teacher=fopen("\\TTR.txt","rb+");
	printf(" ****************************** TECACHER RECORD VIEWING *****************************");
	printf("\n \n SN.NO. NAME \t \t   SUBJECT \tSALARY \tCONTACT \tUSERNAME");
	do
	{
		while(fread(&tea,sizeof(tea),1,teacher)==1)
		{
			printf("\n NSS%d.   %s \t   %s \t%s \t%s \t%s \t%s",tea.teachercode,tea.tname,tea.sub,tea.salary1,tea.con1,tea.user2);
		}
		break;
	}
	while(feof(teacher));
	printf("\n \n Press Enter to continue : ");
	getch();
	redd:
	printf("\n Press 1 to TEACHER WORKPLACE and 2 for EXIT : ");
	scanf("%d",&sc);
	switch(sc)
	{
		case 1: teachers_workplace(); break;
		case 2: {
				printf("\n The Process is Terminamated. \n Thank You !!");
				getch();
				exit(0);
				break;
			}
	       default: {
				printf("\n Wrong Input !! \n Press Enter to REDO : ");
				getch();
				goto redd;
			}
	}
	return;
}

void student_information()
{
	/* Student Information Search */
	char stname[40],waste[2];
	system("cls");
	int is3=0,last7;
	FILE *studenta;
	studenta=fopen("\\STA.txt","rb");
	printf("************************ STUDENT SEARCH INPUTS ***********************");
	printf("\n \n ### Enter the Student Name ###");
	printf("");
	gets(waste);
	printf("\n \n Name of Student : ");
	gets(stname);
	while(fread(&stad,sizeof(stad),1,studenta)==1)
	{
		if(strcmp(stname,stad.sname)==0)
		{
			is3=1;
			break;
		}
	}
	if(is3==1)
	{
		printf("\n \n \n !!! MATCH FOUND !!!");
		printf("\n \n INFORMATION");
		printf("\n \n 1. Name of Student : %s ",stad.sname);
		printf("\n 2. Class : %s",stad.clas1);
		printf("\n 3. Faculty : %s ",stad.fac);
		printf("\n 4. Father's Name : %s ",stad.fath);
		printf("\n 5. Mother's Name : %s ",stad.moth);
		printf("\n 6. Date of Birth : %s ",stad.dob1);
		printf("\n 7. Address : %s ",stad.address);
		printf("\n 8. Contact : %s",stad.cont);
		printf("\n 9. Previous School : %s",stad.prs);
		printf("\n 10. Previous School Percentage : %s",stad.prp);
		fclose(studenta);
		printf("\n \n Press 1 to go to STUDENT WORKPLACE and 2 for EXIT : ");
		scanf("%d",&last7);
		if(last7==1)
			student_workplace();
		else
		{
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}
	else
	{
		printf("\n !!! No Result Found !!!");
		printf("\n \n Press 1 to RE-ENTER 2 for STUDENT WORKPLACE and 3 for EXIT : ");
		scanf("%d",&last7);
		if(last7==1)
			student_information();
		else if(last7==2)
			student_workplace();
		else
		{
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}
	return;
}

void student_record()
{
	/* Record Viewing */
	int sc,i=0;
	system("cls");
	FILE *studenta;
	studenta=fopen("\\STA.txt","rb+");
	printf(" ****************************** TECACHER RECORD VIEWING *****************************");
	printf("\n \n SN.NO. NAME \t\t CLASS \tDATE OF BIRTH \tFACULTY \tCONTACT");
	do
	{
		while(fread(&stad,sizeof(stad),1,studenta)==1)
		{
			i++;
			printf("\n   %d.   %s \t   %s \t%s \t%s \t%s \t%s",i,stad.sname,stad.clas1,stad.dob1,stad.fac,stad.cont);
		}
		break;
	}
	while(feof(studenta));
	printf("\n \n Press Enter to continue : ");
	getch();
	redd:
	printf("\n Press 1 to STUDENT WORKPLACE and 2 for EXIT : ");
	scanf("%d",&sc);
	switch(sc)
	{
		case 1: student_workplace(); break;
		case 2: {
				printf("\n The Process is Terminamated. \n Thank You !!");
				getch();
				exit(0);
				break;
			}
	       default: {
				printf("\n Wrong Input !! \n Press Enter to REDO : ");
				getch();
				goto redd;
			}
	}
	return;
}

void teacher_recovery()
{
	system("cls");
	char rtname[35],wa[2];
	char rcon1[12],rpass2[12];
	int is=0,tchk,ret;
	/* Teacher Recovery Account */
	FILE *teacher;
	teacher=fopen("\\TTR.txt","rb");
	printf(" **************************** Teachers Account Recovery *******************************");
	printf("\n \n ### Enter the Teacher Name ###");
	printf("");
	gets(wa);
	printf("\n \n Name of Teacher : ");
	gets(rtname);
	while(fread(&tea,sizeof(tea),1,teacher)==1)
	{
		if(strcmp(rtname,tea.tname)==0)
		{
			is=1;
			break;
		}
	}
	if(is==1)
	{
		printf("\n ### RECORD FOUND ###");
		printf("\n Press Enter to Continue.......:");
		getch();
	}
	else
	{
		printf("\n !!! RECORD NOT FOUND !!!");
		printf("\n Press 1 for RE-ENTRY and 2 for EXIT : ");
		scanf("%d",&tchk);
		switch(tchk)
		{
			case 1: teacher_recovery(); break;
			default:{
					printf("\n The Process is Terminamated. \n Thank You !!");
					getch();
					exit(0);
					break;
				}
		}
	}
	system("cls");
	printf("\n ### Fill Your Personel Details ###");
	printf("\n \n 1. Contact : ");
	gets(rcon1);
	if(strcmpi(rcon1,tea.con1)==0)
	{
		printf("\n \n ### You are a VALID USER ###");
		printf("\n Press Enter to see your USERNAME and PASSWORD......:");
		getch();
		printf("\n \n \n YOUR USERNAME : \" %s \"",tea.user2);
		printf("\n YOUR PASSWORD : \" %s \"",tea.pass2);
		getch();
		printf("\n \n Press 1 to go to SIGN IN and 2 for EXIT : ");
		scanf("%d",&tchk);
		switch(tchk)
		{
			case 1: teacher_signin(); break;
			default:
				printf("\n The Process is Terminamated. \n Thank You !!");
				getch();
				exit(0);
				break;
		}
	}
	else
	{
		printf("\n \n !!! YOU ARE NOT A VALID USER !!!");
		printf("\n \n Press 1 for RE-TRY and 2 for Exit : ");
		scanf("%d",&ret);
		if(ret==1)
			teacher_recovery();
		else
		{
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}
}

void teacher_code()
{
	char cdname[35],waste[2];
	int isf=0,test;
	system("cls");
	FILE *teacher;
	teacher=fopen("\\TTR.txt","rb");
	printf(" **************************** Teachers Code Finder *******************************");
	printf("\n \n !!!! Enter the name of the Teacher to find the code ");
	gets(waste);
	printf("\n \n \n Name of the Teacher : ");
	gets(cdname);
	while(fread(&tea,sizeof(tea),1,teacher)==1)
	{
		if(strcmp(cdname,tea.tname)==0)
		{
			isf=1;
			break;
		}
	}
	if(isf==1)
	{
		printf("\n \n !!!! RECORD FOUND !!!!");
		printf("\n \n \n YOUR CODE : NSST%d",tea.teachercode);
		getch();
		printf("\n \n Press 1 for TEACHER WORKPLACE and 2 for EXIT : ");
		scanf("%d",&test);
		if(test==1)
			teachers_workplace();
		else
		{
			printf("\n The Process is Terminamated. \n Thank You !!");
			getch();
			exit(0);
		}
	}
	else
	{
		printf("\n \n !!! NO MATCH FOUND !!!");
		printf("\n \n Press 1 for RE-ENTRY, 2 for TEACHER WORKPLACE and 3 for EXIT : ");
		scanf("%d",&test);
		switch(test)
		{
			case 1: teacher_code(); break;
			case 2: teachers_workplace(); break;
			default: {
					printf("\n The Process is Terminamated. \n Thank You !!");
					getch();
					exit(0);
				}
		}
	}
	return ;
}


main()
{
	/* Check Weather Student or Teacher */
	char proff[1];
	system("cls");
	printf("\n \t \t \t Narshing Secondary School");
	printf("\n \t \t \t   Piramath - 14,Birgunj");
	printf("\n \t \tModel School Techincal & Vocational Education");
	printf("\n \t \t \t   Phone no.  9801800559");
	printf("\n \n \n \n !!  Are you a TEACHER  or a STUDENT  !! ");
	printf("\n Enter 1 for TEACHER and 2 for STUDENT : ");
	gets(proff);
	if(strcmp(proff,"1")==0)
		teacher_menu();
	else if(strcmp(proff,"2")==0)
		student_menu();
	else
	{
		printf("\n Wrong Input !! \n Press Enter to RE-DO : ");
		getch();
		main();
	}
	return 0;
}
