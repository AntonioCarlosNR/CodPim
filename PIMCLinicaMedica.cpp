# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main (){
    int a,b,c,delta,d;
    float x1,x2;

   do{
    printf("A eq de Bhaskara eh formada por ax^2+bx+c\n");
    printf("Entre com o valor de a:");
    scanf("%d",&a);
    printf("Entre com o valor de b:");
    scanf("%d",&b);
    printf("Entre com o valor de c:");
    scanf("%d",&c);

    delta= (b*b)-(4*a*c);

    if(delta <0){
    printf("\nImpossivel calcular o delta %d menor que 0\n",delta);
    }
    else if (delta == 0){
    x1= -b/(2*a);
    printf("\nO delta eh 0 portanto so tem uma raiz = %f\n",x1);
    }
    else {
    x1=(-b + sqrt(delta))/2*a;
    x2=(-b - sqrt(delta))/2*a;
    printf("As rizes sao x1=%.2f e x2%.2f\n",x1,x2);
    }
    printf("deseja continuar?\nAperte qualquer numero positivo\nFinalizar programa 0: ");
    scanf("%d",&d);
   }while(d !=0);
   //teste
return 0;
}