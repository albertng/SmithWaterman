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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/phaser_in/SIP_PHASER_IN.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {2U, 0U};



static void NetDecl_8334_0(char *t0)
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
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;

LAB0:    t1 = (t0 + 6016U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8334, ng0);
    t2 = (t0 + 3104U);
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

LAB7:    t11 = (t3 + 4);
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (~(t13));
    *((unsigned int *)t3) = t14;
    *((unsigned int *)t11) = 0;
    if (*((unsigned int *)t12) != 0)
        goto LAB9;

LAB8:    t19 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t19 & 1U);
    t20 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t20 & 1U);
    t21 = (t0 + 8528);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memset(t25, 0, 8);
    t26 = 1U;
    t27 = t26;
    t28 = (t3 + 4);
    t29 = *((unsigned int *)t3);
    t26 = (t26 & t29);
    t30 = *((unsigned int *)t28);
    t27 = (t27 & t30);
    t31 = (t25 + 4);
    t32 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t32 | t26);
    t33 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t33 | t27);
    xsi_driver_vfirst_trans(t21, 0, 0U);
    t34 = (t0 + 8320);
    *((int *)t34) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t15 = *((unsigned int *)t3);
    t16 = *((unsigned int *)t12);
    *((unsigned int *)t3) = (t15 | t16);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t12);
    *((unsigned int *)t11) = (t17 | t18);
    goto LAB8;

}

static void NetDecl_8336_1(char *t0)
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
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;

LAB0:    t1 = (t0 + 6264U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8336, ng0);
    t2 = (t0 + 2624U);
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

LAB7:    t11 = (t3 + 4);
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (~(t13));
    *((unsigned int *)t3) = t14;
    *((unsigned int *)t11) = 0;
    if (*((unsigned int *)t12) != 0)
        goto LAB9;

LAB8:    t19 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t19 & 1U);
    t20 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t20 & 1U);
    t21 = (t0 + 8592);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memset(t25, 0, 8);
    t26 = 1U;
    t27 = t26;
    t28 = (t3 + 4);
    t29 = *((unsigned int *)t3);
    t26 = (t26 & t29);
    t30 = *((unsigned int *)t28);
    t27 = (t27 & t30);
    t31 = (t25 + 4);
    t32 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t32 | t26);
    t33 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t33 | t27);
    xsi_driver_vfirst_trans(t21, 0, 0U);
    t34 = (t0 + 8336);
    *((int *)t34) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t15 = *((unsigned int *)t3);
    t16 = *((unsigned int *)t12);
    *((unsigned int *)t3) = (t15 | t16);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t12);
    *((unsigned int *)t11) = (t17 | t18);
    goto LAB8;

}

static void NetDecl_8338_2(char *t0)
{
    char t3[8];
    char t5[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
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
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;

LAB0:    t1 = (t0 + 6512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8338, ng0);
    t2 = (t0 + 2304U);
    t4 = *((char **)t2);
    t2 = (t0 + 2784U);
    t6 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t6 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t2) == 0)
        goto LAB4;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t5 + 4);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    *((unsigned int *)t5) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB9;

LAB8:    t21 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t24 = *((unsigned int *)t4);
    t25 = *((unsigned int *)t5);
    t26 = (t24 & t25);
    *((unsigned int *)t23) = t26;
    t27 = (t4 + 4);
    t28 = (t5 + 4);
    t29 = (t23 + 4);
    t30 = *((unsigned int *)t27);
    t31 = *((unsigned int *)t28);
    t32 = (t30 | t31);
    *((unsigned int *)t29) = t32;
    t33 = *((unsigned int *)t29);
    t34 = (t33 != 0);
    if (t34 == 1)
        goto LAB10;

LAB11:
LAB12:    memset(t3, 0, 8);
    t55 = (t23 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t23);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB16;

LAB14:    if (*((unsigned int *)t55) == 0)
        goto LAB13;

LAB15:    t61 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t61) = 1;

LAB16:    t62 = (t3 + 4);
    t63 = (t23 + 4);
    t64 = *((unsigned int *)t23);
    t65 = (~(t64));
    *((unsigned int *)t3) = t65;
    *((unsigned int *)t62) = 0;
    if (*((unsigned int *)t63) != 0)
        goto LAB18;

