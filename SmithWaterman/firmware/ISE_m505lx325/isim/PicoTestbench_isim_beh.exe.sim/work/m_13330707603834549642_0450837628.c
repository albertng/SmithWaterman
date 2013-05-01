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
static const char *ng0 = "/home/albertng/SmithWaterman/StreamBandwidthTest/firmware/ISE_m505lx325/source/Reorder.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {0U, 0U};
static unsigned int ng5[] = {1U, 0U};



static void Always_30_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;

LAB0:    t1 = (t0 + 8232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(30, ng0);
    t2 = (t0 + 10040);
    *((int *)t2) = 1;
    t3 = (t0 + 8264);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(30, ng0);

LAB5:    goto LAB2;

}

static void Always_36_1(char *t0)
{
    char t11[8];
    char t22[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    int t33;
    char *t34;
    unsigned int t35;
    int t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    int t40;
    int t41;

LAB0:    t1 = (t0 + 8480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 10056);
    *((int *)t2) = 1;
    t3 = (t0 + 8512);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(36, ng0);

LAB5:    xsi_set_current_line(37, ng0);
    t4 = (t0 + 2440U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(38, ng0);
    t12 = (t0 + 2600U);
    t13 = *((char **)t12);
    memset(t11, 0, 8);
    t12 = (t11 + 4);
    t14 = (t13 + 4);
    t15 = *((unsigned int *)t13);
    t16 = (t15 >> 0);
    *((unsigned int *)t11) = t16;
    t17 = *((unsigned int *)t14);
    t18 = (t17 >> 0);
    *((unsigned int *)t12) = t18;
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t19 & 511U);
    t20 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t20 & 511U);
    t21 = (t0 + 4760);
    t24 = (t0 + 4760);
    t25 = (t24 + 72U);
    t26 = *((char **)t25);
    t27 = (t0 + 4760);
    t28 = (t27 + 64U);
    t29 = *((char **)t28);
    t30 = (t0 + 2760U);
    t31 = *((char **)t30);
    xsi_vlog_generic_convert_array_indices(t22, t23, t26, t29, 2, 1, t31, 8, 2);
    t30 = (t22 + 4);
    t32 = *((unsigned int *)t30);
    t33 = (!(t32));
    t34 = (t23 + 4);
    t35 = *((unsigned int *)t34);
    t36 = (!(t35));
    t37 = (t33 && t36);
    if (t37 == 1)
        goto LAB9;

LAB10:    goto LAB8;

LAB9:    t38 = *((unsigned int *)t22);
    t39 = *((unsigned int *)t23);
    t40 = (t38 - t39);
    t41 = (t40 + 1);
    xsi_vlogvar_wait_assign_value(t21, t11, 0, *((unsigned int *)t23), t41, 0LL);
    goto LAB10;

}

static void NetDecl_46_2(char *t0)
{
    char t8[8];
    char t15[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
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
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;

LAB0:    t1 = (t0 + 8728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4920);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t9 = (t0 + 4920);
    t10 = (t9 + 72U);
    t11 = *((char **)t10);
    t12 = (t0 + 5400);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_generic_get_index_select_value(t8, 1, t7, t11, 2, t14, 9, 2);
    memset(t15, 0, 8);
    t16 = (t4 + 4);
    t17 = (t8 + 4);
    t18 = *((unsigned int *)t4);
    t19 = *((unsigned int *)t8);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t16);
    t22 = *((unsigned int *)t17);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t25 = *((unsigned int *)t16);
    t26 = *((unsigned int *)t17);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB7;

LAB4:    if (t27 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t15) = 1;

LAB7:    t31 = (t0 + 10216);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memset(t35, 0, 8);
    t36 = 1U;
    t37 = t36;
    t38 = (t15 + 4);
    t39 = *((unsigned int *)t15);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t38);
    t37 = (t37 & t40);
    t41 = (t35 + 4);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t42 | t36);
    t43 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t43 | t37);
    xsi_driver_vfirst_trans(t31, 0, 0U);
    t44 = (t0 + 10072);
    *((int *)t44) = 1;

LAB1:    return;
LAB6:    t30 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB7;

}

