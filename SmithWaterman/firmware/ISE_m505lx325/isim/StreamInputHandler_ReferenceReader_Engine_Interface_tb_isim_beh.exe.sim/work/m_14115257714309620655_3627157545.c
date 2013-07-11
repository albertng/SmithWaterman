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
static const char *ng0 = "/afs/cs.stanford.edu/group/evodevo/u/albertng/SmithWaterman/SmithWaterman/firmware/SmithWatermanPE.v";
static int ng1[] = {0, 0};



static void Cont_63_0(char *t0)
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

LAB0:    t1 = (t0 + 8160U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10672);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1023U;
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
    xsi_driver_vfirst_trans(t5, 0, 9);
    t18 = (t0 + 10464);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_64_1(char *t0)
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

LAB0:    t1 = (t0 + 8408U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 5488);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10736);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1023U;
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
    xsi_driver_vfirst_trans(t5, 0, 9);
    t18 = (t0 + 10480);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_65_2(char *t0)
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

LAB0:    t1 = (t0 + 8656U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 5648);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10800);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1023U;
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
    xsi_driver_vfirst_trans(t5, 0, 9);
    t18 = (t0 + 10496);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_66_3(char *t0)
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

LAB0:    t1 = (t0 + 8904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 5008);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10864);
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
    t18 = (t0 + 10512);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_67_4(char *t0)
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

LAB0:    t1 = (t0 + 9152U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10928);
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
    t18 = (t0 + 10528);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_68_5(char *t0)
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

LAB0:    t1 = (t0 + 9400U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10992);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 10544);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_69_6(char *t0)
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

LAB0:    t1 = (t0 + 9648U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 5808);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 11056);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 10560);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_71_7(char *t0)
{
    char t9[8];
    char t33[8];
    char t34[8];
    char t35[8];
    char t36[8];
    char t37[8];
    char t38[8];
    char t66[8];
    char t79[8];
    char t83[8];
    char t84[8];
    char t92[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t10;
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
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    int t58;
    int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    char *t80;
    char *t81;
    char *t82;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
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
    unsigned int t104;
    unsigned int t105;
    char *t106;
    char *t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    int t116;
    int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    char *t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    char *t130;
    char *t131;

LAB0:    t1 = (t0 + 9896U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 10576);
    *((int *)t2) = 1;
    t3 = (t0 + 9928);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(71, ng0);

LAB5:    xsi_set_current_line(72, ng0);
    t4 = (t0 + 5328);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 880);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t6, 10, t8, 32);
    t7 = (t0 + 6128);
    xsi_vlogvar_assign_value(t7, t9, 0, 0, 10);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 5488);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1016);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t4, 10, t6, 32);
    t5 = (t0 + 6288);
    xsi_vlogvar_assign_value(t5, t9, 0, 0, 10);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2208U);
    t3 = *((char **)t2);
    t2 = (t0 + 880);
    t4 = *((char **)t2);
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t3, 10, t4, 32);
    t2 = (t0 + 6448);
    xsi_vlogvar_assign_value(t2, t9, 0, 0, 10);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 2368U);
    t3 = *((char **)t2);
    t2 = (t0 + 1016);
    t4 = *((char **)t2);
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t3, 10, t4, 32);
    t2 = (t0 + 6608);
    xsi_vlogvar_assign_value(t2, t9, 0, 0, 10);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 5008);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2528U);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    t5 = (t4 + 4);
    t7 = (t6 + 4);
    t10 = *((unsigned int *)t4);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = *((unsigned int *)t5);
    t14 = *((unsigned int *)t7);
    t15 = (t13 ^ t14);
    t16 = (t12 | t15);
    t17 = *((unsigned int *)t5);
    t18 = *((unsigned int *)t7);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB9;

LAB6:    if (t19 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t9) = 1;