LAB17:    t70 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t70 & 1U);
    t71 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t71 & 1U);
    t72 = (t0 + 8656);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    t75 = (t74 + 56U);
    t76 = *((char **)t75);
    memset(t76, 0, 8);
    t77 = 1U;
    t78 = t77;
    t79 = (t3 + 4);
    t80 = *((unsigned int *)t3);
    t77 = (t77 & t80);
    t81 = *((unsigned int *)t79);
    t78 = (t78 & t81);
    t82 = (t76 + 4);
    t83 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t83 | t77);
    t84 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t84 | t78);
    xsi_driver_vfirst_trans(t72, 0, 0U);
    t85 = (t0 + 8352);
    *((int *)t85) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB9:    t17 = *((unsigned int *)t5);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t5) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB8;

LAB10:    t35 = *((unsigned int *)t23);
    t36 = *((unsigned int *)t29);
    *((unsigned int *)t23) = (t35 | t36);
    t37 = (t4 + 4);
    t38 = (t5 + 4);
    t39 = *((unsigned int *)t4);
    t40 = (~(t39));
    t41 = *((unsigned int *)t37);
    t42 = (~(t41));
    t43 = *((unsigned int *)t5);
    t44 = (~(t43));
    t45 = *((unsigned int *)t38);
    t46 = (~(t45));
    t47 = (t40 & t42);
    t48 = (t44 & t46);
    t49 = (~(t47));
    t50 = (~(t48));
    t51 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t51 & t49);
    t52 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t52 & t50);
    t53 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t53 & t49);
    t54 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t54 & t50);
    goto LAB12;

LAB13:    *((unsigned int *)t3) = 1;
    goto LAB16;

LAB18:    t66 = *((unsigned int *)t3);
    t67 = *((unsigned int *)t63);
    *((unsigned int *)t3) = (t66 | t67);
    t68 = *((unsigned int *)t62);
    t69 = *((unsigned int *)t63);
    *((unsigned int *)t62) = (t68 | t69);
    goto LAB17;

}

static void Always_8362_3(char *t0)
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

LAB0:    t1 = (t0 + 6760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8362, ng0);
    t2 = (t0 + 8368);
    *((int *)t2) = 1;
    t3 = (t0 + 6792);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(8362, ng0);

LAB5:    xsi_set_current_line(8363, ng0);
    t4 = (t0 + 3104U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(8365, ng0);

LAB10:    xsi_set_current_line(8366, ng0);
    t2 = (t0 + 3744U);
    t3 = *((char **)t2);
    t2 = (t0 + 4944);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 50000LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(8363, ng0);

LAB9:    xsi_set_current_line(8364, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4944);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    goto LAB8;

}

static void Always_8370_4(char *t0)
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

LAB0:    t1 = (t0 + 7008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8370, ng0);
    t2 = (t0 + 8384);
    *((int *)t2) = 1;
    t3 = (t0 + 7040);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(8370, ng0);

LAB5:    xsi_set_current_line(8371, ng0);
    t4 = (t0 + 3104U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(8374, ng0);

LAB10:    xsi_set_current_line(8377, ng0);
    t2 = (t0 + 4944);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:
LAB13:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(8371, ng0);

LAB9:    xsi_set_current_line(8372, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4784);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    goto LAB8;

LAB11:    xsi_set_current_line(8378, ng0);
    t11 = ((char*)((ng2)));
    t12 = (t0 + 4784);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    goto LAB13;

}

static void Cont_8382_5(char *t0)
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
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 7256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8382, ng0);
    t2 = (t0 + 4784);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t6) == 0)
        goto LAB4;

LAB6:    t12 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t3 + 4);
    t14 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (~(t15));
    *((unsigned int *)t3) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB9;

LAB8:    t21 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 8720);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0);
    t36 = (t0 + 8400);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t17 = *((unsigned int *)t3);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t3) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB8;

}

static void Always_8384_6(char *t0)
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

LAB0:    t1 = (t0 + 7504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8384, ng0);
    t2 = (t0 + 8416);
    *((int *)t2) = 1;
    t3 = (t0 + 7536);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(8384, ng0);

LAB5:    xsi_set_current_line(8385, ng0);
    t4 = (t0 + 3904U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(8388, ng0);

LAB10:    xsi_set_current_line(8391, ng0);
    t2 = (t0 + 4944);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:
LAB13:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(8385, ng0);

LAB9:    xsi_set_current_line(8386, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4304);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    goto LAB8;

LAB11:    xsi_set_current_line(8392, ng0);
    t11 = ((char*)((ng2)));
    t12 = (t0 + 4304);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    goto LAB13;

}

