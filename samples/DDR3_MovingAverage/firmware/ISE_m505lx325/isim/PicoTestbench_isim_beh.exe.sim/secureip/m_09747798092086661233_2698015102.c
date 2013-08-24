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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/phaser_out/SIP_PHASER_OUT.v";
static int ng1[] = {50, 0, 0, 0};
static int ng2[] = {2, 0};
static int ng3[] = {250, 0, 0, 0};
static int ng4[] = {0, 0};
static int ng5[] = {0, 0, 0, 0};



static void Always_5402_0(char *t0)
{
    char t4[16];
    char t10[16];
    char t17[8];
    char t18[8];
    char t21[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t19;
    char *t20;
    char *t22;

LAB0:    t1 = (t0 + 3640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5402, ng0);
    t2 = (t0 + 4952);
    *((int *)t2) = 1;
    t3 = (t0 + 3672);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(5402, ng0);

LAB5:    xsi_set_current_line(5403, ng0);
    t5 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    t6 = (t0 + 2568);
    xsi_vlogvar_assign_value(t6, t4, 0, 0, 64);
    xsi_set_current_line(5404, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 2408);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    xsi_vlog_unsigned_minus(t4, 64, t5, 64, t8, 64);
    t9 = ((char*)((ng1)));
    xsi_vlog_unsigned_less(t10, 64, t4, 64, t9, 32);
    t11 = (t10 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t10);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(5404, ng0);

LAB9:    xsi_set_current_line(5405, ng0);
    *((int *)t18) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t19 = (t18 + 4);
    *((int *)t19) = 0;
    xsi_vlogtype_concat(t17, 32, 32, 1U, t18, 32);
    t20 = ((char*)((ng2)));
    memset(t21, 0, 8);
    xsi_vlog_unsigned_mod(t21, 32, t17, 32, t20, 32);
    t22 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t22, t21, 0, 0, 1, 100000LL);
    goto LAB8;

}

static void Always_5409_1(char *t0)
{
    char t4[16];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;

LAB0:    t1 = (t0 + 3888U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5409, ng0);
    t2 = (t0 + 4968);
    *((int *)t2) = 1;
    t3 = (t0 + 3920);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(5409, ng0);
    t5 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    t6 = (t0 + 2728);
    xsi_vlogvar_assign_value(t6, t4, 0, 0, 64);
    goto LAB2;

}

static void Always_5411_2(char *t0)
{
    char t4[16];
    char t10[16];
    char t11[8];
    char t27[8];
    char t43[8];
    char t51[8];
    char t89[8];
    char t90[8];
    char t93[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    int t75;
    int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t91;
    char *t92;
    char *t94;

LAB0:    t1 = (t0 + 4136U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5411, ng0);
    t2 = (t0 + 4984);
    *((int *)t2) = 1;
    t3 = (t0 + 4168);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(5411, ng0);

LAB5:    xsi_set_current_line(5412, ng0);
    t5 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    t6 = (t0 + 2248);
    xsi_vlogvar_assign_value(t6, t4, 0, 0, 64);
    xsi_set_current_line(5413, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 2408);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    xsi_vlog_unsigned_minus(t4, 64, t5, 64, t8, 64);
    t9 = ((char*)((ng3)));
    xsi_vlog_unsigned_less(t10, 64, t4, 64, t9, 32);
    memset(t11, 0, 8);
    t12 = (t10 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t12) != 0)
        goto LAB8;

LAB9:    t19 = (t11 + 4);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t19);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    memcpy(t51, t11, 8);

LAB12:    t83 = (t51 + 4);
    t84 = *((unsigned int *)t83);
    t85 = (~(t84));
    t86 = *((unsigned int *)t51);
    t87 = (t86 & t85);
    t88 = (t87 != 0);
    if (t88 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t11) = 1;
    goto LAB9;

LAB8:    t18 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB9;

LAB10:    t23 = (t0 + 1048U);
    t24 = *((char **)t23);
    t23 = (t0 + 2088);
    t25 = (t23 + 56U);
    t26 = *((char **)t25);
    memset(t27, 0, 8);
    t28 = (t24 + 4);
    t29 = (t26 + 4);
    t30 = *((unsigned int *)t24);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t33 = *((unsigned int *)t28);
    t34 = *((unsigned int *)t29);
    t35 = (t33 ^ t34);
    t36 = (t32 | t35);
    t37 = *((unsigned int *)t28);
    t38 = *((unsigned int *)t29);
    t39 = (t37 | t38);
    t40 = (~(t39));
    t41 = (t36 & t40);
    if (t41 != 0)
        goto LAB14;

LAB13:    if (t39 != 0)
        goto LAB15;

LAB16:    memset(t43, 0, 8);
    t44 = (t27 + 4);
    t45 = *((unsigned int *)t44);
    t46 = (~(t45));
    t47 = *((unsigned int *)t27);
    t48 = (t47 & t46);
    t49 = (t48 & 1U);
    if (t49 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t44) != 0)
        goto LAB19;

