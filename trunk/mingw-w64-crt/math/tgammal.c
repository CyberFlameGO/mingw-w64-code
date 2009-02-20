/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include "cephes_mconf.h"

/*
gamma(x+2)  = gamma(x+2) P(x)/Q(x)
0 <= x <= 1
Relative error
n=7, d=8
Peak error =  1.83e-20
Relative error spread =  8.4e-23
*/

#if UNK
static const long double P[8] = {
 4.212760487471622013093E-5L,
 4.542931960608009155600E-4L,
 4.092666828394035500949E-3L,
 2.385363243461108252554E-2L,
 1.113062816019361559013E-1L,
 3.629515436640239168939E-1L,
 8.378004301573126728826E-1L,
 1.000000000000000000009E0L,
};
static const long double Q[9] = {
-1.397148517476170440917E-5L,
 2.346584059160635244282E-4L,
-1.237799246653152231188E-3L,
-7.955933682494738320586E-4L,
 2.773706565840072979165E-2L,
-4.633887671244534213831E-2L,
-2.243510905670329164562E-1L,
 4.150160950588455434583E-1L,
 9.999999999999999999908E-1L,
};
#endif
#if IBMPC
static const unsigned short P[] = {
0x434a,0x3f22,0x2bda,0xb0b2,0x3ff0, XPD XPD_SHORT
0xf5aa,0xe82f,0x335b,0xee2e,0x3ff3, XPD XPD_SHORT
0xbe6c,0x3757,0xc717,0x861b,0x3ff7, XPD XPD_SHORT
0x7f43,0x5196,0xb166,0xc368,0x3ff9, XPD XPD_SHORT
0x9549,0x8eb5,0x8c3a,0xe3f4,0x3ffb, XPD XPD_SHORT
0x8d75,0x23af,0xc8e4,0xb9d4,0x3ffd, XPD XPD_SHORT
0x29cf,0x19b3,0x16c8,0xd67a,0x3ffe, XPD XPD_SHORT
0x0000,0x0000,0x0000,0x8000,0x3fff, XPD XPD_SHORT
};
static const unsigned short Q[] = {
0x5473,0x2de8,0x1268,0xea67,0xbfee, XPD XPD_SHORT
0x334b,0xc2f0,0xa2dd,0xf60e,0x3ff2, XPD XPD_SHORT
0xbeed,0x1853,0xa691,0xa23d,0xbff5, XPD XPD_SHORT
0x296e,0x7cb1,0x5dfd,0xd08f,0xbff4, XPD XPD_SHORT
0x0417,0x7989,0xd7bc,0xe338,0x3ff9, XPD XPD_SHORT
0x3295,0x3698,0xd580,0xbdcd,0xbffa, XPD XPD_SHORT
0x75ef,0x3ab7,0x4ad3,0xe5bc,0xbffc, XPD XPD_SHORT
0xe458,0x2ec7,0xfd57,0xd47c,0x3ffd, XPD XPD_SHORT
0x0000,0x0000,0x0000,0x8000,0x3fff, XPD XPD_SHORT
};
#endif
#if MIEEE
static const long P[24] = {
0x3ff00000,0xb0b22bda,0x3f22434a, XPD_LONG
0x3ff30000,0xee2e335b,0xe82ff5aa, XPD_LONG
0x3ff70000,0x861bc717,0x3757be6c, XPD_LONG
0x3ff90000,0xc368b166,0x51967f43, XPD_LONG
0x3ffb0000,0xe3f48c3a,0x8eb59549, XPD_LONG
0x3ffd0000,0xb9d4c8e4,0x23af8d75, XPD_LONG
0x3ffe0000,0xd67a16c8,0x19b329cf, XPD_LONG
0x3fff0000,0x80000000,0x00000000, XPD_LONG
};
static const long Q[27] = {
0xbfee0000,0xea671268,0x2de85473, XPD_LONG
0x3ff20000,0xf60ea2dd,0xc2f0334b, XPD_LONG
0xbff50000,0xa23da691,0x1853beed, XPD_LONG
0xbff40000,0xd08f5dfd,0x7cb1296e, XPD_LONG
0x3ff90000,0xe338d7bc,0x79890417, XPD_LONG
0xbffa0000,0xbdcdd580,0x36983295, XPD_LONG
0xbffc0000,0xe5bc4ad3,0x3ab775ef, XPD_LONG
0x3ffd0000,0xd47cfd57,0x2ec7e458, XPD_LONG
0x3fff0000,0x80000000,0x00000000, XPD_LONG
};
#endif
/*
static const long double P[] = {
-3.01525602666895735709e0L,
-3.25157411956062339893e1L,
-2.92929976820724030353e2L,
-1.70730828800510297666e3L,
-7.96667499622741999770e3L,
-2.59780216007146401957e4L,
-5.99650230220855581642e4L,
-7.15743521530849602425e4L
};
static const long double Q[] = {
 1.00000000000000000000e0L,
-1.67955233807178858919e1L,
 8.85946791747759881659e1L,
 5.69440799097468430177e1L,
-1.98526250512761318471e3L,
 3.31667508019495079814e3L,
 1.60577839621734713377e4L,
-2.97045081369399940529e4L,
-7.15743521530849602412e4L
};
*/
#define MAXGAML 1755.455L
/*static const long double LOGPI = 1.14472988584940017414L;*/

