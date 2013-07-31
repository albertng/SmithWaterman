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
static const char *ng0 = "/afs/cs.stanford.edu/group/evodevo/u/albertng/SmithWaterman/SmithWaterman/firmware/ReferenceReader.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {0U, 0U};



static void Always_90_0(char *t0)
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

LAB0:    t1 = (t0 + 8184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 11728);
    *((int *)t2) = 1;
    t3 = (t0 + 8216);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(90, ng0);

LAB5:    xsi_set_current_line(91, ng0);
    t4 = (t0 + 1752U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(95, ng0);

LAB10:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 2232U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 7272);
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

LAB6:    xsi_set_current_line(91, ng0);

LAB9:    xsi_set_current_line(92, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 6792);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 25, 0LL);
    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6952);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 25, 0LL);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(96, ng0);

LAB14:    xsi_set_current_line(97, ng0);
    t4 = (t0 + 1912U);
    t5 = *((char **)t4);
    t4 = (t0 + 6792);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 25, 0LL);
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 2072U);
    t3 = *((char **)t2);
    t2 = (t0 + 6952);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 25, 0LL);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 7112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB13;

LAB15:    xsi_set_current_line(100, ng0);

LAB18:    xsi_set_current_line(101, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 7112);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    goto LAB17;

}

static void Cont_107_1(char *t0)
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

LAB0:    t1 = (t0 + 8432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 6312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12000);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 63U;
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
    xsi_driver_vfirst_trans(t5, 0, 5);
    t18 = (t0 + 11744);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_108_2(char *t0)
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

LAB0:    t1 = (t0 + 8680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 5672);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12064);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t4, 8);
    xsi_driver_vfirst_trans(t5, 0, 31);
    t10 = (t0 + 11760);
    *((int *)t10) = 1;

LAB1:    return;
}

static void Cont_109_3(char *t0)
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

LAB0:    t1 = (t0 + 8928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 12128);
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

static void Cont_110_4(char *t0)
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

LAB0:    t1 = (t0 + 9176U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 6632);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12192);
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
    t18 = (t0 + 11776);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_123_5(char *t0)
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

LAB0:    t1 = (t0 + 9424U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(123, ng0);
    t2 = (t0 + 4792U);
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

LAB7:    t11 = (t0 + 3832U);
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
LAB10:    t44 = (t0 + 12256);
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
    t57 = (t0 + 11792);
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

static void Cont_124_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 9672U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 3672U);
    t3 = *((char **)t2);
    t2 = (t0 + 12320);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_bit_copy(t7, 0, t3, 0, 256);
    xsi_driver_vfirst_trans(t2, 0, 255);
    t8 = (t0 + 11808);
    *((int *)t8) = 1;

LAB1:    return;
}

static void Cont_125_7(char *t0)
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

LAB0:    t1 = (t0 + 9920U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 4312U);
    t3 = *((char **)t2);
    t2 = (t0 + 12384);
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
    t16 = (t0 + 11824);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_126_8(char *t0)
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

LAB0:    t1 = (t0 + 10168U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 4952U);
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

LAB7:    t11 = (t0 + 12448);
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
    t24 = (t0 + 11840);
    *((int *)t24) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

}

static void Cont_127_9(char *t0)
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

LAB0:    t1 = (t0 + 10416U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 2712U);
    t3 = *((char **)t2);
    t2 = (t0 + 12512);
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
    t16 = (t0 + 11856);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_128_10(char *t0)
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

LAB0:    t1 = (t0 + 10664U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(128, ng0);
    t2 = (t0 + 4632U);
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
    *((unsigned int *)t3) = (t10 & 255U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 255U);
    t12 = (t0 + 12576);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 255U;
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
    xsi_driver_vfirst_trans(t12, 0, 7);
    t25 = (t0 + 11872);
    *((int *)t25) = 1;

LAB1:    return;
}

static void Always_131_11(char *t0)
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

LAB0:    t1 = (t0 + 10912U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 11888);
    *((int *)t2) = 1;
    t3 = (t0 + 10944);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(131, ng0);

