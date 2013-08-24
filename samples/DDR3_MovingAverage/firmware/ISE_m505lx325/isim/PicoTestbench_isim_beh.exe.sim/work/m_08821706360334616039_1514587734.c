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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/samples/DDR3_MovingAverage/firmware/ISE_m505lx325/source/coregen-LX325T/mig_M505_DDR3/rtl/axi/mig_7series_v1_8_axi_mc_cmd_translator.v";
static int ng1[] = {4, 0};
static int ng2[] = {3, 0};
static unsigned int ng3[] = {1073741816U, 0U, 0U, 0U};
static int ng4[] = {2, 0};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {1U, 0U};



static void Cont_149_0(char *t0)
{
    char t3[16];
    char t4[8];
    char t6[8];
    char t21[8];
    char t22[16];
    char t24[16];
    char t89[8];
    char t90[16];
    char t92[16];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    int t63;
    int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    unsigned int t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    char *t87;
    char *t88;
    char *t91;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    char *t96;
    char *t97;
    char *t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    char *t104;
    unsigned int t105;
    char *t106;
    unsigned int t107;
    char *t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    unsigned int t118;
    char *t119;
    char *t120;
    unsigned int t121;
    char *t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    int t131;
    int t132;
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
    unsigned int t144;
    unsigned int t145;
    char *t146;
    unsigned int t147;
    unsigned int t148;
    char *t149;
    char *t150;
    char *t151;
    char *t152;
    char *t153;
    char *t154;
    char *t155;

LAB0:    t1 = (t0 + 8040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(149, ng0);
    t2 = (t0 + 1016);
    t5 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_signed_equal(t6, 32, t5, 32, t2, 32);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t82 = *((unsigned int *)t4);
    t83 = (~(t82));
    t84 = *((unsigned int *)t14);
    t85 = (t83 || t84);
    if (t85 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t92, 16);

LAB16:    t150 = (t0 + 11080);
    t151 = (t150 + 56U);
    t152 = *((char **)t151);
    t153 = (t152 + 56U);
    t154 = *((char **)t153);
    xsi_vlog_bit_copy(t154, 0, t3, 0, 30);
    xsi_driver_vfirst_trans(t150, 0, 29);
    t155 = (t0 + 10840);
    *((int *)t155) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 4488U);
    t19 = *((char **)t18);
    t18 = (t0 + 1152);
    t20 = *((char **)t18);
    t18 = ((char*)((ng2)));
    memset(t21, 0, 8);
    xsi_vlog_signed_minus(t21, 32, t20, 32, t18, 32);
    xsi_vlog_unsigned_rshift(t22, 33, t19, 33, t21, 32);
    t23 = ((char*)((ng3)));
    t25 = 0;

LAB20:    t26 = (t25 < 1);
    if (t26 == 1)
        goto LAB21;

LAB22:    t25 = 1;

LAB23:    t71 = (t25 < 2);
    if (t71 == 1)
        goto LAB24;

LAB29:    goto LAB9;

LAB10:    t86 = (t0 + 4488U);
    t87 = *((char **)t86);
    t86 = (t0 + 1152);
    t88 = *((char **)t86);
    t86 = ((char*)((ng4)));
    memset(t89, 0, 8);
    xsi_vlog_signed_minus(t89, 32, t88, 32, t86, 32);
    xsi_vlog_unsigned_rshift(t90, 33, t87, 33, t89, 32);
    t91 = ((char*)((ng3)));
    t93 = 0;

LAB33:    t94 = (t93 < 1);
    if (t94 == 1)
        goto LAB34;

LAB35:    t93 = 1;

LAB36:    t139 = (t93 < 2);
    if (t139 == 1)
        goto LAB37;

LAB42:    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 33, t24, 33, t92, 33);
    goto LAB16;

LAB14:    memcpy(t3, t24, 16);
    goto LAB16;