/* Stirling's formula for the gamma function
gamma(x) = sqrt(2 pi) x^(x-.5) exp(-x) (1 + 1/x P(1/x))
z(x) = x
13 <= x <= 1024
Relative error
n=8, d=0
Peak error =  9.44e-21
Relative error spread =  8.8e-4
*/
#if UNK
static const long double STIR[9] = {
 7.147391378143610789273E-4L,
-2.363848809501759061727E-5L,
-5.950237554056330156018E-4L,
 6.989332260623193171870E-5L,
 7.840334842744753003862E-4L,
-2.294719747873185405699E-4L,
-2.681327161876304418288E-3L,
 3.472222222230075327854E-3L,
 8.333333333333331800504E-2L,
};
#endif
#if IBMPC
static const unsigned short STIR[] = {
0x6ede,0x69f7,0x54e3,0xbb5d,0x3ff4, XPD XPD_SHORT
0xc395,0x0295,0x4443,0xc64b,0xbfef, XPD XPD_SHORT
0xba6f,0x7c59,0x5e47,0x9bfb,0xbff4, XPD XPD_SHORT
0x5704,0x1a39,0xb11d,0x9293,0x3ff1, XPD XPD_SHORT
0x30b7,0x1a21,0x98b2,0xcd87,0x3ff4, XPD XPD_SHORT
0xbef3,0x7023,0x6a08,0xf09e,0xbff2, XPD XPD_SHORT
0x3a1c,0x5ac8,0x3478,0xafb9,0xbff6, XPD XPD_SHORT
0xc3c9,0x906e,0x38e3,0xe38e,0x3ff6, XPD XPD_SHORT
0xa1d5,0xaaaa,0xaaaa,0xaaaa,0x3ffb, XPD XPD_SHORT
};
#endif
#if MIEEE
static const long STIR[27] = {
0x3ff40000,0xbb5d54e3,0x69f76ede, XPD_LONG
0xbfef0000,0xc64b4443,0x0295c395, XPD_LONG
0xbff40000,0x9bfb5e47,0x7c59ba6f, XPD_LONG
0x3ff10000,0x9293b11d,0x1a395704, XPD_LONG
0x3ff40000,0xcd8798b2,0x1a2130b7, XPD_LONG
0xbff20000,0xf09e6a08,0x7023bef3, XPD_LONG
0xbff60000,0xafb93478,0x5ac83a1c, XPD_LONG
0x3ff60000,0xe38e38e3,0x906ec3c9, XPD_LONG
0x3ffb0000,0xaaaaaaaa,0xaaaaa1d5, XPD_LONG
};
#endif
#define MAXSTIR 1024.0L
static const long double SQTPI = 2.50662827463100050242E0L;

/* 1/gamma(x) = z P(z)
 * z(x) = 1/x
 * 0 < x < 0.03125
 * Peak relative error 4.2e-23
 */
