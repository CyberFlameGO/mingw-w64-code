/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include "cephes_mconf.h"
#ifndef _SET_ERRNO
#define _SET_ERRNO(x)
#endif

#ifdef UNK
static long double P[] = {
-6.8473739392677100872869E-5L,
-9.5658283111794641589011E-1L,
-8.4053568599672284488465E1L,
-1.3080425704712825945553E3L,
};
static long double Q[] = {
/* 1.0000000000000000000000E0L,*/
 9.6259501838840336946872E1L,
 1.8218117903645559060232E3L,
 3.9241277114138477845780E3L,
};
#endif

#ifdef IBMPC
static unsigned short P[] = {
0xd2a4,0x1b0c,0x8f15,0x8f99,0xbff1, XPD
0x5959,0x9111,0x9cc7,0xf4e2,0xbffe, XPD
0xb576,0xef5e,0x6d57,0xa81b,0xc005, XPD
0xe3be,0xbfbd,0x5cbc,0xa381,0xc009, XPD
};
static unsigned short Q[] = {
/*0x0000,0x0000,0x0000,0x8000,0x3fff,*/
0x687f,0xce24,0xdd6c,0xc084,0x4005, XPD
0x3793,0xc95f,0xfa2f,0xe3b9,0x4009, XPD
0xd5a2,0x1f9c,0x0b1b,0xf542,0x400a, XPD
};
#endif

#ifdef MIEEE
static long P[] = {
0xbff10000,0x8f998f15,0x1b0cd2a4,
0xbffe0000,0xf4e29cc7,0x91115959,
0xc0050000,0xa81b6d57,0xef5eb576,
0xc0090000,0xa3815cbc,0xbfbde3be,
};
static long Q[] = {
/*0x3fff0000,0x80000000,0x00000000,*/
0x40050000,0xc084dd6c,0xce24687f,
0x40090000,0xe3b9fa2f,0xc95f3793,
0x400a0000,0xf5420b1b,0x1f9cd5a2,
};
#endif

long double tanhl(x)
long double x;
{
long double s, z;

#ifdef MINUSZERO
if( x == 0.0L )
	return(x);
#endif
if (isnanl(x))
	{
	_SET_ERRNO (EDOM);
	return x;
	}

z = fabsl(x);
if( z > 0.5L * MAXLOGL )
	{
	_SET_ERRNO (ERANGE);
	if( x > 0 )
		return( 1.0L );
	else
		return( -1.0L );
	}
if( z >= 0.625L )
	{
	s = expl(2.0*z);
	z =  1.0L  - 2.0/(s + 1.0L);
	if( x < 0 )
		z = -z;
	}
else
	{
	s = x * x;
	z = polevll( s, P, 3 )/p1evll(s, Q, 3);
	z = x * s * z;
	z = x + z;
	}
return( z );
}
