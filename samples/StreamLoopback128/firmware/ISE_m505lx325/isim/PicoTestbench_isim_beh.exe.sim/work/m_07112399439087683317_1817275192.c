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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/samples/StreamLoopback128/firmware/ISE_m505lx325/source/PIO_128_RX_ENGINE_SIM.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {0U, 0U, 0U, 0U};
static int ng5[] = {4, 0};
static unsigned int ng6[] = {74U, 0U};
static int ng7[] = {1, 0};
static unsigned int ng8[] = {32U, 0U};
static unsigned int ng9[] = {96U, 0U};
static unsigned int ng10[] = {31U, 0U};
static int ng11[] = {1413567557, 0, 1398038355, 0, 1381523282, 0, 0, 0, 0, 0};
static int ng12[] = {1598314293, 0, 1465005620, 0, 1296387423, 0, 5396575, 0, 0, 0};
static int ng13[] = {541413970, 0, 1413567557, 0, 842539091, 0, 1229922353, 0, 80, 0};



static void Cont_147_0(char *t0)
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

LAB0:    t1 = (t0 + 11648U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(147, ng0);
    t2 = (t0 + 8336);
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
    t14 = (t0 + 13864);
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
    t27 = (t0 + 13704);
    *((int *)t27) = 1;

LAB1:    return;
}