static void Always_8396_7(char *t0)
{
    char t13[8];
    char t17[8];
    char t36[8];
    char t44[8];
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
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
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
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    int t68;
    int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    unsigned int t77;

LAB0:    t1 = (t0 + 7752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8396, ng0);
    t2 = (t0 + 8432);
    *((int *)t2) = 1;
    t3 = (t0 + 7784);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(8396, ng0);

LAB5:    xsi_set_current_line(8397, ng0);
    t4 = (t0 + 3904U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(8401, ng0);

LAB10:    xsi_set_current_line(8402, ng0);
    t2 = (t0 + 1344U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t2) != 0)
        goto LAB13;

LAB14:    t5 = (t13 + 4);
    t14 = *((unsigned int *)t13);
    t15 = *((unsigned int *)t5);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB15;

LAB16:    memcpy(t44, t13, 8);

LAB17:    t76 = (t0 + 5104);
    xsi_vlogvar_wait_assign_value(t76, t44, 0, 0, 1, 50000LL);
    xsi_set_current_line(8403, ng0);
    t2 = (t0 + 3264U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t13, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t2);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t4);
    t20 = *((unsigned int *)t5);
    t21 = (t16 | t20);
    t22 = (~(t21));
    t23 = (t15 & t22);
    if (t23 != 0)
        goto LAB34;

LAB31:    if (t21 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t13) = 1;

LAB34:    memset(t17, 0, 8);
    t12 = (t13 + 4);
    t24 = *((unsigned int *)t12);
    t28 = (~(t24));
    t29 = *((unsigned int *)t13);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t12) != 0)
        goto LAB37;

LAB38:    t19 = (t17 + 4);
    t32 = *((unsigned int *)t17);
    t33 = (!(t32));
    t34 = *((unsigned int *)t19);
    t35 = (t33 || t34);
    if (t35 > 0)
        goto LAB39;

LAB40:    memcpy(t44, t17, 8);

LAB41:    t58 = (t44 + 4);
    t72 = *((unsigned int *)t58);
    t73 = (~(t72));
    t74 = *((unsigned int *)t44);
    t75 = (t74 & t73);
    t77 = (t75 != 0);
    if (t77 > 0)
        goto LAB49;

LAB50:    xsi_set_current_line(8406, ng0);

LAB53:    xsi_set_current_line(8407, ng0);
    t2 = (t0 + 4624);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t13, 0, 8);
    t5 = (t13 + 4);
    t11 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 1);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t11);
    t10 = (t9 >> 1);
    t14 = (t10 & 1);
    *((unsigned int *)t5) = t14;
    t12 = (t0 + 4624);
    t18 = (t12 + 56U);
    t19 = *((char **)t18);
    memset(t17, 0, 8);
    t25 = (t17 + 4);
    t26 = (t19 + 4);
    t15 = *((unsigned int *)t19);
    t16 = (t15 >> 0);
    t20 = (t16 & 1);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t26);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t25) = t23;
    t24 = *((unsigned int *)t13);
    t28 = *((unsigned int *)t17);
    t29 = (t24 | t28);
    *((unsigned int *)t36) = t29;
    t27 = (t13 + 4);
    t37 = (t17 + 4);
    t43 = (t36 + 4);
    t30 = *((unsigned int *)t27);
    t31 = *((unsigned int *)t37);
    t32 = (t30 | t31);
    *((unsigned int *)t43) = t32;
    t33 = *((unsigned int *)t43);
    t34 = (t33 != 0);
    if (t34 == 1)
        goto LAB54;

LAB55:
LAB56:    t50 = (t0 + 4464);
    xsi_vlogvar_wait_assign_value(t50, t36, 0, 0, 1, 50000LL);

LAB51:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(8397, ng0);

LAB9:    xsi_set_current_line(8398, ng0);
    t11 = ((char*)((ng3)));
    t12 = (t0 + 4464);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    xsi_set_current_line(8399, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5104);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);
    goto LAB8;

LAB11:    *((unsigned int *)t13) = 1;
    goto LAB14;

LAB13:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB14;

LAB15:    t11 = (t0 + 5104);
    t12 = (t11 + 56U);
    t18 = *((char **)t12);
    memset(t17, 0, 8);
    t19 = (t18 + 4);
    t20 = *((unsigned int *)t19);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB21;