LAB9:    t22 = (t9 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t9);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 5168);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 744);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t4, 10, t6, 32);
    t5 = (t0 + 6768);
    xsi_vlogvar_assign_value(t5, t9, 0, 0, 10);

LAB12:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 6128);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6288);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t34, 0, 8);
    xsi_vlog_signed_greater(t34, 10, t4, 10, t7, 10);
    t8 = (t34 + 4);
    t10 = *((unsigned int *)t8);
    t11 = (~(t10));
    t12 = *((unsigned int *)t34);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB13;

LAB14:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 6288);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6928);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);

LAB15:    xsi_set_current_line(88, ng0);
    t2 = (t0 + 6448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6608);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t34, 0, 8);
    xsi_vlog_signed_greater(t34, 10, t4, 10, t7, 10);
    t8 = (t34 + 4);
    t10 = *((unsigned int *)t8);
    t11 = (~(t10));
    t12 = *((unsigned int *)t34);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 6608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7088);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);

LAB18:    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6928);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlogtype_sign_extend(t9, 32, t5, 10);
    memset(t33, 0, 8);
    xsi_vlog_signed_greater(t33, 32, t2, 32, t9, 32);
    memset(t34, 0, 8);
    t6 = (t33 + 4);
    t10 = *((unsigned int *)t6);
    t11 = (~(t10));
    t12 = *((unsigned int *)t33);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t6) != 0)
        goto LAB21;

LAB22:    t8 = (t34 + 4);
    t15 = *((unsigned int *)t34);
    t16 = *((unsigned int *)t8);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB23;

LAB24:    memcpy(t38, t34, 8);

LAB25:    memset(t66, 0, 8);
    t67 = (t38 + 4);
    t68 = *((unsigned int *)t67);
    t69 = (~(t68));
    t70 = *((unsigned int *)t38);
    t71 = (t70 & t69);
    t72 = (t71 & 1U);
    if (t72 != 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t67) != 0)
        goto LAB35;

LAB36:    t74 = (t66 + 4);
    t75 = *((unsigned int *)t66);
    t76 = *((unsigned int *)t74);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB37;

LAB38:    memcpy(t92, t66, 8);

LAB39:    t124 = (t92 + 4);
    t125 = *((unsigned int *)t124);
    t126 = (~(t125));
    t127 = *((unsigned int *)t92);
    t128 = (t127 & t126);
    t129 = (t128 != 0);
    if (t129 > 0)
        goto LAB47;

LAB48:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 6928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7088);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t34, 0, 8);
    xsi_vlog_signed_greater(t34, 10, t4, 10, t7, 10);
    memset(t35, 0, 8);
    t8 = (t34 + 4);
    t10 = *((unsigned int *)t8);
    t11 = (~(t10));
    t12 = *((unsigned int *)t34);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t8) != 0)
        goto LAB52;

LAB53:    t28 = (t35 + 4);
    t15 = *((unsigned int *)t35);
    t16 = *((unsigned int *)t28);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB54;

LAB55:    memcpy(t79, t35, 8);

LAB56:    t80 = (t79 + 4);
    t68 = *((unsigned int *)t80);
    t69 = (~(t68));
    t70 = *((unsigned int *)t79);
    t71 = (t70 & t69);
    t72 = (t71 != 0);
    if (t72 > 0)
        goto LAB64;

LAB65:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 7088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6768);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t34, 0, 8);
    xsi_vlog_signed_greater(t34, 10, t4, 10, t7, 10);
    t8 = (t34 + 4);
    t10 = *((unsigned int *)t8);
    t11 = (~(t10));
    t12 = *((unsigned int *)t34);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB67;

LAB68:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 6768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7248);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 10);

LAB69:
LAB66:
LAB49:    goto LAB2;

LAB8:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(78, ng0);
    t28 = (t0 + 5168);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t31 = (t0 + 608);
    t32 = *((char **)t31);
    memset(t33, 0, 8);
    xsi_vlog_signed_add(t33, 32, t30, 10, t32, 32);
    t31 = (t0 + 6768);
    xsi_vlogvar_assign_value(t31, t33, 0, 0, 10);
    goto LAB12;

