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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/StreamInputHandler.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {2U, 0U};
static unsigned int ng3[] = {4U, 0U};
static unsigned int ng4[] = {8U, 0U};
static int ng5[] = {0, 0};
static int ng6[] = {1, 0};



static void Cont_79_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 7520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2208U);
    t3 = *((char **)t2);
    t2 = (t0 + 11616);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_bit_copy(t7, 0, t3, 0, 128);
    xsi_driver_vfirst_trans(t2, 0, 127);
    t8 = (t0 + 11312);
    *((int *)t8) = 1;

LAB1:    return;
}

static void Cont_80_1(char *t0)
{
    char t3[8];
    char t13[8];
    char *t1;
    char *t2;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    int t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;

LAB0:    t1 = (t0 + 7768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 4768U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t4 + 4);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t4);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t2) == 0)
        goto LAB4;

LAB6:    t10 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t10) = 1;

LAB7:    t11 = (t0 + 2048U);
    t12 = *((char **)t11);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t12);
    t16 = (t14 & t15);
    *((unsigned int *)t13) = t16;
    t11 = (t3 + 4);
    t17 = (t12 + 4);
    t18 = (t13 + 4);
    t19 = *((unsigned int *)t11);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    *((unsigned int *)t18) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 != 0);
    if (t23 == 1)
        goto LAB8;

LAB9:
LAB10:    t44 = (t0 + 11680);
    t45 = (t44 + 56U);
    t46 = *((char **)t45);
    t47 = (t46 + 56U);
    t48 = *((char **)t47);
    memset(t48, 0, 8);
    t49 = 1U;
    t50 = t49;
    t51 = (t13 + 4);
    t52 = *((unsigned int *)t13);
    t49 = (t49 & t52);
    t53 = *((unsigned int *)t51);
    t50 = (t50 & t53);
    t54 = (t48 + 4);
    t55 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t55 | t49);
    t56 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t56 | t50);
    xsi_driver_vfirst_trans(t44, 0, 0);
    t57 = (t0 + 11328);
    *((int *)t57) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB8:    t24 = *((unsigned int *)t13);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t13) = (t24 | t25);
    t26 = (t3 + 4);
    t27 = (t12 + 4);
    t28 = *((unsigned int *)t3);
    t29 = (~(t28));
    t30 = *((unsigned int *)t26);
    t31 = (~(t30));
    t32 = *((unsigned int *)t12);
    t33 = (~(t32));
    t34 = *((unsigned int *)t27);
    t35 = (~(t34));
    t36 = (t29 & t31);
    t37 = (t33 & t35);
    t38 = (~(t36));
    t39 = (~(t37));
    t40 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t40 & t38);
    t41 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t41 & t39);
    t42 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t42 & t38);
    t43 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t43 & t39);
    goto LAB10;

}

static void Cont_81_2(char *t0)
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

LAB0:    t1 = (t0 + 8016U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t2 = (t0 + 11744);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 0);
    t16 = (t0 + 11344);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_84_3(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;

LAB0:    t1 = (t0 + 8264U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 4608U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 268435455U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 268435455U);
    t12 = (t0 + 11808);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 268435455U;
    t18 = t17;
    t19 = (t3 + 4);
    t20 = *((unsigned int *)t3);
    t17 = (t17 & t20);
    t21 = *((unsigned int *)t19);
    t18 = (t18 & t21);
    t22 = (t16 + 4);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 | t17);
    t24 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t24 | t18);
    xsi_driver_vfirst_trans(t12, 0, 27);
    t25 = (t0 + 11360);
    *((int *)t25) = 1;

LAB1:    return;
}

static void Cont_85_4(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 8512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 4608U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 8);
    t6 = (t4 + 12);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 268435455U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 268435455U);
    t13 = (t0 + 11872);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t17, 0, 8);
    t18 = 268435455U;
    t19 = t18;
    t20 = (t3 + 4);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 | t18);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t25 | t19);
    xsi_driver_vfirst_trans(t13, 0, 27);
    t26 = (t0 + 11376);
    *((int *)t26) = 1;

