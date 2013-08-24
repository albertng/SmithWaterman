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
static unsigned int ng1[] = {86U, 0U};
static unsigned int ng2[] = {89U, 0U};
static unsigned int ng3[] = {101U, 0U};
static unsigned int ng4[] = {149U, 0U};
static unsigned int ng5[] = {85U, 0U};
static unsigned int ng6[] = {0U, 1U};
static unsigned int ng7[] = {1U, 1U};



static void Always_9482_0(char *t0)
{
    char t4[8];
    char t15[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    int t14;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;

LAB0:    t1 = (t0 + 4120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(9482, ng0);
    t2 = (t0 + 4440);
    *((int *)t2) = 1;
    t3 = (t0 + 4152);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(9482, ng0);

LAB5:    xsi_set_current_line(9483, ng0);
    t5 = (t0 + 1848U);
    t6 = *((char **)t5);
    t5 = (t0 + 1688U);
    t7 = *((char **)t5);
    t5 = (t0 + 2168U);
    t8 = *((char **)t5);
    t5 = (t0 + 2008U);
    t9 = *((char **)t5);
    t5 = (t0 + 2488U);
    t10 = *((char **)t5);
    t5 = (t0 + 2328U);
    t11 = *((char **)t5);
    t5 = (t0 + 2808U);
    t12 = *((char **)t5);
    t5 = (t0 + 2648U);
    t13 = *((char **)t5);
    xsi_vlogtype_concat(t4, 8, 8, 8U, t13, 1, t12, 1, t11, 1, t10, 1, t9, 1, t8, 1, t7, 1, t6, 1);

LAB6:    t5 = ((char*)((ng1)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 8, t5, 8);
    if (t14 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 8, t2, 8);
    if (t14 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 8, t2, 8);
    if (t14 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 8, t2, 8);
    if (t14 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 8, t2, 8);
    if (t14 == 1)
        goto LAB15;

LAB16:
LAB18:
LAB17:    xsi_set_current_line(9489, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(9484, ng0);
    t16 = (t0 + 1048U);
    t17 = *((char **)t16);
    memset(t15, 0, 8);
    t16 = (t17 + 4);
    t18 = *((unsigned int *)t16);
    t19 = (~(t18));
    t20 = *((unsigned int *)t17);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB23;

LAB21:    if (*((unsigned int *)t16) == 0)
        goto LAB20;

LAB22:    t23 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t23) = 1;

LAB23:    t24 = (t15 + 4);
    t25 = (t17 + 4);
    t26 = *((unsigned int *)t17);
    t27 = (~(t26));
    *((unsigned int *)t15) = t27;
    *((unsigned int *)t24) = 0;
    if (*((unsigned int *)t25) != 0)
        goto LAB25;

LAB24:    t32 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t32 & 1U);
    t33 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t33 & 1U);
    t34 = (t0 + 3208);
    xsi_vlogvar_assign_value(t34, t15, 0, 0, 1);
    goto LAB19;

LAB9:    xsi_set_current_line(9485, ng0);
    t3 = (t0 + 1208U);
    t5 = *((char **)t3);
    memset(t15, 0, 8);
    t3 = (t5 + 4);
    t18 = *((unsigned int *)t3);
    t19 = (~(t18));
    t20 = *((unsigned int *)t5);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB29;

LAB27:    if (*((unsigned int *)t3) == 0)
        goto LAB26;

LAB28:    t6 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t6) = 1;

LAB29:    t7 = (t15 + 4);
    t8 = (t5 + 4);
    t26 = *((unsigned int *)t5);
    t27 = (~(t26));
    *((unsigned int *)t15) = t27;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t8) != 0)
        goto LAB31;

LAB30:    t32 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t32 & 1U);
    t33 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t33 & 1U);
    t9 = (t0 + 3208);
    xsi_vlogvar_assign_value(t9, t15, 0, 0, 1);
    goto LAB19;

