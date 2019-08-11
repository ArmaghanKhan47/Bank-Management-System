#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct customer
{
	int account_number;
	char cust_name[55];
	char gender[7];
	char status[7];
	char cnic[14];
	int age;
	float balance;
	
};
void line();
void head();
int main()
{
	FILE *record;
	FILE *next_account_number;
	int choice;
	customer cu;
	customer temp;
	int program_status = 1;
	while (program_status == 1)
	{
		head();
		printf("\n\n\t\t\t\t\tPress 1 for New Entery.");
		printf("\n\t\t\t\t\tPress 2 for Search Particular Record.");
		printf("\n\t\t\t\t\tPress 3 for Deposit Cash.");
		printf("\n\t\t\t\t\tPress 4 for Withdrawl Cash.");
		printf("\n\t\t\t\t\tPress 5 for Viewing Transaction History.");
		printf("\n\t\t\t\t\tPress 6 for Changing Account Status.");
		printf("\n\n\t\t\t\t\tEnter Choice:");
		scanf("%d",&choice);
		system("cls");
		switch(choice)
		{
			case 1:
				{
					int i = 1;
					while(i == 1)
					{
						head();
						record = fopen("bank_database.txt","a");
						next_account_number = fopen("Account_number.txt","r+");
						printf("\n\n\t\t\t\t\tFirst Name:");
						scanf("%s",&cu.cust_name);
						printf("\n\t\t\t\t\tGender:");
						scanf("%s",&cu.gender);
						printf("\n\t\t\t\t\tAge:");
						scanf("%d",&cu.age);
						printf("\n\t\t\t\t\tCNIC(13-digits without -):");
						scanf("%s",&cu.cnic);
						printf("\n\t\t\t\t\tBalance:");
						scanf("%f",&cu.balance);
						printf("\n\t\t\t\t\tStatus:");
						scanf("%s",&cu.status);
						fscanf(next_account_number,"%d",&cu.account_number);
						printf("\n\t\t\t\t\tAccount#:%d",cu.account_number);
						fprintf(record, "\n%d %s %s %d %s %s %.2f",cu.account_number,&cu.cust_name,&cu.gender,cu.age,&cu.cnic,&cu.status,cu.balance);
						cu.account_number = cu.account_number + 2;
						fseek(next_account_number,0,SEEK_SET);
						fprintf(next_account_number,"%d",cu.account_number);
						fclose(record);
						fclose(next_account_number);
						printf("\n\n\n\t\t\t\t\tDo you want to enter another record(1/0):");
						scanf("%d",&i);
						system("cls");
					}
					break;
				}
			case 2:
				{
					head();
					printf("\n\n\t\t\t\t\tPress 1 for Searching by Account#.");
					printf("\n\t\t\t\t\tPress 2 for Searching by Name.");
					printf("\n\t\t\t\t\tPress 3 for Searching by CNIC#");
					printf("\n\t\t\t\t\tPress 4 for Searching by Gender.");
					printf("\n\n\t\t\t\t\tEnter Choice:");
					scanf("%d",&choice);
					switch(choice)
					{
						case 1:
							{
								int ea;
								printf("\n\n\t\t\t\t\tEnter Account#:");
								scanf("%d",&ea);
								record = fopen("bank_database.txt","r");
								printf("%-10s %-33s %-7s %-4s %-15s %-7s %-s\n","Acc#","Client Name","Gender","Age","CNIC#","Status","Balance");
								while(fscanf(record ,"%d %s %s %d %s %s %f",&cu.account_number,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.status,&cu.balance) != EOF)
								{
									if(ea == cu.account_number)
									{
										temp.account_number = cu.account_number;
										strcpy(temp.cust_name,cu.cust_name);
										strcpy(temp.gender,cu.gender);
										strcpy(temp.status,cu.status);
										strcpy(temp.cnic,cu.cnic);
										temp.age = cu.age;
										temp.balance = cu.balance;
									}
								}
								printf("%-10d %-33s %-7s %-4d %-15s %-7s %-.2f\n",temp.account_number,temp.cust_name,temp.gender,temp.age,temp.cnic,temp.status,temp.balance);
								fclose(record);
								break;	
							}
						case 2:
							{
								char name[55];
								printf("\n\n\t\t\t\t\tEnter Name:");
								scanf("%s",&name);
								record = fopen("bank_database.txt","r");
								printf("%-10s %-33s %-7s %-4s %-15s %-7s %-s\n","Acc#","Client Name","Gender","Age","CNIC#","Status","Balance");
								while(fscanf(record ,"%d %s %s %d %s %s %f",&cu.account_number,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.status,&cu.balance) != EOF)
								{
									if(strcmp(name,cu.cust_name) == 0)
									{
										temp.account_number = cu.account_number;
										strcpy(temp.cust_name,cu.cust_name);
										strcpy(temp.gender,cu.gender);
										strcpy(temp.status,cu.status);
										strcpy(temp.cnic,cu.cnic);
										temp.age = cu.age;
										temp.balance = cu.balance;
									}
								}
								printf("%-10d %-33s %-7s %-4d %-15s %-7s %-.2f\n",temp.account_number,temp.cust_name,temp.gender,temp.age,temp.cnic,temp.status,temp.balance);
								fclose(record);
								break;
							}
						case 3:
							{
								char ea[14];
								printf("\n\n\t\t\t\t\tEnter CNIC#(without -):");
								scanf("%d",&ea);
								record = fopen("bank_database.txt","r");
								printf("%-10s %-33s %-7s %-4s %-15s %-7s %-s\n","Acc#","Client Name","Gender","Age","CNIC#","Status","Balance");
								while(fscanf(record ,"%d %s %s %d %s %s %f",&cu.account_number,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.status,&cu.balance) != EOF)
								{
									if(strcmp(cu.cnic,ea) == 0)
									{
										temp.account_number = cu.account_number;
										strcpy(temp.cust_name,cu.cust_name);
										strcpy(temp.gender,cu.gender);
										strcpy(temp.status,cu.status);
										strcpy(temp.cnic,cu.status);
										temp.age = cu.age;
										temp.balance = cu.balance;
									}
								}
								printf("%-10d %-33s %-7s %-4d %-15s %-7s %-.2f\n",temp.account_number,temp.cust_name,temp.gender,temp.age,temp.cnic,temp.status,temp.balance);
								fclose(record);
								break;
							}
						case 4:
							{
								char name[55];
								printf("\n\n\t\t\t\t\tEnter Gender:");
								scanf("%s",&name);
								record = fopen("bank_database.txt","r");
								printf("%-10s %-33s %-7s %-4s %-15s %-7s %-s\n","Acc#","Client Name","Gender","Age","CNIC#","Status","Balance");
								while(fscanf(record ,"%d %s %s %d %s %s %f",&cu.account_number,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.status,&cu.balance) != EOF)
								{
									if(strcmp(name,cu.gender) == 0)
									{
										printf("%-10d %-33s %-7s %-4d %-15s %-7s %-.2f\n",cu.account_number,cu.cust_name,cu.gender,cu.age,cu.cnic,cu.status,cu.balance);
									}
								}
								fclose(record);
								break;
							}
						default:
							{
								printf("\nInvalid Selection");
								break;
							}
					}
					break;
				}
			case 3:
				{
					int ea;
					float balance;
					char status[7] = "ACTIVE";
					printf("\n\n\t\t\t\t\tEnter Account#:");
					scanf("%d",&ea);
					record = fopen("bank_database.txt","a+");
					printf("%-10s %-33s %-7s %-4s %-15s %-7s %-s\n","Acc#","Client Name","Gender","Age","CNIC#","Status","Balance");
					while(fscanf(record ,"%d %s %s %d %s %s %f",&cu.account_number,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.status,&cu.balance)!= EOF)
					{
						if(ea == cu.account_number)
						{
							temp.account_number = cu.account_number;
							strcpy(temp.cust_name,cu.cust_name);
							strcpy(temp.gender,cu.gender);
							strcpy(temp.status,cu.status);
							strcpy(temp.cnic,cu.cnic);
							temp.age = cu.age;
							temp.balance = cu.balance;
						}
					}
					printf("%-10d %-33s %-7s %-4d %-15s %-7s %-.2f\n",temp.account_number,temp.cust_name,temp.gender,temp.age,temp.cnic,temp.status,temp.balance);
					if(strcmp(temp.status,status) == 0)
					{
						printf("\n\t\t\t\t\tEnter Balance:");
						scanf("%f",&balance);
						temp.balance = temp.balance + balance;
						printf("%-10d %-33s %-7s %-4d %-15s %-7s %-.2f\n",temp.account_number,temp.cust_name,temp.gender,temp.age,temp.cnic,temp.status,temp.balance);
						fseek(record,0,SEEK_END);
						fprintf(record ,"\n%d %s %s %d %s %s %.2f",temp.account_number,&temp.cust_name,&temp.gender,temp.age,&temp.cnic,&temp.status,temp.balance);
					}
					else
					{
						printf("\nNOTE: ...ACCOUNT IS FREEZED...");
						printf("\nNOTE: ...CANNOT MAKE ANY TRANSACTIONS...");
					}
					fclose(record);
					break;
				}
			case 4:
				{
					int ea;
					int balance;
					char status[7] = "ACTIVE";
					printf("\n\n\t\t\t\t\tEnter Account#:");
					scanf("%d",&ea);
					record = fopen("bank_database.txt","a+");
					printf("%-10s %-33s %-7s %-4s %-15s %-7s %-s\n","Acc#","Client Name","Gender","Age","CNIC#","Status","Balance");
					while(fscanf(record ,"%d %s %s %d %s %s %f",&cu.account_number,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.status,&cu.balance) != EOF)
					{
						if(ea == cu.account_number)
						{
							temp.account_number = cu.account_number;
							strcpy(temp.cust_name,cu.cust_name);
							strcpy(temp.gender,cu.gender);
							strcpy(temp.status,cu.status);
							strcpy(temp.cnic,cu.cnic);
							temp.age = cu.age;
							temp.balance = cu.balance;
						}
					}
					printf("\n%-10d %-33s %-7s %-4d %-15s %-7s %-.2f",temp.account_number,temp.cust_name,temp.gender,temp.age,temp.cnic,temp.status,temp.balance);
					if(strcmp(temp.status,status) == 0)
					{
						printf("\nEnter CASH AMOUNT for WITHDRAWL:");
						scanf("%d",&balance);
						temp.balance = temp.balance - balance;
						if (temp.balance >= 0)
						{
							printf("\n%-10d %-33s %-7s %-4d %-15s %-7s %-.2f",temp.account_number,temp.cust_name,temp.gender,temp.age,temp.cnic,temp.status,temp.balance);
							fprintf(record, "\n%d %s %s %d %s %s %0.2f",temp.account_number,&temp.cust_name,&temp.gender,temp.age,&temp.cnic,&temp.status,temp.balance);
						}
						else
						{
							printf("NOTE: ...NOT ENOUGH MONEY IN ACCOUNT...");
						}
					}
					else
					{
						printf("\nNOTE: ...ACCOUNT IS FREEZED...");
						printf("\nNOTE: ...CANNOT MAKE ANY TRANSACTIONS...");
					}
					fclose(record);
					break;
				}
			case 5:
				{
					int ea;
					head();
					printf("\n\n\t\t\t\t\tEnter Account#:");
					scanf("%d",&ea);
					record = fopen("bank_database.txt","r");
					printf("%-10s %-33s %-7s %-4s %-15s %-7s %-s\n","Acc#","Client Name","Gender","Age","CNIC#","Status","Balance");
					while(fscanf(record ,"%d %s %s %d %s %s %f",&cu.account_number,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.status,&cu.balance) != EOF)
					{
						if(ea == cu.account_number)
						{
							printf("%-10d %-33s %-7s %-4d %-15s %-7s %-.2f\n",cu.account_number,cu.cust_name,cu.gender,cu.age,cu.cnic,cu.status,cu.balance);
						}
					}
					fclose(record);
					break;
				}
			case 6:
				{
					int ea;
					head();
					char status[7] = "FREEZE";
					printf("\n\n\t\t\t\t\tEnter Account#:");
					scanf("%d",&ea);
					record = fopen("bank_database.txt","a+");
					printf("%-10s %-33s %-7s %-4s %-15s %-7s %-s\n","Acc#","Client Name","Gender","Age","CNIC#","Status","Balance");
					while(fscanf(record ,"%d %s %s %d %s %s %f",&cu.account_number,&cu.cust_name,&cu.gender,&cu.age,&cu.cnic,&cu.status,&cu.balance)!= EOF)
					{
						if(ea == cu.account_number)
						{
							temp.account_number = cu.account_number;
							strcpy(temp.cust_name,cu.cust_name);
							strcpy(temp.gender,cu.gender);
							strcpy(temp.status,cu.status);
							strcpy(temp.cnic,cu.cnic);
							temp.age = cu.age;
							temp.balance = cu.balance;
						}
					}
					printf("%-10d %-33s %-7s %-4d %-15s %-7s %-.2f\n",temp.account_number,temp.cust_name,temp.gender,temp.age,temp.cnic,temp.status,temp.balance);
					printf("\nEnter Statues:");
					scanf("%s",&status);
					if (strcmp(temp.status,status))
					{
						strcpy(temp.status,status);
						fprintf(record, "\n%d %s %s %d %s %s %0.2f",temp.account_number,&temp.cust_name,&temp.gender,temp.age,&temp.cnic,&temp.status,temp.balance);
						printf("\nNOTE: ...STATUS CHANGED SUCCESSFULLY...");
					}
					else
					{
						printf("\nNOTE: ...ACCOUNT IS ALREADY %s...",temp.status);
					}
					fclose(record);
					break;
				}
			default:
				{
					printf("\nInvalid Selection");
					break;
				}
		}
	printf("\nRESTART PROGRAM AGAIN(1/0):");
	scanf("%d",&program_status);
	system("cls");
	}	
}
void line()
{
	int i = 1;
	while (i < 121)
	{
		printf("=");
		i++;
	}
}
void head()
{
	line();
	line();
	printf("\n%70s\n","...WELCOME TO F.A.L.T.U BANK...");
	printf("%65s\n","...EMPLOYEE PANEL...");
	printf("%80s\n","...PROGRAM IS CREATED FOR SEMESTER PROJECT...");
	printf("%70s","...BANK MANAGEMENT SYSTEM...\n\n");
	line();
	line();
}
