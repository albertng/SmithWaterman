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
static const char *ng0 = "/afs/cs.stanford.edu/group/evodevo/u/albertng/SmithWaterman/SmithWaterman/firmware/SmithWatermanPE_tb.v";
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
static const char *ng18 = "store_S_out error: Got 0 expected 1";
static const char *ng19 = "S_out error: Got %d expected %d";
static int ng20[] = {8, 0};
static const char *ng21 = "%d %d %d %d";
static const char *ng22 = "V_out error: Got %d expected %d";
static const char *ng23 = "F_out error: Got %d expected -1";
static const char *ng24 = "T_out error: Got %d expected %d";
static const char *ng25 = "Init_out error: Got 0 expected 1";
static const char *ng26 = "store_S_out error: Got 1 expected 0";
static unsigned int ng27[] = {6U, 0U};
static const char *ng28 = "V=0, F=0, S='C' test";
static unsigned int ng29[] = {20U, 0U};
static unsigned int ng30[] = {18U, 0U};
static const char *ng31 = "V=10, F=-4, S='T' test";
static int ng32[] = {10, 0};



static void Initial_63_0(char *t0)
{
    char t4[8];
    char t5[8];
    char t45[8];
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
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;

LAB0:    t1 = (t0 + 5560U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(63, ng0);

LAB4:    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4168);
    t6 = (t0 + 4168);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4168);
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

LAB6:    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4168);
    t6 = (t0 + 4168);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4168);
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

LAB8:    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4168);
    t6 = (t0 + 4168);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4168);
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

LAB10:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4168);
    t6 = (t0 + 4168);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4168);
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

LAB12:    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 4168);
    t6 = (t0 + 4168);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4168);
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

LAB14:    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4168);
    t6 = (t0 + 4168);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4168);
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

LAB16:    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4328);
    t6 = (t0 + 4328);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4328);
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

LAB18:    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4328);
    t6 = (t0 + 4328);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4328);
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

LAB20:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4328);
    t6 = (t0 + 4328);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4328);
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

LAB22:    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 4328);
    t6 = (t0 + 4328);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4328);
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

LAB24:    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4328);
    t6 = (t0 + 4328);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4328);
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

LAB26:    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4328);
    t6 = (t0 + 4328);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4328);
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

LAB28:    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 4328);
    t6 = (t0 + 4328);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4328);
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

LAB30:    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4328);
    t6 = (t0 + 4328);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4328);
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

LAB32:    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 5368);
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

LAB33:    xsi_set_current_line(95, ng0);
    t3 = ((char*)((ng2)));
    t6 = (t0 + 2568);
    xsi_vlogvar_assign_value(t6, t3, 0, 0, 1);
    xsi_set_current_line(100, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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

LAB35:    xsi_set_current_line(101, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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

LAB37:    xsi_set_current_line(102, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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

LAB39:    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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

LAB41:    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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

LAB43:    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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

LAB45:    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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

LAB47:    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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

LAB49:    xsi_set_current_line(108, ng0);
    xsi_vlogfile_write(1, 0, 0, ng16, 1, t0);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 4168);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t0 + 4168);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t10 = (t0 + 4168);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng2)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t6, t9, t12, 2, 1, t13, 32, 1);
    t16 = (t0 + 3208);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 2);
    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 5368);
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

LAB50:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 2008U);
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
LAB53:    xsi_set_current_line(116, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB58;

LAB56:    if (*((unsigned int *)t2) == 0)
        goto LAB55;

LAB57:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB58:    t7 = (t4 + 4);
    t25 = *((unsigned int *)t7);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB59;

LAB60:
LAB61:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 4168);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4168);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4168);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = ((char*)((ng2)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t16, 32, 1);
    memset(t5, 0, 8);
    t30 = (t3 + 4);
    t31 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t30);
    t24 = *((unsigned int *)t31);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t30);
    t28 = *((unsigned int *)t31);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB64;

LAB63:    if (t29 != 0)
        goto LAB65;

LAB66:    t35 = (t5 + 4);
    t36 = *((unsigned int *)t35);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB67;