static void Always_48_3(char *t0)
{
    char t6[32];
    char t16[8];
    char t22[8];
    char t35[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;

LAB0:    t1 = (t0 + 8976U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 10088);
    *((int *)t2) = 1;
    t3 = (t0 + 9008);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(48, ng0);

LAB5:    xsi_set_current_line(49, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 5720);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 128, 0LL);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 5400);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5560);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 9, 0LL);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 5720);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5880);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 4440);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4440);
    t7 = (t5 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4440);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 5560);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_generic_get_array_select_value(t6, 128, t4, t8, t11, 2, 1, t14, 9, 2);
    t15 = (t0 + 4600);
    xsi_vlogvar_wait_assign_value(t15, t6, 0, 0, 128, 0LL);
    xsi_set_current_line(56, ng0);
    t2 = (t0 + 4120);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4120);
    t7 = (t5 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4120);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 5560);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_generic_get_array_select_value(t16, 8, t4, t8, t11, 2, 1, t14, 9, 2);
    t15 = (t0 + 4280);
    xsi_vlogvar_wait_assign_value(t15, t16, 0, 0, 8, 0LL);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 5880);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t17 = *((unsigned int *)t5);
    t18 = (~(t17));
    t19 = *((unsigned int *)t4);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB6;

LAB7:
LAB8:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t17 = *((unsigned int *)t2);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(66, ng0);

LAB14:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2920U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t17 = *((unsigned int *)t2);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB15;

LAB16:
LAB17:
LAB12:    goto LAB2;

LAB6:    xsi_set_current_line(57, ng0);

LAB9:    xsi_set_current_line(58, ng0);
    t7 = ((char*)((ng3)));
    t8 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 1, 0LL);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 4600);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 128, 0LL);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 4280);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3960);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    goto LAB8;

LAB10:    xsi_set_current_line(63, ng0);

LAB13:    xsi_set_current_line(64, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 5400);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 9, 0LL);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 5240);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB12;

LAB15:    xsi_set_current_line(67, ng0);

LAB18:    xsi_set_current_line(68, ng0);
    t4 = (t0 + 5400);
    t5 = (t4 + 56U);
    t7 = *((char **)t5);
    t8 = ((char*)((ng3)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t7, 9, t8, 32);
    t9 = (t0 + 5400);
    xsi_vlogvar_wait_assign_value(t9, t16, 0, 0, 9, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 5400);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 472);
    t7 = *((char **)t5);
    t5 = ((char*)((ng3)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_minus(t16, 32, t7, 32, t5, 32);
    memset(t22, 0, 8);
    t8 = (t4 + 4);
    t9 = (t16 + 4);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t16);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t8);
    t21 = *((unsigned int *)t9);
    t23 = (t20 ^ t21);
    t24 = (t19 | t23);
    t25 = *((unsigned int *)t8);
    t26 = *((unsigned int *)t9);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB22;

LAB19:    if (t27 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t22) = 1;

LAB22:    t11 = (t22 + 4);
    t30 = *((unsigned int *)t11);
    t31 = (~(t30));
    t32 = *((unsigned int *)t22);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB23;

LAB24:
LAB25:    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5720);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB17;

LAB21:    t10 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(72, ng0);
    t12 = (t0 + 5240);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t35, 0, 8);
    t15 = (t14 + 4);
    t36 = *((unsigned int *)t15);
    t37 = (~(t36));
    t38 = *((unsigned int *)t14);
    t39 = (t38 & t37);
    t40 = (t39 & 1U);
    if (t40 != 0)
        goto LAB29;

LAB27:    if (*((unsigned int *)t15) == 0)
        goto LAB26;

LAB28:    t41 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t41) = 1;

LAB29:    t42 = (t35 + 4);
    t43 = (t14 + 4);
    t44 = *((unsigned int *)t14);
    t45 = (~(t44));
    *((unsigned int *)t35) = t45;
    *((unsigned int *)t42) = 0;
    if (*((unsigned int *)t43) != 0)
        goto LAB31;

LAB30:    t50 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t50 & 1U);
    t51 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t51 & 1U);
    t52 = (t0 + 5240);
    xsi_vlogvar_wait_assign_value(t52, t35, 0, 0, 1, 0LL);
    goto LAB25;

LAB26:    *((unsigned int *)t35) = 1;
    goto LAB29;

LAB31:    t46 = *((unsigned int *)t35);
    t47 = *((unsigned int *)t43);
    *((unsigned int *)t35) = (t46 | t47);
    t48 = *((unsigned int *)t42);
    t49 = *((unsigned int *)t43);
    *((unsigned int *)t42) = (t48 | t49);
    goto LAB30;

}