LAB17:    t46 = (t25 * 8);
    t47 = *((unsigned int *)t30);
    t48 = *((unsigned int *)t40);
    *((unsigned int *)t30) = (t47 | t48);
    t49 = (t22 + t46);
    t50 = (t46 + 4);
    t51 = (t22 + t50);
    t52 = (t23 + t46);
    t53 = (t46 + 4);
    t54 = (t23 + t53);
    t55 = *((unsigned int *)t49);
    t56 = (~(t55));
    t57 = *((unsigned int *)t51);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = *((unsigned int *)t54);
    t62 = (~(t61));
    t63 = (t56 & t58);
    t64 = (t60 & t62);
    t65 = (~(t63));
    t66 = (~(t64));
    t67 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t67 & t65);
    t68 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t68 & t66);
    t69 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t69 & t65);
    t70 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t70 & t66);

LAB19:    t25 = (t25 + 1);
    goto LAB20;

LAB18:    goto LAB19;

LAB21:    t27 = (t25 * 8);
    t28 = (t22 + t27);
    t29 = (t23 + t27);
    t30 = (t24 + t27);
    t31 = *((unsigned int *)t28);
    t32 = *((unsigned int *)t29);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t34 = (t25 * 8);
    t35 = (t34 + 4);
    t36 = (t22 + t35);
    t37 = (t34 + 4);
    t38 = (t23 + t37);
    t39 = (t34 + 4);
    t40 = (t24 + t39);
    t41 = *((unsigned int *)t36);
    t42 = *((unsigned int *)t38);
    t43 = (t41 | t42);
    *((unsigned int *)t40) = t43;
    t44 = *((unsigned int *)t40);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB17;
    else
        goto LAB18;

LAB24:    t72 = (t25 * 8);
    t73 = (t24 + t72);
    *((unsigned int *)t73) = 0;
    t74 = (t72 + 4);
    t75 = (t24 + t74);
    *((unsigned int *)t75) = 0;
    t76 = (t25 < 2);
    if (t76 == 1)
        goto LAB25;

LAB27:    t79 = (t25 < 1);
    if (t79 == 1)
        goto LAB26;

LAB28:    t25 = (t25 + 1);
    goto LAB23;

LAB25:    t77 = (t72 + 4);
    t78 = (t22 + t77);
    *((unsigned int *)t73) = *((unsigned int *)t78);
    *((unsigned int *)t75) = *((unsigned int *)t78);
    goto LAB28;

LAB26:    t80 = (t72 + 4);
    t81 = (t23 + t80);
    *((unsigned int *)t73) = *((unsigned int *)t81);
    *((unsigned int *)t75) = *((unsigned int *)t81);
    goto LAB28;

LAB30:    t114 = (t93 * 8);
    t115 = *((unsigned int *)t98);
    t116 = *((unsigned int *)t108);
    *((unsigned int *)t98) = (t115 | t116);
    t117 = (t90 + t114);
    t118 = (t114 + 4);
    t119 = (t90 + t118);
    t120 = (t91 + t114);
    t121 = (t114 + 4);
    t122 = (t91 + t121);
    t123 = *((unsigned int *)t117);
    t124 = (~(t123));
    t125 = *((unsigned int *)t119);
    t126 = (~(t125));
    t127 = *((unsigned int *)t120);
    t128 = (~(t127));
    t129 = *((unsigned int *)t122);
    t130 = (~(t129));
    t131 = (t124 & t126);
    t132 = (t128 & t130);
    t133 = (~(t131));
    t134 = (~(t132));
    t135 = *((unsigned int *)t108);
    *((unsigned int *)t108) = (t135 & t133);
    t136 = *((unsigned int *)t108);
    *((unsigned int *)t108) = (t136 & t134);
    t137 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t137 & t133);
    t138 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t138 & t134);

LAB32:    t93 = (t93 + 1);
    goto LAB33;

LAB31:    goto LAB32;

LAB34:    t95 = (t93 * 8);
    t96 = (t90 + t95);
    t97 = (t91 + t95);
    t98 = (t92 + t95);
    t99 = *((unsigned int *)t96);
    t100 = *((unsigned int *)t97);
    t101 = (t99 & t100);
    *((unsigned int *)t98) = t101;
    t102 = (t93 * 8);
    t103 = (t102 + 4);
    t104 = (t90 + t103);
    t105 = (t102 + 4);
    t106 = (t91 + t105);
    t107 = (t102 + 4);
    t108 = (t92 + t107);
    t109 = *((unsigned int *)t104);
    t110 = *((unsigned int *)t106);
    t111 = (t109 | t110);
    *((unsigned int *)t108) = t111;
    t112 = *((unsigned int *)t108);
    t113 = (t112 != 0);
    if (t113 == 1)
        goto LAB30;
    else
        goto LAB31;

