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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/CardInfo32.v";
static unsigned int ng1[] = {1040U, 0U};
static int ng2[] = {32, 0};
static unsigned int ng3[] = {422597527U, 0U};
static unsigned int ng4[] = {5U, 0U};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {7U, 0U};
static unsigned int ng7[] = {8U, 0U};
static unsigned int ng8[] = {4292870156U, 0U};
static unsigned int ng9[] = {4292870220U, 0U};
static unsigned int ng10[] = {4292870212U, 0U};
static unsigned int ng11[] = {4292870224U, 0U};



static void NetDecl_23_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 4120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(23, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6520);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t2, 8);
    xsi_driver_vfirst_trans(t3, 0, 31U);

LAB1:    return;
}

static void NetDecl_24_1(char *t0)
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
    char *t17;

LAB0:    t1 = (t0 + 4368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(24, ng0);
    t2 = (t0 + 2168U);
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
    *((unsigned int *)t3) = (t10 & 4294967295U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 4294967295U);
    t12 = (t0 + 6584);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t3, 8);
    xsi_driver_vfirst_trans(t12, 0, 31U);
    t17 = (t0 + 6424);
    *((int *)t17) = 1;

LAB1:    return;
}

static void NetDecl_28_2(char *t0)
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

LAB0:    t1 = (t0 + 4616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6648);
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
    xsi_driver_vfirst_trans(t3, 0, 7U);

LAB1:    return;
}

static void NetDecl_32_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 4864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 6712);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t2, 8);
    xsi_driver_vfirst_trans(t3, 0, 31U);

LAB1:    return;
}

static void Cont_35_4(char *t0)
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

LAB0:    t1 = (t0 + 5112U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 6776);
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
    xsi_driver_vfirst_trans(t3, 24, 31);

LAB1:    return;
}

static void Cont_36_5(char *t0)
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

LAB0:    t1 = (t0 + 5360U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 6840);
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
    xsi_driver_vfirst_trans(t3, 16, 23);

LAB1:    return;
}

static void Cont_37_6(char *t0)
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

LAB0:    t1 = (t0 + 5608U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 6904);
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
    xsi_driver_vfirst_trans(t3, 8, 15);

LAB1:    return;
}

static void Cont_38_7(char *t0)
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

LAB0:    t1 = (t0 + 5856U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 6968);
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

static void Always_40_8(char *t0)
{
    char t6[8];
    char t16[8];
    char t32[8];
    char t70[8];
    char t81[8];
    char t82[8];
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
    char *t15;
    char *t17;
    char *t18;
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
    unsigned int t30;
    char *t31;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    char *t38;
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
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    int t56;
    int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;

LAB0:    t1 = (t0 + 6104U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 6440);
    *((int *)t2) = 1;
    t3 = (t0 + 6136);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(40, ng0);

LAB5:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    t4 = (t0 + 1368U);
    t7 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t4) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 4294967295U);
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 4294967295U);
    t15 = ((char*)((ng8)));
    memset(t16, 0, 8);
    t17 = (t6 + 4);
    t18 = (t15 + 4);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t15);
    t21 = (t19 ^ t20);
    t22 = *((unsigned int *)t17);
    t23 = *((unsigned int *)t18);
    t24 = (t22 ^ t23);
    t25 = (t21 | t24);
    t26 = *((unsigned int *)t17);
    t27 = *((unsigned int *)t18);
    t28 = (t26 | t27);
    t29 = (~(t28));
    t30 = (t25 & t29);
    if (t30 != 0)
        goto LAB9;

LAB6:    if (t28 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t16) = 1;

LAB9:    t33 = *((unsigned int *)t5);
    t34 = *((unsigned int *)t16);
    t35 = (t33 & t34);
    *((unsigned int *)t32) = t35;
    t36 = (t5 + 4);
    t37 = (t16 + 4);
    t38 = (t32 + 4);
    t39 = *((unsigned int *)t36);
    t40 = *((unsigned int *)t37);
    t41 = (t39 | t40);
    *((unsigned int *)t38) = t41;
    t42 = *((unsigned int *)t38);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB10;

