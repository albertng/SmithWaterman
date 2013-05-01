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
static const char *ng0 = "/home/albertng/SeqAlignFPGA/SmithWaterman/firmware/SmithWatermanPE_tb.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {1, 0};
static int ng5[] = {2, 0};
static int ng6[] = {3, 0};
static unsigned int ng7[] = {3U, 0U};
static int ng8[] = {4, 0};
static int ng9[] = {5, 0};
static unsigned int ng10[] = {2U, 0U};
static int ng11[] = {6, 0};
static int ng12[] = {7, 0};
static unsigned int ng13[] = {10U, 0U};
static unsigned int ng14[] = {8U, 0U};
static unsigned int ng15[] = {7U, 0U};
static const char *ng16 = "V=0, F=0, S='A' test";
static const char *ng17 = "Init_out error: Got 1 expected 0";
static int ng18[] = {8, 0};
static const char *ng19 = "%d %d %d %d";
static const char *ng20 = "V_out error: Got %d expected %d";
static const char *ng21 = "F_out error: Got %d expected -1";
static const char *ng22 = "T_out error: Got %d expected %d";
static const char *ng23 = "Init_out error: Got 0 expected 1";
static unsigned int ng24[] = {6U, 0U};
static const char *ng25 = "V=0, F=0, S='C' test";
static unsigned int ng26[] = {20U, 0U};
static unsigned int ng27[] = {18U, 0U};
static const char *ng28 = "V=10, F=-4, S='T' test";
static int ng29[] = {10, 0};



static void Initial_48_0(char *t0)
{
    char t4[8];
    char t5[8];
    char t47[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    int t15;
    char *t16;
    unsigned int t17;
    int t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    int t22;
    int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;

LAB0:    t1 = (t0 + 4600U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);

LAB4:    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    t6 = (t0 + 3208);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3208);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng2)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB5;

LAB6:    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3208);
    t6 = (t0 + 3208);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3208);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng4)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB7;

LAB8:    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    t6 = (t0 + 3208);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3208);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng5)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB9;

LAB10:    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3208);
    t6 = (t0 + 3208);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3208);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB11;

LAB12:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3208);
    t6 = (t0 + 3208);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3208);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng8)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    t6 = (t0 + 3208);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3208);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng9)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB15;

LAB16:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    t6 = (t0 + 3368);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3368);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng2)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB17;

LAB18:    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3368);
    t6 = (t0 + 3368);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3368);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng4)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB19;

LAB20:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    t6 = (t0 + 3368);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3368);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng5)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB21;

LAB22:    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 3368);
    t6 = (t0 + 3368);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3368);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB23;

LAB24:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    t6 = (t0 + 3368);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3368);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng8)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB25;

LAB26:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3368);
    t6 = (t0 + 3368);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3368);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng9)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB27;

LAB28:    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3368);
    t6 = (t0 + 3368);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3368);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng11)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB29;

LAB30:    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    t6 = (t0 + 3368);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3368);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng12)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB31;

LAB32:    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 4408);
    xsi_process_wait(t2, 20000LL);
    *((char **)t1) = &&LAB33;

LAB1:    return;
LAB5:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB6;

LAB7:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB8;

LAB9:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB10;

LAB11:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB12;

LAB13:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB14;

LAB15:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB16;

LAB17:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB18;

LAB19:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB20;

LAB21:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB22;

LAB23:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB24;

LAB25:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB26;

LAB27:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB28;

LAB29:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB30;

LAB31:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB32;

LAB33:    xsi_set_current_line(77, ng0);
    t3 = ((char*)((ng2)));
    t6 = (t0 + 2088);
    xsi_vlogvar_assign_value(t6, t3, 0, 0, 1);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng2)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB34;

LAB35:    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng4)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB36;

LAB37:    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng5)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB38;

LAB39:    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB40;

LAB41:    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng8)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB42;

LAB43:    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng9)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB44;

LAB45:    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng11)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB46;

LAB47:    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng12)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB48;

LAB49:    xsi_set_current_line(90, ng0);
    xsi_vlogfile_write(1, 0, 0, ng16, 1, t0);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t0 + 3208);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t10 = (t0 + 3208);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng2)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t6, t9, t12, 2, 1, t13, 32, 1);
    t16 = (t0 + 2728);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 2);
    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 4408);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB50;
    goto LAB1;

LAB34:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB35;

LAB36:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB37;

