#include "matrix.h"
#include "complex.h"
#include <windows.h>
using namespace std;

double adou[9] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
int aint[9] = {1,2,3,4,5,6,7,8,9};
int aint1[16] ={1,1,-1,2,-1,-1,-4,1,2,4,-6,1,1,2,4,2}; 
long along[9] = {1,2,3,4,5,6,7,8,9};

int main()
{
	Matrix<int> mint(3, 3);
	Matrix<long> mlong(3, 3);
	Matrix<double> mdou(3, 3);
	Matrix<complex> mcom(3, 3);
	Matrix<int> mint1(4,4);
//	Matrix<int> m4(3, 3); m4 = a1;
//	Matrix<int> m5(3, 3); 
//    cin >> m1;// >> m2 >> m3 >> m4 ;
//    cout <<"转置前矩阵："<<"\n"<< m1;
//    m1.Transport(); //m1的单位矩阵  
//    cout <<"转置后矩阵:"<<"\n"<< m1;
    mint = aint;
    mlong = along;
    mdou = adou;
    mint1=aint1;

	cout << "int型矩阵" <<endl<< mint<< endl;
	cout << "long型矩阵"<<endl<< mlong <<endl;
	cout << "double型矩阵"<<endl<< mdou <<endl;
	cout << mint1<<endl;
    cout << mint1.det()<<endl;
//	Matrix<double> m100();
//	Matrix<int> m10(m1);
//	cout <<m10<<endl;

	double time=0;
    double counts=0;
    LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	Matrix<double> m1(3, 3);
	m1 = adou;
	Matrix<double> m2(3, 3);
	m2 = adou;
	cout <<"---------矩阵的 + ------"<<endl;
	cout << "m1:\n";
	cout <<m1<<endl;
	cout << "m2:\n";
	cout << m2 << endl;
	QueryPerformanceCounter(&nBeginTime);//开始计时
	Matrix<double> m3(3,3);
	m3 = m1 + m2;
	QueryPerformanceCounter(&nEndTime);
	cout << " m3 = m1 + m2\n" ;
	cout << m3;

	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    cout<<"程序执行时间："<<time*1000<<"ms"<<endl;

	
	cout <<"---------矩阵的 += ------"<<endl;
	cout << "m1:\n";
	cout << m1;
	cout << "m2:\n";
	cout << m2 << endl;
	QueryPerformanceCounter(&nBeginTime);//开始计时
	 m1 += m2;
	QueryPerformanceCounter(&nEndTime);
	cout <<"m1 += m2:\n"<< m1 <<endl;

	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    cout<<"程序执行时间："<<time*1000<<"ms"<<endl;
    
	cout <<"---------矩阵的 - ------"<<endl;
	cout << "m1:\n";
	cout << m1;
	cout << "m2:\n";
	cout << m2 << endl;
	QueryPerformanceCounter(&nBeginTime);//开始计时
	Matrix<double> m4(3, 3);
	m4= m1 - m2;
	QueryPerformanceCounter(&nEndTime);
	cout << " m4 = m1 - m2\n" << m3 <<endl;

	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    cout<<"程序执行时间："<<time*1000<<"ms"<<endl;

	cout <<"---------矩阵的-=------"<<endl;
	cout << "m1:\n";
	cout << m1;
	cout << "m2:\n";
	cout << m2 << endl;
	QueryPerformanceCounter(&nBeginTime);//开始计时
	m1 -= m2;
	QueryPerformanceCounter(&nEndTime);
	cout << "m1 -= m2\n" << m1 <<endl;

	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为ms
    cout<<"程序执行时间："<<time*1000<<"ms"<<endl;
    
	cout <<"---------矩阵的*=------"<<endl;
	cout << "m1:\n";
	cout << m1;
	cout << "m2:\n";
	cout << m2 << endl;
	QueryPerformanceCounter(&nBeginTime);//开始计时
	m1 *= m2;
	QueryPerformanceCounter(&nEndTime);
	cout << "m1 *= m2\n" << m1 <<endl;

	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;//计算程序执行时间单位为ms
    cout<<"程序执行时间："<<time*1000<<"ms"<<endl;
	m1 = adou;
	 
	cout <<"---------矩阵的标准 * ------"<<endl;
	cout << "m1:\n";
	cout << m1;
	cout << "m2:\n";
	cout << m2 << endl;
	QueryPerformanceCounter(&nBeginTime);//开始计时
	Matrix<double> m5(3, 3);
	m5 = m1 * m2;
	QueryPerformanceCounter(&nEndTime);
	cout << " m5 = m1 * m2\n" << m5 <<endl;

	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    cout<<"程序执行时间："<<time*1000<<"ms"<<endl;
    /*
	cout <<"---------矩阵的标准 *错误版 ------"<<endl;
	cout << "m1:\n";
	cout << m1;
	cout << "m7:\n";
	cout << m7 << endl;
	QueryPerformanceCounter(&nBeginTime);//开始计时
	Matrix<double> m10(3 , 3);
	m10 = m1 * m7;
	QueryPerformanceCounter(&nEndTime);
	cout << " m10 = m1 * m7\n" << m10 <<endl;

	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    cout<<"程序执行时间："<<time*1000<<"ms"<<endl;
    
	cout <<"---------矩阵的代数 * ------"<<endl;
	cout << "m1:\n";
	cout << m1;
	QueryPerformanceCounter(&nBeginTime);//开始计时
	Matrix<double> m6(3, 3);
	m6 = m1 * 4;
	QueryPerformanceCounter(&nEndTime);
	cout << " m6 = m1 * 4\n" << m6 <<endl;

	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
    cout<<"程序执行时间："<<time*1000<<"ms"<<endl;
    
*/
	cout << "请输入18个数据,9组复数的实部虚部"<<endl; 
	cin >> mcom;
	cout << "complex型矩阵"<<endl<< mcom <<endl;


	return 0;
}

