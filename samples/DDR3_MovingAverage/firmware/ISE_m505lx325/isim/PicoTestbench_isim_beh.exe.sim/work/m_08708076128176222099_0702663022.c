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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/samples/DDR3_MovingAverage/firmware/ISE_m505lx325/source/UserWrapper.v";
static int ng1[] = {1, 0};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {0U, 0U};
static int ng4[] = {124, 0};
static unsigned int ng5[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};



static int sp_clogb2(char *t1, char *t2)
{
    char t7[8];
    char t21[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
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
    char *t20;
    char *t22;

LAB0:    t0 = 1;
    xsi_set_current_line(511, ng0);

LAB2:    xsi_set_current_line(512, ng0);
    t3 = (t1 + 21096);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_minus(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 21096);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    xsi_set_current_line(513, ng0);
    xsi_set_current_line(513, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t1 + 20936);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);

LAB3:    t3 = (t1 + 21096);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng2)));
    memset(t7, 0, 8);
    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB5;

LAB4:    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB5;

LAB8:    if (*((unsigned int *)t5) > *((unsigned int *)t6))
        goto LAB6;

LAB7:    t11 = (t7 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t7);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB9;

LAB10:    t0 = 0;

LAB1:    return t0;
LAB5:    t10 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB7;

LAB6:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB9:    xsi_set_current_line(513, ng0);

LAB11:    xsi_set_current_line(514, ng0);
    t17 = (t1 + 21096);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = ((char*)((ng1)));
    memset(t21, 0, 8);
    xsi_vlog_unsigned_rshift(t21, 32, t19, 32, t20, 32);
    t22 = (t1 + 21096);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 32);
    xsi_set_current_line(513, ng0);
    t3 = (t1 + 20936);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 20936);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB3;

}

static void Cont_4743_0(char *t0)
{
    char t5[8];
    char t12[8];
    char t42[8];
    char t49[8];
    char t79[8];
    char t86[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
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
    int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    char *t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    char *t115;
    char *t116;
    char *t117;
    char *t118;
    char *t119;

LAB0:    t1 = (t0 + 22008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(4743, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 18456U);
    t4 = *((char **)t3);
    t3 = (t0 + 18416U);
    t6 = (t3 + 72U);
    t7 = *((char **)t6);
    t8 = (t0 + 18416U);
    t9 = (t8 + 48U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t5, 32, t4, t7, t10, 2, 1, t11, 32, 1);
    t13 = *((unsigned int *)t2);
    t14 = *((unsigned int *)t5);
    t15 = (t13 | t14);
    *((unsigned int *)t12) = t15;
    t16 = (t2 + 4);
    t17 = (t5 + 4);
    t18 = (t12 + 4);
    t19 = *((unsigned int *)t16);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    *((unsigned int *)t18) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 != 0);
    if (t23 == 1)
        goto LAB4;

LAB5:
LAB6:    t40 = (t0 + 18456U);
    t41 = *((char **)t40);
    t40 = (t0 + 18416U);
    t43 = (t40 + 72U);
    t44 = *((char **)t43);
    t45 = (t0 + 18416U);
    t46 = (t45 + 48U);
    t47 = *((char **)t46);
    t48 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t42, 32, t41, t44, t47, 2, 1, t48, 32, 1);
    t50 = *((unsigned int *)t12);
    t51 = *((unsigned int *)t42);
    t52 = (t50 | t51);
    *((unsigned int *)t49) = t52;
    t53 = (t12 + 4);
    t54 = (t42 + 4);
    t55 = (t49 + 4);
    t56 = *((unsigned int *)t53);
    t57 = *((unsigned int *)t54);
    t58 = (t56 | t57);
    *((unsigned int *)t55) = t58;
    t59 = *((unsigned int *)t55);
    t60 = (t59 != 0);
    if (t60 == 1)
        goto LAB7;

LAB8:
LAB9:    t77 = (t0 + 19416U);
    t78 = *((char **)t77);
    t77 = (t0 + 19376U);
    t80 = (t77 + 72U);
    t81 = *((char **)t80);
    t82 = (t0 + 19376U);
    t83 = (t82 + 48U);
    t84 = *((char **)t83);
    t85 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t79, 32, t78, t81, t84, 2, 1, t85, 32, 1);
    t87 = *((unsigned int *)t49);
    t88 = *((unsigned int *)t79);
    t89 = (t87 | t88);
    *((unsigned int *)t86) = t89;
    t90 = (t49 + 4);
    t91 = (t79 + 4);
    t92 = (t86 + 4);
    t93 = *((unsigned int *)t90);
    t94 = *((unsigned int *)t91);
    t95 = (t93 | t94);
    *((unsigned int *)t92) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 != 0);
    if (t97 == 1)
        goto LAB10;