LAB1:    return;
}

static void Cont_86_5(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 8760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 4608U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 16);
    t6 = (t4 + 20);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 65535U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 65535U);
    t13 = (t0 + 11936);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t17, 0, 8);
    t18 = 65535U;
    t19 = t18;
    t20 = (t3 + 4);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 | t18);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t25 | t19);
    xsi_driver_vfirst_trans(t13, 0, 15);
    t26 = (t0 + 11392);
    *((int *)t26) = 1;

LAB1:    return;
}

static void Cont_87_6(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 9008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 4608U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 16);
    t6 = (t4 + 20);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 16);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 16);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 65535U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 65535U);
    t13 = (t0 + 12000);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t17, 0, 8);
    t18 = 65535U;
    t19 = t18;
    t20 = (t3 + 4);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 | t18);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t25 | t19);
    xsi_driver_vfirst_trans(t13, 0, 15);
    t26 = (t0 + 11408);
    *((int *)t26) = 1;

LAB1:    return;
}

static void Cont_88_7(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:    t1 = (t0 + 9256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(88, ng0);
    t2 = (t0 + 4608U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 24);
    t6 = (t4 + 28);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 4294967295U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 4294967295U);
    t13 = (t0 + 12064);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t3, 8);
    xsi_driver_vfirst_trans(t13, 0, 31);
    t18 = (t0 + 11424);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_89_8(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 9504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 5648);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12128);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 11440);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_90_9(char *t0)
{
    char t3[32];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    t1 = (t0 + 9752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 4608U);
    t4 = *((char **)t2);
    xsi_vlog_get_part_select_value(t3, 128, t4, 127, 0);
    t2 = (t0 + 12192);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    xsi_vlog_bit_copy(t8, 0, t3, 0, 128);
    xsi_driver_vfirst_trans(t2, 0, 127);
    t9 = (t0 + 11456);
    *((int *)t9) = 1;

LAB1:    return;
}

static void Cont_91_10(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 10000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 5808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12256);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 11472);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_94_11(char *t0)
{
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
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 10248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 11488);
    *((int *)t2) = 1;
    t3 = (t0 + 10280);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(94, ng0);

LAB5:    xsi_set_current_line(95, ng0);
    t4 = (t0 + 1728U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(97, ng0);

LAB10:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 5488);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(95, ng0);

LAB9:    xsi_set_current_line(96, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 4, 0LL);
    goto LAB8;

}

static void Always_102_12(char *t0)
{
    char t9[8];
    char t26[8];
    char t40[8];
    char t48[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
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
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    int t72;
    int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    char *t87;

LAB0:    t1 = (t0 + 10496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 11504);
    *((int *)t2) = 1;
    t3 = (t0 + 10528);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(102, ng0);

LAB5:    xsi_set_current_line(103, ng0);
    t4 = (t0 + 5328);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t7, 4);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(138, ng0);

LAB72:    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(104, ng0);

LAB18:    xsi_set_current_line(105, ng0);
    t10 = (t0 + 4928U);
    t11 = *((char **)t10);
    memset(t9, 0, 8);
    t10 = (t11 + 4);
    t12 = *((unsigned int *)t10);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB22;

LAB20:    if (*((unsigned int *)t10) == 0)
        goto LAB19;

LAB21:    t17 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t17) = 1;

LAB22:    t18 = (t9 + 4);
    t19 = *((unsigned int *)t18);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(107, ng0);

LAB27:    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB25:    goto LAB17;

LAB9:    xsi_set_current_line(112, ng0);