LAB19:    if (*((unsigned int *)t19) == 0)
        goto LAB18;

LAB20:    t25 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t25) = 1;

LAB21:    t26 = (t17 + 4);
    t27 = (t18 + 4);
    t28 = *((unsigned int *)t18);
    t29 = (~(t28));
    *((unsigned int *)t17) = t29;
    *((unsigned int *)t26) = 0;
    if (*((unsigned int *)t27) != 0)
        goto LAB23;

LAB22:    t34 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t34 & 1U);
    t35 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t35 & 1U);
    memset(t36, 0, 8);
    t37 = (t17 + 4);
    t38 = *((unsigned int *)t37);
    t39 = (~(t38));
    t40 = *((unsigned int *)t17);
    t41 = (t40 & t39);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t37) != 0)
        goto LAB26;

LAB27:    t45 = *((unsigned int *)t13);
    t46 = *((unsigned int *)t36);
    t47 = (t45 & t46);
    *((unsigned int *)t44) = t47;
    t48 = (t13 + 4);
    t49 = (t36 + 4);
    t50 = (t44 + 4);
    t51 = *((unsigned int *)t48);
    t52 = *((unsigned int *)t49);
    t53 = (t51 | t52);
    *((unsigned int *)t50) = t53;
    t54 = *((unsigned int *)t50);
    t55 = (t54 != 0);
    if (t55 == 1)
        goto LAB28;

LAB29:
LAB30:    goto LAB17;

LAB18:    *((unsigned int *)t17) = 1;
    goto LAB21;

LAB23:    t30 = *((unsigned int *)t17);
    t31 = *((unsigned int *)t27);
    *((unsigned int *)t17) = (t30 | t31);
    t32 = *((unsigned int *)t26);
    t33 = *((unsigned int *)t27);
    *((unsigned int *)t26) = (t32 | t33);
    goto LAB22;

LAB24:    *((unsigned int *)t36) = 1;
    goto LAB27;

LAB26:    t43 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB27;

LAB28:    t56 = *((unsigned int *)t44);
    t57 = *((unsigned int *)t50);
    *((unsigned int *)t44) = (t56 | t57);
    t58 = (t13 + 4);
    t59 = (t36 + 4);
    t60 = *((unsigned int *)t13);
    t61 = (~(t60));
    t62 = *((unsigned int *)t58);
    t63 = (~(t62));
    t64 = *((unsigned int *)t36);
    t65 = (~(t64));
    t66 = *((unsigned int *)t59);
    t67 = (~(t66));
    t68 = (t61 & t63);
    t69 = (t65 & t67);
    t70 = (~(t68));
    t71 = (~(t69));
    t72 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t72 & t70);
    t73 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t73 & t71);
    t74 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t74 & t70);
    t75 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t75 & t71);
    goto LAB30;

LAB33:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB34;

LAB35:    *((unsigned int *)t17) = 1;
    goto LAB38;

LAB37:    t18 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB38;

LAB39:    t25 = (t0 + 2144U);
    t26 = *((char **)t25);
    memset(t36, 0, 8);
    t25 = (t26 + 4);
    t38 = *((unsigned int *)t25);
    t39 = (~(t38));
    t40 = *((unsigned int *)t26);
    t41 = (t40 & t39);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t25) != 0)
        goto LAB44;

LAB45:    t45 = *((unsigned int *)t17);
    t46 = *((unsigned int *)t36);
    t47 = (t45 | t46);
    *((unsigned int *)t44) = t47;
    t37 = (t17 + 4);
    t43 = (t36 + 4);
    t48 = (t44 + 4);
    t51 = *((unsigned int *)t37);
    t52 = *((unsigned int *)t43);
    t53 = (t51 | t52);
    *((unsigned int *)t48) = t53;
    t54 = *((unsigned int *)t48);
    t55 = (t54 != 0);
    if (t55 == 1)
        goto LAB46;

LAB47:
LAB48:    goto LAB41;

LAB42:    *((unsigned int *)t36) = 1;
    goto LAB45;

LAB44:    t27 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB45;

LAB46:    t56 = *((unsigned int *)t44);
    t57 = *((unsigned int *)t48);
    *((unsigned int *)t44) = (t56 | t57);
    t49 = (t17 + 4);
    t50 = (t36 + 4);
    t60 = *((unsigned int *)t49);
    t61 = (~(t60));
    t62 = *((unsigned int *)t17);
    t68 = (t62 & t61);
    t63 = *((unsigned int *)t50);
    t64 = (~(t63));
    t65 = *((unsigned int *)t36);
    t69 = (t65 & t64);
    t66 = (~(t68));
    t67 = (~(t69));
    t70 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t70 & t66);
    t71 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t71 & t67);
    goto LAB48;