LAB5:    xsi_set_current_line(132, ng0);
    t4 = (t0 + 1752U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(137, ng0);

LAB10:    xsi_set_current_line(138, ng0);
    t2 = (t0 + 5512);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5352);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 5832);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5672);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 0LL);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 6152);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5992);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 0LL);
    xsi_set_current_line(141, ng0);
    t2 = (t0 + 6472);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6312);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 6, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(132, ng0);

LAB9:    xsi_set_current_line(133, ng0);
    t11 = ((char*)((ng3)));
    t12 = (t0 + 5352);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 0LL);
    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5672);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(135, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5992);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6312);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 6, 0LL);
    goto LAB8;

}

static void Always_145_12(char *t0)
{
    char t20[8];
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
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;

LAB0:    t1 = (t0 + 11160U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 11904);
    *((int *)t2) = 1;
    t3 = (t0 + 11192);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(145, ng0);

LAB5:    xsi_set_current_line(146, ng0);
    t4 = (t0 + 5352);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:
LAB13:    goto LAB2;

LAB7:    xsi_set_current_line(147, ng0);

LAB14:    xsi_set_current_line(148, ng0);
    t9 = (t0 + 7112);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB15;

LAB16:    xsi_set_current_line(150, ng0);

LAB19:    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5512);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB17:    goto LAB13;

LAB9:    xsi_set_current_line(155, ng0);

LAB20:    xsi_set_current_line(156, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t0 + 5512);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 3);
    goto LAB13;

LAB11:    xsi_set_current_line(159, ng0);

LAB21:    xsi_set_current_line(160, ng0);
    t3 = (t0 + 3512U);
    t4 = *((char **)t3);
    memset(t20, 0, 8);
    t3 = (t4 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (~(t13));
    t15 = *((unsigned int *)t4);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB25;

LAB23:    if (*((unsigned int *)t3) == 0)
        goto LAB22;

LAB24:    t5 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t5) = 1;

LAB25:    t7 = (t20 + 4);
    t21 = *((unsigned int *)t7);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 5672);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5992);
    t7 = (t5 + 56U);
    t9 = *((char **)t7);
    memset(t20, 0, 8);
    t10 = (t4 + 4);
    t11 = (t9 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t10);
    t17 = *((unsigned int *)t11);
    t21 = (t16 ^ t17);
    t22 = (t15 | t21);
    t23 = *((unsigned int *)t10);
    t24 = *((unsigned int *)t11);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB31;

LAB30:    if (t25 != 0)
        goto LAB32;

LAB33:    t18 = (t20 + 4);
    t28 = *((unsigned int *)t18);
    t29 = (~(t28));
    t30 = *((unsigned int *)t20);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB34;

LAB35:    xsi_set_current_line(164, ng0);

LAB38:    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5512);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB36:
LAB28:    goto LAB13;

LAB15:    xsi_set_current_line(148, ng0);

LAB18:    xsi_set_current_line(149, ng0);
    t18 = ((char*)((ng4)));
    t19 = (t0 + 5512);
    xsi_vlogvar_assign_value(t19, t18, 0, 0, 3);
    goto LAB17;

LAB22:    *((unsigned int *)t20) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(160, ng0);

LAB29:    xsi_set_current_line(161, ng0);
    t9 = ((char*)((ng5)));
    t10 = (t0 + 5512);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 3);
    goto LAB28;

LAB31:    *((unsigned int *)t20) = 1;
    goto LAB33;

LAB32:    t12 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB33;

LAB34:    xsi_set_current_line(162, ng0);

LAB37:    xsi_set_current_line(163, ng0);
    t19 = ((char*)((ng4)));
    t33 = (t0 + 5512);
    xsi_vlogvar_assign_value(t33, t19, 0, 0, 3);
    goto LAB36;

}

