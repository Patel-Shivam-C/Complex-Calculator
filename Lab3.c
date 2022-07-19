/* Revision 1.1.  loadComplex() changed, to return Complex structure */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
   double real; 
   double imag; 
} Complex;

#define Exit 0
#define Load 1
#define Display 2
#define Move 3
#define Conjugate 4
#define Add 5
#define Subtract 6
#define Multiply 7
#define Divide 8

#define PROMPT_USER_TO(menuItem) printf("%d. %s complex numbers\n", menuItem, #menuItem);

int  displayMenu();
void executeMenuItem(int menuItem);
Complex loadComplex();
int chooseComplexNumberTo(char*);

Complex add(Complex, Complex);
Complex subtract(Complex, Complex);
Complex multiply(Complex, Complex);
Complex divide(Complex, Complex);
Complex complexConjugate(Complex);
Complex moveComplex(Complex);
char display(Complex);

int main(void){   
   int choice = Exit;
   printf("Welcome to the complex number calculatollr\n\n");
   do{
      choice = displayMenu();
	   executeMenuItem(choice);
   } while (choice != Exit);

   printf("Program exited\n");
   exit(EXIT_SUCCESS);
}

// display menu options, prompt the user to enter a choice, and return the value selected
// DO NOT CHANGE THIS FUNCTION
int displayMenu(){  
    int input = Exit;
    printf("Select one of the following:\n\n");
    PROMPT_USER_TO(Load)
    PROMPT_USER_TO(Display)
    PROMPT_USER_TO(Move)
    PROMPT_USER_TO(Conjugate)
    PROMPT_USER_TO(Add)
    PROMPT_USER_TO(Subtract)
    PROMPT_USER_TO(Multiply)
    PROMPT_USER_TO(Divide)
    printf("%d. Exit Program\n", Exit);
    scanf("%d", &input);
    return input;
}

// DO NOT CHANGE THIS FUNCTION
void executeMenuItem(int menuItem){
    Complex c = {0,0};  
    static Complex c0 = {0,0}, c1 = {0,0}, cResult = {0,0};
 
    switch (menuItem) {

         case Exit: break; 

         case Load:
            if (chooseComplexNumberTo("load"))
               c1 = loadComplex();
            else
               c0 = loadComplex();
            break;

         case Display:
            c = chooseComplexNumberTo("display")?c1:c0;
            display(c);
            break;  

         case Move:
            c = chooseComplexNumberTo("Move")?(c1 = moveComplex(cResult)):(c0 = moveComplex(cResult));
            break; 

         case Conjugate:
            c = chooseComplexNumberTo("Conjugate")?(c1 = complexConjugate(c1)):(c0 = complexConjugate(c0));
            break;

         case Add:
            cResult = add(c1, c0); 
            display(cResult);
            break;      

         case Subtract:
            cResult = subtract(c1, c0); 
            display(cResult);
            break;

         case Multiply:
            cResult = multiply(c1, c0); 
            display(cResult);
            break;

         case Divide:
            cResult = divide(c1, c0); 
            display(cResult);
            break;        

         default:
            printf("Bad menu value entered; ");
      }
      printf("\n");
}

// DO NOT CHANGE THIS FUNCTION
Complex loadComplex(){
   Complex cTemp;
   printf("\tEnter the real component : ");
   scanf("%lf", &cTemp.real);

   printf("\tEnter the imaginary component : ");
   scanf("%lf", &cTemp.imag);
   printf("\n");
   return cTemp;
}

// DO NOT CHANGE THIS FUNCTION
int chooseComplexNumberTo(char* operation){
    int choice = 0;
    printf("\nWhich complex number do you wish to %s? (enter 0 or 1): ", operation);
    scanf("%d", &choice);
    return choice;
}

// TODO: add all additional funtions here, as specified above in the executeMenuItem() method.

char display(Complex result){
   if (result.                              imag < 0){
      printf("%.2lf - %.2lfi\n", result.real, (-1 * result.imag));
   }else{
      printf("%.2lf + %.2lfi\n", result.real, result.imag);
   }
}


Complex complexConjugate(Complex c){
   Complex result;
   result.real = c.real;
   result.imag = -1 * c.imag;
   display(result);
   return result;
}

Complex add(Complex c1, Complex c0) {
   Complex result;
   result.real = c1.real + c0.real;
   result.imag = c1.imag + c0.imag;
   return result;
}

Complex subtract(Complex c1, Complex c0) {
   Complex result;
   result.real = c1.real - c0.real;
   result.imag = c1.imag - c0.imag;
   return result;
}

Complex divide(Complex c1, Complex c0) {
   Complex result;
   double denominator = (c0.real*c0.real) + (c0.imag*c0.imag);
   assert(denominator != 0 && "Denominator should not be zero");
   result.real = ((c0.real*c1.real) + (c1.imag*c0.imag))/denominator;
   result.imag = ((c0.real*c1.imag) - (c1.real*c0.imag))/denominator;
   return result;
}

Complex multiply(Complex c1, Complex c0) {
   Complex result;
   result.real = (c1.real*c0.real) - (c1.imag*c0.imag);
   result.imag = (c1.real*c0.imag) + (c0.real*c1.imag);
   return result;
}

Complex moveComplex(Complex c){
   Complex new;
   new.real = c.real;
   new.imag = c.imag;
   return new;
}