LAB11:    xsi_set_current_line(9486, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    memset(t15, 0, 8);
    t3 = (t5 + 4);
    t18 = *((unsigned int *)t3);
    t19 = (~(t18));
    t20 = *((unsigned int *)t5);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB35;

LAB33:    if (*((unsigned int *)t3) == 0)
        goto LAB32;

LAB34:    t6 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t6) = 1;

LAB35:    t7 = (t15 + 4);
    t8 = (t5 + 4);
    t26 = *((unsigned int *)t5);
    t27 = (~(t26));
    *((unsigned int *)t15) = t27;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t8) != 0)
        goto LAB37;

LAB36:    t32 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t32 & 1U);
    t33 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t33 & 1U);
    t9 = (t0 + 3208);
    xsi_vlogvar_assign_value(t9, t15, 0, 0, 1);
    goto LAB19;

LAB13:    xsi_set_current_line(9487, ng0);
    t3 = (t0 + 1528U);
    t5 = *((char **)t3);
    memset(t15, 0, 8);
    t3 = (t5 + 4);
    t18 = *((unsigned int *)t3);
    t19 = (~(t18));
    t20 = *((unsigned int *)t5);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB41;

LAB39:    if (*((unsigned int *)t3) == 0)
        goto LAB38;

LAB40:    t6 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t6) = 1;

LAB41:    t7 = (t15 + 4);
    t8 = (t5 + 4);
    t26 = *((unsigned int *)t5);
    t27 = (~(t26));
    *((unsigned int *)t15) = t27;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t8) != 0)
        goto LAB43;

LAB42:    t32 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t32 & 1U);
    t33 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t33 & 1U);
    t9 = (t0 + 3208);
    xsi_vlogvar_assign_value(t9, t15, 0, 0, 1);
    goto LAB19;

LAB15:    xsi_set_current_line(9488, ng0);
    t3 = ((char*)((ng6)));
    t5 = (t0 + 3208);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    goto LAB19;

LAB20:    *((unsigned int *)t15) = 1;
    goto LAB23;

LAB25:    t28 = *((unsigned int *)t15);
    t29 = *((unsigned int *)t25);
    *((unsigned int *)t15) = (t28 | t29);
    t30 = *((unsigned int *)t24);
    t31 = *((unsigned int *)t25);
    *((unsigned int *)t24) = (t30 | t31);
    goto LAB24;

LAB26:    *((unsigned int *)t15) = 1;
    goto LAB29;

LAB31:    t28 = *((unsigned int *)t15);
    t29 = *((unsigned int *)t8);
    *((unsigned int *)t15) = (t28 | t29);
    t30 = *((unsigned int *)t7);
    t31 = *((unsigned int *)t8);
    *((unsigned int *)t7) = (t30 | t31);
    goto LAB30;

LAB32:    *((unsigned int *)t15) = 1;
    goto LAB35;

LAB37:    t28 = *((unsigned int *)t15);
    t29 = *((unsigned int *)t8);
    *((unsigned int *)t15) = (t28 | t29);
    t30 = *((unsigned int *)t7);
    t31 = *((unsigned int *)t8);
    *((unsigned int *)t7) = (t30 | t31);
    goto LAB36;

LAB38:    *((unsigned int *)t15) = 1;
    goto LAB41;

LAB43:    t28 = *((unsigned int *)t15);
    t29 = *((unsigned int *)t8);
    *((unsigned int *)t15) = (t28 | t29);
    t30 = *((unsigned int *)t7);
    t31 = *((unsigned int *)t8);
    *((unsigned int *)t7) = (t30 | t31);
    goto LAB42;

}


extern void secureip_m_07369200107595910672_4150929873_init()
{
	static char *pe[] = {(void *)Always_9482_0};
	xsi_register_didat("secureip_m_07369200107595910672_4150929873", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_07369200107595910672_4150929873.didat");
	xsi_register_executes(pe);
}