LAB28:    xsi_set_current_line(113, ng0);
    t3 = (t0 + 3648U);
    t4 = *((char **)t3);
    t3 = (t4 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (~(t12));
    t14 = *((unsigned int *)t4);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(115, ng0);

LAB33:    xsi_set_current_line(116, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB31:    goto LAB17;

LAB11:    xsi_set_current_line(120, ng0);

LAB34:    xsi_set_current_line(121, ng0);
    t3 = (t0 + 4928U);
    t4 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t4 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (~(t12));
    t14 = *((unsigned int *)t4);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB38;

LAB36:    if (*((unsigned int *)t3) == 0)
        goto LAB35;

LAB37:    t5 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t5) = 1;

LAB38:    t7 = (t9 + 4);
    t19 = *((unsigned int *)t7);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB39;

LAB40:    xsi_set_current_line(123, ng0);

LAB43:    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB41:    goto LAB17;

LAB13:    xsi_set_current_line(128, ng0);

LAB44:    xsi_set_current_line(129, ng0);
    t3 = (t0 + 4128U);
    t4 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t4 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (~(t12));
    t14 = *((unsigned int *)t4);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t3) != 0)
        goto LAB47;

LAB48:    t7 = (t9 + 4);
    t19 = *((unsigned int *)t9);
    t20 = *((unsigned int *)t7);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB49;

LAB50:    memcpy(t48, t9, 8);

LAB51:    t80 = (t48 + 4);
    t81 = *((unsigned int *)t80);
    t82 = (~(t81));
    t83 = *((unsigned int *)t48);
    t84 = (t83 & t82);
    t85 = (t84 != 0);
    if (t85 > 0)
        goto LAB63;

LAB64:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 4128U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB67;

LAB68:    xsi_set_current_line(133, ng0);

LAB71:    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB69:
LAB65:    goto LAB17;

LAB19:    *((unsigned int *)t9) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(105, ng0);

LAB26:    xsi_set_current_line(106, ng0);
    t24 = ((char*)((ng2)));
    t25 = (t0 + 5488);
    xsi_vlogvar_assign_value(t25, t24, 0, 0, 4);
    goto LAB25;

LAB29:    xsi_set_current_line(113, ng0);

LAB32:    xsi_set_current_line(114, ng0);
    t5 = ((char*)((ng3)));
    t7 = (t0 + 5488);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 4);
    goto LAB31;

LAB35:    *((unsigned int *)t9) = 1;
    goto LAB38;

LAB39:    xsi_set_current_line(121, ng0);

LAB42:    xsi_set_current_line(122, ng0);
    t10 = ((char*)((ng4)));
    t11 = (t0 + 5488);
    xsi_vlogvar_assign_value(t11, t10, 0, 0, 4);
    goto LAB41;

LAB45:    *((unsigned int *)t9) = 1;
    goto LAB48;

LAB47:    t5 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB48;

LAB49:    t10 = (t0 + 6128);
    t11 = (t10 + 56U);
    t17 = *((char **)t11);
    t18 = (t0 + 5968);
    t24 = (t18 + 56U);
    t25 = *((char **)t24);
    memset(t26, 0, 8);
    t27 = (t17 + 4);
    t28 = (t25 + 4);
    t22 = *((unsigned int *)t17);
    t23 = *((unsigned int *)t25);
    t29 = (t22 ^ t23);
    t30 = *((unsigned int *)t27);
    t31 = *((unsigned int *)t28);
    t32 = (t30 ^ t31);
    t33 = (t29 | t32);
    t34 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t28);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB55;

LAB52:    if (t36 != 0)
        goto LAB54;

LAB53:    *((unsigned int *)t26) = 1;

LAB55:    memset(t40, 0, 8);
    t41 = (t26 + 4);
    t42 = *((unsigned int *)t41);
    t43 = (~(t42));
    t44 = *((unsigned int *)t26);
    t45 = (t44 & t43);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t41) != 0)
        goto LAB58;

LAB59:    t49 = *((unsigned int *)t9);
    t50 = *((unsigned int *)t40);
    t51 = (t49 & t50);
    *((unsigned int *)t48) = t51;
    t52 = (t9 + 4);
    t53 = (t40 + 4);
    t54 = (t48 + 4);
    t55 = *((unsigned int *)t52);
    t56 = *((unsigned int *)t53);
    t57 = (t55 | t56);
    *((unsigned int *)t54) = t57;
    t58 = *((unsigned int *)t54);
    t59 = (t58 != 0);
    if (t59 == 1)
        goto LAB60;

