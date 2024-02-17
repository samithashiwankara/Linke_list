#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void AdiminMenuList();
void admin();
void adminMenuListContent();
void MainMenuContentDisplay();
void customer();
void CustomerMenuList();
void CustomerMenuListAbove();
void CalculateScales();
void displaybill();
int deletecustomer();
int deleteadmin();
void mainnenu();
void adminMenuAbove();


struct node
{
    char foodname[50];
    int quantity;
    float price;
    int data;
    struct node *prev;
    struct node *next;
};

int main_exit;
struct node *headc = NULL,*newnode,*tailc = NULL;
struct node *heada = NULL, *taila = NULL;
struct node *head_s;

void delay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


struct node* createadmin(struct node *head,int data, char foodname[25], float price)
{
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->price = price;
    newnode-> quantity = 0;
    strcpy(newnode->foodname,foodname);
    newnode->next = NULL;
    newnode->prev = NULL;

    struct node *temp = head;

    if(temp==NULL)
        heada = taila = newnode;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newnode;
        newnode->prev = taila;
        taila = newnode;
    }

    return heada;
}

struct node* createcustomer(struct node *head,int data,int quantity)
{
    newnode = (struct node*)malloc(sizeof(struct node));

    struct node *temp1 = heada;
    int flag = 0;
    while(temp1!=NULL)
    {
        if(temp1->data==data)
        {
            flag = 1;
            break;
        }
        temp1 = temp1->next;
    }

    if(flag==1)
    {
        newnode->data = data;
        newnode->price = quantity*(temp1->price);
        newnode-> quantity = quantity;
        strcpy(newnode->foodname,temp1->foodname);
        newnode->next = NULL;
        newnode->prev = NULL;

        struct node *temp = head;

        if(temp==NULL)
            headc = tailc = newnode;
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=newnode;
            newnode->prev = tailc;
            tailc = newnode;
        }


    }
    else
    {
        printf("\n\t\t\t\t\t\t\tThis item is not present in the menu!\n");
    }
    return headc;
}

void displayList(struct node *head)
{
    struct node *temp1 = head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tList is empty!!\n\n");
    }
    else
    {
        printf("\n");
        while(temp1!=NULL)
        {
            if(temp1->quantity==0)
                printf("\t\t\t\t\t\t\t%d\t%s\t\t\t%0.2f\n",temp1->data,temp1->foodname,temp1->price);
            else
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t\t\t%d\t%0.2f\n",temp1->data,temp1->foodname,temp1->quantity,temp1->price);
            }

            temp1 = temp1->next;
        }
        printf("\n");
    }

}

struct node* totalsales(int data,int quantity)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    int flag = 0;

    struct node *temp1 = heada;
    while(temp1->data!=data)
    {
        temp1 = temp1->next;
    }

    newnode->data = data;
    newnode->price = quantity*(temp1->price);
    newnode-> quantity = quantity;
    strcpy(newnode->foodname,temp1->foodname);
    newnode->next = NULL;
    newnode->prev = NULL;

    struct node *temp = head_s;

    if(temp==NULL)
        head_s = newnode;
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->data==data)
            {
                flag = 1;
                break;
            }
            temp=temp->next;
        }

        if(flag==1)
        {
            temp->quantity += newnode-> quantity;
            temp->price    += newnode->price;
        }
        else
        {
            temp->next=newnode;
        }
    }

    return head_s;
}


