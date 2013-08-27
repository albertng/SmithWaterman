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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/sim_tb_top.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {0, 0};
static int ng4[] = {5195334, 0};
static int ng5[] = {20302, 0};
static int ng6[] = {1, 0};



static void Initial_180_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;

LAB0:    t1 = (t0 + 21008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(180, ng0);

LAB4:    xsi_set_current_line(181, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 18336);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(182, ng0);
    t2 = (t0 + 20816);
    xsi_process_wait(t2, 200000000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(183, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 18336);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    goto LAB1;

}

static void Always_188_1(char *t0)
{
    char t6[8];
    char t7[8];
    char t24[8];
    char t41[8];
    char t42[8];
    char t51[8];
    char t61[8];
    char t71[8];
    char t81[8];
    char t91[8];
    char t101[8];
    char t109[8];
    char t125[8];
    char t126[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    int t15;
    char *t16;
    unsigned int t17;
    int t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    int t22;
    int t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
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
    unsigned int t39;
    unsigned int t40;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    char *t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    char *t80;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    char *t100;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    char *t110;
    char *t111;
    char *t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    char *t123;
    char *t124;
    char *t127;
    char *t128;
    char *t129;
    char *t130;
    char *t131;
    char *t132;
    char *t133;
    char *t134;
    unsigned int t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;

LAB0:    t1 = (t0 + 21256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(188, ng0);
    t2 = (t0 + 23064);
    *((int *)t2) = 1;
    t3 = (t0 + 21288);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(188, ng0);

LAB5:    xsi_set_current_line(189, ng0);
    t4 = (t0 + 4176U);
    t5 = *((char **)t4);
    t4 = (t0 + 19456);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 2, 0LL);
    xsi_set_current_line(190, ng0);
    t2 = (t0 + 4336U);
    t3 = *((char **)t2);
    t2 = (t0 + 19616);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 2, 0LL);
    xsi_set_current_line(191, ng0);
    t2 = (t0 + 4496U);
    t3 = *((char **)t2);
    t2 = (t0 + 18496);
    t4 = (t0 + 18496);
    t5 = (t4 + 72U);
    t8 = *((char **)t5);
    t9 = (t0 + 18496);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng3)));
    xsi_vlog_generic_convert_array_indices(t6, t7, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t6 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t7 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB6;

LAB7:    xsi_set_current_line(192, ng0);
    t2 = ((char*)((ng4)));
    t3 = ((char*)((ng5)));
    memset(t24, 0, 8);
    t4 = (t2 + 4);
    t5 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = *((unsigned int *)t3);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t4);
    t25 = *((unsigned int *)t5);
    t26 = (t21 ^ t25);
    t27 = (t20 | t26);
    t28 = *((unsigned int *)t4);
    t29 = *((unsigned int *)t5);
    t30 = (t28 | t29);
    t31 = (~(t30));
    t32 = (t27 & t31);
    if (t32 != 0)
        goto LAB11;

LAB8:    if (t30 != 0)
        goto LAB10;

LAB9:    *((unsigned int *)t24) = 1;

LAB11:    memset(t7, 0, 8);
    t9 = (t24 + 4);
    t33 = *((unsigned int *)t9);
    t34 = (~(t33));
    t35 = *((unsigned int *)t24);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t9) != 0)
        goto LAB14;

LAB15:    t11 = (t7 + 4);
    t38 = *((unsigned int *)t7);
    t39 = *((unsigned int *)t11);
    t40 = (t38 || t39);
    if (t40 > 0)
        goto LAB16;

LAB17:    t119 = *((unsigned int *)t7);
    t120 = (~(t119));
    t121 = *((unsigned int *)t11);
    t122 = (t120 || t121);
    if (t122 > 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t11) > 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t7) > 0)
        goto LAB22;

LAB23:    memcpy(t6, t124, 8);

LAB24:    t123 = (t0 + 18496);
    t127 = (t0 + 18496);
    t128 = (t127 + 72U);
    t129 = *((char **)t128);
    t130 = (t0 + 18496);
    t131 = (t130 + 64U);
    t132 = *((char **)t131);
    t133 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t125, t126, t129, t132, 2, 1, t133, 32, 1);
    t134 = (t125 + 4);
    t135 = *((unsigned int *)t134);
    t15 = (!(t135));
    t136 = (t126 + 4);
    t137 = *((unsigned int *)t136);
    t18 = (!(t137));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB25;