LAB11:
LAB12:    t114 = (t0 + 23464);
    t115 = (t114 + 56U);
    t116 = *((char **)t115);
    t117 = (t116 + 56U);
    t118 = *((char **)t117);
    memcpy(t118, t86, 8);
    xsi_driver_vfirst_trans(t114, 0, 31);
    t119 = (t0 + 23320);
    *((int *)t119) = 1;

LAB1:    return;
LAB4:    t24 = *((unsigned int *)t12);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t12) = (t24 | t25);
    t26 = (t2 + 4);
    t27 = (t5 + 4);
    t28 = *((unsigned int *)t26);
    t29 = (~(t28));
    t30 = *((unsigned int *)t2);
    t31 = (t30 & t29);
    t32 = *((unsigned int *)t27);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (~(t31));
    t37 = (~(t35));
    t38 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t38 & t36);
    t39 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t39 & t37);
    goto LAB6;

LAB7:    t61 = *((unsigned int *)t49);
    t62 = *((unsigned int *)t55);
    *((unsigned int *)t49) = (t61 | t62);
    t63 = (t12 + 4);
    t64 = (t42 + 4);
    t65 = *((unsigned int *)t63);
    t66 = (~(t65));
    t67 = *((unsigned int *)t12);
    t68 = (t67 & t66);
    t69 = *((unsigned int *)t64);
    t70 = (~(t69));
    t71 = *((unsigned int *)t42);
    t72 = (t71 & t70);
    t73 = (~(t68));
    t74 = (~(t72));
    t75 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t75 & t73);
    t76 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t76 & t74);
    goto LAB9;

LAB10:    t98 = *((unsigned int *)t86);
    t99 = *((unsigned int *)t92);
    *((unsigned int *)t86) = (t98 | t99);
    t100 = (t49 + 4);
    t101 = (t79 + 4);
    t102 = *((unsigned int *)t100);
    t103 = (~(t102));
    t104 = *((unsigned int *)t49);
    t105 = (t104 & t103);
    t106 = *((unsigned int *)t101);
    t107 = (~(t106));
    t108 = *((unsigned int *)t79);
    t109 = (t108 & t107);
    t110 = (~(t105));
    t111 = (~(t109));
    t112 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t112 & t110);
    t113 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t113 & t111);
    goto LAB12;

}

