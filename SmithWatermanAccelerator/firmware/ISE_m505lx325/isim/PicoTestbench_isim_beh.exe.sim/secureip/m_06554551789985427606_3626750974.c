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
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {1, 0};
static int ng5[] = {2, 0};



static void Cont_2538_0(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 5688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2538, ng0);
    t2 = (t0 + 4456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t5 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 2);
    t10 = (t9 & 1);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 2);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t14 = (t0 + 7408);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t5 + 4);
    t22 = *((unsigned int *)t5);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 7248);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Cont_2539_1(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 5936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2539, ng0);
    t2 = (t0 + 4456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t5 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t14 = (t0 + 7472);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t5 + 4);
    t22 = *((unsigned int *)t5);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 7264);
    *((int *)t27) = 1;

LAB1:    return;
}

static void NetDecl_2540_2(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;

LAB0:    t1 = (t0 + 6184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2540, ng0);
    t2 = (t0 + 4296);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB7;

LAB4:    if (t18 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t6) = 1;

LAB7:    t22 = (t0 + 7536);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memset(t26, 0, 8);
    t27 = 1U;
    t28 = t27;
    t29 = (t6 + 4);
    t30 = *((unsigned int *)t6);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t29);
    t28 = (t28 & t31);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t33 | t27);
    t34 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t34 | t28);
    xsi_driver_vfirst_trans(t22, 0, 0U);
    t35 = (t0 + 7280);
    *((int *)t35) = 1;

LAB1:    return;
LAB6:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB7;

}

static void Cont_2541_3(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 6432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2541, ng0);
    t2 = (t0 + 4776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t5 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t14 = (t0 + 7600);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t5 + 4);
    t22 = *((unsigned int *)t5);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 7296);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Cont_2542_4(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 6680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2542, ng0);
    t2 = (t0 + 4776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t5 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t14 = (t0 + 7664);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t5 + 4);
    t22 = *((unsigned int *)t5);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 7312);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Always_2545_5(char *t0)
{
    char t13[8];
    char t33[8];
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
    char *t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    int t38;

LAB0:    t1 = (t0 + 6928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2545, ng0);
    t2 = (t0 + 7328);
    *((int *)t2) = 1;
    t3 = (t0 + 6960);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(2545, ng0);

LAB5:    xsi_set_current_line(2546, ng0);
    t4 = (t0 + 2776U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(2554, ng0);

LAB12:    xsi_set_current_line(2556, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4456);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 10000LL);
    xsi_set_current_line(2557, ng0);
    t2 = (t0 + 4296);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t16 = (t9 ^ t10);
    t17 = (t8 | t16);
    t18 = *((unsigned int *)t11);
    t19 = *((unsigned int *)t12);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB14;

LAB13:    if (t20 != 0)
        goto LAB15;

LAB16:    t23 = (t13 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t13);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB17;

LAB18:
LAB19:    xsi_set_current_line(2559, ng0);
    t2 = ((char*)((ng3)));

LAB20:    t3 = (t0 + 4456);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t13, 0, 8);
    t11 = (t13 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 0);
    t16 = (t10 & 1);
    *((unsigned int *)t11) = t16;
    t15 = xsi_vlog_unsigned_case_compare(t2, 1, t13, 1);
    if (t15 == 1)
        goto LAB21;

LAB22:    t3 = (t0 + 4456);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    memset(t13, 0, 8);
    t12 = (t13 + 4);
    t14 = (t11 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (t6 >> 1);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t14);
    t10 = (t9 >> 1);
    t16 = (t10 & 1);
    *((unsigned int *)t12) = t16;
    t15 = xsi_vlog_unsigned_case_compare(t2, 1, t13, 1);
    if (t15 == 1)
        goto LAB23;

LAB24:    t3 = (t0 + 4456);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    memset(t13, 0, 8);
    t12 = (t13 + 4);
    t14 = (t11 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (t6 >> 2);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t14);
    t10 = (t9 >> 2);
    t16 = (t10 & 1);
    *((unsigned int *)t12) = t16;
    t15 = xsi_vlog_unsigned_case_compare(t2, 1, t13, 1);
    if (t15 == 1)
        goto LAB25;

LAB26:
LAB27:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(2546, ng0);