LAB68:
LAB69:    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(125, ng0);
    xsi_set_current_line(125, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB71:    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng20)));
    memset(t4, 0, 8);
    xsi_vlog_signed_less(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB72;

LAB73:    xsi_set_current_line(153, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB112;

LAB113:    xsi_set_current_line(154, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB114;

LAB115:    xsi_set_current_line(155, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB116;

LAB117:    xsi_set_current_line(156, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB118;

LAB119:    xsi_set_current_line(157, ng0);
    t2 = ((char*)((ng27)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB120;

LAB121:    xsi_set_current_line(158, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB122;

LAB123:    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB124;

LAB125:    xsi_set_current_line(160, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB126;

LAB127:    xsi_set_current_line(161, ng0);
    xsi_vlogfile_write(1, 0, 0, ng28, 1, t0);
    xsi_set_current_line(162, ng0);
    t2 = (t0 + 4168);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t0 + 4168);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t10 = (t0 + 4168);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t6, t9, t12, 2, 1, t13, 32, 1);
    t16 = (t0 + 3208);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 2);
    xsi_set_current_line(163, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(164, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(165, ng0);
    t2 = (t0 + 5368);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB128;
    goto LAB1;

LAB51:    xsi_set_current_line(112, ng0);

LAB54:    xsi_set_current_line(113, ng0);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);
    xsi_set_current_line(114, ng0);
    xsi_vlog_finish(1);
    goto LAB53;

LAB55:    *((unsigned int *)t4) = 1;
    goto LAB58;

LAB59:    xsi_set_current_line(116, ng0);

LAB62:    xsi_set_current_line(117, ng0);
    xsi_vlogfile_write(1, 0, 0, ng18, 1, t0);
    xsi_set_current_line(118, ng0);
    xsi_vlog_finish(1);
    goto LAB61;

LAB64:    *((unsigned int *)t5) = 1;
    goto LAB66;

LAB65:    t34 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB66;

LAB67:    xsi_set_current_line(120, ng0);

LAB70:    xsi_set_current_line(121, ng0);
    t41 = (t0 + 1528U);
    t42 = *((char **)t41);
    t41 = (t0 + 4168);
    t43 = (t41 + 56U);
    t44 = *((char **)t43);
    t46 = (t0 + 4168);
    t47 = (t46 + 72U);
    t48 = *((char **)t47);
    t49 = (t0 + 4168);
    t50 = (t49 + 64U);
    t51 = *((char **)t50);
    t52 = ((char*)((ng2)));
    xsi_vlog_generic_get_array_select_value(t45, 2, t44, t48, t51, 2, 1, t52, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng19, 3, t0, (char)118, t42, 2, (char)118, t45, 2);
    xsi_set_current_line(122, ng0);
    xsi_vlog_finish(1);
    goto LAB69;

LAB72:    xsi_set_current_line(125, ng0);

LAB74:    xsi_set_current_line(126, ng0);
    t9 = (t0 + 4328);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 4328);
    t13 = (t12 + 72U);
    t16 = *((char **)t13);
    t30 = (t0 + 4328);
    t31 = (t30 + 64U);
    t34 = *((char **)t31);
    t35 = (t0 + 4648);
    t41 = (t35 + 56U);
    t42 = *((char **)t41);
    xsi_vlog_generic_get_array_select_value(t5, 2, t11, t16, t34, 2, 1, t42, 32, 1);
    t43 = (t0 + 3048);
    xsi_vlogvar_assign_value(t43, t5, 0, 0, 2);
    xsi_set_current_line(127, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 5368);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB75;
    goto LAB1;

LAB75:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 1368U);
    t6 = *((char **)t2);
    t2 = (t0 + 1688U);
    t7 = *((char **)t2);
    t2 = (t0 + 2008U);
    t8 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng21, 5, t0, (char)118, t3, 10, (char)118, t6, 10, (char)118, t7, 2, (char)118, t8, 1);
    xsi_set_current_line(130, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 4488);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4488);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4488);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 4648);
    t30 = (t16 + 56U);
    t31 = *((char **)t30);
    xsi_vlog_generic_get_array_select_value(t4, 10, t7, t10, t13, 2, 1, t31, 32, 1);
    memset(t5, 0, 8);
    t34 = (t3 + 4);
    t35 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t34);
    t28 = *((unsigned int *)t35);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB77;

