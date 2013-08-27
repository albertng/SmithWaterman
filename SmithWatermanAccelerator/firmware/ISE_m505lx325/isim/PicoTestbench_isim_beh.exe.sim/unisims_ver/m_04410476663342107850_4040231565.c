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
static unsigned int ng0[] = {1U, 0U};
static int ng1[] = {1, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {0, 0};
static int ng4[] = {0, 0, 0, 0};
static int ng5[] = {10, 0, 0, 0};



static void Gate_41_0(char *t0)
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
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 4120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6880);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 4);
    t11 = (t4 + 4);
    if (*((unsigned int *)t11) == 1)
        goto LAB4;

LAB5:    t12 = *((unsigned int *)t4);
    t13 = (t12 & 1);
    *((unsigned int *)t9) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 & 1);
    *((unsigned int *)t10) = t15;

LAB6:    t16 = (t0 + 6880);
    xsi_driver_vfirst_trans(t16, 0, 0);
    t17 = (t0 + 6672);
    *((int *)t17) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t9) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB6;

}

static void Gate_42_1(char *t0)
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
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 4368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = (t0 + 6944);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = (t3 + 4);
    if (*((unsigned int *)t9) == 1)
        goto LAB4;

LAB5:    t10 = *((unsigned int *)t3);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 & 1);
    *((unsigned int *)t8) = t13;

LAB6:    t14 = (t0 + 6944);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t15 = (t0 + 6688);
    *((int *)t15) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB6;

}

static void Gate_43_2(char *t0)
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
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 4616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 7008);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = (t3 + 4);
    if (*((unsigned int *)t9) == 1)
        goto LAB4;

LAB5:    t10 = *((unsigned int *)t3);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 & 1);
    *((unsigned int *)t8) = t13;

LAB6:    t14 = (t0 + 7008);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t15 = (t0 + 6704);
    *((int *)t15) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB6;

}

static void Always_46_3(char *t0)
{
    char t6[8];
    char t22[8];
    char t39[8];
    char t55[8];
    char t63[8];
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
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;

LAB0:    t1 = (t0 + 4864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6720);
    *((int *)t2) = 1;
    t3 = (t0 + 4896);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng0)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
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
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    memset(t22, 0, 8);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) != 0)
        goto LAB12;

LAB13:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = (!(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB14;

LAB15:    memcpy(t63, t22, 8);

LAB16:    t91 = (t63 + 4);
    t92 = *((unsigned int *)t91);
    t93 = (~(t92));
    t94 = *((unsigned int *)t63);
    t95 = (t94 & t93);
    t96 = (t95 != 0);
    if (t96 > 0)
        goto LAB28;

LAB29:    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB34;

LAB31:    if (t18 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t6) = 1;

LAB34:    memset(t22, 0, 8);
    t8 = (t6 + 4);
    t24 = *((unsigned int *)t8);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t8) != 0)
        goto LAB37;

LAB38:    t23 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t23);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB39;

LAB40:    memcpy(t63, t22, 8);

LAB41:    t77 = (t63 + 4);
    t95 = *((unsigned int *)t77);
    t96 = (~(t95));
    t99 = *((unsigned int *)t63);
    t100 = (t99 & t96);
    t101 = (t100 != 0);
    if (t101 > 0)
        goto LAB53;

LAB54:
LAB55:
LAB30:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t22) = 1;
    goto LAB13;

LAB12:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB13;

LAB14:    t35 = (t0 + 3048);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = ((char*)((ng1)));
    memset(t39, 0, 8);
    t40 = (t37 + 4);
    t41 = (t38 + 4);
    t42 = *((unsigned int *)t37);
    t43 = *((unsigned int *)t38);
    t44 = (t42 ^ t43);
    t45 = *((unsigned int *)t40);
    t46 = *((unsigned int *)t41);
    t47 = (t45 ^ t46);
    t48 = (t44 | t47);
    t49 = *((unsigned int *)t40);
    t50 = *((unsigned int *)t41);
    t51 = (t49 | t50);
    t52 = (~(t51));
    t53 = (t48 & t52);
    if (t53 != 0)
        goto LAB20;

