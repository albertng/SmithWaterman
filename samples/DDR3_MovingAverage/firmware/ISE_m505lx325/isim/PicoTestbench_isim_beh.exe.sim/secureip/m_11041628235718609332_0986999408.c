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
static unsigned int ng1[] = {1500U, 0U, 0U, 0U};



static void Initial_12699_0(char *t0)
{
    char t10[16];
    char *t1;
    char *t2;
    double t3;
    char *t4;
    double t5;
    double t6;
    double t7;
    double t8;
    double t9;
    char *t11;

LAB0:    xsi_set_current_line(12699, ng0);

LAB2:    xsi_set_current_line(12700, ng0);
    t1 = (t0 + 472);
    t2 = *((char **)t1);
    t3 = xsi_vlog_convert_to_real(t2, 32, 1);
    t1 = (t0 + 608);
    t4 = *((char **)t1);
    t5 = *((double *)t4);
    t1 = ((char*)((ng1)));
    t6 = xsi_vlog_convert_to_real(t1, 32, 1);
    t7 = (t5 * t6);
    t8 = (t3 + t7);
    t9 = (t8 / 2.0000000000000000);
    xsi_vlog_convert_real_to_values(t9, t10, 64);
    t11 = (t0 + 2016);
    xsi_vlogvar_assign_value(t11, t10, 0, 0, 64);

LAB1:    return;
}

static void Always_12705_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    double t17;
    double t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    t1 = (t0 + 3336U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(12705, ng0);
    t2 = (t0 + 3904);
    *((int *)t2) = 1;
    t3 = (t0 + 3368);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(12705, ng0);

LAB5:    xsi_set_current_line(12706, ng0);
    t4 = (t0 + 1456U);
    t5 = *((char **)t4);
    t4 = (t0 + 5328);
    memset(t4, 0, 8);
    t6 = 1U;
    t7 = t6;
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t6 = (t6 & t9);
    t10 = *((unsigned int *)t8);
    t7 = (t7 & t10);
    t11 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 | t6);
    t13 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t13 | t7);
    t14 = (t0 + 2016);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = xsi_vlog_convert_to_real(t16, 64, 2);
    t17 = (t17 * 1000.0000000000000);
    t18 = (t17 < 0.0000000000000000);
    if (t18 == 1)
        goto LAB6;

LAB7:    t17 = (t17 + 0.50000000000000000);
    t17 = ((int64)(t17));

LAB8:    t17 = (t17 * 1.0000000000000000);
    t19 = (t0 + 3144);
    xsi_process_wait(t19, t17);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB6:    t17 = 0.0000000000000000;
    goto LAB8;

LAB9:    t20 = (t0 + 5328);
    t21 = (t0 + 2176);
    xsi_vlogvar_assign_value(t21, t20, 0, 0, 1);
    goto LAB2;

}

static void Always_12709_2(char *t0)
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
    char *t22;
    char *t23;

LAB0:    t1 = (t0 + 3584U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(12709, ng0);
    t2 = (t0 + 3920);
    *((int *)t2) = 1;
    t3 = (t0 + 3616);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(12709, ng0);

LAB5:    xsi_set_current_line(12710, ng0);
    t4 = (t0 + 2176);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 5336);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t6 + 4);
    t11 = *((unsigned int *)t6);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    t16 = (t0 + 2016);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = xsi_vlog_convert_to_real(t18, 64, 2);
    t19 = (t19 * 1000.0000000000000);
    t20 = (t19 < 0.0000000000000000);
    if (t20 == 1)
        goto LAB6;

LAB7:    t19 = (t19 + 0.50000000000000000);
    t19 = ((int64)(t19));

LAB8:    t19 = (t19 * 1.0000000000000000);
    t21 = (t0 + 3392);
    xsi_process_wait(t21, t19);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB6:    t19 = 0.0000000000000000;
    goto LAB8;

LAB9:    t22 = (t0 + 5336);
    t23 = (t0 + 1856);
    xsi_vlogvar_assign_value(t23, t22, 0, 0, 1);
    goto LAB2;

}


extern void secureip_m_11041628235718609332_0986999408_init()
{
	static char *pe[] = {(void *)Initial_12699_0,(void *)Always_12705_1,(void *)Always_12709_2};
	xsi_register_didat("secureip_m_11041628235718609332_0986999408", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_11041628235718609332_0986999408.didat");
	xsi_register_executes(pe);
}