LAB38:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB39;

LAB40:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB41;

LAB42:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB43;

LAB44:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB45;

LAB46:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB47;

LAB48:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB49;

LAB50:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB51;

LAB52:
LAB53:    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(99, ng0);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB55:    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng18)));
    memset(t4, 0, 8);
    xsi_vlog_signed_less(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB56;

LAB57:    xsi_set_current_line(123, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng2)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB92;

LAB93:    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng4)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB94;

LAB95:    xsi_set_current_line(125, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng5)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB96;

LAB97:    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB98;

LAB99:    xsi_set_current_line(127, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng8)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB100;

LAB101:    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng9)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB102;

LAB103:    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng11)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB104;

LAB105:    xsi_set_current_line(130, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng12)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB106;

LAB107:    xsi_set_current_line(131, ng0);
    xsi_vlogfile_write(1, 0, 0, ng25, 1, t0);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t0 + 3208);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t10 = (t0 + 3208);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t6, t9, t12, 2, 1, t13, 32, 1);
    t16 = (t0 + 2728);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 2);
    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 4408);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB108;
    goto LAB1;

LAB51:    xsi_set_current_line(94, ng0);

LAB54:    xsi_set_current_line(95, ng0);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);
    xsi_set_current_line(96, ng0);
    xsi_vlog_finish(1);
    goto LAB53;

LAB56:    xsi_set_current_line(99, ng0);

LAB58:    xsi_set_current_line(100, ng0);
    t9 = (t0 + 3368);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 3368);
    t13 = (t12 + 72U);
    t16 = *((char **)t13);
    t25 = (t0 + 3368);
    t26 = (t25 + 64U);
    t27 = *((char **)t26);
    t28 = (t0 + 3688);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    xsi_vlog_generic_get_array_select_value(t5, 2, t11, t16, t27, 2, 1, t30, 32, 1);
    t31 = (t0 + 2568);
    xsi_vlogvar_assign_value(t31, t5, 0, 0, 2);
    xsi_set_current_line(101, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 4408);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB59:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 1208U);
    t6 = *((char **)t2);
    t2 = (t0 + 1368U);
    t7 = *((char **)t2);
    t2 = (t0 + 1528U);
    t8 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng19, 5, t0, (char)118, t3, 10, (char)118, t6, 10, (char)118, t7, 2, (char)118, t8, 1);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 3528);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3528);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 3528);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 3688);
    t25 = (t16 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_array_select_value(t4, 10, t7, t10, t13, 2, 1, t26, 32, 1);
    memset(t5, 0, 8);
    t27 = (t3 + 4);
    t28 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t27);
    t24 = *((unsigned int *)t28);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t28);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB61;

LAB60:    if (t36 != 0)
        goto LAB62;

LAB63:    t30 = (t5 + 4);
    t39 = *((unsigned int *)t30);
    t40 = (~(t39));
    t41 = *((unsigned int *)t5);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB64;

LAB65:
LAB66:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_unary_minus(t4, 10, t2, 10);
    memset(t5, 0, 8);
    t6 = (t3 + 4);
    t7 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t6);
    t24 = *((unsigned int *)t7);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t6);
    t35 = *((unsigned int *)t7);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB69;

LAB68:    if (t36 != 0)
        goto LAB70;

LAB71:    t9 = (t5 + 4);
    t39 = *((unsigned int *)t9);
    t40 = (~(t39));
    t41 = *((unsigned int *)t5);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB72;

LAB73:
LAB74:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 3368);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3368);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 3368);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 3688);
    t25 = (t16 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t26, 32, 1);
    memset(t5, 0, 8);
    t27 = (t3 + 4);
    t28 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t27);
    t24 = *((unsigned int *)t28);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t28);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB77;

LAB76:    if (t36 != 0)
        goto LAB78;

LAB79:    t30 = (t5 + 4);
    t39 = *((unsigned int *)t30);
    t40 = (~(t39));
    t41 = *((unsigned int *)t5);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB80;

LAB81:
LAB82:    xsi_set_current_line(116, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB87;

LAB85:    if (*((unsigned int *)t2) == 0)
        goto LAB84;

LAB86:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB87:    t7 = (t4 + 4);
    t32 = *((unsigned int *)t7);
    t33 = (~(t32));
    t34 = *((unsigned int *)t4);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB88;

LAB89:
LAB90:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 3688);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    goto LAB55;

