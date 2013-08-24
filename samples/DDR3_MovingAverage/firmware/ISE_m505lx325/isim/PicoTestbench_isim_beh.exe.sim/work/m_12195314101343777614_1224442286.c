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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/samples/DDR3_MovingAverage/firmware/ISE_m505lx325/source/PicoTestbench.v";
static int ng1[] = {0, 0};
static int ng2[] = {4096, 0};
static unsigned int ng3[] = {4294967295U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static int ng4[] = {16, 0};
static int ng5[] = {0, 0, 0, 0};
static unsigned int ng6[] = {0U, 0U, 4096U, 0U, 4096U, 0U, 0U, 0U};
static int ng7[] = {1, 0};
static int ng8[] = {2, 0};
static int ng9[] = {7, 0};
static int ng10[] = {8, 0};
static int ng11[] = {0, 0, 0, 0, 0, 0, 0, 0};
static int ng12[] = {4096, 0, 0, 0};
static const char *ng13 = "data[%d]: actual (%h) != expected (%h)\n";
static const char *ng14 = "All Tests Successful!";



static void Initial_19_0(char *t0)
{
    char t23[8];
    char t29[8];
    char t30[32];
    char t47[32];
    char t90[8];
    char t91[8];
    char t102[8];
    char t115[8];
    char t121[32];
    char t122[32];
    char t127[32];
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
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
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
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    unsigned int t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    unsigned int t69;
    char *t70;
    char *t71;
    unsigned int t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    char *t101;
    char *t103;
    unsigned int t104;
    int t105;
    char *t106;
    unsigned int t107;
    int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    int t112;
    int t113;
    char *t114;
    char *t116;
    char *t117;
    char *t118;
    char *t119;
    char *t120;
    char *t123;
    char *t124;
    char *t125;
    char *t126;
    char *t128;
    char *t129;
    char *t130;
    char *t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    char *t136;

LAB0:    t1 = (t0 + 2840U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(19, ng0);

LAB4:    xsi_set_current_line(22, ng0);
    t2 = (t0 + 2648);
    t3 = (t0 + 4936);
    t4 = *((char **)t3);
    t5 = (t0 + 4944);
    t6 = xsi_create_subprogram_invocation(t2, 0, *((char **)t5), ((char*)(t4)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t4)), t6);

LAB7:    t7 = (t0 + 2744);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = (t0 + 4944);
    t16 = ((int  (*)(char *, char *))t14)(*((char **)t15), t8);

LAB9:    if (t16 != 0)
        goto LAB10;

LAB5:    t8 = (t0 + 4976);
    t17 = *((char **)t8);
    xsi_vlog_subprogram_popinvocation(((char*)(t17)));

LAB6:    t18 = (t0 + 2744);
    t19 = *((char **)t18);
    t18 = (t0 + 4976);
    t20 = *((char **)t18);
    t21 = (t0 + 2648);
    t22 = 0;
    xsi_delete_subprogram_invocation(((char*)(t20)), t19, t0, t21, t22);
    xsi_set_current_line(25, ng0);
    xsi_set_current_line(25, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB11:    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t23, 0, 8);
    xsi_vlog_signed_less(t23, 32, t4, 32, t5, 32);
    t6 = (t23 + 4);
    t24 = *((unsigned int *)t6);
    t25 = (~(t24));
    t26 = *((unsigned int *)t23);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB12;

LAB13:    xsi_set_current_line(29, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng2)));
    t4 = ((char*)((ng1)));
    t5 = (t0 + 2648);
    t6 = (t0 + 5144);
    t7 = *((char **)t6);
    t8 = (t0 + 5176);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 5152);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 33);
    t12 = (t0 + 5160);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 32);
    t14 = (t0 + 5168);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 7);

LAB35:    t17 = (t0 + 2744);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t57 = (t22 + 0U);
    t59 = *((char **)t57);
    t68 = (t0 + 5176);
    t16 = ((int  (*)(char *, char *))t59)(*((char **)t68), t18);

LAB37:    if (t16 != 0)
        goto LAB38;

LAB33:    t18 = (t0 + 5208);
    t70 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t70)));