LAB76:    if (t29 != 0)
        goto LAB78;

LAB79:    t42 = (t5 + 4);
    t36 = *((unsigned int *)t42);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB80;

LAB81:
LAB82:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 1368U);
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
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t7);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB85;

LAB84:    if (t29 != 0)
        goto LAB86;

LAB87:    t9 = (t5 + 4);
    t36 = *((unsigned int *)t9);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB88;

LAB89:
LAB90:    xsi_set_current_line(138, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 4328);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4328);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4328);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 4648);
    t30 = (t16 + 56U);
    t31 = *((char **)t30);
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t31, 32, 1);
    memset(t5, 0, 8);
    t34 = (t3 + 4);
    t35 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t34);
    t28 = *((unsigned int *)t35);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB93;

LAB92:    if (t29 != 0)
        goto LAB94;

LAB95:    t42 = (t5 + 4);
    t36 = *((unsigned int *)t42);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB96;

LAB97:
LAB98:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB103;

LAB101:    if (*((unsigned int *)t2) == 0)
        goto LAB100;

LAB102:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB103:    t7 = (t4 + 4);
    t25 = *((unsigned int *)t7);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB104;

LAB105:
LAB106:    xsi_set_current_line(146, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB108;

LAB109:
LAB110:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 4648);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    goto LAB71;

LAB77:    *((unsigned int *)t5) = 1;
    goto LAB79;

LAB78:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB79;

LAB80:    xsi_set_current_line(130, ng0);

LAB83:    xsi_set_current_line(131, ng0);
    t43 = (t0 + 1048U);
    t44 = *((char **)t43);
    t43 = (t0 + 4488);
    t46 = (t43 + 56U);
    t47 = *((char **)t46);
    t48 = (t0 + 4488);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 4488);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 4648);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t45, 10, t47, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng22, 3, t0, (char)118, t44, 10, (char)118, t45, 10);
    xsi_set_current_line(132, ng0);
    xsi_vlog_finish(1);
    goto LAB82;

LAB85:    *((unsigned int *)t5) = 1;
    goto LAB87;

LAB86:    t8 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB87;

LAB88:    xsi_set_current_line(134, ng0);

LAB91:    xsi_set_current_line(135, ng0);
    t10 = (t0 + 1368U);
    t11 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng23, 2, t0, (char)118, t11, 10);
    xsi_set_current_line(136, ng0);
    xsi_vlog_finish(1);
    goto LAB90;

LAB93:    *((unsigned int *)t5) = 1;
    goto LAB95;

LAB94:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB95;

LAB96:    xsi_set_current_line(138, ng0);

LAB99:    xsi_set_current_line(139, ng0);
    t43 = (t0 + 1688U);
    t44 = *((char **)t43);
    t43 = (t0 + 4328);
    t46 = (t43 + 56U);
    t47 = *((char **)t46);
    t48 = (t0 + 4328);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 4328);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 4648);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t45, 2, t47, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng24, 3, t0, (char)118, t44, 2, (char)118, t45, 2);
    xsi_set_current_line(140, ng0);
    xsi_vlog_finish(1);
    goto LAB98;

LAB100:    *((unsigned int *)t4) = 1;
    goto LAB103;

LAB104:    xsi_set_current_line(142, ng0);

LAB107:    xsi_set_current_line(143, ng0);
    xsi_vlogfile_write(1, 0, 0, ng25, 1, t0);
    xsi_set_current_line(144, ng0);
    xsi_vlog_finish(1);
    goto LAB106;

LAB108:    xsi_set_current_line(146, ng0);

LAB111:    xsi_set_current_line(147, ng0);
    xsi_vlogfile_write(1, 0, 0, ng26, 1, t0);
    xsi_set_current_line(148, ng0);
    xsi_vlog_finish(1);
    goto LAB110;

LAB112:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB113;

LAB114:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB115;

LAB116:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB117;

LAB118:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB119;

LAB120:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB121;

LAB122:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB123;

LAB124:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB125;

LAB126:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB127;

