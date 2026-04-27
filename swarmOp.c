#include <stdio.h>
#include <math.h>
#include "alea.h"

#define XMAX 5.0 //No hay XMIN porque el espacio de busqeuda es equipolente o equiparable
#define D 5
#define TAMAENJ 30
#define W 0.8
#define C1 1.62
#define C2 1.62
#define EPOCHS 1000
#define EPSILON 1e-7

//Definicion de tipos de datos
typedef struct
{
  double x[D];
  double aptitud;
}posicion; //nombre de la estructura

typedef struct
{
  posicion actual;
  posicion mejor;
  double v[D];
}particula; //hello

double rastrigin(double *x)//Se pasa el inicio del arreglo
{
  double suma = 0;
  int i;
  
  for(i = 0; i < D; i++)
  {
    suma += x[i]*x[i] - 10.0 * cos(2.0*M_PI*x[i]) + 10;
  }
  
  return suma;
}

posicion inicializa(particula *enjambre)
{
  posicion mejor;
  int p, i; //particula, indice de particula
  inirndm();
  
  for(p = 0; p < TAMAENJ; p++)
  {
    for(i = 0; i < D; i++)
    {
      enjambre[p].actual.x[i] = XMAX*VNI;
      enjambre[p].v[i] = 0.0;
    }
    enjambre[p].actual.aptitud = rastrigin(enjambre[p].actual.x);
    enjambre[p].mejor = enjambre[p].actual;
    if(p == 0 || enjambre[p].mejor.aptitud < mejor.aptitud)
    {
      mejor = enjambre[p].mejor;
    }
  }
  return mejor;
}

//aceleracion por lotes, el algoritmo tarda mas iteraciones en converges, extremos locales, en linea cada particula se mueve y se calcula y todo individualmente, pero tiende más a quedarse estancado en extremos locales.
void aceleracion(particula *enjambre, posicion mejor)
{
    int p, i;
    for(p = 0;p < TAMAENJ; p++)
    {
		for(i = 0; i < D; i++)
		{
			  enjambre[p].v[i] = W * enjambre[p].v[i] + C1 * UNI * (enjambre[p].mejor.x[i] - enjambre[p].actual.x[i]) + C2 * UNI * (mejor.x[i] - enjambre[p].actual.x[i]);
			  //Validaciones de velocidad máxima
			  if(enjambre[p].v[i] > XMAX/2.0)
			  { 
				enjambre[p].v[i] = XMAX/2.0;
			  }
			  if(enjambre[p].v[i] < -XMAX/2.0)
			  {
				enjambre[p].v[i] = -XMAX/2.0;
			  }
		}
    }
}

posicion movimiento(particula *enjambre, posicion mejor)
{
    int p,i;
    for(p = 0; p < TAMAENJ; p++)
    {
      for(i=0; i<D; i++)
      {
        enjambre[p].actual.x[i] += enjambre[p].v[i];
        if(enjambre[p].actual.x[i] > XMAX)
        {
          enjambre[p].actual.x[i] = XMAX;
        }
        //Osea el otro lado del espacio, porque el espacio(de busqeuda) es un cuadradin
        if(enjambre[p].actual.x[i] < -XMAX)
        {
          enjambre[p].actual.x[i] = -XMAX;
        }
      }
      enjambre[p].actual.aptitud = rastrigin(enjambre[p].actual.x);
      if(enjambre[p].actual.aptitud < enjambre[p].mejor.aptitud) //problema minimizacion, ratrigin està definido como problema de mimizacion
      {
        enjambre[p].mejor = enjambre[p].actual;
        if(enjambre[p].mejor.aptitud < mejor.aptitud)
        {
          mejor = enjambre[p].mejor;
        }
      }
    }
    
    return mejor;
}

//MAAAIIIIN 
int main(int argc, char *argv[])
{ 
  //Declaraciones
  int i = 0;
  int epoch;
  posicion mejor;
  particula enjambre[TAMAENJ];
  
  mejor = inicializa(enjambre);
  
  
  for(epoch = 0; epoch < EPOCHS && mejor.aptitud > EPSILON; epoch++)
  {
    aceleracion(enjambre, mejor);
    mejor = movimiento(enjambre, mejor);
  }
  printf("Epoca: %d, f(x) %f \n", epoch,mejor.aptitud);
  for(int i = 0; i <D; i ++)
  {
	printf("x[%d] = %f\n",i+1,mejor.x[i]);
  }
  
  return 0;
}