struct node* delete(int data,struct node *head, struct node* tail)
{
    if(head==NULL)
    {
        printf("\n\t\t\t\t\t\t\tList is empty\n");
    }
    else
    {
        struct node* temp;
        if(data==head->data)
        {
            temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
        }
        else if(data==tail->data)
        {
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else
        {
            temp = head;
            while(data!=temp->data)
            {
                temp = temp->next;
            }
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}



struct node* deleteList(struct node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node* temp = head;
        while(temp->next!=0)
        {
            temp = temp->next;
            free(temp->prev);
        }
        free(temp);
        head = NULL;
    }

    return head;
}


int main()
{
    heada = createadmin(heada,1,"MIXED FRIED RICE ",300);
    heada = createadmin(heada,2,"FISH FRIED RICE ",200);
    heada = createadmin(heada,3,"MIXED KOTTU ",150);
    heada = createadmin(heada,4,"VEGETABLE FRIED RICE ",180);
    heada = createadmin(heada,5,"CHICKEN FRIED RICE ",80);
    heada = createadmin(heada,6,"EGG FRIED RICE ",100);
    heada = createadmin(heada,7,"CHOPSUCY RICE ",200);
    heada = createadmin(heada,8,"MIXED NOODLES ",150);
    heada = createadmin(heada,9,"VEG/EGG NOODLES",180);
    heada = createadmin(heada,10,"CHOPSUCY CHILI NOODLES ",180);

    while(1)
    {
        mainnenu();
        int choice;
        scanf("%d",&choice);

        if(choice==3)
        {
        	printf("\n");
        	system("cls");
            printf("\n\n\t\t\t\t\t_____________/\\_____________THANK YOU FOR JOINING US!!_____________/\\_____________\n");
            break;
        }

        switch (choice)
        {
            case 1:
                admin();
                break;
            case 2:
                customer();
                break;
            case 3:
            	
                break;

            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                break;
        }
    }
}
void adminMenuAbove()
{
	printf("\n\n\n\n\n");
    printf("\t\t\t\t ADMIN SECTION\n");
    printf("\t\t\t\t ------------------------------------------------------------------------------------\n");
}

void adminMenuListContent()
{
           	 MainMenuContentDisplay();  
    		 printf("\n\t\t\t\t\t\t\t1. View total sales\n");
    		 printf("\t\t\t\t\t\t\t2. Add new items in the order menu\n");
       		 printf("\t\t\t\t\t\t\t3. Delete items from the order menu\n");
			 printf("\t\t\t\t\t\t\t4. Display order menu\n");
			 printf("\t\t\t\t\t\t\t5. Back to main menu \n\n");
		     printf("\t\t\t\t\t\t\t  ->  Enter Your Choice  : ");
}
void AdiminMenuList()
{
	
	char pass[10],password[10]="admin";
    int i=0;int cno,option;
  
    printf("\n\n\t\tEnter Admin the password to login:");
    scanf("%s",pass);
    
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
	        for(i=0;i<=6;i++)
	        {
	        	
	            delay(100000000);
	            printf("..>");
  
	        }
	        
	         system("cls");
	         adminMenuListContent();
	         	            
        }
         else
        {   printf("\n\nWrong password!!\a\a\a");
            loginAdmin_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        admin();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    exit;
					}
            else
                    {printf("\nInvalid!");
                    delay(1000000000);
                    system("cls");
                    goto loginAdmin_try;
					}

        }

}
void CustomerMenuListAbove()
{
	printf("\n\n\n\n\n");
    printf("\t\t\t\t CUSTOMER SECTION\n");
    printf("\t\t\t\t ------------------------------------------------------------------------------------\n");
}
void CustomerMenuList()
{
	MainMenuContentDisplay();
 	CustomerMenuListAbove();
    
    printf("\n\t\t\t\t\t\t\t1. Place your order\n");
    printf("\t\t\t\t\t\t\t2. View your ordered items\n");
    printf("\t\t\t\t\t\t\t3. Delete an item from order\n");
    printf("\t\t\t\t\t\t\t4. Display final bill\n");
    printf("\t\t\t\t\t\t\t5. Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice --->");
}
void CalculateScales()
{
    struct node *temp = headc;
    while(temp!=NULL)
    {
        head_s = totalsales(temp->data, temp->quantity);
        temp=temp->next;
    }
}
int deleteadmin()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d",&num);

    struct node* temp=heada;
    while(temp!=NULL)
    {
        if (temp->data == num)
        {
            heada = delete(num, heada, taila);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}

int deletecustomer()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d",&num);

    struct node* temp=headc;
    while(temp!=NULL)
    {
        if (temp->data == num)
        {
            headc = delete(num, headc, tailc);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}

void displaybill()
{
    displayList(headc);
    struct node *temp = headc;
    float total_price = 0;
    while (temp!=NULL)
    {
        total_price +=temp->price;
        temp = temp->next;
    }

    printf("\t\t\t\t\t\t\tTotal price: %0.02f\n",total_price);

}

void mainnenu()
{
	char pass[10],password[10]="abcode";
    int i=0;int cno,option;
    system("cls");
    printf("PADA project by \n\t KUHDSE 21.1F -002 => H.A.S Shiwankara \n\t KUHDSE 21.1F -009 => A.H.M.C.M Samanmali \n\t KUHDSE 21.1F -021 => R.R.K Chalhara \n\t KUHDSE 21.1F -026 => M.S.U Vass \n\t KUHDSE 21.1F -019 => E.A.Y.B Edirisinghe \n");
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
	        for(i=0;i<=6;i++)
	        {
	        	
	            delay(100000000);
	            printf("..>");
	        }
             system("cls");
    		 MainMenuContentDisplay();
    		
   		 	printf("\t\t\t\t\t\t\t1. -> ADMIN PANEL  \n");
		    printf("\t\t\t\t\t\t\t2. -> CUSTOMER ORDERING SECTION \n");
		    printf("\t\t\t\t\t\t\t3. -> EXIT \n\n");
		    printf("\t\t\t\t\t\t\tEnter Your Choice    :   ");
            
        }
         else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    exit;
					}
            else
                    {printf("\nInvalid!");
                    delay(1000000000);
                    system("cls");
                    goto login_try;
					}

        }

}

