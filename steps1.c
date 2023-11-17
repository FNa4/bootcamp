#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

char *headings[40][6] ; 

int main() { 

int i ;  

FILE *fp = fopen("FitnessData_2023.csv", "r") ; 

 if ( fp != NULL ) 
 { 
    for(i=0; i<4; i++)  
    {           
         while(i == 0) 
           {  
             headings[40][0] = "Obs" ;         
             fscanf(fp, "%s, %s, %s, %s, %s \n", 
             headings[40][1], headings[40][2], headings[40][3], 
             headings[40][4], headings[40][5] ) ;   
             i++;      
           }   
                  
    mydata = i;
   fscanf(fp, "%s, %s, %s, %d, %d \n", 
      mydata->date, mydata->time, mydata->steps);                   
   }  /* EOF */  
   
}  /* File exists */    
   

/*  Print the file */ 

printf("%s, %s, %s, %s, %s, %s \n", headings[40][0], 
   headings[40][1], headings[40][2], headings[40][3], 
   headings[40][4], headings[40][5] );  
  
int j; 
  
for (j=0; j<4; j++)    
  { 
    printf("%d %s %s %s %d %d", 
           mydata[j].date, mydata[j].time, 
           mydata[j].steps);   
  }  
          
return 0;   
  
}