LAB128:    xsi_set_current_line(166, ng0);
    t3 = (t0 + 2008U);
    t6 = *((char **)t3);
    t3 = (t6 + 4);
    t14 = *((unsigned int *)t3);
    t17 = (~(t14));
    t20 = *((unsigned int *)t6);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB129;

LAB130:
LAB131:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB136;

LAB134:    if (*((unsigned int *)t2) == 0)
        goto LAB133;

LAB135:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB136:    t7 = (t4 + 4);
    t25 = *((unsigned int *)t7);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB137;

LAB138:
LAB139:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 4168);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4168);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4168);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t16, 32, 1);
    memset(t5, 0, 8);
    t30 = (t3 + 4);
    t31 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t30);
    t24 = *((unsigned int *)t31);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t30);
    t28 = *((unsigned int *)t31);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB142;

LAB141:    if (t29 != 0)
        goto LAB143;

LAB144:    t35 = (t5 + 4);
    t36 = *((unsigned int *)t35);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB145;

LAB146:
LAB147:    xsi_set_current_line(178, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(179, ng0);
    xsi_set_current_line(179, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB149:    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng20)));
    memset(t4, 0, 8);
    xsi_vlog_signed_less(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB150;

LAB151:    xsi_set_current_line(207, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB190;

LAB191:    xsi_set_current_line(208, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB192;

LAB193:    xsi_set_current_line(209, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB194;

LAB195:    xsi_set_current_line(210, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB196;

LAB197:    xsi_set_current_line(211, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB198;

LAB199:    xsi_set_current_line(212, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB200;

LAB201:    xsi_set_current_line(213, ng0);
    t2 = ((char*)((ng29)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB202;

LAB203:    xsi_set_current_line(214, ng0);
    t2 = ((char*)((ng30)));
    t3 = (t0 + 4488);
    t6 = (t0 + 4488);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4488);
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
        goto LAB204;

LAB205:    xsi_set_current_line(215, ng0);
    xsi_vlogfile_write(1, 0, 0, ng31, 1, t0);
    xsi_set_current_line(216, ng0);
    t2 = ((char*)((ng32)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    xsi_set_current_line(217, ng0);
    t2 = ((char*)((ng8)));
    memset(t4, 0, 8);
    xsi_vlog_signed_unary_minus(t4, 32, t2, 32);
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 10);
    xsi_set_current_line(218, ng0);
    t2 = (t0 + 4168);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t0 + 4168);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t10 = (t0 + 4168);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng8)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t6, t9, t12, 2, 1, t13, 32, 1);
    t16 = (t0 + 3208);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 2);
    xsi_set_current_line(219, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(220, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(221, ng0);
    t2 = (t0 + 5368);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB206;
    goto LAB1;

LAB129:    xsi_set_current_line(166, ng0);

LAB132:    xsi_set_current_line(167, ng0);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);
    xsi_set_current_line(168, ng0);
    xsi_vlog_finish(1);
    goto LAB131;

LAB133:    *((unsigned int *)t4) = 1;
    goto LAB136;

LAB137:    xsi_set_current_line(170, ng0);

LAB140:    xsi_set_current_line(171, ng0);
    xsi_vlogfile_write(1, 0, 0, ng18, 1, t0);
    xsi_set_current_line(172, ng0);
    xsi_vlog_finish(1);
    goto LAB139;

LAB142:    *((unsigned int *)t5) = 1;
    goto LAB144;

LAB143:    t34 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB144;

LAB145:    xsi_set_current_line(174, ng0);

LAB148:    xsi_set_current_line(175, ng0);
    t41 = (t0 + 1528U);
    t42 = *((char **)t41);
    t41 = (t0 + 4168);
    t43 = (t41 + 56U);
    t44 = *((char **)t43);
    t46 = (t0 + 4168);
    t47 = (t46 + 72U);
    t48 = *((char **)t47);
    t49 = (t0 + 4168);
    t50 = (t49 + 64U);
    t51 = *((char **)t50);
    t52 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t45, 2, t44, t48, t51, 2, 1, t52, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng19, 3, t0, (char)118, t42, 2, (char)118, t45, 2);
    xsi_set_current_line(176, ng0);
    xsi_vlog_finish(1);
    goto LAB147;

LAB150:    xsi_set_current_line(179, ng0);

LAB152:    xsi_set_current_line(180, ng0);
    t9 = (t0 + 4328);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 4328);
    t13 = (t12 + 72U);
    t16 = *((char **)t13);
    t30 = (t0 + 4328);
    t31 = (t30 + 64U);
    t34 = *((char **)t31);
    t35 = (t0 + 4648);
    t41 = (t35 + 56U);
    t42 = *((char **)t41);
    xsi_vlog_generic_get_array_select_value(t5, 2, t11, t16, t34, 2, 1, t42, 32, 1);
    t43 = (t0 + 3048);
    xsi_vlogvar_assign_value(t43, t5, 0, 0, 2);
    xsi_set_current_line(181, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(182, ng0);
    t2 = (t0 + 5368);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB153;
    goto LAB1;

LAB153:    xsi_set_current_line(183, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 1368U);
    t6 = *((char **)t2);
    t2 = (t0 + 1688U);
    t7 = *((char **)t2);
    t2 = (t0 + 2008U);
    t8 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng21, 5, t0, (char)118, t3, 10, (char)118, t6, 10, (char)118, t7, 2, (char)118, t8, 1);
    xsi_set_current_line(184, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 4488);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4488);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4488);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 4648);
    t30 = (t16 + 56U);
    t31 = *((char **)t30);
    xsi_vlog_generic_get_array_select_value(t4, 10, t7, t10, t13, 2, 1, t31, 32, 1);
    memset(t5, 0, 8);
    t34 = (t3 + 4);
    t35 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t34);
    t28 = *((unsigned int *)t35);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB155;

