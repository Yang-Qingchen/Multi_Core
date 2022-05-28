#include <stdio.h>
#include <omp.h>


int main1()
{
  #pragma omp parallel 
  {
    printf("Thread %d sagt Hallo \n", omp_get_thread_num());
    if(omp_get_thread_num() == 0)
      printf("Es gibt %d Threads.\n", omp_get_num_threads()); 
  } 

}



int main2() 
{ 
  printf("Wie viele Threads sollen es sein?\n");
  int n;
  scanf_s("%d", &n);
  int a = 0;
  #pragma omp parallel num_threads(n) 
  { 
   // printf("Hallo ");
    //printf("Welt!\n"); 

     #pragma omp for
      for (int i = 0; i < 20; i++)
      {
          printf("现在进行到%d了,由线程%d执行的\n", i, omp_get_thread_num());
          a = a + i;
      }
  }
  printf("a的最终值为%d\n", a);
  //printf("Alle Threads haben Hallo gesagt."); 
}

int main3()
{ 
#pragma omp parallel
  { 
    printf("Thread %d sagt Hallo \n", omp_get_thread_num());
    #pragma omp master 
    {
      printf_s("Es gibt %d Threads.\n", omp_get_num_threads());
    }
    #pragma omp single
    {
      printf_s("Thread %d war hier.\n", omp_get_thread_num());
    }
    #pragma omp single
    {
      printf("Danach war Thread %d da.\n", omp_get_thread_num());
    }
  }
}

int main4() 
{ 
  #pragma omp parallel
  { 
    #pragma omp sections
    {
      
      {
        printf_s("Thread %d war hier.\n", 	omp_get_thread_num());
      } 
      
      #pragma omp section
      {
        printf("Aber hier war Thread %d.\n", 	omp_get_thread_num());
      }

      #pragma omp section
      {
        printf("und eine weitere section mit Thread %d.\n", omp_get_thread_num());
      }
    }
    printf("Thread %d sagt Tschuess \n", omp_get_thread_num()); 
  } 
}

double a_[128];
double b_[128];
int tnum[128];

void a1(int n, double* a, double* b)
{
  int i;
  for (i = 1; i < n; i++)
    a[i] = i;

#pragma omp parallel for
    for (i = 1; i < n; i++) /* i is private by default */
    {
      b[i] = (a[i] + a[i - 1]) / 2.0;
      tnum[i] = omp_get_thread_num();
    }

 #pragma omp parallel
  {
   // #pragma omp for collapse(2)
      #pragma omp for 
      for (int i = 0; i < 10; ++i) 
      {
        printf("AusserThreadNr: %d\n", omp_get_thread_num());
            // Dieses for ist ein ganz normales C/C++ for --wird durch Compiler ohne collapse abgelehnt
        //#pragma omp for 
          for (int j = 0; j < 10; ++j) 
          { 
            printf_s("%d*%d = %d InnerThreadNr: %d\n", i, j, i * j, omp_get_thread_num()); 
          }
      }
  }
}

int a ; 
int main5() 
{
    int b ;
  #pragma omp parallel
  { 
    int c=0;
    // a und b werden geteilt, jeder Thread hat sein eigenes c
    c += omp_get_thread_num();
    b += omp_get_thread_num();
    a += omp_get_thread_num();
    printf("a:%d b:%d c:%d ThreadNr: %d\n", a, b, c, omp_get_thread_num());
  }
}

int main6() 
{ 
  #pragma omp parallel for
  for (int i = 0; i < 10; ++i) 
  { 
    int n;
    #pragma omp critical
    { 
      printf_s("Geben sie eine Zahl ein: "); 
      scanf_s("%d",& n); 
    }
      printf_s("%d * %d = %d\n", i, n, i * n); 
  } 
}

int main7()
{
  int n;
  printf("Geben sie eine Ganzzahl ein: ");
  scanf_s("%d", &n);
  // Der Initialwert von is_prime ist wichtig, da dieser auch
  // in die Berechnung einbezogen wird.
  bool is_prime = true;
  int summe = 0;
#pragma omp parallel reduction(&&: is_prime) reduction(+:summe) 
  {
    // jeder bekommt sein eigenes is_prime,
    // welches mit true, dem neutralen Element von &&,
    // initialisiert wurde.
#pragma omp for 
    for (int i = 0; i < n; ++i)
    {
      summe += i;
      if ( i>2 && n % i == 0)
        is_prime = false;
      printf_s("Durchlauf %d summe %d\n",i, summe);
    }
    // Alle is_prime (auch das aus der main Funktion) werden
    // mittels && verkn黳ft. Im Klartext bedeutet dies, dass, 
    // falls eines false ist, das Resultat false ist.}
    if (is_prime)
      printf_s("%d ist prim summe = %d\n", n, summe);
    else
      printf_s("%d ist nicht prim summe = %d\n", n, summe);
  }
  if (is_prime)
    printf_s("Ergebnis ist prime summe = %d\n", summe);
  else
    printf_s("Ergebnis ist nicht prime summe = %d\n", summe);
}

int main8()
{
#pragma omp parallel
    {
        // #pragma omp for collapse(2)
#pragma omp for collapse(1)
        for (int i = 0; i < 5; i++)
        {
            //printf("AusserThreadNr: %d\n", omp_get_thread_num());
            printf("\n");
            printf("第一层循环，执行到第%d次了\n", (i + 1));
            printf("\n");


            for (int j = 0; j < 5; j++)
            {
               // printf_s("%d*%d = %d InnerThreadNr: %d\n", i, j, i * j, omp_get_thread_num());
                printf("\n");
                printf("第一层为%d，第二层循环，执行到第%d次了\n", (i + 1),(j + 1));
                printf("\n");
            
                for (int p = 0; p < 5; p++)
                {
                    // printf_s("%d*%d = %d InnerThreadNr: %d\n", i, j, i * j, omp_get_thread_num());
                    printf("第一层为%d，第二层为%d，第三层循环，执行到第%d次了\n", (i + 1), (j+ 1),(p + 1));
                }



            }

        }
    }
}

int main()
{
  //main1();
  //main2();
  //main3();
  //main4();
  //a1(128,a_,b_);
  //main5();
  //main6();
  //main7();
    main8();
}
