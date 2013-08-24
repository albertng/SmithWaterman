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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/samples/DDR3_MovingAverage/firmware/ISE_m505lx325/source/coregen-LX325T/mig_M505_DDR3/rtl/phy/mig_7series_v1_8_ddr_prbs_gen.v";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {2, 0};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {5U, 0U};
static int ng6[] = {4, 0};
static int ng7[] = {64, 0};
static int ng8[] = {5, 0};
static int ng9[] = {31, 0};
static int ng10[] = {30, 0};
static int ng11[] = {29, 0};
static int ng12[] = {9, 0};
static int ng13[] = {8, 0};
static int ng14[] = {7, 0};
static int ng15[] = {6, 0};
static int ng16[] = {3, 0};



static int sp_clogb2(char *t1, char *t2)
{
    char t7[8];
    char t18[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t19;

LAB0:    t0 = 1;
    xsi_set_current_line(110, ng0);

LAB2:    xsi_set_current_line(111, ng0);
    t3 = (t1 + 4184);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t7, 0, 8);
    xsi_vlog_signed_minus(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 4184);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    xsi_set_current_line(112, ng0);
    xsi_set_current_line(112, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t1 + 4344);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);

LAB3:    t3 = (t1 + 4184);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t7, 0, 8);
    xsi_vlog_signed_greater(t7, 32, t5, 32, t6, 32);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB4;

LAB5:    t0 = 0;

LAB1:    return t0;
LAB4:    xsi_set_current_line(113, ng0);
    t14 = (t1 + 4184);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = ((char*)((ng1)));
    memset(t18, 0, 8);
    xsi_vlog_signed_rshift(t18, 32, t16, 32, t17, 32);
    t19 = (t1 + 4184);
    xsi_vlogvar_assign_value(t19, t18, 0, 0, 32);
    xsi_set_current_line(112, ng0);
    t3 = (t1 + 4344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 4344);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB3;

}

static void Always_128_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 5256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(128, ng0);
    t2 = (t0 + 6568);
    *((int *)t2) = 1;
    t3 = (t0 + 5288);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(128, ng0);

LAB5:    xsi_set_current_line(129, ng0);
    t4 = (t0 + 2664U);
    t5 = *((char **)t4);
    t4 = (t0 + 3384);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 100000LL);
    goto LAB2;

}

static void Always_137_1(char *t0)
{
    char t6[8];
    char t18[8];
    char t37[8];
    char t45[8];
    char t81[8];
    char t82[8];
    char t104[8];
    char t112[8];
    char t154[8];
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
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    char *t80;
    char *t83;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    char *t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t111;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    char *t116;
    char *t117;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    char *t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    int t136;
    int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    char *t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    char *t150;
    char *t151;
    char *t152;
    char *t153;
    char *t155;

LAB0:    t1 = (t0 + 5504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(137, ng0);
    t2 = (t0 + 6584);
    *((int *)t2) = 1;
    t3 = (t0 + 5536);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(138, ng0);

LAB5:    xsi_set_current_line(139, ng0);
    t4 = (t0 + 2344U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t45, t6, 8);

LAB12:    t73 = (t45 + 4);
    t74 = *((unsigned int *)t73);
    t75 = (~(t74));
    t76 = *((unsigned int *)t45);
    t77 = (t76 & t75);
    t78 = (t77 != 0);
    if (t78 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t2) != 0)
        goto LAB32;

LAB33:    t5 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t5);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB34;

LAB35:    memcpy(t112, t6, 8);

LAB36:    t144 = (t112 + 4);
    t145 = *((unsigned int *)t144);
    t146 = (~(t145));
    t147 = *((unsigned int *)t112);
    t148 = (t147 & t146);
    t149 = (t148 != 0);
    if (t149 > 0)
        goto LAB70;

LAB71:
LAB72:
LAB28:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t19 = (t0 + 2184U);
    t20 = *((char **)t19);
    memset(t18, 0, 8);
    t19 = (t20 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB16;

LAB14:    if (*((unsigned int *)t19) == 0)
        goto LAB13;

LAB15:    t26 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t26) = 1;

LAB16:    t27 = (t18 + 4);
    t28 = (t20 + 4);
    t29 = *((unsigned int *)t20);
    t30 = (~(t29));
    *((unsigned int *)t18) = t30;
    *((unsigned int *)t27) = 0;
    if (*((unsigned int *)t28) != 0)
        goto LAB18;

LAB17:    t35 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t35 & 1U);
    t36 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t36 & 1U);
    memset(t37, 0, 8);
    t38 = (t18 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t18);
    t42 = (t41 & t40);
    t43 = (t42 & 1U);
    if (t43 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t38) != 0)
        goto LAB21;

LAB22:    t46 = *((unsigned int *)t6);
    t47 = *((unsigned int *)t37);
    t48 = (t46 | t47);
    *((unsigned int *)t45) = t48;
    t49 = (t6 + 4);
    t50 = (t37 + 4);
    t51 = (t45 + 4);
    t52 = *((unsigned int *)t49);
    t53 = *((unsigned int *)t50);
    t54 = (t52 | t53);
    *((unsigned int *)t51) = t54;
    t55 = *((unsigned int *)t51);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB23;

LAB24:
LAB25:    goto LAB12;

LAB13:    *((unsigned int *)t18) = 1;
    goto LAB16;

LAB18:    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t28);
    *((unsigned int *)t18) = (t31 | t32);
    t33 = *((unsigned int *)t27);
    t34 = *((unsigned int *)t28);
    *((unsigned int *)t27) = (t33 | t34);
    goto LAB17;

LAB19:    *((unsigned int *)t37) = 1;
    goto LAB22;

LAB21:    t44 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB22;

LAB23:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t45) = (t57 | t58);
    t59 = (t6 + 4);
    t60 = (t37 + 4);
    t61 = *((unsigned int *)t59);
    t62 = (~(t61));
    t63 = *((unsigned int *)t6);
    t64 = (t63 & t62);
    t65 = *((unsigned int *)t60);
    t66 = (~(t65));
    t67 = *((unsigned int *)t37);
    t68 = (t67 & t66);
    t69 = (~(t64));
    t70 = (~(t68));
    t71 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t71 & t69);
    t72 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t72 & t70);
    goto LAB25;

LAB26:    xsi_set_current_line(139, ng0);

LAB29:    xsi_set_current_line(140, ng0);
    t79 = ((char*)((ng2)));
    t80 = (t0 + 3704);
    xsi_vlogvar_wait_assign_value(t80, t79, 0, 0, 7, 100000LL);
    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 100000LL);
    goto LAB28;

LAB30:    *((unsigned int *)t6) = 1;
    goto LAB33;

LAB32:    t4 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB33;

LAB34:    t12 = (t0 + 3384);
    t13 = (t12 + 56U);
    t19 = *((char **)t13);
    memset(t18, 0, 8);
    t20 = (t19 + 4);
    t17 = *((unsigned int *)t20);
    t21 = (~(t17));
    t22 = *((unsigned int *)t19);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB40;

