#pragma once

// Value of e
#define M_E             2.7182818284590452353602874713526624977572470936999595
// Value of log2(e)
#define M_LOG2E         1.4426950408889634073599246810018921374266459541529859
// Value of log10(e)
#define M_LOG10E        0.4342944819032518276511289189166050822943970058036665
// Value of ln(2)
#define M_LN2           0.6931471805599453094172321214581765680755001343602552
// Value of ln(10)
#define M_LN10          2.3025850929940456840179914546843642076011014886287729
// Value of Pi
#define M_PI            3.1415926535897932384626433832795028841971693993751058
// Value of Pi/2
#define M_PI_2          1.5707963267948966192313216916397514420985846996875529
// Value of Pi/4
#define M_PI_4          0.7853981633974483096156608458198757210492923498437764
// Value of 1/Pi
#define M_1_PI          0.3183098861837906715377675267450287240689192914809128
// Value of 2/Pi
#define M_2_PI          0.6366197723675813430755350534900574481378385829618257
// Value of 2/sqrt(Pi)
#define M_2_SQRTPI      1.1283791670955125738961589031215451716881012586579977
// Value of sqrt(2)
#define M_SQRT2         1.4142135623730950488016887242096980785696718753769480
// Value of 1/sqrt(2)
#define M_SQRT1_2       0.7071067811865475244008443621048490392848359376884740

#include <decl.h>

BEGIN_DECL
#if PORT_CPU_FAMILY == arm && PORT_CPU_SUBFAMILY == CM4F
#define SOFTFLOAT_SQRTF
static inline float sqrtf(float x) {
    float r;
    asm("vsqrt.f32 %0, %1" : "=w"(r) : "w"(x));
    return r;
}
#endif
#include <fdlibm.h>
#include <softfloat.h>
END_DECL