LAB37:    t140 = (t93 * 8);
    t141 = (t92 + t140);
    *((unsigned int *)t141) = 0;
    t142 = (t140 + 4);
    t143 = (t92 + t142);
    *((unsigned int *)t143) = 0;
    t144 = (t93 < 2);
    if (t144 == 1)
        goto LAB38;

LAB40:    t147 = (t93 < 1);
    if (t147 == 1)
        goto LAB39;

LAB41:    t93 = (t93 + 1);
    goto LAB36;

LAB38:    t145 = (t140 + 4);
    t146 = (t90 + t145);
    *((unsigned int *)t141) = *((unsigned int *)t146);
    *((unsigned int *)t143) = *((unsigned int *)t146);
    goto LAB41;

LAB39:    t148 = (t140 + 4);
    t149 = (t91 + t148);
    *((unsigned int *)t141) = *((unsigned int *)t149);
    *((unsigned int *)t143) = *((unsigned int *)t149);
    goto LAB41;

}

static void Cont_153_1(char *t0)
{
    char t3[16];
    char t4[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    t1 = (t0 + 8288U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(153, ng0);
    t2 = (t0 + 5288U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    memset(t4, 0, 8);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t6);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t14) != 0)
        goto LAB6;

LAB7:    t21 = (t4 + 4);
    t22 = *((unsigned int *)t4);
    t23 = *((unsigned int *)t21);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB8;

LAB9:    t27 = *((unsigned int *)t4);
    t28 = (~(t27));
    t29 = *((unsigned int *)t21);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t21) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t31, 16);

LAB16:    t25 = (t0 + 11144);
    t32 = (t25 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    xsi_vlog_bit_copy(t35, 0, t3, 0, 33);
    xsi_driver_vfirst_trans(t25, 0, 32);
    t36 = (t0 + 10856);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB7;

LAB8:    t25 = (t0 + 4968U);
    t26 = *((char **)t25);
    goto LAB9;

LAB10:    t25 = (t0 + 4648U);
    t31 = *((char **)t25);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 33, t26, 33, t31, 33);
    goto LAB16;

LAB14:    memcpy(t3, t26, 16);
    goto LAB16;

}

static void Cont_157_2(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;

LAB0:    t1 = (t0 + 8536U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(157, ng0);
    t2 = (t0 + 5288U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    memset(t4, 0, 8);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t6);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t14) != 0)
        goto LAB6;

LAB7:    t21 = (t4 + 4);
    t22 = *((unsigned int *)t4);
    t23 = *((unsigned int *)t21);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB8;

LAB9:    t27 = *((unsigned int *)t4);
    t28 = (~(t27));
    t29 = *((unsigned int *)t21);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t21) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t31, 8);

LAB16:    t25 = (t0 + 11208);
    t32 = (t25 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memset(t35, 0, 8);
    t36 = 1U;
    t37 = t36;
    t38 = (t3 + 4);
    t39 = *((unsigned int *)t3);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t38);
    t37 = (t37 & t40);
    t41 = (t35 + 4);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t42 | t36);
    t43 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t43 | t37);
    xsi_driver_vfirst_trans(t25, 0, 0);
    t44 = (t0 + 10872);
    *((int *)t44) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB7;

LAB8:    t25 = (t0 + 5768U);
    t26 = *((char **)t25);
    goto LAB9;

LAB10:    t25 = (t0 + 5448U);
    t31 = *((char **)t25);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 1, t26, 1, t31, 1);
    goto LAB16;

LAB14:    memcpy(t3, t26, 8);
    goto LAB16;

}

static void Cont_160_3(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;

LAB0:    t1 = (t0 + 8784U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 5288U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    memset(t4, 0, 8);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t6);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t14) != 0)
        goto LAB6;

LAB7:    t21 = (t4 + 4);
    t22 = *((unsigned int *)t4);
    t23 = *((unsigned int *)t21);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB8;

LAB9:    t27 = *((unsigned int *)t4);
    t28 = (~(t27));
    t29 = *((unsigned int *)t21);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t21) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t31, 8);