LAB38:    if (*((unsigned int *)t20) == 0)
        goto LAB37;

LAB39:    t26 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t26) = 1;

LAB40:    t27 = (t18 + 4);
    t28 = (t19 + 4);
    t25 = *((unsigned int *)t19);
    t29 = (~(t25));
    *((unsigned int *)t18) = t29;
    *((unsigned int *)t27) = 0;
    if (*((unsigned int *)t28) != 0)
        goto LAB42;

LAB41:    t34 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t34 & 1U);
    t35 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t35 & 1U);
    memset(t37, 0, 8);
    t38 = (t18 + 4);
    t36 = *((unsigned int *)t38);
    t39 = (~(t36));
    t40 = *((unsigned int *)t18);
    t41 = (t40 & t39);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t38) != 0)
        goto LAB45;

LAB46:    t49 = (t37 + 4);
    t43 = *((unsigned int *)t37);
    t46 = (!(t43));
    t47 = *((unsigned int *)t49);
    t48 = (t46 || t47);
    if (t48 > 0)
        goto LAB47;

LAB48:    memcpy(t82, t37, 8);

LAB49:    memset(t104, 0, 8);
    t105 = (t82 + 4);
    t106 = *((unsigned int *)t105);
    t107 = (~(t106));
    t108 = *((unsigned int *)t82);
    t109 = (t108 & t107);
    t110 = (t109 & 1U);
    if (t110 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t105) != 0)
        goto LAB65;

LAB66:    t113 = *((unsigned int *)t6);
    t114 = *((unsigned int *)t104);
    t115 = (t113 & t114);
    *((unsigned int *)t112) = t115;
    t116 = (t6 + 4);
    t117 = (t104 + 4);
    t118 = (t112 + 4);
    t119 = *((unsigned int *)t116);
    t120 = *((unsigned int *)t117);
    t121 = (t119 | t120);
    *((unsigned int *)t118) = t121;
    t122 = *((unsigned int *)t118);
    t123 = (t122 != 0);
    if (t123 == 1)
        goto LAB67;

LAB68:
LAB69:    goto LAB36;

LAB37:    *((unsigned int *)t18) = 1;
    goto LAB40;

LAB42:    t30 = *((unsigned int *)t18);
    t31 = *((unsigned int *)t28);
    *((unsigned int *)t18) = (t30 | t31);
    t32 = *((unsigned int *)t27);
    t33 = *((unsigned int *)t28);
    *((unsigned int *)t27) = (t32 | t33);
    goto LAB41;

LAB43:    *((unsigned int *)t37) = 1;
    goto LAB46;

LAB45:    t44 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB46;

LAB47:    t50 = (t0 + 2824U);
    t51 = *((char **)t50);
    memset(t45, 0, 8);
    t50 = (t51 + 4);
    t52 = *((unsigned int *)t50);
    t53 = (~(t52));
    t54 = *((unsigned int *)t51);
    t55 = (t54 & t53);
    t56 = (t55 & 1U);
    if (t56 != 0)
        goto LAB53;

LAB51:    if (*((unsigned int *)t50) == 0)
        goto LAB50;

LAB52:    t59 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t59) = 1;

LAB53:    t60 = (t45 + 4);
    t73 = (t51 + 4);
    t57 = *((unsigned int *)t51);
    t58 = (~(t57));
    *((unsigned int *)t45) = t58;
    *((unsigned int *)t60) = 0;
    if (*((unsigned int *)t73) != 0)
        goto LAB55;

LAB54:    t66 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t66 & 1U);
    t67 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t67 & 1U);
    memset(t81, 0, 8);
    t79 = (t45 + 4);
    t69 = *((unsigned int *)t79);
    t70 = (~(t69));
    t71 = *((unsigned int *)t45);
    t72 = (t71 & t70);
    t74 = (t72 & 1U);
    if (t74 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t79) != 0)
        goto LAB58;

LAB59:    t75 = *((unsigned int *)t37);
    t76 = *((unsigned int *)t81);
    t77 = (t75 | t76);
    *((unsigned int *)t82) = t77;
    t83 = (t37 + 4);
    t84 = (t81 + 4);
    t85 = (t82 + 4);
    t78 = *((unsigned int *)t83);
    t86 = *((unsigned int *)t84);
    t87 = (t78 | t86);
    *((unsigned int *)t85) = t87;
    t88 = *((unsigned int *)t85);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB60;

LAB61:
LAB62:    goto LAB49;

LAB50:    *((unsigned int *)t45) = 1;
    goto LAB53;

LAB55:    t61 = *((unsigned int *)t45);
    t62 = *((unsigned int *)t73);
    *((unsigned int *)t45) = (t61 | t62);
    t63 = *((unsigned int *)t60);
    t65 = *((unsigned int *)t73);
    *((unsigned int *)t60) = (t63 | t65);
    goto LAB54;

LAB56:    *((unsigned int *)t81) = 1;
    goto LAB59;

LAB58:    t80 = (t81 + 4);
    *((unsigned int *)t81) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB59;

LAB60:    t90 = *((unsigned int *)t82);
    t91 = *((unsigned int *)t85);
    *((unsigned int *)t82) = (t90 | t91);
    t92 = (t37 + 4);
    t93 = (t81 + 4);
    t94 = *((unsigned int *)t92);
    t95 = (~(t94));
    t96 = *((unsigned int *)t37);
    t64 = (t96 & t95);
    t97 = *((unsigned int *)t93);
    t98 = (~(t97));
    t99 = *((unsigned int *)t81);
    t68 = (t99 & t98);
    t100 = (~(t64));
    t101 = (~(t68));
    t102 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t102 & t100);
    t103 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t103 & t101);
    goto LAB62;

LAB63:    *((unsigned int *)t104) = 1;
    goto LAB66;

LAB65:    t111 = (t104 + 4);
    *((unsigned int *)t104) = 1;
    *((unsigned int *)t111) = 1;
    goto LAB66;

LAB67:    t124 = *((unsigned int *)t112);
    t125 = *((unsigned int *)t118);
    *((unsigned int *)t112) = (t124 | t125);
    t126 = (t6 + 4);
    t127 = (t104 + 4);
    t128 = *((unsigned int *)t6);
    t129 = (~(t128));
    t130 = *((unsigned int *)t126);
    t131 = (~(t130));
    t132 = *((unsigned int *)t104);
    t133 = (~(t132));
    t134 = *((unsigned int *)t127);
    t135 = (~(t134));
    t136 = (t129 & t131);
    t137 = (t133 & t135);
    t138 = (~(t136));
    t139 = (~(t137));
    t140 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t140 & t138);
    t141 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t141 & t139);
    t142 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t142 & t138);
    t143 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t143 & t139);
    goto LAB69;

LAB70:    xsi_set_current_line(142, ng0);