LAB9:    xsi_set_current_line(2547, ng0);
    t11 = ((char*)((ng2)));
    t12 = (t0 + 4136);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 6, 10000LL);
    xsi_set_current_line(2548, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4616);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 10000LL);
    xsi_set_current_line(2549, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4776);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 10000LL);
    xsi_set_current_line(2550, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4296);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 6, 10000LL);
    xsi_set_current_line(2551, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4456);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 10000LL);
    xsi_set_current_line(2552, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4456);
    t4 = (t0 + 4456);
    t5 = (t4 + 72U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t13, t11, 2, t12, 32, 1);
    t14 = (t13 + 4);
    t6 = *((unsigned int *)t14);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB10;

LAB11:    goto LAB8;

LAB10:    xsi_vlogvar_wait_assign_value(t3, t2, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB11;

LAB14:    *((unsigned int *)t13) = 1;
    goto LAB16;

LAB15:    t14 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB16;

LAB17:    xsi_set_current_line(2558, ng0);
    t29 = (t0 + 4296);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    t32 = ((char*)((ng3)));
    memset(t33, 0, 8);
    xsi_vlog_unsigned_minus(t33, 6, t31, 6, t32, 6);
    t34 = (t0 + 4296);
    xsi_vlogvar_wait_assign_value(t34, t33, 0, 0, 6, 10000LL);
    goto LAB19;

LAB21:    xsi_set_current_line(2560, ng0);

LAB28:    xsi_set_current_line(2561, ng0);
    t14 = (t0 + 2936U);
    t23 = *((char **)t14);
    t14 = (t23 + 4);
    t17 = *((unsigned int *)t14);
    t18 = (~(t17));
    t19 = *((unsigned int *)t23);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(2580, ng0);

LAB50:    xsi_set_current_line(2581, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 4456);
    t11 = (t0 + 4456);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t23 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t13, t14, 2, t23, 32, 1);
    t29 = (t13 + 4);
    t6 = *((unsigned int *)t29);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB51;

LAB52:
LAB31:    goto LAB27;

LAB23:    xsi_set_current_line(2584, ng0);

LAB53:    xsi_set_current_line(2585, ng0);
    t23 = (t0 + 3736U);
    t29 = *((char **)t23);
    t23 = (t29 + 4);
    t17 = *((unsigned int *)t23);
    t18 = (~(t17));
    t19 = *((unsigned int *)t29);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB54;

LAB55:    xsi_set_current_line(2590, ng0);

LAB60:    xsi_set_current_line(2591, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 4456);
    t11 = (t0 + 4456);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t23 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t13, t14, 2, t23, 32, 1);
    t29 = (t13 + 4);
    t6 = *((unsigned int *)t29);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB61;

LAB62:
LAB56:    goto LAB27;

LAB25:    xsi_set_current_line(2594, ng0);

LAB63:    xsi_set_current_line(2595, ng0);
    t23 = (t0 + 3736U);
    t29 = *((char **)t23);
    t23 = (t29 + 4);
    t17 = *((unsigned int *)t23);
    t18 = (~(t17));
    t19 = *((unsigned int *)t29);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB64;

LAB65:    xsi_set_current_line(2598, ng0);

LAB70:    xsi_set_current_line(2599, ng0);
    t3 = (t0 + 4616);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 4776);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 2, 10000LL);
    xsi_set_current_line(2600, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 4456);
    t11 = (t0 + 4456);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t23 = ((char*)((ng5)));
    xsi_vlog_generic_convert_bit_index(t13, t14, 2, t23, 32, 1);
    t29 = (t13 + 4);
    t6 = *((unsigned int *)t29);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB71;

LAB72:
LAB66:    goto LAB27;

LAB29:    xsi_set_current_line(2561, ng0);

LAB32:    xsi_set_current_line(2562, ng0);
    t29 = (t0 + 2296U);
    t30 = *((char **)t29);
    t29 = (t0 + 4136);
    xsi_vlogvar_wait_assign_value(t29, t30, 0, 0, 6, 10000LL);
    xsi_set_current_line(2563, ng0);
    t3 = (t0 + 2616U);
    t4 = *((char **)t3);
    t3 = (t0 + 4616);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 2, 10000LL);
    xsi_set_current_line(2564, ng0);
    t3 = (t0 + 2456U);
    t4 = *((char **)t3);

LAB33:    t3 = ((char*)((ng1)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 6, t3, 32);
    if (t15 == 1)
        goto LAB34;

LAB35:    t3 = ((char*)((ng4)));
    t15 = xsi_vlog_unsigned_case_compare(t4, 6, t3, 32);
    if (t15 == 1)
        goto LAB36;

LAB37:
LAB39:
LAB38:    xsi_set_current_line(2574, ng0);

LAB47:    xsi_set_current_line(2575, ng0);
    t3 = (t0 + 2456U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng4)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_minus(t13, 32, t5, 6, t3, 32);
    t11 = (t0 + 4296);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 6, 10000LL);
    xsi_set_current_line(2576, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 4456);
    t11 = (t0 + 4456);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t23 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t13, t14, 2, t23, 32, 1);
    t29 = (t13 + 4);
    t6 = *((unsigned int *)t29);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB48;

