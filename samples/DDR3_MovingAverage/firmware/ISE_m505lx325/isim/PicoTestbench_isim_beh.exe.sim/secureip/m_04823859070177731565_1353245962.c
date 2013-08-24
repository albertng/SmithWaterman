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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/phaser_out/SIP_PHASER_OUT.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};



static void Always_4802_0(char *t0)
{
    char t4[8];
    char t9[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;

LAB0:    t1 = (t0 + 3640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(4802, ng0);
    t2 = (t0 + 3960);
    *((int *)t2) = 1;
    t3 = (t0 + 3672);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(4802, ng0);

LAB5:    xsi_set_current_line(4803, ng0);
    t5 = (t0 + 1208U);
    t6 = *((char **)t5);
    t5 = (t0 + 1048U);
    t7 = *((char **)t5);
    xsi_vlogtype_concat(t4, 2, 2, 2U, t7, 1, t6, 1);

LAB6:    t5 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 2, t5, 2);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(4804, ng0);

LAB16:    xsi_set_current_line(4805, ng0);
    t10 = (t0 + 1688U);
    t11 = *((char **)t10);
    memset(t9, 0, 8);
    t10 = (t11 + 4);
    t12 = *((unsigned int *)t10);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB20;

LAB18:    if (*((unsigned int *)t10) == 0)
        goto LAB17;

LAB19:    t17 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t17) = 1;

LAB20:    t18 = (t9 + 4);
    t19 = (t11 + 4);
    t20 = *((unsigned int *)t11);
    t21 = (~(t20));
    *((unsigned int *)t9) = t21;
    *((unsigned int *)t18) = 0;
    if (*((unsigned int *)t19) != 0)
        goto LAB22;

LAB21:    t26 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t26 & 1U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 & 1U);
    t28 = (t0 + 2568);
    xsi_vlogvar_assign_value(t28, t9, 0, 0, 1);
    xsi_set_current_line(4806, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB26;

LAB24:    if (*((unsigned int *)t2) == 0)
        goto LAB23;

LAB25:    t5 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t5) = 1;

LAB26:    t6 = (t9 + 4);
    t7 = (t3 + 4);
    t20 = *((unsigned int *)t3);
    t21 = (~(t20));
    *((unsigned int *)t9) = t21;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB28;

LAB27:    t26 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t26 & 1U);
    t27 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t27 & 1U);
    t10 = (t0 + 2728);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 1);
    goto LAB15;

LAB9:    xsi_set_current_line(4808, ng0);

LAB29:    xsi_set_current_line(4809, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t5 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (~(t12));
    t14 = *((unsigned int *)t5);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB33;

LAB31:    if (*((unsigned int *)t3) == 0)
        goto LAB30;

LAB32:    t6 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t6) = 1;

LAB33:    t7 = (t9 + 4);
    t10 = (t5 + 4);
    t20 = *((unsigned int *)t5);
    t21 = (~(t20));
    *((unsigned int *)t9) = t21;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t10) != 0)
        goto LAB35;

LAB34:    t26 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t26 & 1U);
    t27 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t27 & 1U);
    t11 = (t0 + 2568);
    xsi_vlogvar_assign_value(t11, t9, 0, 0, 1);
    xsi_set_current_line(4810, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB39;

LAB37:    if (*((unsigned int *)t2) == 0)
        goto LAB36;

LAB38:    t5 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t5) = 1;

LAB39:    t6 = (t9 + 4);
    t7 = (t3 + 4);
    t20 = *((unsigned int *)t3);
    t21 = (~(t20));
    *((unsigned int *)t9) = t21;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB41;

LAB40:    t26 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t26 & 1U);
    t27 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t27 & 1U);
    t10 = (t0 + 2728);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 1);
    goto LAB15;

LAB11:    xsi_set_current_line(4812, ng0);

LAB42:    xsi_set_current_line(4813, ng0);
    t3 = (t0 + 2168U);
    t5 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t5 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (~(t12));
    t14 = *((unsigned int *)t5);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB46;

LAB44:    if (*((unsigned int *)t3) == 0)
        goto LAB43;

LAB45:    t6 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t6) = 1;

LAB46:    t7 = (t9 + 4);
    t10 = (t5 + 4);
    t20 = *((unsigned int *)t5);
    t21 = (~(t20));
    *((unsigned int *)t9) = t21;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t10) != 0)
        goto LAB48;

