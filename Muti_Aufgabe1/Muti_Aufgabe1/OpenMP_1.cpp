#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<iostream>

int Wurfel_1[100][100][100];
int Wurfel_2[100][100][100];
clock_t start;
clock_t end;

//Array Definition
void Array_Definieren(int LeerArray[100][100][100])
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 0; c < 100; c++)
			{
				LeerArray[a][b][c] = 1;
			}
		}
	}
}

void Werte_Uberweisen_1_2()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 0; c < 100; c++)
			{
				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
			}
		}
	}
}
void Werte_Uberweisen_2_1()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 0; c < 100; c++)
			{
				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
			}
		}
	}
}

void Werte_Uberweisen_1_2_1()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 0; c < 25; c++)
			{
				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
			}
		}
	}
}
void Werte_Uberweisen_1_2_2()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 25; c < 50; c++)
			{
				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
			}
		}
	}
}
void Werte_Uberweisen_1_2_3()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 50; c < 75; c++)
			{
				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
			}
		}
	}
}
void Werte_Uberweisen_1_2_4()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 75; c < 100; c++)
			{
				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
			}
		}
	}
}

void Werte_Uberweisen_2_1_1()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 0; c < 25; c++)
			{
				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
			}
		}
	}
}
void Werte_Uberweisen_2_1_2()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 25; c < 50; c++)
			{
				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
			}
		}
	}
}
void Werte_Uberweisen_2_1_3()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 50; c < 75; c++)
			{
				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
			}
		}
	}
}
void Werte_Uberweisen_2_1_4()
{
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 75; c < 100; c++)
			{
				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
			}
		}
	}
}


//Aufgabe des Threads
void Aufteilung_1()
{
	for (int a = 0; a < 1000; a++)
	{
		Werte_Uberweisen_1_2_1();
		Werte_Uberweisen_2_1_1();
	}
}
void Aufteilung_2()
{
	for (int a = 0; a < 1000; a++)
	{
		Werte_Uberweisen_1_2_2();
		Werte_Uberweisen_2_1_2();
	}
}
void Aufteilung_3()
{
	for (int a = 0; a < 1000; a++)
	{
		Werte_Uberweisen_1_2_3();
		Werte_Uberweisen_2_1_3();
	}
}
void Aufteilung_4()
{
	for (int a = 0; a < 1000; a++)
	{
		Werte_Uberweisen_1_2_4();
		Werte_Uberweisen_2_1_4();
	}
}


int MutiThread_1()     //�������sections��ÿ��С��������һ��Section
{
	Array_Definieren(Wurfel_1);

	start = clock();

    #pragma omp parallel
	  {
		#pragma omp sections
		  {
			  Aufteilung_1();

              #pragma omp section
			  {
				  Aufteilung_2();
			  }
              #pragma omp section
			  {
				  Aufteilung_3();
			  }
              #pragma omp section
			  {
				  Aufteilung_4();
			  }

		  }
	  }
	  end = clock();

	  int duration = end - start;  //ms
	  std::cout << "���߳�ʹ��ʱ��" << duration << "����" << std::endl;

	  printf("���ս����%d\n", Wurfel_1[99][99][99]);
}

/*
int MutiThread_2()  
{
	Array_Definieren(Wurfel_1);
	int summe = 0;

	printf("Wie viele Threads sollen es sein?\n");
	int n;
	scanf_s("%d", &n);

    start = clock();

#pragma omp parallel num_threads(n) 
	{

     //  #pragma omp for ordered 
	  #pragma omp for  ordered
		//for (int i = 0; i < 10000000; i++)
	    for (int i = 0; i < 1000; i++)
		{

			//Werte_Uberweisen_1_2();
	  //      Werte_Uberweisen_2_1(); 
	  //      printf("������%d�εĽ����%d,���߳�%dִ�е�\n", (i + 1), Wurfel_1[99][99][99], omp_get_thread_num());
 
//#pragma omp atomic
			//summe++;
			
            
            //#pragma omp critical
			//{
			//	Werte_Uberweisen_1_2();
			//	Werte_Uberweisen_2_1();
			//	printf("������%d�εĽ����%d,���߳�%dִ�е�\n", (i + 1), Wurfel_1[99][99][99], omp_get_thread_num());
			//}
			

            #pragma omp ordered 
			{
			Werte_Uberweisen_1_2();
			Werte_Uberweisen_2_1();
			printf("������%d�εĽ����%d,���߳�%dִ�е�\n",(i+1), Wurfel_1[99][99][99],omp_get_thread_num());
            }

		}
		    
	}
	end = clock();

	int duration = end - start;  //ms
	std::cout << "���߳�ʹ��ʱ��" << duration << "����\n" << std::endl;
	
	printf("���ս����%d\n", Wurfel_1[99][99][99]);
	//printf("���ս����%d\n", summe);
}
*/

int MutiThread_3()
{
	Array_Definieren(Wurfel_1);
	printf("Wie viele Threads sollen es sein?\n");
	int n;
	scanf_s("%d", &n);

	start = clock();
#pragma omp parallel num_threads(n)
{	
        #pragma omp for	
		for (int loop = 0; loop < 1000; loop++)
		{
			for (int a = 0; a < 100; a++)
			{
				for (int b = 0; b < 100; b++)			
				{
					for (int c = 0; c < 100; c++)				
					{				
						Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;				
						Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;			
					}			
				}	
			}
	    }
}
	end = clock();

	int duration = end - start;  //ms
	std::cout << "���߳�ʹ��ʱ��" << duration << "����\n" << std::endl;
	printf("���ս����%d\n", Wurfel_1[99][99][99]);
}

int main()
{
	//MutiThread_1();	
	MutiThread_3();
}