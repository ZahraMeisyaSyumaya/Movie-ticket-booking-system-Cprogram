#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#include"stack.h"
#include"queue.h"

struct book //untukdaftar film agar tidak terulang
{
	char code[20];
	char name[20];
	char date[20];
	char time[20];
	char rate[20];

}b;
int admin();
int sign_In();
void insert();
void details();
void review();
void book();
void loading();
void ticketBooked();
void verifbooking();
void setting();
void about();
void delay(float number_of_seconds);  

int main(){
	loading();
	
}	
		
int menu(){
	int choice;
	int x;
	while(x!=7)
	{
		printf("                 	Book 'N' Go \"Drive In Cinema\" \n");
		printf(" ==================================================================\n");
		printf("||             1 To puchase tickets 				  ||\n");
		printf("||             2 Now Showing Movies 		   		  ||\n");
		printf("||             3 Movie Review				  	  ||\n");
		printf("||             4 Setting (Admin Only)				  ||\n");
		printf("||             5 About Program					  ||\n");
		printf("||             6 Exit system:				  	  ||\n");
		printf("||================================================================||\n");

		printf("  Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				book();
				break;
			case 2:
				details();
				break;
			case 3:
				review();
				break;
			case 4:
				admin();
				break;			
			case 5:
				about();
				break;
			case 6:	
				exit(0);
			default: 
				printf("Choice not available\n");
				getch();
				system("cls");
				break;	
		}
	}
}

void loading(){
	int i;
	int *n=(int *)malloc(sizeof(int)); //mendeklarasikan  variabel n untuk array yang belum diketahui sizenya
	if(n != NULL){
			n[0]=5;
			n[1]=4;  
  			n[2]=3;
  			n[3]=2;
			n[4]=1;
	printf(" \n\n\n\n\t\t\t\t*** LOADING PROGRAM ***\n\t\t\t\t ");		
  	for(i=0;i < 5;i++){ 
  		delay(0.5);  //delaying nilai - nilai n
    	printf("%d ",n[i]); 
	}
	for(i=0;i < 3;i++){ 
  		delay(0.3); //delaying dot
    	printf(" . "); 
	}
	system("cls");
	menu();
	}
}