LAB154:    if (t29 != 0)
        goto LAB156;

LAB157:    t42 = (t5 + 4);
    t36 = *((unsigned int *)t42);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB158;

LAB159:
LAB160:    xsi_set_current_line(188, ng0);
    t2 = (t0 + 1368U);
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
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t7);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB163;

LAB162:    if (t29 != 0)
        goto LAB164;

LAB165:    t9 = (t5 + 4);
    t36 = *((unsigned int *)t9);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB166;

LAB167:
LAB168:    xsi_set_current_line(192, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 4328);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4328);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4328);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 4648);
    t30 = (t16 + 56U);
    t31 = *((char **)t30);
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t31, 32, 1);
    memset(t5, 0, 8);
    t34 = (t3 + 4);
    t35 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t34);
    t28 = *((unsigned int *)t35);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB171;

LAB170:    if (t29 != 0)
        goto LAB172;

LAB173:    t42 = (t5 + 4);
    t36 = *((unsigned int *)t42);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB174;

LAB175:
LAB176:    xsi_set_current_line(196, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB181;

LAB179:    if (*((unsigned int *)t2) == 0)
        goto LAB178;

LAB180:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB181:    t7 = (t4 + 4);
    t25 = *((unsigned int *)t7);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB182;

LAB183:
LAB184:    xsi_set_current_line(200, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB186;

LAB187:
LAB188:    xsi_set_current_line(179, ng0);
    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 4648);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    goto LAB149;

LAB155:    *((unsigned int *)t5) = 1;
    goto LAB157;

LAB156:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB157;

LAB158:    xsi_set_current_line(184, ng0);

LAB161:    xsi_set_current_line(185, ng0);
    t43 = (t0 + 1048U);
    t44 = *((char **)t43);
    t43 = (t0 + 4488);
    t46 = (t43 + 56U);
    t47 = *((char **)t46);
    t48 = (t0 + 4488);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 4488);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 4648);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t45, 10, t47, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng22, 3, t0, (char)118, t44, 10, (char)118, t45, 10);
    xsi_set_current_line(186, ng0);
    xsi_vlog_finish(1);
    goto LAB160;

LAB163:    *((unsigned int *)t5) = 1;
    goto LAB165;

LAB164:    t8 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB165;

LAB166:    xsi_set_current_line(188, ng0);

LAB169:    xsi_set_current_line(189, ng0);
    t10 = (t0 + 1368U);
    t11 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng23, 2, t0, (char)118, t11, 10);
    xsi_set_current_line(190, ng0);
    xsi_vlog_finish(1);
    goto LAB168;