LAB61:    *((unsigned int *)t5) = 1;
    goto LAB63;

LAB62:    t29 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB63;

LAB64:    xsi_set_current_line(104, ng0);

LAB67:    xsi_set_current_line(105, ng0);
    t31 = (t0 + 1048U);
    t44 = *((char **)t31);
    t31 = (t0 + 3528);
    t45 = (t31 + 56U);
    t46 = *((char **)t45);
    t48 = (t0 + 3528);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 3528);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 3688);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t47, 10, t46, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng20, 3, t0, (char)118, t44, 10, (char)118, t47, 10);
    xsi_set_current_line(106, ng0);
    xsi_vlog_finish(1);
    goto LAB66;

LAB69:    *((unsigned int *)t5) = 1;
    goto LAB71;

LAB70:    t8 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB71;

LAB72:    xsi_set_current_line(108, ng0);

LAB75:    xsi_set_current_line(109, ng0);
    t10 = (t0 + 1208U);
    t11 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng21, 2, t0, (char)118, t11, 10);
    xsi_set_current_line(110, ng0);
    xsi_vlog_finish(1);
    goto LAB74;

LAB77:    *((unsigned int *)t5) = 1;
    goto LAB79;

LAB78:    t29 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB79;

LAB80:    xsi_set_current_line(112, ng0);

LAB83:    xsi_set_current_line(113, ng0);
    t31 = (t0 + 1368U);
    t44 = *((char **)t31);
    t31 = (t0 + 3368);
    t45 = (t31 + 56U);
    t46 = *((char **)t45);
    t48 = (t0 + 3368);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 3368);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 3688);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t47, 2, t46, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng22, 3, t0, (char)118, t44, 2, (char)118, t47, 2);
    xsi_set_current_line(114, ng0);
    xsi_vlog_finish(1);
    goto LAB82;

LAB84:    *((unsigned int *)t4) = 1;
    goto LAB87;

LAB88:    xsi_set_current_line(116, ng0);

LAB91:    xsi_set_current_line(117, ng0);
    xsi_vlogfile_write(1, 0, 0, ng23, 1, t0);
    xsi_set_current_line(118, ng0);
    xsi_vlog_finish(1);
    goto LAB90;

LAB92:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB93;

LAB94:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB95;

LAB96:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB97;

LAB98:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB99;

LAB100:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB101;

LAB102:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB103;

LAB104:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB105;

LAB106:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB107;

LAB108:    xsi_set_current_line(136, ng0);
    t3 = (t0 + 1528U);
    t6 = *((char **)t3);
    t3 = (t6 + 4);
    t14 = *((unsigned int *)t3);
    t17 = (~(t14));
    t20 = *((unsigned int *)t6);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB109;

LAB110:
LAB111:    xsi_set_current_line(140, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(141, ng0);
    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB113:    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng18)));
    memset(t4, 0, 8);
    xsi_vlog_signed_less(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB114;

LAB115:    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng2)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB150;

LAB151:    xsi_set_current_line(166, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng4)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB152;

LAB153:    xsi_set_current_line(167, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng5)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB154;

LAB155:    xsi_set_current_line(168, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB156;

LAB157:    xsi_set_current_line(169, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng8)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB158;

LAB159:    xsi_set_current_line(170, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng9)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB160;

LAB161:    xsi_set_current_line(171, ng0);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng11)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB162;