LAB17:    if (t51 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t39) = 1;

LAB20:    memset(t55, 0, 8);
    t56 = (t39 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t39);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t56) != 0)
        goto LAB23;

LAB24:    t64 = *((unsigned int *)t22);
    t65 = *((unsigned int *)t55);
    t66 = (t64 | t65);
    *((unsigned int *)t63) = t66;
    t67 = (t22 + 4);
    t68 = (t55 + 4);
    t69 = (t63 + 4);
    t70 = *((unsigned int *)t67);
    t71 = *((unsigned int *)t68);
    t72 = (t70 | t71);
    *((unsigned int *)t69) = t72;
    t73 = *((unsigned int *)t69);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB19:    t54 = (t39 + 4);
    *((unsigned int *)t39) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t55) = 1;
    goto LAB24;

LAB23:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB24;

LAB25:    t75 = *((unsigned int *)t63);
    t76 = *((unsigned int *)t69);
    *((unsigned int *)t63) = (t75 | t76);
    t77 = (t22 + 4);
    t78 = (t55 + 4);
    t79 = *((unsigned int *)t77);
    t80 = (~(t79));
    t81 = *((unsigned int *)t22);
    t82 = (t81 & t80);
    t83 = *((unsigned int *)t78);
    t84 = (~(t83));
    t85 = *((unsigned int *)t55);
    t86 = (t85 & t84);
    t87 = (~(t82));
    t88 = (~(t86));
    t89 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t89 & t87);
    t90 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t90 & t88);
    goto LAB27;

LAB28:    t97 = ((char*)((ng2)));
    t98 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t98, t97, 0, 0, 1, 0LL);
    goto LAB30;

LAB33:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB34;

LAB35:    *((unsigned int *)t22) = 1;
    goto LAB38;

LAB37:    t21 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB38;

LAB39:    t29 = (t0 + 3048);
    t30 = (t29 + 56U);
    t35 = *((char **)t30);
    t36 = ((char*)((ng3)));
    memset(t39, 0, 8);
    t37 = (t35 + 4);
    t38 = (t36 + 4);
    t34 = *((unsigned int *)t35);
    t42 = *((unsigned int *)t36);
    t43 = (t34 ^ t42);
    t44 = *((unsigned int *)t37);
    t45 = *((unsigned int *)t38);
    t46 = (t44 ^ t45);
    t47 = (t43 | t46);
    t48 = *((unsigned int *)t37);
    t49 = *((unsigned int *)t38);
    t50 = (t48 | t49);
    t51 = (~(t50));
    t52 = (t47 & t51);
    if (t52 != 0)
        goto LAB45;

LAB42:    if (t50 != 0)
        goto LAB44;

LAB43:    *((unsigned int *)t39) = 1;

LAB45:    memset(t55, 0, 8);
    t41 = (t39 + 4);
    t53 = *((unsigned int *)t41);
    t57 = (~(t53));
    t58 = *((unsigned int *)t39);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t41) != 0)
        goto LAB48;

LAB49:    t61 = *((unsigned int *)t22);
    t64 = *((unsigned int *)t55);
    t65 = (t61 & t64);
    *((unsigned int *)t63) = t65;
    t56 = (t22 + 4);
    t62 = (t55 + 4);
    t67 = (t63 + 4);
    t66 = *((unsigned int *)t56);
    t70 = *((unsigned int *)t62);
    t71 = (t66 | t70);
    *((unsigned int *)t67) = t71;
    t72 = *((unsigned int *)t67);
    t73 = (t72 != 0);
    if (t73 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB41;

LAB44:    t40 = (t39 + 4);
    *((unsigned int *)t39) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB45;

LAB46:    *((unsigned int *)t55) = 1;
    goto LAB49;

LAB48:    t54 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB49;

LAB50:    t74 = *((unsigned int *)t63);
    t75 = *((unsigned int *)t67);
    *((unsigned int *)t63) = (t74 | t75);
    t68 = (t22 + 4);
    t69 = (t55 + 4);
    t76 = *((unsigned int *)t22);
    t79 = (~(t76));
    t80 = *((unsigned int *)t68);
    t81 = (~(t80));
    t83 = *((unsigned int *)t55);
    t84 = (~(t83));
    t85 = *((unsigned int *)t69);
    t87 = (~(t85));
    t82 = (t79 & t81);
    t86 = (t84 & t87);
    t88 = (~(t82));
    t89 = (~(t86));
    t90 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t90 & t88);
    t92 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t92 & t89);
    t93 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t93 & t88);
    t94 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t94 & t89);
    goto LAB52;