static void NetDecl_169_1(char *t0)
{
    char t3[32];
    char t4[8];
    char t13[8];
    char t23[8];
    char t33[8];
    char t43[8];
    char t54[8];
    char t65[8];
    char t76[8];
    char t87[8];
    char t98[8];
    char t109[8];
    char t120[8];
    char t131[8];
    char t142[8];
    char t153[8];
    char t164[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t14;
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
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t88;
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
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t121;
    char *t122;
    char *t123;
    char *t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    char *t143;
    char *t144;
    char *t145;
    char *t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    char *t154;
    char *t155;
    char *t156;
    char *t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    char *t165;
    char *t166;
    char *t167;
    char *t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    char *t175;
    char *t176;
    char *t177;
    char *t178;
    char *t179;
    char *t180;

LAB0:    t1 = (t0 + 11896U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 3296U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 24);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 24);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t11 & 255U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 255U);
    t14 = (t0 + 3296U);
    t15 = *((char **)t14);
    memset(t13, 0, 8);
    t14 = (t13 + 4);
    t16 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = (t17 >> 16);
    *((unsigned int *)t13) = t18;
    t19 = *((unsigned int *)t16);
    t20 = (t19 >> 16);
    *((unsigned int *)t14) = t20;
    t21 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t21 & 255U);
    t22 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t22 & 255U);
    t24 = (t0 + 3296U);
    t25 = *((char **)t24);
    memset(t23, 0, 8);
    t24 = (t23 + 4);
    t26 = (t25 + 4);
    t27 = *((unsigned int *)t25);
    t28 = (t27 >> 8);
    *((unsigned int *)t23) = t28;
    t29 = *((unsigned int *)t26);
    t30 = (t29 >> 8);
    *((unsigned int *)t24) = t30;
    t31 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t31 & 255U);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t32 & 255U);
    t34 = (t0 + 3296U);
    t35 = *((char **)t34);
    memset(t33, 0, 8);
    t34 = (t33 + 4);
    t36 = (t35 + 4);
    t37 = *((unsigned int *)t35);
    t38 = (t37 >> 0);
    *((unsigned int *)t33) = t38;
    t39 = *((unsigned int *)t36);
    t40 = (t39 >> 0);
    *((unsigned int *)t34) = t40;
    t41 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t41 & 255U);
    t42 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t42 & 255U);
    t44 = (t0 + 3296U);
    t45 = *((char **)t44);
    memset(t43, 0, 8);
    t44 = (t43 + 4);
    t46 = (t45 + 8);
    t47 = (t45 + 12);
    t48 = *((unsigned int *)t46);
    t49 = (t48 >> 24);
    *((unsigned int *)t43) = t49;
    t50 = *((unsigned int *)t47);
    t51 = (t50 >> 24);
    *((unsigned int *)t44) = t51;
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t52 & 255U);
    t53 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t53 & 255U);
    t55 = (t0 + 3296U);
    t56 = *((char **)t55);
    memset(t54, 0, 8);
    t55 = (t54 + 4);
    t57 = (t56 + 8);
    t58 = (t56 + 12);
    t59 = *((unsigned int *)t57);
    t60 = (t59 >> 16);
    *((unsigned int *)t54) = t60;
    t61 = *((unsigned int *)t58);
    t62 = (t61 >> 16);
    *((unsigned int *)t55) = t62;
    t63 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t63 & 255U);
    t64 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t64 & 255U);
    t66 = (t0 + 3296U);
    t67 = *((char **)t66);
    memset(t65, 0, 8);
    t66 = (t65 + 4);
    t68 = (t67 + 8);
    t69 = (t67 + 12);
    t70 = *((unsigned int *)t68);
    t71 = (t70 >> 8);
    *((unsigned int *)t65) = t71;
    t72 = *((unsigned int *)t69);
    t73 = (t72 >> 8);
    *((unsigned int *)t66) = t73;
    t74 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t74 & 255U);
    t75 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t75 & 255U);
    t77 = (t0 + 3296U);
    t78 = *((char **)t77);
    memset(t76, 0, 8);
    t77 = (t76 + 4);
    t79 = (t78 + 8);
    t80 = (t78 + 12);
    t81 = *((unsigned int *)t79);
    t82 = (t81 >> 0);
    *((unsigned int *)t76) = t82;
    t83 = *((unsigned int *)t80);
    t84 = (t83 >> 0);
    *((unsigned int *)t77) = t84;
    t85 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t85 & 255U);
    t86 = *((unsigned int *)t77);
    *((unsigned int *)t77) = (t86 & 255U);
    t88 = (t0 + 3296U);
    t89 = *((char **)t88);
    memset(t87, 0, 8);
    t88 = (t87 + 4);
    t90 = (t89 + 16);
    t91 = (t89 + 20);
    t92 = *((unsigned int *)t90);
    t93 = (t92 >> 24);
    *((unsigned int *)t87) = t93;
    t94 = *((unsigned int *)t91);
    t95 = (t94 >> 24);
    *((unsigned int *)t88) = t95;
    t96 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t96 & 255U);
    t97 = *((unsigned int *)t88);
    *((unsigned int *)t88) = (t97 & 255U);
    t99 = (t0 + 3296U);
    t100 = *((char **)t99);
    memset(t98, 0, 8);
    t99 = (t98 + 4);
    t101 = (t100 + 16);
    t102 = (t100 + 20);
    t103 = *((unsigned int *)t101);
    t104 = (t103 >> 16);
    *((unsigned int *)t98) = t104;
    t105 = *((unsigned int *)t102);
    t106 = (t105 >> 16);
    *((unsigned int *)t99) = t106;
    t107 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t107 & 255U);
    t108 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t108 & 255U);
    t110 = (t0 + 3296U);
    t111 = *((char **)t110);
    memset(t109, 0, 8);
    t110 = (t109 + 4);
    t112 = (t111 + 16);
    t113 = (t111 + 20);
    t114 = *((unsigned int *)t112);
    t115 = (t114 >> 8);
    *((unsigned int *)t109) = t115;
    t116 = *((unsigned int *)t113);
    t117 = (t116 >> 8);
    *((unsigned int *)t110) = t117;
    t118 = *((unsigned int *)t109);
    *((unsigned int *)t109) = (t118 & 255U);
    t119 = *((unsigned int *)t110);
    *((unsigned int *)t110) = (t119 & 255U);
    t121 = (t0 + 3296U);
    t122 = *((char **)t121);
    memset(t120, 0, 8);
    t121 = (t120 + 4);
    t123 = (t122 + 16);
    t124 = (t122 + 20);
    t125 = *((unsigned int *)t123);
    t126 = (t125 >> 0);
    *((unsigned int *)t120) = t126;
    t127 = *((unsigned int *)t124);
    t128 = (t127 >> 0);
    *((unsigned int *)t121) = t128;
    t129 = *((unsigned int *)t120);
    *((unsigned int *)t120) = (t129 & 255U);
    t130 = *((unsigned int *)t121);
    *((unsigned int *)t121) = (t130 & 255U);
    t132 = (t0 + 3296U);
    t133 = *((char **)t132);
    memset(t131, 0, 8);
    t132 = (t131 + 4);
    t134 = (t133 + 24);
    t135 = (t133 + 28);
    t136 = *((unsigned int *)t134);
    t137 = (t136 >> 24);
    *((unsigned int *)t131) = t137;
    t138 = *((unsigned int *)t135);
    t139 = (t138 >> 24);
    *((unsigned int *)t132) = t139;
    t140 = *((unsigned int *)t131);
    *((unsigned int *)t131) = (t140 & 255U);
    t141 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t141 & 255U);
    t143 = (t0 + 3296U);
    t144 = *((char **)t143);
    memset(t142, 0, 8);
    t143 = (t142 + 4);
    t145 = (t144 + 24);
    t146 = (t144 + 28);
    t147 = *((unsigned int *)t145);
    t148 = (t147 >> 16);
    *((unsigned int *)t142) = t148;
    t149 = *((unsigned int *)t146);
    t150 = (t149 >> 16);
    *((unsigned int *)t143) = t150;
    t151 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t151 & 255U);
    t152 = *((unsigned int *)t143);
    *((unsigned int *)t143) = (t152 & 255U);
    t154 = (t0 + 3296U);
    t155 = *((char **)t154);
    memset(t153, 0, 8);
    t154 = (t153 + 4);
    t156 = (t155 + 24);
    t157 = (t155 + 28);
    t158 = *((unsigned int *)t156);
    t159 = (t158 >> 8);
    *((unsigned int *)t153) = t159;
    t160 = *((unsigned int *)t157);
    t161 = (t160 >> 8);
    *((unsigned int *)t154) = t161;
    t162 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t162 & 255U);
    t163 = *((unsigned int *)t154);
    *((unsigned int *)t154) = (t163 & 255U);
    t165 = (t0 + 3296U);
    t166 = *((char **)t165);
    memset(t164, 0, 8);
    t165 = (t164 + 4);
    t167 = (t166 + 24);
    t168 = (t166 + 28);
    t169 = *((unsigned int *)t167);
    t170 = (t169 >> 0);
    *((unsigned int *)t164) = t170;
    t171 = *((unsigned int *)t168);
    t172 = (t171 >> 0);
    *((unsigned int *)t165) = t172;
    t173 = *((unsigned int *)t164);
    *((unsigned int *)t164) = (t173 & 255U);
    t174 = *((unsigned int *)t165);
    *((unsigned int *)t165) = (t174 & 255U);
    xsi_vlogtype_concat(t3, 128, 128, 16U, t164, 8, t153, 8, t142, 8, t131, 8, t120, 8, t109, 8, t98, 8, t87, 8, t76, 8, t65, 8, t54, 8, t43, 8, t33, 8, t23, 8, t13, 8, t4, 8);
    t175 = (t0 + 13928);
    t176 = (t175 + 56U);
    t177 = *((char **)t176);
    t178 = (t177 + 56U);
    t179 = *((char **)t178);
    xsi_vlog_bit_copy(t179, 0, t3, 0, 128);
    xsi_driver_vfirst_trans(t175, 0, 127U);
    t180 = (t0 + 13720);
    *((int *)t180) = 1;