LAB163:    xsi_set_current_line(172, ng0);
    t2 = ((char*)((ng27)));
    t3 = (t0 + 3528);
    t6 = (t0 + 3528);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3528);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng12)));
    xsi_vlog_generic_convert_array_indices(t4, t5, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t5 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB164;

LAB165:    xsi_set_current_line(173, ng0);
    xsi_vlogfile_write(1, 0, 0, ng28, 1, t0);
    xsi_set_current_line(174, ng0);
    t2 = ((char*)((ng29)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    xsi_set_current_line(175, ng0);
    t2 = ((char*)((ng8)));
    memset(t4, 0, 8);
    xsi_vlog_signed_unary_minus(t4, 32, t2, 32);
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 10);
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t0 + 3208);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t10 = (t0 + 3208);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng8)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t6, t9, t12, 2, 1, t13, 32, 1);
    t16 = (t0 + 2728);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 2);
    xsi_set_current_line(177, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(178, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(179, ng0);
    t2 = (t0 + 4408);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB166;
    goto LAB1;

LAB109:    xsi_set_current_line(136, ng0);

LAB112:    xsi_set_current_line(137, ng0);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);
    xsi_set_current_line(138, ng0);
    xsi_vlog_finish(1);
    goto LAB111;

LAB114:    xsi_set_current_line(141, ng0);

LAB116:    xsi_set_current_line(142, ng0);
    t9 = (t0 + 3368);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 3368);
    t13 = (t12 + 72U);
    t16 = *((char **)t13);
    t25 = (t0 + 3368);
    t26 = (t25 + 64U);
    t27 = *((char **)t26);
    t28 = (t0 + 3688);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    xsi_vlog_generic_get_array_select_value(t5, 2, t11, t16, t27, 2, 1, t30, 32, 1);
    t31 = (t0 + 2568);
    xsi_vlogvar_assign_value(t31, t5, 0, 0, 2);
    xsi_set_current_line(143, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(144, ng0);
    t2 = (t0 + 4408);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB117;
    goto LAB1;

LAB117:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 1208U);
    t6 = *((char **)t2);
    t2 = (t0 + 1368U);
    t7 = *((char **)t2);
    t2 = (t0 + 1528U);
    t8 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng19, 5, t0, (char)118, t3, 10, (char)118, t6, 10, (char)118, t7, 2, (char)118, t8, 1);
    xsi_set_current_line(146, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 3528);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3528);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 3528);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 3688);
    t25 = (t16 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_array_select_value(t4, 10, t7, t10, t13, 2, 1, t26, 32, 1);
    memset(t5, 0, 8);
    t27 = (t3 + 4);
    t28 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t27);
    t24 = *((unsigned int *)t28);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t28);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB119;

LAB118:    if (t36 != 0)
        goto LAB120;

LAB121:    t30 = (t5 + 4);
    t39 = *((unsigned int *)t30);
    t40 = (~(t39));
    t41 = *((unsigned int *)t5);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB122;

LAB123:
LAB124:    xsi_set_current_line(150, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_unary_minus(t4, 10, t2, 10);
    memset(t5, 0, 8);
    t6 = (t3 + 4);
    t7 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t6);
    t24 = *((unsigned int *)t7);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t6);
    t35 = *((unsigned int *)t7);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB127;

LAB126:    if (t36 != 0)
        goto LAB128;

LAB129:    t9 = (t5 + 4);
    t39 = *((unsigned int *)t9);
    t40 = (~(t39));
    t41 = *((unsigned int *)t5);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB130;

LAB131:
LAB132:    xsi_set_current_line(154, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 3368);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3368);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 3368);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 3688);
    t25 = (t16 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t26, 32, 1);
    memset(t5, 0, 8);
    t27 = (t3 + 4);
    t28 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t27);
    t24 = *((unsigned int *)t28);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t28);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB135;

LAB134:    if (t36 != 0)
        goto LAB136;

LAB137:    t30 = (t5 + 4);
    t39 = *((unsigned int *)t30);
    t40 = (~(t39));
    t41 = *((unsigned int *)t5);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB138;

LAB139:
LAB140:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB145;

LAB143:    if (*((unsigned int *)t2) == 0)
        goto LAB142;

LAB144:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB145:    t7 = (t4 + 4);
    t32 = *((unsigned int *)t7);
    t33 = (~(t32));
    t34 = *((unsigned int *)t4);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB146;

LAB147:
LAB148:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 3688);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    goto LAB113;

LAB119:    *((unsigned int *)t5) = 1;
    goto LAB121;

LAB120:    t29 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB121;

LAB122:    xsi_set_current_line(146, ng0);

LAB125:    xsi_set_current_line(147, ng0);
    t31 = (t0 + 1048U);
    t44 = *((char **)t31);
    t31 = (t0 + 3528);
    t45 = (t31 + 56U);
    t46 = *((char **)t45);
    t48 = (t0 + 3528);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 3528);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 3688);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t47, 10, t46, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng20, 3, t0, (char)118, t44, 10, (char)118, t47, 10);
    xsi_set_current_line(148, ng0);
    xsi_vlog_finish(1);
    goto LAB124;

LAB127:    *((unsigned int *)t5) = 1;
    goto LAB129;

LAB128:    t8 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB129;

LAB130:    xsi_set_current_line(150, ng0);

LAB133:    xsi_set_current_line(151, ng0);
    t10 = (t0 + 1208U);
    t11 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng21, 2, t0, (char)118, t11, 10);
    xsi_set_current_line(152, ng0);
    xsi_vlog_finish(1);
    goto LAB132;

