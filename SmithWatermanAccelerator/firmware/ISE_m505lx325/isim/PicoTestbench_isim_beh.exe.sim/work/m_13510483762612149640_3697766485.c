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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/PicoStreamOut.v";
static unsigned int ng1[] = {8U, 0U};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {16U, 0U};
static unsigned int ng5[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static int ng6[] = {0, 0};
static unsigned int ng7[] = {512U, 0U};
static int ng8[] = {1, 0};
static int ng9[] = {16, 0};



static void NetDecl_36_0(char *t0)
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

LAB0:    t1 = (t0 + 8232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 9936);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 127U;
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
    xsi_driver_vfirst_trans(t3, 0, 6U);

LAB1:    return;
}

static void NetDecl_37_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;

LAB0:    t1 = (t0 + 8480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 3240U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng2)));
    t5 = ((char*)((ng2)));
    xsi_vlogtype_concat(t3, 9, 9, 3U, t5, 1, t2, 1, t4, 7);
    t6 = (t0 + 10000);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t10, 0, 8);
    t11 = 511U;
    t12 = t11;
    t13 = (t3 + 4);
    t14 = *((unsigned int *)t3);
    t11 = (t11 & t14);
    t15 = *((unsigned int *)t13);
    t12 = (t12 & t15);
    t16 = (t10 + 4);
    t17 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t17 | t11);
    t18 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t18 | t12);
    xsi_driver_vfirst_trans(t6, 0, 8U);
    t19 = (t0 + 9792);
    *((int *)t19) = 1;

LAB1:    return;
}

static void NetDecl_38_2(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;

LAB0:    t1 = (t0 + 8728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 3240U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng2)));
    t5 = ((char*)((ng3)));
    xsi_vlogtype_concat(t3, 9, 9, 3U, t5, 1, t2, 1, t4, 7);
    t6 = (t0 + 10064);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t10, 0, 8);
    t11 = 511U;
    t12 = t11;
    t13 = (t3 + 4);
    t14 = *((unsigned int *)t3);
    t11 = (t11 & t14);
    t15 = *((unsigned int *)t13);
    t12 = (t12 & t15);
    t16 = (t10 + 4);
    t17 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t17 | t11);
    t18 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t18 | t12);
    xsi_driver_vfirst_trans(t6, 0, 8U);
    t19 = (t0 + 9808);
    *((int *)t19) = 1;

LAB1:    return;
}

static void NetDecl_47_3(char *t0)
{
    char t3[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
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
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    t1 = (t0 + 8976U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 5880);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 24);
    t8 = (t5 + 28);
    t9 = *((unsigned int *)t7);
    t10 = (t9 >> 0);
    *((unsigned int *)t3) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t6) = t12;
    t13 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t13 & 4294967295U);
    t14 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t14 & 4294967295U);
    t15 = ((char*)((ng4)));
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t3, 32, t15, 32);
    t17 = (t0 + 10128);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t16, 8);
    xsi_driver_vfirst_trans(t17, 0, 31U);
    t22 = (t0 + 9824);
    *((int *)t22) = 1;

LAB1:    return;
}

static void NetDecl_58_4(char *t0)
{
    char t3[8];
    char t23[8];
    char t37[8];
    char t44[8];
    char t76[8];
    char t88[8];
    char t98[8];
    char t108[8];
    char t124[8];
    char t132[8];
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
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
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
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    char *t89;
    char *t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t99;
    char *t100;
    char *t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    char *t109;
    char *t110;
    unsigned int t111;
    unsigned int t112;
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
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    char *t131;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    char *t137;
    char *t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    char *t146;
    char *t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    int t156;
    int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    char *t164;
    char *t165;
    char *t166;
    char *t167;
    char *t168;
    unsigned int t169;
    unsigned int t170;
    char *t171;
    unsigned int t172;
    unsigned int t173;
    char *t174;
    unsigned int t175;
    unsigned int t176;
    char *t177;

LAB0:    t1 = (t0 + 9224U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 7320);
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
    memset(t23, 0, 8);
    t24 = (t3 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t3);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t24) != 0)
        goto LAB12;

LAB13:    t31 = (t23 + 4);
    t32 = *((unsigned int *)t23);
    t33 = *((unsigned int *)t31);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB14;

LAB15:    memcpy(t44, t23, 8);

