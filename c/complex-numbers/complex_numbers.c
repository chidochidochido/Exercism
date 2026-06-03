#include <math.h>
#include "complex_numbers.h"

static double squareAbs(complex_t x)
{
   return pow(x.real, 2) + pow(x.imag, 2);
}

complex_t c_add(complex_t a, complex_t b)
{
   complex_t complexResult;

   complexResult.real = a.real + b.real;
   complexResult.imag = a.imag + b.imag;

   return complexResult;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t complexResult;

   complexResult.real = a.real - b.real;
   complexResult.imag = a.imag - b.imag;

   return complexResult;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t complexResult;

   complexResult.real = a.real * b.real - a.imag * b.imag;
   complexResult.imag = a.imag * b.real + a.real * b.imag;

   return complexResult;
}

complex_t c_div(complex_t a, complex_t b)
{
   complex_t complexResult;

   complexResult.real = (a.real * b.real + a.imag * b.imag) / squareAbs(b);
   complexResult.imag = (a.imag * b.real - a.real * b.imag) / squareAbs(b);

   return complexResult;
}

double c_abs(complex_t x)
{
   return sqrt(squareAbs(x));
}

complex_t c_conjugate(complex_t x)
{
   complex_t complexResult;

   complexResult.real = x.real;
   complexResult.imag = -1 * x.imag;

   return complexResult;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   complex_t complexResult;

   complexResult.real = exp(x.real) * cos(x.imag);
   complexResult.imag = exp(x.real) * sin(x.imag);

   return complexResult;
}