LAB171:    *((unsigned int *)t5) = 1;
    goto LAB173;

LAB172:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB173;

LAB174:    xsi_set_current_line(192, ng0);

LAB177:    xsi_set_current_line(193, ng0);
    t43 = (t0 + 1688U);
    t44 = *((char **)t43);
    t43 = (t0 + 4328);
    t46 = (t43 + 56U);
    t47 = *((char **)t46);
    t48 = (t0 + 4328);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 4328);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 4648);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t45, 2, t47, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng24, 3, t0, (char)118, t44, 2, (char)118, t45, 2);
    xsi_set_current_line(194, ng0);
    xsi_vlog_finish(1);
    goto LAB176;

LAB178:    *((unsigned int *)t4) = 1;
    goto LAB181;

LAB182:    xsi_set_current_line(196, ng0);

LAB185:    xsi_set_current_line(197, ng0);
    xsi_vlogfile_write(1, 0, 0, ng25, 1, t0);
    xsi_set_current_line(198, ng0);
    xsi_vlog_finish(1);
    goto LAB184;

LAB186:    xsi_set_current_line(200, ng0);

LAB189:    xsi_set_current_line(201, ng0);
    xsi_vlogfile_write(1, 0, 0, ng26, 1, t0);
    xsi_set_current_line(202, ng0);
    xsi_vlog_finish(1);
    goto LAB188;

LAB190:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB191;

LAB192:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB193;

LAB194:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB195;

LAB196:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB197;

LAB198:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB199;

LAB200:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB201;

LAB202:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB203;

LAB204:    t20 = *((unsigned int *)t4);
    t21 = *((unsigned int *)t5);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t5), t23);
    goto LAB205;

LAB206:    xsi_set_current_line(222, ng0);
    t3 = (t0 + 2008U);
    t6 = *((char **)t3);
    t3 = (t6 + 4);
    t14 = *((unsigned int *)t3);
    t17 = (~(t14));
    t20 = *((unsigned int *)t6);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB207;

LAB208:
LAB209:    xsi_set_current_line(226, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB214;

LAB212:    if (*((unsigned int *)t2) == 0)
        goto LAB211;

LAB213:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB214:    t7 = (t4 + 4);
    t25 = *((unsigned int *)t7);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB215;

LAB216:
LAB217:    xsi_set_current_line(230, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 4168);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4168);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4168);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = ((char*)((ng8)));
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t16, 32, 1);
    memset(t5, 0, 8);
    t30 = (t3 + 4);
    t31 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t30);
    t24 = *((unsigned int *)t31);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t30);
    t28 = *((unsigned int *)t31);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB220;

LAB219:    if (t29 != 0)
        goto LAB221;

LAB222:    t35 = (t5 + 4);
    t36 = *((unsigned int *)t35);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB223;

LAB224:
LAB225:    xsi_set_current_line(234, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(235, ng0);
    xsi_set_current_line(235, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB227:    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng20)));
    memset(t4, 0, 8);
    xsi_vlog_signed_less(t4, 32, t6, 32, t7, 32);
    t8 = (t4 + 4);
    t14 = *((unsigned int *)t8);
    t17 = (~(t14));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB228;

LAB229:    xsi_set_current_line(262, ng0);
    t2 = (t0 + 5368);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB268;
    goto LAB1;

LAB207:    xsi_set_current_line(222, ng0);

LAB210:    xsi_set_current_line(223, ng0);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);
    xsi_set_current_line(224, ng0);
    xsi_vlog_finish(1);
    goto LAB209;

LAB211:    *((unsigned int *)t4) = 1;
    goto LAB214;

LAB215:    xsi_set_current_line(226, ng0);

LAB218:    xsi_set_current_line(227, ng0);
    xsi_vlogfile_write(1, 0, 0, ng18, 1, t0);
    xsi_set_current_line(228, ng0);
    xsi_vlog_finish(1);
    goto LAB217;

LAB220:    *((unsigned int *)t5) = 1;
    goto LAB222;

LAB221:    t34 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB222;

LAB223:    xsi_set_current_line(230, ng0);