LAB61:
LAB62:    goto LAB51;

LAB54:    t39 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB55;

LAB56:    *((unsigned int *)t40) = 1;
    goto LAB59;

LAB58:    t47 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB59;

LAB60:    t60 = *((unsigned int *)t48);
    t61 = *((unsigned int *)t54);
    *((unsigned int *)t48) = (t60 | t61);
    t62 = (t9 + 4);
    t63 = (t40 + 4);
    t64 = *((unsigned int *)t9);
    t65 = (~(t64));
    t66 = *((unsigned int *)t62);
    t67 = (~(t66));
    t68 = *((unsigned int *)t40);
    t69 = (~(t68));
    t70 = *((unsigned int *)t63);
    t71 = (~(t70));
    t72 = (t65 & t67);
    t73 = (t69 & t71);
    t74 = (~(t72));
    t75 = (~(t73));
    t76 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t76 & t74);
    t77 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t77 & t75);
    t78 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t78 & t74);
    t79 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t79 & t75);
    goto LAB62;

LAB63:    xsi_set_current_line(129, ng0);

LAB66:    xsi_set_current_line(130, ng0);
    t86 = ((char*)((ng1)));
    t87 = (t0 + 5488);
    xsi_vlogvar_assign_value(t87, t86, 0, 0, 4);
    goto LAB65;

LAB67:    xsi_set_current_line(131, ng0);

LAB70:    xsi_set_current_line(132, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 5488);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    goto LAB69;

}

static void Always_144_13(char *t0)
{
    char t9[8];
    char t24[8];
    char t31[8];
    char t53[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
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
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t32;
    char *t33;
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
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;

LAB0:    t1 = (t0 + 10744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 11520);
    *((int *)t2) = 1;
    t3 = (t0 + 10776);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(144, ng0);

LAB5:    xsi_set_current_line(145, ng0);
    t4 = (t0 + 5328);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t7, 4);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(198, ng0);

LAB75:    xsi_set_current_line(199, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 5648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(200, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 5808);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(201, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);
    xsi_set_current_line(202, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    xsi_set_current_line(203, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(146, ng0);

LAB18:    xsi_set_current_line(147, ng0);
    t10 = (t0 + 4928U);
    t11 = *((char **)t10);
    memset(t9, 0, 8);
    t10 = (t11 + 4);
    t12 = *((unsigned int *)t10);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB22;

LAB20:    if (*((unsigned int *)t10) == 0)
        goto LAB19;

LAB21:    t17 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t17) = 1;

LAB22:    t18 = (t0 + 5648);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(148, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 5808);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 4928U);
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

LAB25:    t4 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t4) = 1;

LAB26:    t5 = (t9 + 4);
    t19 = *((unsigned int *)t5);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(155, ng0);

LAB40:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);

LAB29:    xsi_set_current_line(158, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB17;

LAB9:    xsi_set_current_line(162, ng0);

LAB41:    xsi_set_current_line(163, ng0);
    t3 = (t0 + 4928U);
    t4 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t4 + 4);
    t12 = *((unsigned int *)t3);
    t13 = (~(t12));
    t14 = *((unsigned int *)t4);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB45;

LAB43:    if (*((unsigned int *)t3) == 0)
        goto LAB42;

LAB44:    t5 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t5) = 1;