LAB20:    t52 = *((unsigned int *)t11);
    t53 = *((unsigned int *)t43);
    t54 = (t52 & t53);
    *((unsigned int *)t51) = t54;
    t55 = (t11 + 4);
    t56 = (t43 + 4);
    t57 = (t51 + 4);
    t58 = *((unsigned int *)t55);
    t59 = *((unsigned int *)t56);
    t60 = (t58 | t59);
    *((unsigned int *)t57) = t60;
    t61 = *((unsigned int *)t57);
    t62 = (t61 != 0);
    if (t62 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB12;

LAB14:    *((unsigned int *)t27) = 1;
    goto LAB16;

LAB15:    t42 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t42) = 1;
    goto LAB16;

LAB17:    *((unsigned int *)t43) = 1;
    goto LAB20;

LAB19:    t50 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB20;

LAB21:    t63 = *((unsigned int *)t51);
    t64 = *((unsigned int *)t57);
    *((unsigned int *)t51) = (t63 | t64);
    t65 = (t11 + 4);
    t66 = (t43 + 4);
    t67 = *((unsigned int *)t11);
    t68 = (~(t67));
    t69 = *((unsigned int *)t65);
    t70 = (~(t69));
    t71 = *((unsigned int *)t43);
    t72 = (~(t71));
    t73 = *((unsigned int *)t66);
    t74 = (~(t73));
    t75 = (t68 & t70);
    t76 = (t72 & t74);
    t77 = (~(t75));
    t78 = (~(t76));
    t79 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t79 & t77);
    t80 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t80 & t78);
    t81 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t81 & t77);
    t82 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t82 & t78);
    goto LAB23;

LAB24:    xsi_set_current_line(5413, ng0);

LAB27:    xsi_set_current_line(5414, ng0);
    *((int *)t90) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t91 = (t90 + 4);
    *((int *)t91) = 0;
    xsi_vlogtype_concat(t89, 32, 32, 1U, t90, 32);
    t92 = ((char*)((ng2)));
    memset(t93, 0, 8);
    xsi_vlog_unsigned_mod(t93, 32, t89, 32, t92, 32);
    t94 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t94, t93, 0, 0, 1, 100000LL);
    goto LAB26;

}

static void Always_5418_3(char *t0)
{
    char t4[16];
    char t10[16];
    char t11[8];
    char t27[8];
    char t43[8];
    char t51[8];
    char t89[8];
    char t90[8];
    char t93[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    int t75;
    int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t91;
    char *t92;
    char *t94;

LAB0:    t1 = (t0 + 4384U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5418, ng0);
    t2 = (t0 + 5000);
    *((int *)t2) = 1;
    t3 = (t0 + 4416);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(5418, ng0);

LAB5:    xsi_set_current_line(5419, ng0);
    t5 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    t6 = (t0 + 2408);
    xsi_vlogvar_assign_value(t6, t4, 0, 0, 64);
    xsi_set_current_line(5420, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 2248);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    xsi_vlog_unsigned_minus(t4, 64, t5, 64, t8, 64);
    t9 = ((char*)((ng3)));
    xsi_vlog_unsigned_less(t10, 64, t4, 64, t9, 32);
    memset(t11, 0, 8);
    t12 = (t10 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t12) != 0)
        goto LAB8;

LAB9:    t19 = (t11 + 4);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t19);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    memcpy(t51, t11, 8);