LAB26:    xsi_set_current_line(199, ng0);
    t2 = (t0 + 4656U);
    t3 = *((char **)t2);
    t2 = (t0 + 18656);
    t4 = (t0 + 18656);
    t5 = (t4 + 72U);
    t8 = *((char **)t5);
    t9 = (t0 + 18656);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng3)));
    xsi_vlog_generic_convert_array_indices(t6, t7, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t6 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (!(t14));
    t16 = (t7 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (!(t17));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB27;

LAB28:    xsi_set_current_line(200, ng0);
    t2 = ((char*)((ng4)));
    t3 = ((char*)((ng5)));
    memset(t24, 0, 8);
    t4 = (t2 + 4);
    t5 = (t3 + 4);
    t14 = *((unsigned int *)t2);
    t17 = *((unsigned int *)t3);
    t20 = (t14 ^ t17);
    t21 = *((unsigned int *)t4);
    t25 = *((unsigned int *)t5);
    t26 = (t21 ^ t25);
    t27 = (t20 | t26);
    t28 = *((unsigned int *)t4);
    t29 = *((unsigned int *)t5);
    t30 = (t28 | t29);
    t31 = (~(t30));
    t32 = (t27 & t31);
    if (t32 != 0)
        goto LAB32;

LAB29:    if (t30 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t24) = 1;

LAB32:    memset(t7, 0, 8);
    t9 = (t24 + 4);
    t33 = *((unsigned int *)t9);
    t34 = (~(t33));
    t35 = *((unsigned int *)t24);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t9) != 0)
        goto LAB35;

LAB36:    t11 = (t7 + 4);
    t38 = *((unsigned int *)t7);
    t39 = *((unsigned int *)t11);
    t40 = (t38 || t39);
    if (t40 > 0)
        goto LAB37;

LAB38:    t73 = *((unsigned int *)t7);
    t74 = (~(t73));
    t75 = *((unsigned int *)t11);
    t76 = (t74 || t75);
    if (t76 > 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t11) > 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t7) > 0)
        goto LAB43;

LAB44:    memcpy(t6, t70, 8);

LAB45:    t69 = (t0 + 18656);
    t72 = (t0 + 18656);
    t79 = (t72 + 72U);
    t80 = *((char **)t79);
    t82 = (t0 + 18656);
    t89 = (t82 + 64U);
    t90 = *((char **)t89);
    t92 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t71, t81, t80, t90, 2, 1, t92, 32, 1);
    t99 = (t71 + 4);
    t77 = *((unsigned int *)t99);
    t15 = (!(t77));
    t100 = (t81 + 4);
    t78 = *((unsigned int *)t100);
    t18 = (!(t78));
    t19 = (t15 && t18);
    if (t19 == 1)
        goto LAB46;

LAB47:    xsi_set_current_line(205, ng0);
    t2 = (t0 + 4816U);
    t3 = *((char **)t2);
    t2 = (t0 + 18816);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(206, ng0);
    t2 = (t0 + 4976U);
    t3 = *((char **)t2);
    t2 = (t0 + 18976);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(207, ng0);
    t2 = (t0 + 5136U);
    t3 = *((char **)t2);
    t2 = (t0 + 19136);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(208, ng0);
    t2 = (t0 + 5456U);
    t3 = *((char **)t2);
    t2 = (t0 + 19296);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 2, 0LL);
    goto LAB2;

LAB6:    t20 = *((unsigned int *)t6);
    t21 = *((unsigned int *)t7);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, *((unsigned int *)t7), t23, 0LL);
    goto LAB7;

LAB10:    t8 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB11;

LAB12:    *((unsigned int *)t7) = 1;
    goto LAB15;

LAB14:    t10 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB15;