LAB73:    xsi_set_current_line(144, ng0);
    t150 = (t0 + 3704);
    t151 = (t150 + 56U);
    t152 = *((char **)t151);
    t153 = ((char*)((ng1)));
    memset(t154, 0, 8);
    xsi_vlog_unsigned_add(t154, 32, t152, 7, t153, 32);
    t155 = (t0 + 3704);
    xsi_vlogvar_wait_assign_value(t155, t154, 0, 0, 7, 100000LL);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 3704);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 744);
    t12 = *((char **)t5);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 32, t12, 32, t5, 32);
    memset(t18, 0, 8);
    t13 = (t4 + 4);
    t19 = (t6 + 4);
    t7 = *((unsigned int *)t4);
    t8 = *((unsigned int *)t6);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t13);
    t11 = *((unsigned int *)t19);
    t14 = (t10 ^ t11);
    t15 = (t9 | t14);
    t16 = *((unsigned int *)t13);
    t17 = *((unsigned int *)t19);
    t21 = (t16 | t17);
    t22 = (~(t21));
    t23 = (t15 & t22);
    if (t23 != 0)
        goto LAB77;

LAB74:    if (t21 != 0)
        goto LAB76;

LAB75:    *((unsigned int *)t18) = 1;

LAB77:    t26 = (t18 + 4);
    t24 = *((unsigned int *)t26);
    t25 = (~(t24));
    t29 = *((unsigned int *)t18);
    t30 = (t29 & t25);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB78;

LAB79:    xsi_set_current_line(150, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 100000LL);

LAB80:    goto LAB72;

LAB76:    t20 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB77;

LAB78:    xsi_set_current_line(148, ng0);
    t27 = ((char*)((ng4)));
    t28 = (t0 + 3544);
    xsi_vlogvar_wait_assign_value(t28, t27, 0, 0, 1, 100000LL);
    goto LAB80;

}

static void Always_154_2(char *t0)
{
    char t7[8];
    char t21[8];
    char t28[8];
    char t60[8];
    char t75[8];
    char t82[8];
    char t110[8];
    char t123[8];
    char t142[8];
    char t150[8];
    char t184[8];
    char t195[8];
    char t224[8];
    char t225[8];
    char t226[8];
    char t249[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    char *t96;
    char *t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    char *t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    char *t124;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    char *t131;
    char *t132;
    char *t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    char *t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    char *t149;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    char *t154;
    char *t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    char *t164;
    char *t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    char *t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    char *t185;
    char *t186;
    char *t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    char *t194;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    char *t199;
    char *t200;
    char *t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    char *t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    int t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    char *t223;
    char *t227;
    char *t228;
    char *t229;
    char *t230;
    char *t231;
    char *t232;
    unsigned int t233;
    int t234;
    char *t235;
    unsigned int t236;
    int t237;
    int t238;
    char *t239;
    unsigned int t240;
    int t241;
    int t242;
    unsigned int t243;
    int t244;
    unsigned int t245;
    unsigned int t246;
    int t247;
    int t248;

LAB0:    t1 = (t0 + 5752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(154, ng0);
    t2 = (t0 + 6600);
    *((int *)t2) = 1;
    t3 = (t0 + 5784);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(155, ng0);

LAB5:    xsi_set_current_line(157, ng0);
    t4 = (t0 + 3544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t8) != 0)
        goto LAB8;

LAB9:    t15 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB10;

LAB11:    memcpy(t28, t7, 8);

LAB12:    memset(t60, 0, 8);
    t61 = (t28 + 4);
    t62 = *((unsigned int *)t61);
    t63 = (~(t62));
    t64 = *((unsigned int *)t28);
    t65 = (t64 & t63);
    t66 = (t65 & 1U);
    if (t66 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t61) != 0)
        goto LAB22;

LAB23:    t68 = (t60 + 4);
    t69 = *((unsigned int *)t60);
    t70 = (!(t69));
    t71 = *((unsigned int *)t68);
    t72 = (t70 || t71);
    if (t72 > 0)
        goto LAB24;

LAB25:    memcpy(t82, t60, 8);

LAB26:    memset(t110, 0, 8);
    t111 = (t82 + 4);
    t112 = *((unsigned int *)t111);
    t113 = (~(t112));
    t114 = *((unsigned int *)t82);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB34;

LAB35:    if (*((unsigned int *)t111) != 0)
        goto LAB36;

LAB37:    t118 = (t110 + 4);
    t119 = *((unsigned int *)t110);
    t120 = (!(t119));
    t121 = *((unsigned int *)t118);
    t122 = (t120 || t121);
    if (t122 > 0)
        goto LAB38;

LAB39:    memcpy(t150, t110, 8);

LAB40:    t178 = (t150 + 4);
    t179 = *((unsigned int *)t178);
    t180 = (~(t179));
    t181 = *((unsigned int *)t150);
    t182 = (t181 & t180);
    t183 = (t182 != 0);
    if (t183 > 0)
        goto LAB54;

LAB55:    xsi_set_current_line(161, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB65;

LAB66:    if (*((unsigned int *)t2) != 0)
        goto LAB67;

LAB68:    t5 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t5);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB69;

LAB70:    memcpy(t123, t7, 8);

LAB71:    t132 = (t123 + 4);
    t148 = *((unsigned int *)t132);
    t151 = (~(t148));
    t152 = *((unsigned int *)t123);
    t153 = (t152 & t151);
    t157 = (t153 != 0);
    if (t157 > 0)
        goto LAB105;

LAB106:
LAB107:
LAB56:    goto LAB2;

LAB6:    *((unsigned int *)t7) = 1;
    goto LAB9;

LAB8:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB9;

LAB10:    t19 = (t0 + 2184U);
    t20 = *((char **)t19);
    memset(t21, 0, 8);
    t19 = (t20 + 4);
    t22 = *((unsigned int *)t19);
    t23 = (~(t22));
    t24 = *((unsigned int *)t20);
    t25 = (t24 & t23);
    t26 = (t25 & 1U);
    if (t26 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t19) != 0)
        goto LAB15;

LAB16:    t29 = *((unsigned int *)t7);
    t30 = *((unsigned int *)t21);
    t31 = (t29 & t30);
    *((unsigned int *)t28) = t31;
    t32 = (t7 + 4);
    t33 = (t21 + 4);
    t34 = (t28 + 4);
    t35 = *((unsigned int *)t32);
    t36 = *((unsigned int *)t33);
    t37 = (t35 | t36);
    *((unsigned int *)t34) = t37;
    t38 = *((unsigned int *)t34);
    t39 = (t38 != 0);
    if (t39 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t21) = 1;
    goto LAB16;

LAB15:    t27 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB16;

