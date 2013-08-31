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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ReferenceReader.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {0, 0, 0, 0};
static unsigned int ng5[] = {2U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {0U, 0U};
static unsigned int ng8[] = {32U, 0U, 0U, 0U};



static void Always_94_0(char *t0)
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

LAB0:    t1 = (t0 + 8320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 11864);
    *((int *)t2) = 1;
    t3 = (t0 + 8352);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(94, ng0);

LAB5:    xsi_set_current_line(95, ng0);
    t4 = (t0 + 1888U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(99, ng0);

LAB10:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 2368U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 7408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB15;

LAB16:
LAB17:
LAB13:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(95, ng0);

LAB9:    xsi_set_current_line(96, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 6928);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 28, 0LL);
    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 28, 0LL);
    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(100, ng0);

LAB14:    xsi_set_current_line(101, ng0);
    t4 = (t0 + 2048U);
    t5 = *((char **)t4);
    t4 = (t0 + 6928);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 28, 0LL);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 2208U);
    t3 = *((char **)t2);
    t2 = (t0 + 7088);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 28, 0LL);
    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 7248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB13;

LAB15:    xsi_set_current_line(104, ng0);

LAB18:    xsi_set_current_line(105, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 7248);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    goto LAB17;

}

static void Cont_111_1(char *t0)
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

LAB0:    t1 = (t0 + 8568U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12136);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 15U;
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
    xsi_driver_vfirst_trans(t5, 0, 3);
    t18 = (t0 + 11880);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_112_2(char *t0)
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
    char *t10;

LAB0:    t1 = (t0 + 8816U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 5808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12200);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t4, 0, 33);
    xsi_driver_vfirst_trans(t5, 0, 32);
    t10 = (t0 + 11896);
    *((int *)t10) = 1;

LAB1:    return;
}

static void Cont_113_3(char *t0)
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

LAB0:    t1 = (t0 + 9064U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(113, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 12264);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 255U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 7);

LAB1:    return;
}

static void Cont_114_4(char *t0)
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

LAB0:    t1 = (t0 + 9312U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 6768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12328);
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
    t18 = (t0 + 11912);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_127_5(char *t0)
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

LAB0:    t1 = (t0 + 9560U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 4928U);
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

LAB7:    t11 = (t0 + 3968U);
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
LAB10:    t44 = (t0 + 12392);
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
    t57 = (t0 + 11928);
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

static void Cont_128_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 9808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(128, ng0);
    t2 = (t0 + 3808U);
    t3 = *((char **)t2);
    t2 = (t0 + 12456);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_bit_copy(t7, 0, t3, 0, 256);
    xsi_driver_vfirst_trans(t2, 0, 255);
    t8 = (t0 + 11944);
    *((int *)t8) = 1;

LAB1:    return;
}

static void Cont_129_7(char *t0)
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

LAB0:    t1 = (t0 + 10056U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t2 = (t0 + 12520);
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
    t16 = (t0 + 11960);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_130_8(char *t0)
{
    char t3[8];
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
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 10304U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(130, ng0);
    t2 = (t0 + 5088U);
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

LAB7:    t11 = (t0 + 12584);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t15, 0, 8);
    t16 = 1U;
    t17 = t16;
    t18 = (t3 + 4);
    t19 = *((unsigned int *)t3);
    t16 = (t16 & t19);
    t20 = *((unsigned int *)t18);
    t17 = (t17 & t20);
    t21 = (t15 + 4);
    t22 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t22 | t16);
    t23 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t23 | t17);
    xsi_driver_vfirst_trans(t11, 0, 0);
    t24 = (t0 + 11976);
    *((int *)t24) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

}

static void Cont_131_9(char *t0)
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

LAB0:    t1 = (t0 + 10552U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    t2 = (t0 + 12648);
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
    t16 = (t0 + 11992);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_132_10(char *t0)
{
    char t3[64];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    t1 = (t0 + 10800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(132, ng0);
    t2 = (t0 + 4768U);
    t4 = *((char **)t2);
    xsi_vlog_get_part_select_value(t3, 256, t4, 255, 0);
    t2 = (t0 + 12712);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    xsi_vlog_bit_copy(t8, 0, t3, 0, 256);
    xsi_driver_vfirst_trans(t2, 0, 255);
    t9 = (t0 + 12008);
    *((int *)t9) = 1;

LAB1:    return;
}

static void Always_135_11(char *t0)
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

LAB0:    t1 = (t0 + 11048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(135, ng0);
    t2 = (t0 + 12024);
    *((int *)t2) = 1;
    t3 = (t0 + 11080);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(135, ng0);

LAB5:    xsi_set_current_line(136, ng0);
    t4 = (t0 + 1888U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(141, ng0);

LAB10:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 5648);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5488);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5808);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 33, 0LL);
    xsi_set_current_line(144, ng0);
    t2 = (t0 + 6288);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6128);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 33, 0LL);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 6608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6448);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(136, ng0);