LAB16:    t12 = (t0 + 4496U);
    t13 = *((char **)t12);
    memset(t42, 0, 8);
    t12 = (t42 + 4);
    t16 = (t13 + 4);
    t43 = *((unsigned int *)t13);
    t44 = (t43 >> 0);
    *((unsigned int *)t42) = t44;
    t45 = *((unsigned int *)t16);
    t46 = (t45 >> 0);
    *((unsigned int *)t12) = t46;
    t47 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t47 & 7U);
    t48 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t48 & 7U);
    t49 = (t0 + 4496U);
    t50 = *((char **)t49);
    memset(t51, 0, 8);
    t49 = (t51 + 4);
    t52 = (t50 + 4);
    t53 = *((unsigned int *)t50);
    t54 = (t53 >> 4);
    t55 = (t54 & 1);
    *((unsigned int *)t51) = t55;
    t56 = *((unsigned int *)t52);
    t57 = (t56 >> 4);
    t58 = (t57 & 1);
    *((unsigned int *)t49) = t58;
    t59 = (t0 + 4496U);
    t60 = *((char **)t59);
    memset(t61, 0, 8);
    t59 = (t61 + 4);
    t62 = (t60 + 4);
    t63 = *((unsigned int *)t60);
    t64 = (t63 >> 3);
    t65 = (t64 & 1);
    *((unsigned int *)t61) = t65;
    t66 = *((unsigned int *)t62);
    t67 = (t66 >> 3);
    t68 = (t67 & 1);
    *((unsigned int *)t59) = t68;
    t69 = (t0 + 4496U);
    t70 = *((char **)t69);
    memset(t71, 0, 8);
    t69 = (t71 + 4);
    t72 = (t70 + 4);
    t73 = *((unsigned int *)t70);
    t74 = (t73 >> 6);
    t75 = (t74 & 1);
    *((unsigned int *)t71) = t75;
    t76 = *((unsigned int *)t72);
    t77 = (t76 >> 6);
    t78 = (t77 & 1);
    *((unsigned int *)t69) = t78;
    t79 = (t0 + 4496U);
    t80 = *((char **)t79);
    memset(t81, 0, 8);
    t79 = (t81 + 4);
    t82 = (t80 + 4);
    t83 = *((unsigned int *)t80);
    t84 = (t83 >> 5);
    t85 = (t84 & 1);
    *((unsigned int *)t81) = t85;
    t86 = *((unsigned int *)t82);
    t87 = (t86 >> 5);
    t88 = (t87 & 1);
    *((unsigned int *)t79) = t88;
    t89 = (t0 + 4496U);
    t90 = *((char **)t89);
    memset(t91, 0, 8);
    t89 = (t91 + 4);
    t92 = (t90 + 4);
    t93 = *((unsigned int *)t90);
    t94 = (t93 >> 8);
    t95 = (t94 & 1);
    *((unsigned int *)t91) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 >> 8);
    t98 = (t97 & 1);
    *((unsigned int *)t89) = t98;
    t99 = (t0 + 4496U);
    t100 = *((char **)t99);
    memset(t101, 0, 8);
    t99 = (t101 + 4);
    t102 = (t100 + 4);
    t103 = *((unsigned int *)t100);
    t104 = (t103 >> 7);
    t105 = (t104 & 1);
    *((unsigned int *)t101) = t105;
    t106 = *((unsigned int *)t102);
    t107 = (t106 >> 7);
    t108 = (t107 & 1);
    *((unsigned int *)t99) = t108;
    t110 = (t0 + 4496U);
    t111 = *((char **)t110);
    memset(t109, 0, 8);
    t110 = (t109 + 4);
    t112 = (t111 + 4);
    t113 = *((unsigned int *)t111);
    t114 = (t113 >> 9);
    *((unsigned int *)t109) = t114;
    t115 = *((unsigned int *)t112);
    t116 = (t115 >> 9);
    *((unsigned int *)t110) = t116;
    t117 = *((unsigned int *)t109);
    *((unsigned int *)t109) = (t117 & 127U);
    t118 = *((unsigned int *)t110);
    *((unsigned int *)t110) = (t118 & 127U);
    xsi_vlogtype_concat(t41, 16, 16, 8U, t109, 7, t101, 1, t91, 1, t81, 1, t71, 1, t61, 1, t51, 1, t42, 3);
    goto LAB17;

LAB18:    t123 = (t0 + 4496U);
    t124 = *((char **)t123);
    goto LAB19;

LAB20:    xsi_vlog_unsigned_bit_combine(t6, 16, t41, 16, t124, 16);
    goto LAB24;

LAB22:    memcpy(t6, t41, 8);
    goto LAB24;

LAB25:    t138 = *((unsigned int *)t125);
    t139 = *((unsigned int *)t126);
    t22 = (t138 - t139);
    t23 = (t22 + 1);
    xsi_vlogvar_wait_assign_value(t123, t6, 0, *((unsigned int *)t126), t23, 0LL);
    goto LAB26;

LAB27:    t20 = *((unsigned int *)t6);
    t21 = *((unsigned int *)t7);
    t22 = (t20 - t21);
    t23 = (t22 + 1);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, *((unsigned int *)t7), t23, 0LL);
    goto LAB28;

LAB31:    t8 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB32;

LAB33:    *((unsigned int *)t7) = 1;
    goto LAB36;

LAB35:    t10 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB36;