LAB17:    t40 = *((unsigned int *)t28);
    t41 = *((unsigned int *)t34);
    *((unsigned int *)t28) = (t40 | t41);
    t42 = (t7 + 4);
    t43 = (t21 + 4);
    t44 = *((unsigned int *)t7);
    t45 = (~(t44));
    t46 = *((unsigned int *)t42);
    t47 = (~(t46));
    t48 = *((unsigned int *)t21);
    t49 = (~(t48));
    t50 = *((unsigned int *)t43);
    t51 = (~(t50));
    t52 = (t45 & t47);
    t53 = (t49 & t51);
    t54 = (~(t52));
    t55 = (~(t53));
    t56 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t56 & t54);
    t57 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t57 & t55);
    t58 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t58 & t54);
    t59 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t59 & t55);
    goto LAB19;

LAB20:    *((unsigned int *)t60) = 1;
    goto LAB23;

LAB22:    t67 = (t60 + 4);
    *((unsigned int *)t60) = 1;
    *((unsigned int *)t67) = 1;
    goto LAB23;

LAB24:    t73 = (t0 + 2344U);
    t74 = *((char **)t73);
    memset(t75, 0, 8);
    t73 = (t74 + 4);
    t76 = *((unsigned int *)t73);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (t78 & t77);
    t80 = (t79 & 1U);
    if (t80 != 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t73) != 0)
        goto LAB29;

LAB30:    t83 = *((unsigned int *)t60);
    t84 = *((unsigned int *)t75);
    t85 = (t83 | t84);
    *((unsigned int *)t82) = t85;
    t86 = (t60 + 4);
    t87 = (t75 + 4);
    t88 = (t82 + 4);
    t89 = *((unsigned int *)t86);
    t90 = *((unsigned int *)t87);
    t91 = (t89 | t90);
    *((unsigned int *)t88) = t91;
    t92 = *((unsigned int *)t88);
    t93 = (t92 != 0);
    if (t93 == 1)
        goto LAB31;

LAB32:
LAB33:    goto LAB26;

LAB27:    *((unsigned int *)t75) = 1;
    goto LAB30;

LAB29:    t81 = (t75 + 4);
    *((unsigned int *)t75) = 1;
    *((unsigned int *)t81) = 1;
    goto LAB30;

LAB31:    t94 = *((unsigned int *)t82);
    t95 = *((unsigned int *)t88);
    *((unsigned int *)t82) = (t94 | t95);
    t96 = (t60 + 4);
    t97 = (t75 + 4);
    t98 = *((unsigned int *)t96);
    t99 = (~(t98));
    t100 = *((unsigned int *)t60);
    t101 = (t100 & t99);
    t102 = *((unsigned int *)t97);
    t103 = (~(t102));
    t104 = *((unsigned int *)t75);
    t105 = (t104 & t103);
    t106 = (~(t101));
    t107 = (~(t105));
    t108 = *((unsigned int *)t88);
    *((unsigned int *)t88) = (t108 & t106);
    t109 = *((unsigned int *)t88);
    *((unsigned int *)t88) = (t109 & t107);
    goto LAB33;

LAB34:    *((unsigned int *)t110) = 1;
    goto LAB37;

LAB36:    t117 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t117) = 1;
    goto LAB37;

LAB38:    t124 = (t0 + 2184U);
    t125 = *((char **)t124);
    memset(t123, 0, 8);
    t124 = (t125 + 4);
    t126 = *((unsigned int *)t124);
    t127 = (~(t126));
    t128 = *((unsigned int *)t125);
    t129 = (t128 & t127);
    t130 = (t129 & 1U);
    if (t130 != 0)
        goto LAB44;

LAB42:    if (*((unsigned int *)t124) == 0)
        goto LAB41;

LAB43:    t131 = (t123 + 4);
    *((unsigned int *)t123) = 1;
    *((unsigned int *)t131) = 1;

LAB44:    t132 = (t123 + 4);
    t133 = (t125 + 4);
    t134 = *((unsigned int *)t125);
    t135 = (~(t134));
    *((unsigned int *)t123) = t135;
    *((unsigned int *)t132) = 0;
    if (*((unsigned int *)t133) != 0)
        goto LAB46;

LAB45:    t140 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t140 & 1U);
    t141 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t141 & 1U);
    memset(t142, 0, 8);
    t143 = (t123 + 4);
    t144 = *((unsigned int *)t143);
    t145 = (~(t144));
    t146 = *((unsigned int *)t123);
    t147 = (t146 & t145);
    t148 = (t147 & 1U);
    if (t148 != 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t143) != 0)
        goto LAB49;

LAB50:    t151 = *((unsigned int *)t110);
    t152 = *((unsigned int *)t142);
    t153 = (t151 | t152);
    *((unsigned int *)t150) = t153;
    t154 = (t110 + 4);
    t155 = (t142 + 4);
    t156 = (t150 + 4);
    t157 = *((unsigned int *)t154);
    t158 = *((unsigned int *)t155);
    t159 = (t157 | t158);
    *((unsigned int *)t156) = t159;
    t160 = *((unsigned int *)t156);
    t161 = (t160 != 0);
    if (t161 == 1)
        goto LAB51;

LAB52:
LAB53:    goto LAB40;

LAB41:    *((unsigned int *)t123) = 1;
    goto LAB44;

LAB46:    t136 = *((unsigned int *)t123);
    t137 = *((unsigned int *)t133);
    *((unsigned int *)t123) = (t136 | t137);
    t138 = *((unsigned int *)t132);
    t139 = *((unsigned int *)t133);
    *((unsigned int *)t132) = (t138 | t139);
    goto LAB45;

LAB47:    *((unsigned int *)t142) = 1;
    goto LAB50;

LAB49:    t149 = (t142 + 4);
    *((unsigned int *)t142) = 1;
    *((unsigned int *)t149) = 1;
    goto LAB50;

LAB51:    t162 = *((unsigned int *)t150);
    t163 = *((unsigned int *)t156);
    *((unsigned int *)t150) = (t162 | t163);
    t164 = (t110 + 4);
    t165 = (t142 + 4);
    t166 = *((unsigned int *)t164);
    t167 = (~(t166));
    t168 = *((unsigned int *)t110);
    t169 = (t168 & t167);
    t170 = *((unsigned int *)t165);
    t171 = (~(t170));
    t172 = *((unsigned int *)t142);
    t173 = (t172 & t171);
    t174 = (~(t169));
    t175 = (~(t173));
    t176 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t176 & t174);
    t177 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t177 & t175);
    goto LAB53;

LAB54:    xsi_set_current_line(157, ng0);

