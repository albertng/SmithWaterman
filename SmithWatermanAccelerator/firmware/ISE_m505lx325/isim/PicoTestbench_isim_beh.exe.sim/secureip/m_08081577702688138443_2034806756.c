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
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};



static void Always_1061_0(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 3160U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1061, ng0);
    t2 = (t0 + 3480);
    *((int *)t2) = 1;
    t3 = (t0 + 3192);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(1061, ng0);

LAB5:    xsi_set_current_line(1062, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t4, 2);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB13;

LAB14:
LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(1063, ng0);
    t8 = (t0 + 1048U);
    t9 = *((char **)t8);
    memset(t7, 0, 8);
    t8 = (t9 + 4);
    t10 = *((unsigned int *)t8);
    t11 = (~(t10));
    t12 = *((unsigned int *)t9);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB19;

LAB17:    if (*((unsigned int *)t8) == 0)
        goto LAB16;

LAB18:    t15 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t15) = 1;

LAB19:    t16 = (t7 + 4);
    t17 = (t9 + 4);
    t18 = *((unsigned int *)t9);
    t19 = (~(t18));
    *((unsigned int *)t7) = t19;
    *((unsigned int *)t16) = 0;
    if (*((unsigned int *)t17) != 0)
        goto LAB21;

LAB20:    t24 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t24 & 1U);
    t25 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t25 & 1U);
    t26 = (t0 + 2248);
    xsi_vlogvar_assign_value(t26, t7, 0, 0, 1);
    goto LAB15;

LAB9:    xsi_set_current_line(1064, ng0);
    t3 = (t0 + 1208U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    t12 = *((unsigned int *)t4);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB25;

LAB23:    if (*((unsigned int *)t3) == 0)
        goto LAB22;

LAB24:    t8 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t8) = 1;

LAB25:    t9 = (t7 + 4);
    t15 = (t4 + 4);
    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    *((unsigned int *)t7) = t19;
    *((unsigned int *)t9) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB27;

LAB26:    t24 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t24 & 1U);
    t25 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t25 & 1U);
    t16 = (t0 + 2248);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 1);
    goto LAB15;

LAB11:    xsi_set_current_line(1065, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    t12 = *((unsigned int *)t4);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB31;

LAB29:    if (*((unsigned int *)t3) == 0)
        goto LAB28;

LAB30:    t8 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t8) = 1;

LAB31:    t9 = (t7 + 4);
    t15 = (t4 + 4);
    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    *((unsigned int *)t7) = t19;
    *((unsigned int *)t9) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB33;

LAB32:    t24 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t24 & 1U);
    t25 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t25 & 1U);
    t16 = (t0 + 2248);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 1);
    goto LAB15;

LAB13:    xsi_set_current_line(1066, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    t12 = *((unsigned int *)t4);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB37;

LAB35:    if (*((unsigned int *)t3) == 0)
        goto LAB34;

LAB36:    t8 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t8) = 1;

LAB37:    t9 = (t7 + 4);
    t15 = (t4 + 4);
    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    *((unsigned int *)t7) = t19;
    *((unsigned int *)t9) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB39;

LAB38:    t24 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t24 & 1U);
    t25 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t25 & 1U);
    t16 = (t0 + 2248);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 1);
    goto LAB15;

LAB16:    *((unsigned int *)t7) = 1;
    goto LAB19;

LAB21:    t20 = *((unsigned int *)t7);
    t21 = *((unsigned int *)t17);
    *((unsigned int *)t7) = (t20 | t21);
    t22 = *((unsigned int *)t16);
    t23 = *((unsigned int *)t17);
    *((unsigned int *)t16) = (t22 | t23);
    goto LAB20;

LAB22:    *((unsigned int *)t7) = 1;
    goto LAB25;

LAB27:    t20 = *((unsigned int *)t7);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t7) = (t20 | t21);
    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t15);
    *((unsigned int *)t9) = (t22 | t23);
    goto LAB26;

LAB28:    *((unsigned int *)t7) = 1;
    goto LAB31;

LAB33:    t20 = *((unsigned int *)t7);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t7) = (t20 | t21);
    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t15);
    *((unsigned int *)t9) = (t22 | t23);
    goto LAB32;

LAB34:    *((unsigned int *)t7) = 1;
    goto LAB37;

LAB39:    t20 = *((unsigned int *)t7);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t7) = (t20 | t21);
    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t15);
    *((unsigned int *)t9) = (t22 | t23);
    goto LAB38;

}


extern void secureip_m_08081577702688138443_2034806756_init()
{
	static char *pe[] = {(void *)Always_1061_0};
	xsi_register_didat("secureip_m_08081577702688138443_2034806756", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_08081577702688138443_2034806756.didat");
	xsi_register_executes(pe);
}
