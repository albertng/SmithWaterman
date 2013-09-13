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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/PicoAXIDemux.v";
static int ng1[] = {0, 0};
static int ng2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {1, 0};



static void Always_56_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 5304U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 6368);
    *((int *)t2) = 1;
    t3 = (t0 + 5336);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(56, ng0);

LAB5:    xsi_set_current_line(57, ng0);
    t4 = (t0 + 1752U);
    t5 = *((char **)t4);
    t4 = (t0 + 4232);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 0LL);
    goto LAB2;

}

static void Always_61_1(char *t0)
{
    char t15[8];
    char t19[8];
    char t25[8];
    char t62[8];
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
    char *t13;
    char *t14;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t63;
    char *t64;
    char *t65;
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
    char *t77;
    char *t78;
    char *t79;

LAB0:    t1 = (t0 + 5552U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 6384);
    *((int *)t2) = 1;
    t3 = (t0 + 5584);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(61, ng0);

LAB5:    xsi_set_current_line(62, ng0);
    t4 = (t0 + 4232);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2072U);
    t3 = *((char **)t2);
    memset(t15, 0, 8);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t2) != 0)
        goto LAB12;

LAB13:    t5 = (t15 + 4);
    t16 = *((unsigned int *)t15);
    t17 = *((unsigned int *)t5);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB14;

LAB15:    memcpy(t25, t15, 8);

LAB16:    t56 = (t25 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t25);
    t60 = (t59 & t58);
    t61 = (t60 != 0);
    if (t61 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 3032U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB42;

LAB43:
LAB44:
LAB26:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(62, ng0);

LAB9:    xsi_set_current_line(63, ng0);
    t13 = ((char*)((ng1)));
    t14 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 8, 0LL);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 256, 0LL);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4072);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3592);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    goto LAB8;

LAB10:    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB12:    t4 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB13;

LAB14:    t6 = (t0 + 2232U);
    t7 = *((char **)t6);
    memset(t19, 0, 8);
    t6 = (t7 + 4);
    t20 = *((unsigned int *)t6);
    t21 = (~(t20));
    t22 = *((unsigned int *)t7);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t6) != 0)
        goto LAB19;

LAB20:    t26 = *((unsigned int *)t15);
    t27 = *((unsigned int *)t19);
    t28 = (t26 & t27);
    *((unsigned int *)t25) = t28;
    t14 = (t15 + 4);
    t29 = (t19 + 4);
    t30 = (t25 + 4);
    t31 = *((unsigned int *)t14);
    t32 = *((unsigned int *)t29);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t34 = *((unsigned int *)t30);
    t35 = (t34 != 0);
    if (t35 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t19) = 1;
    goto LAB20;

LAB19:    t13 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB20;

LAB21:    t36 = *((unsigned int *)t25);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t25) = (t36 | t37);
    t38 = (t15 + 4);
    t39 = (t19 + 4);
    t40 = *((unsigned int *)t15);
    t41 = (~(t40));
    t42 = *((unsigned int *)t38);
    t43 = (~(t42));
    t44 = *((unsigned int *)t19);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (~(t46));
    t48 = (t41 & t43);
    t49 = (t45 & t47);
    t50 = (~(t48));
    t51 = (~(t49));
    t52 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t52 & t50);
    t53 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t53 & t51);
    t54 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t54 & t50);
    t55 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t55 & t51);
    goto LAB23;

LAB24:    xsi_set_current_line(71, ng0);

LAB27:    xsi_set_current_line(72, ng0);
    t63 = (t0 + 1912U);
    t64 = *((char **)t63);
    memset(t62, 0, 8);
    t63 = (t62 + 4);
    t65 = (t64 + 4);
    t66 = *((unsigned int *)t64);
    t67 = (t66 >> 0);
    *((unsigned int *)t62) = t67;
    t68 = *((unsigned int *)t65);
    t69 = (t68 >> 0);
    *((unsigned int *)t63) = t69;
    t70 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t70 & 255U);
    t71 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t71 & 255U);
    t72 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t72, t62, 0, 0, 8, 0LL);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2392U);
    t3 = *((char **)t2);
    t2 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 256, 0LL);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2552U);
    t3 = *((char **)t2);
    t2 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 2712U);
    t3 = *((char **)t2);
    t2 = (t0 + 4072);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 2, 0LL);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3592);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    xsi_set_current_line(79, ng0);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4392);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB28:    t2 = (t0 + 4392);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 472);
    t6 = *((char **)t5);
    memset(t15, 0, 8);
    xsi_vlog_signed_less(t15, 32, t4, 32, t6, 32);
    t5 = (t15 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t15);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB29;