LAB226:    xsi_set_current_line(231, ng0);
    t41 = (t0 + 1528U);
    t42 = *((char **)t41);
    t41 = (t0 + 4168);
    t43 = (t41 + 56U);
    t44 = *((char **)t43);
    t46 = (t0 + 4168);
    t47 = (t46 + 72U);
    t48 = *((char **)t47);
    t49 = (t0 + 4168);
    t50 = (t49 + 64U);
    t51 = *((char **)t50);
    t52 = ((char*)((ng8)));
    xsi_vlog_generic_get_array_select_value(t45, 2, t44, t48, t51, 2, 1, t52, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng19, 3, t0, (char)118, t42, 2, (char)118, t45, 2);
    xsi_set_current_line(232, ng0);
    xsi_vlog_finish(1);
    goto LAB225;

LAB228:    xsi_set_current_line(235, ng0);

LAB230:    xsi_set_current_line(236, ng0);
    t9 = (t0 + 4328);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 4328);
    t13 = (t12 + 72U);
    t16 = *((char **)t13);
    t30 = (t0 + 4328);
    t31 = (t30 + 64U);
    t34 = *((char **)t31);
    t35 = (t0 + 4648);
    t41 = (t35 + 56U);
    t42 = *((char **)t41);
    xsi_vlog_generic_get_array_select_value(t5, 2, t11, t16, t34, 2, 1, t42, 32, 1);
    t43 = (t0 + 3048);
    xsi_vlogvar_assign_value(t43, t5, 0, 0, 2);
    xsi_set_current_line(237, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(238, ng0);
    t2 = (t0 + 5368);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB231;
    goto LAB1;

LAB231:    xsi_set_current_line(239, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 1368U);
    t6 = *((char **)t2);
    t2 = (t0 + 1688U);
    t7 = *((char **)t2);
    t2 = (t0 + 2008U);
    t8 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng21, 5, t0, (char)118, t3, 10, (char)118, t6, 10, (char)118, t7, 2, (char)118, t8, 1);
    xsi_set_current_line(240, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 4488);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4488);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4488);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 4648);
    t30 = (t16 + 56U);
    t31 = *((char **)t30);
    xsi_vlog_generic_get_array_select_value(t4, 10, t7, t10, t13, 2, 1, t31, 32, 1);
    memset(t5, 0, 8);
    t34 = (t3 + 4);
    t35 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t34);
    t28 = *((unsigned int *)t35);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB233;

LAB232:    if (t29 != 0)
        goto LAB234;

LAB235:    t42 = (t5 + 4);
    t36 = *((unsigned int *)t42);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB236;

LAB237:
LAB238:    xsi_set_current_line(244, ng0);
    t2 = (t0 + 1368U);
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
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t7);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB241;

LAB240:    if (t29 != 0)
        goto LAB242;

LAB243:    t9 = (t4 + 4);
    t36 = *((unsigned int *)t9);
    t37 = (~(t36));
    t38 = *((unsigned int *)t4);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB244;

LAB245:
LAB246:    xsi_set_current_line(248, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 4328);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 4328);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 4328);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t16 = (t0 + 4648);
    t30 = (t16 + 56U);
    t31 = *((char **)t30);
    xsi_vlog_generic_get_array_select_value(t4, 2, t7, t10, t13, 2, 1, t31, 32, 1);
    memset(t5, 0, 8);
    t34 = (t3 + 4);
    t35 = (t4 + 4);
    t14 = *((unsigned int *)t3);
    t17 = *((unsigned int *)t4);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t21 ^ t24);
    t26 = (t20 | t25);
    t27 = *((unsigned int *)t34);
    t28 = *((unsigned int *)t35);
    t29 = (t27 | t28);
    t32 = (~(t29));
    t33 = (t26 & t32);
    if (t33 != 0)
        goto LAB249;

LAB248:    if (t29 != 0)
        goto LAB250;

LAB251:    t42 = (t5 + 4);
    t36 = *((unsigned int *)t42);
    t37 = (~(t36));
    t38 = *((unsigned int *)t5);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB252;

LAB253:
LAB254:    xsi_set_current_line(252, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 & 1U);
    if (t24 != 0)
        goto LAB259;