LAB34:    t71 = (t0 + 2744);
    t73 = *((char **)t71);
    t71 = (t0 + 5208);
    t89 = *((char **)t71);
    t92 = (t0 + 2648);
    t93 = 0;
    xsi_delete_subprogram_invocation(((char*)(t89)), t73, t0, t92, t93);
    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng1)));
    t3 = ((char*)((ng6)));
    t4 = (t0 + 2648);
    t5 = (t0 + 5280);
    t6 = *((char **)t5);
    t7 = (t0 + 5304);
    t8 = xsi_create_subprogram_invocation(t4, 0, *((char **)t7), ((char*)(t6)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t6)), t8);
    t9 = (t0 + 5288);
    t10 = *((char **)t9);
    xsi_vlogvar_assign_value(((char*)(t10)), t2, 0, 0, 12);
    t11 = (t0 + 5296);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t3, 0, 0, 128);

LAB41:    t13 = (t0 + 2744);
    t14 = *((char **)t13);
    t15 = (t14 + 80U);
    t17 = *((char **)t15);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = (t0 + 5304);
    t16 = ((int  (*)(char *, char *))t21)(*((char **)t22), t14);

LAB43:    if (t16 != 0)
        goto LAB44;

LAB39:    t14 = (t0 + 5344);
    t57 = *((char **)t14);
    xsi_vlog_subprogram_popinvocation(((char*)(t57)));

LAB40:    t59 = (t0 + 2744);
    t68 = *((char **)t59);
    t59 = (t0 + 5344);
    t70 = *((char **)t59);
    t71 = (t0 + 2648);
    t73 = 0;
    xsi_delete_subprogram_invocation(((char*)(t70)), t68, t0, t71, t73);
    xsi_set_current_line(33, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng4)));
    t5 = (t0 + 2648);
    t6 = (t0 + 5400);
    t7 = *((char **)t6);
    t8 = (t0 + 5432);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 5408);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 5416);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 5424);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB47:    t17 = (t0 + 2744);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t57 = (t22 + 0U);
    t59 = *((char **)t57);
    t68 = (t0 + 5432);
    t16 = ((int  (*)(char *, char *))t59)(*((char **)t68), t18);

LAB49:    if (t16 != 0)
        goto LAB50;

LAB45:    t18 = (t0 + 5464);
    t70 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t70)));

LAB46:    t71 = (t0 + 2744);
    t73 = *((char **)t71);
    t71 = (t0 + 5464);
    t89 = *((char **)t71);
    t92 = (t0 + 2648);
    t93 = 0;
    xsi_delete_subprogram_invocation(((char*)(t89)), t73, t0, t92, t93);
    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 34);
    xsi_set_current_line(37, ng0);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB51:    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    t6 = ((char*)((ng4)));
    memset(t23, 0, 8);
    xsi_vlog_signed_divide(t23, 32, t5, 32, t6, 32);
    memset(t29, 0, 8);
    xsi_vlog_signed_less(t29, 32, t4, 32, t23, 32);
    t7 = (t29 + 4);
    t24 = *((unsigned int *)t7);
    t25 = (~(t24));
    t26 = *((unsigned int *)t29);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB52;

LAB53:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2648);
    xsi_process_wait(t2, 5000000000LL);
    *((char **)t1) = &&LAB68;

LAB1:    return;
LAB8:;
LAB10:    t7 = (t0 + 2840U);
    *((char **)t7) = &&LAB7;
    goto LAB1;

LAB12:    xsi_set_current_line(25, ng0);