LAB16:    memset(t76, 0, 8);
    t77 = (t44 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t44);
    t81 = (t80 & t79);
    t82 = (t81 & 1U);
    if (t82 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t77) != 0)
        goto LAB26;

LAB27:    t84 = (t76 + 4);
    t85 = *((unsigned int *)t76);
    t86 = *((unsigned int *)t84);
    t87 = (t85 || t86);
    if (t87 > 0)
        goto LAB28;

LAB29:    memcpy(t132, t76, 8);

LAB30:    t164 = (t0 + 10192);
    t165 = (t164 + 56U);
    t166 = *((char **)t165);
    t167 = (t166 + 56U);
    t168 = *((char **)t167);
    memset(t168, 0, 8);
    t169 = 1U;
    t170 = t169;
    t171 = (t132 + 4);
    t172 = *((unsigned int *)t132);
    t169 = (t169 & t172);
    t173 = *((unsigned int *)t171);
    t170 = (t170 & t173);
    t174 = (t168 + 4);
    t175 = *((unsigned int *)t168);
    *((unsigned int *)t168) = (t175 | t169);
    t176 = *((unsigned int *)t174);
    *((unsigned int *)t174) = (t176 | t170);
    xsi_driver_vfirst_trans(t164, 0, 0U);
    t177 = (t0 + 9840);
    *((int *)t177) = 1;

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

LAB10:    *((unsigned int *)t23) = 1;
    goto LAB13;

LAB12:    t30 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB13;

LAB14:    t35 = (t0 + 1960U);
    t36 = *((char **)t35);
    memset(t37, 0, 8);
    t35 = (t36 + 4);
    t38 = *((unsigned int *)t35);
    t39 = (~(t38));
    t40 = *((unsigned int *)t36);
    t41 = (t40 & t39);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t35) != 0)
        goto LAB19;

LAB20:    t45 = *((unsigned int *)t23);
    t46 = *((unsigned int *)t37);
    t47 = (t45 & t46);
    *((unsigned int *)t44) = t47;
    t48 = (t23 + 4);
    t49 = (t37 + 4);
    t50 = (t44 + 4);
    t51 = *((unsigned int *)t48);
    t52 = *((unsigned int *)t49);
    t53 = (t51 | t52);
    *((unsigned int *)t50) = t53;
    t54 = *((unsigned int *)t50);
    t55 = (t54 != 0);
    if (t55 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t37) = 1;
    goto LAB20;

LAB19:    t43 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB20;

LAB21:    t56 = *((unsigned int *)t44);
    t57 = *((unsigned int *)t50);
    *((unsigned int *)t44) = (t56 | t57);
    t58 = (t23 + 4);
    t59 = (t37 + 4);
    t60 = *((unsigned int *)t23);
    t61 = (~(t60));
    t62 = *((unsigned int *)t58);
    t63 = (~(t62));
    t64 = *((unsigned int *)t37);
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
    goto LAB23;

LAB24:    *((unsigned int *)t76) = 1;
    goto LAB27;

LAB26:    t83 = (t76 + 4);
    *((unsigned int *)t76) = 1;
    *((unsigned int *)t83) = 1;
    goto LAB27;

LAB28:    t89 = (t0 + 2120U);
    t90 = *((char **)t89);
    memset(t88, 0, 8);
    t89 = (t88 + 4);
    t91 = (t90 + 4);
    t92 = *((unsigned int *)t90);
    t93 = (t92 >> 0);
    *((unsigned int *)t88) = t93;
    t94 = *((unsigned int *)t91);
    t95 = (t94 >> 0);
    *((unsigned int *)t89) = t95;
    t96 = *((unsigned int *)t88);
    *((unsigned int *)t88) = (t96 & 511U);
    t97 = *((unsigned int *)t89);
    *((unsigned int *)t89) = (t97 & 511U);
    t99 = (t0 + 3400U);
    t100 = *((char **)t99);
    memset(t98, 0, 8);
    t99 = (t98 + 4);
    t101 = (t100 + 4);
    t102 = *((unsigned int *)t100);
    t103 = (t102 >> 0);
    *((unsigned int *)t98) = t103;
    t104 = *((unsigned int *)t101);
    t105 = (t104 >> 0);
    *((unsigned int *)t99) = t105;
    t106 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t106 & 511U);
    t107 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t107 & 511U);
    memset(t108, 0, 8);
    t109 = (t88 + 4);
    t110 = (t98 + 4);
    t111 = *((unsigned int *)t88);
    t112 = *((unsigned int *)t98);
    t113 = (t111 ^ t112);
    t114 = *((unsigned int *)t109);
    t115 = *((unsigned int *)t110);
    t116 = (t114 ^ t115);
    t117 = (t113 | t116);
    t118 = *((unsigned int *)t109);
    t119 = *((unsigned int *)t110);
    t120 = (t118 | t119);
    t121 = (~(t120));
    t122 = (t117 & t121);
    if (t122 != 0)
        goto LAB34;

