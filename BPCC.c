#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
FILE *fp;
char choice;
int divide, dayno=1;
float inputbudget,totalcalcbudget=0,totalexpense=0,tmp;
int number,i, percentage=100,month,year, flag=0;
void dateprinter(){
	printf("\n_______________________________________________________________\nThis budget is for the month of ");
	fprintf(fp,"\n_______________________________________________________________\nThis budget is for the month of ");
	switch(month){
	case 1:
		printf("January ");
		fprintf(fp,"January ");
		break;
	case 2:
		printf("February ");
		fprintf(fp,"February ");
		break;
	case 3:
		printf("March ");
		fprintf(fp,"March ");
		break;
	case 4:
		printf("April ");
		fprintf(fp,"April ");
		break;
	case 5:
		printf("May ");
		fprintf(fp,"May ");
		break;
	case 6:
		printf("June ");
		fprintf(fp,"June ");
		break;
	case 7:
		printf("July ");
		fprintf(fp,"July ");
		break;
	case 8:
		printf("August ");
		fprintf(fp,"August ");
		break;
	case 9:
		printf("September ");
		fprintf(fp,"September ");
		break;
	case 10:
		printf("October ");
		fprintf(fp,"October ");
		break;
	case 11:
		printf("November ");
		fprintf(fp,"November ");
		break;
	case 12:
		printf("December ");
		fprintf(fp,"December ");
		break;
	}printf("for the year %d.\n_______________________________________________________________\n",year);
	fprintf(fp,"for the year %d.\n_______________________________________________________________\n",year);
}
typedef struct{
	char name[MAX];
	float percent;
	float possiblebudget;
	float calculatedbudget;
	float itemexpense;
}budget;
budget class[MAX];

budget record(){
	budget categ;
	printf("Enter a category: ");
	scanf("%s",categ.name);
	if(i<number-1){
		do{
			printf("    %d% remaining. Enter percentage allocation: ",percentage);
			scanf("%f",&tmp);
			if (tmp>percentage || tmp==percentage || tmp<0){
				printf("\n    Your input is invalid. Please try again.\n");}
			else{
				(categ.percent)=tmp;
			}
		}while(tmp>=percentage || tmp<0);
	}
	else{
		printf("    %d% remaining. Value automatically allocated to last category.",percentage);
		(categ.percent)=percentage;
	}
	(categ.possiblebudget)=((categ.percent)/100)*inputbudget;
	return categ;}
void expenseprinter(budget *item){
	fprintf(fp,"%20s			%.2f			    %.2f\n",(*item).name,(*item).calculatedbudget,(*item).itemexpense);
	printf("%20s			%.2f			    %.2f\n",(*item).name,(*item).calculatedbudget,(*item).itemexpense);
}
void printer(budget *item){
	printf("%20s			%.2f%			    %.2f\n",(*item).name,(*item).percent,(*item).possiblebudget);
	fprintf(fp,"%20s			%.2f%		    	%.2f\n",(*item).name,(*item).percent,(*item).possiblebudget);}
void calculatedprinter(budget *item){
	printf("%20s			%.2f%		    	%.2f\n",(*item).name,(*item).percent,(*item).calculatedbudget);
	fprintf(fp,"%20s			%.2f%	    		%.2f\n",(*item).name,(*item).percent,(*item).calculatedbudget);}
