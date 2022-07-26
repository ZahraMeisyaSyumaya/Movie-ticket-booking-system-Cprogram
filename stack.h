
#include <limits.h>     // untuk INT_MIN

#define CAPACITY 10  // Stack maximum capacity


// menentukan stack node structure
struct stack 
{
    int data;
    struct stack *next;
} *top;

// Stack size
int size = 4;

// Function declaration to perform push and pop on stack 
void push(int element);
int  pop();


int verifinsert()
{
        
        
    int choice, data;

    while(1)
    {
    	printf("------------------------------------\n");
        printf("    VERIFY THAT YOU ARE NOT A ROBOT  \n");
        printf("------------------------------------\n");
        printf("your task : empty the data!\n");
        printf("Press 1 to start/restart the verification\n");
        printf("press 2 to empty the data\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) 
        {
            case 1: 
                
                // Push element ke stack
                push(data);
                printf("press enter to start...");
                getch();
                system("cls");
                break;

            case 2: 
                data = pop();
                // jika stack tidak kosong
                if (data != INT_MIN)
                    printf("Data => %d\n", data);
                    printf("press enter to continue...");
					getch();
					system("cls");
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }

	
    return 0;
}




 //Function untuk push elemen baru pada stack.
 
void push(element)
{	
	for(element=0;element<size;element++){
    // pengecekan stack overflow
    if (size >= CAPACITY)
    {
        printf("Stack Overflow, can't add more value to stack.\n");
        return;
    }

    // membuat node baru dan push ke stack
    struct stack * newNode = (struct stack *) malloc(sizeof(struct stack));

    // Assign data ke node baru pada stack
    newNode->data = element;

	// Elemen berikutnya setelah node baru wajib menjadi elemen top (teratas) saat ini
    newNode->next = top;        

    // memastikan node terbaru selalu di top 
    top = newNode;
    
	}
	//element akan terisi 4 kali
	if (size=4){
		printf("data is full...\n");
	}
}



 //Function untuk pop element dari top stack.
 
int pop()
{	int data;
    struct stack * topNode;
    
    // Check stack underflow
    if (size <= 0 || !top)
    {
        printf("\nStack is empty.\n");

        
       printf("\nRecord insert Sucessfull");
       printf("\nexiting program...");
       exit(0);
    }

    // Copy reference dari stack top ke temp variable
    //disini kita mesti delete element stack top, dan membuat stack top untuk next element-nya.
    topNode = top;

    // Copy data dari element stack top 
    data = top->data;

    // memindahkan top ke  next element-nya
    top = top->next;

    // menghapus element stack paling top sebelumnya dari memory
    free(topNode);

    // Decrement stack size
    size--;
	printf("%d", data);
    return data;
}