LAB31:    if (t120 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t108) = 1;

LAB34:    memset(t124, 0, 8);
    t125 = (t108 + 4);
    t126 = *((unsigned int *)t125);
    t127 = (~(t126));
    t128 = *((unsigned int *)t108);
    t129 = (t128 & t127);
    t130 = (t129 & 1U);
    if (t130 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t125) != 0)
        goto LAB37;

LAB38:    t133 = *((unsigned int *)t76);
    t134 = *((unsigned int *)t124);
    t135 = (t133 & t134);
    *((unsigned int *)t132) = t135;
    t136 = (t76 + 4);
    t137 = (t124 + 4);
    t138 = (t132 + 4);
    t139 = *((unsigned int *)t136);
    t140 = *((unsigned int *)t137);
    t141 = (t139 | t140);
    *((unsigned int *)t138) = t141;
    t142 = *((unsigned int *)t138);
    t143 = (t142 != 0);
    if (t143 == 1)
        goto LAB39;

LAB40:
LAB41:    goto LAB30;

LAB33:    t123 = (t108 + 4);
    *((unsigned int *)t108) = 1;
    *((unsigned int *)t123) = 1;
    goto LAB34;

LAB35:    *((unsigned int *)t124) = 1;
    goto LAB38;

LAB37:    t131 = (t124 + 4);
    *((unsigned int *)t124) = 1;
    *((unsigned int *)t131) = 1;
    goto LAB38;

LAB39:    t144 = *((unsigned int *)t132);
    t145 = *((unsigned int *)t138);
    *((unsigned int *)t132) = (t144 | t145);
    t146 = (t76 + 4);
    t147 = (t124 + 4);
    t148 = *((unsigned int *)t76);
    t149 = (~(t148));
    t150 = *((unsigned int *)t146);
    t151 = (~(t150));
    t152 = *((unsigned int *)t124);
    t153 = (~(t152));
    t154 = *((unsigned int *)t147);
    t155 = (~(t154));
    t156 = (t149 & t151);
    t157 = (t153 & t155);
    t158 = (~(t156));
    t159 = (~(t157));
    t160 = *((unsigned int *)t138);
    *((unsigned int *)t138) = (t160 & t158);
    t161 = *((unsigned int *)t138);
    *((unsigned int *)t138) = (t161 & t159);
    t162 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t162 & t158);
    t163 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t163 & t159);
    goto LAB41;

}

static void Always_63_5(char *t0)
{
    char t6[32];
    char t12[8];
    char t14[8];
    char t23[8];
    char t49[8];
    char t53[8];
    char t60[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t24;
    char *t25;
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
    char *t38;
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
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    int t84;
    int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;

LAB0:    t1 = (t0 + 9472U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 9856);
    *((int *)t2) = 1;
    t3 = (t0 + 9504);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(63, ng0);

LAB5:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 1480U);
    t5 = *((char **)t4);
    t4 = (t0 + 7320);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2600U);
    t3 = *((char **)t2);
    xsi_vlog_get_part_select_value(t6, 128, t3, 127, 0);
    t2 = (t0 + 5880);
    xsi_vlogvar_wait_assign_value(t2, t6, 0, 0, 128, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t0 + 6680);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 128, 0LL);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5400);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 5560);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 128, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 5720);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 4680U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 5240);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 128, 0LL);

