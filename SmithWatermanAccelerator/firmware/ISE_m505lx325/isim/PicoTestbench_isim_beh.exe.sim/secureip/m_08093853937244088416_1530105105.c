/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/phaser_in/SIP_PHASER_IN.v";
static unsigned int ng1[] = {1500U, 0U};
static unsigned int ng2[] = {1500U, 0U, 0U, 0U};



static void Initial_11373_0(char *t0)
{
    char t4[8];
    char t30[16];
    char *t1;
    double t2;
    unsigned int t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    double t12;
    char *t13;
    char *t14;
    double t15;
    char *t16;
    double t17;
    double t18;
    double t19;
    double t20;
    double t21;
    double t22;
    char *t23;
    char *t24;
    double t25;
    double t26;
    double t27;
    double t28;
    double t29;
    char *t31;

LAB0:    xsi_set_current_line(11373, ng0);

LAB2:    xsi_set_current_line(11374, ng0);
    t1 = ((char*)((ng1)));
    t2 = xsi_vlog_convert_to_real(t1, 32, 1);
    t3 = (t2 == 0.0000000000000000);
    *((unsigned int *)t4) = t3;
    t5 = (t4 + 4);
    *((unsigned int *)t5) = 0U;
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 != 0)
        goto LAB3;

LAB4:    t13 = (t0 + 472);
    t14 = *((char **)t13);
    t15 = xsi_vlog_convert_to_real(t14, 32, 1);
    t13 = (t0 + 608);
    t16 = *((char **)t13);
    t17 = *((double *)t16);
    t13 = ((char*)((ng2)));
    t18 = xsi_vlog_convert_to_real(t13, 32, 1);
    t19 = (1000000.0000000000 / t18);
    t20 = (t17 * t19);
    t21 = (t15 + t20);
    t22 = (t21 - 156.00000000000000);
    t23 = (t0 + 744);
    t24 = *((char **)t23);
    t25 = *((double *)t24);
    t26 = (t22 / t25);
    t23 = ((char*)((ng2)));
    t27 = xsi_vlog_convert_to_real(t23, 32, 1);
    t28 = (t26 * t27);
    t29 = (t28 / 10000.000000000000);
    t12 = t29;

LAB5:    xsi_vlog_convert_real_to_values(t12, t30, 64);
    t31 = (t0 + 2312);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 64);

LAB1:    return;
LAB3:    t12 = 0.0000000000000000;
    goto LAB5;

}

static void Cont_11388_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    double t19;
    double t20;
    char *t21;

LAB0:    t1 = (t0 + 3472U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(11388, ng0);
    t2 = (t0 + 1752U);
    t3 = *((char **)t2);
    t2 = (t0 + 3872);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    t16 = (t0 + 2312);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = xsi_vlog_convert_to_real(t18, 64, 2);
    t19 = (t19 * 1000.0000000000000);
    t20 = (t19 < 0.0000000000000000);
    if (t20 == 1)
        goto LAB4;

LAB5:    t19 = (t19 + 0.50000000000000000);
    t19 = ((int64)(t19));

LAB6:    t19 = (t19 * 1.0000000000000000);
    xsi_driver_vfirst_trans_delayed(t2, 0, 0, t19, 0);
    t21 = (t0 + 3792);
    *((int *)t21) = 1;

LAB1:    return;
LAB4:    t19 = 0.0000000000000000;
    goto LAB6;

}


extern void secureip_m_08093853937244088416_1530105105_init()
{
	static char *pe[] = {(void *)Initial_11373_0,(void *)Cont_11388_1};
	xsi_register_didat("secureip_m_08093853937244088416_1530105105", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_08093853937244088416_1530105105.didat");
	xsi_register_executes(pe);
}