#if UNK
static const long double S[9] = {
-1.193945051381510095614E-3L,
 7.220599478036909672331E-3L,
-9.622023360406271645744E-3L,
-4.219773360705915470089E-2L,
 1.665386113720805206758E-1L,
-4.200263503403344054473E-2L,
-6.558780715202540684668E-1L,
 5.772156649015328608253E-1L,
 1.000000000000000000000E0L,
};
#endif
#if IBMPC
static const unsigned short S[] = {
0xbaeb,0xd6d3,0x25e5,0x9c7e,0xbff5, XPD XPD_SHORT
0xfe9a,0xceb4,0xc74e,0xec9a,0x3ff7, XPD XPD_SHORT
0x9225,0xdfef,0xb0e9,0x9da5,0xbff8, XPD XPD_SHORT
0x10b0,0xec17,0x87dc,0xacd7,0xbffa, XPD XPD_SHORT
0x6b8d,0x7515,0x1905,0xaa89,0x3ffc, XPD XPD_SHORT
0xf183,0x126b,0xf47d,0xac0a,0xbffa, XPD XPD_SHORT
0x7bf6,0x57d1,0xa013,0xa7e7,0xbffe, XPD XPD_SHORT
0xc7a9,0x7db0,0x67e3,0x93c4,0x3ffe, XPD XPD_SHORT
0x0000,0x0000,0x0000,0x8000,0x3fff, XPD XPD_SHORT
};
#endif
#if MIEEE
static const long S[27] = {
0xbff50000,0x9c7e25e5,0xd6d3baeb, XPD_LONG
0x3ff70000,0xec9ac74e,0xceb4fe9a, XPD_LONG
0xbff80000,0x9da5b0e9,0xdfef9225, XPD_LONG
0xbffa0000,0xacd787dc,0xec1710b0, XPD_LONG
0x3ffc0000,0xaa891905,0x75156b8d, XPD_LONG
0xbffa0000,0xac0af47d,0x126bf183, XPD_LONG
0xbffe0000,0xa7e7a013,0x57d17bf6, XPD_LONG
0x3ffe0000,0x93c467e3,0x7db0c7a9, XPD_LONG
0x3fff0000,0x80000000,0x00000000, XPD_LONG
};
#endif
/* 1/gamma(-x) = z P(z)
 * z(x) = 1/x
 * 0 < x < 0.03125
 * Peak relative error 5.16e-23
 * Relative error spread =  2.5e-24
 */
#if UNK
static const long double SN[9] = {
 1.133374167243894382010E-3L,
 7.220837261893170325704E-3L,
 9.621911155035976733706E-3L,
-4.219773343731191721664E-2L,
-1.665386113944413519335E-1L,
-4.200263503402112910504E-2L,
 6.558780715202536547116E-1L,
 5.772156649015328608727E-1L,
-1.000000000000000000000E0L,
};
#endif
#if IBMPC
static const unsigned short SN[] = {
0x5dd1,0x02de,0xb9f7,0x948d,0x3ff5, XPD XPD_SHORT
0x989b,0xdd68,0xc5f1,0xec9c,0x3ff7, XPD XPD_SHORT
0x2ca1,0x18f0,0x386f,0x9da5,0x3ff8, XPD XPD_SHORT
0x783f,0x41dd,0x87d1,0xacd7,0xbffa, XPD XPD_SHORT
0x7a5b,0xd76d,0x1905,0xaa89,0xbffc, XPD XPD_SHORT
0x7f64,0x1234,0xf47d,0xac0a,0xbffa, XPD XPD_SHORT
0x5e26,0x57d1,0xa013,0xa7e7,0x3ffe, XPD XPD_SHORT
0xc7aa,0x7db0,0x67e3,0x93c4,0x3ffe, XPD XPD_SHORT
0x0000,0x0000,0x0000,0x8000,0xbfff, XPD XPD_SHORT
};
#endif
#if MIEEE
static const long SN[27] = {
0x3ff50000,0x948db9f7,0x02de5dd1, XPD_LONG
0x3ff70000,0xec9cc5f1,0xdd68989b, XPD_LONG
0x3ff80000,0x9da5386f,0x18f02ca1, XPD_LONG
0xbffa0000,0xacd787d1,0x41dd783f, XPD_LONG
0xbffc0000,0xaa891905,0xd76d7a5b, XPD_LONG
0xbffa0000,0xac0af47d,0x12347f64, XPD_LONG
0x3ffe0000,0xa7e7a013,0x57d15e26, XPD_LONG
0x3ffe0000,0x93c467e3,0x7db0c7aa, XPD_LONG
0xbfff0000,0x80000000,0x00000000, XPD_LONG
};
#endif