static void NetDecl_87_4(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;

LAB0:    t1 = (t0 + 9224U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 6360);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6040);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    xsi_vlog_unsigned_minus(t8, 9, t4, 9, t7, 8);
    t9 = (t0 + 10280);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memset(t13, 0, 8);
    t14 = 511U;
    t15 = t14;
    t16 = (t8 + 4);
    t17 = *((unsigned int *)t8);
    t14 = (t14 & t17);
    t18 = *((unsigned int *)t16);
    t15 = (t15 & t18);
    t19 = (t13 + 4);
    t20 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t20 | t14);
    t21 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t21 | t15);
    xsi_driver_vfirst_trans(t9, 0, 8U);
    t22 = (t0 + 10104);
    *((int *)t22) = 1;

LAB1:    return;
}

static void NetDecl_88_5(char *t0)
{
    char t3[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
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
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;

LAB0:    t1 = (t0 + 9472U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(88, ng0);
    t2 = (t0 + 5080);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 5080);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t10 = (t0 + 3080U);
    t11 = *((char **)t10);
    xsi_vlog_generic_get_index_select_value(t6, 1, t5, t9, 2, t11, 9, 2);
    memset(t3, 0, 8);
    t10 = (t6 + 4);
    t12 = *((unsigned int *)t10);
    t13 = (~(t12));
    t14 = *((unsigned int *)t6);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t10) == 0)
        goto LAB4;

LAB6:    t17 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t17) = 1;

LAB7:    t18 = (t3 + 4);
    t19 = (t6 + 4);
    t20 = *((unsigned int *)t6);
    t21 = (~(t20));
    *((unsigned int *)t3) = t21;
    *((unsigned int *)t18) = 0;
    if (*((unsigned int *)t19) != 0)
        goto LAB9;

LAB8:    t26 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t26 & 1U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 & 1U);
    t28 = (t0 + 10344);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    memset(t32, 0, 8);
    t33 = 1U;
    t34 = t33;
    t35 = (t3 + 4);
    t36 = *((unsigned int *)t3);
    t33 = (t33 & t36);
    t37 = *((unsigned int *)t35);
    t34 = (t34 & t37);
    t38 = (t32 + 4);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t39 | t33);
    t40 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t40 | t34);
    xsi_driver_vfirst_trans(t28, 0, 0U);
    t41 = (t0 + 10120);
    *((int *)t41) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t22 = *((unsigned int *)t3);
    t23 = *((unsigned int *)t19);
    *((unsigned int *)t3) = (t22 | t23);
    t24 = *((unsigned int *)t18);
    t25 = *((unsigned int *)t19);
    *((unsigned int *)t18) = (t24 | t25);
    goto LAB8;

}

static void Always_90_6(char *t0)
{
    char t13[8];
    char t21[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    int t22;
    int t23;
    int t24;
    int t25;
    int t26;
    char *t27;
    char *t28;
    unsigned int t29;

LAB0:    t1 = (t0 + 9720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 10136);
    *((int *)t2) = 1;
    t3 = (t0 + 9752);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(90, ng0);

LAB5:    xsi_set_current_line(92, ng0);
    t4 = (t0 + 6520);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 6360);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 9, 0LL);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 6840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB10;

LAB11:
LAB12:
LAB8:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = (t0 + 6680);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 128, 0LL);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 2280U);
    t3 = *((char **)t2);
    t2 = (t0 + 6840);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(102, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7000);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 3080U);
    t3 = *((char **)t2);
    t2 = (t0 + 7320);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 9, 0LL);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(106, ng0);

LAB18:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 6840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB19;

LAB20:
LAB21:    xsi_set_current_line(116, ng0);
    t2 = (t0 + 7000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB27;

LAB28:
LAB29:
LAB16:    goto LAB2;

LAB6:    xsi_set_current_line(93, ng0);

LAB9:    xsi_set_current_line(94, ng0);
    t4 = (t0 + 4760);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 4760);
    t14 = (t7 + 72U);
    t15 = *((char **)t14);
    t16 = (t0 + 4760);
    t17 = (t16 + 64U);
    t18 = *((char **)t17);
    t19 = (t0 + 1640U);
    t20 = *((char **)t19);
    xsi_vlog_generic_get_array_select_value(t13, 9, t6, t15, t18, 2, 1, t20, 8, 2);
    t19 = (t0 + 6520);
    xsi_vlogvar_wait_assign_value(t19, t13, 0, 0, 9, 0LL);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 1640U);
    t3 = *((char **)t2);
    t2 = (t0 + 6200);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 1960U);
    t3 = *((char **)t2);
    t2 = (t0 + 6040);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    goto LAB8;

LAB10:    xsi_set_current_line(97, ng0);

