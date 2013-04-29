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
static const char *ng0 = "/home/albertng/SmithWaterman/StreamBandwidthTest/firmware/ISE_m505lx325/source/UserWrapper.v";
static int ng1[] = {1, 0};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};



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
    t3 = (t1 + 7752);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_minus(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 7752);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    xsi_set_current_line(513, ng0);
    xsi_set_current_line(513, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t1 + 7592);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);

LAB3:    t3 = (t1 + 7752);
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
    t17 = (t1 + 7752);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = ((char*)((ng1)));
    memset(t21, 0, 8);
    xsi_vlog_unsigned_rshift(t21, 32, t19, 32, t20, 32);
    t22 = (t1 + 7752);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 32);
    xsi_set_current_line(513, ng0);
    t3 = (t1 + 7592);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 7592);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB3;

}

static void Cont_4743_0(char *t0)
{
    char t5[8];
    char t12[8];
    char t42[8];
    char t49[8];
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
    char *t79;
    char *t80;
    char *t81;
    char *t82;

LAB0:    t1 = (t0 + 8664U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(4743, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5272U);
    t4 = *((char **)t3);
    t3 = (t0 + 5232U);
    t6 = (t3 + 72U);
    t7 = *((char **)t6);
    t8 = (t0 + 5232U);
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
LAB6:    t40 = (t0 + 6232U);
    t41 = *((char **)t40);
    t40 = (t0 + 6192U);
    t43 = (t40 + 72U);
    t44 = *((char **)t43);
    t45 = (t0 + 6192U);
    t46 = (t45 + 48U);
    t47 = *((char **)t46);
    t48 = ((char*)((ng1)));
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
LAB9:    t77 = (t0 + 9856);
    t78 = (t77 + 56U);
    t79 = *((char **)t78);
    t80 = (t79 + 56U);
    t81 = *((char **)t80);
    memcpy(t81, t49, 8);
    xsi_driver_vfirst_trans(t77, 0, 31);
    t82 = (t0 + 9728);
    *((int *)t82) = 1;

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

}

static void Cont_4998_1(char *t0)
{
    char t5[8];
    char t12[8];
    char t42[8];
    char t49[8];
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
    char *t79;
    char *t80;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;

LAB0:    t1 = (t0 + 8912U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(4998, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 5432U);
    t4 = *((char **)t3);
    t3 = (t0 + 5392U);
    t6 = (t3 + 72U);
    t7 = *((char **)t6);
    t8 = (t0 + 5392U);
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
LAB6:    t40 = (t0 + 6392U);
    t41 = *((char **)t40);
    t40 = (t0 + 6352U);
    t43 = (t40 + 72U);
    t44 = *((char **)t43);
    t45 = (t0 + 6352U);
    t46 = (t45 + 48U);
    t47 = *((char **)t46);
    t48 = ((char*)((ng1)));
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
LAB9:    t77 = (t0 + 9920);
    t78 = (t77 + 56U);
    t79 = *((char **)t78);
    t80 = (t79 + 56U);
    t81 = *((char **)t80);
    memset(t81, 0, 8);
    t82 = 1U;
    t83 = t82;
    t84 = (t49 + 4);
    t85 = *((unsigned int *)t49);
    t82 = (t82 & t85);
    t86 = *((unsigned int *)t84);
    t83 = (t83 & t86);
    t87 = (t81 + 4);
    t88 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t88 | t82);
    t89 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t89 | t83);
    xsi_driver_vfirst_trans(t77, 0, 0);
    t90 = (t0 + 9744);
    *((int *)t90) = 1;

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

}

static void Cont_5253_2(char *t0)
{
    char t5[32];
    char t12[32];
    char t57[32];
    char t64[32];
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
    char *t109;
    char *t110;
    char *t111;
    char *t112;

LAB0:    t1 = (t0 + 9160U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5253, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5592U);
    t4 = *((char **)t3);
    t3 = (t0 + 5552U);
    t6 = (t3 + 72U);
    t7 = *((char **)t6);
    t8 = (t0 + 5552U);
    t9 = (t8 + 48U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t5, 128, t4, t7, t10, 2, 1, t11, 32, 1);
    t13 = 0;

LAB7:    t14 = (t13 < 4);
    if (t14 == 1)
        goto LAB8;

LAB9:    t55 = (t0 + 6552U);
    t56 = *((char **)t55);
    t55 = (t0 + 6512U);
    t58 = (t55 + 72U);
    t59 = *((char **)t58);
    t60 = (t0 + 6512U);
    t61 = (t60 + 48U);
    t62 = *((char **)t61);
    t63 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t57, 128, t56, t59, t62, 2, 1, t63, 32, 1);
    t65 = 0;

LAB13:    t66 = (t65 < 4);
    if (t66 == 1)
        goto LAB14;

LAB15:    t107 = (t0 + 9984);
    t108 = (t107 + 56U);
    t109 = *((char **)t108);
    t110 = (t109 + 56U);
    t111 = *((char **)t110);
    xsi_vlog_bit_copy(t111, 0, t64, 0, 128);
    xsi_driver_vfirst_trans(t107, 0, 127);
    t112 = (t0 + 9760);
    *((int *)t112) = 1;

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

LAB0:    t1 = (t0 + 9408U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5508, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 6712U);
    t4 = *((char **)t3);
    t3 = (t0 + 6672U);
    t6 = (t3 + 72U);
    t7 = *((char **)t6);
    t8 = (t0 + 6672U);
    t9 = (t8 + 48U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t5, 128, t4, t7, t10, 2, 1, t11, 32, 1);
    xsi_vlog_get_part_select_value(t12, 128, t5, 127, 0);
    t14 = 0;

LAB7:    t15 = (t14 < 4);
    if (t15 == 1)
        goto LAB8;

LAB9:    t56 = (t0 + 10048);
    t57 = (t56 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    xsi_vlog_bit_copy(t60, 0, t13, 0, 128);
    xsi_driver_vfirst_trans(t56, 0, 127);
    t61 = (t0 + 9776);
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


extern void work_m_11963040569457102825_0546100569_init()
{
	static char *pe[] = {(void *)Cont_4743_0,(void *)Cont_4998_1,(void *)Cont_5253_2,(void *)Cont_5508_3};
	static char *se[] = {(void *)sp_clogb2};
	xsi_register_didat("work_m_11963040569457102825_0546100569", "isim/PicoTestbench_isim_beh.exe.sim/work/m_11963040569457102825_0546100569.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