void user_choice(int div, char *input1,char *input2,char *input3){
    char def_choice;
    float addbudget;
	divide=div;
	fprintf(fp,"%s",input1);
	printf("%s.\n",input2);
	while((divide>0)&&(inputbudget>0)){
		calculate_startweek: for(i=0;i<number;i++){
			class[i].calculatedbudget=(class[i].possiblebudget)/divide;
			totalcalcbudget+=(class[i].possiblebudget)/divide;}
		printf("\nStarting DAY # %d\n________________\nYou are expected to spend %.2f pesos today\n\t    CATEGORY			 RATE       POSSIBLE BUDGET(%s)\n",dayno,totalcalcbudget,input3);
		fprintf(fp,"\nStarting DAY # %d\n________________\nYou are expected to spend %.2f pesos today\n\t    CATEGORY			 RATE       POSSIBLE BUDGET(%s)\n",dayno,totalcalcbudget,input3);
		for(i=0;i<number;i++){
			calculatedprinter(&(class[i]));}
		divide--;
		dayno++;
		if(flag==1){
			if(divide<0){
				printf("\nThe possible number of days have already been filled. Assessment ends here.\n");
				break;
			}
		}
		else if (flag!=1){
			if(divide<=0){
				printf("\nThe possible number of days have already been filled. Assessment ends here.\n");
				break;
			}
		}
		if(inputbudget<=0){
			printf("\nYour expenses have exceeded your inputted budget. Future assessments will be invalid.\n");
			break;
		}
		printf("\nWould you like to assess your expenses? Press Y for yes and any other key for no: ");
		scanf("%s",&choice);
		if(choice=='Y'||choice=='y'){
			for(i=0;i<number;i++){
				printf("How much did you spend on the %s category for today?\t",class[i].name);
				scanf("%f",&(class[i].itemexpense));
				totalexpense+=(class[i].itemexpense);}
			printf("\nYou have spent %.2f pesos for today while you are expected to spend %.2f pesos.The table below\nshows your expenses along with the proposed budget for every category.\n\n\t    CATEGORY		POSSIBLE BUDGET(%s)		     EXPENSE\n",totalexpense,totalcalcbudget,input3);
			fprintf(fp,"\nYou have spent %.2f pesos for today while you are expected to spend %.2f pesos.The table below\nshows your expenses along with the proposed budget for every category.\n\n\t    CATEGORY		POSSIBLE BUDGET(%s)		    EXPENSE\n",totalexpense,totalcalcbudget,input3);
			for(i=0;i<number;i++){
				expenseprinter(&(class[i]));
			}
			if(totalexpense>totalcalcbudget){
				printf("\nYou have exceeded today's budget by %.2f pesos.\n",totalexpense-totalcalcbudget);
				fprintf(fp,"\nYou have exceeded today's budget by %.2f pesos.\n",totalexpense-totalcalcbudget);}
			else if(totalexpense==totalcalcbudget){
				printf("\nYou have spent your money according to your budget plan.\n");
				fprintf(fp,"\nYou have spent your money according to your budget plan.\n");}
			else{
				printf("\nYou have saved an amount of %.2f pesos based on your expenses.\n",totalcalcbudget-totalexpense);
				fprintf(fp,"\nYou have saved an amount of %.2f pesos based on your expenses.\n",totalcalcbudget-totalexpense);}
			inputbudget-=totalexpense;
			totalexpense=totalcalcbudget=0;
			if(div!=1){
				if(inputbudget<=0&&divide!=0){
					printf("\nYou have a deficit of %.2f.\nWould you like to increase your budget?\nEnter Y for yes and any key for no: ",inputbudget*(-1));
					fprintf(fp,"\nYou had a deficit of %.2f. ",inputbudget*(-1));
					scanf("%s",&def_choice);
					if(def_choice=='Y' || def_choice=='y'){
						do{
                    	    printf("\nEnter your additional budget: ");
                    	    scanf("%f",&addbudget);
                    	    if(addbudget<=inputbudget*(-1)){
                    	        printf("Please enter additional budget higher than %.2f\n",inputbudget*(-1));}
						}while(addbudget<=(inputbudget*(-1)));
						inputbudget+=addbudget;
						printf("Current budget is %.2f.\nThe program has formulated a new budget plan for you.\n\n",inputbudget);
						fprintf(fp,"You chose to increase your budget. Current budget is %.2f.\nThe program has formulated a new budget plan for you.\n\n",inputbudget);
						for(i=0;i<number;i++){
							class[i].possiblebudget=((class[i].percent)/100)*inputbudget;
                    	}
					}
					else{
						printf("You chose to not increase your budget.\n");
						fprintf(fp,"You chose to not increase your budget.\n");
					}
				}
				else{
					printf("\nYour current budget is %.2f.\nThe program has formulated a new budget plan for you.\n\n",inputbudget);
					for(i=0;i<number;i++){
						class[i].possiblebudget=((class[i].percent)/100)*inputbudget;
					}
				}
				goto calculate_startweek;
			}
		}
		else{
			printf("\nYou have chosen to not assess your expenses for the day.\n");
			break;
		}
	}
	fprintf(fp,"\nRemaining budget based on previous calculations and assessments: ");
	if(inputbudget>=0){
		fprintf(fp,"%.2f",inputbudget);
	}
	else{
		fprintf(fp,"%.2f (deficit)",inputbudget*(-1));
	}
}
main(){
    char choose;
	int ans,pick;
	totalcalcbudget=totalexpense=0;
	fp=fopen("records.txt","a");
	printf(" _________________________________________________________________\n|WELCOME TO THE Budget Planner and Consumption Calculator PROGRAM!|\n _________________________________________________________________\n\tHow may we help you?\n\tS	Start\n\tI	Instructions\n\tC	Credits\n\tE	Exit\n");
	do{
		printf("\nPlease enter a command: ");
		scanf("%s",&choice);
		if((choice!='S')&&(choice!='s')&&(choice!='I')&&(choice!='i')&&(choice!='C')&&(choice!='c')&&(choice!='E')&&(choice!='e')){
			printf("\nCommand Error. Please try again.");
		}
	}while((choice!='S')&&(choice!='s')&&(choice!='I')&&(choice!='i')&&(choice!='C')&&(choice!='c')&&(choice!='E')&&(choice!='e'));
	if(choice=='E'||choice=='e'){
		printf("\n\t+-----PROGRAM IS NOW EXITING-----+\n\tThank you for trying out the BPCC App.\n");
		exit (1);
	}
	else if(choice=='C'||choice=='c'){
		printf("\n\t\t\t\t _______\n\t\t\t\t|CREDITS|\n\t\t\t\t _______\nThis program was made possible through the efforts of Shebna Rose Fabilloren, Michelle Nemiada,\nand Gregg Marionn Icay BS in Computer Science I students of the University of the Philippines\nVisayas A.Y. 2014-2015 as a requirement for their subject CMSC 21(Fundamentals of C Programming).\n\n");
		main();
	}
	else if(choice=='I'||choice=='i'){
		printf("\n\t\t\t\t __________\n\t\t\t\t|DIRECTIONS|\n\t\t\t\t __________\n\n\t(1)The user will first input the month number and the year on which a budget will be allocated.\n\n\t(2)The user will provide the budget for planning.\n\n\t(3)The user will then have to input the number of possible categories in which he/she\n\twill be spending the money on.\n\n\t(4)The user will input categories and for each category, the user will have to input the\n\tdesired percentage to accommodate a corresponding category.\n\n\t(5)The user is not allowed to enter percentage greater than the current one. While each category\n\thas not yet been filled, entering a value equal to the current percentage is also invalid.\n\tThe program will alert the user of any invalid inputs. The user can choose to change any inputs.\n\n\t(6)The program will then ask if the user would like to use the budget in a month, week, or day.\n\n\t(7)The program will then formulate a budget based on the inputted data and present a\n\tbudget plan to the user.\n\n\t(8)An option will be available to the user if he/she would like to assess today's\n\tconsumption and check his/her expenses.\n\n\t(9)The expenses for each previously inputted category will be asked and the program will\n\tcalculate a revised budget plan based on the remaining based on the remaining budget\n\tand number of days.\n\n\t(10)If ever the user's expenses exceeds the budget and yields a deficit,he/she has an option\n\tof increasing his/her budget granted that there are still a number of remaining days.\n\tOtherwise, the output will be considered as a deficit.\n\n");
		main();
	}
	else if(choice=='S'||choice=='s'){
	do{
		printf("\nEnter month number and a year for your budget plan(format mm/yyyy)\n\tEx.\n	Input: 1 2009\n	Output: January 2009\nInput: ");
		scanf("%d %d",&month,&year);
		if((month<=0)||(month>12)||(year<=0)){
			printf("\nThat was an invalid date. Please try again.");}
	}while((month<=0)||(month>12)||(year<=0));
	start:do{
		printf("Enter number of categories: ");
		scanf("%d",&number);
		if(number>MAX){
			printf("Not enough space. Please enter a different number.\n");}
		else if(number<=0){
			printf("Invalid input. Please enter only positive numbers.\n");}
	}while(number>MAX||number<=0);
	percentage=100;
	do{
		printf("\nEnter your budget: ");
		scanf("%f",&inputbudget);
		if(inputbudget<=0){
			printf("That was an invalid input. Enter only a positive value.\n");
		}
	}while(inputbudget<=0);
	fprintf(fp,"\nNewly inputted BPCC DATA STARTS HERE\nInputted Budget: %.2f\n",inputbudget);
	for(i=0;(i<number)&&(percentage>0);i++){
		printf("(%d) ",i+1);
		class[i]=record();
		percentage-=(class[i].percent);}
	change: printf("\nInputted values\n\t    CATEGORY			 RATE			POSSIBLE BUDGET\n");
	fprintf(fp,"\nInputted values\n\t    CATEGORY			 RATE			POSSIBLE BUDGET\n");
	for(i=0;i<number;i++){
		printer(&(class[i]));}
	printf("\nWould you like to change your inputted values? Press Y for yes and any other key for no: ");
	scanf("%s",&choice);
	if(choice=='Y'||choice=='y'){
		do{
			printf("\nPlease choose from 1-4 the part that you would like to change.\n\t(1)Percentage only\n\t(2)Category only\n\t(3)Percentage and category\n\t(4)All inputs including the number of categories\n\t:");
			scanf("%s",&choose);
			if(choose!='1'&&choose!='2'&&choose!='3'&&choose!='4'){
				printf("Invalid input. Choose only between numbers 1-4");}
        }while(choose!='1'&&choose!='2'&&choose!='3'&&choose!='4');
		if(choose=='4'){
			goto start;}
		else if(choose=='1'){
			percentage=100;
			for(i=0;(i<number)&&(percentage>0);i++){
				if(i<number-1){
					do{
						printf("\nEnter percentage allocation for the %s category: ",class[i].name);
						scanf("%f",&tmp);
						if (tmp>percentage || (tmp==percentage && i!=number-1)){
							printf("Your input is invalid. Please try again.\n");}
						else{
							(class[i].percent)=tmp;}
					}while(tmp>percentage || (tmp==percentage && i!=number-1));}

				else{
					(class[i].percent)=percentage;}

				(class[i].possiblebudget)=((class[i].percent)/100)*inputbudget;
				percentage-=class[i].percent;}
			goto change;}
		else if(choose=='2'){
			for(i=0;i<number;i++){
				printf("#%d Input a category: ",i+1);
				scanf("%s",class[i].name);}
			goto change;}
		else if(choose='3'){
			percentage=100;
			for(i=0;i<number&&percentage>0;i++){
				printf("(%d) ",i+1);
				class[i]=record();
				percentage-=(class[i].percent);}
			goto change;}}
	do{
		printf("\nChoose a time frame for the budget:\n\t(1)Month\n\t(2)Week\n\t(3)Day\n:");
		scanf("%s",&choose);
		if(choose!='1'&&choose!='2'&&choose!='3'){
			printf("Invalid input. Choose only between numbers 1-3");}
    }while(choose!='1'&&choose!='2'&&choose!='3');
	dateprinter();
	printf("\nYou have chosen to use the money as a ");
	fprintf(fp,"\nThis data was used as ");
	if(choose=='2'){
		user_choice(7,"a weekly budget.\n","weekly budget","weekly");}
	if(choose=='1'){
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
			divide=31;}
		else if(month==2){
			(year%4==0)?(divide=29):(divide=28);}
		else{
			divide=30;}
		user_choice(divide,"a monthly budget","monthly budget","monthly");}
	if(choose=='3'){
		flag=1;
		user_choice(1,"a daily budget","daily budget","daily");
	}
	printf("\nBudget planning and assessment is done for the given date and budget. Would you like to try again?\nPress Y for yes and any other key to exit: ");
	scanf("%s",&choice);
	if(choice=='Y'||choice=='y'){
		printf("\n...The program is now resetting...\n");
		main();
	}
	else{
		printf("\n\t+-----PROGRAM IS NOW EXITING-----+\n\tThank you for trying out the BPCC App.\n");
		exit(1);}}

	return 0;}