static void Cont_4998_1(char *t0)
{
    char t5[8];
    char t12[8];
    char t42[8];
    char t49[8];
    char t79[8];
    char t86[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
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
    int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    char *t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    char *t115;
    char *t116;
    char *t117;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    char *t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;

LAB0:    t1 = (t0 + 22256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(4998, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 18616U);
    t4 = *((char **)t3);
    t3 = (t0 + 18576U);
    t6 = (t3 + 72U);
    t7 = *((char **)t6);
    t8 = (t0 + 18576U);
    t9 = (t8 + 48U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t5, 1, t4, t7, t10, 2, 1, t11, 32, 1);
    t13 = *((unsigned int *)t2);
    t14 = *((unsigned int *)t5);
    t15 = (t13 | t14);
    *((unsigned int *)t12) = t15;
    t16 = (t2 + 4);
    t17 = (t5 + 4);
    t18 = (t12 + 4);
    t19 = *((unsigned int *)t16);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    *((unsigned int *)t18) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 != 0);
    if (t23 == 1)
        goto LAB4;

LAB5:
LAB6:    t40 = (t0 + 18616U);
    t41 = *((char **)t40);
    t40 = (t0 + 18576U);
    t43 = (t40 + 72U);
    t44 = *((char **)t43);
    t45 = (t0 + 18576U);
    t46 = (t45 + 48U);
    t47 = *((char **)t46);
    t48 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t42, 1, t41, t44, t47, 2, 1, t48, 32, 1);
    t50 = *((unsigned int *)t12);
    t51 = *((unsigned int *)t42);
    t52 = (t50 | t51);
    *((unsigned int *)t49) = t52;
    t53 = (t12 + 4);
    t54 = (t42 + 4);
    t55 = (t49 + 4);
    t56 = *((unsigned int *)t53);
    t57 = *((unsigned int *)t54);
    t58 = (t56 | t57);
    *((unsigned int *)t55) = t58;
    t59 = *((unsigned int *)t55);
    t60 = (t59 != 0);
    if (t60 == 1)
        goto LAB7;

LAB8:
LAB9:    t77 = (t0 + 19576U);
    t78 = *((char **)t77);
    t77 = (t0 + 19536U);
    t80 = (t77 + 72U);
    t81 = *((char **)t80);
    t82 = (t0 + 19536U);
    t83 = (t82 + 48U);
    t84 = *((char **)t83);
    t85 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t79, 1, t78, t81, t84, 2, 1, t85, 32, 1);
    t87 = *((unsigned int *)t49);
    t88 = *((unsigned int *)t79);
    t89 = (t87 | t88);
    *((unsigned int *)t86) = t89;
    t90 = (t49 + 4);
    t91 = (t79 + 4);
    t92 = (t86 + 4);
    t93 = *((unsigned int *)t90);
    t94 = *((unsigned int *)t91);
    t95 = (t93 | t94);
    *((unsigned int *)t92) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 != 0);
    if (t97 == 1)
        goto LAB10;

LAB11:
LAB12:    t114 = (t0 + 23528);
    t115 = (t114 + 56U);
    t116 = *((char **)t115);
    t117 = (t116 + 56U);
    t118 = *((char **)t117);
    memset(t118, 0, 8);
    t119 = 1U;
    t120 = t119;
    t121 = (t86 + 4);
    t122 = *((unsigned int *)t86);
    t119 = (t119 & t122);
    t123 = *((unsigned int *)t121);
    t120 = (t120 & t123);
    t124 = (t118 + 4);
    t125 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t125 | t119);
    t126 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t126 | t120);
    xsi_driver_vfirst_trans(t114, 0, 0);
    t127 = (t0 + 23336);
    *((int *)t127) = 1;

LAB1:    return;
LAB4:    t24 = *((unsigned int *)t12);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t12) = (t24 | t25);
    t26 = (t2 + 4);
    t27 = (t5 + 4);
    t28 = *((unsigned int *)t26);
    t29 = (~(t28));
    t30 = *((unsigned int *)t2);
    t31 = (t30 & t29);
    t32 = *((unsigned int *)t27);
    t33 = (~(t32));
    t34 = *((unsigned int *)t5);
    t35 = (t34 & t33);
    t36 = (~(t31));
    t37 = (~(t35));
    t38 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t38 & t36);
    t39 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t39 & t37);
    goto LAB6;

LAB7:    t61 = *((unsigned int *)t49);
    t62 = *((unsigned int *)t55);
    *((unsigned int *)t49) = (t61 | t62);
    t63 = (t12 + 4);
    t64 = (t42 + 4);
    t65 = *((unsigned int *)t63);
    t66 = (~(t65));
    t67 = *((unsigned int *)t12);
    t68 = (t67 & t66);
    t69 = *((unsigned int *)t64);
    t70 = (~(t69));
    t71 = *((unsigned int *)t42);
    t72 = (t71 & t70);
    t73 = (~(t68));
    t74 = (~(t72));
    t75 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t75 & t73);
    t76 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t76 & t74);
    goto LAB9;