LAB135:    *((unsigned int *)t5) = 1;
    goto LAB137;

LAB136:    t29 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB137;

LAB138:    xsi_set_current_line(154, ng0);

LAB141:    xsi_set_current_line(155, ng0);
    t31 = (t0 + 1368U);
    t44 = *((char **)t31);
    t31 = (t0 + 3368);
    t45 = (t31 + 56U);
    t46 = *((char **)t45);
    t48 = (t0 + 3368);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 3368);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 3688);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t47, 2, t46, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng22, 3, t0, (char)118, t44, 2, (char)118, t47, 2);
    xsi_set_current_line(156, ng0);
    xsi_vlog_finish(1);
    goto LAB140;

LAB142:    *((unsigned int *)t4) = 1;
    goto LAB145;

LAB146:    xsi_set_current_line(158, ng0);

LAB149:    xsi_set_current_line(159, ng0);
    xsi_vlogfile_write(1, 0, 0, ng23, 1, t0);
    xsi_set_current_line(160, ng0);
    xsi_vlog_finish(1);
    goto LAB148;

LAB150:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB151;

LAB152:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB153;

LAB154:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB155;

LAB156:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB157;

LAB158:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB159;

LAB160:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB161;

LAB162:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB163;

LAB164:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB165;

LAB166:    xsi_set_current_line(180, ng0);
    t3 = (t0 + 1528U);
    t6 = *((char **)t3);
    t3 = (t6 + 4);
    t14 = *((unsigned int *)t3);
    t17 = (~(t14));
    t20 = *((unsigned int *)t6);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB167;

LAB168:
LAB169:    xsi_set_current_line(184, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(185, ng0);
    xsi_set_current_line(185, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB171:    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng18)));
    memset(t4, 0, 8);
    xsi_vlog_signed_less(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB172;

LAB173:    xsi_set_current_line(208, ng0);
    t2 = (t0 + 4408);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB208;
    goto LAB1;

LAB167:    xsi_set_current_line(180, ng0);

LAB170:    xsi_set_current_line(181, ng0);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);
    xsi_set_current_line(182, ng0);
    xsi_vlog_finish(1);
    goto LAB169;

LAB172:    xsi_set_current_line(185, ng0);

LAB174:    xsi_set_current_line(186, ng0);
    t9 = (t0 + 3368);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 3368);
    t13 = (t12 + 72U);
    t16 = *((char **)t13);
    t25 = (t0 + 3368);
    t26 = (t25 + 64U);
    t27 = *((char **)t26);
    t28 = (t0 + 3688);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    xsi_vlog_generic_get_array_select_value(t5, 2, t11, t16, t27, 2, 1, t30, 32, 1);
    t31 = (t0 + 2568);
    xsi_vlogvar_assign_value(t31, t5, 0, 0, 2);
    xsi_set_current_line(187, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(188, ng0);
    t2 = (t0 + 4408);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB175;
    goto LAB1;

LAB175:    xsi_set_current_line(189, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 1208U);
    t6 = *((char **)t2);
    t2 = (t0 + 1368U);
    t7 = *((char **)t2);
    t2 = (t0 + 1528U);
    t8 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng19, 5, t0, (char)118, t3, 10, (char)118, t6, 10, (char)118, t7, 2, (char)118, t8, 1);
    xsi_set_current_line(190, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 3528);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3528);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 3528);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 3688);
    t25 = (t16 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_array_select_value(t4, 10, t7, t10, t13, 2, 1, t26, 32, 1);
    memset(t5, 0, 8);
    t27 = (t3 + 4);
    t28 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t27);
    t24 = *((unsigned int *)t28);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t28);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB177;

LAB176:    if (t36 != 0)
        goto LAB178;

LAB179:    t30 = (t5 + 4);
    t39 = *((unsigned int *)t30);
    t40 = (~(t39));
    t41 = *((unsigned int *)t5);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB180;

LAB181:
LAB182:    xsi_set_current_line(194, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng14)));
    memset(t4, 0, 8);
    t6 = (t3 + 4);
    t7 = (t2 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t2);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t6);
    t24 = *((unsigned int *)t7);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t6);
    t35 = *((unsigned int *)t7);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB185;

LAB184:    if (t36 != 0)
        goto LAB186;