LAB13:    xsi_set_current_line(84, ng0);
    t22 = (t0 + 6128);
    t28 = (t22 + 56U);
    t29 = *((char **)t28);
    t30 = (t0 + 6928);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 10);
    goto LAB15;

LAB16:    xsi_set_current_line(89, ng0);
    t22 = (t0 + 6448);
    t28 = (t22 + 56U);
    t29 = *((char **)t28);
    t30 = (t0 + 7088);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 10);
    goto LAB18;

LAB19:    *((unsigned int *)t34) = 1;
    goto LAB22;

LAB21:    t7 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB22;

LAB23:    t22 = ((char*)((ng1)));
    t28 = (t0 + 7088);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    xsi_vlogtype_sign_extend(t35, 32, t30, 10);
    memset(t36, 0, 8);
    xsi_vlog_signed_greater(t36, 32, t22, 32, t35, 32);
    memset(t37, 0, 8);
    t31 = (t36 + 4);
    t18 = *((unsigned int *)t31);
    t19 = (~(t18));
    t20 = *((unsigned int *)t36);
    t21 = (t20 & t19);
    t23 = (t21 & 1U);
    if (t23 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t31) != 0)
        goto LAB28;

LAB29:    t24 = *((unsigned int *)t34);
    t25 = *((unsigned int *)t37);
    t26 = (t24 & t25);
    *((unsigned int *)t38) = t26;
    t39 = (t34 + 4);
    t40 = (t37 + 4);
    t41 = (t38 + 4);
    t27 = *((unsigned int *)t39);
    t42 = *((unsigned int *)t40);
    t43 = (t27 | t42);
    *((unsigned int *)t41) = t43;
    t44 = *((unsigned int *)t41);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB30;

LAB31:
LAB32:    goto LAB25;

LAB26:    *((unsigned int *)t37) = 1;
    goto LAB29;

LAB28:    t32 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB29;

LAB30:    t46 = *((unsigned int *)t38);
    t47 = *((unsigned int *)t41);
    *((unsigned int *)t38) = (t46 | t47);
    t48 = (t34 + 4);
    t49 = (t37 + 4);
    t50 = *((unsigned int *)t34);
    t51 = (~(t50));
    t52 = *((unsigned int *)t48);
    t53 = (~(t52));
    t54 = *((unsigned int *)t37);
    t55 = (~(t54));
    t56 = *((unsigned int *)t49);
    t57 = (~(t56));
    t58 = (t51 & t53);
    t59 = (t55 & t57);
    t60 = (~(t58));
    t61 = (~(t59));
    t62 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t62 & t60);
    t63 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t63 & t61);
    t64 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t64 & t60);
    t65 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t65 & t61);
    goto LAB32;

LAB33:    *((unsigned int *)t66) = 1;
    goto LAB36;

LAB35:    t73 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t73) = 1;
    goto LAB36;

LAB37:    t78 = ((char*)((ng1)));
    t80 = (t0 + 6768);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    xsi_vlogtype_sign_extend(t79, 32, t82, 10);
    memset(t83, 0, 8);
    xsi_vlog_signed_greater(t83, 32, t78, 32, t79, 32);
    memset(t84, 0, 8);
    t85 = (t83 + 4);
    t86 = *((unsigned int *)t85);
    t87 = (~(t86));
    t88 = *((unsigned int *)t83);
    t89 = (t88 & t87);
    t90 = (t89 & 1U);
    if (t90 != 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t85) != 0)
        goto LAB42;

