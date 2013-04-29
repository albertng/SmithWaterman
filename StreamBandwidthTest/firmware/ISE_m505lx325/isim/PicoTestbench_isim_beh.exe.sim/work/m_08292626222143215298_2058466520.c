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
static const char *ng0 = "/home/albertng/SmithWaterman/StreamBandwidthTest/firmware/ISE_m505lx325/source/PICO_128_SIM.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 0U};



static void Cont_2023_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t17[8];
    char t28[8];
    char t36[8];
    char t68[8];
    char t83[8];
    char t97[8];
    char t105[8];
    char t137[8];
    char t145[8];
    char *t1;
    char *t2;
    char *t5;
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
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
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
    int t60;
    int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    char *t82;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    char *t94;
    char *t95;
    char *t96;
    char *t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    char *t104;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    char *t109;
    char *t110;
    char *t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    int t129;
    int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    char *t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    char *t144;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    char *t149;
    char *t150;
    char *t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    char *t159;
    char *t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    char *t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    char *t179;
    char *t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    char *t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    char *t189;
    char *t190;
    char *t191;
    char *t192;
    char *t193;
    char *t194;
    unsigned int t195;
    unsigned int t196;
    char *t197;
    unsigned int t198;
    unsigned int t199;
    char *t200;
    unsigned int t201;
    unsigned int t202;
    char *t203;

LAB0:    t1 = (t0 + 3160U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2023, ng0);
    t2 = (t0 + 1528U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t5 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t36, t6, 8);

LAB10:    memset(t68, 0, 8);
    t69 = (t36 + 4);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t36);
    t73 = (t72 & t71);
    t74 = (t73 & 1U);
    if (t74 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t69) != 0)
        goto LAB24;

LAB25:    t76 = (t68 + 4);
    t77 = *((unsigned int *)t68);
    t78 = (!(t77));
    t79 = *((unsigned int *)t76);
    t80 = (t78 || t79);
    if (t80 > 0)
        goto LAB26;

LAB27:    memcpy(t145, t68, 8);

LAB28:    memset(t4, 0, 8);
    t173 = (t145 + 4);
    t174 = *((unsigned int *)t173);
    t175 = (~(t174));
    t176 = *((unsigned int *)t145);
    t177 = (t176 & t175);
    t178 = (t177 & 1U);
    if (t178 != 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t173) != 0)
        goto LAB52;

LAB53:    t180 = (t4 + 4);
    t181 = *((unsigned int *)t4);
    t182 = *((unsigned int *)t180);
    t183 = (t181 || t182);
    if (t183 > 0)
        goto LAB54;

LAB55:    t185 = *((unsigned int *)t4);
    t186 = (~(t185));
    t187 = *((unsigned int *)t180);
    t188 = (t186 || t187);
    if (t188 > 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t180) > 0)
        goto LAB58;

LAB59:    if (*((unsigned int *)t4) > 0)
        goto LAB60;

LAB61:    memcpy(t3, t189, 8);

LAB62:    t190 = (t0 + 3824);
    t191 = (t190 + 56U);
    t192 = *((char **)t191);
    t193 = (t192 + 56U);
    t194 = *((char **)t193);
    memset(t194, 0, 8);
    t195 = 1U;
    t196 = t195;
    t197 = (t3 + 4);
    t198 = *((unsigned int *)t3);
    t195 = (t195 & t198);
    t199 = *((unsigned int *)t197);
    t196 = (t196 & t199);
    t200 = (t194 + 4);
    t201 = *((unsigned int *)t194);
    *((unsigned int *)t194) = (t201 | t195);
    t202 = *((unsigned int *)t200);
    *((unsigned int *)t200) = (t202 | t196);
    xsi_driver_vfirst_trans(t190, 0, 0);
    t203 = (t0 + 3728);
    *((int *)t203) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t6) = 1;
    goto LAB7;

LAB6:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 2088);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memset(t17, 0, 8);
    t21 = (t20 + 4);
    t22 = *((unsigned int *)t21);
    t23 = (~(t22));
    t24 = *((unsigned int *)t20);
    t25 = (t24 & t23);
    t26 = (t25 & 1U);
    if (t26 != 0)
        goto LAB14;

LAB12:    if (*((unsigned int *)t21) == 0)
        goto LAB11;

LAB13:    t27 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t27) = 1;