LAB16:    t25 = (t0 + 11272);
    t32 = (t25 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memset(t35, 0, 8);
    t36 = 1U;
    t37 = t36;
    t38 = (t3 + 4);
    t39 = *((unsigned int *)t3);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t38);
    t37 = (t37 & t40);
    t41 = (t35 + 4);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t42 | t36);
    t43 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t43 | t37);
    xsi_driver_vfirst_trans(t25, 0, 0);
    t44 = (t0 + 10888);
    *((int *)t44) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB7;

LAB8:    t25 = (t0 + 5928U);
    t26 = *((char **)t25);
    goto LAB9;

LAB10:    t25 = (t0 + 5608U);
    t31 = *((char **)t25);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 1, t26, 1, t31, 1);
    goto LAB16;

LAB14:    memcpy(t3, t26, 8);
    goto LAB16;

}

static void Cont_162_4(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;

LAB0:    t1 = (t0 + 9032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 5288U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    memset(t4, 0, 8);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t6);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t14) != 0)
        goto LAB6;

LAB7:    t21 = (t4 + 4);
    t22 = *((unsigned int *)t4);
    t23 = *((unsigned int *)t21);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB8;

LAB9:    t26 = *((unsigned int *)t4);
    t27 = (~(t26));
    t28 = *((unsigned int *)t21);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t21) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t31, 8);

LAB16:    t30 = (t0 + 11336);
    t32 = (t30 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memset(t35, 0, 8);
    t36 = 1U;
    t37 = t36;
    t38 = (t3 + 4);
    t39 = *((unsigned int *)t3);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t38);
    t37 = (t37 & t40);
    t41 = (t35 + 4);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t42 | t36);
    t43 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t43 | t37);
    xsi_driver_vfirst_trans(t30, 0, 0);
    t44 = (t0 + 10904);
    *((int *)t44) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB7;

LAB8:    t25 = ((char*)((ng5)));
    goto LAB9;

LAB10:    t30 = (t0 + 6088U);
    t31 = *((char **)t30);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 1, t25, 1, t31, 1);
    goto LAB16;

LAB14:    memcpy(t3, t25, 8);
    goto LAB16;

}

static void Always_167_5(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;

LAB0:    t1 = (t0 + 9280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(167, ng0);
    t2 = (t0 + 10920);
    *((int *)t2) = 1;
    t3 = (t0 + 9312);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(167, ng0);

LAB5:    xsi_set_current_line(168, ng0);
    t4 = (t0 + 2568U);
    t5 = *((char **)t4);
    t4 = (t0 + 3368U);
    t6 = *((char **)t4);
    t8 = *((unsigned int *)t5);
    t9 = *((unsigned int *)t6);
    t10 = (t8 | t9);
    *((unsigned int *)t7) = t10;
    t4 = (t5 + 4);
    t11 = (t6 + 4);
    t12 = (t7 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t11);
    t15 = (t13 | t14);
    *((unsigned int *)t12) = t15;
    t16 = *((unsigned int *)t12);
    t17 = (t16 != 0);
    if (t17 == 1)
        goto LAB6;

LAB7:
LAB8:    t34 = (t7 + 4);
    t35 = *((unsigned int *)t34);
    t36 = (~(t35));
    t37 = *((unsigned int *)t7);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 4168U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t13 = (t10 & t9);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB13;

LAB14:
LAB15:
LAB11:    goto LAB2;

LAB6:    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t12);
    *((unsigned int *)t7) = (t18 | t19);
    t20 = (t5 + 4);
    t21 = (t6 + 4);
    t22 = *((unsigned int *)t20);
    t23 = (~(t22));
    t24 = *((unsigned int *)t5);
    t25 = (t24 & t23);
    t26 = *((unsigned int *)t21);
    t27 = (~(t26));
    t28 = *((unsigned int *)t6);
    t29 = (t28 & t27);
    t30 = (~(t25));
    t31 = (~(t29));
    t32 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t32 & t30);
    t33 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t33 & t31);
    goto LAB8;

LAB9:    xsi_set_current_line(168, ng0);

LAB12:    xsi_set_current_line(169, ng0);
    t40 = ((char*)((ng6)));
    t41 = (t0 + 6488);
    xsi_vlogvar_wait_assign_value(t41, t40, 0, 0, 1, 0LL);
    goto LAB11;

