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
static unsigned int ng1[] = {0U, 0U};



static void Cont_3860_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t5[8];
    char t34[8];
    char t57[8];
    char t58[8];
    char t59[8];
    char t89[8];
    char *t1;
    char *t2;
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
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
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
    unsigned int t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    char *t113;
    char *t114;
    char *t115;
    char *t116;
    char *t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    char *t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;

LAB0:    t1 = (t0 + 4120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3860, ng0);
    t2 = (t0 + 2008U);
    t6 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t6 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t2) == 0)
        goto LAB4;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t5 + 4);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    *((unsigned int *)t5) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB9;

LAB8:    t21 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    memset(t4, 0, 8);
    t23 = (t5 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t5);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) != 0)
        goto LAB12;

LAB13:    t30 = (t4 + 4);
    t31 = *((unsigned int *)t4);
    t32 = *((unsigned int *)t30);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB14;

LAB15:    t53 = *((unsigned int *)t4);
    t54 = (~(t53));
    t55 = *((unsigned int *)t30);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t30) > 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t4) > 0)
        goto LAB20;

LAB21:    memcpy(t3, t57, 8);

LAB22:    t113 = (t0 + 4784);
    t114 = (t113 + 56U);
    t115 = *((char **)t114);
    t116 = (t115 + 56U);
    t117 = *((char **)t116);
    memset(t117, 0, 8);
    t118 = 1U;
    t119 = t118;
    t120 = (t3 + 4);
    t121 = *((unsigned int *)t3);
    t118 = (t118 & t121);
    t122 = *((unsigned int *)t120);
    t119 = (t119 & t122);
    t123 = (t117 + 4);
    t124 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t124 | t118);
    t125 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t125 | t119);
    xsi_driver_vfirst_trans(t113, 0, 0);
    t126 = (t0 + 4688);
    *((int *)t126) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB9:    t17 = *((unsigned int *)t5);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t5) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB8;

LAB10:    *((unsigned int *)t4) = 1;
    goto LAB13;

LAB12:    t29 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB13;

LAB14:    t35 = (t0 + 2968U);
    t36 = *((char **)t35);
    memset(t34, 0, 8);
    t35 = (t36 + 4);
    t37 = *((unsigned int *)t35);
    t38 = (~(t37));
    t39 = *((unsigned int *)t36);
    t40 = (t39 & t38);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB26;

LAB24:    if (*((unsigned int *)t35) == 0)
        goto LAB23;

LAB25:    t42 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t42) = 1;

LAB26:    t43 = (t34 + 4);
    t44 = (t36 + 4);
    t45 = *((unsigned int *)t36);
    t46 = (~(t45));
    *((unsigned int *)t34) = t46;
    *((unsigned int *)t43) = 0;
    if (*((unsigned int *)t44) != 0)
        goto LAB28;

LAB27:    t51 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t51 & 1U);
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t52 & 1U);
    goto LAB15;

LAB16:    t60 = (t0 + 1848U);
    t61 = *((char **)t60);
    memset(t59, 0, 8);
    t60 = (t61 + 4);
    t62 = *((unsigned int *)t60);
    t63 = (~(t62));
    t64 = *((unsigned int *)t61);
    t65 = (t64 & t63);
    t66 = (t65 & 1U);
    if (t66 != 0)
        goto LAB32;

LAB30:    if (*((unsigned int *)t60) == 0)
        goto LAB29;

LAB31:    t67 = (t59 + 4);
    *((unsigned int *)t59) = 1;
    *((unsigned int *)t67) = 1;

LAB32:    t68 = (t59 + 4);
    t69 = (t61 + 4);
    t70 = *((unsigned int *)t61);
    t71 = (~(t70));
    *((unsigned int *)t59) = t71;
    *((unsigned int *)t68) = 0;
    if (*((unsigned int *)t69) != 0)
        goto LAB34;