LAB43:    t93 = *((unsigned int *)t66);
    t94 = *((unsigned int *)t84);
    t95 = (t93 & t94);
    *((unsigned int *)t92) = t95;
    t96 = (t66 + 4);
    t97 = (t84 + 4);
    t98 = (t92 + 4);
    t99 = *((unsigned int *)t96);
    t100 = *((unsigned int *)t97);
    t101 = (t99 | t100);
    *((unsigned int *)t98) = t101;
    t102 = *((unsigned int *)t98);
    t103 = (t102 != 0);
    if (t103 == 1)
        goto LAB44;

LAB45:
LAB46:    goto LAB39;

LAB40:    *((unsigned int *)t84) = 1;
    goto LAB43;

LAB42:    t91 = (t84 + 4);
    *((unsigned int *)t84) = 1;
    *((unsigned int *)t91) = 1;
    goto LAB43;

LAB44:    t104 = *((unsigned int *)t92);
    t105 = *((unsigned int *)t98);
    *((unsigned int *)t92) = (t104 | t105);
    t106 = (t66 + 4);
    t107 = (t84 + 4);
    t108 = *((unsigned int *)t66);
    t109 = (~(t108));
    t110 = *((unsigned int *)t106);
    t111 = (~(t110));
    t112 = *((unsigned int *)t84);
    t113 = (~(t112));
    t114 = *((unsigned int *)t107);
    t115 = (~(t114));
    t116 = (t109 & t111);
    t117 = (t113 & t115);
    t118 = (~(t116));
    t119 = (~(t117));
    t120 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t120 & t118);
    t121 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t121 & t119);
    t122 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t122 & t118);
    t123 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t123 & t119);
    goto LAB46;

LAB47:    xsi_set_current_line(94, ng0);
    t130 = ((char*)((ng1)));
    t131 = (t0 + 7248);
    xsi_vlogvar_assign_value(t131, t130, 0, 0, 10);
    goto LAB49;

LAB50:    *((unsigned int *)t35) = 1;
    goto LAB53;

LAB52:    t22 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB53;

LAB54:    t29 = (t0 + 6928);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    t32 = (t0 + 6768);
    t39 = (t32 + 56U);
    t40 = *((char **)t39);
    memset(t38, 0, 8);
    xsi_vlog_signed_greater(t38, 10, t31, 10, t40, 10);
    memset(t66, 0, 8);
    t41 = (t38 + 4);
    t18 = *((unsigned int *)t41);
    t19 = (~(t18));
    t20 = *((unsigned int *)t38);
    t21 = (t20 & t19);
    t23 = (t21 & 1U);
    if (t23 != 0)
        goto LAB57;

LAB58:    if (*((unsigned int *)t41) != 0)
        goto LAB59;

LAB60:    t24 = *((unsigned int *)t35);
    t25 = *((unsigned int *)t66);
    t26 = (t24 & t25);
    *((unsigned int *)t79) = t26;
    t49 = (t35 + 4);
    t67 = (t66 + 4);
    t73 = (t79 + 4);
    t27 = *((unsigned int *)t49);
    t42 = *((unsigned int *)t67);
    t43 = (t27 | t42);
    *((unsigned int *)t73) = t43;
    t44 = *((unsigned int *)t73);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB61;

LAB62:
LAB63:    goto LAB56;

LAB57:    *((unsigned int *)t66) = 1;
    goto LAB60;

LAB59:    t48 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t48) = 1;
    goto LAB60;

LAB61:    t46 = *((unsigned int *)t79);
    t47 = *((unsigned int *)t73);
    *((unsigned int *)t79) = (t46 | t47);
    t74 = (t35 + 4);
    t78 = (t66 + 4);
    t50 = *((unsigned int *)t35);
    t51 = (~(t50));
    t52 = *((unsigned int *)t74);
    t53 = (~(t52));
    t54 = *((unsigned int *)t66);
    t55 = (~(t54));
    t56 = *((unsigned int *)t78);
    t57 = (~(t56));
    t58 = (t51 & t53);
    t59 = (t55 & t57);
    t60 = (~(t58));
    t61 = (~(t59));
    t62 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t62 & t60);
    t63 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t63 & t61);
    t64 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t64 & t60);
    t65 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t65 & t61);
    goto LAB63;