LAB11:
LAB12:    t64 = (t32 + 4);
    t65 = *((unsigned int *)t64);
    t66 = (~(t65));
    t67 = *((unsigned int *)t32);
    t68 = (t67 & t66);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB13;

LAB14:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 1368U);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t5 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 4294967295U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 4294967295U);
    t7 = ((char*)((ng9)));
    memset(t16, 0, 8);
    t8 = (t6 + 4);
    t15 = (t7 + 4);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t7);
    t21 = (t19 ^ t20);
    t22 = *((unsigned int *)t8);
    t23 = *((unsigned int *)t15);
    t24 = (t22 ^ t23);
    t25 = (t21 | t24);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t15);
    t28 = (t26 | t27);
    t29 = (~(t28));
    t30 = (t25 & t29);
    if (t30 != 0)
        goto LAB19;

LAB16:    if (t28 != 0)
        goto LAB18;

LAB17:    *((unsigned int *)t16) = 1;

LAB19:    t33 = *((unsigned int *)t3);
    t34 = *((unsigned int *)t16);
    t35 = (t33 & t34);
    *((unsigned int *)t32) = t35;
    t18 = (t3 + 4);
    t31 = (t16 + 4);
    t36 = (t32 + 4);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t31);
    t41 = (t39 | t40);
    *((unsigned int *)t36) = t41;
    t42 = *((unsigned int *)t36);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB20;

LAB21:
LAB22:    t46 = (t32 + 4);
    t65 = *((unsigned int *)t46);
    t66 = (~(t65));
    t67 = *((unsigned int *)t32);
    t68 = (t67 & t66);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 1368U);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t5 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 4294967295U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 4294967295U);
    t7 = ((char*)((ng10)));
    memset(t16, 0, 8);
    t8 = (t6 + 4);
    t15 = (t7 + 4);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t7);
    t21 = (t19 ^ t20);
    t22 = *((unsigned int *)t8);
    t23 = *((unsigned int *)t15);
    t24 = (t22 ^ t23);
    t25 = (t21 | t24);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t15);
    t28 = (t26 | t27);
    t29 = (~(t28));
    t30 = (t25 & t29);
    if (t30 != 0)
        goto LAB29;

LAB26:    if (t28 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t16) = 1;

LAB29:    t33 = *((unsigned int *)t3);
    t34 = *((unsigned int *)t16);
    t35 = (t33 & t34);
    *((unsigned int *)t32) = t35;
    t18 = (t3 + 4);
    t31 = (t16 + 4);
    t36 = (t32 + 4);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t31);
    t41 = (t39 | t40);
    *((unsigned int *)t36) = t41;
    t42 = *((unsigned int *)t36);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB30;

LAB31:
LAB32:    t46 = (t32 + 4);
    t65 = *((unsigned int *)t46);
    t66 = (~(t65));
    t67 = *((unsigned int *)t32);
    t68 = (t67 & t66);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB33;

LAB34:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 1368U);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t5 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t5);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 4294967295U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 4294967295U);
    t7 = ((char*)((ng11)));
    memset(t16, 0, 8);
    t8 = (t6 + 4);
    t15 = (t7 + 4);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t7);
    t21 = (t19 ^ t20);
    t22 = *((unsigned int *)t8);
    t23 = *((unsigned int *)t15);
    t24 = (t22 ^ t23);
    t25 = (t21 | t24);
    t26 = *((unsigned int *)t8);
    t27 = *((unsigned int *)t15);
    t28 = (t26 | t27);
    t29 = (~(t28));
    t30 = (t25 & t29);
    if (t30 != 0)
        goto LAB39;

LAB36:    if (t28 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t16) = 1;

