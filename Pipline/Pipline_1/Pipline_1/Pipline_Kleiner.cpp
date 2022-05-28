//#include<stdio.h>
//#include<time.h>
//#include<windows.h>
//#include<stdlib.h>
//#include <mutex>
//#include<math.h>
//
//
//
//
////double Hilfe_1 = 0;
//
//HANDLE handle1, handle2, handle3, handle4;
//
//std::mutex mtx_FIFO_1;
//std::mutex mtx_FIFO_2;
//std::mutex mtx_FIFO_3;
//
//int Rund =900;
//double ergebnis[1000];
//
//
//
////struct _FIFO_1
////{
////	double Val_1[2] = { 0,0 };
////	int read_1 = 0;
////	int write_1 = 0;
////	int nochfrei = 2;
////
////}Fifo_1;
////
////struct _FIFO_2
////{
////	double Val_2[2] = { 0,0 };
////	int read_2 = 0;
////	int write_2 = 0;
////	int nochfrei = 2;
////}Fifo_2;
////
////struct _FIFO_3
////{
////	double Val_3[2] = { 0,0 };
////	int read_3 = 0;
////	int write_3 = 0;
////	int nochfrei = 2;
////}Fifo_3;
//
//struct _FIFO_1
//{
//	double Val_1[10] = {0,0,0,0,0,0,0,0,0,0};
//	int read_1 = 0 ;
//	int write_1 = 0;
//	int nochfrei = 10;
//
//}Fifo_1;
//
//struct _FIFO_2
//{
//	double Val_2[10] = { 0,0,0,0,0,0,0,0,0,0};
//	int read_2 = 0;
//	int write_2 = 0;
//	int nochfrei = 10;
//}Fifo_2;
//
//struct _FIFO_3
//{
//	double Val_3[10] = { 0,0,0,0,0,0,0,0,0,0};
//	int read_3 = 0;
//	int write_3 = 0;
//	int nochfrei = 10;
//}Fifo_3;
//
//
//int grenz = sizeof(Fifo_1.Val_1) / 8;
//int freigrenz = Fifo_1.nochfrei;
//
//
////int val = (rand() % 1000);
//
////Handle 1
//void WriteValInFifo_1(double val)
//{
//	if (Fifo_1.nochfrei != 0)  //说明队列中还有空位置
//	{
//		mtx_FIFO_1.lock();  // 上锁
//		if ((Fifo_1.write_1 != (grenz -1)) )
//		{
//			//mtx_FIFO_1.lock();  // 上锁
//			Fifo_1.Val_1[Fifo_1.write_1] = val;
//			Fifo_1.nochfrei--;
//			Fifo_1.write_1++;
//			//mtx_FIFO_1.unlock();
//		}
//		else
//		{
//			//mtx_FIFO_1.lock();  // 上锁
//			Fifo_1.Val_1[Fifo_1.write_1] = val;
//			Fifo_1.nochfrei--;
//			Fifo_1.write_1 = 0;
//			//mtx_FIFO_1.unlock();
//		}
//		mtx_FIFO_1.unlock();
//	}
//	else   // FIFO_1已满，暂停写入
//	{
//		printf("FIFO_1已满，等待数据被读取...\n");
//		while (Fifo_1.nochfrei == 0)
//		{
//			Sleep(1);
//		}
//
//		mtx_FIFO_1.lock();
//		printf("FIFO_1中的数据被读取，出现空位，继续执行\n");
//		if (Fifo_1.write_1 == (grenz - 1))
//		{
//			Fifo_1.Val_1[Fifo_1.write_1] = val;
//			Fifo_1.nochfrei--;
//			Fifo_1.write_1 = 0;
//		}
//		else
//		{
//			Fifo_1.Val_1[Fifo_1.write_1] = val;
//			Fifo_1.nochfrei--;
//			Fifo_1.write_1++;
//		}
//		mtx_FIFO_1.unlock();
//	}
//}
//
////Handle 2
//double ReadValInFifo_1()
//{
//	double val;
//	if (Fifo_1.nochfrei != freigrenz)
//	{
//		if (Fifo_1.read_1 != (grenz - 1))
//		{
//			mtx_FIFO_1.lock();
//			val = Fifo_1.Val_1[Fifo_1.read_1];
//			Fifo_1.nochfrei++;
//			Fifo_1.read_1++;
//			mtx_FIFO_1.unlock();
//			return val;
//		}
//		else
//		{
//			mtx_FIFO_1.lock();
//			val = Fifo_1.Val_1[Fifo_1.read_1];
//			Fifo_1.nochfrei++;
//			Fifo_1.read_1 = 0;
//			mtx_FIFO_1.unlock();
//			return val;
//		}
//	}
//	else  //FIFO_1已空，暂停读取
//	{
//		//mtx_FIFO_1.unlock(); //先开放Mutex
//		printf("FIFO_1已空，等待数据被加入...\n");
//		while (Fifo_1.nochfrei == freigrenz)
//		{
//			Sleep(1);
//		}
//		//SuspendThread(handle2);//暂停Funk_1，需要在Handle2中恢复运行
//		mtx_FIFO_1.lock();
//		printf("FIFO_1中加入了数据，继续执行读取\n");
//		if (Fifo_1.read_1 == (grenz - 1))
//		{
//			val = Fifo_1.Val_1[Fifo_1.read_1];
//			Fifo_1.nochfrei++;
//			Fifo_1.read_1 = 0;
//		}
//		else
//		{
//			val = Fifo_1.Val_1[Fifo_1.read_1];
//			Fifo_1.nochfrei++;
//			Fifo_1.read_1++;
//		}
//		mtx_FIFO_1.unlock();
//		return val;
//	}
//}
//
//void WriteValInFifo_2(double val)
//{
//	if (Fifo_2.nochfrei != 0)  //说明队列中还有空位置
//	{
//		if (Fifo_2.write_2 != (grenz - 1))
//		{
//			mtx_FIFO_2.lock();
//			Fifo_2.Val_2[Fifo_2.write_2] = val;
//			Fifo_2.nochfrei--;
//			Fifo_2.write_2++;
//			mtx_FIFO_2.unlock();
//		}
//		else
//		{
//			mtx_FIFO_2.lock();
//			Fifo_2.Val_2[Fifo_2.write_2] = val;
//			Fifo_2.nochfrei--;
//			Fifo_2.write_2 = 0;
//			mtx_FIFO_2.unlock();
//		}
//	}
//	else
//	{
//		//mtx_FIFO_2.unlock(); //先开放Mutex
//		printf("FIFO_2已满，等待数据被读取...\n");
//		while (Fifo_2.nochfrei == 0)
//		{
//			Sleep(1);
//		}
//		//SuspendThread(handle2);//暂停Funk_1，需要在Handle2中恢复运行
//		mtx_FIFO_2.lock();
//		printf("FIFO_2中的数据被读取，出现空位，继续执行\n");
//		if (Fifo_2.write_2 == (grenz - 1))
//		{
//			Fifo_2.Val_2[Fifo_2.write_2] = val;
//			Fifo_2.nochfrei--;
//			Fifo_2.write_2 = 0;
//		}
//		else
//		{
//			Fifo_2.Val_2[Fifo_2.write_2] = val;
//			Fifo_2.nochfrei--;
//			Fifo_2.write_2++;
//		}
//		mtx_FIFO_2.unlock();
//	}
//}
//
//
////Handle 3
//double ReadValInFifo_2()
//{
//	double val;
//	if (Fifo_2.nochfrei != freigrenz)
//	{
//		if (Fifo_2.read_2 != (grenz - 1))
//		{
//			mtx_FIFO_2.lock();
//			val = Fifo_2.Val_2[Fifo_2.read_2];
//			Fifo_2.nochfrei++;
//			Fifo_2.read_2++;
//			mtx_FIFO_2.unlock();
//			return val;
//
//		}
//		else
//		{
//			mtx_FIFO_2.lock();
//			val = Fifo_2.Val_2[Fifo_2.read_2];
//			Fifo_2.nochfrei++;
//			Fifo_2.read_2 = 0;
//			mtx_FIFO_2.unlock();
//			return val;
//		}
//	}
//	else  //FIFO_2已空，暂停读取
//	{
//		//mtx_FIFO_2.unlock(); //先开放Mutex
//		printf("FIFO_2已空，等待数据被加入...\n");
//		while (Fifo_2.nochfrei == freigrenz)
//		{
//			Sleep(1);
//		}
//		//SuspendThread(handle2);//暂停Funk_2，需要在Handle中恢复运行
//		mtx_FIFO_2.lock();
//		printf("FIFO_2中加入了数据，继续执行读取\n");
//		if (Fifo_2.read_2 == (grenz - 1))
//		{		
//			val = Fifo_2.Val_2[Fifo_2.read_2];		
//			Fifo_2.nochfrei++;
//			Fifo_2.read_2 = 0;
//		}
//		else
//		{
//			val = Fifo_2.Val_2[Fifo_2.read_2];
//			Fifo_2.nochfrei++;
//			Fifo_2.read_2++;
//		}		
//		mtx_FIFO_2.unlock();
//		return val;
//	}
//}
//
//void WriteValInFifo_3(double val)
//{
//	if (Fifo_3.nochfrei != 0)  //说明队列中还有空位置
//	{
//		if (Fifo_3.write_3 != (grenz - 1))
//		{
//			mtx_FIFO_3.lock();
//			Fifo_3.Val_3[Fifo_3.write_3] = val;
//			Fifo_3.nochfrei--;
//			Fifo_3.write_3++;
//			mtx_FIFO_3.unlock();
//		}
//		else
//		{
//			mtx_FIFO_3.lock();
//			Fifo_3.Val_3[Fifo_3.write_3] = val;
//			Fifo_3.nochfrei--;
//			Fifo_3.write_3 = 0;
//			mtx_FIFO_3.unlock();
//		}
//	}
//	else
//	{
//		//mtx_FIFO_3.unlock(); //先开放Mutex
//		printf("FIFO_3已满，等待数据被读取...\n");
//		while (Fifo_3.nochfrei == 0)
//		{
//			Sleep(1);
//		}
//		//SuspendThread(handle3);//暂停Funk_1，需要在Handle2中恢复运行
//		mtx_FIFO_3.lock();
//		printf("FIFO_3中的数据被读取，出现空位，继续执行\n");
//		if (Fifo_3.write_3 == (grenz - 1))
//		{
//			Fifo_3.Val_3[Fifo_3.write_3] = val;
//			Fifo_3.nochfrei--;
//			Fifo_3.write_3 = 0;
//		}
//		else
//		{
//			Fifo_3.Val_3[Fifo_3.write_3] = val;
//			Fifo_3.nochfrei--;
//			Fifo_3.write_3++;
//		}
//		mtx_FIFO_3.unlock();
//	}
//}
//
////Handle 4
//double ReadValInFifo_3()
//{
//	double val;
//	if (Fifo_3.nochfrei != freigrenz)   // 表示FIFO_3中有数据，不为空
//	{
//		if (Fifo_3.read_3 != (grenz - 1))
//		{
//			mtx_FIFO_3.lock();
//			val = Fifo_3.Val_3[Fifo_3.read_3];
//			Fifo_3.nochfrei++;
//			Fifo_3.read_3++;
//			mtx_FIFO_3.unlock();
//			return val;
//
//		}
//		else
//		{
//			mtx_FIFO_3.lock();
//			val = Fifo_3.Val_3[Fifo_3.read_3];
//			Fifo_3.nochfrei++;
//			Fifo_3.read_3 = 0;
//			mtx_FIFO_3.unlock();
//			return val;
//		}
//	}
//	else  //FIFO_2已空，暂停读取
//	{
//		//mtx_FIFO_3.unlock(); //先开放Mutex
//		printf("FIFO_3已空，等待数据被加入...\n");
//		while (Fifo_3.nochfrei == freigrenz)
//		{
//			Sleep(1);
//		}
//		//SuspendThread(handle4);//暂停Funk_2，需要在Handle中恢复运行
//		mtx_FIFO_3.lock();
//		printf("FIFO_3中加入了数据，继续执行读取\n");
//		//Fifo_3.read_3++;
//		if (Fifo_3.read_3 == (grenz - 1))
//		{
//			val = Fifo_3.Val_3[Fifo_3.read_3];
//			Fifo_3.nochfrei++;
//			Fifo_3.read_3 = 0;
//		}
//		else
//		{
//			val = Fifo_3.Val_3[Fifo_3.read_3];
//			Fifo_3.nochfrei++;
//			Fifo_3.read_3++;
//		}
//		mtx_FIFO_3.unlock();
//		return val;
//	}
//}
//
//void Funk_1()
//{
//
//	for (int i = 0; i < Rund; i++)
//	{
//		//Sleep(rand() % 5);
//
//		//double val = (rand() % 1000);
//		double val = i + 1;
//		printf("现在是第%d次向FIFO_1写入,写入的值是%f\n", (i + 1),val);
//		WriteValInFifo_1(val);
//	}
//}
//
//void Funk_2()
//{
//	//Sleep(2);
//	for (int i = 0; i < Rund; i++)
//	{
//		printf("现在是第%d次从FIFO_1中读出,", (i + 1));
//		//double Val_From_FIFO_1 = sqrt(sin(ReadValInFifo_1()) + (rand() % 50));
//		double Val_From_FIFO_1 = ReadValInFifo_1() + 1;
//		printf("读出的值是%f\n", Val_From_FIFO_1-1);
//		printf("现在是第%d次向FIFO_2写入,写入的值是%f\n", (i + 1), Val_From_FIFO_1);
//		WriteValInFifo_2(Val_From_FIFO_1);
//	}
//}
//
//void Funk_3()
//{
//	//Sleep(3);
//	for (int i = 0; i < Rund; i++)
//	{
//		printf("现在是第%d次从FIFO_2中读出,", (i + 1));
//		//double Val_From_FIFO_2 = log10(sqrt(ReadValInFifo_2()));
//		double Val_From_FIFO_2 = ReadValInFifo_2() + 1;
//		printf("读出的值是%f\n", Val_From_FIFO_2-1);
//		printf("现在是第%d次向FIFO_3写入，写入的值是%f\n", (i + 1),Val_From_FIFO_2);
//		WriteValInFifo_3(Val_From_FIFO_2);
//	}
//}
//
//void Funk_4()
//{
//	//Sleep(4);
//	for (int i = 0; i < Rund; i++)
//	{
//		printf("现在是第%d次从FIFO_3中读出,", (i + 1));
//		//double Val_From_FIFO_3 = (ReadValInFifo_3() + (rand() % 25));
//		double Val_From_FIFO_3 = ReadValInFifo_3() + 1;
//		printf("读出的值是%f\n", Val_From_FIFO_3 -1);
//		ergebnis[i] = Val_From_FIFO_3;
//		printf("第%d个最终结果是%f\n", (i + 1), Val_From_FIFO_3);
//	}
//}
//
//int main()
//{
//	handle1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Funk_1, NULL, NULL, NULL);
//	handle2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Funk_2, NULL, NULL, NULL);
//	handle3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Funk_3, NULL, NULL, NULL);
//	handle4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Funk_4, NULL, NULL, NULL);
//
//	WaitForSingleObject(handle1, 5000);
//	WaitForSingleObject(handle2, 5000);
//	WaitForSingleObject(handle3, 5000);
//	WaitForSingleObject(handle4, 5000);
//
//		for (int i = 0; i < Rund; i++)
//		{
//			if(i>=1)
//			{ 
//				if (((int(ergebnis[i]) - int(ergebnis[i - 1]))) != 1)
//				{
//					printf("第%d个结果是%d,有问题\n", (i + 1), int(ergebnis[i]));
//	
//				}
//				else
//				{
//					printf("第%d个结果是%d\n", (i + 1), int(ergebnis[i]));
//				}
//	
//			}
//			else
//			{
//				printf("第%d个结果是%d\n", (i + 1), int(ergebnis[i]));
//			}
//		}
//
//
//	//return 0;
//}