LAB187:    t9 = (t4 + 4);
    t39 = *((unsigned int *)t9);
    t40 = (~(t39));
    t41 = *((unsigned int *)t4);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB188;

LAB189:
LAB190:    xsi_set_current_line(198, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 3368);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 3368);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 3368);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 3688);
    t25 = (t16 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t26, 32, 1);
    memset(t5, 0, 8);
    t27 = (t3 + 4);
    t28 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t27);
    t24 = *((unsigned int *)t28);
    t32 = (t21 ^ t24);
    t33 = (t20 | t32);
    t34 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t28);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB193;

LAB192:    if (t36 != 0)
        goto LAB194;

LAB195:    t30 = (t5 + 4);
    t39 = *((unsigned int *)t30);
    t40 = (~(t39));
    t41 = *((unsigned int *)t5);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB196;

LAB197:
LAB198:    xsi_set_current_line(202, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB203;

LAB201:    if (*((unsigned int *)t2) == 0)
        goto LAB200;

LAB202:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB203:    t7 = (t4 + 4);
    t32 = *((unsigned int *)t7);
    t33 = (~(t32));
    t34 = *((unsigned int *)t4);
    t35 = (t34 & t33);
    t36 = (t35 != 0);
    if (t36 > 0)
        goto LAB204;

LAB205:
LAB206:    xsi_set_current_line(185, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 3688);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    goto LAB171;

LAB177:    *((unsigned int *)t5) = 1;
    goto LAB179;

LAB178:    t29 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB179;

LAB180:    xsi_set_current_line(190, ng0);

LAB183:    xsi_set_current_line(191, ng0);
    t31 = (t0 + 1048U);
    t44 = *((char **)t31);
    t31 = (t0 + 3528);
    t45 = (t31 + 56U);
    t46 = *((char **)t45);
    t48 = (t0 + 3528);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 3528);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 3688);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t47, 10, t46, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng20, 3, t0, (char)118, t44, 10, (char)118, t47, 10);
    xsi_set_current_line(192, ng0);
    xsi_vlog_finish(1);
    goto LAB182;

LAB185:    *((unsigned int *)t4) = 1;
    goto LAB187;

LAB186:    t8 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB187;

LAB188:    xsi_set_current_line(194, ng0);

LAB191:    xsi_set_current_line(195, ng0);
    t10 = (t0 + 1208U);
    t11 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng21, 2, t0, (char)118, t11, 10);
    xsi_set_current_line(196, ng0);
    xsi_vlog_finish(1);
    goto LAB190;

LAB193:    *((unsigned int *)t5) = 1;
    goto LAB195;

LAB194:    t29 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB195;

LAB196:    xsi_set_current_line(198, ng0);

LAB199:    xsi_set_current_line(199, ng0);
    t31 = (t0 + 1368U);
    t44 = *((char **)t31);
    t31 = (t0 + 3368);
    t45 = (t31 + 56U);
    t46 = *((char **)t45);
    t48 = (t0 + 3368);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 3368);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 3688);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t47, 2, t46, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng22, 3, t0, (char)118, t44, 2, (char)118, t47, 2);
    xsi_set_current_line(200, ng0);
    xsi_vlog_finish(1);
    goto LAB198;

LAB200:    *((unsigned int *)t4) = 1;
    goto LAB203;

LAB204:    xsi_set_current_line(202, ng0);

LAB207:    xsi_set_current_line(203, ng0);
    xsi_vlogfile_write(1, 0, 0, ng23, 1, t0);
    xsi_set_current_line(204, ng0);
    xsi_vlog_finish(1);
    goto LAB206;

LAB208:    xsi_set_current_line(209, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}

static void Always_212_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;

LAB0:    t1 = (t0 + 4848U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(212, ng0);

LAB4:    xsi_set_current_line(213, ng0);
    t2 = (t0 + 4656);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(213, ng0);
    t4 = (t0 + 1928);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t7) == 0)
        goto LAB6;

LAB8:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    t14 = (t0 + 1928);
    xsi_vlogvar_assign_value(t14, t3, 0, 0, 1);
    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

}


extern void work_m_11964176682938877025_3430131090_init()
{
	static char *pe[] = {(void *)Initial_48_0,(void *)Always_212_1};
	xsi_register_didat("work_m_11964176682938877025_3430131090", "isim/SmithWatermanPE_tb_isim_beh.exe.sim/work/m_11964176682938877025_3430131090.didat");
	xsi_register_executes(pe);
}
