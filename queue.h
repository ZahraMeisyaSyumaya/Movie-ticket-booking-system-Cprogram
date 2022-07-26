 
struct node   //mendklarasikan struct node pointer next
{  
    int data;   
    struct node *next;  
};  

struct node *front;  
struct node *rear;   

void enqueue()  
{  
    struct node *ptr;  
    int item,i;   
		printf("-------------------------------------------------------------\n");
        printf("   			  VERIFY THAT YOU ARE NOT A ROBOT  \n");
        printf("-------------------------------------------------------------\n");
        printf("your task : enter random numbers 3 times to full the data!\n");
        printf("example -> 1 , 2 , 3 \n");
        printf("-------------------------------------------------------------\n");
    for (i=0;i<3;i++){
	
    ptr = (struct node *) malloc (sizeof(struct node));  //pounter yang jumlahnya menyesuaikan jumlah item nantinya
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        scanf("%d",&item);  //input nilai
        ptr -> data = item;  //nilai variabel item dipinhkan pada ptr -> data 
        if(front == NULL)  //jika bagian depan masih kosong 
        { 
            front = ptr;  //front(depan) dan rear(belakang) memiliki alamat yang sama (dari ptr yang berisikan angka pertama yang di input)
            rear = ptr;   
            front -> next = NULL;  // nilai next datanya pun kosong
            rear -> next = NULL; 
        }  
        else   			 //jika bagian depan sudah terisi		
        {  	//metode swap				
            rear -> next = ptr;  //nilai paling baru dimasukan oleh user itu dideklarasikan menjadi nilai paling belakang
            rear = ptr;  //dipindahkan ke variabel baru (bukan paling belakang)
            rear->next = NULL; //mengosongkan variabel paling belakang agar dapat digunakan untuk next input terbaru yang dimasukan oleh user 
			printf("%d", rear->next);  
        }  
    } 

	}
	printf("queue is full..");
	 
}     