LAB30:    goto LAB26;

LAB29:    xsi_set_current_line(79, ng0);

LAB31:    xsi_set_current_line(80, ng0);
    t7 = (t0 + 1912U);
    t13 = *((char **)t7);
    memset(t19, 0, 8);
    t7 = (t19 + 4);
    t14 = (t13 + 4);
    t16 = *((unsigned int *)t13);
    t17 = (t16 >> 8);
    *((unsigned int *)t19) = t17;
    t18 = *((unsigned int *)t14);
    t20 = (t18 >> 8);
    *((unsigned int *)t7) = t20;
    t21 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t21 & 15U);
    t22 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t22 & 15U);
    t29 = (t0 + 4392);
    t30 = (t29 + 56U);
    t38 = *((char **)t30);
    memset(t25, 0, 8);
    t39 = (t19 + 4);
    t56 = (t38 + 4);
    t23 = *((unsigned int *)t19);
    t24 = *((unsigned int *)t38);
    t26 = (t23 ^ t24);
    t27 = *((unsigned int *)t39);
    t28 = *((unsigned int *)t56);
    t31 = (t27 ^ t28);
    t32 = (t26 | t31);
    t33 = *((unsigned int *)t39);
    t34 = *((unsigned int *)t56);
    t35 = (t33 | t34);
    t36 = (~(t35));
    t37 = (t32 & t36);
    if (t37 != 0)
        goto LAB35;

LAB32:    if (t35 != 0)
        goto LAB34;

LAB33:    *((unsigned int *)t25) = 1;

LAB35:    t64 = (t25 + 4);
    t40 = *((unsigned int *)t64);
    t41 = (~(t40));
    t42 = *((unsigned int *)t25);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB36;

LAB37:
LAB38:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 4392);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t15, 0, 8);
    xsi_vlog_signed_add(t15, 32, t4, 32, t5, 32);
    t6 = (t0 + 4392);
    xsi_vlogvar_assign_value(t6, t15, 0, 0, 32);
    goto LAB28;

LAB34:    t63 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB35;

LAB36:    xsi_set_current_line(80, ng0);

LAB39:    xsi_set_current_line(81, ng0);
    t65 = ((char*)((ng3)));
    t72 = (t0 + 3592);
    t73 = (t0 + 3592);
    t74 = (t73 + 72U);
    t75 = *((char **)t74);
    t76 = (t0 + 4392);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    xsi_vlog_generic_convert_bit_index(t62, t75, 2, t78, 32, 1);
    t79 = (t62 + 4);
    t45 = *((unsigned int *)t79);
    t48 = (!(t45));
    if (t48 == 1)
        goto LAB40;

LAB41:    goto LAB38;

LAB40:    xsi_vlogvar_wait_assign_value(t72, t65, 0, *((unsigned int *)t62), 1, 0LL);
    goto LAB41;

LAB42:    xsi_set_current_line(87, ng0);

LAB45:    xsi_set_current_line(88, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 3592);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);
    goto LAB44;

}

static void Cont_94_2(char *t0)
{
    char t7[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
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
    unsigned int t21;
    char *t22;
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
    int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;

LAB0:    t1 = (t0 + 5800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 3032U);
    t3 = *((char **)t2);
    t2 = (t0 + 3592);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t7, 0, 8);
    t8 = (t5 + 4);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = *((unsigned int *)t8);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = (t12 | t15);
    t17 = *((unsigned int *)t8);
    t18 = *((unsigned int *)t9);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB7;

LAB4:    if (t19 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t7) = 1;

LAB7:    t24 = *((unsigned int *)t3);
    t25 = *((unsigned int *)t7);
    t26 = (t24 | t25);
    *((unsigned int *)t23) = t26;
    t27 = (t3 + 4);
    t28 = (t7 + 4);
    t29 = (t23 + 4);
    t30 = *((unsigned int *)t27);
    t31 = *((unsigned int *)t28);
    t32 = (t30 | t31);
    *((unsigned int *)t29) = t32;
    t33 = *((unsigned int *)t29);
    t34 = (t33 != 0);
    if (t34 == 1)
        goto LAB8;

LAB9:
LAB10:    t51 = (t0 + 6496);
    t52 = (t51 + 56U);
    t53 = *((char **)t52);
    t54 = (t53 + 56U);
    t55 = *((char **)t54);
    memset(t55, 0, 8);
    t56 = 1U;
    t57 = t56;
    t58 = (t23 + 4);
    t59 = *((unsigned int *)t23);
    t56 = (t56 & t59);
    t60 = *((unsigned int *)t58);
    t57 = (t57 & t60);
    t61 = (t55 + 4);
    t62 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t62 | t56);
    t63 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t63 | t57);
    xsi_driver_vfirst_trans(t51, 0, 0);
    t64 = (t0 + 6400);
    *((int *)t64) = 1;