LAB33:    t76 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t76 & 1U);
    t77 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t77 & 1U);
    memset(t58, 0, 8);
    t78 = (t59 + 4);
    t79 = *((unsigned int *)t78);
    t80 = (~(t79));
    t81 = *((unsigned int *)t59);
    t82 = (t81 & t80);
    t83 = (t82 & 1U);
    if (t83 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t78) != 0)
        goto LAB37;

LAB38:    t85 = (t58 + 4);
    t86 = *((unsigned int *)t58);
    t87 = *((unsigned int *)t85);
    t88 = (t86 || t87);
    if (t88 > 0)
        goto LAB39;

LAB40:    t108 = *((unsigned int *)t58);
    t109 = (~(t108));
    t110 = *((unsigned int *)t85);
    t111 = (t109 || t110);
    if (t111 > 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t85) > 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t58) > 0)
        goto LAB45;

LAB46:    memcpy(t57, t112, 8);

LAB47:    goto LAB17;

LAB18:    xsi_vlog_unsigned_bit_combine(t3, 1, t34, 1, t57, 1);
    goto LAB22;

LAB20:    memcpy(t3, t34, 8);
    goto LAB22;

LAB23:    *((unsigned int *)t34) = 1;
    goto LAB26;

LAB28:    t47 = *((unsigned int *)t34);
    t48 = *((unsigned int *)t44);
    *((unsigned int *)t34) = (t47 | t48);
    t49 = *((unsigned int *)t43);
    t50 = *((unsigned int *)t44);
    *((unsigned int *)t43) = (t49 | t50);
    goto LAB27;

LAB29:    *((unsigned int *)t59) = 1;
    goto LAB32;

LAB34:    t72 = *((unsigned int *)t59);
    t73 = *((unsigned int *)t69);
    *((unsigned int *)t59) = (t72 | t73);
    t74 = *((unsigned int *)t68);
    t75 = *((unsigned int *)t69);
    *((unsigned int *)t68) = (t74 | t75);
    goto LAB33;

LAB35:    *((unsigned int *)t58) = 1;
    goto LAB38;

LAB37:    t84 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB38;

LAB39:    t90 = (t0 + 2648U);
    t91 = *((char **)t90);
    memset(t89, 0, 8);
    t90 = (t91 + 4);
    t92 = *((unsigned int *)t90);
    t93 = (~(t92));
    t94 = *((unsigned int *)t91);
    t95 = (t94 & t93);
    t96 = (t95 & 1U);
    if (t96 != 0)
        goto LAB51;

LAB49:    if (*((unsigned int *)t90) == 0)
        goto LAB48;

LAB50:    t97 = (t89 + 4);
    *((unsigned int *)t89) = 1;
    *((unsigned int *)t97) = 1;

LAB51:    t98 = (t89 + 4);
    t99 = (t91 + 4);
    t100 = *((unsigned int *)t91);
    t101 = (~(t100));
    *((unsigned int *)t89) = t101;
    *((unsigned int *)t98) = 0;
    if (*((unsigned int *)t99) != 0)
        goto LAB53;

LAB52:    t106 = *((unsigned int *)t89);
    *((unsigned int *)t89) = (t106 & 1U);
    t107 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t107 & 1U);
    goto LAB40;

LAB41:    t112 = ((char*)((ng1)));
    goto LAB42;

LAB43:    xsi_vlog_unsigned_bit_combine(t57, 1, t89, 1, t112, 1);
    goto LAB47;

LAB45:    memcpy(t57, t89, 8);
    goto LAB47;

LAB48:    *((unsigned int *)t89) = 1;
    goto LAB51;

LAB53:    t102 = *((unsigned int *)t89);
    t103 = *((unsigned int *)t99);
    *((unsigned int *)t89) = (t102 | t103);
    t104 = *((unsigned int *)t98);
    t105 = *((unsigned int *)t99);
    *((unsigned int *)t98) = (t104 | t105);
    goto LAB52;

}

static void Cont_3861_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t5[8];
    char t34[8];
    char t57[8];
    char t58[8];
    char t59[8];
    char t89[8];
    char *t1;
    char *t2;
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
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
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
    unsigned int t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    char *t113;
    char *t114;
    char *t115;
    char *t116;
    char *t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    char *t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;