LAB47:    t26 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t26 & 1U);
    t27 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t27 & 1U);
    t11 = (t0 + 2568);
    xsi_vlogvar_assign_value(t11, t9, 0, 0, 1);
    xsi_set_current_line(4814, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB52;

LAB50:    if (*((unsigned int *)t2) == 0)
        goto LAB49;

LAB51:    t5 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t5) = 1;

LAB52:    t6 = (t9 + 4);
    t7 = (t3 + 4);
    t20 = *((unsigned int *)t3);
    t21 = (~(t20));
    *((unsigned int *)t9) = t21;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB54;

LAB53:    t26 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t26 & 1U);
    t27 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t27 & 1U);
    t10 = (t0 + 2728);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 1);
    goto LAB15;

LAB13:    xsi_set_current_line(4816, ng0);

LAB55:    xsi_set_current_line(4817, ng0);
    t3 = (t0 + 2168U);
    t5 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t5 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (~(t12));
    t14 = *((unsigned int *)t5);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB59;

LAB57:    if (*((unsigned int *)t3) == 0)
        goto LAB56;

LAB58:    t6 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t6) = 1;

LAB59:    t7 = (t9 + 4);
    t10 = (t5 + 4);
    t20 = *((unsigned int *)t5);
    t21 = (~(t20));
    *((unsigned int *)t9) = t21;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t10) != 0)
        goto LAB61;

LAB60:    t26 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t26 & 1U);
    t27 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t27 & 1U);
    t11 = (t0 + 2568);
    xsi_vlogvar_assign_value(t11, t9, 0, 0, 1);
    xsi_set_current_line(4818, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB65;

LAB63:    if (*((unsigned int *)t2) == 0)
        goto LAB62;

LAB64:    t5 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t5) = 1;

LAB65:    t6 = (t9 + 4);
    t7 = (t3 + 4);
    t20 = *((unsigned int *)t3);
    t21 = (~(t20));
    *((unsigned int *)t9) = t21;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB67;

LAB66:    t26 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t26 & 1U);
    t27 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t27 & 1U);
    t10 = (t0 + 2728);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 1);
    goto LAB15;

LAB17:    *((unsigned int *)t9) = 1;
    goto LAB20;

LAB22:    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t19);
    *((unsigned int *)t9) = (t22 | t23);
    t24 = *((unsigned int *)t18);
    t25 = *((unsigned int *)t19);
    *((unsigned int *)t18) = (t24 | t25);
    goto LAB21;

LAB23:    *((unsigned int *)t9) = 1;
    goto LAB26;

LAB28:    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t7);
    *((unsigned int *)t9) = (t22 | t23);
    t24 = *((unsigned int *)t6);
    t25 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t24 | t25);
    goto LAB27;

LAB30:    *((unsigned int *)t9) = 1;
    goto LAB33;

LAB35:    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t10);
    *((unsigned int *)t9) = (t22 | t23);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t10);
    *((unsigned int *)t7) = (t24 | t25);
    goto LAB34;

LAB36:    *((unsigned int *)t9) = 1;
    goto LAB39;

LAB41:    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t7);
    *((unsigned int *)t9) = (t22 | t23);
    t24 = *((unsigned int *)t6);
    t25 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t24 | t25);
    goto LAB40;

LAB43:    *((unsigned int *)t9) = 1;
    goto LAB46;

LAB48:    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t10);
    *((unsigned int *)t9) = (t22 | t23);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t10);
    *((unsigned int *)t7) = (t24 | t25);
    goto LAB47;

LAB49:    *((unsigned int *)t9) = 1;
    goto LAB52;

LAB54:    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t7);
    *((unsigned int *)t9) = (t22 | t23);
    t24 = *((unsigned int *)t6);
    t25 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t24 | t25);
    goto LAB53;

LAB56:    *((unsigned int *)t9) = 1;
    goto LAB59;

LAB61:    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t10);
    *((unsigned int *)t9) = (t22 | t23);
    t24 = *((unsigned int *)t7);
    t25 = *((unsigned int *)t10);
    *((unsigned int *)t7) = (t24 | t25);
    goto LAB60;

LAB62:    *((unsigned int *)t9) = 1;
    goto LAB65;

LAB67:    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t7);
    *((unsigned int *)t9) = (t22 | t23);
    t24 = *((unsigned int *)t6);
    t25 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t24 | t25);
    goto LAB66;

}


extern void secureip_m_04823859070177731565_1353245962_init()
{
	static char *pe[] = {(void *)Always_4802_0};
	xsi_register_didat("secureip_m_04823859070177731565_1353245962", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_04823859070177731565_1353245962.didat");
	xsi_register_executes(pe);
}