LAB13:    xsi_set_current_line(170, ng0);

LAB16:    xsi_set_current_line(171, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 6488);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB15;

}

static void Cont_175_6(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
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
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;

LAB0:    t1 = (t0 + 9528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(175, ng0);
    t2 = (t0 + 6488);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t7) != 0)
        goto LAB6;

LAB7:    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    t20 = *((unsigned int *)t4);
    t21 = (~(t20));
    t22 = *((unsigned int *)t14);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t25, 8);

LAB16:    t26 = (t0 + 11400);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    memset(t30, 0, 8);
    t31 = 3U;
    t32 = t31;
    t33 = (t3 + 4);
    t34 = *((unsigned int *)t3);
    t31 = (t31 & t34);
    t35 = *((unsigned int *)t33);
    t32 = (t32 & t35);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t37 | t31);
    t38 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t38 | t32);
    xsi_driver_vfirst_trans(t26, 0, 1);
    t39 = (t0 + 10936);
    *((int *)t39) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 3208U);
    t19 = *((char **)t18);
    goto LAB9;

LAB10:    t18 = (t0 + 6648);
    t24 = (t18 + 56U);
    t25 = *((char **)t24);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 2, t19, 2, t25, 2);
    goto LAB16;

LAB14:    memcpy(t3, t19, 8);
    goto LAB16;

}

static void Always_177_7(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 9776U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(177, ng0);
    t2 = (t0 + 10952);
    *((int *)t2) = 1;
    t3 = (t0 + 9808);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(177, ng0);

LAB5:    xsi_set_current_line(178, ng0);
    t4 = (t0 + 5288U);
    t5 = *((char **)t4);
    t4 = (t0 + 6648);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 2, 0LL);
    goto LAB2;

}

static void Always_183_8(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;

LAB0:    t1 = (t0 + 10024U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(183, ng0);
    t2 = (t0 + 10968);
    *((int *)t2) = 1;
    t3 = (t0 + 10056);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(183, ng0);

LAB5:    xsi_set_current_line(184, ng0);
    t4 = (t0 + 2568U);
    t5 = *((char **)t4);
    t4 = (t0 + 3368U);
    t6 = *((char **)t4);
    t8 = *((unsigned int *)t5);
    t9 = *((unsigned int *)t6);
    t10 = (t8 | t9);
    *((unsigned int *)t7) = t10;
    t4 = (t5 + 4);
    t11 = (t6 + 4);
    t12 = (t7 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t11);
    t15 = (t13 | t14);
    *((unsigned int *)t12) = t15;
    t16 = *((unsigned int *)t12);
    t17 = (t16 != 0);
    if (t17 == 1)
        goto LAB6;

LAB7:
LAB8:    t34 = (t7 + 4);
    t35 = *((unsigned int *)t34);
    t36 = (~(t35));
    t37 = *((unsigned int *)t7);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(186, ng0);
    t2 = (t0 + 4168U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t13 = (t10 & t9);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB13;

LAB14:    xsi_set_current_line(188, ng0);

LAB17:    xsi_set_current_line(189, ng0);
    t2 = (t0 + 6488);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7128);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);

LAB15:
LAB11:    goto LAB2;

LAB6:    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t12);
    *((unsigned int *)t7) = (t18 | t19);
    t20 = (t5 + 4);
    t21 = (t6 + 4);
    t22 = *((unsigned int *)t20);
    t23 = (~(t22));
    t24 = *((unsigned int *)t5);
    t25 = (t24 & t23);
    t26 = *((unsigned int *)t21);
    t27 = (~(t26));
    t28 = *((unsigned int *)t6);
    t29 = (t28 & t27);
    t30 = (~(t25));
    t31 = (~(t29));
    t32 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t32 & t30);
    t33 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t33 & t31);
    goto LAB8;

LAB9:    xsi_set_current_line(184, ng0);

LAB12:    xsi_set_current_line(185, ng0);
    t40 = ((char*)((ng6)));
    t41 = (t0 + 7128);
    xsi_vlogvar_assign_value(t41, t40, 0, 0, 1);
    goto LAB11;

LAB13:    xsi_set_current_line(186, ng0);

LAB16:    xsi_set_current_line(187, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 7128);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB15;

}