LAB0:    t1 = (t0 + 4368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3861, ng0);
    t2 = (t0 + 2008U);
    t6 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t6 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t2) == 0)
        goto LAB4;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t5 + 4);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    *((unsigned int *)t5) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB9;

LAB8:    t21 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    memset(t4, 0, 8);
    t23 = (t5 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t5);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) != 0)
        goto LAB12;

LAB13:    t30 = (t4 + 4);
    t31 = *((unsigned int *)t4);
    t32 = *((unsigned int *)t30);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB14;

LAB15:    t53 = *((unsigned int *)t4);
    t54 = (~(t53));
    t55 = *((unsigned int *)t30);
    t56 = (t54 || t55);
    if (t56 > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t30) > 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t4) > 0)
        goto LAB20;

LAB21:    memcpy(t3, t57, 8);

LAB22:    t113 = (t0 + 4848);
    t114 = (t113 + 56U);
    t115 = *((char **)t114);
    t116 = (t115 + 56U);
    t117 = *((char **)t116);
    memset(t117, 0, 8);
    t118 = 1U;
    t119 = t118;
    t120 = (t3 + 4);
    t121 = *((unsigned int *)t3);
    t118 = (t118 & t121);
    t122 = *((unsigned int *)t120);
    t119 = (t119 & t122);
    t123 = (t117 + 4);
    t124 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t124 | t118);
    t125 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t125 | t119);
    xsi_driver_vfirst_trans(t113, 0, 0);
    t126 = (t0 + 4704);
    *((int *)t126) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB9:    t17 = *((unsigned int *)t5);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t5) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB8;

LAB10:    *((unsigned int *)t4) = 1;
    goto LAB13;

LAB12:    t29 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB13;

LAB14:    t35 = (t0 + 2808U);
    t36 = *((char **)t35);
    memset(t34, 0, 8);
    t35 = (t36 + 4);
    t37 = *((unsigned int *)t35);
    t38 = (~(t37));
    t39 = *((unsigned int *)t36);
    t40 = (t39 & t38);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB26;

LAB24:    if (*((unsigned int *)t35) == 0)
        goto LAB23;

LAB25:    t42 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t42) = 1;

LAB26:    t43 = (t34 + 4);
    t44 = (t36 + 4);
    t45 = *((unsigned int *)t36);
    t46 = (~(t45));
    *((unsigned int *)t34) = t46;
    *((unsigned int *)t43) = 0;
    if (*((unsigned int *)t44) != 0)
        goto LAB28;

LAB27:    t51 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t51 & 1U);
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t52 & 1U);
    goto LAB15;

LAB16:    t60 = (t0 + 1848U);
    t61 = *((char **)t60);
    memset(t59, 0, 8);
    t60 = (t61 + 4);
    t62 = *((unsigned int *)t60);
    t63 = (~(t62));
    t64 = *((unsigned int *)t61);
    t65 = (t64 & t63);
    t66 = (t65 & 1U);
    if (t66 != 0)
        goto LAB32;

LAB30:    if (*((unsigned int *)t60) == 0)
        goto LAB29;

LAB31:    t67 = (t59 + 4);
    *((unsigned int *)t59) = 1;
    *((unsigned int *)t67) = 1;

LAB32:    t68 = (t59 + 4);
    t69 = (t61 + 4);
    t70 = *((unsigned int *)t61);
    t71 = (~(t70));
    *((unsigned int *)t59) = t71;
    *((unsigned int *)t68) = 0;
    if (*((unsigned int *)t69) != 0)
        goto LAB34;

LAB33:    t76 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t76 & 1U);
    t77 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t77 & 1U);
    memset(t58, 0, 8);
    t78 = (t59 + 4);
    t79 = *((unsigned int *)t78);
    t80 = (~(t79));
    t81 = *((unsigned int *)t59);
    t82 = (t81 & t80);
    t83 = (t82 & 1U);
    if (t83 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t78) != 0)
        goto LAB37;

