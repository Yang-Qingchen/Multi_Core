//#include<stdio.h>
//#include<iostream>
//#include<thread>
//#include<time.h>
//#include<Windows.h>
//
//
//clock_t start;
//clock_t end;
//int a = 0;
//int b = 0;
//
//int Wurfel_1[100][100][100];
//int Wurfel_2[100][100][100];
//
////Array Definition
//void Array_Definieren(int LeerArray[100][100][100])
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 0; c < 100; c++)
//			{
//				LeerArray[a][b][c] = 1;
//			}
//		}
//	}
//}
//
//// One Thread
//void Werte_Uberweisen_1_2()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 0; c < 100; c++)
//			{
//				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
//			}
//		}
//	}
//}
//void Werte_Uberweisen_2_1()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 0; c < 100; c++)
//			{
//				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
//			}
//		}
//	}
//}
//
//
//
//void One_Thread ()
//{
//	Array_Definieren(Wurfel_1);	
//	start = clock();   // timer On
//	for(int a=0;a<1000;a++)
//	{
//		Werte_Uberweisen_1_2();
//	    Werte_Uberweisen_2_1();
//	}
//	end = clock(); //timer Off
//	int duration = end - start;  //ms
//	std::cout << "单线程使用时间" << duration <<"毫秒" << std::endl;
//}
//
////Multi Thread
//
//// von 1 zur 2  4 Teilen
//void Werte_Uberweisen_1_2_1()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 0; c < 25; c++)
//			{
//				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
//			}
//		}
//	}
//}
//void Werte_Uberweisen_1_2_2()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 25; c < 50; c++)
//			{
//				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
//			}
//		}
//	}
//}
//void Werte_Uberweisen_1_2_3()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 50; c < 75; c++)
//			{
//				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
//			}
//		}
//	}
//}
//void Werte_Uberweisen_1_2_4()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 75; c < 100; c++)
//			{
//				Wurfel_2[a][b][c] = Wurfel_1[a][b][c] + 1;
//			}
//		}
//	}
//}
//
//
//// von 2 zur 1  4 Teilen
//void Werte_Uberweisen_2_1_1()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 0; c < 25; c++)
//			{
//				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
//			}
//		}
//	}
//}
//void Werte_Uberweisen_2_1_2()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 25; c < 50; c++)
//			{
//				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
//			}
//		}
//	}
//}
//void Werte_Uberweisen_2_1_3()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 50; c < 75; c++)
//			{
//				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
//			}
//		}
//	}
//}
//void Werte_Uberweisen_2_1_4()
//{
//	for (int a = 0; a < 100; a++)
//	{
//		for (int b = 0; b < 100; b++)
//		{
//			for (int c = 75; c < 100; c++)
//			{
//				Wurfel_1[a][b][c] = Wurfel_2[a][b][c] + 2;
//			}
//		}
//	}
//}
//
//
//
////Aufgabe des Threads
//void Aufteilung_1()
//{
//	for (int a = 0; a < 1000; a++)
//	{
//		Werte_Uberweisen_1_2_1();
//		Werte_Uberweisen_2_1_1();
//	}
//}
//void Aufteilung_2()
//{
//	for (int a = 0; a < 1000; a++)
//	{
//		Werte_Uberweisen_1_2_2();
//		Werte_Uberweisen_2_1_2();
//	}
//}
//void Aufteilung_3()
//{
//	for (int a = 0; a < 1000; a++)
//	{
//		Werte_Uberweisen_1_2_3();
//		Werte_Uberweisen_2_1_3();
//	}
//}
//void Aufteilung_4()
//{
//	for (int a = 0; a < 1000; a++)
//	{
//		Werte_Uberweisen_1_2_4();
//		Werte_Uberweisen_2_1_4();
//	}
//}
//
//
//void Aufteilung_1_()
//{
//		Werte_Uberweisen_1_2_1();
//		Werte_Uberweisen_2_1_1();
//}
//
//void Aufteilung_2_()
//{
//		Werte_Uberweisen_1_2_2();
//		Werte_Uberweisen_2_1_2();
//}
//
//void Aufteilung_3_()
//{
//		Werte_Uberweisen_1_2_3();
//		Werte_Uberweisen_2_1_3();
//}
//
//void Aufteilung_4_()
//{
//		Werte_Uberweisen_1_2_4();
//		Werte_Uberweisen_2_1_4();
//}
//
//
//
//int main()
//{
//	One_Thread();
//
//	
//	
//	
//	Array_Definieren(Wurfel_1);
//	HANDLE handle1, handle2, handle3, handle4; //句柄
//
//
//	handle1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_1, NULL, 0, NULL);
//	handle2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_2, NULL, 0, NULL);
//	handle3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_3, NULL, 0, NULL);
//	handle4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_4, NULL, 0, NULL);
//
//
//    start = clock();   // timer On
//
//
//
//    WaitForSingleObject(handle1, 2000);
//	WaitForSingleObject(handle2, 2000);
//	WaitForSingleObject(handle3, 2000);
//	WaitForSingleObject(handle4, 2000);
//
//	end = clock(); //timer Off
//	int duration = end - start;  //ms
//	std::cout << "多线程使用时间" << duration << "毫秒" << std::endl;
//	
//	return 0;
//
//}