LAB1:    return;
}

static void Always_187_2(char *t0)
{
    char t4[8];
    char t21[8];
    char t36[8];
    char t45[8];
    char t52[16];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
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
    char *t19;
    char *t20;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    int t35;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;

LAB0:    t1 = (t0 + 12144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(187, ng0);
    t2 = (t0 + 13736);
    *((int *)t2) = 1;
    t3 = (t0 + 12176);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(187, ng0);

LAB5:    xsi_set_current_line(188, ng0);
    t5 = (t0 + 2976U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(213, ng0);

LAB14:    xsi_set_current_line(214, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8016);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(215, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 8176);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(216, ng0);
    t2 = (t0 + 8176);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 8336);
    t12 = (t6 + 56U);
    t13 = *((char **)t12);
    memset(t21, 0, 8);
    t19 = (t21 + 4);
    t20 = (t13 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (t7 >> 0);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t20);
    t10 = (t9 >> 0);
    *((unsigned int *)t19) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 7U);
    t14 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t14 & 7U);
    xsi_vlogtype_concat(t4, 4, 4, 2U, t21, 3, t5, 1);
    t22 = (t0 + 8336);
    xsi_vlogvar_wait_assign_value(t22, t4, 0, 0, 4, 1000LL);
    xsi_set_current_line(217, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 9136);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(218, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 8656);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(224, ng0);
    t2 = (t0 + 4736U);
    t3 = *((char **)t2);
    t2 = (t0 + 9616);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 128, 1000LL);
    xsi_set_current_line(225, ng0);
    t2 = (t0 + 9616);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 9776);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 128, 1000LL);
    xsi_set_current_line(226, ng0);
    t2 = (t0 + 9776);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 9936);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 128, 1000LL);
    xsi_set_current_line(227, ng0);
    t2 = (t0 + 9136);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 9296);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 1000LL);
    xsi_set_current_line(228, ng0);
    t2 = (t0 + 9296);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 9456);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 1000LL);
    xsi_set_current_line(229, ng0);
    t2 = (t0 + 10256);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t4, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1023U);
    if (t11 != 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t6) != 0)
        goto LAB17;