LAB53:    t78 = ((char*)((ng0)));
    t91 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t91, t78, 0, 0, 1, 0LL);
    goto LAB55;

}

static void Initial_67_4(char *t0)
{
    char *t1;
    char *t2;

LAB0:
LAB2:    t1 = ((char*)((ng4)));
    t2 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 64, 0LL);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    t1 = ((char*)((ng4)));
    t2 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 64, 0LL);

LAB1:    return;
}

static void Always_76_5(char *t0)
{
    char t6[8];
    char t28[16];
    char t31[16];
    char t33[16];
    char t40[8];
    char t42[8];
    char t45[8];
    char t80[16];
    char t85[16];
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
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t29;
    char *t30;
    char *t32;
    double t34;
    char *t35;
    char *t36;
    char *t37;
    double t38;
    double t39;
    char *t41;
    char *t43;
    char *t44;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    int t66;
    int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t86;

LAB0:    t1 = (t0 + 5360U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6736);
    *((int *)t2) = 1;
    t3 = (t0 + 5392);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
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
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:
LAB13:    t29 = xsi_vlog_time(t28, 1000.0000000000000, 1.0000000000000000);
    t30 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t30, t28, 0, 0, 64, 0LL);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t28, 64, t4, 64, t5, 32);
    memset(t6, 0, 8);
    t7 = (t28 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t28);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t7) != 0)
        goto LAB16;

LAB17:    t21 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t21);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB18;

LAB19:    memcpy(t45, t6, 8);

LAB20:    t74 = (t45 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t45);
    t78 = (t77 & t76);
    t79 = (t78 != 0);
    if (t79 > 0)
        goto LAB28;

LAB29:    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t28, 64, t4, 64, t5, 32);
    memset(t6, 0, 8);
    t7 = (t28 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t28);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t7) != 0)
        goto LAB33;

LAB34:    t21 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t21);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB35;

LAB36:    memcpy(t45, t6, 8);

LAB37:    t74 = (t45 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t45);
    t78 = (t77 & t76);
    t79 = (t78 != 0);
    if (t79 > 0)
        goto LAB45;

LAB46:    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    xsi_vlog_unsigned_equal(t28, 64, t4, 64, t5, 32);
    memset(t6, 0, 8);
    t7 = (t28 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t28);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB48;

LAB49:    if (*((unsigned int *)t7) != 0)
        goto LAB50;

LAB51:    t21 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t21);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB52;

LAB53:    memcpy(t42, t6, 8);

LAB54:    t47 = (t42 + 4);
    t73 = *((unsigned int *)t47);
    t75 = (~(t73));
    t76 = *((unsigned int *)t42);
    t77 = (t76 & t75);
    t78 = (t77 != 0);
    if (t78 > 0)
        goto LAB62;

LAB63:
LAB64:
LAB47:
LAB30:    goto LAB12;

LAB14:    *((unsigned int *)t6) = 1;
    goto LAB17;

LAB16:    t8 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB17;

LAB18:    t22 = xsi_vlog_time(t31, 1000.0000000000000, 1.0000000000000000);
    t29 = (t0 + 2088);
    t30 = (t29 + 56U);
    t32 = *((char **)t30);
    xsi_vlog_unsigned_minus(t33, 64, t31, 64, t32, 64);
    t34 = xsi_vlog_convert_to_real(t33, 64, 2);
    t35 = (t0 + 2248);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = xsi_vlog_convert_to_real(t37, 64, 2);
    t39 = (1.5000000000000000 * t38);
    t17 = (t34 <= t39);
    *((unsigned int *)t40) = t17;
    t41 = (t40 + 4);
    *((unsigned int *)t41) = 0U;
    memset(t42, 0, 8);
    t43 = (t40 + 4);
    t18 = *((unsigned int *)t43);
    t19 = (~(t18));
    t20 = *((unsigned int *)t40);
    t23 = (t20 & t19);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t43) != 0)
        goto LAB23;