LAB14:    xsi_set_current_line(26, ng0);
    *((int *)t29) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t7 = (t29 + 4);
    *((int *)t7) = 0;
    memcpy(t30, t29, 8);
    t8 = (t30 + 8);
    memset(t8, 0, 24);
    t33 = *((unsigned int *)t29);
    t34 = (t33 & 2147483648U);
    t31 = t34;
    t9 = (t29 + 4);
    t35 = *((unsigned int *)t9);
    t36 = (t35 & 2147483648U);
    t32 = t36;
    t37 = (t34 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:    t42 = (t36 != 0);
    if (t42 == 1)
        goto LAB17;

LAB18:    t18 = ((char*)((ng3)));
    t48 = 0;

LAB22:    t49 = (t48 < 4);
    if (t49 == 1)
        goto LAB23;

LAB24:    t89 = (t0 + 1288);
    t92 = (t0 + 1288);
    t93 = (t92 + 72U);
    t94 = *((char **)t93);
    t95 = (t0 + 1288);
    t96 = (t95 + 64U);
    t97 = *((char **)t96);
    t98 = (t0 + 1768);
    t99 = (t98 + 56U);
    t100 = *((char **)t99);
    t101 = ((char*)((ng4)));
    memset(t102, 0, 8);
    xsi_vlog_signed_divide(t102, 32, t100, 32, t101, 32);
    xsi_vlog_generic_convert_array_indices(t90, t91, t94, t97, 2, 1, t102, 32, 1);
    t103 = (t90 + 4);
    t104 = *((unsigned int *)t103);
    t105 = (!(t104));
    t106 = (t91 + 4);
    t107 = *((unsigned int *)t106);
    t108 = (!(t107));
    t109 = (t105 && t108);
    if (t109 == 1)
        goto LAB25;

LAB26:    xsi_set_current_line(27, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1288);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 1288);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 1288);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t14 = (t0 + 1768);
    t15 = (t14 + 56U);
    t17 = *((char **)t15);
    t18 = ((char*)((ng4)));
    memset(t23, 0, 8);
    xsi_vlog_signed_divide(t23, 32, t17, 32, t18, 32);
    xsi_vlog_generic_get_array_select_value(t30, 128, t7, t10, t13, 2, 1, t23, 32, 1);
    t19 = (t0 + 2648);
    t20 = (t0 + 5024);
    t21 = *((char **)t20);
    t22 = (t0 + 5048);
    t57 = xsi_create_subprogram_invocation(t19, 0, *((char **)t22), ((char*)(t21)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t21)), t57);
    t59 = (t0 + 5032);
    t68 = *((char **)t59);
    xsi_vlogvar_assign_value(((char*)(t68)), t4, 0, 0, 12);
    t70 = (t0 + 5040);
    t71 = *((char **)t70);
    xsi_vlogvar_assign_value(((char*)(t71)), t30, 0, 0, 128);

LAB29:    t73 = (t0 + 2744);
    t89 = *((char **)t73);
    t92 = (t89 + 80U);
    t93 = *((char **)t92);
    t94 = (t93 + 272U);
    t95 = *((char **)t94);
    t96 = (t95 + 0U);
    t97 = *((char **)t96);
    t98 = (t0 + 5048);
    t16 = ((int  (*)(char *, char *))t97)(*((char **)t98), t89);

LAB31:    if (t16 != 0)
        goto LAB32;

LAB27:    t89 = (t0 + 5088);
    t99 = *((char **)t89);
    xsi_vlog_subprogram_popinvocation(((char*)(t99)));

LAB28:    t100 = (t0 + 2744);
    t101 = *((char **)t100);
    t100 = (t0 + 5088);
    t103 = *((char **)t100);
    t106 = (t0 + 2648);
    t114 = 0;
    xsi_delete_subprogram_invocation(((char*)(t103)), t101, t0, t106, t114);
    xsi_set_current_line(25, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t23, 0, 8);
    xsi_vlog_signed_add(t23, 32, t4, 32, t5, 32);
    t6 = (t0 + 1768);
    xsi_vlogvar_assign_value(t6, t23, 0, 0, 32);
    goto LAB11;

LAB15:    t38 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t38 | 0U);
    t10 = (t30 + 8);
    t39 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t39 | 4294967295U);
    t11 = (t30 + 16);
    t40 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t40 | 4294967295U);
    t12 = (t30 + 24);
    t41 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t41 | 4294967295U);
    goto LAB16;

LAB17:    t13 = (t30 + 4);
    t43 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t43 | 0U);
    t14 = (t30 + 12);
    t44 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t44 | 4294967295U);
    t15 = (t30 + 20);
    t45 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t45 | 4294967295U);
    t17 = (t30 + 28);
    t46 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t46 | 4294967295U);
    goto LAB18;

