#ifndef __MATRIX__
#define __MATRIX__
#include <cmath>
#include "complex.h"
#include <iostream>
#include <cstdlib>
using namespace std;
template<typename T>
class Matrix {

public:
	Matrix(int rows, int cols);
	Matrix<T>(int rows, int cols, T value);
	Matrix(const Matrix<T>&);
	Matrix<T>& operator =  (const Matrix<T>&);
	Matrix<T>& operator =  (T *);

	virtual ~Matrix();
	
	Matrix<T>& operator += (const Matrix<T>&);
	Matrix<T>  operator +  (const Matrix<T> &) const;
	Matrix<T>& operator -= (const Matrix<T>&);
	Matrix<T>  operator -  (const Matrix<T>&) const;
	Matrix<T>& operator *= (const Matrix<T>&);
	Matrix<T>  operator *  (const Matrix<T>& m) const;
	Matrix<T> operator *  (T);
//	Matrix<complex>& operator=(complex *);
	int row() const { return rows_num;} 
	int col() const { return cols_num;} 
	static Matrix<T> eye(T);//矩阵的单位矩阵 
	void swapRows(int a, int b);
	void Transport();//矩阵转置 
    T det(); //行列式 
    static Matrix<T> inv(Matrix<T>);//求矩阵的逆矩阵
    
	void input();
	void output() const;
	T Point(int i, int j) const;
private:
	int rows_num, cols_num;
	T **p;
	void initialize();



	friend istream& operator>>(istream& is, Matrix<T>& m){
		for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			is >> m.p[i][j];
		}
	}
	return is;
	}
	friend ostream& operator<<(ostream& os, const Matrix<T>& m){
		for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			os << m.p[i][j]<< " ";
		}
			os << endl;
		}
 		return os;
	}
	
	
};

#include "matrix.h"
#include "complex.h"
using namespace std; 
const double EPS = 1e-10;
template<class T> 
inline void 
Matrix<T>::initialize() 
{
	p = new T*[rows_num];
	for (int i = 0; i < rows_num; ++i) 
	{
		p[i] = new T[cols_num];
	}
}

//构造函数 
template <class T>
inline
Matrix<T>::Matrix(int rows, int cols)
: rows_num(rows), cols_num (cols)
{		
	initialize();
 }

//析构函数
template <class T>
Matrix<T>::~Matrix(){
		for (int i = 0; i < rows_num; ++i)
        {
			delete[] p[i];
  		}	
		delete[] p;
}; 
	
//声明一个值全部为value的矩阵
template <class T>
inline
Matrix<T>::Matrix(int rows, int cols, T value)
: rows_num(rows), cols_num(cols)
{
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = value;
		}
	}
}

//拷贝构造
template <class T>
inline 
Matrix<T>::Matrix(const Matrix<T>& m)
{
	rows_num = m.rows_num;
	cols_num = m.cols_num;
	initialize();
	
 
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}
} 

//Matrix拷贝赋值 
template <class T>
inline Matrix<T>& 
Matrix<T>::operator = (const Matrix<T>& m)
{
	if (this == &m) {
		return *this;
	}
 
	if (rows_num != m.rows_num || cols_num != m.cols_num) {
		for (int i = 0; i < rows_num; ++i) {
			delete[] p[i];
		}
		delete[] p;
 
		rows_num = m.rows_num;
		cols_num = m.cols_num;
		initialize();
	}
 
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}
	return *this;
}

//数组赋值 
template <class T>
inline Matrix<T>& 
Matrix<T>::operator=(T *a){

	for(int i=0;i<rows_num;i++){
		for(int j=0;j<cols_num;j++){
			p[i][j]= *(a+i*cols_num+j);
		}
	}
	return *this;
}
/*
inline Matrix<complex>& 
Matrix<complex>::operator=(complex *a){

	for(int i=0;i<rows_num;i++){
		for(int j=0;j<cols_num;j+=2){
			p[i][j].re= *(a+i*2*cols_num+j);
			p[i][j].im= *(a+i*2*cols_num+j+1);
		}
	}
	return *this;
}
*/
//+=操作
template <class T>
inline Matrix<T>& 
Matrix<T>::operator+=(const Matrix<T>& m)
{
	if(this->rows_num != m.rows_num||this->cols_num != m.cols_num)
	{
		cout << "rows != cols不能计算" <<endl; 
	}
		for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] += m.p[i][j];
		}
	}
	return *this;	
		
}

//实现 + 
template <class T>
inline Matrix<T> 
Matrix<T>::operator + (const Matrix<T> &m) const{
	Matrix<T> M(rows_num, cols_num);
	for (int i = 0; i < M.rows_num; i++) {
		for (int j = 0; j < M.cols_num; j++) {
			M.p[i][j] = p[i][j]+m.p[i][j];
		}
	}
	return M;
}

//实现-=
template <class T>
inline Matrix<T>&
Matrix<T>::operator-=(const Matrix<T>& m)
{
		
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] -= m.p[i][j];
		}
	}
	return *this;
}