LAB1:    return;
LAB6:    t22 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB7;

LAB8:    t35 = *((unsigned int *)t23);
    t36 = *((unsigned int *)t29);
    *((unsigned int *)t23) = (t35 | t36);
    t37 = (t3 + 4);
    t38 = (t7 + 4);
    t39 = *((unsigned int *)t37);
    t40 = (~(t39));
    t41 = *((unsigned int *)t3);
    t42 = (t41 & t40);
    t43 = *((unsigned int *)t38);
    t44 = (~(t43));
    t45 = *((unsigned int *)t7);
    t46 = (t45 & t44);
    t47 = (~(t42));
    t48 = (~(t46));
    t49 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t49 & t47);
    t50 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t50 & t48);
    goto LAB10;

}

static void Cont_97_3(char *t0)
{
    char t3[8];
    char t8[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;

LAB0:    t1 = (t0 + 6048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 3592);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2872U);
    t7 = *((char **)t6);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t7);
    t11 = (t9 & t10);
    *((unsigned int *)t8) = t11;
    t6 = (t5 + 4);
    t12 = (t7 + 4);
    t13 = (t8 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t12);
    t16 = (t14 | t15);
    *((unsigned int *)t13) = t16;
    t17 = *((unsigned int *)t13);
    t18 = (t17 != 0);
    if (t18 == 1)
        goto LAB4;

LAB5:
LAB6:    memset(t3, 0, 8);
    t39 = (t8 + 4);
    t40 = *((unsigned int *)t39);
    t41 = (~(t40));
    t42 = *((unsigned int *)t8);
    t43 = (t42 & t41);
    t44 = (t43 & 3U);
    if (t44 != 0)
        goto LAB7;

LAB8:    if (*((unsigned int *)t39) != 0)
        goto LAB9;

LAB10:    t46 = (t0 + 6560);
    t47 = (t46 + 56U);
    t48 = *((char **)t47);
    t49 = (t48 + 56U);
    t50 = *((char **)t49);
    memset(t50, 0, 8);
    t51 = 1U;
    t52 = t51;
    t53 = (t3 + 4);
    t54 = *((unsigned int *)t3);
    t51 = (t51 & t54);
    t55 = *((unsigned int *)t53);
    t52 = (t52 & t55);
    t56 = (t50 + 4);
    t57 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t57 | t51);
    t58 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t58 | t52);
    xsi_driver_vfirst_trans(t46, 0, 0);
    t59 = (t0 + 6416);
    *((int *)t59) = 1;

LAB1:    return;
LAB4:    t19 = *((unsigned int *)t8);
    t20 = *((unsigned int *)t13);
    *((unsigned int *)t8) = (t19 | t20);
    t21 = (t5 + 4);
    t22 = (t7 + 4);
    t23 = *((unsigned int *)t5);
    t24 = (~(t23));
    t25 = *((unsigned int *)t21);
    t26 = (~(t25));
    t27 = *((unsigned int *)t7);
    t28 = (~(t27));
    t29 = *((unsigned int *)t22);
    t30 = (~(t29));
    t31 = (t24 & t26);
    t32 = (t28 & t30);
    t33 = (~(t31));
    t34 = (~(t32));
    t35 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t35 & t33);
    t36 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t36 & t34);
    t37 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t37 & t33);
    t38 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t38 & t34);
    goto LAB6;

LAB7:    *((unsigned int *)t3) = 1;
    goto LAB10;

LAB9:    t45 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB10;

}


extern void work_m_07317430054798131369_0686155800_init()
{
	static char *pe[] = {(void *)Always_56_0,(void *)Always_61_1,(void *)Cont_94_2,(void *)Cont_97_3};
	xsi_register_didat("work_m_07317430054798131369_0686155800", "isim/PicoTestbench_isim_beh.exe.sim/work/m_07317430054798131369_0686155800.didat");
	xsi_register_executes(pe);
}