LAB57:    xsi_set_current_line(158, ng0);
    t185 = (t0 + 2504U);
    t186 = *((char **)t185);
    memset(t184, 0, 8);
    t185 = (t184 + 4);
    t187 = (t186 + 4);
    t188 = *((unsigned int *)t186);
    t189 = (t188 >> 0);
    *((unsigned int *)t184) = t189;
    t190 = *((unsigned int *)t187);
    t191 = (t190 >> 0);
    *((unsigned int *)t185) = t191;
    t192 = *((unsigned int *)t184);
    *((unsigned int *)t184) = (t192 & 15U);
    t193 = *((unsigned int *)t185);
    *((unsigned int *)t185) = (t193 & 15U);
    t194 = ((char*)((ng5)));
    t196 = *((unsigned int *)t184);
    t197 = *((unsigned int *)t194);
    t198 = (t196 | t197);
    *((unsigned int *)t195) = t198;
    t199 = (t184 + 4);
    t200 = (t194 + 4);
    t201 = (t195 + 4);
    t202 = *((unsigned int *)t199);
    t203 = *((unsigned int *)t200);
    t204 = (t202 | t203);
    *((unsigned int *)t201) = t204;
    t205 = *((unsigned int *)t201);
    t206 = (t205 != 0);
    if (t206 == 1)
        goto LAB58;

LAB59:
LAB60:    t223 = (t0 + 4024);
    t227 = (t0 + 4024);
    t228 = (t227 + 72U);
    t229 = *((char **)t228);
    t230 = ((char*)((ng6)));
    t231 = ((char*)((ng1)));
    xsi_vlog_convert_partindices(t224, t225, t226, ((int*)(t229)), 2, t230, 32, 1, t231, 32, 1);
    t232 = (t224 + 4);
    t233 = *((unsigned int *)t232);
    t234 = (!(t233));
    t235 = (t225 + 4);
    t236 = *((unsigned int *)t235);
    t237 = (!(t236));
    t238 = (t234 && t237);
    t239 = (t226 + 4);
    t240 = *((unsigned int *)t239);
    t241 = (!(t240));
    t242 = (t238 && t241);
    if (t242 == 1)
        goto LAB61;

LAB62:    xsi_set_current_line(159, ng0);
    t2 = (t0 + 2504U);
    t3 = *((char **)t2);
    xsi_vlog_get_part_select_value(t249, 60, t3, 63, 4);
    t2 = (t0 + 4024);
    t4 = (t0 + 4024);
    t5 = (t4 + 72U);
    t6 = *((char **)t5);
    t8 = ((char*)((ng7)));
    t14 = ((char*)((ng8)));
    xsi_vlog_convert_partindices(t7, t21, t28, ((int*)(t6)), 2, t8, 32, 1, t14, 32, 1);
    t15 = (t7 + 4);
    t9 = *((unsigned int *)t15);
    t52 = (!(t9));
    t19 = (t21 + 4);
    t10 = *((unsigned int *)t19);
    t53 = (!(t10));
    t101 = (t52 && t53);
    t20 = (t28 + 4);
    t11 = *((unsigned int *)t20);
    t105 = (!(t11));
    t169 = (t101 && t105);
    if (t169 == 1)
        goto LAB63;

LAB64:    goto LAB56;

LAB58:    t207 = *((unsigned int *)t195);
    t208 = *((unsigned int *)t201);
    *((unsigned int *)t195) = (t207 | t208);
    t209 = (t184 + 4);
    t210 = (t194 + 4);
    t211 = *((unsigned int *)t209);
    t212 = (~(t211));
    t213 = *((unsigned int *)t184);
    t214 = (t213 & t212);
    t215 = *((unsigned int *)t210);
    t216 = (~(t215));
    t217 = *((unsigned int *)t194);
    t218 = (t217 & t216);
    t219 = (~(t214));
    t220 = (~(t218));
    t221 = *((unsigned int *)t201);
    *((unsigned int *)t201) = (t221 & t219);
    t222 = *((unsigned int *)t201);
    *((unsigned int *)t201) = (t222 & t220);
    goto LAB60;

LAB61:    t243 = *((unsigned int *)t226);
    t244 = (t243 + 0);
    t245 = *((unsigned int *)t224);
    t246 = *((unsigned int *)t225);
    t247 = (t245 - t246);
    t248 = (t247 + 1);
    xsi_vlogvar_wait_assign_value(t223, t195, t244, *((unsigned int *)t225), t248, 100000LL);
    goto LAB62;

LAB63:    t12 = *((unsigned int *)t28);
    t173 = (t12 + 0);
    t13 = *((unsigned int *)t7);
    t16 = *((unsigned int *)t21);
    t214 = (t13 - t16);
    t218 = (t214 + 1);
    xsi_vlogvar_wait_assign_value(t2, t249, t173, *((unsigned int *)t21), t218, 100000LL);
    goto LAB64;

LAB65:    *((unsigned int *)t7) = 1;
    goto LAB68;

LAB67:    t4 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB68;

LAB69:    t6 = (t0 + 3384);
    t8 = (t6 + 56U);
    t14 = *((char **)t8);
    memset(t21, 0, 8);
    t15 = (t14 + 4);
    t22 = *((unsigned int *)t15);
    t23 = (~(t22));
    t24 = *((unsigned int *)t14);
    t25 = (t24 & t23);
    t26 = (t25 & 1U);
    if (t26 != 0)
        goto LAB75;

LAB73:    if (*((unsigned int *)t15) == 0)
        goto LAB72;

LAB74:    t19 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t19) = 1;

LAB75:    t20 = (t21 + 4);
    t27 = (t14 + 4);
    t29 = *((unsigned int *)t14);
    t30 = (~(t29));
    *((unsigned int *)t21) = t30;
    *((unsigned int *)t20) = 0;
    if (*((unsigned int *)t27) != 0)
        goto LAB77;

LAB76:    t38 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t38 & 1U);
    t39 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t39 & 1U);
    memset(t28, 0, 8);
    t32 = (t21 + 4);
    t40 = *((unsigned int *)t32);
    t41 = (~(t40));
    t44 = *((unsigned int *)t21);
    t45 = (t44 & t41);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t32) != 0)
        goto LAB80;

LAB81:    t34 = (t28 + 4);
    t47 = *((unsigned int *)t28);
    t48 = (!(t47));
    t49 = *((unsigned int *)t34);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB82;

LAB83:    memcpy(t82, t28, 8);

LAB84:    memset(t110, 0, 8);
    t97 = (t82 + 4);
    t107 = *((unsigned int *)t97);
    t108 = (~(t107));
    t109 = *((unsigned int *)t82);
    t112 = (t109 & t108);
    t113 = (t112 & 1U);
    if (t113 != 0)
        goto LAB98;

LAB99:    if (*((unsigned int *)t97) != 0)
        goto LAB100;

LAB101:    t114 = *((unsigned int *)t7);
    t115 = *((unsigned int *)t110);
    t116 = (t114 & t115);
    *((unsigned int *)t123) = t116;
    t117 = (t7 + 4);
    t118 = (t110 + 4);
    t124 = (t123 + 4);
    t119 = *((unsigned int *)t117);
    t120 = *((unsigned int *)t118);
    t121 = (t119 | t120);
    *((unsigned int *)t124) = t121;
    t122 = *((unsigned int *)t124);
    t126 = (t122 != 0);
    if (t126 == 1)
        goto LAB102;

LAB103:
LAB104:    goto LAB71;