LAB12:    t83 = (t51 + 4);
    t84 = *((unsigned int *)t83);
    t85 = (~(t84));
    t86 = *((unsigned int *)t51);
    t87 = (t86 & t85);
    t88 = (t87 != 0);
    if (t88 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(5422, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 2568);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    xsi_vlog_unsigned_minus(t4, 64, t5, 64, t8, 64);
    t9 = ((char*)((ng1)));
    xsi_vlog_unsigned_less(t10, 64, t4, 64, t9, 32);
    t12 = (t10 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(5424, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 2728);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    xsi_vlog_unsigned_minus(t4, 64, t5, 64, t8, 64);
    t9 = ((char*)((ng1)));
    xsi_vlog_unsigned_less(t10, 64, t4, 64, t9, 32);
    t12 = (t10 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB32;

LAB33:    xsi_set_current_line(5426, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t13 = *((unsigned int *)t2);
    t14 = (~(t13));
    t15 = *((unsigned int *)t3);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB36;

LAB37:    xsi_set_current_line(5427, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 50000LL);

LAB38:
LAB34:
LAB30:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t11) = 1;
    goto LAB9;

LAB8:    t18 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB9;

LAB10:    t23 = (t0 + 1048U);
    t24 = *((char **)t23);
    t23 = (t0 + 2088);
    t25 = (t23 + 56U);
    t26 = *((char **)t25);
    memset(t27, 0, 8);
    t28 = (t24 + 4);
    t29 = (t26 + 4);
    t30 = *((unsigned int *)t24);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t33 = *((unsigned int *)t28);
    t34 = *((unsigned int *)t29);
    t35 = (t33 ^ t34);
    t36 = (t32 | t35);
    t37 = *((unsigned int *)t28);
    t38 = *((unsigned int *)t29);
    t39 = (t37 | t38);
    t40 = (~(t39));
    t41 = (t36 & t40);
    if (t41 != 0)
        goto LAB14;

LAB13:    if (t39 != 0)
        goto LAB15;

LAB16:    memset(t43, 0, 8);
    t44 = (t27 + 4);
    t45 = *((unsigned int *)t44);
    t46 = (~(t45));
    t47 = *((unsigned int *)t27);
    t48 = (t47 & t46);
    t49 = (t48 & 1U);
    if (t49 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t44) != 0)
        goto LAB19;

LAB20:    t52 = *((unsigned int *)t11);
    t53 = *((unsigned int *)t43);
    t54 = (t52 & t53);
    *((unsigned int *)t51) = t54;
    t55 = (t11 + 4);
    t56 = (t43 + 4);
    t57 = (t51 + 4);
    t58 = *((unsigned int *)t55);
    t59 = *((unsigned int *)t56);
    t60 = (t58 | t59);
    *((unsigned int *)t57) = t60;
    t61 = *((unsigned int *)t57);
    t62 = (t61 != 0);
    if (t62 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB12;

LAB14:    *((unsigned int *)t27) = 1;
    goto LAB16;

LAB15:    t42 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t42) = 1;
    goto LAB16;

LAB17:    *((unsigned int *)t43) = 1;
    goto LAB20;

LAB19:    t50 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB20;

LAB21:    t63 = *((unsigned int *)t51);
    t64 = *((unsigned int *)t57);
    *((unsigned int *)t51) = (t63 | t64);
    t65 = (t11 + 4);
    t66 = (t43 + 4);
    t67 = *((unsigned int *)t11);
    t68 = (~(t67));
    t69 = *((unsigned int *)t65);
    t70 = (~(t69));
    t71 = *((unsigned int *)t43);
    t72 = (~(t71));
    t73 = *((unsigned int *)t66);
    t74 = (~(t73));
    t75 = (t68 & t70);
    t76 = (t72 & t74);
    t77 = (~(t75));
    t78 = (~(t76));
    t79 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t79 & t77);
    t80 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t80 & t78);
    t81 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t81 & t77);
    t82 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t82 & t78);
    goto LAB23;

LAB24:    xsi_set_current_line(5420, ng0);

LAB27:    xsi_set_current_line(5421, ng0);
    *((int *)t90) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t91 = (t90 + 4);
    *((int *)t91) = 0;
    xsi_vlogtype_concat(t89, 32, 32, 1U, t90, 32);
    t92 = ((char*)((ng2)));
    memset(t93, 0, 8);
    xsi_vlog_unsigned_mod(t93, 32, t89, 32, t92, 32);
    t94 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t94, t93, 0, 0, 1, 100000LL);
    goto LAB26;

LAB28:    xsi_set_current_line(5422, ng0);

LAB31:    xsi_set_current_line(5423, ng0);
    *((int *)t27) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t18 = (t27 + 4);
    *((int *)t18) = 0;
    xsi_vlogtype_concat(t11, 32, 32, 1U, t27, 32);
    t19 = ((char*)((ng2)));
    memset(t43, 0, 8);
    xsi_vlog_unsigned_mod(t43, 32, t11, 32, t19, 32);
    t23 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t23, t43, 0, 0, 1, 100000LL);
    goto LAB30;

LAB32:    xsi_set_current_line(5424, ng0);

LAB35:    xsi_set_current_line(5425, ng0);
    *((int *)t27) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t18 = (t27 + 4);
    *((int *)t18) = 0;
    xsi_vlogtype_concat(t11, 32, 32, 1U, t27, 32);
    t19 = ((char*)((ng2)));
    memset(t43, 0, 8);
    xsi_vlog_unsigned_mod(t43, 32, t11, 32, t19, 32);
    t23 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t23, t43, 0, 0, 1, 100000LL);
    goto LAB34;

LAB36:    xsi_set_current_line(5426, ng0);
    t5 = ((char*)((ng4)));
    t6 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 50000LL);
    goto LAB38;

}

static void Initial_5431_4(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(5431, ng0);

LAB2:    xsi_set_current_line(5432, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 2248);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 64);
    xsi_set_current_line(5433, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 2408);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 64);
    xsi_set_current_line(5434, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 2568);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 64);
    xsi_set_current_line(5435, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 2728);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 64);

LAB1:    return;
}


extern void secureip_m_09747798092086661233_2698015102_init()
{
	static char *pe[] = {(void *)Always_5402_0,(void *)Always_5409_1,(void *)Always_5411_2,(void *)Always_5418_3,(void *)Initial_5431_4};
	xsi_register_didat("secureip_m_09747798092086661233_2698015102", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_09747798092086661233_2698015102.didat");
	xsi_register_executes(pe);
}