static long double stirf ( long double );

/* Gamma function computed by Stirling's formula.  */

static long double stirf(x)
long double x;
{
long double y, w, v;

w = 1.0L/x;
/* For large x, use rational coefficients from the analytical expansion.  */
if( x > 1024.0L )
	w = (((((6.97281375836585777429E-5L * w
		+ 7.84039221720066627474E-4L) * w
		- 2.29472093621399176955E-4L) * w
		- 2.68132716049382716049E-3L) * w
		+ 3.47222222222222222222E-3L) * w
		+ 8.33333333333333333333E-2L) * w
		+ 1.0L;
else
	w = 1.0L + w * polevll( w, STIR, 8 );
y = expl(x);
if( x > MAXSTIR )
	{ /* Avoid overflow in pow() */
	v = powl( x, 0.5L * x - 0.25L );
	y = v * (v / y);
	}
else
	{
	y = powl( x, x - 0.5L ) / y;
	}
y = SQTPI * y * w;
return( y );
}


long double __tgammal_r(long double x, int* sgngaml)
{
long double p, q, z;
int i;

*sgngaml = 1;
#ifdef NANS
if( isnanl(x) )
	return(NANL);
#endif
#ifdef INFINITIES
#ifdef NANS
if( x == INFINITYL )
	return(x);
if( x == -INFINITYL )
	return(NANL);
#else
if( !isfinite(x) )
	return(x);
#endif
#endif
q = fabsl(x);

if( q > 13.0L )
	{
	if( q > MAXGAML )
		goto goverf;
	if( x < 0.0L )
		{
		p = floorl(q);
		if( p == q )
			{
gsing:
			_SET_ERRNO(EDOM);
			mtherr( "tgammal", SING );
#ifdef INFINITIES
			return (INFINITYL);
#else
			return( *sgngaml * MAXNUML);
#endif
			}
		i = p;
		if( (i & 1) == 0 )
			*sgngaml = -1;
		z = q - p;
		if( z > 0.5L )
			{
			p += 1.0L;
			z = q - p;
			}
		z = q * sinl( PIL * z );
		z = fabsl(z) * stirf(q);
		if( z <= PIL/MAXNUML )
			{
goverf:
			_SET_ERRNO(ERANGE);
			mtherr( "tgammal", OVERFLOW );
#ifdef INFINITIES
			return( *sgngaml * INFINITYL);
#else
			return( *sgngaml * MAXNUML);
#endif
			}
		z = PIL/z;
		}
	else
		{
		z = stirf(x);
		}
	return( *sgngaml * z );
	}

z = 1.0L;
while( x >= 3.0L )
	{
	x -= 1.0L;
	z *= x;
	}

while( x < -0.03125L )
	{
	z /= x;
	x += 1.0L;
	}

if( x <= 0.03125L )
	goto Small;

while( x < 2.0L )
	{
	z /= x;
	x += 1.0L;
	}

if( x == 2.0L )
	return(z);

x -= 2.0L;
p = polevll( x, P, 7 );
q = polevll( x, Q, 8 );
return( z * p / q );

Small:
if( x == 0.0L )
	{
	goto gsing;
	}
else
	{
	if( x < 0.0L )
		{
		x = -x;
		q = z / (x * polevll( x, SN, 8 ));
		}
	else
		q = z / (x * polevll( x, S, 8 ));
	}
return q;
}


/* This is the C99 version. */

long double tgammal(long double x)
{
  int local_sgngaml=0;
  return (__tgammal_r(x, &local_sgngaml));
}