LAB49:    xsi_set_current_line(8403, ng0);

LAB52:    xsi_set_current_line(8404, ng0);
    t59 = ((char*)((ng2)));
    t76 = (t0 + 4464);
    xsi_vlogvar_wait_assign_value(t76, t59, 0, 0, 1, 50000LL);
    goto LAB51;

LAB54:    t35 = *((unsigned int *)t36);
    t38 = *((unsigned int *)t43);
    *((unsigned int *)t36) = (t35 | t38);
    t48 = (t13 + 4);
    t49 = (t17 + 4);
    t39 = *((unsigned int *)t48);
    t40 = (~(t39));
    t41 = *((unsigned int *)t13);
    t68 = (t41 & t40);
    t42 = *((unsigned int *)t49);
    t45 = (~(t42));
    t46 = *((unsigned int *)t17);
    t69 = (t46 & t45);
    t47 = (~(t68));
    t51 = (~(t69));
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t52 & t47);
    t53 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t53 & t51);
    goto LAB56;

}

static void Always_8412_8(char *t0)
{
    char t13[8];
    char t14[8];
    char t15[8];
    char t28[8];
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
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;

LAB0:    t1 = (t0 + 8000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(8412, ng0);
    t2 = (t0 + 8448);
    *((int *)t2) = 1;
    t3 = (t0 + 8032);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(8412, ng0);

LAB5:    xsi_set_current_line(8413, ng0);
    t4 = (t0 + 3904U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(8415, ng0);

LAB9:    xsi_set_current_line(8416, ng0);
    t2 = (t0 + 2944U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(8419, ng0);
    t2 = (t0 + 5104);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2464U);
    t11 = *((char **)t5);
    memset(t15, 0, 8);
    t5 = (t11 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t11);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t5) != 0)
        goto LAB15;

LAB16:    t16 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = *((unsigned int *)t16);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB17;

LAB18:    t21 = *((unsigned int *)t15);
    t22 = (~(t21));
    t23 = *((unsigned int *)t16);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t16) > 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t15) > 0)
        goto LAB23;

LAB24:    memcpy(t14, t28, 8);

LAB25:    xsi_vlogtype_concat(t13, 2, 2, 2U, t14, 1, t4, 1);
    t37 = (t0 + 4624);
    xsi_vlogvar_wait_assign_value(t37, t13, 0, 0, 2, 50000LL);

LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(8414, ng0);
    t11 = ((char*)((ng3)));
    t12 = (t0 + 4624);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 2, 50000LL);
    goto LAB8;

LAB10:    xsi_set_current_line(8417, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 4624);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 50000LL);
    goto LAB12;

LAB13:    *((unsigned int *)t15) = 1;
    goto LAB16;

LAB15:    t12 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB16;

LAB17:    t20 = ((char*)((ng1)));
    goto LAB18;

LAB19:    t25 = (t0 + 4624);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t28, 0, 8);
    t29 = (t28 + 4);
    t30 = (t27 + 4);
    t31 = *((unsigned int *)t27);
    t32 = (t31 >> 0);
    t33 = (t32 & 1);
    *((unsigned int *)t28) = t33;
    t34 = *((unsigned int *)t30);
    t35 = (t34 >> 0);
    t36 = (t35 & 1);
    *((unsigned int *)t29) = t36;
    goto LAB20;

LAB21:    xsi_vlog_unsigned_bit_combine(t14, 1, t20, 1, t28, 1);
    goto LAB25;

LAB23:    memcpy(t14, t20, 8);
    goto LAB25;

}


extern void secureip_m_04471956399568101867_2574657542_init()
{
	static char *pe[] = {(void *)NetDecl_8334_0,(void *)NetDecl_8336_1,(void *)NetDecl_8338_2,(void *)Always_8362_3,(void *)Always_8370_4,(void *)Cont_8382_5,(void *)Always_8384_6,(void *)Always_8396_7,(void *)Always_8412_8};
	xsi_register_didat("secureip_m_04471956399568101867_2574657542", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_04471956399568101867_2574657542.didat");
	xsi_register_executes(pe);
}
