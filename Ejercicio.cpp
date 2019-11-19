#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double K=50.0;
const double M=2.0;
const double x=1.0;
const double v=0.0;

const double LAMBDA=1.0;
const double drag =0.2;
const double DeltaT=0.01;
double t_0=0.0;

double f0(double t, double y0, double y1); 
double f1(double t, double y0, double y1); 
void rk4(double t, double h, double & y0, double & y1); 

double f0(double t, double y0, double y1)
{
  return y1;
}

double f1(double t, double y0, double y1)
{
  return (-K/M)*LAMBDA-y1;
}

void rk(double t, double h, double & y0, double & y1)
{
  double y_10,y_11,y_20,y_21,y_30,y_31,y_40,y_41;
  y_10=h*f0(t,y0,y1);
  y_20=h*f0(t+h/2,y0+y_10/2,y1+y_11/2);
  y_30=h*f0(t+h/2,y0+y_20/2,y1+y_21/2);
  y_40=h*f0(t+h,y0+y_30,y1+y_31);
  y_11=h*f1(t,y0,y1);
  y_21=h*f1(t+h/2,y0+y_10/2,y1+y_11/2);
  y_31=h*f1(t+h/2,y0+y_20/2,y1+y_21/2);
  y_41=h*f1(t+h,y0+y_30,y1+y_31);
  y0=y0+(1.0/6.0)*(y_10+2*y_20+2*y_30+y_40);
  y1=y1+(1.0/6.0)*(y_11+2*y_21+2*y_31+y_41);
}

int main(void)
{
  double x,v,time;
  x=1;
  v=0;
  for(time = 0; time <= 10.0; time += DeltaT) {
      cout << time << "\t" << x << "\t" << v << endl;
      rk4(time, DeltaT, x, v);
  }
  return 0;
}