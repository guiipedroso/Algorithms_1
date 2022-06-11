/*
  Title: Trabalho de Calculo Numerico
  Discente: Guilherme Pedroso
 
*/


/* 
 
 * 1 - Usando metodo da dicotomia encontre a raiz da função f(x) = x³-x²-1 precisao 4 casas decimais 
 
 * f(x) = x³-x²-1

 * intervalo n definido
 
*/

/* <Libraries> */
#include <stdio.h>
#include <math.h>

float
raizfunc
(float xa, float xb, float precisao)
  {
    float xa_intervalo, xb_intervalo,fxa_intervalo,fxb_intervalo;
    int resp = 0;

    /* Verificar intervalo f(a).f(b)<0 (teorema de Bolzano) */
    xa_intervalo = xa;
    xb_intervalo = xb;
    /* <definir a f intrvalo para realizar Bolzano> */
    fxa_intervalo = ((pow(xa_intervalo,3))-(pow(xa_intervalo,2))-1);
    fxb_intervalo = ((pow(xb_intervalo,3))-(pow(xb_intervalo,2))-1);

    if ((fxa_intervalo*fxb_intervalo) < 0)
      {
        printf("Existe pelo menos uma raiz!\n");
	getchar();
      }
    else
      {
        printf("Pode nao existir uma raiz dentro desse intervalo, altere intevalo:\n OBS: intervalo valido = f(comeco_intervalo)*f(final_intervalo) > 0\n");
	getchar();
      }

    /* Encontrar numero de interações até chegar na raiz, caso necessario o valor pode ser alterado, dependendo do nuemro de interacoes */
    float numintr;
    numintr=((log(xb-xa)-log(precisao))/log(2));
    printf("Numero de interacoes: %2.f\n\n",numintr);
  }

float
dicotomia(float xa, float xb, float precisao)
  {
     
    float xc, xc_anterior, f_xa, f_xb, f_xc, xa_inicial, xb_inicial,xa_intervalo, xb_intervalo,fxa_intervalo,fxb_intervalo;

    xa_inicial = xa;
    xb_inicial = xb;
  
    int iteracoes = 0;

    xc_anterior = xb;
    xc = xa;

    printf("i, xa, xb, xc, f(xa), f(xb), f(xc), f_xa * f_xc < 0.0, f_xb * f_xc < 0.0, |xc - xc_anterior|, precisao\n");
    while(fabs(xc - xc_anterior) > precisao)  
      {

      iteracoes++;

      xc_anterior = xc;

      xc = (xa + xb) / 2.0;
      f_xa = ((pow(xa,3))-(pow(xa,2))-1);
      f_xb = ((pow(xb,3))-(pow(xb,2))-1);
      f_xc = ((pow(xc,3))-(pow(xc,2))-1);
   
      printf("%d, %f, %f, %f, %f, %f, %f, %d, %d, %f, %f\n", iteracoes, xa, xb, xc, f_xa, f_xb, f_xc, ( f_xa * f_xc < 0.0 ), ( f_xb * f_xc < 0.0 ), fabs(xc - xc_anterior), precisao);

      if( f_xa * f_xc < 0.0)
        {
        xb = xc;
        }
      else
        {
        if( f_xb * f_xc < 0.0)
          {
          xa = xc;
          }
        }
      }

  return (xc);
  }

/* <MENU> */
int 
menu()
  {
  int ch;
  printf("\n------------  <DICOTOMIA> -> f(x) = x³-x²-1 | default: intervalo ]1.4 ; 1.5[, precisao 0.0001--------------");
  printf("\n\n1- Entrar com o intervalo e precisao\n");
  printf("2- Usar intervalo e precisao default\n");
  printf("3- Realizar dicotomia\n");
  printf("0- Sair\n");
  scanf("%d", &ch);
  return ch;
  }

int 
main()
  {
  float inter_a, inter_b, precisao;
  float raiz;
  int ch;
    do
      {
      ch=menu();
      
        switch (ch)
          {
          case 1:
            {		  
            printf("\nEntre com os intervalos e precisao: ");
            scanf ("%f%f%f", &inter_a, &inter_b, &precisao);
            printf("\n");
            raizfunc(inter_a,inter_b, precisao);
            break;
	    }
          case 2:
	    {
	    raiz = dicotomia(1.4, 1.5, 0.0001);
            printf("\nraiz = %f\n \n", raiz);
            ch = 0;
            break;
	    }
          case 3 :
	    {
            raiz = dicotomia(inter_a, inter_b, precisao);
            printf("\nraiz = %f\n \n", raiz);
	    }
           } 

    } while (ch != 0);
    return(0);
  } /* <end main> */