LAB24:    t25 = *((unsigned int *)t6);
    t26 = *((unsigned int *)t42);
    t27 = (t25 & t26);
    *((unsigned int *)t45) = t27;
    t46 = (t6 + 4);
    t47 = (t42 + 4);
    t48 = (t45 + 4);
    t49 = *((unsigned int *)t46);
    t50 = *((unsigned int *)t47);
    t51 = (t49 | t50);
    *((unsigned int *)t48) = t51;
    t52 = *((unsigned int *)t48);
    t53 = (t52 != 0);
    if (t53 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB20;

LAB21:    *((unsigned int *)t42) = 1;
    goto LAB24;

LAB23:    t44 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB24;

LAB25:    t54 = *((unsigned int *)t45);
    t55 = *((unsigned int *)t48);
    *((unsigned int *)t45) = (t54 | t55);
    t56 = (t6 + 4);
    t57 = (t42 + 4);
    t58 = *((unsigned int *)t6);
    t59 = (~(t58));
    t60 = *((unsigned int *)t56);
    t61 = (~(t60));
    t62 = *((unsigned int *)t42);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (~(t64));
    t66 = (t59 & t61);
    t67 = (t63 & t65);
    t68 = (~(t66));
    t69 = (~(t67));
    t70 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t70 & t68);
    t71 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t71 & t69);
    t72 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t72 & t68);
    t73 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t73 & t69);
    goto LAB27;

LAB28:    t81 = xsi_vlog_time(t80, 1000.0000000000000, 1.0000000000000000);
    t82 = (t0 + 2088);
    t83 = (t82 + 56U);
    t84 = *((char **)t83);
    xsi_vlog_unsigned_minus(t85, 64, t80, 64, t84, 64);
    t86 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t86, t85, 0, 0, 64, 0LL);
    goto LAB30;

LAB31:    *((unsigned int *)t6) = 1;
    goto LAB34;

LAB33:    t8 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB34;

LAB35:    t22 = xsi_vlog_time(t31, 1000.0000000000000, 1.0000000000000000);
    t29 = (t0 + 2088);
    t30 = (t29 + 56U);
    t32 = *((char **)t30);
    xsi_vlog_unsigned_minus(t33, 64, t31, 64, t32, 64);
    t34 = xsi_vlog_convert_to_real(t33, 64, 2);
    t35 = (t0 + 2248);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = xsi_vlog_convert_to_real(t37, 64, 2);
    t39 = (1.5000000000000000 * t38);
    t17 = (t34 > t39);
    *((unsigned int *)t40) = t17;
    t41 = (t40 + 4);
    *((unsigned int *)t41) = 0U;
    memset(t42, 0, 8);
    t43 = (t40 + 4);
    t18 = *((unsigned int *)t43);
    t19 = (~(t18));
    t20 = *((unsigned int *)t40);
    t23 = (t20 & t19);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t43) != 0)
        goto LAB40;

LAB41:    t25 = *((unsigned int *)t6);
    t26 = *((unsigned int *)t42);
    t27 = (t25 & t26);
    *((unsigned int *)t45) = t27;
    t46 = (t6 + 4);
    t47 = (t42 + 4);
    t48 = (t45 + 4);
    t49 = *((unsigned int *)t46);
    t50 = *((unsigned int *)t47);
    t51 = (t49 | t50);
    *((unsigned int *)t48) = t51;
    t52 = *((unsigned int *)t48);
    t53 = (t52 != 0);
    if (t53 == 1)
        goto LAB42;

LAB43:
LAB44:    goto LAB37;

LAB38:    *((unsigned int *)t42) = 1;
    goto LAB41;

LAB40:    t44 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB41;