LAB19:    t65 = (t48 * 8);
    t66 = *((unsigned int *)t21);
    t67 = *((unsigned int *)t59);
    *((unsigned int *)t21) = (t66 | t67);
    t68 = (t30 + t65);
    t69 = (t65 + 4);
    t70 = (t30 + t69);
    t71 = (t18 + t65);
    t72 = (t65 + 4);
    t73 = (t18 + t72);
    t74 = *((unsigned int *)t68);
    t75 = (~(t74));
    t76 = *((unsigned int *)t70);
    t77 = (~(t76));
    t78 = *((unsigned int *)t71);
    t79 = (~(t78));
    t80 = *((unsigned int *)t73);
    t81 = (~(t80));
    t16 = (t75 & t77);
    t82 = (t79 & t81);
    t83 = (~(t16));
    t84 = (~(t82));
    t85 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t85 & t83);
    t86 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t86 & t84);
    t87 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t87 & t83);
    t88 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t88 & t84);

LAB21:    t48 = (t48 + 1);
    goto LAB22;

LAB20:    goto LAB21;

LAB23:    t50 = (t48 * 8);
    t19 = (t30 + t50);
    t20 = (t18 + t50);
    t21 = (t47 + t50);
    t51 = *((unsigned int *)t19);
    t52 = *((unsigned int *)t20);
    t53 = (t51 & t52);
    *((unsigned int *)t21) = t53;
    t54 = (t48 * 8);
    t55 = (t54 + 4);
    t22 = (t30 + t55);
    t56 = (t54 + 4);
    t57 = (t18 + t56);
    t58 = (t54 + 4);
    t59 = (t47 + t58);
    t60 = *((unsigned int *)t22);
    t61 = *((unsigned int *)t57);
    t62 = (t60 | t61);
    *((unsigned int *)t59) = t62;
    t63 = *((unsigned int *)t59);
    t64 = (t63 != 0);
    if (t64 == 1)
        goto LAB19;
    else
        goto LAB20;

LAB25:    t110 = *((unsigned int *)t90);
    t111 = *((unsigned int *)t91);
    t112 = (t110 - t111);
    t113 = (t112 + 1);
    xsi_vlogvar_assign_value(t89, t47, 0, *((unsigned int *)t91), t113);
    goto LAB26;

LAB30:;
LAB32:    t73 = (t0 + 2840U);
    *((char **)t73) = &&LAB29;
    goto LAB1;

LAB36:;
LAB38:    t17 = (t0 + 2840U);
    *((char **)t17) = &&LAB35;
    goto LAB1;

LAB42:;
LAB44:    t13 = (t0 + 2840U);
    *((char **)t13) = &&LAB41;
    goto LAB1;

LAB48:;
LAB50:    t17 = (t0 + 2840U);
    *((char **)t17) = &&LAB47;
    goto LAB1;

LAB52:    xsi_set_current_line(37, ng0);

LAB54:    xsi_set_current_line(45, ng0);
    t8 = (t0 + 1768);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng8)));
    memset(t90, 0, 8);
    xsi_vlog_signed_mod(t90, 32, t10, 32, t11, 32);
    t12 = ((char*)((ng1)));
    memset(t91, 0, 8);
    xsi_vlog_signed_equal(t91, 32, t90, 32, t12, 32);
    t13 = (t91 + 4);
    t31 = *((unsigned int *)t13);
    t32 = (~(t31));
    t33 = *((unsigned int *)t91);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB55;

LAB56:    xsi_set_current_line(51, ng0);

LAB65:    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 1448);
    t4 = (t0 + 1448);
    t5 = (t4 + 72U);
    t6 = *((char **)t5);
    t7 = (t0 + 1448);
    t8 = (t7 + 64U);
    t9 = *((char **)t8);
    t10 = (t0 + 1768);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    xsi_vlog_generic_convert_array_indices(t23, t29, t6, t9, 2, 1, t12, 32, 1);
    t13 = (t23 + 4);
    t24 = *((unsigned int *)t13);
    t16 = (!(t24));
    t14 = (t29 + 4);
    t25 = *((unsigned int *)t14);
    t82 = (!(t25));
    t105 = (t16 && t82);
    if (t105 == 1)
        goto LAB66;

LAB67:
LAB57:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng7)));
    memset(t23, 0, 8);
    xsi_vlog_signed_add(t23, 32, t4, 32, t5, 32);
    t6 = (t0 + 1768);
    xsi_vlogvar_assign_value(t6, t23, 0, 0, 32);
    goto LAB51;

LAB55:    xsi_set_current_line(45, ng0);

