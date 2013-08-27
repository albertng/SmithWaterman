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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/phy_control/SIP_PHY_CONTROL.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {6U, 0U};



static void Always_3789_0(char *t0)
{
    char t7[8];
    char t8[8];
    char t25[8];
    char t32[8];
    char t39[8];
    char t46[8];
    char t56[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;

LAB0:    t1 = (t0 + 4920U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3789, ng0);
    t2 = (t0 + 5240);
    *((int *)t2) = 1;
    t3 = (t0 + 4952);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(3789, ng0);

LAB5:    xsi_set_current_line(3790, ng0);
    t4 = (t0 + 1048U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(3795, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(3791, ng0);
    t9 = (t0 + 2008U);
    t10 = *((char **)t9);
    memset(t8, 0, 8);
    t9 = (t8 + 4);
    t11 = (t10 + 4);
    t12 = *((unsigned int *)t10);
    t13 = (t12 >> 0);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 >> 0);
    *((unsigned int *)t9) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 3U);
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 3U);
    t18 = (t0 + 1528U);
    t19 = *((char **)t18);
    t18 = (t0 + 1688U);
    t20 = *((char **)t18);
    t18 = (t0 + 3288U);
    t21 = *((char **)t18);
    t18 = (t0 + 3608U);
    t22 = *((char **)t18);
    t18 = (t0 + 3448U);
    t23 = *((char **)t18);
    t18 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 16, 16, 7U, t18, 9, t23, 1, t22, 1, t21, 1, t20, 1, t19, 1, t8, 2);
    t24 = (t0 + 4008);
    xsi_vlogvar_assign_value(t24, t7, 0, 0, 16);
    goto LAB17;

LAB9:    xsi_set_current_line(3792, ng0);
    t3 = (t0 + 3128U);
    t4 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4);
    t9 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 0);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t9);
    t15 = (t14 >> 0);
    *((unsigned int *)t3) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 15U);
    t17 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t17 & 15U);
    t10 = (t0 + 2328U);
    t11 = *((char **)t10);
    memset(t25, 0, 8);
    t10 = (t25 + 4);
    t18 = (t11 + 4);
    t26 = *((unsigned int *)t11);
    t27 = (t26 >> 0);
    *((unsigned int *)t25) = t27;
    t28 = *((unsigned int *)t18);
    t29 = (t28 >> 0);
    *((unsigned int *)t10) = t29;
    t30 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t30 & 3U);
    t31 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t31 & 3U);
    t19 = (t0 + 2488U);
    t20 = *((char **)t19);
    memset(t32, 0, 8);
    t19 = (t32 + 4);
    t21 = (t20 + 4);
    t33 = *((unsigned int *)t20);
    t34 = (t33 >> 0);
    *((unsigned int *)t32) = t34;
    t35 = *((unsigned int *)t21);
    t36 = (t35 >> 0);
    *((unsigned int *)t19) = t36;
    t37 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t37 & 3U);
    t38 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t38 & 3U);
    t22 = (t0 + 2648U);
    t23 = *((char **)t22);
    memset(t39, 0, 8);
    t22 = (t39 + 4);
    t24 = (t23 + 4);
    t40 = *((unsigned int *)t23);
    t41 = (t40 >> 0);
    *((unsigned int *)t39) = t41;
    t42 = *((unsigned int *)t24);
    t43 = (t42 >> 0);
    *((unsigned int *)t22) = t43;
    t44 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t44 & 3U);
    t45 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t45 & 3U);
    t47 = (t0 + 2808U);
    t48 = *((char **)t47);
    memset(t46, 0, 8);
    t47 = (t46 + 4);
    t49 = (t48 + 4);
    t50 = *((unsigned int *)t48);
    t51 = (t50 >> 0);
    *((unsigned int *)t46) = t51;
    t52 = *((unsigned int *)t49);
    t53 = (t52 >> 0);
    *((unsigned int *)t47) = t53;
    t54 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t54 & 3U);
    t55 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t55 & 3U);
    t57 = (t0 + 2168U);
    t58 = *((char **)t57);
    memset(t56, 0, 8);
    t57 = (t56 + 4);
    t59 = (t58 + 4);
    t60 = *((unsigned int *)t58);
    t61 = (t60 >> 0);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t59);
    t63 = (t62 >> 0);
    *((unsigned int *)t57) = t63;
    t64 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t64 & 15U);
    t65 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t65 & 15U);
    xsi_vlogtype_concat(t7, 16, 16, 6U, t56, 4, t46, 2, t39, 2, t32, 2, t25, 2, t8, 4);
    t66 = (t0 + 4008);
    xsi_vlogvar_assign_value(t66, t7, 0, 0, 16);
    goto LAB17;

LAB11:    xsi_set_current_line(3793, ng0);
    t3 = (t0 + 2968U);
    t4 = *((char **)t3);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB17;

LAB13:    xsi_set_current_line(3794, ng0);
    t3 = (t0 + 1208U);
    t4 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4);
    t9 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 0);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t9);
    t15 = (t14 >> 0);
    *((unsigned int *)t3) = t15;
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 3U);
    t17 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t17 & 3U);
    t10 = (t0 + 1848U);
    t11 = *((char **)t10);
    memset(t25, 0, 8);
    t10 = (t25 + 4);
    t18 = (t11 + 4);
    t26 = *((unsigned int *)t11);
    t27 = (t26 >> 0);
    *((unsigned int *)t25) = t27;
    t28 = *((unsigned int *)t18);
    t29 = (t28 >> 0);
    *((unsigned int *)t10) = t29;
    t30 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t30 & 15U);
    t31 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t31 & 15U);
    t19 = ((char*)((ng1)));
    xsi_vlogtype_concat(t7, 16, 16, 3U, t19, 10, t25, 4, t8, 2);
    t20 = (t0 + 4008);
    xsi_vlogvar_assign_value(t20, t7, 0, 0, 16);
    goto LAB17;

}


extern void secureip_m_16999038763518487413_1971026893_init()
{
	static char *pe[] = {(void *)Always_3789_0};
	xsi_register_didat("secureip_m_16999038763518487413_1971026893", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_16999038763518487413_1971026893.didat");
	xsi_register_executes(pe);
}