LAB45:    t7 = (t0 + 5648);
    xsi_vlogvar_assign_value(t7, t9, 0, 0, 1);
    xsi_set_current_line(164, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 5808);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(165, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 6128);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6448);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);
    xsi_set_current_line(167, ng0);
    t2 = (t0 + 3648U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB46;

LAB47:    xsi_set_current_line(169, ng0);

LAB50:    xsi_set_current_line(170, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB48:    goto LAB17;

LAB11:    xsi_set_current_line(174, ng0);

LAB51:    xsi_set_current_line(175, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t0 + 5648);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 4928U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB55;

LAB53:    if (*((unsigned int *)t2) == 0)
        goto LAB52;

LAB54:    t4 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t4) = 1;

LAB55:    t5 = (t0 + 5808);
    xsi_vlogvar_assign_value(t5, t9, 0, 0, 1);
    xsi_set_current_line(177, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);
    xsi_set_current_line(178, ng0);
    t2 = (t0 + 4928U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB59;

LAB57:    if (*((unsigned int *)t2) == 0)
        goto LAB56;

LAB58:    t4 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t4) = 1;

LAB59:    t5 = (t9 + 4);
    t19 = *((unsigned int *)t5);
    t20 = (~(t19));
    t21 = *((unsigned int *)t9);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB60;

LAB61:    xsi_set_current_line(180, ng0);

LAB64:    xsi_set_current_line(181, ng0);
    t2 = (t0 + 6128);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6448);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);

LAB62:    xsi_set_current_line(183, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB17;

LAB13:    xsi_set_current_line(186, ng0);

LAB65:    xsi_set_current_line(187, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t0 + 5648);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(188, ng0);
    t2 = (t0 + 4928U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB69;

LAB67:    if (*((unsigned int *)t2) == 0)
        goto LAB66;

LAB68:    t4 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t4) = 1;

LAB69:    t5 = (t0 + 5808);
    xsi_vlogvar_assign_value(t5, t9, 0, 0, 1);
    xsi_set_current_line(189, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);
    xsi_set_current_line(190, ng0);
    t2 = (t0 + 6128);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6448);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);
    xsi_set_current_line(191, ng0);
    t2 = (t0 + 4128U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB70;

LAB71:    xsi_set_current_line(193, ng0);

LAB74:    xsi_set_current_line(194, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB72:    goto LAB17;

LAB19:    *((unsigned int *)t9) = 1;
    goto LAB22;

LAB23:    *((unsigned int *)t9) = 1;
    goto LAB26;

LAB27:    xsi_set_current_line(149, ng0);

LAB30:    xsi_set_current_line(150, ng0);
    t7 = (t0 + 4608U);
    t10 = *((char **)t7);
    memset(t24, 0, 8);
    t7 = (t24 + 4);
    t11 = (t10 + 16);
    t17 = (t10 + 20);
    t25 = *((unsigned int *)t11);
    t26 = (t25 >> 0);
    *((unsigned int *)t24) = t26;
    t27 = *((unsigned int *)t17);
    t28 = (t27 >> 0);
    *((unsigned int *)t7) = t28;
    t29 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t29 & 63U);
    t30 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t30 & 63U);
    t18 = ((char*)((ng5)));
    memset(t31, 0, 8);
    t32 = (t24 + 4);
    t33 = (t18 + 4);
    t34 = *((unsigned int *)t24);
    t35 = *((unsigned int *)t18);
    t36 = (t34 ^ t35);
    t37 = *((unsigned int *)t32);
    t38 = *((unsigned int *)t33);
    t39 = (t37 ^ t38);
    t40 = (t36 | t39);
    t41 = *((unsigned int *)t32);
    t42 = *((unsigned int *)t33);
    t43 = (t41 | t42);
    t44 = (~(t43));
    t45 = (t40 & t44);
    if (t45 != 0)
        goto LAB34;

LAB31:    if (t43 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t31) = 1;

LAB34:    t47 = (t31 + 4);
    t48 = *((unsigned int *)t47);
    t49 = (~(t48));
    t50 = *((unsigned int *)t31);
    t51 = (t50 & t49);
    t52 = (t51 != 0);
    if (t52 > 0)
        goto LAB35;

LAB36:    xsi_set_current_line(152, ng0);