LAB58:    xsi_set_current_line(46, ng0);
    t14 = (t0 + 1768);
    t15 = (t14 + 56U);
    t17 = *((char **)t15);
    t18 = ((char*)((ng9)));
    memset(t102, 0, 8);
    xsi_vlog_signed_greater(t102, 32, t17, 32, t18, 32);
    t19 = (t102 + 4);
    t36 = *((unsigned int *)t19);
    t37 = (~(t36));
    t38 = *((unsigned int *)t102);
    t39 = (t38 & t37);
    t40 = (t39 != 0);
    if (t40 > 0)
        goto LAB59;

LAB60:
LAB61:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1288);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t0 + 1288);
    t9 = (t8 + 72U);
    t10 = *((char **)t9);
    t11 = (t0 + 1288);
    t12 = (t11 + 64U);
    t13 = *((char **)t12);
    t14 = (t0 + 1768);
    t15 = (t14 + 56U);
    t17 = *((char **)t15);
    xsi_vlog_generic_get_array_select_value(t30, 128, t7, t10, t13, 2, 1, t17, 32, 1);
    xsi_vlog_unsigned_add(t47, 128, t4, 34, t30, 128);
    t18 = (t0 + 1928);
    xsi_vlogvar_assign_value(t18, t47, 0, 0, 34);
    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    xsi_vlog_unsigned_rshift(t30, 128, t4, 34, t5, 32);
    t6 = (t0 + 1448);
    t7 = (t0 + 1448);
    t8 = (t7 + 72U);
    t9 = *((char **)t8);
    t10 = (t0 + 1448);
    t11 = (t10 + 64U);
    t12 = *((char **)t11);
    t13 = (t0 + 1768);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    xsi_vlog_generic_convert_array_indices(t23, t29, t9, t12, 2, 1, t15, 32, 1);
    t17 = (t23 + 4);
    t24 = *((unsigned int *)t17);
    t16 = (!(t24));
    t18 = (t29 + 4);
    t25 = *((unsigned int *)t18);
    t82 = (!(t25));
    t105 = (t16 && t82);
    if (t105 == 1)
        goto LAB63;

LAB64:    goto LAB57;

LAB59:    xsi_set_current_line(46, ng0);

LAB62:    xsi_set_current_line(47, ng0);
    t20 = (t0 + 1928);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t57 = (t0 + 1288);
    t59 = (t57 + 56U);
    t68 = *((char **)t59);
    t70 = (t0 + 1288);
    t71 = (t70 + 72U);
    t73 = *((char **)t71);
    t89 = (t0 + 1288);
    t92 = (t89 + 64U);
    t93 = *((char **)t92);
    t94 = (t0 + 1768);
    t95 = (t94 + 56U);
    t96 = *((char **)t95);
    t97 = ((char*)((ng10)));
    memset(t115, 0, 8);
    xsi_vlog_signed_minus(t115, 32, t96, 32, t97, 32);
    xsi_vlog_generic_get_array_select_value(t30, 128, t68, t73, t93, 2, 1, t115, 32, 1);
    xsi_vlog_unsigned_minus(t47, 128, t22, 34, t30, 128);
    t98 = (t0 + 1928);
    xsi_vlogvar_assign_value(t98, t47, 0, 0, 34);
    goto LAB61;

LAB63:    t26 = *((unsigned int *)t23);
    t27 = *((unsigned int *)t29);
    t108 = (t26 - t27);
    t109 = (t108 + 1);
    xsi_vlogvar_assign_value(t6, t30, 0, *((unsigned int *)t29), t109);
    goto LAB64;

LAB66:    t26 = *((unsigned int *)t23);
    t27 = *((unsigned int *)t29);
    t108 = (t26 - t27);
    t109 = (t108 + 1);
    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t29), t109);
    goto LAB67;

LAB68:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng12)));
    t3 = ((char*)((ng2)));
    t4 = ((char*)((ng1)));
    t5 = (t0 + 2648);
    t6 = (t0 + 5520);
    t7 = *((char **)t6);
    t8 = (t0 + 5552);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 5528);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 33);
    t12 = (t0 + 5536);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 32);
    t14 = (t0 + 5544);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 7);

LAB71:    t17 = (t0 + 2744);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t57 = (t22 + 0U);
    t59 = *((char **)t57);
    t68 = (t0 + 5552);
    t16 = ((int  (*)(char *, char *))t59)(*((char **)t68), t18);