LAB9:    xsi_set_current_line(137, ng0);
    t11 = ((char*)((ng3)));
    t12 = (t0 + 5488);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 0LL);
    xsi_set_current_line(138, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5808);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 33, 0LL);
    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 6128);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 33, 0LL);
    xsi_set_current_line(140, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6448);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB8;

}

static void Always_149_12(char *t0)
{
    char t20[8];
    char t26[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;

LAB0:    t1 = (t0 + 11296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(149, ng0);
    t2 = (t0 + 12040);
    *((int *)t2) = 1;
    t3 = (t0 + 11328);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(149, ng0);

LAB5:    xsi_set_current_line(150, ng0);
    t4 = (t0 + 5488);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:
LAB14:
LAB13:    xsi_set_current_line(179, ng0);

LAB50:    xsi_set_current_line(180, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(151, ng0);

LAB16:    xsi_set_current_line(152, ng0);
    t9 = (t0 + 7248);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB17;

LAB18:    xsi_set_current_line(154, ng0);

LAB21:    xsi_set_current_line(155, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB19:    goto LAB15;

LAB9:    xsi_set_current_line(159, ng0);

LAB22:    xsi_set_current_line(160, ng0);
    t3 = (t0 + 3648U);
    t4 = *((char **)t3);
    memset(t20, 0, 8);
    t3 = (t4 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t4);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB26;

LAB24:    if (*((unsigned int *)t3) == 0)
        goto LAB23;

LAB25:    t5 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t5) = 1;

LAB26:    t7 = (t20 + 4);
    t21 = *((unsigned int *)t7);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 5808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6128);
    t7 = (t5 + 56U);
    t9 = *((char **)t7);
    xsi_vlog_unsigned_not_equal(t26, 33, t4, 33, t9, 33);
    t10 = (t26 + 4);
    t13 = *((unsigned int *)t10);
    t14 = (~(t13));
    t15 = *((unsigned int *)t26);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB31;

LAB32:    xsi_set_current_line(164, ng0);

LAB35:    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB33:
LAB29:    goto LAB15;

LAB11:    xsi_set_current_line(169, ng0);

LAB36:    xsi_set_current_line(170, ng0);
    t3 = (t0 + 3648U);
    t4 = *((char **)t3);
    memset(t20, 0, 8);
    t3 = (t4 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t4);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB40;

LAB38:    if (*((unsigned int *)t3) == 0)
        goto LAB37;

LAB39:    t5 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t5) = 1;

LAB40:    t7 = (t20 + 4);
    t21 = *((unsigned int *)t7);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB41;

LAB42:    xsi_set_current_line(172, ng0);
    t2 = (t0 + 5808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6128);
    t7 = (t5 + 56U);
    t9 = *((char **)t7);
    xsi_vlog_unsigned_not_equal(t26, 33, t4, 33, t9, 33);
    t10 = (t26 + 4);
    t13 = *((unsigned int *)t10);
    t14 = (~(t13));
    t15 = *((unsigned int *)t26);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB45;

LAB46:    xsi_set_current_line(174, ng0);

LAB49:    xsi_set_current_line(175, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB47:
LAB43:    goto LAB15;

LAB17:    xsi_set_current_line(152, ng0);

LAB20:    xsi_set_current_line(153, ng0);
    t18 = ((char*)((ng5)));
    t19 = (t0 + 5648);
    xsi_vlogvar_assign_value(t19, t18, 0, 0, 3);
    goto LAB19;

LAB23:    *((unsigned int *)t20) = 1;
    goto LAB26;

LAB27:    xsi_set_current_line(160, ng0);

LAB30:    xsi_set_current_line(161, ng0);
    t9 = ((char*)((ng6)));
    t10 = (t0 + 5648);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 3);
    goto LAB29;

LAB31:    xsi_set_current_line(162, ng0);

LAB34:    xsi_set_current_line(163, ng0);
    t11 = ((char*)((ng5)));
    t12 = (t0 + 5648);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 3);
    goto LAB33;

LAB37:    *((unsigned int *)t20) = 1;
    goto LAB40;

LAB41:    xsi_set_current_line(170, ng0);

LAB44:    xsi_set_current_line(171, ng0);
    t9 = ((char*)((ng6)));
    t10 = (t0 + 5648);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 3);
    goto LAB43;

LAB45:    xsi_set_current_line(172, ng0);

LAB48:    xsi_set_current_line(173, ng0);
    t11 = ((char*)((ng5)));
    t12 = (t0 + 5648);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 3);
    goto LAB47;

}