void delay(float number_of_seconds) 
{ 
    // Convert waktu ke milisekon
    float milli_seconds = 1000 * number_of_seconds; 
  
    // Storing waktu start
    clock_t start_time = clock(); 
  
    // looping sampai waktu yang dibutuhkan tidak tercapai
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void setting(){
	system("cls");
	FILE *fp; //deklarasikan pointer file.txt untuk menyimpan rincian dari film yang ingin di-input
	char sentence1[1000], sentence2[1000], sentence3[1000], sentence4[1000], sentence5[1000];	
	//ticket data
	struct book b;
	printf("Enter movie code (ex: 01) *No Space input:  ");	
	scanf("%s",b.code);
	printf("\nEnter movie name (ex: ForrestGump) *No Space input: ");	
	scanf("%s",b.name);	
	printf("\nEnter Date (format: DD/MM/YYYY) *No Space input: ");	
	scanf("%s",b.date);
	printf("\nTime (ex: 12PM) *No Space input : ");	
	scanf("%s",b.time);
	printf("\nEnter Film Rating (ex: PG-13, R, etc.) *No Space input : ");	
	scanf("%s",b.rate);
	
	fp=fopen("data.txt","a"); //menambahkan data pada End Of File agar data sebelumnya tidak terhapus

	if(fp == NULL) //saat belum terdapat data film
	{
		printf("FIle not Found");
	}
	else 
	{
		fprintf(fp,"\n%s %s \t\t%s \t\t%s \t\t%s", b.code, b.name, b.date, b.time, b.rate);
		
	}
	fclose(fp);
	
	
	printf("\n");
	system("cls");
	verifinsert();  //verifikasi menggunakan stack
	
}

void details(){

	char ch; //digunakan untuk menampilkan semua film
	FILE *fp;

	fp = fopen("data.txt","r"); //membaca semua film yang ada  
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
	printf(" ===================================================================\n");
	printf("                 	Book 'N' Go \"Drive In Cinema\" \n");
	printf("                 		Now Showing				 \n");
	printf(" ===================================================================\n");
		printf("Code Movies \t\tDate \t\t\tTime \t\tRate\n"); //berhenti sampai akhir data pada file
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
	getch();
	system("cls");
}

void book()
{
	struct book b;
	FILE *fp;

	FILE *ufp;
	
	char name[20];
	int totalTicket,mobileNumber,totalAmount;
	char ch; //digunakan untuk menampilkan semua film
	char movieCode[30]; //untuk mencari film yang diinginkan menggunakan code film

	// menampilkan semua film yang dicari berdasarkan code
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		printf(" ==================================================================\n");
		printf("                 	Book 'N' Go \"Drive In Cinema\" \n");
		printf(" ==================================================================\n");
		printf("Code Movies\t \tDate\t \t\tTime \t\tRate\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
	
	//display berakhir 
	printf("\n ***Ticket Booking***\n");
	printf("\n Enter movie code :");
	scanf("%s",movieCode);
	
	fp = fopen("data.txt","r");  //membaca semua film yang ada  
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fp) != EOF) // dicek sampai akhir file
		{
			fscanf(fp,"%s %s %s %s %s",b.code,b.name,b.date, b.time, b.rate); //mengecek (menyamakan) code yang diinput dari user
			
			if(strcmp(b.code,movieCode) == 0)
			{	system("cls");
				printf(" ==================================================================\n");
				printf("                 	Book 'N' Go \"Drive In Cinema\" \n");
				printf(" ==================================================================\n");		
				printf("\n Movie Record\n");
				printf("\n\t\tCode : %s",b.code);
				printf("\n\t\tMovie : %s",b.name);
				printf("\n\t\tDate : %s",b.date);
				printf("\n\t\tTime : %s",b.time);
				printf("\n\t\tRate : %s",b.rate);
			}

		}
		
	}
	printf("\n\n* Fill Details to continue booking the tickets  *"); //mengisi data pemesan ticket
	printf("\n\n your name :"); 
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobileNumber);
	printf("\n Total number of tickets :");
	scanf("%d",&totalTicket);
	printf("\nParking fee = IDR 10.000");
	printf("\nTicket Price = IDR 50.000");
	
	totalAmount = 50000 * totalTicket + 10000; //menjumlahkan total pembelian tiket
	printf("\npress any key to continue verification...");
	getch();
	system("cls");
	enqueue();
	system("cls");
	printf("\n\t\t ***** ENJOY THE MOVIE ****\n");
	printf("\t==============================================\n");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tMobile Number : %d",mobileNumber);
	printf("\n\t\tMovie: %s",b.name);
	printf("\n\t\tNumber of Tickets: %d",totalTicket);
	printf("\n\t\tTotal Amount : IDR %d",totalAmount);
	printf("\n\n\n\n\t\t*Dont forget to bring the\n\t\ttransactionrecord for proof");
	printf("\n\t==============================================\n");
	printf("\n\t\tEmail	: proyekakhirlancar@test.ing\n");
	printf("\t==============================================\n");
	getch();
	system("cls");
	ufp=fopen("oldReservation.txt","a"); //memasukan data pembeli tiket ke file baru 
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"\n\t\tName : %s \n\t\tMobile Number : %d \n\t\tMovie : %s \n\t\tDate : %s \n\t\tTime : %s \n\t\tNumber of Tickets : %d \n\t\tTotal Amount : IDR %d \n",name,mobileNumber,b.name,b.date, b.time,totalTicket, totalAmount);
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);

}