LAB13:    xsi_set_current_line(98, ng0);
    t6 = (t0 + 6040);
    t7 = (t6 + 56U);
    t14 = *((char **)t7);
    t15 = ((char*)((ng3)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_minus(t13, 32, t14, 8, t15, 32);
    t16 = (t0 + 6040);
    xsi_vlogvar_wait_assign_value(t16, t13, 0, 0, 8, 0LL);
    goto LAB12;

LAB14:    xsi_set_current_line(104, ng0);

LAB17:    goto LAB16;

LAB19:    xsi_set_current_line(107, ng0);

LAB22:    xsi_set_current_line(111, ng0);
    t6 = ((char*)((ng3)));
    t7 = (t0 + 7000);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 1, 0LL);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 3240U);
    t3 = *((char **)t2);
    t2 = (t0 + 7160);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 6680);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4440);
    t6 = (t0 + 4440);
    t7 = (t6 + 72U);
    t14 = *((char **)t7);
    t15 = (t0 + 4440);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t18 = (t0 + 3080U);
    t19 = *((char **)t18);
    xsi_vlog_generic_convert_array_indices(t13, t21, t14, t17, 2, 1, t19, 9, 2);
    t18 = (t13 + 4);
    t8 = *((unsigned int *)t18);
    t22 = (!(t8));
    t20 = (t21 + 4);
    t9 = *((unsigned int *)t20);
    t23 = (!(t9));
    t24 = (t22 && t23);
    if (t24 == 1)
        goto LAB23;

LAB24:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 6200);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4120);
    t6 = (t0 + 4120);
    t7 = (t6 + 72U);
    t14 = *((char **)t7);
    t15 = (t0 + 4120);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t18 = (t0 + 3080U);
    t19 = *((char **)t18);
    xsi_vlog_generic_convert_array_indices(t13, t21, t14, t17, 2, 1, t19, 9, 2);
    t18 = (t13 + 4);
    t8 = *((unsigned int *)t18);
    t22 = (!(t8));
    t20 = (t21 + 4);
    t9 = *((unsigned int *)t20);
    t23 = (!(t9));
    t24 = (t22 && t23);
    if (t24 == 1)
        goto LAB25;

LAB26:    goto LAB21;

LAB23:    t10 = *((unsigned int *)t13);
    t11 = *((unsigned int *)t21);
    t25 = (t10 - t11);
    t26 = (t25 + 1);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t21), t26, 0LL);
    goto LAB24;

LAB25:    t10 = *((unsigned int *)t13);
    t11 = *((unsigned int *)t21);
    t25 = (t10 - t11);
    t26 = (t25 + 1);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t21), t26, 0LL);
    goto LAB26;

LAB27:    xsi_set_current_line(116, ng0);

LAB30:    xsi_set_current_line(117, ng0);
    t6 = (t0 + 7160);
    t7 = (t6 + 56U);
    t14 = *((char **)t7);
    t15 = (t0 + 4920);
    t16 = (t0 + 4920);
    t17 = (t16 + 72U);
    t18 = *((char **)t17);
    t19 = (t0 + 7320);
    t20 = (t19 + 56U);
    t27 = *((char **)t20);
    xsi_vlog_generic_convert_bit_index(t13, t18, 2, t27, 9, 2);
    t28 = (t13 + 4);
    t29 = *((unsigned int *)t28);
    t22 = (!(t29));
    if (t22 == 1)
        goto LAB31;

LAB32:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 7160);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5080);
    t6 = (t0 + 5080);
    t7 = (t6 + 72U);
    t14 = *((char **)t7);
    t15 = (t0 + 7320);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    xsi_vlog_generic_convert_bit_index(t13, t14, 2, t17, 9, 2);
    t18 = (t13 + 4);
    t8 = *((unsigned int *)t18);
    t22 = (!(t8));
    if (t22 == 1)
        goto LAB33;

LAB34:    goto LAB29;

LAB31:    xsi_vlogvar_wait_assign_value(t15, t14, 0, *((unsigned int *)t13), 1, 0LL);
    goto LAB32;

LAB33:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t13), 1, 0LL);
    goto LAB34;

}


extern void work_m_13330707603834549642_0450837628_init()
{
	static char *pe[] = {(void *)Always_30_0,(void *)Always_36_1,(void *)NetDecl_46_2,(void *)Always_48_3,(void *)NetDecl_87_4,(void *)NetDecl_88_5,(void *)Always_90_6};
	xsi_register_didat("work_m_13330707603834549642_0450837628", "isim/PicoTestbench_isim_beh.exe.sim/work/m_13330707603834549642_0450837628.didat");
	xsi_register_executes(pe);
}