void admin()
{
    adminMenuAbove();
    while(1)
    {
        AdiminMenuList();
		back:
		printf("");
        int opt;
        scanf("%d",&opt);

        if(opt==5)
            break;

        switch (opt)
        {
            case 1:
            adminMenuAbove();
                displayList(head_s);
                printf("\n\n\n\nPress any key to continue ................ ");
                getch();
                system("cls");
                adminMenuListContent();
                goto back;
                break;
             case 2:
				adminMenuAbove();
                printf("\n\t\t\t\t\t\t\tEnter serial no. of the food item: ");
                int num,flag = 0;
                char name[50];
                float price;
                scanf("%d",&num);

                struct node *temp = heada;

                while(temp!=NULL)
                {
                    if(temp->data==num)
                    {
                        printf("\n\t\t\t\t\t\tFood item with given serial number already exists!!\n\n");
                        printf("\n\n\n\nPress any key to continue ................ ");
		                getch();
		                system("cls");
		                adminMenuListContent();
		                goto back;
						flag = 1;
                        
                        break;
                    }
                    temp = temp->next;
                }

                if(flag==1)
                    break;

                printf("\t\t\t\t\t\t\tEnter food item name: ");
                scanf("%s",name);
                printf("\t\t\t\t\t\t\tEnter price: ");
                scanf("%f",&price);
                heada = createadmin(heada, num, name, price);
                printf("\n\t\t\t\t\t\t\tNew food item added to the list!!\n\n");
              
                printf("\n\n\n\nPress any key to continue ................ ");
                getch();
                system("cls");
                adminMenuListContent();
                goto back;
                
                break;
            case 3:
            adminMenuAbove();
                if(deleteadmin())
                {
                    printf("\n\t\t\t\t\t\t### Updated list of food items menu ###\n");
                    displayList(heada);
                    
                }
                else
                {
                    printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist!\n\n");
                }
                
                printf("\n\n\n\nPress any key to continue ................ ");
                getch();
                system("cls");
                adminMenuListContent();
                goto back;

                break;
            case 4:
            adminMenuAbove();
            
                printf("\n\t\t\t\t\t\t\t________________/\\____Menu List____/\\_________________\n");
                displayList(heada);
                printf("\n\n\n\nPress any key to continue ................ ");
                getch();
                system("cls");
                adminMenuListContent();
                goto back;
                break;
			
            default:
            adminMenuAbove();
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                printf("\n\n\n\nPress any key to continue ................ ");
                getch();
                system("cls");
                adminMenuListContent();
                goto back;
                break;
        }
    }
}


void customer()
{
	
    int flag=0,j=1;
    char ch;
    printf("\n\t\t\t\t\t   ----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t    CUSTOMER SECTION\n");
    printf("\t\t\t\t\t   ----------------------------------------------\n");
    while(1)
    {
    	system("cls");
        CustomerMenuList();

        int opt;
        scanf("%d",&opt);

        if(opt==5)
            break;

        switch (opt)
        {
        	 case 1:
                	
				system("cls");
				MainMenuContentDisplay();
				CustomerMenuListAbove();
                displayList(heada);
                printf("\n\t\t\t\t\t\tEnter number corresponding to the item you want to order: ");
                int n;
                scanf("%d",&n);
                printf("\t\t\t\t\t\tEnter food item quantity: ");
                int quantity;
                scanf("%d",&quantity);
    			
                headc = createcustomer(headc, n, quantity);
                printf("\n\n\nPress any key to continoue add another item or to get bill amount ....");
                getch();
                break;
                
            case 2:
                system("cls");
				MainMenuContentDisplay();
				CustomerMenuListAbove();
                printf("\n\t\t\t\t\t\t\t  ###__ List of ordered items __###\n");
                displayList(headc);
                printf("\n\n\n Press any key to continoue...........");
                getch();
                break;
            case 3:
            	system("cls");
				MainMenuContentDisplay();
				CustomerMenuListAbove();
                if(deletecustomer())
                {
                    printf("\n\t\t\t\t\t\t### Updated list of your ordered food items ###\n");
                    displayList(headc);
                    printf("\n\nPress any key to continue...............");
                    getch();
                }
                else
                    printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist!!\n");
                    printf("\n\nPress any key to continue.................");  
					getch();
                  
                break;
            case 4:
                system("cls");
				MainMenuContentDisplay();
				CustomerMenuListAbove();
                printf("\n\t\t\t\t\t\t\t  ### Final Bill ###\n");
                displaybill();
                headc = deleteList(headc);
                printf("\n\n\npress any key to continoue.............");
                getch();
                system("cls");
				MainMenuContentDisplay();
				CustomerMenuListAbove();
                //flag=1;
                break;

            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                printf("\n\n\npress any key to continoue.............");
                getch();
                system("cls");
				MainMenuContentDisplay();
				CustomerMenuListAbove();
                
                break;
        }
        if(flag==1)
            break;
    }
}
void MainMenuContentDisplay()
{
	system("COLOR 0B");
	printf("\n\n");
    printf("                                             *****************************************************************\n");
    printf("                                               *************************************************************\n");
    printf("                                                  ______________________________________________________\n\n");
    printf("                                                     WELCOME TO CITY PLUS RESTAURANT MANAGEMENT SYSTEM\n");
    printf("                                                  ______________________________________________________\n\n");  
    printf("                                               *************************************************************\n");
    printf("                                             *****************************************************************\n\n\n");

}