LAB72:    *((unsigned int *)t21) = 1;
    goto LAB75;

LAB77:    t31 = *((unsigned int *)t21);
    t35 = *((unsigned int *)t27);
    *((unsigned int *)t21) = (t31 | t35);
    t36 = *((unsigned int *)t20);
    t37 = *((unsigned int *)t27);
    *((unsigned int *)t20) = (t36 | t37);
    goto LAB76;

LAB78:    *((unsigned int *)t28) = 1;
    goto LAB81;

LAB80:    t33 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB81;

LAB82:    t42 = (t0 + 2824U);
    t43 = *((char **)t42);
    memset(t60, 0, 8);
    t42 = (t43 + 4);
    t51 = *((unsigned int *)t42);
    t54 = (~(t51));
    t55 = *((unsigned int *)t43);
    t56 = (t55 & t54);
    t57 = (t56 & 1U);
    if (t57 != 0)
        goto LAB88;

LAB86:    if (*((unsigned int *)t42) == 0)
        goto LAB85;

LAB87:    t61 = (t60 + 4);
    *((unsigned int *)t60) = 1;
    *((unsigned int *)t61) = 1;

LAB88:    t67 = (t60 + 4);
    t68 = (t43 + 4);
    t58 = *((unsigned int *)t43);
    t59 = (~(t58));
    *((unsigned int *)t60) = t59;
    *((unsigned int *)t67) = 0;
    if (*((unsigned int *)t68) != 0)
        goto LAB90;

LAB89:    t66 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t66 & 1U);
    t69 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t69 & 1U);
    memset(t75, 0, 8);
    t73 = (t60 + 4);
    t70 = *((unsigned int *)t73);
    t71 = (~(t70));
    t72 = *((unsigned int *)t60);
    t76 = (t72 & t71);
    t77 = (t76 & 1U);
    if (t77 != 0)
        goto LAB91;

LAB92:    if (*((unsigned int *)t73) != 0)
        goto LAB93;

LAB94:    t78 = *((unsigned int *)t28);
    t79 = *((unsigned int *)t75);
    t80 = (t78 | t79);
    *((unsigned int *)t82) = t80;
    t81 = (t28 + 4);
    t86 = (t75 + 4);
    t87 = (t82 + 4);
    t83 = *((unsigned int *)t81);
    t84 = *((unsigned int *)t86);
    t85 = (t83 | t84);
    *((unsigned int *)t87) = t85;
    t89 = *((unsigned int *)t87);
    t90 = (t89 != 0);
    if (t90 == 1)
        goto LAB95;

LAB96:
LAB97:    goto LAB84;

LAB85:    *((unsigned int *)t60) = 1;
    goto LAB88;

LAB90:    t62 = *((unsigned int *)t60);
    t63 = *((unsigned int *)t68);
    *((unsigned int *)t60) = (t62 | t63);
    t64 = *((unsigned int *)t67);
    t65 = *((unsigned int *)t68);
    *((unsigned int *)t67) = (t64 | t65);
    goto LAB89;

LAB91:    *((unsigned int *)t75) = 1;
    goto LAB94;

LAB93:    t74 = (t75 + 4);
    *((unsigned int *)t75) = 1;
    *((unsigned int *)t74) = 1;
    goto LAB94;

LAB95:    t91 = *((unsigned int *)t82);
    t92 = *((unsigned int *)t87);
    *((unsigned int *)t82) = (t91 | t92);
    t88 = (t28 + 4);
    t96 = (t75 + 4);
    t93 = *((unsigned int *)t88);
    t94 = (~(t93));
    t95 = *((unsigned int *)t28);
    t52 = (t95 & t94);
    t98 = *((unsigned int *)t96);
    t99 = (~(t98));
    t100 = *((unsigned int *)t75);
    t53 = (t100 & t99);
    t102 = (~(t52));
    t103 = (~(t53));
    t104 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t104 & t102);
    t106 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t106 & t103);
    goto LAB97;

LAB98:    *((unsigned int *)t110) = 1;
    goto LAB101;

LAB100:    t111 = (t110 + 4);
    *((unsigned int *)t110) = 1;
    *((unsigned int *)t111) = 1;
    goto LAB101;

LAB102:    t127 = *((unsigned int *)t123);
    t128 = *((unsigned int *)t124);
    *((unsigned int *)t123) = (t127 | t128);
    t125 = (t7 + 4);
    t131 = (t110 + 4);
    t129 = *((unsigned int *)t7);
    t130 = (~(t129));
    t134 = *((unsigned int *)t125);
    t135 = (~(t134));
    t136 = *((unsigned int *)t110);
    t137 = (~(t136));
    t138 = *((unsigned int *)t131);
    t139 = (~(t138));
    t101 = (t130 & t135);
    t105 = (t137 & t139);
    t140 = (~(t101));
    t141 = (~(t105));
    t144 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t144 & t140);
    t145 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t145 & t141);
    t146 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t146 & t140);
    t147 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t147 & t141);
    goto LAB104;

LAB105:    xsi_set_current_line(161, ng0);

LAB108:    xsi_set_current_line(162, ng0);
    t133 = (t0 + 4024);
    t143 = (t133 + 56U);
    t149 = *((char **)t143);
    xsi_vlog_get_part_select_value(t249, 34, t149, 62, 29);
    t154 = (t0 + 4024);
    t155 = (t0 + 4024);
    t156 = (t155 + 72U);
    t164 = *((char **)t156);
    t165 = ((char*)((ng7)));
    t178 = ((char*)((ng9)));
    xsi_vlog_convert_partindices(t142, t150, t184, ((int*)(t164)), 2, t165, 32, 1, t178, 32, 1);
    t185 = (t142 + 4);
    t158 = *((unsigned int *)t185);
    t169 = (!(t158));
    t186 = (t150 + 4);
    t159 = *((unsigned int *)t186);
    t173 = (!(t159));
    t214 = (t169 && t173);
    t187 = (t184 + 4);
    t160 = *((unsigned int *)t187);
    t218 = (!(t160));
    t234 = (t214 && t218);
    if (t234 == 1)
        goto LAB109;

