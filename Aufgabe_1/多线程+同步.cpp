#include<stdio.h>
#include<iostream>
#include<thread>
#include<time.h>
#include<Windows.h>

HANDLE handle1, handle2, handle3, handle4; //���
clock_t start;
clock_t end;

bool is_Stoppen_1 = false;
bool K_1 = false;   //�Ƿ�ִ�е���1000��

bool is_Stoppen_2 = false;
bool K_2 = false;

bool is_Stoppen_3 = false;
bool K_3 = false;

bool is_Stoppen_4 = false;
bool K_4 = false;

int Wurfel_1[100][100][100];
int Wurfel_2[100][100][100];



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

// One Thread
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



void One_Thread()
{
	Array_Definieren(Wurfel_1);
	start = clock();   // timer On
	for (int a = 0; a < 1000; a++)
	{
		Werte_Uberweisen_1_2();
		Werte_Uberweisen_2_1();
	}
	end = clock(); //timer Off
	int duration = end - start;  //ms
	std::cout << "���߳�ʹ��ʱ��" << duration << "����" << std::endl;
}

//Multi Thread

// von 1 zur 2  4 Teilen
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


// von 2 zur 1  4 Teilen
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

	for (int a = 1; a <= 1000; a++)
	{		
		Werte_Uberweisen_1_2_1();
		Werte_Uberweisen_2_1_1();

		if (is_Stoppen_1 == false) 
		{
			is_Stoppen_1 = true;
			SuspendThread(handle1);
		}
		is_Stoppen_1 = false;
		if (a == 1000) { K_1 = true; }
	}
}
void Aufteilung_2()
{
	for (int a = 1; a <= 1000; a++)
	{
		Werte_Uberweisen_1_2_2();
		Werte_Uberweisen_2_1_2();

		if (is_Stoppen_2 == false)
		{
			is_Stoppen_2 = true;
			SuspendThread(handle2);
		}
		is_Stoppen_2 = false;
		if (a == 1000) { K_2 = true; }
	}
}
void Aufteilung_3()
{
	for (int a = 1; a <= 1000; a++)
	{
		Werte_Uberweisen_1_2_3();
		Werte_Uberweisen_2_1_3();
	
		if (is_Stoppen_3 == false)	
		{		
			is_Stoppen_3 = true;		
			SuspendThread(handle3);	
		}	
		is_Stoppen_3 = false;	
		if (a == 1000) { K_3 = true; }
	}

}
void Aufteilung_4()
{
	for (int a = 1; a <= 1000; a++)
	{
		Werte_Uberweisen_1_2_4();
		Werte_Uberweisen_2_1_4();
	
		if (is_Stoppen_4 == false)	
		{	
			is_Stoppen_4 = true;		
			SuspendThread(handle4);
		}
		is_Stoppen_4 = false;	
		if (a == 1000) { K_4 = true; }
	}

}








int main()
{
	One_Thread();


	

	Array_Definieren(Wurfel_1);


	//handle1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_1, NULL, 0, NULL);    //�����̲߳�ֱ�ӿ���
	//handle2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_2, NULL, 0, NULL);
	//handle3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_3, NULL, 0, NULL);
	//handle4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_4, NULL, 0, NULL);

	handle1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_1, NULL, CREATE_SUSPENDED, NULL);  //�����̲߳���ͣ����Ҫ��������ResumeThread����
	handle2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_2, NULL, CREATE_SUSPENDED, NULL);
	handle3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_3, NULL, CREATE_SUSPENDED, NULL);
	handle4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_4, NULL, CREATE_SUSPENDED, NULL);

	
	
	start = clock();   // timer On
	
	ResumeThread(handle1);  // ���øմ������߳̿�ʼ
	ResumeThread(handle2);
	ResumeThread(handle3);
	ResumeThread(handle4);
	
	while ((K_1 == false) && (K_2 ==false) && (K_3 == false) && (K_4 == false))
	{
		if ((is_Stoppen_1 == true) && (is_Stoppen_2 ==true) && (is_Stoppen_3 == true) && (is_Stoppen_4 == true))
		{
			if ((Wurfel_1[99][99][24] == Wurfel_1[99][99][49]) && (Wurfel_1[99][99][24] == Wurfel_1[99][99][74]) && (Wurfel_1[99][99][24] == Wurfel_1[99][99][99]))
			{
				//printf("���ǵ�һ���ֵ�%d\n", Wurfel_1[99][99][24]);			
			    //printf("���ǵڶ����ֵ�%d\n", Wurfel_1[99][99][49]);
				//printf("���ǵ������ֵ�%d\n", Wurfel_1[99][99][74]);
				//printf("���ǵ��Ĳ��ֵ�%d\n", Wurfel_1[99][99][99]);

			    ResumeThread(handle1);
				ResumeThread(handle2);
				ResumeThread(handle3);
				ResumeThread(handle4);
			}
			else if (min(min(Wurfel_1[99][99][24], Wurfel_1[99][99][49]), min(Wurfel_1[99][99][74], Wurfel_1[99][99][99])) == Wurfel_1[99][99][24])
			{
				ResumeThread(handle1);
			}
			else if(min(min(Wurfel_1[99][99][24], Wurfel_1[99][99][49]), min(Wurfel_1[99][99][74], Wurfel_1[99][99][99])) == Wurfel_1[99][99][49])
			{
				ResumeThread(handle2);
			}
			else if (min(min(Wurfel_1[99][99][24], Wurfel_1[99][99][49]), min(Wurfel_1[99][99][74], Wurfel_1[99][99][99])) == Wurfel_1[99][99][74])
			{
				ResumeThread(handle3);
			}
			else if(min(min(Wurfel_1[99][99][24], Wurfel_1[99][99][49]), min(Wurfel_1[99][99][74], Wurfel_1[99][99][99])) == Wurfel_1[99][99][99])
			{
				ResumeThread(handle4);
			}

		}
		
	}

	//printf("���ǵ�һ���ֵ����ս��%d\n", Wurfel_1[99][99][24]);
	//printf("���ǵڶ����ֵ����ս��%d\n", Wurfel_1[99][99][49]);
	//printf("���ǵ������ֵ����ս��%d\n", Wurfel_1[99][99][74]);
	//printf("���ǵ��Ĳ��ֵ����ս��%d\n", Wurfel_1[99][99][99]);

	end = clock(); //timer Off
	int duration = end - start;  //ms
	std::cout << "���߳�ʹ��ʱ��" << duration << "����" << std::endl;

	return 0;

}