LAB10:    t98 = *((unsigned int *)t86);
    t99 = *((unsigned int *)t92);
    *((unsigned int *)t86) = (t98 | t99);
    t100 = (t49 + 4);
    t101 = (t79 + 4);
    t102 = *((unsigned int *)t100);
    t103 = (~(t102));
    t104 = *((unsigned int *)t49);
    t105 = (t104 & t103);
    t106 = *((unsigned int *)t101);
    t107 = (~(t106));
    t108 = *((unsigned int *)t79);
    t109 = (t108 & t107);
    t110 = (~(t105));
    t111 = (~(t109));
    t112 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t112 & t110);
    t113 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t113 & t111);
    goto LAB12;

}

static void Cont_5253_2(char *t0)
{
    char t5[32];
    char t12[32];
    char t57[32];
    char t64[32];
    char t109[32];
    char t116[32];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    char *t39;
    char *t40;
    unsigned int t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    unsigned int t77;
    char *t78;
    unsigned int t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    unsigned int t90;
    char *t91;
    char *t92;
    unsigned int t93;
    char *t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    char *t107;
    char *t108;
    char *t110;
    char *t111;
    char *t112;
    char *t113;
    char *t114;
    char *t115;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    char *t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    char *t128;
    unsigned int t129;
    char *t130;
    unsigned int t131;
    char *t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    unsigned int t142;
    char *t143;
    char *t144;
    unsigned int t145;
    char *t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    char *t159;
    char *t160;
    char *t161;
    char *t162;
    char *t163;
    char *t164;

LAB0:    t1 = (t0 + 22504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5253, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 18776U);
    t4 = *((char **)t3);
    t3 = (t0 + 18736U);
    t6 = (t3 + 72U);
    t7 = *((char **)t6);
    t8 = (t0 + 18736U);
    t9 = (t8 + 48U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t5, 128, t4, t7, t10, 2, 1, t11, 32, 1);
    t13 = 0;

LAB7:    t14 = (t13 < 4);
    if (t14 == 1)
        goto LAB8;

LAB9:    t55 = (t0 + 18776U);
    t56 = *((char **)t55);
    t55 = (t0 + 18736U);
    t58 = (t55 + 72U);
    t59 = *((char **)t58);
    t60 = (t0 + 18736U);
    t61 = (t60 + 48U);
    t62 = *((char **)t61);
    t63 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t57, 128, t56, t59, t62, 2, 1, t63, 32, 1);
    t65 = 0;

LAB13:    t66 = (t65 < 4);
    if (t66 == 1)
        goto LAB14;

LAB15:    t107 = (t0 + 19736U);
    t108 = *((char **)t107);
    t107 = (t0 + 19696U);
    t110 = (t107 + 72U);
    t111 = *((char **)t110);
    t112 = (t0 + 19696U);
    t113 = (t112 + 48U);
    t114 = *((char **)t113);
    t115 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t109, 128, t108, t111, t114, 2, 1, t115, 32, 1);
    t117 = 0;

LAB19:    t118 = (t117 < 4);
    if (t118 == 1)
        goto LAB20;

LAB21:    t159 = (t0 + 23592);
    t160 = (t159 + 56U);
    t161 = *((char **)t160);
    t162 = (t161 + 56U);
    t163 = *((char **)t162);
    xsi_vlog_bit_copy(t163, 0, t116, 0, 128);
    xsi_driver_vfirst_trans(t159, 0, 127);
    t164 = (t0 + 23352);
    *((int *)t164) = 1;

LAB1:    return;
LAB4:    t34 = (t13 * 8);
    t35 = *((unsigned int *)t18);
    t36 = *((unsigned int *)t28);
    *((unsigned int *)t18) = (t35 | t36);
    t37 = (t2 + t34);
    t38 = (t34 + 4);
    t39 = (t2 + t38);
    t40 = (t5 + t34);
    t41 = (t34 + 4);
    t42 = (t5 + t41);
    t43 = *((unsigned int *)t39);
    t44 = (~(t43));
    t45 = *((unsigned int *)t37);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t40);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t53 & t51);
    t54 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t54 & t52);