LAB8:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2760U);
    t3 = *((char **)t2);
    memset(t12, 0, 8);
    t2 = (t12 + 4);
    t4 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 0);
    *((unsigned int *)t12) = t8;
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t11 & 511U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 511U);
    t5 = (t0 + 3560U);
    t15 = *((char **)t5);
    memset(t14, 0, 8);
    t5 = (t14 + 4);
    t16 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = (t17 >> 0);
    *((unsigned int *)t14) = t18;
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 0);
    *((unsigned int *)t5) = t20;
    t21 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t21 & 511U);
    t22 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t22 & 511U);
    memset(t23, 0, 8);
    t24 = (t12 + 4);
    t25 = (t14 + 4);
    t26 = *((unsigned int *)t12);
    t27 = *((unsigned int *)t14);
    t28 = (t26 ^ t27);
    t29 = *((unsigned int *)t24);
    t30 = *((unsigned int *)t25);
    t31 = (t29 ^ t30);
    t32 = (t28 | t31);
    t33 = *((unsigned int *)t24);
    t34 = *((unsigned int *)t25);
    t35 = (t33 | t34);
    t36 = (~(t35));
    t37 = (t32 & t36);
    if (t37 != 0)
        goto LAB12;

LAB9:    if (t35 != 0)
        goto LAB11;

LAB10:    *((unsigned int *)t23) = 1;

LAB12:    t39 = (t23 + 4);
    t40 = *((unsigned int *)t39);
    t41 = (~(t40));
    t42 = *((unsigned int *)t23);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB13;

LAB14:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2760U);
    t3 = *((char **)t2);
    memset(t12, 0, 8);
    t2 = (t12 + 4);
    t4 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 0);
    *((unsigned int *)t12) = t8;
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t11 & 511U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 511U);
    t5 = (t0 + 3400U);
    t15 = *((char **)t5);
    memset(t14, 0, 8);
    t5 = (t14 + 4);
    t16 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = (t17 >> 0);
    *((unsigned int *)t14) = t18;
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 0);
    *((unsigned int *)t5) = t20;
    t21 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t21 & 511U);
    t22 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t22 & 511U);
    memset(t23, 0, 8);
    t24 = (t12 + 4);
    t25 = (t14 + 4);
    t26 = *((unsigned int *)t12);
    t27 = *((unsigned int *)t14);
    t28 = (t26 ^ t27);
    t29 = *((unsigned int *)t24);
    t30 = *((unsigned int *)t25);
    t31 = (t29 ^ t30);
    t32 = (t28 | t31);
    t33 = *((unsigned int *)t24);
    t34 = *((unsigned int *)t25);
    t35 = (t33 | t34);
    t36 = (~(t35));
    t37 = (t32 & t36);
    if (t37 != 0)
        goto LAB20;

LAB17:    if (t35 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t23) = 1;

LAB20:    t39 = (t23 + 4);
    t40 = *((unsigned int *)t39);
    t41 = (~(t40));
    t42 = *((unsigned int *)t23);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB21;

LAB22:
LAB23:
LAB15:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB31;

LAB32:    xsi_set_current_line(93, ng0);

LAB35:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 7000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t12, 0, 8);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB39;

LAB37:    if (*((unsigned int *)t5) == 0)
        goto LAB36;

LAB38:    t15 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t15) = 1;

LAB39:    t16 = (t12 + 4);
    t24 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t17 = (~(t13));
    *((unsigned int *)t12) = t17;
    *((unsigned int *)t16) = 0;
    if (*((unsigned int *)t24) != 0)
        goto LAB41;

LAB40:    t22 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t22 & 1U);
    t26 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t26 & 1U);
    t25 = (t0 + 5080);
    xsi_vlogvar_wait_assign_value(t25, t12, 0, 0, 1, 0LL);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 4200U);
    t3 = *((char **)t2);
    t2 = (t0 + 7000);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 6200);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 6520);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 2280U);
    t3 = *((char **)t2);
    memset(t12, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t2) != 0)
        goto LAB44;

LAB45:    t5 = (t12 + 4);
    t13 = *((unsigned int *)t12);
    t17 = *((unsigned int *)t5);
    t18 = (t13 || t17);
    if (t18 > 0)
        goto LAB46;

LAB47:    memcpy(t60, t12, 8);

LAB48:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB60;