LAB42:    t54 = *((unsigned int *)t45);
    t55 = *((unsigned int *)t48);
    *((unsigned int *)t45) = (t54 | t55);
    t56 = (t6 + 4);
    t57 = (t42 + 4);
    t58 = *((unsigned int *)t6);
    t59 = (~(t58));
    t60 = *((unsigned int *)t56);
    t61 = (~(t60));
    t62 = *((unsigned int *)t42);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (~(t64));
    t66 = (t59 & t61);
    t67 = (t63 & t65);
    t68 = (~(t66));
    t69 = (~(t67));
    t70 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t70 & t68);
    t71 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t71 & t69);
    t72 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t72 & t68);
    t73 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t73 & t69);
    goto LAB44;

LAB45:    t81 = ((char*)((ng4)));
    t82 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t82, t81, 0, 0, 64, 0LL);
    goto LAB47;

LAB48:    *((unsigned int *)t6) = 1;
    goto LAB51;

LAB50:    t8 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB51;

LAB52:    t22 = (t0 + 2088);
    t29 = (t22 + 56U);
    t30 = *((char **)t29);
    t32 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t31, 64, t30, 64, t32, 32);
    memset(t40, 0, 8);
    t35 = (t31 + 4);
    t17 = *((unsigned int *)t35);
    t18 = (~(t17));
    t19 = *((unsigned int *)t31);
    t20 = (t19 & t18);
    t23 = (t20 & 1U);
    if (t23 != 0)
        goto LAB55;

LAB56:    if (*((unsigned int *)t35) != 0)
        goto LAB57;

LAB58:    t24 = *((unsigned int *)t6);
    t25 = *((unsigned int *)t40);
    t26 = (t24 & t25);
    *((unsigned int *)t42) = t26;
    t37 = (t6 + 4);
    t41 = (t40 + 4);
    t43 = (t42 + 4);
    t27 = *((unsigned int *)t37);
    t49 = *((unsigned int *)t41);
    t50 = (t27 | t49);
    *((unsigned int *)t43) = t50;
    t51 = *((unsigned int *)t43);
    t52 = (t51 != 0);
    if (t52 == 1)
        goto LAB59;

LAB60:
LAB61:    goto LAB54;

LAB55:    *((unsigned int *)t40) = 1;
    goto LAB58;

LAB57:    t36 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB58;

LAB59:    t53 = *((unsigned int *)t42);
    t54 = *((unsigned int *)t43);
    *((unsigned int *)t42) = (t53 | t54);
    t44 = (t6 + 4);
    t46 = (t40 + 4);
    t55 = *((unsigned int *)t6);
    t58 = (~(t55));
    t59 = *((unsigned int *)t44);
    t60 = (~(t59));
    t61 = *((unsigned int *)t40);
    t62 = (~(t61));
    t63 = *((unsigned int *)t46);
    t64 = (~(t63));
    t66 = (t58 & t60);
    t67 = (t62 & t64);
    t65 = (~(t66));
    t68 = (~(t67));
    t69 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t69 & t65);
    t70 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t70 & t68);
    t71 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t71 & t65);
    t72 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t72 & t68);
    goto LAB61;

LAB62:    t48 = xsi_vlog_time(t33, 1000.0000000000000, 1.0000000000000000);
    t56 = (t0 + 2088);
    t57 = (t56 + 56U);
    t74 = *((char **)t57);
    xsi_vlog_unsigned_minus(t80, 64, t33, 64, t74, 64);
    t81 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t81, t80, 0, 0, 64, 0LL);
    goto LAB64;

}

