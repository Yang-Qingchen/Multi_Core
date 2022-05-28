//#include<stdio.h>
//#include<iostream>
//#include<thread>
//#include<time.h>
//#include<Windows.h>
//
//HANDLE handle1, handle2, handle3, handle4; 
//clock_t start;
//clock_t end;
//
//bool is_Stoppen_1 = false;  //Bool Signal für Thread 1. Es prüft,ob diese Thread gestoppt wird oder nicht
//bool K_1 = false;   //Bool Signal für Thread 1. Es prüft,ob 1000 mal erreicht oder nicht. Default ist False
//
//bool is_Stoppen_2 = false;  //Bool Signal für Thread 2. Es prüft,ob diese Thread gestoppt wird oder nicht
//bool K_2 = false;   //Bool Signal für Thread 2. Es prüft,ob 1000 mal erreicht oder nicht. Default ist False
//
//bool is_Stoppen_3 = false;  //Bool Signal für Thread 3. Es prüft,ob diese Thread gestoppt wird oder nicht
//bool K_3 = false;  //Bool Signal für Thread 3. Es prüft,ob 1000 mal erreicht oder nicht. Default ist False
//
//bool is_Stoppen_4 = false;   //Bool Signal für Thread 4. Es prüft,ob diese Thread gestoppt wird oder nicht
//bool K_4 = false;  //Bool Signal für Thread 4. Es prüft,ob 1000 mal erreicht oder nicht. Default ist False
//
//
//int Wurfel_1[100][100][100];    
//int Wurfel_2[100][100][100];
//
//
//
////Array Definition.alle Elemente in Wurfel 1 werden hier als 1 definiert.
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
//
//// One Thread
//// Alle Aufgabe wird von eine Thread verarbeitet. Dient nur für Verleich(z.B Zeitaufwand). 
//// Alle Werte von Würfel 1 nach Würfel 2 übergeben und dann von Würfel 2 nach Würfel 1 übergeben, wird als 1 mal gerechnet. Insgesamt soll 1000 mal sein.
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
////In diese Funktion rufe andere Funktion an und zählt die Zeit.
//void One_Thread()
//{
//	Array_Definieren(Wurfel_1);
//	start = clock();   // timer On
//	for (int a = 0; a < 1000; a++)
//	{
//		Werte_Uberweisen_1_2();
//		Werte_Uberweisen_2_1();
//	}
//	end = clock(); //timer Off
//	int duration = end - start;  //ms
//	std::cout << "Zeitaufwand von einer Thread " << duration << " ms" << std::endl;
//}
//
//
//
////Multi Thread
//
//// von Würfel 1 nach Würfel 2. Die Aufgabe wird in 4 Teilen geteilt.
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
//// von Würfel 2 nach Würfel 1.  Die Aufgabe wird in 4 Teilen geteilt.
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
//
///*Die Logik : nach jede Wertüberweisung wird das Thread durch SuspendThread gestoppt.Dann wird in Main() prüfen, ob jede Thread die Aufgabe einmal fertig ist oder nicht
//In meine Fall ist so, weil alle Element in Würfel 1 gleich 1 sind und die Ändern immer gleich sind(von Würfel 1 nach Würfel 2 muss +1 und umgekehrt +2), ist es günstig, immer 
//letzte Element in einer Teil zu prüfen( Würfel[99][[99][24] und Würfel[99][[99][49] und Würfel[99][[99][74] und Würfel[99][[99][99] ). Wenn sie alle gleich sind, könnte mann 
//sagen, dass alle Thread synchronisiert sind.(Diese Prüfensverfahren passt nur meine Fall.) Wenn alle Ergebinsse gleich sind, dann start alle Thread mit ResumThread weiter.
//Wenn nein, müssen andere Thread warten, bis langsamste Thread da ist(Das habe ich in Main geschrieben.).
//*/
//void Aufteilung_1()
//{
//
//	for (int a = 1; a <= 1000; a++)
//	{		
//		Werte_Uberweisen_1_2_1();  //Werte Überweisung
//		Werte_Uberweisen_2_1_1();  //Werte Überweisung
//
//		if (is_Stoppen_1 == false) 
//		{
//			is_Stoppen_1 = true;
//			SuspendThread(handle1);
//		}
//		is_Stoppen_1 = false;
//		if (a == 1000) { K_1 = true; }
//	}
//}
//void Aufteilung_2()
//{
//	for (int a = 1; a <= 1000; a++)
//	{
//		Werte_Uberweisen_1_2_2();
//		Werte_Uberweisen_2_1_2();
//
//		if (is_Stoppen_2 == false)
//		{
//			is_Stoppen_2 = true;
//			SuspendThread(handle2);
//		}
//		is_Stoppen_2 = false;
//		if (a == 1000) { K_2 = true; }
//	}
//}
//void Aufteilung_3()
//{
//	for (int a = 1; a <= 1000; a++)
//	{
//		Werte_Uberweisen_1_2_3();
//		Werte_Uberweisen_2_1_3();
//	
//		if (is_Stoppen_3 == false)	
//		{		
//			is_Stoppen_3 = true;		
//			SuspendThread(handle3);	
//		}	
//		is_Stoppen_3 = false;	
//		if (a == 1000) { K_3 = true; }
//	}
//
//}
//void Aufteilung_4()
//{
//	for (int a = 1; a <= 1000; a++)
//	{
//		Werte_Uberweisen_1_2_4();
//		Werte_Uberweisen_2_1_4();
//	
//		if (is_Stoppen_4 == false)	
//		{	
//			is_Stoppen_4 = true;		
//			SuspendThread(handle4);
//		}
//		is_Stoppen_4 = false;	
//		if (a == 1000) { K_4 = true; }
//	}
//
//}
//
//
//
//
//
//
//
//
//int main()
//{
//	One_Thread();
//
//	Array_Definieren(Wurfel_1);
//
//
//	handle1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_1, NULL, CREATE_SUSPENDED, NULL);  //创建线程并暂停，需要在下文用ResumeThread开启
//	handle2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_2, NULL, CREATE_SUSPENDED, NULL);
//	handle3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_3, NULL, CREATE_SUSPENDED, NULL);
//	handle4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Aufteilung_4, NULL, CREATE_SUSPENDED, NULL);
//
//	
//	
//	start = clock();   // timer On
//	
//	ResumeThread(handle1);  
//	ResumeThread(handle2);
//	ResumeThread(handle3);
//	ResumeThread(handle4);
//	
//	while ((K_1 == false) && (K_2 ==false) && (K_3 == false) && (K_4 == false))    //wenn 1000 mal noch nicht erreicht, machen immer Endlosschleife.
//	{
//		//wenn alle Thread gestoppt sind.
//		if ((is_Stoppen_1 == true) && (is_Stoppen_2 ==true) && (is_Stoppen_3 == true) && (is_Stoppen_4 == true))
//		{
//
//			if ((Wurfel_1[99][99][24] == Wurfel_1[99][99][49]) && (Wurfel_1[99][99][24] == Wurfel_1[99][99][74]) && (Wurfel_1[99][99][24] == Wurfel_1[99][99][99]))
//			{
//			    ResumeThread(handle1);
//				ResumeThread(handle2);
//				ResumeThread(handle3);
//				ResumeThread(handle4);
//			}
//			//Die langsamste Thread hat kleinste Wert.
//			else if ( min(min(Wurfel_1[99][99][24], Wurfel_1[99][99][49]), min(Wurfel_1[99][99][74], Wurfel_1[99][99][99]) ) == Wurfel_1[99][99][24])
//			{
//				ResumeThread(handle1);
//			}
//			else if(min(min(Wurfel_1[99][99][24], Wurfel_1[99][99][49]), min(Wurfel_1[99][99][74], Wurfel_1[99][99][99])) == Wurfel_1[99][99][49])
//			{
//				ResumeThread(handle2);
//			}
//			else if (min(min(Wurfel_1[99][99][24], Wurfel_1[99][99][49]), min(Wurfel_1[99][99][74], Wurfel_1[99][99][99])) == Wurfel_1[99][99][74])
//			{
//				ResumeThread(handle3);
//			}
//			else if(min(min(Wurfel_1[99][99][24], Wurfel_1[99][99][49]), min(Wurfel_1[99][99][74], Wurfel_1[99][99][99])) == Wurfel_1[99][99][99])
//			{
//				ResumeThread(handle4);
//			}
//
//		}
//		
//	}
//
//	//printf("这是第一部分的最终结果%d\n", Wurfel_1[99][99][24]);
//	//printf("这是第二部分的最终结果%d\n", Wurfel_1[99][99][49]);
//	//printf("这是第三部分的最终结果%d\n", Wurfel_1[99][99][74]);
//	//printf("这是第四部分的最终结果%d\n", Wurfel_1[99][99][99]);
//
//	end = clock(); //timer Off
//	int duration = end - start;  //ms
//	std::cout << "Zeitaufwand von Multi Thread " << duration << " ms" << std::endl;
//
//	return 0;
//
//}