LAB73:    if (t16 != 0)
        goto LAB74;

LAB69:    t18 = (t0 + 5576);
    t70 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t70)));

LAB70:    t71 = (t0 + 2744);
    t73 = *((char **)t71);
    t71 = (t0 + 5576);
    t89 = *((char **)t71);
    t92 = (t0 + 2648);
    t93 = 0;
    xsi_delete_subprogram_invocation(((char*)(t89)), t73, t0, t92, t93);
    xsi_set_current_line(62, ng0);
    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB75:    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t23, 0, 8);
    xsi_vlog_signed_less(t23, 32, t4, 32, t5, 32);
    t6 = (t23 + 4);
    t24 = *((unsigned int *)t6);
    t25 = (~(t24));
    t26 = *((unsigned int *)t23);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB76;

LAB77:    xsi_set_current_line(67, ng0);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB84:    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    t6 = ((char*)((ng4)));
    memset(t23, 0, 8);
    xsi_vlog_signed_divide(t23, 32, t5, 32, t6, 32);
    memset(t29, 0, 8);
    xsi_vlog_signed_less(t29, 32, t4, 32, t23, 32);
    t7 = (t29 + 4);
    t24 = *((unsigned int *)t7);
    t25 = (~(t24));
    t26 = *((unsigned int *)t29);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB85;

LAB86:    xsi_set_current_line(75, ng0);
    xsi_vlogfile_write(1, 0, 0, ng14, 1, t0);
    xsi_set_current_line(76, ng0);
    xsi_vlog_stop(1);
    goto LAB1;

LAB72:;
LAB74:    t17 = (t0 + 2840U);
    *((char **)t17) = &&LAB71;
    goto LAB1;

LAB76:    xsi_set_current_line(62, ng0);

LAB78:    xsi_set_current_line(63, ng0);
    t7 = (t0 + 1768);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 2648);
    t11 = (t0 + 5648);
    t12 = *((char **)t11);
    t13 = (t0 + 5664);
    t14 = xsi_create_subprogram_invocation(t10, 0, *((char **)t13), ((char*)(t12)), 0, 0);
    t15 = (t0 + 5656);
    t17 = *((char **)t15);
    xsi_vlogvar_assign_value(((char*)(t17)), t9, 0, 0, 12);

LAB79:    t18 = (t0 + 2744);
    t19 = *((char **)t18);
    t20 = (t19 + 80U);
    t21 = *((char **)t20);
    t22 = (t21 + 272U);
    t57 = *((char **)t22);
    t59 = (t57 + 0U);
    t68 = *((char **)t59);
    t70 = (t0 + 5664);
    t16 = ((int  (*)(char *, char *))t68)(*((char **)t70), t19);
    if (t16 != 0)
        goto LAB81;

LAB80:    t19 = (t0 + 2744);
    t71 = *((char **)t19);
    t19 = (t0 + 5672);
    t73 = *((char **)t19);
    t89 = ((((char*)(t73))) + 56U);
    t92 = *((char **)t89);
    memcpy(t30, t92, 32);
    t93 = (t0 + 5648);
    t94 = *((char **)t93);
    t95 = (t0 + 2648);
    t96 = 0;
    xsi_delete_subprogram_invocation(((char*)(t94)), t71, t0, t95, t96);
    t97 = (t0 + 1608);
    t98 = (t0 + 1608);
    t99 = (t98 + 72U);
    t100 = *((char **)t99);
    t101 = (t0 + 1608);
    t103 = (t101 + 64U);
    t106 = *((char **)t103);
    t114 = (t0 + 1768);
    t116 = (t114 + 56U);
    t117 = *((char **)t116);
    t118 = ((char*)((ng4)));
    memset(t91, 0, 8);
    xsi_vlog_signed_divide(t91, 32, t117, 32, t118, 32);
    xsi_vlog_generic_convert_array_indices(t29, t90, t100, t106, 2, 1, t91, 32, 1);
    t119 = (t29 + 4);
    t31 = *((unsigned int *)t119);
    t82 = (!(t31));
    t120 = (t90 + 4);
    t32 = *((unsigned int *)t120);
    t105 = (!(t32));
    t108 = (t82 && t105);
    if (t108 == 1)
        goto LAB82;