LAB257:    if (*((unsigned int *)t2) == 0)
        goto LAB256;

LAB258:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB259:    t7 = (t4 + 4);
    t25 = *((unsigned int *)t7);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB260;

LAB261:
LAB262:    xsi_set_current_line(256, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = (~(t14));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t17);
    t24 = (t21 != 0);
    if (t24 > 0)
        goto LAB264;

LAB265:
LAB266:    xsi_set_current_line(235, ng0);
    t2 = (t0 + 4648);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t6, 32, t7, 32);
    t8 = (t0 + 4648);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 32);
    goto LAB227;

LAB233:    *((unsigned int *)t5) = 1;
    goto LAB235;

LAB234:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB235;

LAB236:    xsi_set_current_line(240, ng0);

LAB239:    xsi_set_current_line(241, ng0);
    t43 = (t0 + 1048U);
    t44 = *((char **)t43);
    t43 = (t0 + 4488);
    t46 = (t43 + 56U);
    t47 = *((char **)t46);
    t48 = (t0 + 4488);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 4488);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 4648);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t45, 10, t47, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng22, 3, t0, (char)118, t44, 10, (char)118, t45, 10);
    xsi_set_current_line(242, ng0);
    xsi_vlog_finish(1);
    goto LAB238;

LAB241:    *((unsigned int *)t4) = 1;
    goto LAB243;

LAB242:    t8 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB243;

LAB244:    xsi_set_current_line(244, ng0);

LAB247:    xsi_set_current_line(245, ng0);
    t10 = (t0 + 1368U);
    t11 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng23, 2, t0, (char)118, t11, 10);
    xsi_set_current_line(246, ng0);
    xsi_vlog_finish(1);
    goto LAB246;

LAB249:    *((unsigned int *)t5) = 1;
    goto LAB251;

LAB250:    t41 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB251;

LAB252:    xsi_set_current_line(248, ng0);

LAB255:    xsi_set_current_line(249, ng0);
    t43 = (t0 + 1688U);
    t44 = *((char **)t43);
    t43 = (t0 + 4328);
    t46 = (t43 + 56U);
    t47 = *((char **)t46);
    t48 = (t0 + 4328);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t0 + 4328);
    t52 = (t51 + 64U);
    t53 = *((char **)t52);
    t54 = (t0 + 4648);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    xsi_vlog_generic_get_array_select_value(t45, 2, t47, t50, t53, 2, 1, t56, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng24, 3, t0, (char)118, t44, 2, (char)118, t45, 2);
    xsi_set_current_line(250, ng0);
    xsi_vlog_finish(1);
    goto LAB254;

LAB256:    *((unsigned int *)t4) = 1;
    goto LAB259;

LAB260:    xsi_set_current_line(252, ng0);

LAB263:    xsi_set_current_line(253, ng0);
    xsi_vlogfile_write(1, 0, 0, ng25, 1, t0);
    xsi_set_current_line(254, ng0);
    xsi_vlog_finish(1);
    goto LAB262;

LAB264:    xsi_set_current_line(256, ng0);

LAB267:    xsi_set_current_line(257, ng0);
    xsi_vlogfile_write(1, 0, 0, ng26, 1, t0);
    xsi_set_current_line(258, ng0);
    xsi_vlog_finish(1);
    goto LAB266;

LAB268:    xsi_set_current_line(263, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}

static void Always_266_1(char *t0)
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

LAB0:    t1 = (t0 + 5808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(266, ng0);

LAB4:    xsi_set_current_line(267, ng0);
    t2 = (t0 + 5616);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(267, ng0);
    t4 = (t0 + 2408);
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

LAB9:    t14 = (t0 + 2408);
    xsi_vlogvar_assign_value(t14, t3, 0, 0, 1);
    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

}


extern void work_m_08967310298277270481_3430131090_init()
{
	static char *pe[] = {(void *)Initial_63_0,(void *)Always_266_1};
	xsi_register_didat("work_m_08967310298277270481_3430131090", "isim/SmithWatermanPE_tb_isim_beh.exe.sim/work/m_08967310298277270481_3430131090.didat");
	xsi_register_executes(pe);
}