LAB6:    t13 = (t13 + 1);
    goto LAB7;

LAB5:    goto LAB6;

LAB8:    t15 = (t13 * 8);
    t16 = (t2 + t15);
    t17 = (t5 + t15);
    t18 = (t12 + t15);
    t19 = *((unsigned int *)t16);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    *((unsigned int *)t18) = t21;
    t22 = (t13 * 8);
    t23 = (t22 + 4);
    t24 = (t2 + t23);
    t25 = (t22 + 4);
    t26 = (t5 + t25);
    t27 = (t22 + 4);
    t28 = (t12 + t27);
    t29 = *((unsigned int *)t24);
    t30 = *((unsigned int *)t26);
    t31 = (t29 | t30);
    *((unsigned int *)t28) = t31;
    t32 = *((unsigned int *)t28);
    t33 = (t32 != 0);
    if (t33 == 1)
        goto LAB4;
    else
        goto LAB5;

LAB10:    t86 = (t65 * 8);
    t87 = *((unsigned int *)t70);
    t88 = *((unsigned int *)t80);
    *((unsigned int *)t70) = (t87 | t88);
    t89 = (t12 + t86);
    t90 = (t86 + 4);
    t91 = (t12 + t90);
    t92 = (t57 + t86);
    t93 = (t86 + 4);
    t94 = (t57 + t93);
    t95 = *((unsigned int *)t91);
    t96 = (~(t95));
    t97 = *((unsigned int *)t89);
    t98 = (t97 & t96);
    t99 = *((unsigned int *)t94);
    t100 = (~(t99));
    t101 = *((unsigned int *)t92);
    t102 = (t101 & t100);
    t103 = (~(t98));
    t104 = (~(t102));
    t105 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t105 & t103);
    t106 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t106 & t104);

LAB12:    t65 = (t65 + 1);
    goto LAB13;

LAB11:    goto LAB12;

LAB14:    t67 = (t65 * 8);
    t68 = (t12 + t67);
    t69 = (t57 + t67);
    t70 = (t64 + t67);
    t71 = *((unsigned int *)t68);
    t72 = *((unsigned int *)t69);
    t73 = (t71 | t72);
    *((unsigned int *)t70) = t73;
    t74 = (t65 * 8);
    t75 = (t74 + 4);
    t76 = (t12 + t75);
    t77 = (t74 + 4);
    t78 = (t57 + t77);
    t79 = (t74 + 4);
    t80 = (t64 + t79);
    t81 = *((unsigned int *)t76);
    t82 = *((unsigned int *)t78);
    t83 = (t81 | t82);
    *((unsigned int *)t80) = t83;
    t84 = *((unsigned int *)t80);
    t85 = (t84 != 0);
    if (t85 == 1)
        goto LAB10;
    else
        goto LAB11;

LAB16:    t138 = (t117 * 8);
    t139 = *((unsigned int *)t122);
    t140 = *((unsigned int *)t132);
    *((unsigned int *)t122) = (t139 | t140);
    t141 = (t64 + t138);
    t142 = (t138 + 4);
    t143 = (t64 + t142);
    t144 = (t109 + t138);
    t145 = (t138 + 4);
    t146 = (t109 + t145);
    t147 = *((unsigned int *)t143);
    t148 = (~(t147));
    t149 = *((unsigned int *)t141);
    t150 = (t149 & t148);
    t151 = *((unsigned int *)t146);
    t152 = (~(t151));
    t153 = *((unsigned int *)t144);
    t154 = (t153 & t152);
    t155 = (~(t150));
    t156 = (~(t154));
    t157 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t157 & t155);
    t158 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t158 & t156);

LAB18:    t117 = (t117 + 1);
    goto LAB19;

LAB17:    goto LAB18;