LAB61:
LAB62:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 1640U);
    t3 = *((char **)t2);
    memset(t12, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB64;

LAB65:    if (*((unsigned int *)t2) != 0)
        goto LAB66;

LAB67:    t5 = (t12 + 4);
    t13 = *((unsigned int *)t12);
    t17 = *((unsigned int *)t5);
    t18 = (t13 || t17);
    if (t18 > 0)
        goto LAB68;

LAB69:    memcpy(t23, t12, 8);

LAB70:    t59 = (t0 + 6840);
    xsi_vlogvar_wait_assign_value(t59, t23, 0, 0, 1, 0LL);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 6840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB78;

LAB79:
LAB80:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 3080U);
    t3 = *((char **)t2);
    memset(t12, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB81;

LAB82:    if (*((unsigned int *)t2) != 0)
        goto LAB83;

LAB84:    t5 = (t12 + 4);
    t13 = *((unsigned int *)t12);
    t17 = *((unsigned int *)t5);
    t18 = (t13 || t17);
    if (t18 > 0)
        goto LAB85;

LAB86:    memcpy(t60, t12, 8);

LAB87:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB99;

LAB100:
LAB101:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 6520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB102;

LAB103:
LAB104:
LAB33:    goto LAB2;

LAB6:    xsi_set_current_line(74, ng0);
    t4 = (t0 + 4520U);
    t5 = *((char **)t4);
    t4 = (t0 + 5240);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 128, 0LL);
    goto LAB8;

LAB11:    t38 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB12;

LAB13:    xsi_set_current_line(78, ng0);

LAB16:    xsi_set_current_line(79, ng0);
    t45 = (t0 + 6360);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = (t0 + 5400);
    xsi_vlogvar_wait_assign_value(t48, t47, 0, 0, 32, 0LL);
    goto LAB15;

LAB19:    t38 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB20;

LAB21:    xsi_set_current_line(80, ng0);

LAB24:    xsi_set_current_line(81, ng0);
    t45 = (t0 + 7160);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = (t0 + 5400);
    xsi_vlogvar_wait_assign_value(t48, t47, 0, 0, 32, 0LL);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 3880U);
    t3 = *((char **)t2);
    t2 = (t0 + 5560);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 128, 0LL);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3720U);
    t3 = *((char **)t2);
    memset(t12, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB28;

LAB26:    if (*((unsigned int *)t2) == 0)
        goto LAB25;

LAB27:    t4 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t4) = 1;

LAB28:    t5 = (t12 + 4);
    t15 = (t3 + 4);
    t13 = *((unsigned int *)t3);
    t17 = (~(t13));
    *((unsigned int *)t12) = t17;
    *((unsigned int *)t5) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB30;

LAB29:    t22 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t22 & 1U);
    t26 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t26 & 1U);
    t16 = (t0 + 5720);
    xsi_vlogvar_wait_assign_value(t16, t12, 0, 0, 1, 0LL);
    goto LAB23;

LAB25:    *((unsigned int *)t12) = 1;
    goto LAB28;

LAB30:    t18 = *((unsigned int *)t12);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t12) = (t18 | t19);
    t20 = *((unsigned int *)t5);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t5) = (t20 | t21);
    goto LAB29;

LAB31:    xsi_set_current_line(86, ng0);

LAB34:    xsi_set_current_line(87, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 6840);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 5080);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 7160);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 6200);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 6520);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 6360);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    goto LAB33;

LAB36:    *((unsigned int *)t12) = 1;
    goto LAB39;

LAB41:    t18 = *((unsigned int *)t12);
    t19 = *((unsigned int *)t24);
    *((unsigned int *)t12) = (t18 | t19);
    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t24);
    *((unsigned int *)t16) = (t20 | t21);
    goto LAB40;

LAB42:    *((unsigned int *)t12) = 1;
    goto LAB45;

LAB44:    t4 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB45;

LAB46:    t15 = (t0 + 2440U);
    t16 = *((char **)t15);
    memset(t14, 0, 8);
    t15 = (t14 + 4);
    t24 = (t16 + 4);
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 0);
    *((unsigned int *)t14) = t20;
    t21 = *((unsigned int *)t24);
    t22 = (t21 >> 0);
    *((unsigned int *)t15) = t22;
    t26 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t26 & 511U);
    t27 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t27 & 511U);
    t25 = (t0 + 3560U);
    t38 = *((char **)t25);
    memset(t23, 0, 8);
    t25 = (t23 + 4);
    t39 = (t38 + 4);
    t28 = *((unsigned int *)t38);
    t29 = (t28 >> 0);
    *((unsigned int *)t23) = t29;
    t30 = *((unsigned int *)t39);
    t31 = (t30 >> 0);
    *((unsigned int *)t25) = t31;
    t32 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t32 & 511U);
    t33 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t33 & 511U);
    memset(t49, 0, 8);
    t45 = (t14 + 4);
    t46 = (t23 + 4);
    t34 = *((unsigned int *)t14);
    t35 = *((unsigned int *)t23);
    t36 = (t34 ^ t35);
    t37 = *((unsigned int *)t45);
    t40 = *((unsigned int *)t46);
    t41 = (t37 ^ t40);
    t42 = (t36 | t41);
    t43 = *((unsigned int *)t45);
    t44 = *((unsigned int *)t46);
    t50 = (t43 | t44);
    t51 = (~(t50));
    t52 = (t42 & t51);
    if (t52 != 0)
        goto LAB52;