static void Always_88_6(char *t0)
{
    char t6[16];
    char t22[8];
    char t33[8];
    char t49[8];
    char t65[8];
    char t73[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    char *t20;
    char *t21;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    int t97;
    int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t111;
    char *t112;

LAB0:    t1 = (t0 + 5608U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6752);
    *((int *)t2) = 1;
    t3 = (t0 + 5640);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = ((char*)((ng2)));
    t5 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t6, 64, t4, 64, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:
LAB8:    t2 = ((char*)((ng2)));
    t3 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t15 = xsi_vlog_convert_to_real(t4, 64, 2);
    t16 = (t15 * 9.0999999999999996);
    t5 = ((char*)((ng5)));
    t17 = xsi_vlog_convert_to_real(t5, 32, 1);
    t18 = (t16 / t17);
    t19 = (t18 < 0.0000000000000000);
    if (t19 == 1)
        goto LAB9;

LAB10:    t18 = (t18 + 0.50000000000000000);
    t18 = ((int64)(t18));

LAB11:    t18 = (t18 * 1000.0000000000000);
    t7 = (t0 + 5416);
    xsi_process_wait(t7, t18);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB6:    t13 = ((char*)((ng2)));
    t14 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 1, 0LL);
    goto LAB8;

LAB9:    t18 = 0.0000000000000000;
    goto LAB11;

LAB12:    t13 = (t0 + 2408);
    t14 = (t13 + 56U);
    t20 = *((char **)t14);
    t21 = ((char*)((ng0)));
    memset(t22, 0, 8);
    t23 = (t20 + 4);
    t24 = (t21 + 4);
    t8 = *((unsigned int *)t20);
    t9 = *((unsigned int *)t21);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t23);
    t12 = *((unsigned int *)t24);
    t25 = (t11 ^ t12);
    t26 = (t10 | t25);
    t27 = *((unsigned int *)t23);
    t28 = *((unsigned int *)t24);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB14;

LAB13:    if (t29 != 0)
        goto LAB15;

LAB16:    memset(t33, 0, 8);
    t34 = (t22 + 4);
    t35 = *((unsigned int *)t34);
    t36 = (~(t35));
    t37 = *((unsigned int *)t22);
    t38 = (t37 & t36);
    t39 = (t38 & 1U);
    if (t39 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t34) != 0)
        goto LAB19;

LAB20:    t41 = (t33 + 4);
    t42 = *((unsigned int *)t33);
    t43 = *((unsigned int *)t41);
    t44 = (t42 || t43);
    if (t44 > 0)
        goto LAB21;

LAB22:    memcpy(t73, t33, 8);

LAB23:    t105 = (t73 + 4);
    t106 = *((unsigned int *)t105);
    t107 = (~(t106));
    t108 = *((unsigned int *)t73);
    t109 = (t108 & t107);
    t110 = (t109 != 0);
    if (t110 > 0)
        goto LAB35;

LAB36:
LAB37:    goto LAB2;

LAB14:    *((unsigned int *)t22) = 1;
    goto LAB16;

LAB15:    t32 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB16;

LAB17:    *((unsigned int *)t33) = 1;
    goto LAB20;

LAB19:    t40 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB20;

LAB21:    t45 = (t0 + 2728);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = ((char*)((ng0)));
    memset(t49, 0, 8);
    t50 = (t47 + 4);
    t51 = (t48 + 4);
    t52 = *((unsigned int *)t47);
    t53 = *((unsigned int *)t48);
    t54 = (t52 ^ t53);
    t55 = *((unsigned int *)t50);
    t56 = *((unsigned int *)t51);
    t57 = (t55 ^ t56);
    t58 = (t54 | t57);
    t59 = *((unsigned int *)t50);
    t60 = *((unsigned int *)t51);
    t61 = (t59 | t60);
    t62 = (~(t61));
    t63 = (t58 & t62);
    if (t63 != 0)
        goto LAB25;

LAB24:    if (t61 != 0)
        goto LAB26;

LAB27:    memset(t65, 0, 8);
    t66 = (t49 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (~(t67));
    t69 = *((unsigned int *)t49);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t66) != 0)
        goto LAB30;

LAB31:    t74 = *((unsigned int *)t33);
    t75 = *((unsigned int *)t65);
    t76 = (t74 & t75);
    *((unsigned int *)t73) = t76;
    t77 = (t33 + 4);
    t78 = (t65 + 4);
    t79 = (t73 + 4);
    t80 = *((unsigned int *)t77);
    t81 = *((unsigned int *)t78);
    t82 = (t80 | t81);
    *((unsigned int *)t79) = t82;
    t83 = *((unsigned int *)t79);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB32;

LAB33:
LAB34:    goto LAB23;

LAB25:    *((unsigned int *)t49) = 1;
    goto LAB27;

LAB26:    t64 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB27;

LAB28:    *((unsigned int *)t65) = 1;
    goto LAB31;