//实现-
template <class T>
inline Matrix<T>
Matrix<T>::operator-(const Matrix<T>& m)const 
{
	Matrix<T> M(rows_num, cols_num);
	for (int i = 0; i < M.rows_num; i++) {
		for (int j = 0; j < M.cols_num; j++) {
			M.p[i][j] = p[i][j] - m.p[i][j];
		}
	}
	return M;
} 

//实现*=
template <class T>
inline Matrix<T>& 
Matrix<T>::operator*=(const Matrix<T>& m)
{
		 
	Matrix<T> temp(rows_num, m.cols_num);//若C=AB,则矩阵C的行数等于矩阵A的行数，C的列数等于B的列数。
	for (int i = 0; i < temp.rows_num; i++) {
		for (int j = 0; j < temp.cols_num; j++) {
			for (int k = 0; k < cols_num; k++) {
				temp.p[i][j] += (p[i][k] * m.p[k][j]);
			}
		}
	}
	*this = temp;
	return *this;
}

//实现矩阵的代数乘法 
template <class T>
inline Matrix<T>
Matrix<T>::operator * (T x){
	Matrix<T> temp(rows_num, cols_num);
	for(int i = 0; i < rows_num; i++){
		for(int j = 0; j < cols_num; j++){
			
			temp.p[i][j] = x*p[i][j];
		}
	}
	return temp;
}

//实现矩阵的标准乘
template <class T>
inline Matrix<T> 
Matrix<T>::operator * (const Matrix<T> & m) const {
	//if(rows_num != m.cols_num) return Matrix<T>();
	//如果A的行不等于B的列不能进行运算 
	Matrix<T> temp(rows_num,m.cols_num);
		for(int i = 0; i < rows_num; i++ ){
		for(int j = 0; j < m.cols_num; j++ ){
		for(int	k = 0; k < cols_num; k++){
			temp.p[i][j] += (p[i][k] * m.p[k][j]);
			}
		}
	}
	return temp;
}

//返回矩阵第i行第j列的数 
template <class T>
T Matrix<T>::Point(int i, int j) const{
	return this->p[i][j];
}
  
//计算矩阵行列式的值
template <class T> 
T Matrix<T>::det() {
	//为计算行列式做一个备份
	T ** back_up;
	back_up = new T *[rows_num];
	for (int i = 0; i < rows_num; i++) {
		back_up[i] = new T[cols_num];
	}
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			back_up[i][j] = p[i][j];
		}
	}
	
	if (rows_num != cols_num) {
		std::abort();//只有方阵才能计算行列式，否则调用中断强制停止程序
	}
	T ans = 1;
	for (int i = 0; i < rows_num; i++) {
		//通过行变化的形式，使得矩阵对角线上的主元素不为0
		if (abs(p[i][i]) <= EPS) {
			bool flag = false;
			for (int j = 0; (j < cols_num) && (!flag); j++) {
				//若矩阵的一个对角线上的元素接近于0且能够通过行变换使得矩阵对角线上的元素不为0
				if ((abs(p[i][j]) > EPS) && (abs(p[j][i]) > EPS)) {
					flag = true;
					//注：进行互换后,p[i][j]变为p[j][j]，p[j][i]变为p[i][i]
					//对矩阵进行行变换
					T temp;
					for (int k = 0; k < cols_num; k++) {
						temp = p[i][k];
						p[i][k] = p[j][k];
						p[j][k] = temp;
					}
				}
			}
			if (flag)
				return 0;
		}
	}
	for (int i = 0; i < rows_num; i++) {
		for (int j = i + 1; j < rows_num; j++) {
			for (int k = i + 1; k < cols_num; k++) {
				p[j][k] -= p[i][k] * (p[j][i] * p[i][i]);
			}
		}
	}
	for (int i = 0; i < rows_num; i++) {
		ans *= p[i][i];
	}
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = back_up[i][j];
		}
	}
	return ans;
}

//实现行变换
template <class T>
void Matrix<T>::swapRows(int a, int b)
{
	a--;
	b--;
	double *temp = p[a];
	p[a] = p[b];
	p[b] = temp;
}

//矩阵转置 
template<class T>
void Matrix<T>::Transport()
{
	Matrix<T> temp(cols_num, rows_num);
	for (int i = 0; i < rows_num; i++)
	{
		for (int j = 0; j < cols_num; j++)
		{
			temp.p[j][i] = this->p[i][j];
		}
	}
	*this = temp;
	return;
} 

//制造一个单位矩阵
template <class T>
inline Matrix<T> 
Matrix<T>::eye(T n){
	Matrix<T> A(n,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				A.p[i][j]=1;
			}else{
				A.p[i][j]=0;
			}
		}
	}
	return A;
}

//矩阵显示
template <class T>
inline void 
Matrix<T>::output() const {

	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template <class T>
inline void 
Matrix<T>::input(){

	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			cin>> p[i][j];
		}
	}
}

#endif