static void Always_171_13(char *t0)
{
    char t9[8];
    char t15[8];
    char t16[8];
    char t17[8];
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
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;

LAB0:    t1 = (t0 + 11408U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(171, ng0);
    t2 = (t0 + 11920);
    *((int *)t2) = 1;
    t3 = (t0 + 11440);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(171, ng0);

LAB5:    xsi_set_current_line(172, ng0);
    t4 = (t0 + 5352);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:
LAB13:    goto LAB2;

LAB7:    xsi_set_current_line(173, ng0);

LAB14:    xsi_set_current_line(174, ng0);
    t10 = (t0 + 6792);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = ((char*)((ng6)));
    xsi_vlogtype_concat(t9, 32, 32, 2U, t13, 7, t12, 25);
    t14 = (t0 + 5832);
    xsi_vlogvar_assign_value(t14, t9, 0, 0, 32);
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 6792);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    xsi_vlogtype_concat(t9, 32, 32, 2U, t5, 7, t4, 25);
    t7 = (t0 + 6952);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng6)));
    xsi_vlogtype_concat(t15, 32, 32, 2U, t12, 7, t11, 25);
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t9, 32, t15, 32);
    t13 = ((char*)((ng2)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_minus(t17, 32, t16, 32, t13, 32);
    t14 = (t0 + 6152);
    xsi_vlogvar_assign_value(t14, t17, 0, 0, 32);
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 7112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t18 = *((unsigned int *)t5);
    t19 = (~(t18));
    t20 = *((unsigned int *)t4);
    t21 = (t20 & t19);
    t22 = (t21 != 0);
    if (t22 > 0)
        goto LAB15;

LAB16:    xsi_set_current_line(178, ng0);

LAB19:    xsi_set_current_line(179, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7272);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB17:    xsi_set_current_line(181, ng0);
    t2 = (t0 + 6312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6472);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 6);
    xsi_set_current_line(182, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB13;

LAB9:    xsi_set_current_line(185, ng0);

LAB20:    xsi_set_current_line(186, ng0);
    t3 = (t0 + 5672);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 5832);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 32);
    xsi_set_current_line(187, ng0);
    t2 = (t0 + 5992);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6152);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    xsi_set_current_line(188, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7272);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(189, ng0);
    t2 = (t0 + 6312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6472);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 6);
    xsi_set_current_line(190, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB13;

LAB11:    xsi_set_current_line(193, ng0);

LAB21:    xsi_set_current_line(194, ng0);
    t3 = (t0 + 5992);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 6152);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 32);
    xsi_set_current_line(195, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7272);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(196, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(197, ng0);
    t2 = (t0 + 3512U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t18 = *((unsigned int *)t2);
    t19 = (~(t18));
    t20 = *((unsigned int *)t3);
    t21 = (t20 & t19);
    t22 = (t21 != 0);
    if (t22 > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(200, ng0);

LAB26:    xsi_set_current_line(201, ng0);
    t2 = (t0 + 5672);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5832);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    xsi_set_current_line(202, ng0);
    t2 = (t0 + 6312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6472);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 6);

LAB24:    goto LAB13;

LAB15:    xsi_set_current_line(176, ng0);

LAB18:    xsi_set_current_line(177, ng0);
    t7 = ((char*)((ng2)));
    t10 = (t0 + 7272);
    xsi_vlogvar_assign_value(t10, t7, 0, 0, 1);
    goto LAB17;

LAB22:    xsi_set_current_line(197, ng0);

LAB25:    xsi_set_current_line(198, ng0);
    t4 = (t0 + 5672);
    t5 = (t4 + 56U);
    t7 = *((char **)t5);
    t10 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t7, 32, t10, 32);
    t11 = (t0 + 5832);
    xsi_vlogvar_assign_value(t11, t9, 0, 0, 32);
    xsi_set_current_line(199, ng0);
    t2 = (t0 + 6312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t4, 6, t5, 32);
    t7 = (t0 + 6472);
    xsi_vlogvar_assign_value(t7, t9, 0, 0, 6);
    goto LAB24;

}


extern void work_m_12462826048998305829_0565960108_init()
{
	static char *pe[] = {(void *)Always_90_0,(void *)Cont_107_1,(void *)Cont_108_2,(void *)Cont_109_3,(void *)Cont_110_4,(void *)Cont_123_5,(void *)Cont_124_6,(void *)Cont_125_7,(void *)Cont_126_8,(void *)Cont_127_9,(void *)Cont_128_10,(void *)Always_131_11,(void *)Always_145_12,(void *)Always_171_13};
	xsi_register_didat("work_m_12462826048998305829_0565960108", "isim/Engine_tb_isim_beh.exe.sim/work/m_12462826048998305829_0565960108.didat");
	xsi_register_executes(pe);
}