LAB30:    t72 = (t65 + 4);
    *((unsigned int *)t65) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB31;

LAB32:    t85 = *((unsigned int *)t73);
    t86 = *((unsigned int *)t79);
    *((unsigned int *)t73) = (t85 | t86);
    t87 = (t33 + 4);
    t88 = (t65 + 4);
    t89 = *((unsigned int *)t33);
    t90 = (~(t89));
    t91 = *((unsigned int *)t87);
    t92 = (~(t91));
    t93 = *((unsigned int *)t65);
    t94 = (~(t93));
    t95 = *((unsigned int *)t88);
    t96 = (~(t95));
    t97 = (t90 & t92);
    t98 = (t94 & t96);
    t99 = (~(t97));
    t100 = (~(t98));
    t101 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t101 & t99);
    t102 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t102 & t100);
    t103 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t103 & t99);
    t104 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t104 & t100);
    goto LAB34;

LAB35:    t111 = ((char*)((ng1)));
    t112 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t112, t111, 0, 0, 1, 0LL);
    goto LAB37;

}

static void Always_99_7(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 5856U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6768);
    *((int *)t2) = 1;
    t3 = (t0 + 5888);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = ((char*)((ng0)));
    t5 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB2;

}

static void Always_103_8(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 6104U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6784);
    *((int *)t2) = 1;
    t3 = (t0 + 6136);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = ((char*)((ng0)));
    t5 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB2;

}

static void Always_107_9(char *t0)
{
    char t6[16];
    char t22[8];
    char t33[8];
    char t49[8];
    char t65[8];
    char t73[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    double t15;
    double t16;
    double t17;
    double t18;
    double t19;
    char *t20;
    char *t21;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    int t97;
    int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t111;
    char *t112;

LAB0:    t1 = (t0 + 6352U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 6800);
    *((int *)t2) = 1;
    t3 = (t0 + 6384);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = ((char*)((ng2)));
    t5 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t6, 64, t4, 64, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:
LAB8:    t2 = ((char*)((ng2)));
    t3 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t15 = xsi_vlog_convert_to_real(t4, 64, 2);
    t16 = (t15 * 9.0999999999999996);
    t5 = ((char*)((ng5)));
    t17 = xsi_vlog_convert_to_real(t5, 32, 1);
    t18 = (t16 / t17);
    t19 = (t18 < 0.0000000000000000);
    if (t19 == 1)
        goto LAB9;

LAB10:    t18 = (t18 + 0.50000000000000000);
    t18 = ((int64)(t18));

LAB11:    t18 = (t18 * 1000.0000000000000);
    t7 = (t0 + 6160);
    xsi_process_wait(t7, t18);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB6:    t13 = ((char*)((ng2)));
    t14 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 1, 0LL);
    goto LAB8;

LAB9:    t18 = 0.0000000000000000;
    goto LAB11;

LAB12:    t13 = (t0 + 2568);
    t14 = (t13 + 56U);
    t20 = *((char **)t14);
    t21 = ((char*)((ng0)));
    memset(t22, 0, 8);
    t23 = (t20 + 4);
    t24 = (t21 + 4);
    t8 = *((unsigned int *)t20);
    t9 = *((unsigned int *)t21);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t23);
    t12 = *((unsigned int *)t24);
    t25 = (t11 ^ t12);
    t26 = (t10 | t25);
    t27 = *((unsigned int *)t23);
    t28 = *((unsigned int *)t24);
    t29 = (t27 | t28);
    t30 = (~(t29));
    t31 = (t26 & t30);
    if (t31 != 0)
        goto LAB14;

LAB13:    if (t29 != 0)
        goto LAB15;

LAB16:    memset(t33, 0, 8);
    t34 = (t22 + 4);
    t35 = *((unsigned int *)t34);
    t36 = (~(t35));
    t37 = *((unsigned int *)t22);
    t38 = (t37 & t36);
    t39 = (t38 & 1U);
    if (t39 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t34) != 0)
        goto LAB19;

LAB20:    t41 = (t33 + 4);
    t42 = *((unsigned int *)t33);
    t43 = *((unsigned int *)t41);
    t44 = (t42 || t43);
    if (t44 > 0)
        goto LAB21;