static void Cont_193_9(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
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
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;

LAB0:    t1 = (t0 + 10272U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(193, ng0);
    t2 = (t0 + 3208U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    memset(t4, 0, 8);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t6);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t14) != 0)
        goto LAB6;

LAB7:    t21 = (t4 + 4);
    t22 = *((unsigned int *)t4);
    t23 = *((unsigned int *)t21);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB8;

LAB9:    t28 = *((unsigned int *)t4);
    t29 = (~(t28));
    t30 = *((unsigned int *)t21);
    t31 = (t29 || t30);
    if (t31 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t21) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t34, 8);

LAB16:    t35 = (t0 + 11464);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    memset(t39, 0, 8);
    t40 = 1U;
    t41 = t40;
    t42 = (t3 + 4);
    t43 = *((unsigned int *)t3);
    t40 = (t40 & t43);
    t44 = *((unsigned int *)t42);
    t41 = (t41 & t44);
    t45 = (t39 + 4);
    t46 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t46 | t40);
    t47 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t47 | t41);
    xsi_driver_vfirst_trans(t35, 0, 0);
    t48 = (t0 + 10984);
    *((int *)t48) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB7;

LAB8:    t25 = (t0 + 6808);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    goto LAB9;

LAB10:    t32 = (t0 + 6968);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 1, t27, 1, t34, 1);
    goto LAB16;

LAB14:    memcpy(t3, t27, 8);
    goto LAB16;

}

static void Always_195_10(char *t0)
{
    char t4[8];
    char t5[8];
    char t6[8];
    char t7[8];
    char t29[8];
    char *t1;
    char *t2;
    char *t3;
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
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;

LAB0:    t1 = (t0 + 10520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(195, ng0);
    t2 = (t0 + 11000);
    *((int *)t2) = 1;
    t3 = (t0 + 10552);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(195, ng0);

LAB5:    xsi_set_current_line(196, ng0);
    t8 = (t0 + 7128);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t7, 0, 8);
    t11 = (t10 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t10);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t11) != 0)
        goto LAB8;

LAB9:    t18 = (t7 + 4);
    t19 = *((unsigned int *)t7);
    t20 = *((unsigned int *)t18);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB10;

LAB11:    t23 = *((unsigned int *)t7);
    t24 = (~(t23));
    t25 = *((unsigned int *)t18);
    t26 = (t24 || t25);
    if (t26 > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t18) > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t7) > 0)
        goto LAB16;

LAB17:    memcpy(t6, t29, 8);

LAB18:    memset(t5, 0, 8);
    t37 = (t6 + 4);
    t38 = *((unsigned int *)t37);
    t39 = (~(t38));
    t40 = *((unsigned int *)t6);
    t41 = (t40 & t39);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t37) != 0)
        goto LAB21;

LAB22:    t44 = (t5 + 4);
    t45 = *((unsigned int *)t5);
    t46 = *((unsigned int *)t44);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB23;

LAB24:    t50 = *((unsigned int *)t5);
    t51 = (~(t50));
    t52 = *((unsigned int *)t44);
    t53 = (t51 || t52);
    if (t53 > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t44) > 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t5) > 0)
        goto LAB29;

LAB30:    memcpy(t4, t54, 8);

LAB31:    t48 = (t0 + 6808);
    xsi_vlogvar_wait_assign_value(t48, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(197, ng0);
    t2 = (t0 + 7128);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    memset(t7, 0, 8);
    t9 = (t8 + 4);
    t12 = *((unsigned int *)t9);
    t13 = (~(t12));
    t14 = *((unsigned int *)t8);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t9) != 0)
        goto LAB34;

LAB35:    t11 = (t7 + 4);
    t19 = *((unsigned int *)t7);
    t20 = *((unsigned int *)t11);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB36;

LAB37:    t23 = *((unsigned int *)t7);
    t24 = (~(t23));
    t25 = *((unsigned int *)t11);
    t26 = (t24 || t25);
    if (t26 > 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t11) > 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t7) > 0)
        goto LAB42;

LAB43:    memcpy(t6, t29, 8);