LAB14:    memset(t28, 0, 8);
    t29 = (t17 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (~(t30));
    t32 = *((unsigned int *)t17);
    t33 = (t32 & t31);
    t34 = (t33 & 1U);
    if (t34 != 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t29) != 0)
        goto LAB17;

LAB18:    t37 = *((unsigned int *)t6);
    t38 = *((unsigned int *)t28);
    t39 = (t37 & t38);
    *((unsigned int *)t36) = t39;
    t40 = (t6 + 4);
    t41 = (t28 + 4);
    t42 = (t36 + 4);
    t43 = *((unsigned int *)t40);
    t44 = *((unsigned int *)t41);
    t45 = (t43 | t44);
    *((unsigned int *)t42) = t45;
    t46 = *((unsigned int *)t42);
    t47 = (t46 != 0);
    if (t47 == 1)
        goto LAB19;

LAB20:
LAB21:    goto LAB10;

LAB11:    *((unsigned int *)t17) = 1;
    goto LAB14;

LAB15:    *((unsigned int *)t28) = 1;
    goto LAB18;

LAB17:    t35 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB18;

LAB19:    t48 = *((unsigned int *)t36);
    t49 = *((unsigned int *)t42);
    *((unsigned int *)t36) = (t48 | t49);
    t50 = (t6 + 4);
    t51 = (t28 + 4);
    t52 = *((unsigned int *)t6);
    t53 = (~(t52));
    t54 = *((unsigned int *)t50);
    t55 = (~(t54));
    t56 = *((unsigned int *)t28);
    t57 = (~(t56));
    t58 = *((unsigned int *)t51);
    t59 = (~(t58));
    t60 = (t53 & t55);
    t61 = (t57 & t59);
    t62 = (~(t60));
    t63 = (~(t61));
    t64 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t64 & t62);
    t65 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t65 & t63);
    t66 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t66 & t62);
    t67 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t67 & t63);
    goto LAB21;

LAB22:    *((unsigned int *)t68) = 1;
    goto LAB25;

LAB24:    t75 = (t68 + 4);
    *((unsigned int *)t68) = 1;
    *((unsigned int *)t75) = 1;
    goto LAB25;

LAB26:    t81 = (t0 + 1528U);
    t82 = *((char **)t81);
    memset(t83, 0, 8);
    t81 = (t82 + 4);
    t84 = *((unsigned int *)t81);
    t85 = (~(t84));
    t86 = *((unsigned int *)t82);
    t87 = (t86 & t85);
    t88 = (t87 & 1U);
    if (t88 != 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t81) != 0)
        goto LAB31;

LAB32:    t90 = (t83 + 4);
    t91 = *((unsigned int *)t83);
    t92 = *((unsigned int *)t90);
    t93 = (t91 || t92);
    if (t93 > 0)
        goto LAB33;

LAB34:    memcpy(t105, t83, 8);

LAB35:    memset(t137, 0, 8);
    t138 = (t105 + 4);
    t139 = *((unsigned int *)t138);
    t140 = (~(t139));
    t141 = *((unsigned int *)t105);
    t142 = (t141 & t140);
    t143 = (t142 & 1U);
    if (t143 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t138) != 0)
        goto LAB45;

LAB46:    t146 = *((unsigned int *)t68);
    t147 = *((unsigned int *)t137);
    t148 = (t146 | t147);
    *((unsigned int *)t145) = t148;
    t149 = (t68 + 4);
    t150 = (t137 + 4);
    t151 = (t145 + 4);
    t152 = *((unsigned int *)t149);
    t153 = *((unsigned int *)t150);
    t154 = (t152 | t153);
    *((unsigned int *)t151) = t154;
    t155 = *((unsigned int *)t151);
    t156 = (t155 != 0);
    if (t156 == 1)
        goto LAB47;

LAB48:
LAB49:    goto LAB28;

LAB29:    *((unsigned int *)t83) = 1;
    goto LAB32;

LAB31:    t89 = (t83 + 4);
    *((unsigned int *)t83) = 1;
    *((unsigned int *)t89) = 1;
    goto LAB32;

LAB33:    t94 = (t0 + 2248);
    t95 = (t94 + 56U);
    t96 = *((char **)t95);
    memset(t97, 0, 8);
    t98 = (t96 + 4);
    t99 = *((unsigned int *)t98);
    t100 = (~(t99));
    t101 = *((unsigned int *)t96);
    t102 = (t101 & t100);
    t103 = (t102 & 1U);
    if (t103 != 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t98) != 0)
        goto LAB38;