LAB37:    t12 = (t0 + 4656U);
    t13 = *((char **)t12);
    memset(t42, 0, 8);
    t12 = (t42 + 4);
    t16 = (t13 + 4);
    t43 = *((unsigned int *)t13);
    t44 = (t43 >> 1);
    t45 = (t44 & 1);
    *((unsigned int *)t42) = t45;
    t46 = *((unsigned int *)t16);
    t47 = (t46 >> 1);
    t48 = (t47 & 1);
    *((unsigned int *)t12) = t48;
    t49 = (t0 + 4656U);
    t50 = *((char **)t49);
    memset(t51, 0, 8);
    t49 = (t51 + 4);
    t52 = (t50 + 4);
    t53 = *((unsigned int *)t50);
    t54 = (t53 >> 0);
    t55 = (t54 & 1);
    *((unsigned int *)t51) = t55;
    t56 = *((unsigned int *)t52);
    t57 = (t56 >> 0);
    t58 = (t57 & 1);
    *((unsigned int *)t49) = t58;
    t59 = (t0 + 4656U);
    t60 = *((char **)t59);
    memset(t61, 0, 8);
    t59 = (t61 + 4);
    t62 = (t60 + 4);
    t63 = *((unsigned int *)t60);
    t64 = (t63 >> 2);
    *((unsigned int *)t61) = t64;
    t65 = *((unsigned int *)t62);
    t66 = (t65 >> 2);
    *((unsigned int *)t59) = t66;
    t67 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t67 & 1U);
    t68 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t68 & 1U);
    xsi_vlogtype_concat(t41, 3, 3, 3U, t61, 1, t51, 1, t42, 1);
    goto LAB38;

LAB39:    t69 = (t0 + 4656U);
    t70 = *((char **)t69);
    goto LAB40;

LAB41:    xsi_vlog_unsigned_bit_combine(t6, 3, t41, 3, t70, 3);
    goto LAB45;

LAB43:    memcpy(t6, t41, 8);
    goto LAB45;

LAB46:    t83 = *((unsigned int *)t71);
    t84 = *((unsigned int *)t81);
    t22 = (t83 - t84);
    t23 = (t22 + 1);
    xsi_vlogvar_wait_assign_value(t69, t6, 0, *((unsigned int *)t81), t23, 0LL);
    goto LAB47;

}

static void Always_212_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 21504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(212, ng0);
    t2 = (t0 + 23080);
    *((int *)t2) = 1;
    t3 = (t0 + 21536);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(213, ng0);
    t4 = (t0 + 5296U);
    t5 = *((char **)t4);
    t4 = (t0 + 19776);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 2, 0LL);
    goto LAB2;

}

static void Cont_214_3(char *t0)
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

LAB0:    t1 = (t0 + 21752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(214, ng0);
    t2 = (t0 + 19776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 23240);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 3U;
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
    xsi_driver_vfirst_trans(t5, 0, 1);
    t18 = (t0 + 23096);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_217_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 22000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(217, ng0);
    t2 = (t0 + 23112);
    *((int *)t2) = 1;
    t3 = (t0 + 22032);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(218, ng0);
    t4 = (t0 + 5936U);
    t5 = *((char **)t4);
    t4 = (t0 + 19936);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 8, 0LL);
    goto LAB2;

}

static void Cont_219_5(char *t0)
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

LAB0:    t1 = (t0 + 22248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(219, ng0);
    t2 = (t0 + 19936);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 23304);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
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
    xsi_driver_vfirst_trans(t5, 0, 7);
    t18 = (t0 + 23128);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_222_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 22496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(222, ng0);
    t2 = (t0 + 23144);
    *((int *)t2) = 1;
    t3 = (t0 + 22528);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(223, ng0);
    t4 = (t0 + 5616U);
    t5 = *((char **)t4);
    t4 = (t0 + 20096);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 2, 0LL);
    goto LAB2;

}

static void Cont_224_7(char *t0)
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

LAB0:    t1 = (t0 + 22744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(224, ng0);
    t2 = (t0 + 20096);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 23368);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 3U;
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
    xsi_driver_vfirst_trans(t5, 0, 1);
    t18 = (t0 + 23160);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_00308877706566726766_1339248823_init()
{
	static char *pe[] = {(void *)Initial_180_0,(void *)Always_188_1,(void *)Always_212_2,(void *)Cont_214_3,(void *)Always_217_4,(void *)Cont_219_5,(void *)Always_222_6,(void *)Cont_224_7};
	xsi_register_didat("work_m_00308877706566726766_1339248823", "isim/PicoTestbench_isim_beh.exe.sim/work/m_00308877706566726766_1339248823.didat");
	xsi_register_executes(pe);
}