LAB18:    t13 = (t0 + 5456);
    xsi_vlogvar_wait_assign_value(t13, t4, 0, 0, 1, 1000LL);
    xsi_set_current_line(230, ng0);
    t2 = (t0 + 9936);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 5136);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 128, 1000LL);
    xsi_set_current_line(231, ng0);
    t2 = (t0 + 10096);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 10416);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 10, 1000LL);
    xsi_set_current_line(232, ng0);
    t2 = (t0 + 9456);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(234, ng0);
    t2 = (t0 + 10256);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t4, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1023U);
    if (t11 != 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t6) != 0)
        goto LAB25;

LAB26:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(240, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5456);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);

LAB29:
LAB21:    xsi_set_current_line(242, ng0);
    t2 = (t0 + 8656);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB38;

LAB39:
LAB40:    xsi_set_current_line(248, ng0);
    t2 = (t0 + 8816);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);

LAB42:    t6 = ((char*)((ng2)));
    t35 = xsi_vlog_unsigned_case_compare(t5, 7, t6, 7);
    if (t35 == 1)
        goto LAB43;

LAB44:
LAB45:
LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(188, ng0);

LAB13:    xsi_set_current_line(190, ng0);
    t19 = ((char*)((ng1)));
    t20 = (t0 + 8176);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 1, 1000LL);
    xsi_set_current_line(191, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8336);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 1000LL);
    xsi_set_current_line(192, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5936);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(193, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6096);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 1000LL);
    xsi_set_current_line(194, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6256);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(195, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6416);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(196, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6576);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 1000LL);
    xsi_set_current_line(197, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6736);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 1000LL);
    xsi_set_current_line(198, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6896);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 1000LL);
    xsi_set_current_line(199, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 7056);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 1000LL);
    xsi_set_current_line(200, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 7216);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 1000LL);
    xsi_set_current_line(201, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 64, 1000LL);
    xsi_set_current_line(202, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 7696);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 1000LL);
    xsi_set_current_line(203, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 7536);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 64, 1000LL);
    xsi_set_current_line(204, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 7856);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 1000LL);
    xsi_set_current_line(205, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8016);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(206, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 9136);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(207, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5456);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(208, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 10256);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 1000LL);
    xsi_set_current_line(209, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 8656);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(211, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8816);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 1000LL);
    xsi_set_current_line(212, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8976);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 1000LL);
    goto LAB12;

LAB15:    *((unsigned int *)t4) = 1;
    goto LAB18;

LAB17:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB18;

LAB19:    xsi_set_current_line(232, ng0);

LAB22:    xsi_set_current_line(233, ng0);
    t12 = (t0 + 10416);
    t13 = (t12 + 56U);
    t19 = *((char **)t13);
    t20 = (t0 + 10256);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 10, 1000LL);
    goto LAB21;

LAB23:    *((unsigned int *)t4) = 1;
    goto LAB26;

LAB25:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB26;

LAB27:    xsi_set_current_line(235, ng0);
    t19 = (t0 + 10256);
    t20 = (t19 + 56U);
    t22 = *((char **)t20);
    t23 = ((char*)((ng5)));
    memset(t21, 0, 8);
    t24 = (t22 + 4);
    if (*((unsigned int *)t24) != 0)
        goto LAB31;

LAB30:    t25 = (t23 + 4);
    if (*((unsigned int *)t25) != 0)
        goto LAB31;

LAB34:    if (*((unsigned int *)t22) < *((unsigned int *)t23))
        goto LAB32;

LAB33:    t27 = (t21 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t21);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB35;

LAB36:    xsi_set_current_line(238, ng0);
    t2 = (t0 + 10256);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_minus(t4, 32, t5, 10, t6, 32);
    t12 = (t0 + 10256);
    xsi_vlogvar_wait_assign_value(t12, t4, 0, 0, 10, 1000LL);

LAB37:    goto LAB29;