LAB39:    t106 = *((unsigned int *)t83);
    t107 = *((unsigned int *)t97);
    t108 = (t106 & t107);
    *((unsigned int *)t105) = t108;
    t109 = (t83 + 4);
    t110 = (t97 + 4);
    t111 = (t105 + 4);
    t112 = *((unsigned int *)t109);
    t113 = *((unsigned int *)t110);
    t114 = (t112 | t113);
    *((unsigned int *)t111) = t114;
    t115 = *((unsigned int *)t111);
    t116 = (t115 != 0);
    if (t116 == 1)
        goto LAB40;

LAB41:
LAB42:    goto LAB35;

LAB36:    *((unsigned int *)t97) = 1;
    goto LAB39;

LAB38:    t104 = (t97 + 4);
    *((unsigned int *)t97) = 1;
    *((unsigned int *)t104) = 1;
    goto LAB39;

LAB40:    t117 = *((unsigned int *)t105);
    t118 = *((unsigned int *)t111);
    *((unsigned int *)t105) = (t117 | t118);
    t119 = (t83 + 4);
    t120 = (t97 + 4);
    t121 = *((unsigned int *)t83);
    t122 = (~(t121));
    t123 = *((unsigned int *)t119);
    t124 = (~(t123));
    t125 = *((unsigned int *)t97);
    t126 = (~(t125));
    t127 = *((unsigned int *)t120);
    t128 = (~(t127));
    t129 = (t122 & t124);
    t130 = (t126 & t128);
    t131 = (~(t129));
    t132 = (~(t130));
    t133 = *((unsigned int *)t111);
    *((unsigned int *)t111) = (t133 & t131);
    t134 = *((unsigned int *)t111);
    *((unsigned int *)t111) = (t134 & t132);
    t135 = *((unsigned int *)t105);
    *((unsigned int *)t105) = (t135 & t131);
    t136 = *((unsigned int *)t105);
    *((unsigned int *)t105) = (t136 & t132);
    goto LAB42;

LAB43:    *((unsigned int *)t137) = 1;
    goto LAB46;

LAB45:    t144 = (t137 + 4);
    *((unsigned int *)t137) = 1;
    *((unsigned int *)t144) = 1;
    goto LAB46;

LAB47:    t157 = *((unsigned int *)t145);
    t158 = *((unsigned int *)t151);
    *((unsigned int *)t145) = (t157 | t158);
    t159 = (t68 + 4);
    t160 = (t137 + 4);
    t161 = *((unsigned int *)t159);
    t162 = (~(t161));
    t163 = *((unsigned int *)t68);
    t164 = (t163 & t162);
    t165 = *((unsigned int *)t160);
    t166 = (~(t165));
    t167 = *((unsigned int *)t137);
    t168 = (t167 & t166);
    t169 = (~(t164));
    t170 = (~(t168));
    t171 = *((unsigned int *)t151);
    *((unsigned int *)t151) = (t171 & t169);
    t172 = *((unsigned int *)t151);
    *((unsigned int *)t151) = (t172 & t170);
    goto LAB49;

LAB50:    *((unsigned int *)t4) = 1;
    goto LAB53;

LAB52:    t179 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t179) = 1;
    goto LAB53;

LAB54:    t184 = ((char*)((ng1)));
    goto LAB55;

LAB56:    t189 = ((char*)((ng2)));
    goto LAB57;

LAB58:    xsi_vlog_unsigned_bit_combine(t3, 1, t184, 1, t189, 1);
    goto LAB62;

LAB60:    memcpy(t3, t184, 8);
    goto LAB62;

}

static void Always_2025_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 3408U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2025, ng0);
    t2 = (t0 + 3744);
    *((int *)t2) = 1;
    t3 = (t0 + 3440);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(2025, ng0);

LAB5:    xsi_set_current_line(2026, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);
    t4 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 1000LL);
    xsi_set_current_line(2027, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 1000LL);
    goto LAB2;

}


extern void work_m_08292626222143215298_2058466520_init()
{
	static char *pe[] = {(void *)Cont_2023_0,(void *)Always_2025_1};
	xsi_register_didat("work_m_08292626222143215298_2058466520", "isim/PicoTestbench_isim_beh.exe.sim/work/m_08292626222143215298_2058466520.didat");
	xsi_register_executes(pe);
}
