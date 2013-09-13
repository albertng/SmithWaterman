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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/oserdese2/B_OSERDESE2_enc.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 1U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};



static void Always_3744_0(char *t0)
{
    char t4[8];
    char t9[8];
    char t10[8];
    char t13[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t11;
    char *t12;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;

LAB0:    t1 = (t0 + 2680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3744, ng0);
    t2 = (t0 + 3000);
    *((int *)t2) = 1;
    t3 = (t0 + 2712);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(3744, ng0);

LAB5:    xsi_set_current_line(3745, ng0);
    t5 = (t0 + 1368U);
    t6 = *((char **)t5);
    t5 = (t0 + 1208U);
    t7 = *((char **)t5);
    xsi_vlogtype_concat(t4, 2, 2, 2U, t7, 1, t6, 1);

LAB6:    t5 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 2, t5, 2);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(3746, ng0);
    t11 = (t0 + 1048U);
    t12 = *((char **)t11);
    t11 = ((char*)((ng1)));
    memset(t13, 0, 8);
    t14 = (t12 + 4);
    t15 = (t11 + 4);
    t16 = *((unsigned int *)t12);
    t17 = *((unsigned int *)t11);
    t18 = (t16 ^ t17);
    t19 = *((unsigned int *)t14);
    t20 = *((unsigned int *)t15);
    t21 = (t19 ^ t20);
    t22 = (t18 | t21);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t15);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB19;

LAB16:    if (t25 != 0)
        goto LAB18;

LAB17:    *((unsigned int *)t13) = 1;

LAB19:    memset(t10, 0, 8);
    t29 = (t13 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (~(t30));
    t32 = *((unsigned int *)t13);
    t33 = (t32 & t31);
    t34 = (t33 & 1U);
    if (t34 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t29) != 0)
        goto LAB22;

LAB23:    t36 = (t10 + 4);
    t37 = *((unsigned int *)t10);
    t38 = *((unsigned int *)t36);
    t39 = (t37 || t38);
    if (t39 > 0)
        goto LAB24;

LAB25:    t41 = *((unsigned int *)t10);
    t42 = (~(t41));
    t43 = *((unsigned int *)t36);
    t44 = (t42 || t43);
    if (t44 > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t36) > 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t10) > 0)
        goto LAB30;

LAB31:    memcpy(t9, t45, 8);

LAB32:    t46 = (t0 + 1768);
    xsi_vlogvar_assign_value(t46, t9, 0, 0, 1);
    goto LAB15;

LAB9:    xsi_set_current_line(3747, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    goto LAB15;

LAB11:    xsi_set_current_line(3748, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t5 + 4);
    t16 = *((unsigned int *)t3);
    t17 = (~(t16));
    t18 = *((unsigned int *)t5);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB36;

LAB34:    if (*((unsigned int *)t3) == 0)
        goto LAB33;

LAB35:    t6 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t6) = 1;

LAB36:    t7 = (t9 + 4);
    t11 = (t5 + 4);
    t21 = *((unsigned int *)t5);
    t22 = (~(t21));
    *((unsigned int *)t9) = t22;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t11) != 0)
        goto LAB38;

LAB37:    t27 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t27 & 1U);
    t30 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t30 & 1U);
    t12 = (t0 + 1768);
    xsi_vlogvar_assign_value(t12, t9, 0, 0, 1);
    goto LAB15;

LAB13:    xsi_set_current_line(3749, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng3)));
    memset(t13, 0, 8);
    t6 = (t5 + 4);
    t7 = (t3 + 4);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t3);
    t18 = (t16 ^ t17);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t7);
    t21 = (t19 ^ t20);
    t22 = (t18 | t21);
    t23 = *((unsigned int *)t6);
    t24 = *((unsigned int *)t7);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB42;

LAB39:    if (t25 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t13) = 1;

LAB42:    memset(t10, 0, 8);
    t12 = (t13 + 4);
    t30 = *((unsigned int *)t12);
    t31 = (~(t30));
    t32 = *((unsigned int *)t13);
    t33 = (t32 & t31);
    t34 = (t33 & 1U);
    if (t34 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t12) != 0)
        goto LAB45;

LAB46:    t15 = (t10 + 4);
    t37 = *((unsigned int *)t10);
    t38 = *((unsigned int *)t15);
    t39 = (t37 || t38);
    if (t39 > 0)
        goto LAB47;

LAB48:    t41 = *((unsigned int *)t10);
    t42 = (~(t41));
    t43 = *((unsigned int *)t15);
    t44 = (t42 || t43);
    if (t44 > 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t15) > 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t10) > 0)
        goto LAB53;

LAB54:    memcpy(t9, t29, 8);

LAB55:    t35 = (t0 + 1768);
    xsi_vlogvar_assign_value(t35, t9, 0, 0, 1);
    goto LAB15;

LAB18:    t28 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB19;

LAB20:    *((unsigned int *)t10) = 1;
    goto LAB23;

LAB22:    t35 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB23;

LAB24:    t40 = ((char*)((ng2)));
    goto LAB25;

LAB26:    t45 = ((char*)((ng3)));
    goto LAB27;

LAB28:    xsi_vlog_unsigned_bit_combine(t9, 1, t40, 1, t45, 1);
    goto LAB32;

LAB30:    memcpy(t9, t40, 8);
    goto LAB32;

LAB33:    *((unsigned int *)t9) = 1;
    goto LAB36;

LAB38:    t23 = *((unsigned int *)t9);
    t24 = *((unsigned int *)t11);
    *((unsigned int *)t9) = (t23 | t24);
    t25 = *((unsigned int *)t7);
    t26 = *((unsigned int *)t11);
    *((unsigned int *)t7) = (t25 | t26);
    goto LAB37;

LAB41:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB42;

LAB43:    *((unsigned int *)t10) = 1;
    goto LAB46;

LAB45:    t14 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB46;

LAB47:    t28 = ((char*)((ng2)));
    goto LAB48;

LAB49:    t29 = ((char*)((ng1)));
    goto LAB50;

LAB51:    xsi_vlog_unsigned_bit_combine(t9, 1, t28, 1, t29, 1);
    goto LAB55;

LAB53:    memcpy(t9, t28, 8);
    goto LAB55;

}


extern void secureip_m_17065145335748407545_4238707615_init()
{
	static char *pe[] = {(void *)Always_3744_0};
	xsi_register_didat("secureip_m_17065145335748407545_4238707615", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_17065145335748407545_4238707615.didat");
	xsi_register_executes(pe);
}