LAB38:    t85 = (t58 + 4);
    t86 = *((unsigned int *)t58);
    t87 = *((unsigned int *)t85);
    t88 = (t86 || t87);
    if (t88 > 0)
        goto LAB39;

LAB40:    t108 = *((unsigned int *)t58);
    t109 = (~(t108));
    t110 = *((unsigned int *)t85);
    t111 = (t109 || t110);
    if (t111 > 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t85) > 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t58) > 0)
        goto LAB45;

LAB46:    memcpy(t57, t112, 8);

LAB47:    goto LAB17;

LAB18:    xsi_vlog_unsigned_bit_combine(t3, 1, t34, 1, t57, 1);
    goto LAB22;

LAB20:    memcpy(t3, t34, 8);
    goto LAB22;

LAB23:    *((unsigned int *)t34) = 1;
    goto LAB26;

LAB28:    t47 = *((unsigned int *)t34);
    t48 = *((unsigned int *)t44);
    *((unsigned int *)t34) = (t47 | t48);
    t49 = *((unsigned int *)t43);
    t50 = *((unsigned int *)t44);
    *((unsigned int *)t43) = (t49 | t50);
    goto LAB27;

LAB29:    *((unsigned int *)t59) = 1;
    goto LAB32;

LAB34:    t72 = *((unsigned int *)t59);
    t73 = *((unsigned int *)t69);
    *((unsigned int *)t59) = (t72 | t73);
    t74 = *((unsigned int *)t68);
    t75 = *((unsigned int *)t69);
    *((unsigned int *)t68) = (t74 | t75);
    goto LAB33;

LAB35:    *((unsigned int *)t58) = 1;
    goto LAB38;

LAB37:    t84 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB38;

LAB39:    t90 = (t0 + 2488U);
    t91 = *((char **)t90);
    memset(t89, 0, 8);
    t90 = (t91 + 4);
    t92 = *((unsigned int *)t90);
    t93 = (~(t92));
    t94 = *((unsigned int *)t91);
    t95 = (t94 & t93);
    t96 = (t95 & 1U);
    if (t96 != 0)
        goto LAB51;

LAB49:    if (*((unsigned int *)t90) == 0)
        goto LAB48;

LAB50:    t97 = (t89 + 4);
    *((unsigned int *)t89) = 1;
    *((unsigned int *)t97) = 1;

LAB51:    t98 = (t89 + 4);
    t99 = (t91 + 4);
    t100 = *((unsigned int *)t91);
    t101 = (~(t100));
    *((unsigned int *)t89) = t101;
    *((unsigned int *)t98) = 0;
    if (*((unsigned int *)t99) != 0)
        goto LAB53;

LAB52:    t106 = *((unsigned int *)t89);
    *((unsigned int *)t89) = (t106 & 1U);
    t107 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t107 & 1U);
    goto LAB40;

LAB41:    t112 = ((char*)((ng1)));
    goto LAB42;

LAB43:    xsi_vlog_unsigned_bit_combine(t57, 1, t89, 1, t112, 1);
    goto LAB47;

LAB45:    memcpy(t57, t89, 8);
    goto LAB47;

LAB48:    *((unsigned int *)t89) = 1;
    goto LAB51;

LAB53:    t102 = *((unsigned int *)t89);
    t103 = *((unsigned int *)t99);
    *((unsigned int *)t89) = (t102 | t103);
    t104 = *((unsigned int *)t98);
    t105 = *((unsigned int *)t99);
    *((unsigned int *)t98) = (t104 | t105);
    goto LAB52;

}


extern void secureip_m_07390568816294199236_0549589381_init()
{
	static char *pe[] = {(void *)Cont_3860_0,(void *)Cont_3861_1};
	xsi_register_didat("secureip_m_07390568816294199236_0549589381", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_07390568816294199236_0549589381.didat");
	xsi_register_executes(pe);
}