LAB22:    memcpy(t73, t33, 8);

LAB23:    t105 = (t73 + 4);
    t106 = *((unsigned int *)t105);
    t107 = (~(t106));
    t108 = *((unsigned int *)t73);
    t109 = (t108 & t107);
    t110 = (t109 != 0);
    if (t110 > 0)
        goto LAB35;

LAB36:
LAB37:    goto LAB2;

LAB14:    *((unsigned int *)t22) = 1;
    goto LAB16;

LAB15:    t32 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB16;

LAB17:    *((unsigned int *)t33) = 1;
    goto LAB20;

LAB19:    t40 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB20;

LAB21:    t45 = (t0 + 2888);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = ((char*)((ng0)));
    memset(t49, 0, 8);
    t50 = (t47 + 4);
    t51 = (t48 + 4);
    t52 = *((unsigned int *)t47);
    t53 = *((unsigned int *)t48);
    t54 = (t52 ^ t53);
    t55 = *((unsigned int *)t50);
    t56 = *((unsigned int *)t51);
    t57 = (t55 ^ t56);
    t58 = (t54 | t57);
    t59 = *((unsigned int *)t50);
    t60 = *((unsigned int *)t51);
    t61 = (t59 | t60);
    t62 = (~(t61));
    t63 = (t58 & t62);
    if (t63 != 0)
        goto LAB25;

LAB24:    if (t61 != 0)
        goto LAB26;

LAB27:    memset(t65, 0, 8);
    t66 = (t49 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (~(t67));
    t69 = *((unsigned int *)t49);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t66) != 0)
        goto LAB30;

LAB31:    t74 = *((unsigned int *)t33);
    t75 = *((unsigned int *)t65);
    t76 = (t74 & t75);
    *((unsigned int *)t73) = t76;
    t77 = (t33 + 4);
    t78 = (t65 + 4);
    t79 = (t73 + 4);
    t80 = *((unsigned int *)t77);
    t81 = *((unsigned int *)t78);
    t82 = (t80 | t81);
    *((unsigned int *)t79) = t82;
    t83 = *((unsigned int *)t79);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB32;

LAB33:
LAB34:    goto LAB23;

LAB25:    *((unsigned int *)t49) = 1;
    goto LAB27;

LAB26:    t64 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB27;

LAB28:    *((unsigned int *)t65) = 1;
    goto LAB31;

LAB30:    t72 = (t65 + 4);
    *((unsigned int *)t65) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB31;

LAB32:    t85 = *((unsigned int *)t73);
    t86 = *((unsigned int *)t79);
    *((unsigned int *)t73) = (t85 | t86);
    t87 = (t33 + 4);
    t88 = (t65 + 4);
    t89 = *((unsigned int *)t33);
    t90 = (~(t89));
    t91 = *((unsigned int *)t87);
    t92 = (~(t91));
    t93 = *((unsigned int *)t65);
    t94 = (~(t93));
    t95 = *((unsigned int *)t88);
    t96 = (~(t95));
    t97 = (t90 & t92);
    t98 = (t94 & t96);
    t99 = (~(t97));
    t100 = (~(t98));
    t101 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t101 & t99);
    t102 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t102 & t100);
    t103 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t103 & t99);
    t104 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t104 & t100);
    goto LAB34;

LAB35:    t111 = ((char*)((ng1)));
    t112 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t112, t111, 0, 0, 1, 0LL);
    goto LAB37;

}


extern void unisims_ver_m_04410476663342107850_4040231565_init()
{
	static char *pe[] = {(void *)Gate_41_0,(void *)Gate_42_1,(void *)Gate_43_2,(void *)Always_46_3,(void *)Initial_67_4,(void *)Always_76_5,(void *)Always_88_6,(void *)Always_99_7,(void *)Always_103_8,(void *)Always_107_9};
	xsi_register_didat("unisims_ver_m_04410476663342107850_4040231565", "isim/PicoTestbench_isim_beh.exe.sim/unisims_ver/m_04410476663342107850_4040231565.didat");
	xsi_register_executes(pe);
}