LAB49:    if (t50 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t49) = 1;

LAB52:    memset(t53, 0, 8);
    t48 = (t49 + 4);
    t54 = *((unsigned int *)t48);
    t55 = (~(t54));
    t56 = *((unsigned int *)t49);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t48) != 0)
        goto LAB55;

LAB56:    t61 = *((unsigned int *)t12);
    t62 = *((unsigned int *)t53);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t12 + 4);
    t65 = (t53 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB57;

LAB58:
LAB59:    goto LAB48;

LAB51:    t47 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB52;

LAB53:    *((unsigned int *)t53) = 1;
    goto LAB56;

LAB55:    t59 = (t53 + 4);
    *((unsigned int *)t53) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB56;

LAB57:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t12 + 4);
    t75 = (t53 + 4);
    t76 = *((unsigned int *)t12);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t53);
    t81 = (~(t80));
    t82 = *((unsigned int *)t75);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t88 & t86);
    t89 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB59;

LAB60:    xsi_set_current_line(99, ng0);

LAB63:    xsi_set_current_line(100, ng0);
    t98 = ((char*)((ng8)));
    t99 = (t0 + 6200);
    xsi_vlogvar_wait_assign_value(t99, t98, 0, 0, 1, 0LL);
    goto LAB62;

LAB64:    *((unsigned int *)t12) = 1;
    goto LAB67;

LAB66:    t4 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB67;

LAB68:    t15 = (t0 + 5080);
    t16 = (t15 + 56U);
    t24 = *((char **)t16);
    memset(t14, 0, 8);
    t25 = (t24 + 4);
    t19 = *((unsigned int *)t25);
    t20 = (~(t19));
    t21 = *((unsigned int *)t24);
    t22 = (t21 & t20);
    t26 = (t22 & 1U);
    if (t26 != 0)
        goto LAB71;

LAB72:    if (*((unsigned int *)t25) != 0)
        goto LAB73;

LAB74:    t27 = *((unsigned int *)t12);
    t28 = *((unsigned int *)t14);
    t29 = (t27 & t28);
    *((unsigned int *)t23) = t29;
    t39 = (t12 + 4);
    t45 = (t14 + 4);
    t46 = (t23 + 4);
    t30 = *((unsigned int *)t39);
    t31 = *((unsigned int *)t45);
    t32 = (t30 | t31);
    *((unsigned int *)t46) = t32;
    t33 = *((unsigned int *)t46);
    t34 = (t33 != 0);
    if (t34 == 1)
        goto LAB75;

LAB76:
LAB77:    goto LAB70;

LAB71:    *((unsigned int *)t14) = 1;
    goto LAB74;

LAB73:    t38 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB74;

LAB75:    t35 = *((unsigned int *)t23);
    t36 = *((unsigned int *)t46);
    *((unsigned int *)t23) = (t35 | t36);
    t47 = (t12 + 4);
    t48 = (t14 + 4);
    t37 = *((unsigned int *)t12);
    t40 = (~(t37));
    t41 = *((unsigned int *)t47);
    t42 = (~(t41));
    t43 = *((unsigned int *)t14);
    t44 = (~(t43));
    t50 = *((unsigned int *)t48);
    t51 = (~(t50));
    t84 = (t40 & t42);
    t85 = (t44 & t51);
    t52 = (~(t84));
    t54 = (~(t85));
    t55 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t55 & t52);
    t56 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t56 & t54);
    t57 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t57 & t52);
    t58 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t58 & t54);
    goto LAB77;