LAB110:    xsi_set_current_line(163, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 15);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 15);
    t16 = (t13 & 1);
    *((unsigned int *)t5) = t16;
    t8 = (t0 + 4024);
    t14 = (t8 + 56U);
    t15 = *((char **)t14);
    memset(t21, 0, 8);
    t19 = (t21 + 4);
    t20 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = (t17 >> 12);
    t22 = (t18 & 1);
    *((unsigned int *)t21) = t22;
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 12);
    t25 = (t24 & 1);
    *((unsigned int *)t19) = t25;
    t26 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t21);
    t30 = (t26 ^ t29);
    *((unsigned int *)t28) = t30;
    t27 = (t7 + 4);
    t32 = (t21 + 4);
    t33 = (t28 + 4);
    t31 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t32);
    t36 = (t31 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB111;

LAB112:
LAB113:    t34 = (t0 + 4024);
    t42 = (t34 + 56U);
    t43 = *((char **)t42);
    memset(t60, 0, 8);
    t61 = (t60 + 4);
    t67 = (t43 + 4);
    t41 = *((unsigned int *)t43);
    t44 = (t41 >> 4);
    t45 = (t44 & 1);
    *((unsigned int *)t60) = t45;
    t46 = *((unsigned int *)t67);
    t47 = (t46 >> 4);
    t48 = (t47 & 1);
    *((unsigned int *)t61) = t48;
    t49 = *((unsigned int *)t28);
    t50 = *((unsigned int *)t60);
    t51 = (t49 ^ t50);
    *((unsigned int *)t75) = t51;
    t68 = (t28 + 4);
    t73 = (t60 + 4);
    t74 = (t75 + 4);
    t54 = *((unsigned int *)t68);
    t55 = *((unsigned int *)t73);
    t56 = (t54 | t55);
    *((unsigned int *)t74) = t56;
    t57 = *((unsigned int *)t74);
    t58 = (t57 != 0);
    if (t58 == 1)
        goto LAB114;

LAB115:
LAB116:    t81 = (t0 + 4024);
    t86 = (t81 + 56U);
    t87 = *((char **)t86);
    memset(t82, 0, 8);
    t88 = (t82 + 4);
    t96 = (t87 + 4);
    t63 = *((unsigned int *)t87);
    t64 = (t63 >> 0);
    t65 = (t64 & 1);
    *((unsigned int *)t82) = t65;
    t66 = *((unsigned int *)t96);
    t69 = (t66 >> 0);
    t70 = (t69 & 1);
    *((unsigned int *)t88) = t70;
    t71 = *((unsigned int *)t75);
    t72 = *((unsigned int *)t82);
    t76 = (t71 ^ t72);
    *((unsigned int *)t110) = t76;
    t97 = (t75 + 4);
    t111 = (t82 + 4);
    t117 = (t110 + 4);
    t77 = *((unsigned int *)t97);
    t78 = *((unsigned int *)t111);
    t79 = (t77 | t78);
    *((unsigned int *)t117) = t79;
    t80 = *((unsigned int *)t117);
    t83 = (t80 != 0);
    if (t83 == 1)
        goto LAB117;

LAB118:
LAB119:    t118 = (t0 + 4024);
    t124 = (t0 + 4024);
    t125 = (t124 + 72U);
    t131 = *((char **)t125);
    t132 = ((char*)((ng10)));
    xsi_vlog_generic_convert_bit_index(t123, t131, 2, t132, 32, 1);
    t133 = (t123 + 4);
    t89 = *((unsigned int *)t133);
    t52 = (!(t89));
    if (t52 == 1)
        goto LAB120;

LAB121:    xsi_set_current_line(164, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 7);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t6);
    t12 = (t11 >> 7);
    *((unsigned int *)t5) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 2097151U);
    t16 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t16 & 2097151U);
    t8 = (t0 + 4024);
    t14 = (t0 + 4024);
    t15 = (t14 + 72U);
    t19 = *((char **)t15);
    t20 = ((char*)((ng11)));
    t27 = ((char*)((ng12)));
    xsi_vlog_convert_partindices(t21, t28, t60, ((int*)(t19)), 2, t20, 32, 1, t27, 32, 1);
    t32 = (t21 + 4);
    t17 = *((unsigned int *)t32);
    t52 = (!(t17));
    t33 = (t28 + 4);
    t18 = *((unsigned int *)t33);
    t53 = (!(t18));
    t101 = (t52 && t53);
    t34 = (t60 + 4);
    t22 = *((unsigned int *)t34);
    t105 = (!(t22));
    t169 = (t101 && t105);
    if (t169 == 1)
        goto LAB122;

LAB123:    xsi_set_current_line(165, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 31);
    t16 = (t13 & 1);
    *((unsigned int *)t5) = t16;
    t8 = (t0 + 4024);
    t14 = (t8 + 56U);
    t15 = *((char **)t14);
    memset(t21, 0, 8);
    t19 = (t21 + 4);
    t20 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = (t17 >> 6);
    t22 = (t18 & 1);
    *((unsigned int *)t21) = t22;
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 6);
    t25 = (t24 & 1);
    *((unsigned int *)t19) = t25;
    t26 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t21);
    t30 = (t26 ^ t29);
    *((unsigned int *)t28) = t30;
    t27 = (t7 + 4);
    t32 = (t21 + 4);
    t33 = (t28 + 4);
    t31 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t32);
    t36 = (t31 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB124;

LAB125:
LAB126:    t34 = (t0 + 4024);
    t42 = (t0 + 4024);
    t43 = (t42 + 72U);
    t61 = *((char **)t43);
    t67 = ((char*)((ng13)));
    xsi_vlog_generic_convert_bit_index(t60, t61, 2, t67, 32, 1);
    t68 = (t60 + 4);
    t41 = *((unsigned int *)t68);
    t52 = (!(t41));
    if (t52 == 1)
        goto LAB127;

LAB128:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 31);
    t16 = (t13 & 1);
    *((unsigned int *)t5) = t16;
    t8 = (t0 + 4024);
    t14 = (t8 + 56U);
    t15 = *((char **)t14);
    memset(t21, 0, 8);
    t19 = (t21 + 4);
    t20 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = (t17 >> 5);
    t22 = (t18 & 1);
    *((unsigned int *)t21) = t22;
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 5);
    t25 = (t24 & 1);
    *((unsigned int *)t19) = t25;
    t26 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t21);
    t30 = (t26 ^ t29);
    *((unsigned int *)t28) = t30;
    t27 = (t7 + 4);
    t32 = (t21 + 4);
    t33 = (t28 + 4);
    t31 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t32);
    t36 = (t31 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB129;

LAB130:
LAB131:    t34 = (t0 + 4024);
    t42 = (t0 + 4024);
    t43 = (t42 + 72U);
    t61 = *((char **)t43);
    t67 = ((char*)((ng14)));
    xsi_vlog_generic_convert_bit_index(t60, t61, 2, t67, 32, 1);
    t68 = (t60 + 4);
    t41 = *((unsigned int *)t68);
    t52 = (!(t41));
    if (t52 == 1)
        goto LAB132;

LAB133:    xsi_set_current_line(167, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 2);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t6);
    t12 = (t11 >> 2);
    *((unsigned int *)t5) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 7U);
    t16 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t16 & 7U);
    t8 = (t0 + 4024);
    t14 = (t0 + 4024);
    t15 = (t14 + 72U);
    t19 = *((char **)t15);
    t20 = ((char*)((ng15)));
    t27 = ((char*)((ng6)));
    xsi_vlog_convert_partindices(t21, t28, t60, ((int*)(t19)), 2, t20, 32, 1, t27, 32, 1);
    t32 = (t21 + 4);
    t17 = *((unsigned int *)t32);
    t52 = (!(t17));
    t33 = (t28 + 4);
    t18 = *((unsigned int *)t33);
    t53 = (!(t18));
    t101 = (t52 && t53);
    t34 = (t60 + 4);
    t22 = *((unsigned int *)t34);
    t105 = (!(t22));
    t169 = (t101 && t105);
    if (t169 == 1)
        goto LAB134;