LAB31:    t26 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB33;

LAB32:    *((unsigned int *)t21) = 1;
    goto LAB33;

LAB35:    xsi_set_current_line(236, ng0);
    t33 = ((char*)((ng1)));
    t34 = (t0 + 10256);
    xsi_vlogvar_wait_assign_value(t34, t33, 0, 0, 10, 0LL);
    goto LAB37;

LAB38:    xsi_set_current_line(242, ng0);

LAB41:    xsi_set_current_line(243, ng0);
    t12 = (t0 + 8496);
    t13 = (t12 + 56U);
    t19 = *((char **)t13);
    t20 = (t0 + 7536);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 64, 1000LL);
    xsi_set_current_line(244, ng0);
    t2 = (t0 + 4736U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 0);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t11 & 4294967295U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 4294967295U);
    t6 = (t0 + 7856);
    xsi_vlogvar_wait_assign_value(t6, t4, 0, 0, 32, 1000LL);
    xsi_set_current_line(245, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 8016);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    goto LAB40;

LAB43:    xsi_set_current_line(250, ng0);

LAB46:    xsi_set_current_line(252, ng0);
    t12 = ((char*)((ng2)));
    t13 = (t0 + 8816);
    xsi_vlogvar_wait_assign_value(t13, t12, 0, 0, 7, 1000LL);
    xsi_set_current_line(253, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5936);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(256, ng0);
    t2 = (t0 + 3456U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB47;

LAB48:    xsi_set_current_line(315, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8816);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 1000LL);

LAB49:    goto LAB45;

LAB47:    xsi_set_current_line(256, ng0);

LAB50:    xsi_set_current_line(257, ng0);
    t6 = (t0 + 3136U);
    t12 = *((char **)t6);
    memset(t4, 0, 8);
    t6 = (t4 + 4);
    t13 = (t12 + 8);
    t19 = (t12 + 12);
    t14 = *((unsigned int *)t13);
    t15 = (t14 >> 16);
    *((unsigned int *)t4) = t15;
    t16 = *((unsigned int *)t19);
    t17 = (t16 >> 16);
    *((unsigned int *)t6) = t17;
    t18 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t18 & 65535U);
    t28 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t28 & 65535U);
    t20 = (t0 + 8976);
    xsi_vlogvar_wait_assign_value(t20, t4, 0, 0, 7, 1000LL);
    xsi_set_current_line(259, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t6 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 24);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 24);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t11 & 127U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 127U);

LAB51:    t12 = ((char*)((ng6)));
    t35 = xsi_vlog_unsigned_case_compare(t4, 7, t12, 7);
    if (t35 == 1)
        goto LAB52;

LAB53:    t2 = ((char*)((ng8)));
    t35 = xsi_vlog_unsigned_case_compare(t4, 7, t2, 7);
    if (t35 == 1)
        goto LAB54;

LAB55:    t2 = ((char*)((ng9)));
    t35 = xsi_vlog_unsigned_case_compare(t4, 7, t2, 7);
    if (t35 == 1)
        goto LAB56;

LAB57:
LAB58:    goto LAB49;

LAB52:    xsi_set_current_line(261, ng0);

LAB59:    xsi_set_current_line(264, ng0);
    t13 = (t0 + 3136U);
    t19 = *((char **)t13);
    memset(t21, 0, 8);
    t13 = (t21 + 4);
    t20 = (t19 + 4);
    t15 = *((unsigned int *)t19);
    t16 = (t15 >> 0);
    *((unsigned int *)t21) = t16;
    t17 = *((unsigned int *)t20);
    t18 = (t17 >> 0);
    *((unsigned int *)t13) = t18;
    t28 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t28 & 1023U);
    t29 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t29 & 1023U);
    t22 = (t0 + 10096);
    xsi_vlogvar_wait_assign_value(t22, t21, 0, 0, 10, 1000LL);
    xsi_set_current_line(265, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 9136);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(266, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 16);
    t12 = (t3 + 20);
    t7 = *((unsigned int *)t6);
    t8 = (t7 >> 16);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 16);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 65535U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 65535U);
    t13 = (t0 + 5776);
    xsi_vlogvar_wait_assign_value(t13, t21, 0, 0, 16, 1000LL);
    goto LAB58;

LAB54:    xsi_set_current_line(272, ng0);