LAB39:    xsi_set_current_line(153, ng0);
    t2 = (t0 + 4608U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t4 = (t3 + 16);
    t5 = (t3 + 20);
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 6);
    *((unsigned int *)t9) = t13;
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 6);
    *((unsigned int *)t2) = t15;
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 & 1023U);
    t19 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t19 & 1023U);
    t7 = ((char*)((ng6)));
    memset(t24, 0, 8);
    xsi_vlog_unsigned_add(t24, 32, t9, 32, t7, 32);
    t10 = (t0 + 6288);
    xsi_vlogvar_assign_value(t10, t24, 0, 0, 10);

LAB37:    goto LAB29;

LAB33:    t46 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t46) = 1;
    goto LAB34;

LAB35:    xsi_set_current_line(150, ng0);

LAB38:    xsi_set_current_line(151, ng0);
    t54 = (t0 + 4608U);
    t55 = *((char **)t54);
    memset(t53, 0, 8);
    t54 = (t53 + 4);
    t56 = (t55 + 16);
    t57 = (t55 + 20);
    t58 = *((unsigned int *)t56);
    t59 = (t58 >> 6);
    *((unsigned int *)t53) = t59;
    t60 = *((unsigned int *)t57);
    t61 = (t60 >> 6);
    *((unsigned int *)t54) = t61;
    t62 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t62 & 1023U);
    t63 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t63 & 1023U);
    t64 = (t0 + 6288);
    xsi_vlogvar_assign_value(t64, t53, 0, 0, 10);
    goto LAB37;

LAB42:    *((unsigned int *)t9) = 1;
    goto LAB45;

LAB46:    xsi_set_current_line(167, ng0);

LAB49:    xsi_set_current_line(168, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 6608);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB48;

LAB52:    *((unsigned int *)t9) = 1;
    goto LAB55;

LAB56:    *((unsigned int *)t9) = 1;
    goto LAB59;

LAB60:    xsi_set_current_line(178, ng0);

LAB63:    xsi_set_current_line(179, ng0);
    t7 = (t0 + 6128);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    t17 = ((char*)((ng6)));
    memset(t24, 0, 8);
    xsi_vlog_unsigned_add(t24, 32, t11, 10, t17, 32);
    t18 = (t0 + 6448);
    xsi_vlogvar_assign_value(t18, t24, 0, 0, 10);
    goto LAB62;

LAB66:    *((unsigned int *)t9) = 1;
    goto LAB69;

LAB70:    xsi_set_current_line(191, ng0);

LAB73:    xsi_set_current_line(192, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 6608);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB72;

}

static void Always_208_14(char *t0)
{
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
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 10992U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(208, ng0);
    t2 = (t0 + 11536);
    *((int *)t2) = 1;
    t3 = (t0 + 11024);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(208, ng0);

LAB5:    xsi_set_current_line(209, ng0);
    t4 = (t0 + 1728U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(212, ng0);

LAB10:    xsi_set_current_line(213, ng0);
    t2 = (t0 + 6288);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5968);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(214, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6128);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(209, ng0);

LAB9:    xsi_set_current_line(210, ng0);
    t11 = ((char*)((ng5)));
    t12 = (t0 + 5968);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 10, 0LL);
    xsi_set_current_line(211, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6128);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 0LL);
    goto LAB8;

}


extern void work_m_17474236217538184517_3003528064_init()
{
	static char *pe[] = {(void *)Cont_79_0,(void *)Cont_80_1,(void *)Cont_81_2,(void *)Cont_84_3,(void *)Cont_85_4,(void *)Cont_86_5,(void *)Cont_87_6,(void *)Cont_88_7,(void *)Cont_89_8,(void *)Cont_90_9,(void *)Cont_91_10,(void *)Always_94_11,(void *)Always_102_12,(void *)Always_144_13,(void *)Always_208_14};
	xsi_register_didat("work_m_17474236217538184517_3003528064", "isim/PicoTestbench_isim_beh.exe.sim/work/m_17474236217538184517_3003528064.didat");
	xsi_register_executes(pe);
}