static void Always_185_13(char *t0)
{
    char t9[16];
    char t15[8];
    char t16[8];
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
    char *t12;
    char *t13;
    char *t14;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;

LAB0:    t1 = (t0 + 11544U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(185, ng0);
    t2 = (t0 + 12056);
    *((int *)t2) = 1;
    t3 = (t0 + 11576);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(185, ng0);

LAB5:    xsi_set_current_line(186, ng0);
    t4 = (t0 + 5488);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:
LAB14:
LAB13:    xsi_set_current_line(225, ng0);

LAB34:    xsi_set_current_line(226, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5968);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 33);
    xsi_set_current_line(227, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 6288);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 33);
    xsi_set_current_line(228, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(229, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6608);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    xsi_set_current_line(230, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(187, ng0);

LAB16:    xsi_set_current_line(188, ng0);
    t10 = ((char*)((ng7)));
    t11 = (t0 + 6928);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    xsi_vlogtype_concat(t9, 33, 33, 2U, t13, 28, t10, 5);
    t14 = (t0 + 5968);
    xsi_vlogvar_assign_value(t14, t9, 0, 0, 33);
    xsi_set_current_line(189, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 6928);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 7088);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 32, t5, 28, t11, 28);
    t12 = ((char*)((ng2)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_minus(t16, 32, t15, 32, t12, 32);
    xsi_vlogtype_concat(t9, 37, 37, 2U, t16, 32, t2, 5);
    t13 = (t0 + 6288);
    xsi_vlogvar_assign_value(t13, t9, 0, 0, 33);
    xsi_set_current_line(190, ng0);
    t2 = (t0 + 7248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t17 = *((unsigned int *)t5);
    t18 = (~(t17));
    t19 = *((unsigned int *)t4);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB17;

LAB18:    xsi_set_current_line(192, ng0);

LAB21:    xsi_set_current_line(193, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB19:    xsi_set_current_line(195, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6608);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);
    xsi_set_current_line(196, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB15;

LAB9:    xsi_set_current_line(199, ng0);

LAB22:    xsi_set_current_line(200, ng0);
    t3 = (t0 + 3648U);
    t4 = *((char **)t3);
    t3 = (t4 + 4);
    t17 = *((unsigned int *)t3);
    t18 = (~(t17));
    t19 = *((unsigned int *)t4);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(203, ng0);

LAB27:    xsi_set_current_line(204, ng0);
    t2 = (t0 + 5808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5968);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 33);
    xsi_set_current_line(205, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6608);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);

LAB25:    xsi_set_current_line(207, ng0);
    t2 = (t0 + 6128);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 33);
    xsi_set_current_line(208, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(209, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB15;

LAB11:    xsi_set_current_line(212, ng0);

LAB28:    xsi_set_current_line(213, ng0);
    t3 = (t0 + 6128);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 6288);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 33);
    xsi_set_current_line(214, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(215, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(216, ng0);
    t2 = (t0 + 3648U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t17 = *((unsigned int *)t2);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(219, ng0);

LAB33:    xsi_set_current_line(220, ng0);
    t2 = (t0 + 5808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5968);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 33);
    xsi_set_current_line(221, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6608);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);

LAB31:    goto LAB15;

LAB17:    xsi_set_current_line(190, ng0);

LAB20:    xsi_set_current_line(191, ng0);
    t7 = ((char*)((ng2)));
    t10 = (t0 + 7408);
    xsi_vlogvar_assign_value(t10, t7, 0, 0, 1);
    goto LAB19;

LAB23:    xsi_set_current_line(200, ng0);

LAB26:    xsi_set_current_line(201, ng0);
    t5 = (t0 + 5808);
    t7 = (t5 + 56U);
    t10 = *((char **)t7);
    t11 = ((char*)((ng8)));
    xsi_vlog_unsigned_add(t9, 33, t10, 33, t11, 33);
    t12 = (t0 + 5968);
    xsi_vlogvar_assign_value(t12, t9, 0, 0, 33);
    xsi_set_current_line(202, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 32, t4, 4, t5, 32);
    t7 = (t0 + 6608);
    xsi_vlogvar_assign_value(t7, t15, 0, 0, 4);
    goto LAB25;

LAB29:    xsi_set_current_line(216, ng0);

LAB32:    xsi_set_current_line(217, ng0);
    t4 = (t0 + 5808);
    t5 = (t4 + 56U);
    t7 = *((char **)t5);
    t10 = ((char*)((ng8)));
    xsi_vlog_unsigned_add(t9, 33, t7, 33, t10, 33);
    t11 = (t0 + 5968);
    xsi_vlogvar_assign_value(t11, t9, 0, 0, 33);
    xsi_set_current_line(218, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 32, t4, 4, t5, 32);
    t7 = (t0 + 6608);
    xsi_vlogvar_assign_value(t7, t15, 0, 0, 4);
    goto LAB31;

}


extern void work_m_07316832155380695034_4010985380_init()
{
	static char *pe[] = {(void *)Always_94_0,(void *)Cont_111_1,(void *)Cont_112_2,(void *)Cont_113_3,(void *)Cont_114_4,(void *)Cont_127_5,(void *)Cont_128_6,(void *)Cont_129_7,(void *)Cont_130_8,(void *)Cont_131_9,(void *)Cont_132_10,(void *)Always_135_11,(void *)Always_149_12,(void *)Always_185_13};
	xsi_register_didat("work_m_07316832155380695034_4010985380", "isim/PicoTestbench_isim_beh.exe.sim/work/m_07316832155380695034_4010985380.didat");
	xsi_register_executes(pe);
}