LAB39:    t33 = *((unsigned int *)t3);
    t34 = *((unsigned int *)t16);
    t35 = (t33 & t34);
    *((unsigned int *)t32) = t35;
    t18 = (t3 + 4);
    t31 = (t16 + 4);
    t36 = (t32 + 4);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t31);
    t41 = (t39 | t40);
    *((unsigned int *)t36) = t41;
    t42 = *((unsigned int *)t36);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB40;

LAB41:
LAB42:    t46 = (t32 + 4);
    t65 = *((unsigned int *)t46);
    t66 = (~(t65));
    t67 = *((unsigned int *)t32);
    t68 = (t67 & t66);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB43;

LAB44:    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);

LAB45:
LAB35:
LAB25:
LAB15:    goto LAB2;

LAB8:    t31 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB9;

LAB10:    t44 = *((unsigned int *)t32);
    t45 = *((unsigned int *)t38);
    *((unsigned int *)t32) = (t44 | t45);
    t46 = (t5 + 4);
    t47 = (t16 + 4);
    t48 = *((unsigned int *)t5);
    t49 = (~(t48));
    t50 = *((unsigned int *)t46);
    t51 = (~(t50));
    t52 = *((unsigned int *)t16);
    t53 = (~(t52));
    t54 = *((unsigned int *)t47);
    t55 = (~(t54));
    t56 = (t49 & t51);
    t57 = (t53 & t55);
    t58 = (~(t56));
    t59 = (~(t57));
    t60 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t60 & t58);
    t61 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t61 & t59);
    t62 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t62 & t58);
    t63 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t63 & t59);
    goto LAB12;

LAB13:    xsi_set_current_line(42, ng0);
    t71 = (t0 + 2648U);
    t72 = *((char **)t71);
    memset(t70, 0, 8);
    t71 = (t70 + 4);
    t73 = (t72 + 4);
    t74 = *((unsigned int *)t72);
    t75 = (t74 >> 0);
    *((unsigned int *)t70) = t75;
    t76 = *((unsigned int *)t73);
    t77 = (t76 >> 0);
    *((unsigned int *)t71) = t77;
    t78 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t78 & 4294967295U);
    t79 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t79 & 4294967295U);
    t80 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t80, t70, 0, 0, 32, 0LL);
    goto LAB15;

LAB18:    t17 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB19;

LAB20:    t44 = *((unsigned int *)t32);
    t45 = *((unsigned int *)t36);
    *((unsigned int *)t32) = (t44 | t45);
    t37 = (t3 + 4);
    t38 = (t16 + 4);
    t48 = *((unsigned int *)t3);
    t49 = (~(t48));
    t50 = *((unsigned int *)t37);
    t51 = (~(t50));
    t52 = *((unsigned int *)t16);
    t53 = (~(t52));
    t54 = *((unsigned int *)t38);
    t55 = (~(t54));
    t56 = (t49 & t51);
    t57 = (t53 & t55);
    t58 = (~(t56));
    t59 = (~(t57));
    t60 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t60 & t58);
    t61 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t61 & t59);
    t62 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t62 & t58);
    t63 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t63 & t59);
    goto LAB22;

LAB23:    xsi_set_current_line(44, ng0);
    t47 = (t0 + 2328U);
    t64 = *((char **)t47);
    memset(t70, 0, 8);
    t47 = (t70 + 4);
    t71 = (t64 + 4);
    t74 = *((unsigned int *)t64);
    t75 = (t74 >> 0);
    *((unsigned int *)t70) = t75;
    t76 = *((unsigned int *)t71);
    t77 = (t76 >> 0);
    *((unsigned int *)t47) = t77;
    t78 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t78 & 4294967295U);
    t79 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t79 & 4294967295U);
    t72 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t72, t70, 0, 0, 32, 0LL);
    goto LAB25;

LAB28:    t17 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB29;