LAB135:    xsi_set_current_line(168, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 31);
    t16 = (t13 & 1);
    *((unsigned int *)t5) = t16;
    t8 = (t0 + 4024);
    t14 = (t8 + 56U);
    t15 = *((char **)t14);
    memset(t21, 0, 8);
    t19 = (t21 + 4);
    t20 = (t15 + 4);
    t17 = *((unsigned int *)t15);
    t18 = (t17 >> 1);
    t22 = (t18 & 1);
    *((unsigned int *)t21) = t22;
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 1);
    t25 = (t24 & 1);
    *((unsigned int *)t19) = t25;
    t26 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t21);
    t30 = (t26 ^ t29);
    *((unsigned int *)t28) = t30;
    t27 = (t7 + 4);
    t32 = (t21 + 4);
    t33 = (t28 + 4);
    t31 = *((unsigned int *)t27);
    t35 = *((unsigned int *)t32);
    t36 = (t31 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB136;

LAB137:
LAB138:    t34 = (t0 + 4024);
    t42 = (t0 + 4024);
    t43 = (t42 + 72U);
    t61 = *((char **)t43);
    t67 = ((char*)((ng16)));
    xsi_vlog_generic_convert_bit_index(t60, t61, 2, t67, 32, 1);
    t68 = (t60 + 4);
    t41 = *((unsigned int *)t68);
    t52 = (!(t41));
    if (t52 == 1)
        goto LAB139;

LAB140:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 0);
    t16 = (t13 & 1);
    *((unsigned int *)t5) = t16;
    t8 = (t0 + 4024);
    t14 = (t0 + 4024);
    t15 = (t14 + 72U);
    t19 = *((char **)t15);
    t20 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t21, t19, 2, t20, 32, 1);
    t27 = (t21 + 4);
    t17 = *((unsigned int *)t27);
    t52 = (!(t17));
    if (t52 == 1)
        goto LAB141;

LAB142:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 31);
    t16 = (t13 & 1);
    *((unsigned int *)t5) = t16;
    t8 = (t0 + 4024);
    t14 = (t0 + 4024);
    t15 = (t14 + 72U);
    t19 = *((char **)t15);
    t20 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t21, t19, 2, t20, 32, 1);
    t27 = (t21 + 4);
    t17 = *((unsigned int *)t27);
    t52 = (!(t17));
    if (t52 == 1)
        goto LAB143;

LAB144:    goto LAB107;

LAB109:    t161 = *((unsigned int *)t184);
    t237 = (t161 + 0);
    t162 = *((unsigned int *)t142);
    t163 = *((unsigned int *)t150);
    t238 = (t162 - t163);
    t241 = (t238 + 1);
    xsi_vlogvar_wait_assign_value(t154, t249, t237, *((unsigned int *)t150), t241, 100000LL);
    goto LAB110;

LAB111:    t39 = *((unsigned int *)t28);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t28) = (t39 | t40);
    goto LAB113;

LAB114:    t59 = *((unsigned int *)t75);
    t62 = *((unsigned int *)t74);
    *((unsigned int *)t75) = (t59 | t62);
    goto LAB116;

LAB117:    t84 = *((unsigned int *)t110);
    t85 = *((unsigned int *)t117);
    *((unsigned int *)t110) = (t84 | t85);
    goto LAB119;

LAB120:    xsi_vlogvar_wait_assign_value(t118, t110, 0, *((unsigned int *)t123), 1, 100000LL);
    goto LAB121;

LAB122:    t23 = *((unsigned int *)t60);
    t173 = (t23 + 0);
    t24 = *((unsigned int *)t21);
    t25 = *((unsigned int *)t28);
    t214 = (t24 - t25);
    t218 = (t214 + 1);
    xsi_vlogvar_wait_assign_value(t8, t7, t173, *((unsigned int *)t28), t218, 100000LL);
    goto LAB123;

LAB124:    t39 = *((unsigned int *)t28);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t28) = (t39 | t40);
    goto LAB126;

LAB127:    xsi_vlogvar_wait_assign_value(t34, t28, 0, *((unsigned int *)t60), 1, 100000LL);
    goto LAB128;

LAB129:    t39 = *((unsigned int *)t28);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t28) = (t39 | t40);
    goto LAB131;

LAB132:    xsi_vlogvar_wait_assign_value(t34, t28, 0, *((unsigned int *)t60), 1, 100000LL);
    goto LAB133;

LAB134:    t23 = *((unsigned int *)t60);
    t173 = (t23 + 0);
    t24 = *((unsigned int *)t21);
    t25 = *((unsigned int *)t28);
    t214 = (t24 - t25);
    t218 = (t214 + 1);
    xsi_vlogvar_wait_assign_value(t8, t7, t173, *((unsigned int *)t28), t218, 100000LL);
    goto LAB135;

LAB136:    t39 = *((unsigned int *)t28);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t28) = (t39 | t40);
    goto LAB138;

LAB139:    xsi_vlogvar_wait_assign_value(t34, t28, 0, *((unsigned int *)t60), 1, 100000LL);
    goto LAB140;

LAB141:    xsi_vlogvar_wait_assign_value(t8, t7, 0, *((unsigned int *)t21), 1, 100000LL);
    goto LAB142;

LAB143:    xsi_vlogvar_wait_assign_value(t8, t7, 0, *((unsigned int *)t21), 1, 100000LL);
    goto LAB144;

}

static void Always_174_3(char *t0)
{
    char t4[16];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 6000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 6616);
    *((int *)t2) = 1;
    t3 = (t0 + 6032);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(174, ng0);

LAB5:    xsi_set_current_line(175, ng0);
    t5 = (t0 + 4024);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_get_part_select_value(t4, 64, t7, 63, 0);
    t8 = (t0 + 3864);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 64);
    goto LAB2;

}

static void Cont_178_4(char *t0)
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

LAB0:    t1 = (t0 + 6248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(178, ng0);
    t2 = (t0 + 3864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6712);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t4, 0, 64);
    xsi_driver_vfirst_trans(t5, 0, 63);
    t10 = (t0 + 6632);
    *((int *)t10) = 1;

LAB1:    return;
}


extern void work_m_07000823412491611143_1726891099_init()
{
	static char *pe[] = {(void *)Always_128_0,(void *)Always_137_1,(void *)Always_154_2,(void *)Always_174_3,(void *)Cont_178_4};
	static char *se[] = {(void *)sp_clogb2};
	xsi_register_didat("work_m_07000823412491611143_1726891099", "isim/PicoTestbench_isim_beh.exe.sim/work/m_07000823412491611143_1726891099.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