LAB49:
LAB40:    goto LAB31;

LAB34:    xsi_set_current_line(2565, ng0);

LAB41:    xsi_set_current_line(2566, ng0);
    t5 = (t0 + 2616U);
    t11 = *((char **)t5);
    t5 = (t0 + 4776);
    xsi_vlogvar_wait_assign_value(t5, t11, 0, 0, 2, 10000LL);
    xsi_set_current_line(2567, ng0);
    t3 = (t0 + 2296U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng4)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_minus(t13, 32, t5, 6, t3, 32);
    t11 = (t0 + 4296);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 6, 10000LL);
    xsi_set_current_line(2568, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 4456);
    t11 = (t0 + 4456);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t23 = ((char*)((ng5)));
    xsi_vlog_generic_convert_bit_index(t13, t14, 2, t23, 32, 1);
    t29 = (t13 + 4);
    t6 = *((unsigned int *)t29);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB42;

LAB43:    goto LAB40;

LAB36:    xsi_set_current_line(2570, ng0);

LAB44:    xsi_set_current_line(2571, ng0);
    t5 = ((char*)((ng1)));
    t11 = (t0 + 4296);
    xsi_vlogvar_wait_assign_value(t11, t5, 0, 0, 6, 10000LL);
    xsi_set_current_line(2572, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 4456);
    t11 = (t0 + 4456);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t23 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t13, t14, 2, t23, 32, 1);
    t29 = (t13 + 4);
    t6 = *((unsigned int *)t29);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB45;

LAB46:    goto LAB40;

LAB42:    xsi_vlogvar_wait_assign_value(t5, t3, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB43;

LAB45:    xsi_vlogvar_wait_assign_value(t5, t3, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB46;

LAB48:    xsi_vlogvar_wait_assign_value(t5, t3, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB49;

LAB51:    xsi_vlogvar_wait_assign_value(t5, t3, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB52;

LAB54:    xsi_set_current_line(2585, ng0);

LAB57:    xsi_set_current_line(2586, ng0);
    t30 = (t0 + 4616);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t34 = (t0 + 4776);
    xsi_vlogvar_wait_assign_value(t34, t32, 0, 0, 2, 10000LL);
    xsi_set_current_line(2587, ng0);
    t3 = (t0 + 4136);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng4)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_minus(t13, 32, t11, 6, t12, 32);
    t14 = (t0 + 4296);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 6, 10000LL);
    xsi_set_current_line(2588, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 4456);
    t11 = (t0 + 4456);
    t12 = (t11 + 72U);
    t14 = *((char **)t12);
    t23 = ((char*)((ng5)));
    xsi_vlog_generic_convert_bit_index(t13, t14, 2, t23, 32, 1);
    t29 = (t13 + 4);
    t6 = *((unsigned int *)t29);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB58;

LAB59:    goto LAB56;

LAB58:    xsi_vlogvar_wait_assign_value(t5, t3, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB59;

LAB61:    xsi_vlogvar_wait_assign_value(t5, t3, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB62;

LAB64:    xsi_set_current_line(2595, ng0);

LAB67:    xsi_set_current_line(2596, ng0);
    t30 = ((char*)((ng3)));
    t31 = (t0 + 4456);
    t32 = (t0 + 4456);
    t34 = (t32 + 72U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t33, t35, 2, t36, 32, 1);
    t37 = (t33 + 4);
    t22 = *((unsigned int *)t37);
    t38 = (!(t22));
    if (t38 == 1)
        goto LAB68;

LAB69:    goto LAB66;

LAB68:    xsi_vlogvar_wait_assign_value(t31, t30, 0, *((unsigned int *)t33), 1, 10000LL);
    goto LAB69;

LAB71:    xsi_vlogvar_wait_assign_value(t5, t3, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB72;

}


extern void secureip_m_06554551789985427606_3626750974_init()
{
	static char *pe[] = {(void *)Cont_2538_0,(void *)Cont_2539_1,(void *)NetDecl_2540_2,(void *)Cont_2541_3,(void *)Cont_2542_4,(void *)Always_2545_5};
	xsi_register_didat("secureip_m_06554551789985427606_3626750974", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_06554551789985427606_3626750974.didat");
	xsi_register_executes(pe);
}