int admin(){ //username dan password terdapat pada file users.txt
    char user[30], pass[30];
	admin:
	system("cls");
	printf(" ==================================================================\n");
	printf("                 	Book 'N' Go (Admin)\n");
	printf(" ==================================================================\n");	
	printf("||             User	:"											  ); //berdasarkan file users.txt username : kalgam
	scanf("%s",user);
	printf("||             Password	:"                                            ); //berdasarkan file users.txt pasword : protein12
    scanf("%s",pass);
 	FILE *p;
    char user2[30], pass2[30]; //mendeklarasikan variabel yang terdapat pada file users.txt

    p= fopen("users.txt", "r"); 


    fscanf(p,"User: %s Password: %s",user2,pass2);  //scanning file users.txt

    if( (strcmp(user,user2)==0) && (strcmp(pass,pass2)==0) ){ //menyamakan file users.txt dengan username dan password yang dimasukan user
	
        printf("\nUser and password correct!!!");
        menu_admin();
    }
	else
		 printf("\nUser or password incorrect!\n\n");
    printf("\n\n");	
	getch();
	system("cls");
    fclose(p);
	main();
}

void ticketBooked()
{	
	char ch;
	FILE *fp;

	
	
	fp = fopen("oldReservation.txt","r"); //membaca	seluruh	transaksi yang telah dilakukan pada function book
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF ) //dicek sampai akhir file
      		printf("%c",ch);
		
	}
	fclose(fp);
	getch();
	system("cls");


}

void review(){
	
	char r;
	FILE *rptr; //deklarasi file review
	char revMovie[20];
	rptr = fopen("review.txt","r");

		system("cls");
		printf(" ==================================================================\n");
		printf("                Book 'N' Go \"Drive In Cinema\" \n");
		printf("                    	Movie Review        \n");
		printf(" ==================================================================\n");
		while( ( r = fgetc(rptr) ) != EOF ) //membaca seluruh data pada file review sampai akhir
   		printf("%c",r);
		
	
	fclose(rptr);

	char text1[1000], text2[1000], buff[1000]; //buff digunakan sebagai buffer agar program lancar 

	printf("\nMovie : ");
    scanf("%s",revMovie); //memasukan nama film
    printf("\nReview (2 lines max) :\n "); // menuliskan review yang maksimalnya 2 baris/line
	rptr = fopen("review.txt","a"); 
	
	if(rptr == NULL)
	{
		printf("File not Found");
	}
	else
	{	
		fgets(text1, sizeof(text1), stdin);
		fgets(text2, sizeof(text2), stdin);
		fgets(buff, sizeof(buff), stdin);
		fprintf(rptr,"%s %s %s %s \n",revMovie, text1, text2, buff);
		
	}
	fclose(rptr);
	system("cls");
}

int menu_admin(){
	int chc;	
	system("cls");
	printf(" ==================================================================\n");
	printf("                 	Book 'N' Go (Admin)\n");
	printf(" ==================================================================\n");
	printf("||             1 Ticket Booked					  ||\n");
	printf("||             2 Setting		   			  ||\n");
	printf("||             3 Back to Main Menu		  		  ||\n");
	printf(" ==================================================================\n");
	printf("  \nEnter your choice: ");
		scanf("%d",&chc);
		switch(chc)
		{
			case 1:
			ticketBooked();
			menu_admin();
			case 2:
				setting();
				break;
			case 3:
				system("cls");
				menu();
				break;
			
			default: 
				printf("Choice not available\n");
				break;	
		}
}
void about(){
		system("cls");
		printf(" ==================================================================\n");
		printf("                Book 'N' Go \"Drive In Cinema\" \n");
		printf("                      About Program      \n");
		printf(" ==================================================================\n");
		printf(" This Program Created by Zahra Meisya Syumaya and Zidan Masyudul Haq\n");
		printf(" With this program, you can easily book Drive In Cinema only by phone\n");
		printf(" or web browser\n");
		printf(" We choose to create this program because of the covid - 19 pandemic  \n");
		printf(" so it would be better if we enjoy the movie inside cars than inside\n");
		printf(" the cinema that full of people\n");
		
		getch();
		system("cls");
}