LAB83:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t23, 0, 8);
    xsi_vlog_signed_add(t23, 32, t4, 32, t5, 32);
    t6 = (t0 + 1768);
    xsi_vlogvar_assign_value(t6, t23, 0, 0, 32);
    goto LAB75;

LAB81:    t18 = (t0 + 2840U);
    *((char **)t18) = &&LAB79;
    goto LAB1;

LAB82:    t33 = *((unsigned int *)t29);
    t34 = *((unsigned int *)t90);
    t109 = (t33 - t34);
    t112 = (t109 + 1);
    xsi_vlogvar_assign_value(t97, t30, 0, *((unsigned int *)t90), t112);
    goto LAB83;

LAB85:    xsi_set_current_line(67, ng0);

LAB87:    xsi_set_current_line(68, ng0);
    t8 = (t0 + 1608);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t0 + 1608);
    t12 = (t11 + 72U);
    t13 = *((char **)t12);
    t14 = (t0 + 1608);
    t15 = (t14 + 64U);
    t17 = *((char **)t15);
    t18 = (t0 + 1768);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    xsi_vlog_generic_get_array_select_value(t30, 128, t10, t13, t17, 2, 1, t20, 32, 1);
    t21 = (t0 + 1448);
    t22 = (t21 + 56U);
    t57 = *((char **)t22);
    t59 = (t0 + 1448);
    t68 = (t59 + 72U);
    t70 = *((char **)t68);
    t71 = (t0 + 1448);
    t73 = (t71 + 64U);
    t89 = *((char **)t73);
    t92 = (t0 + 1768);
    t93 = (t92 + 56U);
    t94 = *((char **)t93);
    xsi_vlog_generic_get_array_select_value(t47, 128, t57, t70, t89, 2, 1, t94, 32, 1);
    xsi_vlog_unsigned_case_noteq(t121, 128, t30, 128, t47, 128);
    t95 = (t121 + 4);
    t31 = *((unsigned int *)t95);
    t32 = (~(t31));
    t33 = *((unsigned int *)t121);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB88;

LAB89:
LAB90:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng7)));
    memset(t23, 0, 8);
    xsi_vlog_signed_add(t23, 32, t4, 32, t5, 32);
    t6 = (t0 + 1768);
    xsi_vlogvar_assign_value(t6, t23, 0, 0, 32);
    goto LAB84;

LAB88:    xsi_set_current_line(68, ng0);

LAB91:    xsi_set_current_line(69, ng0);
    t96 = (t0 + 1768);
    t97 = (t96 + 56U);
    t98 = *((char **)t97);
    t99 = (t0 + 1608);
    t100 = (t99 + 56U);
    t101 = *((char **)t100);
    t103 = (t0 + 1608);
    t106 = (t103 + 72U);
    t114 = *((char **)t106);
    t116 = (t0 + 1608);
    t117 = (t116 + 64U);
    t118 = *((char **)t117);
    t119 = (t0 + 1768);
    t120 = (t119 + 56U);
    t123 = *((char **)t120);
    xsi_vlog_generic_get_array_select_value(t122, 128, t101, t114, t118, 2, 1, t123, 32, 1);
    t124 = (t0 + 1448);
    t125 = (t124 + 56U);
    t126 = *((char **)t125);
    t128 = (t0 + 1448);
    t129 = (t128 + 72U);
    t130 = *((char **)t129);
    t131 = (t0 + 1448);
    t132 = (t131 + 64U);
    t133 = *((char **)t132);
    t134 = (t0 + 1768);
    t135 = (t134 + 56U);
    t136 = *((char **)t135);
    xsi_vlog_generic_get_array_select_value(t127, 128, t126, t130, t133, 2, 1, t136, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng13, 4, t0, (char)119, t98, 32, (char)118, t122, 128, (char)118, t127, 128);
    xsi_set_current_line(71, ng0);
    xsi_vlog_stop(1);
    goto LAB90;

}


extern void work_m_12195314101343777614_1224442286_init()
{
	static char *pe[] = {(void *)Initial_19_0};
	xsi_register_didat("work_m_12195314101343777614_1224442286", "isim/PicoTestbench_isim_beh.exe.sim/work/m_12195314101343777614_1224442286.didat");
	xsi_register_executes(pe);
}