LAB60:    xsi_set_current_line(274, ng0);
    t3 = (t0 + 3136U);
    t6 = *((char **)t3);
    memset(t21, 0, 8);
    t3 = (t21 + 4);
    t12 = (t6 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (t7 >> 0);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 0);
    *((unsigned int *)t3) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 1023U);
    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 1023U);
    t13 = ((char*)((ng3)));
    memset(t36, 0, 8);
    t19 = (t21 + 4);
    t20 = (t13 + 4);
    t15 = *((unsigned int *)t21);
    t16 = *((unsigned int *)t13);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t19);
    t28 = *((unsigned int *)t20);
    t29 = (t18 ^ t28);
    t30 = (t17 | t29);
    t31 = *((unsigned int *)t19);
    t32 = *((unsigned int *)t20);
    t37 = (t31 | t32);
    t38 = (~(t37));
    t39 = (t30 & t38);
    if (t39 != 0)
        goto LAB64;

LAB61:    if (t37 != 0)
        goto LAB63;

LAB62:    *((unsigned int *)t36) = 1;

LAB64:    t23 = (t36 + 4);
    t40 = *((unsigned int *)t23);
    t41 = (~(t40));
    t42 = *((unsigned int *)t36);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB65;

LAB66:    xsi_set_current_line(292, ng0);

LAB69:    xsi_set_current_line(293, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8816);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 1000LL);

LAB67:    goto LAB58;

LAB56:    xsi_set_current_line(297, ng0);

LAB70:    xsi_set_current_line(298, ng0);
    t3 = (t0 + 3136U);
    t6 = *((char **)t3);
    memset(t21, 0, 8);
    t3 = (t21 + 4);
    t12 = (t6 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (t7 >> 0);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 0);
    *((unsigned int *)t3) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 1023U);
    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 1023U);
    t13 = ((char*)((ng3)));
    memset(t36, 0, 8);
    t19 = (t21 + 4);
    t20 = (t13 + 4);
    t15 = *((unsigned int *)t21);
    t16 = *((unsigned int *)t13);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t19);
    t28 = *((unsigned int *)t20);
    t29 = (t18 ^ t28);
    t30 = (t17 | t29);
    t31 = *((unsigned int *)t19);
    t32 = *((unsigned int *)t20);
    t37 = (t31 | t32);
    t38 = (~(t37));
    t39 = (t30 & t38);
    if (t39 != 0)
        goto LAB74;

LAB71:    if (t37 != 0)
        goto LAB73;

LAB72:    *((unsigned int *)t36) = 1;

LAB74:    t23 = (t36 + 4);
    t40 = *((unsigned int *)t23);
    t41 = (~(t40));
    t42 = *((unsigned int *)t36);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB75;

LAB76:    xsi_set_current_line(309, ng0);

LAB88:    xsi_set_current_line(310, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8816);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 1000LL);

LAB77:    goto LAB58;

LAB63:    t22 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB64;

LAB65:    xsi_set_current_line(274, ng0);