LAB78:    xsi_set_current_line(106, ng0);
    t15 = (t0 + 7160);
    t16 = (t15 + 56U);
    t24 = *((char **)t16);
    t25 = ((char*)((ng9)));
    memset(t12, 0, 8);
    xsi_vlog_unsigned_add(t12, 32, t24, 32, t25, 32);
    t38 = (t0 + 7160);
    xsi_vlogvar_wait_assign_value(t38, t12, 0, 0, 32, 0LL);
    goto LAB80;

LAB81:    *((unsigned int *)t12) = 1;
    goto LAB84;

LAB83:    t4 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB84;

LAB85:    t15 = (t0 + 2920U);
    t16 = *((char **)t15);
    memset(t14, 0, 8);
    t15 = (t14 + 4);
    t24 = (t16 + 4);
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 0);
    *((unsigned int *)t14) = t20;
    t21 = *((unsigned int *)t24);
    t22 = (t21 >> 0);
    *((unsigned int *)t15) = t22;
    t26 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t26 & 511U);
    t27 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t27 & 511U);
    t25 = (t0 + 3400U);
    t38 = *((char **)t25);
    memset(t23, 0, 8);
    t25 = (t23 + 4);
    t39 = (t38 + 4);
    t28 = *((unsigned int *)t38);
    t29 = (t28 >> 0);
    *((unsigned int *)t23) = t29;
    t30 = *((unsigned int *)t39);
    t31 = (t30 >> 0);
    *((unsigned int *)t25) = t31;
    t32 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t32 & 511U);
    t33 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t33 & 511U);
    memset(t49, 0, 8);
    t45 = (t14 + 4);
    t46 = (t23 + 4);
    t34 = *((unsigned int *)t14);
    t35 = *((unsigned int *)t23);
    t36 = (t34 ^ t35);
    t37 = *((unsigned int *)t45);
    t40 = *((unsigned int *)t46);
    t41 = (t37 ^ t40);
    t42 = (t36 | t41);
    t43 = *((unsigned int *)t45);
    t44 = *((unsigned int *)t46);
    t50 = (t43 | t44);
    t51 = (~(t50));
    t52 = (t42 & t51);
    if (t52 != 0)
        goto LAB91;

LAB88:    if (t50 != 0)
        goto LAB90;

LAB89:    *((unsigned int *)t49) = 1;

LAB91:    memset(t53, 0, 8);
    t48 = (t49 + 4);
    t54 = *((unsigned int *)t48);
    t55 = (~(t54));
    t56 = *((unsigned int *)t49);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB92;

LAB93:    if (*((unsigned int *)t48) != 0)
        goto LAB94;

LAB95:    t61 = *((unsigned int *)t12);
    t62 = *((unsigned int *)t53);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t12 + 4);
    t65 = (t53 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB96;

LAB97:
LAB98:    goto LAB87;

LAB90:    t47 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB91;

LAB92:    *((unsigned int *)t53) = 1;
    goto LAB95;

LAB94:    t59 = (t53 + 4);
    *((unsigned int *)t53) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB95;

LAB96:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t12 + 4);
    t75 = (t53 + 4);
    t76 = *((unsigned int *)t12);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t53);
    t81 = (~(t80));
    t82 = *((unsigned int *)t75);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t88 & t86);
    t89 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB98;

LAB99:    xsi_set_current_line(109, ng0);
    t98 = ((char*)((ng8)));
    t99 = (t0 + 6520);
    xsi_vlogvar_wait_assign_value(t99, t98, 0, 0, 1, 0LL);
    goto LAB101;

LAB102:    xsi_set_current_line(112, ng0);
    t15 = (t0 + 6360);
    t16 = (t15 + 56U);
    t24 = *((char **)t16);
    t25 = ((char*)((ng9)));
    memset(t12, 0, 8);
    xsi_vlog_unsigned_add(t12, 32, t24, 32, t25, 32);
    t38 = (t0 + 6360);
    xsi_vlogvar_wait_assign_value(t38, t12, 0, 0, 32, 0LL);
    goto LAB104;

}


extern void work_m_13510483762612149640_3697766485_init()
{
	static char *pe[] = {(void *)NetDecl_36_0,(void *)NetDecl_37_1,(void *)NetDecl_38_2,(void *)NetDecl_47_3,(void *)NetDecl_58_4,(void *)Always_63_5};
	xsi_register_didat("work_m_13510483762612149640_3697766485", "isim/PicoTestbench_isim_beh.exe.sim/work/m_13510483762612149640_3697766485.didat");
	xsi_register_executes(pe);
}
