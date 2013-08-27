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



static void Initial_9316_0(char *t0)
{
    char *t1;
    double t2;
    double t3;
    char *t4;

LAB0:    xsi_set_current_line(9316, ng0);

LAB2:    xsi_set_current_line(9317, ng0);
    t1 = ((char*)((ng1)));
    t2 = xsi_vlog_convert_to_real(t1, 32, 1);
    t3 = (t2 / 64.000000000000000);
    t4 = (t0 + 1744);
    xsi_vlogvar_assign_value_double(t4, t3, 0);

LAB1:    return;
}

static void Always_9320_1(char *t0)
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

LAB0:    t1 = (t0 + 2904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(9320, ng0);
    t2 = (t0 + 3224);
    *((int *)t2) = 1;
    t3 = (t0 + 2936);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(9320, ng0);

LAB5:    xsi_set_current_line(9321, ng0);
    t4 = (t0 + 1184U);
    t5 = *((char **)t4);
    t4 = (t0 + 4552);
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
    t14 = (t0 + 1744);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = *((double *)t16);
    t17 = (t17 * 1000.0000000000000);
    t18 = (t17 < 0.0000000000000000);
    if (t18 == 1)
        goto LAB6;

LAB7:    t17 = (t17 + 0.50000000000000000);
    t17 = ((int64)(t17));

LAB8:    t17 = (t17 * 1.0000000000000000);
    t19 = (t0 + 2712);
    xsi_process_wait(t19, t17);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB6:    t17 = 0.0000000000000000;
    goto LAB8;

LAB9:    t20 = (t0 + 4552);
    t21 = (t0 + 1584);
    xsi_vlogvar_assign_value(t21, t20, 0, 0, 1);
    goto LAB2;

}


extern void secureip_m_18133525006710680106_2020953963_init()
{
	static char *pe[] = {(void *)Initial_9316_0,(void *)Always_9320_1};
	xsi_register_didat("secureip_m_18133525006710680106_2020953963", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_18133525006710680106_2020953963.didat");
	xsi_register_executes(pe);
}