LAB68:    xsi_set_current_line(275, ng0);
    t24 = (t0 + 3136U);
    t25 = *((char **)t24);
    memset(t45, 0, 8);
    t24 = (t45 + 4);
    t26 = (t25 + 4);
    t46 = *((unsigned int *)t25);
    t47 = (t46 >> 20);
    *((unsigned int *)t45) = t47;
    t48 = *((unsigned int *)t26);
    t49 = (t48 >> 20);
    *((unsigned int *)t24) = t49;
    t50 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t50 & 7U);
    t51 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t51 & 7U);
    t27 = (t0 + 6096);
    xsi_vlogvar_wait_assign_value(t27, t45, 0, 0, 3, 1000LL);
    xsi_set_current_line(276, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 15);
    t9 = (t8 & 1);
    *((unsigned int *)t21) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 15);
    t14 = (t11 & 1);
    *((unsigned int *)t2) = t14;
    t12 = (t0 + 6256);
    xsi_vlogvar_wait_assign_value(t12, t21, 0, 0, 1, 1000LL);
    xsi_set_current_line(277, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 14);
    t9 = (t8 & 1);
    *((unsigned int *)t21) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 14);
    t14 = (t11 & 1);
    *((unsigned int *)t2) = t14;
    t12 = (t0 + 6416);
    xsi_vlogvar_wait_assign_value(t12, t21, 0, 0, 1, 1000LL);
    xsi_set_current_line(278, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 12);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 12);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 3U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 3U);
    t12 = (t0 + 6576);
    xsi_vlogvar_wait_assign_value(t12, t21, 0, 0, 2, 1000LL);
    xsi_set_current_line(279, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 0);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 1023U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 1023U);
    t12 = (t0 + 6736);
    xsi_vlogvar_wait_assign_value(t12, t21, 0, 0, 10, 1000LL);
    xsi_set_current_line(280, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 8);
    t12 = (t3 + 12);
    t7 = *((unsigned int *)t6);
    t8 = (t7 >> 16);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 16);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 65535U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 65535U);
    t13 = (t0 + 6896);
    xsi_vlogvar_wait_assign_value(t13, t21, 0, 0, 16, 1000LL);
    xsi_set_current_line(281, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 8);
    t12 = (t3 + 12);
    t7 = *((unsigned int *)t6);
    t8 = (t7 >> 8);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 8);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 255U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 255U);
    t13 = (t0 + 7056);
    xsi_vlogvar_wait_assign_value(t13, t21, 0, 0, 8, 1000LL);
    xsi_set_current_line(282, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 8);
    t12 = (t3 + 12);
    t7 = *((unsigned int *)t6);
    t8 = (t7 >> 0);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 255U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 255U);
    t13 = (t0 + 7216);
    xsi_vlogvar_wait_assign_value(t13, t21, 0, 0, 8, 1000LL);
    xsi_set_current_line(288, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3136U);
    t6 = *((char **)t3);
    memset(t21, 0, 8);
    t3 = (t21 + 4);
    t12 = (t6 + 16);
    t13 = (t6 + 20);
    t7 = *((unsigned int *)t12);
    t8 = (t7 >> 2);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t13);
    t10 = (t9 >> 2);
    *((unsigned int *)t3) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 1073741823U);
    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 1073741823U);
    t19 = ((char*)((ng2)));
    xsi_vlogtype_concat(t52, 64, 64, 3U, t19, 32, t21, 30, t2, 2);
    t20 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t20, t52, 0, 0, 64, 1000LL);
    xsi_set_current_line(289, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 8176);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(290, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5936);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(291, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8816);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 1000LL);
    goto LAB67;

LAB73:    t22 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB74;

LAB75:    xsi_set_current_line(298, ng0);

LAB78:    xsi_set_current_line(299, ng0);
    t24 = (t0 + 3136U);
    t25 = *((char **)t24);
    memset(t45, 0, 8);
    t24 = (t45 + 4);
    t26 = (t25 + 8);
    t27 = (t25 + 12);
    t46 = *((unsigned int *)t26);
    t47 = (t46 >> 0);
    *((unsigned int *)t45) = t47;
    t48 = *((unsigned int *)t27);
    t49 = (t48 >> 0);
    *((unsigned int *)t24) = t49;
    t50 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t50 & 255U);
    t51 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t51 & 255U);
    t33 = (t0 + 7696);
    xsi_vlogvar_wait_assign_value(t33, t45, 0, 0, 8, 1000LL);
    xsi_set_current_line(300, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t21, 0, 8);
    t2 = (t21 + 4);
    t6 = (t3 + 8);
    t12 = (t3 + 12);
    t7 = *((unsigned int *)t6);
    t8 = (t7 >> 8);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t12);
    t10 = (t9 >> 8);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 255U);
    t14 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t14 & 255U);
    t13 = ((char*)((ng10)));
    memset(t36, 0, 8);
    t19 = (t21 + 4);
    t20 = (t13 + 4);
    t15 = *((unsigned int *)t21);
    t16 = *((unsigned int *)t13);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t19);
    t28 = *((unsigned int *)t20);
    t29 = (t18 ^ t28);
    t30 = (t17 | t29);
    t31 = *((unsigned int *)t19);
    t32 = *((unsigned int *)t20);
    t37 = (t31 | t32);
    t38 = (~(t37));
    t39 = (t30 & t38);
    if (t39 != 0)
        goto LAB82;

LAB79:    if (t37 != 0)
        goto LAB81;

LAB80:    *((unsigned int *)t36) = 1;

LAB82:    t23 = (t36 + 4);
    t40 = *((unsigned int *)t23);
    t41 = (~(t40));
    t42 = *((unsigned int *)t36);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB83;

LAB84:    xsi_set_current_line(302, ng0);