LAB44:    memset(t5, 0, 8);
    t28 = (t6 + 4);
    t38 = *((unsigned int *)t28);
    t39 = (~(t38));
    t40 = *((unsigned int *)t6);
    t41 = (t40 & t39);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t28) != 0)
        goto LAB47;

LAB48:    t37 = (t5 + 4);
    t45 = *((unsigned int *)t5);
    t46 = *((unsigned int *)t37);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB49;

LAB50:    t50 = *((unsigned int *)t5);
    t51 = (~(t50));
    t52 = *((unsigned int *)t37);
    t53 = (t51 || t52);
    if (t53 > 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t37) > 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t5) > 0)
        goto LAB55;

LAB56:    memcpy(t4, t48, 8);

LAB57:    t43 = (t0 + 6968);
    xsi_vlogvar_wait_assign_value(t43, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB6:    *((unsigned int *)t7) = 1;
    goto LAB9;

LAB8:    t17 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB9;

LAB10:    t22 = ((char*)((ng6)));
    goto LAB11;

LAB12:    t27 = (t0 + 5288U);
    t28 = *((char **)t27);
    memset(t29, 0, 8);
    t27 = (t29 + 4);
    t30 = (t28 + 4);
    t31 = *((unsigned int *)t28);
    t32 = (t31 >> 1);
    t33 = (t32 & 1);
    *((unsigned int *)t29) = t33;
    t34 = *((unsigned int *)t30);
    t35 = (t34 >> 1);
    t36 = (t35 & 1);
    *((unsigned int *)t27) = t36;
    goto LAB13;

LAB14:    xsi_vlog_unsigned_bit_combine(t6, 1, t22, 1, t29, 1);
    goto LAB18;

LAB16:    memcpy(t6, t22, 8);
    goto LAB18;

LAB19:    *((unsigned int *)t5) = 1;
    goto LAB22;

LAB21:    t43 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB22;

LAB23:    t48 = (t0 + 5128U);
    t49 = *((char **)t48);
    goto LAB24;

LAB25:    t48 = (t0 + 4808U);
    t54 = *((char **)t48);
    goto LAB26;

LAB27:    xsi_vlog_unsigned_bit_combine(t4, 1, t49, 1, t54, 1);
    goto LAB31;

LAB29:    memcpy(t4, t49, 8);
    goto LAB31;

LAB32:    *((unsigned int *)t7) = 1;
    goto LAB35;

LAB34:    t10 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB35;

LAB36:    t17 = ((char*)((ng5)));
    goto LAB37;

LAB38:    t18 = (t0 + 5288U);
    t22 = *((char **)t18);
    memset(t29, 0, 8);
    t18 = (t29 + 4);
    t27 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = (t31 >> 1);
    t33 = (t32 & 1);
    *((unsigned int *)t29) = t33;
    t34 = *((unsigned int *)t27);
    t35 = (t34 >> 1);
    t36 = (t35 & 1);
    *((unsigned int *)t18) = t36;
    goto LAB39;

LAB40:    xsi_vlog_unsigned_bit_combine(t6, 1, t17, 1, t29, 1);
    goto LAB44;

LAB42:    memcpy(t6, t17, 8);
    goto LAB44;

LAB45:    *((unsigned int *)t5) = 1;
    goto LAB48;

LAB47:    t30 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB48;

LAB49:    t43 = (t0 + 5128U);
    t44 = *((char **)t43);
    goto LAB50;

LAB51:    t43 = (t0 + 4808U);
    t48 = *((char **)t43);
    goto LAB52;

LAB53:    xsi_vlog_unsigned_bit_combine(t4, 1, t44, 1, t48, 1);
    goto LAB57;

LAB55:    memcpy(t4, t44, 8);
    goto LAB57;

}


extern void work_m_08821706360334616039_1514587734_init()
{
	static char *pe[] = {(void *)Cont_149_0,(void *)Cont_153_1,(void *)Cont_157_2,(void *)Cont_160_3,(void *)Cont_162_4,(void *)Always_167_5,(void *)Cont_175_6,(void *)Always_177_7,(void *)Always_183_8,(void *)Cont_193_9,(void *)Always_195_10};
	xsi_register_didat("work_m_08821706360334616039_1514587734", "isim/PicoTestbench_isim_beh.exe.sim/work/m_08821706360334616039_1514587734.didat");
	xsi_register_executes(pe);
}