LAB20:    t119 = (t117 * 8);
    t120 = (t64 + t119);
    t121 = (t109 + t119);
    t122 = (t116 + t119);
    t123 = *((unsigned int *)t120);
    t124 = *((unsigned int *)t121);
    t125 = (t123 | t124);
    *((unsigned int *)t122) = t125;
    t126 = (t117 * 8);
    t127 = (t126 + 4);
    t128 = (t64 + t127);
    t129 = (t126 + 4);
    t130 = (t109 + t129);
    t131 = (t126 + 4);
    t132 = (t116 + t131);
    t133 = *((unsigned int *)t128);
    t134 = *((unsigned int *)t130);
    t135 = (t133 | t134);
    *((unsigned int *)t132) = t135;
    t136 = *((unsigned int *)t132);
    t137 = (t136 != 0);
    if (t137 == 1)
        goto LAB16;
    else
        goto LAB17;

}

static void Cont_5508_3(char *t0)
{
    char t5[32];
    char t12[32];
    char t13[32];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
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
    char *t25;
    unsigned int t26;
    char *t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;

LAB0:    t1 = (t0 + 22752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5508, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 19896U);
    t4 = *((char **)t3);
    t3 = (t0 + 19856U);
    t6 = (t3 + 72U);
    t7 = *((char **)t6);
    t8 = (t0 + 19856U);
    t9 = (t8 + 48U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t5, 128, t4, t7, t10, 2, 1, t11, 32, 1);
    xsi_vlog_get_part_select_value(t12, 128, t5, 127, 0);
    t14 = 0;

LAB7:    t15 = (t14 < 4);
    if (t15 == 1)
        goto LAB8;

LAB9:    t56 = (t0 + 23656);
    t57 = (t56 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    xsi_vlog_bit_copy(t60, 0, t13, 0, 128);
    xsi_driver_vfirst_trans(t56, 0, 127);
    t61 = (t0 + 23368);
    *((int *)t61) = 1;

LAB1:    return;
LAB4:    t35 = (t14 * 8);
    t36 = *((unsigned int *)t19);
    t37 = *((unsigned int *)t29);
    *((unsigned int *)t19) = (t36 | t37);
    t38 = (t2 + t35);
    t39 = (t35 + 4);
    t40 = (t2 + t39);
    t41 = (t12 + t35);
    t42 = (t35 + 4);
    t43 = (t12 + t42);
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t38);
    t47 = (t46 & t45);
    t48 = *((unsigned int *)t43);
    t49 = (~(t48));
    t50 = *((unsigned int *)t41);
    t51 = (t50 & t49);
    t52 = (~(t47));
    t53 = (~(t51));
    t54 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t54 & t52);
    t55 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t55 & t53);

LAB6:    t14 = (t14 + 1);
    goto LAB7;

LAB5:    goto LAB6;

LAB8:    t16 = (t14 * 8);
    t17 = (t2 + t16);
    t18 = (t12 + t16);
    t19 = (t13 + t16);
    t20 = *((unsigned int *)t17);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    *((unsigned int *)t19) = t22;
    t23 = (t14 * 8);
    t24 = (t23 + 4);
    t25 = (t2 + t24);
    t26 = (t23 + 4);
    t27 = (t12 + t26);
    t28 = (t23 + 4);
    t29 = (t13 + t28);
    t30 = *((unsigned int *)t25);
    t31 = *((unsigned int *)t27);
    t32 = (t30 | t31);
    *((unsigned int *)t29) = t32;
    t33 = *((unsigned int *)t29);
    t34 = (t33 != 0);
    if (t34 == 1)
        goto LAB4;
    else
        goto LAB5;

}

static void implSig1_execute(char *t0)
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

LAB0:    t1 = (t0 + 23000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2776U);
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
    t21 = (t0 + 23720);
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
    xsi_driver_vfirst_trans(t21, 0, 0);
    t34 = (t0 + 23384);
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


extern void work_m_08708076128176222099_0702663022_init()
{
	static char *pe[] = {(void *)Cont_4743_0,(void *)Cont_4998_1,(void *)Cont_5253_2,(void *)Cont_5508_3,(void *)implSig1_execute};
	static char *se[] = {(void *)sp_clogb2};
	xsi_register_didat("work_m_08708076128176222099_0702663022", "isim/PicoTestbench_isim_beh.exe.sim/work/m_08708076128176222099_0702663022.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