LAB87:
LAB85:    xsi_set_current_line(306, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3136U);
    t6 = *((char **)t3);
    memset(t21, 0, 8);
    t3 = (t21 + 4);
    t12 = (t6 + 16);
    t13 = (t6 + 20);
    t7 = *((unsigned int *)t12);
    t8 = (t7 >> 2);
    *((unsigned int *)t21) = t8;
    t9 = *((unsigned int *)t13);
    t10 = (t9 >> 2);
    *((unsigned int *)t3) = t10;
    t11 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t11 & 1073741823U);
    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 1073741823U);
    t19 = ((char*)((ng2)));
    xsi_vlogtype_concat(t52, 64, 64, 3U, t19, 32, t21, 30, t2, 2);
    t20 = (t0 + 8496);
    xsi_vlogvar_wait_assign_value(t20, t52, 0, 0, 64, 1000LL);
    xsi_set_current_line(307, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 8656);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 1000LL);
    xsi_set_current_line(308, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8816);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 1000LL);
    goto LAB77;

LAB81:    t22 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB82;

LAB83:    xsi_set_current_line(300, ng0);

LAB86:    goto LAB85;

}

static void Cont_325_3(char *t0)
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

LAB0:    t1 = (t0 + 12392U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(325, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 13992);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
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
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void Cont_326_4(char *t0)
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

LAB0:    t1 = (t0 + 12640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(326, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 14056);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
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
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void Cont_327_5(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
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
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;

LAB0:    t1 = (t0 + 12888U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(327, ng0);
    t2 = (t0 + 3616U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 14120);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 1U;
    t18 = t17;
    t19 = (t4 + 4);
    t20 = *((unsigned int *)t4);
    t17 = (t17 & t20);
    t21 = *((unsigned int *)t19);
    t18 = (t18 & t21);
    t22 = (t16 + 4);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 | t17);
    t24 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t24 | t18);
    xsi_driver_vfirst_trans(t12, 0, 0);
    t25 = (t0 + 13752);
    *((int *)t25) = 1;

LAB1:    return;
}

static void Cont_328_6(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
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
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;

LAB0:    t1 = (t0 + 13136U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(328, ng0);
    t2 = (t0 + 3616U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 6);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 6);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 14184);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memset(t16, 0, 8);
    t17 = 1U;
    t18 = t17;
    t19 = (t4 + 4);
    t20 = *((unsigned int *)t4);
    t17 = (t17 & t20);
    t21 = *((unsigned int *)t19);
    t18 = (t18 & t21);
    t22 = (t16 + 4);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 | t17);
    t24 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t24 | t18);
    xsi_driver_vfirst_trans(t12, 0, 0);
    t25 = (t0 + 13768);
    *((int *)t25) = 1;

LAB1:    return;
}

static void Always_333_7(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
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
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;

LAB0:    t1 = (t0 + 13384U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(333, ng0);
    t2 = (t0 + 13784);
    *((int *)t2) = 1;
    t3 = (t0 + 13416);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(334, ng0);

LAB5:    xsi_set_current_line(335, ng0);
    t4 = (t0 + 8816);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng2)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB9;

LAB6:    if (t20 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB9:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(340, ng0);
    t2 = (t0 + 8816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB16;

LAB13:    if (t20 != 0)
        goto LAB15;

LAB14:    *((unsigned int *)t8) = 1;

LAB16:    t10 = (t8 + 4);
    t25 = *((unsigned int *)t10);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB17;

LAB18:    xsi_set_current_line(343, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 10736);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 160, 1000LL);

LAB19:
LAB12:    goto LAB2;

LAB8:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(335, ng0);
    t30 = ((char*)((ng11)));
    t31 = (t0 + 10736);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 160, 1000LL);
    goto LAB12;

LAB15:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB16;

LAB17:    xsi_set_current_line(340, ng0);
    t23 = ((char*)((ng12)));
    t24 = (t0 + 10736);
    xsi_vlogvar_wait_assign_value(t24, t23, 0, 0, 160, 1000LL);
    goto LAB19;

}


extern void work_m_07112399439087683317_1817275192_init()
{
	static char *pe[] = {(void *)Cont_147_0,(void *)NetDecl_169_1,(void *)Always_187_2,(void *)Cont_325_3,(void *)Cont_326_4,(void *)Cont_327_5,(void *)Cont_328_6,(void *)Always_333_7};
	xsi_register_didat("work_m_07112399439087683317_1817275192", "isim/PicoTestbench_isim_beh.exe.sim/work/m_07112399439087683317_1817275192.didat");
	xsi_register_executes(pe);
}