LAB30:    t44 = *((unsigned int *)t32);
    t45 = *((unsigned int *)t36);
    *((unsigned int *)t32) = (t44 | t45);
    t37 = (t3 + 4);
    t38 = (t16 + 4);
    t48 = *((unsigned int *)t3);
    t49 = (~(t48));
    t50 = *((unsigned int *)t37);
    t51 = (~(t50));
    t52 = *((unsigned int *)t16);
    t53 = (~(t52));
    t54 = *((unsigned int *)t38);
    t55 = (~(t54));
    t56 = (t49 & t51);
    t57 = (t53 & t55);
    t58 = (~(t56));
    t59 = (~(t57));
    t60 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t60 & t58);
    t61 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t61 & t59);
    t62 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t62 & t58);
    t63 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t63 & t59);
    goto LAB32;

LAB33:    xsi_set_current_line(46, ng0);
    t47 = (t0 + 2808U);
    t64 = *((char **)t47);
    memset(t70, 0, 8);
    t47 = (t70 + 4);
    t71 = (t64 + 4);
    t74 = *((unsigned int *)t64);
    t75 = (t74 >> 0);
    *((unsigned int *)t70) = t75;
    t76 = *((unsigned int *)t71);
    t77 = (t76 >> 0);
    *((unsigned int *)t47) = t77;
    t78 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t78 & 4294967295U);
    t79 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t79 & 4294967295U);
    t72 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t72, t70, 0, 0, 32, 0LL);
    goto LAB35;

LAB38:    t17 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB39;

LAB40:    t44 = *((unsigned int *)t32);
    t45 = *((unsigned int *)t36);
    *((unsigned int *)t32) = (t44 | t45);
    t37 = (t3 + 4);
    t38 = (t16 + 4);
    t48 = *((unsigned int *)t3);
    t49 = (~(t48));
    t50 = *((unsigned int *)t37);
    t51 = (~(t50));
    t52 = *((unsigned int *)t16);
    t53 = (~(t52));
    t54 = *((unsigned int *)t38);
    t55 = (~(t54));
    t56 = (t49 & t51);
    t57 = (t53 & t55);
    t58 = (~(t56));
    t59 = (~(t57));
    t60 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t60 & t58);
    t61 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t61 & t59);
    t62 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t62 & t58);
    t63 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t63 & t59);
    goto LAB42;

LAB43:    xsi_set_current_line(48, ng0);
    t47 = (t0 + 2488U);
    t64 = *((char **)t47);
    memset(t81, 0, 8);
    t47 = (t81 + 4);
    t71 = (t64 + 4);
    t74 = *((unsigned int *)t64);
    t75 = (t74 >> 0);
    *((unsigned int *)t81) = t75;
    t76 = *((unsigned int *)t71);
    t77 = (t76 >> 0);
    *((unsigned int *)t47) = t77;
    t78 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t78 & 255U);
    t79 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t79 & 255U);
    t72 = (t0 + 2008U);
    t73 = *((char **)t72);
    memset(t82, 0, 8);
    t72 = (t82 + 4);
    t80 = (t73 + 4);
    t83 = *((unsigned int *)t73);
    t84 = (t83 >> 0);
    *((unsigned int *)t82) = t84;
    t85 = *((unsigned int *)t80);
    t86 = (t85 >> 0);
    *((unsigned int *)t72) = t86;
    t87 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t87 & 255U);
    t88 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t88 & 255U);
    t89 = ((char*)((ng5)));
    xsi_vlogtype_concat(t70, 32, 32, 3U, t89, 16, t82, 8, t81, 8);
    t90 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t90, t70, 0, 0, 32, 0LL);
    goto LAB45;

}


extern void work_m_01873015474930943640_3608462700_init()
{
	static char *pe[] = {(void *)NetDecl_23_0,(void *)NetDecl_24_1,(void *)NetDecl_28_2,(void *)NetDecl_32_3,(void *)Cont_35_4,(void *)Cont_36_5,(void *)Cont_37_6,(void *)Cont_38_7,(void *)Always_40_8};
	xsi_register_didat("work_m_01873015474930943640_3608462700", "isim/PicoTestbench_isim_beh.exe.sim/work/m_01873015474930943640_3608462700.didat");
	xsi_register_executes(pe);
}