LAB64:    xsi_set_current_line(96, ng0);
    t81 = (t0 + 6928);
    t82 = (t81 + 56U);
    t85 = *((char **)t82);
    t91 = (t0 + 7248);
    xsi_vlogvar_assign_value(t91, t85, 0, 0, 10);
    goto LAB66;

LAB67:    xsi_set_current_line(98, ng0);
    t22 = (t0 + 7088);
    t28 = (t22 + 56U);
    t29 = *((char **)t28);
    t30 = (t0 + 7248);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 10);
    goto LAB69;

}

static void Always_103_8(char *t0)
{
    char t13[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;

LAB0:    t1 = (t0 + 10144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 10592);
    *((int *)t2) = 1;
    t3 = (t0 + 10176);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(103, ng0);

LAB5:    xsi_set_current_line(104, ng0);
    t4 = (t0 + 1888U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 2048U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB13;

LAB11:    if (*((unsigned int *)t2) == 0)
        goto LAB10;

LAB12:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;

LAB13:    t5 = (t13 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (~(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB14;

LAB15:
LAB16:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(104, ng0);

LAB9:    xsi_set_current_line(105, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 2, 0LL);
    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5008);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5168);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 0LL);
    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 0LL);
    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5488);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 0LL);
    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5648);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 0LL);
    xsi_set_current_line(111, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5808);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5968);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB8;

LAB10:    *((unsigned int *)t13) = 1;
    goto LAB13;

LAB14:    xsi_set_current_line(113, ng0);

LAB17:    xsi_set_current_line(114, ng0);
    t11 = (t0 + 2848U);
    t12 = *((char **)t11);
    t11 = (t0 + 5808);
    xsi_vlogvar_wait_assign_value(t11, t12, 0, 0, 1, 0LL);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 3008U);
    t3 = *((char **)t2);
    t2 = (t0 + 5968);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 2528U);
    t3 = *((char **)t2);
    t2 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 2, 0LL);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 2208U);
    t3 = *((char **)t2);
    t2 = (t0 + 5168);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 10, 0LL);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB18;

LAB19:
LAB20:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 3008U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(124, ng0);

LAB25:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 2208U);
    t3 = *((char **)t2);
    t2 = (t0 + 5168);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 10, 0LL);
    xsi_set_current_line(126, ng0);
    t2 = (t0 + 3328U);
    t3 = *((char **)t2);
    t2 = (t0 + 5488);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 10, 0LL);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 3168U);
    t3 = *((char **)t2);
    t2 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 10, 0LL);

LAB23:    goto LAB16;

LAB18:    xsi_set_current_line(119, ng0);
    t4 = (t0 + 2688U);
    t5 = *((char **)t4);
    t4 = (t0 + 5008);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 2, 0LL);
    goto LAB20;

LAB21:    xsi_set_current_line(120, ng0);

LAB24:    xsi_set_current_line(121, ng0);
    t4 = (t0 + 6928);
    t5 = (t4 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 5488);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 10, 0LL);
    xsi_set_current_line(122, ng0);
    t2 = (t0 + 7088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5648);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 7248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    goto LAB23;

}


extern void work_m_14115257714309620655_3627157545_init()
{
	static char *pe[] = {(void *)Cont_63_0,(void *)Cont_64_1,(void *)Cont_65_2,(void *)Cont_66_3,(void *)Cont_67_4,(void *)Cont_68_5,(void *)Cont_69_6,(void *)Always_71_7,(void *)Always_103_8};
	xsi_register_didat("work_m_14115257714309620655_3627157545", "isim/StreamInputHandler_ReferenceReader_Engine_Interface_tb_isim_beh.exe.sim/work/m_14115257714309620655_3627157545.didat");
	xsi_register_executes(pe);
}
