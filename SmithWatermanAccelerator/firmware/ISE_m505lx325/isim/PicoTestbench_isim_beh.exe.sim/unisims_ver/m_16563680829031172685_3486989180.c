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
static int ng0[] = {0, 0};
static int ng1[] = {6, 0};
static int ng2[] = {1, 0};
static int ng3[] = {3, 0};
static unsigned int ng4[] = {0U, 0U};
static int ng5[] = {5, 0};
static unsigned int ng6[] = {1U, 0U};
static const char *ng7 = "Warning: Invalid average CLKIN frequency detected = %4.3f MHz";
static const char *ng8 = "    on %s instance %m at time %t ps.";
static const char *ng9 = "    The valid CLKIN frequency range is:";
static const char *ng10 = "        Minimum = %4.3f MHz";
static const char *ng11 = "        Maximum = %4.3f MHz";



static void NetDecl_50_0(char *t0)
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

LAB0:    t1 = (t0 + 6080U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 11136);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 8592);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 0U);
    t18 = (t0 + 8384);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_71_1(char *t0)
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

LAB0:    t1 = (t0 + 6328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8656);
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
    xsi_driver_vfirst_trans_delayed(t5, 0, 0, 10000LL, 0);
    t18 = (t0 + 8400);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_73_2(char *t0)
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
    char *t16;

LAB0:    t1 = (t0 + 6576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1888U);
    t3 = *((char **)t2);
    t2 = (t0 + 8720);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 0, 0LL, 0);
    t16 = (t0 + 8416);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_74_3(char *t0)
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
    char *t16;

LAB0:    t1 = (t0 + 6824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2048U);
    t3 = *((char **)t2);
    t2 = (t0 + 8784);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 0, 1000LL, 0);
    t16 = (t0 + 8432);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_75_4(char *t0)
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
    char *t16;

LAB0:    t1 = (t0 + 7072U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2208U);
    t3 = *((char **)t2);
    t2 = (t0 + 8848);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 0, 1000LL, 0);
    t16 = (t0 + 8448);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_76_5(char *t0)
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
    char *t16;

LAB0:    t1 = (t0 + 7320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2368U);
    t3 = *((char **)t2);
    t2 = (t0 + 8912);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 0);
    t16 = (t0 + 8464);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Always_79_6(char *t0)
{
    char t8[8];
    char t10[16];
    char t26[8];
    char t39[8];
    char t55[8];
    char t63[8];
    char t95[8];
    char t116[8];
    char t117[8];
    char t125[8];
    char t157[8];
    char t182[8];
    char t183[8];
    char t191[8];
    char t233[8];
    char t244[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    double t7;
    char *t9;
    double t11;
    double t12;
    double t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
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
    char *t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    int t87;
    int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    char *t102;
    char *t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    char *t107;
    char *t108;
    char *t109;
    char *t110;
    char *t111;
    char *t112;
    char *t113;
    char *t114;
    unsigned int t115;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    char *t124;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    char *t129;
    char *t130;
    char *t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    char *t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    int t149;
    int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    char *t158;
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
    char *t169;
    char *t170;
    char *t171;
    double t172;
    char *t173;
    char *t174;
    char *t175;
    double t176;
    double t177;
    char *t178;
    char *t179;
    double t180;
    unsigned int t181;
    char *t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    char *t190;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    char *t195;
    char *t196;
    char *t197;
    unsigned int t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    char *t205;
    char *t206;
    unsigned int t207;
    unsigned int t208;
    unsigned int t209;
    unsigned int t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    int t215;
    int t216;
    unsigned int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    char *t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    char *t229;
    char *t230;
    char *t231;
    char *t232;
    char *t234;
    unsigned int t235;
    unsigned int t236;
    unsigned int t237;
    unsigned int t238;
    unsigned int t239;
    char *t240;
    char *t241;
    char *t242;
    char *t243;
    char *t245;

LAB0:    t1 = (t0 + 7568U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8480);
    *((int *)t2) = 1;
    t3 = (t0 + 7600);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 3568);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = *((double *)t6);
    *((double *)t8) = t7;
    t9 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t9, t8, 0, 0, 1, 0LL);
    t2 = (t0 + 3728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t7 = *((double *)t4);
    *((double *)t8) = t7;
    t5 = (t0 + 4208);
    xsi_vlogvar_wait_assign_value(t5, t8, 0, 0, 1, 0LL);
    t2 = (t0 + 4368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 0LL);
    t2 = xsi_vlog_time(t10, 1000.0000000000000, 1.0000000000000000);
    t7 = xsi_vlog_convert_to_real(t10, 64, 2);
    t3 = (t0 + 3888);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t11 = *((double *)t5);
    t12 = (t7 - t11);
    *((double *)t8) = t12;
    t6 = (t0 + 3568);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 1, 0LL);
    t2 = xsi_vlog_time(t10, 1000.0000000000000, 1.0000000000000000);
    t7 = xsi_vlog_convert_to_real(t10, 64, 2);
    t3 = (t0 + 3888);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t11 = *((double *)t5);
    t12 = (t7 - t11);
    t13 = (1000000.0000000000 / t12);
    *((double *)t8) = t13;
    t6 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 1, 0LL);
    t2 = xsi_vlog_time(t10, 1000.0000000000000, 1.0000000000000000);
    t7 = xsi_vlog_convert_to_real(t10, 64, 2);
    t11 = (t7 / 1.0000000000000000);
    *((double *)t8) = t11;
    t3 = (t0 + 3888);
    xsi_vlogvar_wait_assign_value(t3, t8, 0, 0, 1, 0LL);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng0)));
    memset(t8, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t2);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t21 = *((unsigned int *)t4);
    t22 = *((unsigned int *)t5);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB9;

LAB6:    if (t23 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB9:    memset(t26, 0, 8);
    t9 = (t8 + 4);
    t27 = *((unsigned int *)t9);
    t28 = (~(t27));
    t29 = *((unsigned int *)t8);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t9) != 0)
        goto LAB12;

LAB13:    t33 = (t26 + 4);
    t34 = *((unsigned int *)t26);
    t35 = *((unsigned int *)t33);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB14;

LAB15:    memcpy(t63, t26, 8);

LAB16:    memset(t95, 0, 8);
    t96 = (t63 + 4);
    t97 = *((unsigned int *)t96);
    t98 = (~(t97));
    t99 = *((unsigned int *)t63);
    t100 = (t99 & t98);
    t101 = (t100 & 1U);
    if (t101 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t96) != 0)
        goto LAB30;

LAB31:    t103 = (t95 + 4);
    t104 = *((unsigned int *)t95);
    t105 = *((unsigned int *)t103);
    t106 = (t104 || t105);
    if (t106 > 0)
        goto LAB32;

LAB33:    memcpy(t125, t95, 8);

LAB34:    memset(t157, 0, 8);
    t158 = (t125 + 4);
    t159 = *((unsigned int *)t158);
    t160 = (~(t159));
    t161 = *((unsigned int *)t125);
    t162 = (t161 & t160);
    t163 = (t162 & 1U);
    if (t163 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t158) != 0)
        goto LAB44;

LAB45:    t165 = (t157 + 4);
    t166 = *((unsigned int *)t157);
    t167 = *((unsigned int *)t165);
    t168 = (t166 || t167);
    if (t168 > 0)
        goto LAB46;

LAB47:    memcpy(t191, t157, 8);

LAB48:    t223 = (t191 + 4);
    t224 = *((unsigned int *)t223);
    t225 = (~(t224));
    t226 = *((unsigned int *)t191);
    t227 = (t226 & t225);
    t228 = (t227 != 0);
    if (t228 > 0)
        goto LAB56;

LAB57:
LAB95:    t2 = (t0 + 4528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t8, 0, 8);
    xsi_vlog_signed_add(t8, 32, t4, 32, t5, 32);
    t6 = (t0 + 4528);
    xsi_vlogvar_assign_value(t6, t8, 0, 0, 32);
    t2 = (t0 + 4528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t8, 0, 8);
    xsi_vlog_signed_greatereq(t8, 32, t4, 32, t5, 32);
    memset(t26, 0, 8);
    t6 = (t8 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (~(t14));
    t16 = *((unsigned int *)t8);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB96;

LAB97:    if (*((unsigned int *)t6) != 0)
        goto LAB98;

LAB99:    t32 = (t26 + 4);
    t19 = *((unsigned int *)t26);
    t20 = *((unsigned int *)t32);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB100;

LAB101:    memcpy(t63, t26, 8);

LAB102:    t77 = (t63 + 4);
    t64 = *((unsigned int *)t77);
    t65 = (~(t64));
    t66 = *((unsigned int *)t63);
    t70 = (t66 & t65);
    t71 = (t70 != 0);
    if (t71 > 0)
        goto LAB110;

LAB111:
LAB112:
LAB58:    goto LAB2;

LAB8:    t6 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t26) = 1;
    goto LAB13;

LAB12:    t32 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB13;

LAB14:    t37 = (t0 + 2688U);
    t38 = *((char **)t37);
    t37 = ((char*)((ng0)));
    memset(t39, 0, 8);
    t40 = (t38 + 4);
    t41 = (t37 + 4);
    t42 = *((unsigned int *)t38);
    t43 = *((unsigned int *)t37);
    t44 = (t42 ^ t43);
    t45 = *((unsigned int *)t40);
    t46 = *((unsigned int *)t41);
    t47 = (t45 ^ t46);
    t48 = (t44 | t47);
    t49 = *((unsigned int *)t40);
    t50 = *((unsigned int *)t41);
    t51 = (t49 | t50);
    t52 = (~(t51));
    t53 = (t48 & t52);
    if (t53 != 0)
        goto LAB20;

LAB17:    if (t51 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t39) = 1;

LAB20:    memset(t55, 0, 8);
    t56 = (t39 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t39);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t56) != 0)
        goto LAB23;

LAB24:    t64 = *((unsigned int *)t26);
    t65 = *((unsigned int *)t55);
    t66 = (t64 & t65);
    *((unsigned int *)t63) = t66;
    t67 = (t26 + 4);
    t68 = (t55 + 4);
    t69 = (t63 + 4);
    t70 = *((unsigned int *)t67);
    t71 = *((unsigned int *)t68);
    t72 = (t70 | t71);
    *((unsigned int *)t69) = t72;
    t73 = *((unsigned int *)t69);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB19:    t54 = (t39 + 4);
    *((unsigned int *)t39) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t55) = 1;
    goto LAB24;

LAB23:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB24;

LAB25:    t75 = *((unsigned int *)t63);
    t76 = *((unsigned int *)t69);
    *((unsigned int *)t63) = (t75 | t76);
    t77 = (t26 + 4);
    t78 = (t55 + 4);
    t79 = *((unsigned int *)t26);
    t80 = (~(t79));
    t81 = *((unsigned int *)t77);
    t82 = (~(t81));
    t83 = *((unsigned int *)t55);
    t84 = (~(t83));
    t85 = *((unsigned int *)t78);
    t86 = (~(t85));
    t87 = (t80 & t82);
    t88 = (t84 & t86);
    t89 = (~(t87));
    t90 = (~(t88));
    t91 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t91 & t89);
    t92 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t92 & t90);
    t93 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t93 & t89);
    t94 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t94 & t90);
    goto LAB27;

LAB28:    *((unsigned int *)t95) = 1;
    goto LAB31;

LAB30:    t102 = (t95 + 4);
    *((unsigned int *)t95) = 1;
    *((unsigned int *)t102) = 1;
    goto LAB31;

LAB32:    t107 = (t0 + 3568);
    t108 = (t107 + 56U);
    t109 = *((char **)t108);
    t7 = *((double *)t109);
    t110 = (t0 + 4048);
    t111 = (t110 + 56U);
    t112 = *((char **)t111);
    t11 = *((double *)t112);
    t12 = (t7 - t11);
    t113 = (t0 + 1016);
    t114 = *((char **)t113);
    t13 = *((double *)t114);
    t115 = (t12 <= t13);
    *((unsigned int *)t116) = t115;
    t113 = (t116 + 4);
    *((unsigned int *)t113) = 0U;
    memset(t117, 0, 8);
    t118 = (t116 + 4);
    t119 = *((unsigned int *)t118);
    t120 = (~(t119));
    t121 = *((unsigned int *)t116);
    t122 = (t121 & t120);
    t123 = (t122 & 1U);
    if (t123 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t118) != 0)
        goto LAB37;

LAB38:    t126 = *((unsigned int *)t95);
    t127 = *((unsigned int *)t117);
    t128 = (t126 & t127);
    *((unsigned int *)t125) = t128;
    t129 = (t95 + 4);
    t130 = (t117 + 4);
    t131 = (t125 + 4);
    t132 = *((unsigned int *)t129);
    t133 = *((unsigned int *)t130);
    t134 = (t132 | t133);
    *((unsigned int *)t131) = t134;
    t135 = *((unsigned int *)t131);
    t136 = (t135 != 0);
    if (t136 == 1)
        goto LAB39;

LAB40:
LAB41:    goto LAB34;

LAB35:    *((unsigned int *)t117) = 1;
    goto LAB38;

LAB37:    t124 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t124) = 1;
    goto LAB38;

LAB39:    t137 = *((unsigned int *)t125);
    t138 = *((unsigned int *)t131);
    *((unsigned int *)t125) = (t137 | t138);
    t139 = (t95 + 4);
    t140 = (t117 + 4);
    t141 = *((unsigned int *)t95);
    t142 = (~(t141));
    t143 = *((unsigned int *)t139);
    t144 = (~(t143));
    t145 = *((unsigned int *)t117);
    t146 = (~(t145));
    t147 = *((unsigned int *)t140);
    t148 = (~(t147));
    t149 = (t142 & t144);
    t150 = (t146 & t148);
    t151 = (~(t149));
    t152 = (~(t150));
    t153 = *((unsigned int *)t131);
    *((unsigned int *)t131) = (t153 & t151);
    t154 = *((unsigned int *)t131);
    *((unsigned int *)t131) = (t154 & t152);
    t155 = *((unsigned int *)t125);
    *((unsigned int *)t125) = (t155 & t151);
    t156 = *((unsigned int *)t125);
    *((unsigned int *)t125) = (t156 & t152);
    goto LAB41;

LAB42:    *((unsigned int *)t157) = 1;
    goto LAB45;

LAB44:    t164 = (t157 + 4);
    *((unsigned int *)t157) = 1;
    *((unsigned int *)t164) = 1;
    goto LAB45;

LAB46:    t169 = (t0 + 4048);
    t170 = (t169 + 56U);
    t171 = *((char **)t170);
    t172 = *((double *)t171);
    t173 = (t0 + 3568);
    t174 = (t173 + 56U);
    t175 = *((char **)t174);
    t176 = *((double *)t175);
    t177 = (t172 - t176);
    t178 = (t0 + 1016);
    t179 = *((char **)t178);
    t180 = *((double *)t179);
    t181 = (t177 <= t180);
    *((unsigned int *)t182) = t181;
    t178 = (t182 + 4);
    *((unsigned int *)t178) = 0U;
    memset(t183, 0, 8);
    t184 = (t182 + 4);
    t185 = *((unsigned int *)t184);
    t186 = (~(t185));
    t187 = *((unsigned int *)t182);
    t188 = (t187 & t186);
    t189 = (t188 & 1U);
    if (t189 != 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t184) != 0)
        goto LAB51;

LAB52:    t192 = *((unsigned int *)t157);
    t193 = *((unsigned int *)t183);
    t194 = (t192 & t193);
    *((unsigned int *)t191) = t194;
    t195 = (t157 + 4);
    t196 = (t183 + 4);
    t197 = (t191 + 4);
    t198 = *((unsigned int *)t195);
    t199 = *((unsigned int *)t196);
    t200 = (t198 | t199);
    *((unsigned int *)t197) = t200;
    t201 = *((unsigned int *)t197);
    t202 = (t201 != 0);
    if (t202 == 1)
        goto LAB53;

LAB54:
LAB55:    goto LAB48;

LAB49:    *((unsigned int *)t183) = 1;
    goto LAB52;

LAB51:    t190 = (t183 + 4);
    *((unsigned int *)t183) = 1;
    *((unsigned int *)t190) = 1;
    goto LAB52;

LAB53:    t203 = *((unsigned int *)t191);
    t204 = *((unsigned int *)t197);
    *((unsigned int *)t191) = (t203 | t204);
    t205 = (t157 + 4);
    t206 = (t183 + 4);
    t207 = *((unsigned int *)t157);
    t208 = (~(t207));
    t209 = *((unsigned int *)t205);
    t210 = (~(t209));
    t211 = *((unsigned int *)t183);
    t212 = (~(t211));
    t213 = *((unsigned int *)t206);
    t214 = (~(t213));
    t215 = (t208 & t210);
    t216 = (t212 & t214);
    t217 = (~(t215));
    t218 = (~(t216));
    t219 = *((unsigned int *)t197);
    *((unsigned int *)t197) = (t219 & t217);
    t220 = *((unsigned int *)t197);
    *((unsigned int *)t197) = (t220 & t218);
    t221 = *((unsigned int *)t191);
    *((unsigned int *)t191) = (t221 & t217);
    t222 = *((unsigned int *)t191);
    *((unsigned int *)t191) = (t222 & t218);
    goto LAB55;

LAB56:
LAB59:    t229 = (t0 + 4368);
    t230 = (t229 + 56U);
    t231 = *((char **)t230);
    t232 = ((char*)((ng1)));
    memset(t233, 0, 8);
    xsi_vlog_signed_less(t233, 32, t231, 32, t232, 32);
    t234 = (t233 + 4);
    t235 = *((unsigned int *)t234);
    t236 = (~(t235));
    t237 = *((unsigned int *)t233);
    t238 = (t237 & t236);
    t239 = (t238 != 0);
    if (t239 > 0)
        goto LAB60;

LAB61:
LAB62:    t2 = (t0 + 4368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_signed_greatereq(t8, 32, t4, 32, t5, 32);
    memset(t26, 0, 8);
    t6 = (t8 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (~(t14));
    t16 = *((unsigned int *)t8);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t6) != 0)
        goto LAB65;

LAB66:    t32 = (t26 + 4);
    t19 = *((unsigned int *)t26);
    t20 = *((unsigned int *)t32);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB67;

LAB68:    memcpy(t63, t26, 8);

LAB69:    memset(t95, 0, 8);
    t96 = (t63 + 4);
    t64 = *((unsigned int *)t96);
    t65 = (~(t64));
    t66 = *((unsigned int *)t63);
    t70 = (t66 & t65);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t96) != 0)
        goto LAB79;

LAB80:    t103 = (t95 + 4);
    t72 = *((unsigned int *)t95);
    t73 = *((unsigned int *)t103);
    t74 = (t72 || t73);
    if (t74 > 0)
        goto LAB81;

LAB82:    memcpy(t125, t95, 8);

LAB83:    t130 = (t125 + 4);
    t123 = *((unsigned int *)t130);
    t126 = (~(t123));
    t127 = *((unsigned int *)t125);
    t128 = (t127 & t126);
    t132 = (t128 != 0);
    if (t132 > 0)
        goto LAB91;

LAB92:
LAB93:    goto LAB58;

LAB60:    t240 = (t0 + 4368);
    t241 = (t240 + 56U);
    t242 = *((char **)t241);
    t243 = ((char*)((ng2)));
    memset(t244, 0, 8);
    xsi_vlog_signed_add(t244, 32, t242, 32, t243, 32);
    t245 = (t0 + 4368);
    xsi_vlogvar_wait_assign_value(t245, t244, 0, 0, 32, 0LL);
    goto LAB62;

LAB63:    *((unsigned int *)t26) = 1;
    goto LAB66;

LAB65:    t9 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB66;

LAB67:    t33 = (t0 + 4368);
    t37 = (t33 + 56U);
    t38 = *((char **)t37);
    t40 = (t0 + 4688);
    t41 = (t40 + 56U);
    t54 = *((char **)t41);
    memset(t39, 0, 8);
    xsi_vlog_signed_not_equal(t39, 32, t38, 32, t54, 32);
    memset(t55, 0, 8);
    t56 = (t39 + 4);
    t22 = *((unsigned int *)t56);
    t23 = (~(t22));
    t24 = *((unsigned int *)t39);
    t25 = (t24 & t23);
    t27 = (t25 & 1U);
    if (t27 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t56) != 0)
        goto LAB72;

LAB73:    t28 = *((unsigned int *)t26);
    t29 = *((unsigned int *)t55);
    t30 = (t28 & t29);
    *((unsigned int *)t63) = t30;
    t67 = (t26 + 4);
    t68 = (t55 + 4);
    t69 = (t63 + 4);
    t31 = *((unsigned int *)t67);
    t34 = *((unsigned int *)t68);
    t35 = (t31 | t34);
    *((unsigned int *)t69) = t35;
    t36 = *((unsigned int *)t69);
    t42 = (t36 != 0);
    if (t42 == 1)
        goto LAB74;

LAB75:
LAB76:    goto LAB69;

LAB70:    *((unsigned int *)t55) = 1;
    goto LAB73;

LAB72:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB73;

LAB74:    t43 = *((unsigned int *)t63);
    t44 = *((unsigned int *)t69);
    *((unsigned int *)t63) = (t43 | t44);
    t77 = (t26 + 4);
    t78 = (t55 + 4);
    t45 = *((unsigned int *)t26);
    t46 = (~(t45));
    t47 = *((unsigned int *)t77);
    t48 = (~(t47));
    t49 = *((unsigned int *)t55);
    t50 = (~(t49));
    t51 = *((unsigned int *)t78);
    t52 = (~(t51));
    t87 = (t46 & t48);
    t88 = (t50 & t52);
    t53 = (~(t87));
    t57 = (~(t88));
    t58 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t58 & t53);
    t59 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t59 & t57);
    t60 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t60 & t53);
    t61 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t61 & t57);
    goto LAB76;

LAB77:    *((unsigned int *)t95) = 1;
    goto LAB80;

LAB79:    t102 = (t95 + 4);
    *((unsigned int *)t95) = 1;
    *((unsigned int *)t102) = 1;
    goto LAB80;

LAB81:    t107 = (t0 + 4528);
    t108 = (t107 + 56U);
    t109 = *((char **)t108);
    t110 = ((char*)((ng0)));
    memset(t116, 0, 8);
    xsi_vlog_signed_not_equal(t116, 32, t109, 32, t110, 32);
    memset(t117, 0, 8);
    t111 = (t116 + 4);
    t75 = *((unsigned int *)t111);
    t76 = (~(t75));
    t79 = *((unsigned int *)t116);
    t80 = (t79 & t76);
    t81 = (t80 & 1U);
    if (t81 != 0)
        goto LAB84;

LAB85:    if (*((unsigned int *)t111) != 0)
        goto LAB86;

LAB87:    t82 = *((unsigned int *)t95);
    t83 = *((unsigned int *)t117);
    t84 = (t82 & t83);
    *((unsigned int *)t125) = t84;
    t113 = (t95 + 4);
    t114 = (t117 + 4);
    t118 = (t125 + 4);
    t85 = *((unsigned int *)t113);
    t86 = *((unsigned int *)t114);
    t89 = (t85 | t86);
    *((unsigned int *)t118) = t89;
    t90 = *((unsigned int *)t118);
    t91 = (t90 != 0);
    if (t91 == 1)
        goto LAB88;

LAB89:
LAB90:    goto LAB83;

LAB84:    *((unsigned int *)t117) = 1;
    goto LAB87;

LAB86:    t112 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t112) = 1;
    goto LAB87;

LAB88:    t92 = *((unsigned int *)t125);
    t93 = *((unsigned int *)t118);
    *((unsigned int *)t125) = (t92 | t93);
    t124 = (t95 + 4);
    t129 = (t117 + 4);
    t94 = *((unsigned int *)t95);
    t97 = (~(t94));
    t98 = *((unsigned int *)t124);
    t99 = (~(t98));
    t100 = *((unsigned int *)t117);
    t101 = (~(t100));
    t104 = *((unsigned int *)t129);
    t105 = (~(t104));
    t149 = (t97 & t99);
    t150 = (t101 & t105);
    t106 = (~(t149));
    t115 = (~(t150));
    t119 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t119 & t106);
    t120 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t120 & t115);
    t121 = *((unsigned int *)t125);
    *((unsigned int *)t125) = (t121 & t106);
    t122 = *((unsigned int *)t125);
    *((unsigned int *)t125) = (t122 & t115);
    goto LAB90;

LAB91:
LAB94:    t131 = ((char*)((ng0)));
    t139 = (t0 + 4528);
    xsi_vlogvar_wait_assign_value(t139, t131, 0, 0, 32, 0LL);
    goto LAB93;

LAB96:    *((unsigned int *)t26) = 1;
    goto LAB99;

LAB98:    t9 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB99;

LAB100:    t33 = (t0 + 4368);
    t37 = (t33 + 56U);
    t38 = *((char **)t37);
    t40 = ((char*)((ng0)));
    memset(t39, 0, 8);
    xsi_vlog_signed_not_equal(t39, 32, t38, 32, t40, 32);
    memset(t55, 0, 8);
    t41 = (t39 + 4);
    t22 = *((unsigned int *)t41);
    t23 = (~(t22));
    t24 = *((unsigned int *)t39);
    t25 = (t24 & t23);
    t27 = (t25 & 1U);
    if (t27 != 0)
        goto LAB103;

LAB104:    if (*((unsigned int *)t41) != 0)
        goto LAB105;

LAB106:    t28 = *((unsigned int *)t26);
    t29 = *((unsigned int *)t55);
    t30 = (t28 & t29);
    *((unsigned int *)t63) = t30;
    t56 = (t26 + 4);
    t62 = (t55 + 4);
    t67 = (t63 + 4);
    t31 = *((unsigned int *)t56);
    t34 = *((unsigned int *)t62);
    t35 = (t31 | t34);
    *((unsigned int *)t67) = t35;
    t36 = *((unsigned int *)t67);
    t42 = (t36 != 0);
    if (t42 == 1)
        goto LAB107;

LAB108:
LAB109:    goto LAB102;

LAB103:    *((unsigned int *)t55) = 1;
    goto LAB106;

LAB105:    t54 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB106;

LAB107:    t43 = *((unsigned int *)t63);
    t44 = *((unsigned int *)t67);
    *((unsigned int *)t63) = (t43 | t44);
    t68 = (t26 + 4);
    t69 = (t55 + 4);
    t45 = *((unsigned int *)t26);
    t46 = (~(t45));
    t47 = *((unsigned int *)t68);
    t48 = (~(t47));
    t49 = *((unsigned int *)t55);
    t50 = (~(t49));
    t51 = *((unsigned int *)t69);
    t52 = (~(t51));
    t87 = (t46 & t48);
    t88 = (t50 & t52);
    t53 = (~(t87));
    t57 = (~(t88));
    t58 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t58 & t53);
    t59 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t59 & t57);
    t60 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t60 & t53);
    t61 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t61 & t57);
    goto LAB109;

LAB110:
LAB113:    t78 = ((char*)((ng0)));
    t96 = (t0 + 4368);
    xsi_vlogvar_wait_assign_value(t96, t78, 0, 0, 32, 0LL);
    goto LAB112;

}

static void Always_107_7(char *t0)
{
    char t6[8];
    char t20[8];
    char t27[8];
    char t63[8];
    char t64[8];
    char t74[8];
    char t103[8];
    char t105[8];
    char t113[8];
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
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
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
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    char *t75;
    double t76;
    double t77;
    double t78;
    double t79;
    double t80;
    char *t81;
    unsigned int t82;
    char *t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    char *t88;
    char *t89;
    char *t90;
    double t91;
    char *t92;
    char *t93;
    char *t94;
    double t95;
    double t96;
    double t97;
    char *t98;
    char *t99;
    char *t100;
    double t101;
    unsigned int t102;
    char *t104;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    char *t118;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    char *t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    int t137;
    int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    char *t151;
    char *t152;

LAB0:    t1 = (t0 + 7816U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8496);
    *((int *)t2) = 1;
    t3 = (t0 + 7848);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 2848U);
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

LAB11:    memcpy(t27, t6, 8);

LAB12:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB20;

LAB21:    t2 = (t0 + 4368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_greatereq(t6, 32, t4, 32, t5, 32);
    memset(t20, 0, 8);
    t12 = (t6 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t12) != 0)
        goto LAB26;

LAB27:    t18 = (t20 + 4);
    t14 = *((unsigned int *)t20);
    t15 = *((unsigned int *)t18);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB28;

LAB29:    memcpy(t64, t20, 8);

LAB30:    t66 = (t64 + 4);
    t59 = *((unsigned int *)t66);
    t60 = (~(t59));
    t67 = *((unsigned int *)t64);
    t68 = (t67 & t60);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB38;

LAB39:    t2 = (t0 + 4528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_greatereq(t6, 32, t4, 32, t5, 32);
    t12 = (t6 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB42;

LAB43:    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t6, 0, 8);
    xsi_vlog_signed_greatereq(t6, 32, t4, 32, t5, 32);
    memset(t20, 0, 8);
    t12 = (t6 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t12) != 0)
        goto LAB48;

LAB49:    t18 = (t20 + 4);
    t14 = *((unsigned int *)t20);
    t15 = *((unsigned int *)t18);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB50;

LAB51:    memcpy(t64, t20, 8);

LAB52:    memset(t74, 0, 8);
    t81 = (t64 + 4);
    t60 = *((unsigned int *)t81);
    t67 = (~(t60));
    t68 = *((unsigned int *)t64);
    t69 = (t68 & t67);
    t82 = (t69 & 1U);
    if (t82 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t81) != 0)
        goto LAB62;

LAB63:    t84 = (t74 + 4);
    t85 = *((unsigned int *)t74);
    t86 = *((unsigned int *)t84);
    t87 = (t85 || t86);
    if (t87 > 0)
        goto LAB64;

LAB65:    memcpy(t113, t74, 8);

LAB66:    t145 = (t113 + 4);
    t146 = *((unsigned int *)t145);
    t147 = (~(t146));
    t148 = *((unsigned int *)t113);
    t149 = (t148 & t147);
    t150 = (t149 != 0);
    if (t150 > 0)
        goto LAB74;

LAB75:
LAB76:
LAB44:
LAB40:
LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t18 = (t0 + 2688U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t6);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t6 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t20) = 1;
    goto LAB16;

LAB15:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB17:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t6 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t6);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB19;

LAB20:
LAB23:    t61 = ((char*)((ng4)));
    t62 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t62, t61, 0, 0, 1, 0LL);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    goto LAB22;

LAB24:    *((unsigned int *)t20) = 1;
    goto LAB27;

LAB26:    t13 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB27;

LAB28:    t19 = (t0 + 4848);
    t26 = (t19 + 56U);
    t31 = *((char **)t26);
    t32 = ((char*)((ng1)));
    memset(t27, 0, 8);
    xsi_vlog_signed_less(t27, 32, t31, 32, t32, 32);
    memset(t63, 0, 8);
    t33 = (t27 + 4);
    t17 = *((unsigned int *)t33);
    t21 = (~(t17));
    t22 = *((unsigned int *)t27);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t33) != 0)
        goto LAB33;

LAB34:    t25 = *((unsigned int *)t20);
    t28 = *((unsigned int *)t63);
    t29 = (t25 & t28);
    *((unsigned int *)t64) = t29;
    t42 = (t20 + 4);
    t55 = (t63 + 4);
    t61 = (t64 + 4);
    t30 = *((unsigned int *)t42);
    t34 = *((unsigned int *)t55);
    t35 = (t30 | t34);
    *((unsigned int *)t61) = t35;
    t36 = *((unsigned int *)t61);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB35;

LAB36:
LAB37:    goto LAB30;

LAB31:    *((unsigned int *)t63) = 1;
    goto LAB34;

LAB33:    t41 = (t63 + 4);
    *((unsigned int *)t63) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB34;

LAB35:    t38 = *((unsigned int *)t64);
    t39 = *((unsigned int *)t61);
    *((unsigned int *)t64) = (t38 | t39);
    t62 = (t20 + 4);
    t65 = (t63 + 4);
    t40 = *((unsigned int *)t20);
    t43 = (~(t40));
    t44 = *((unsigned int *)t62);
    t45 = (~(t44));
    t47 = *((unsigned int *)t63);
    t48 = (~(t47));
    t49 = *((unsigned int *)t65);
    t51 = (~(t49));
    t46 = (t43 & t45);
    t50 = (t48 & t51);
    t52 = (~(t46));
    t53 = (~(t50));
    t54 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t54 & t52);
    t56 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t56 & t53);
    t57 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t57 & t52);
    t58 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t58 & t53);
    goto LAB37;

LAB38:
LAB41:    t70 = (t0 + 4848);
    t71 = (t70 + 56U);
    t72 = *((char **)t71);
    t73 = ((char*)((ng2)));
    memset(t74, 0, 8);
    xsi_vlog_signed_add(t74, 32, t72, 32, t73, 32);
    t75 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t75, t74, 0, 0, 32, 0LL);
    goto LAB40;

LAB42:
LAB45:    t13 = ((char*)((ng4)));
    t18 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t18, t13, 0, 0, 1, 0LL);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    goto LAB44;

LAB46:    *((unsigned int *)t20) = 1;
    goto LAB49;

LAB48:    t13 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB49;

LAB50:    t19 = (t0 + 3728);
    t26 = (t19 + 56U);
    t31 = *((char **)t26);
    t76 = *((double *)t31);
    t32 = (t0 + 4208);
    t33 = (t32 + 56U);
    t41 = *((char **)t33);
    t77 = *((double *)t41);
    t78 = (t76 + t77);
    t79 = (t78 / 2.0000000000000000);
    t42 = (t0 + 5008);
    t55 = (t42 + 56U);
    t61 = *((char **)t55);
    t80 = *((double *)t61);
    t17 = (t79 >= t80);
    *((unsigned int *)t27) = t17;
    t62 = (t27 + 4);
    *((unsigned int *)t62) = 0U;
    memset(t63, 0, 8);
    t65 = (t27 + 4);
    t21 = *((unsigned int *)t65);
    t22 = (~(t21));
    t23 = *((unsigned int *)t27);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t65) != 0)
        goto LAB55;

LAB56:    t28 = *((unsigned int *)t20);
    t29 = *((unsigned int *)t63);
    t30 = (t28 & t29);
    *((unsigned int *)t64) = t30;
    t70 = (t20 + 4);
    t71 = (t63 + 4);
    t72 = (t64 + 4);
    t34 = *((unsigned int *)t70);
    t35 = *((unsigned int *)t71);
    t36 = (t34 | t35);
    *((unsigned int *)t72) = t36;
    t37 = *((unsigned int *)t72);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB57;

LAB58:
LAB59:    goto LAB52;

LAB53:    *((unsigned int *)t63) = 1;
    goto LAB56;

LAB55:    t66 = (t63 + 4);
    *((unsigned int *)t63) = 1;
    *((unsigned int *)t66) = 1;
    goto LAB56;

LAB57:    t39 = *((unsigned int *)t64);
    t40 = *((unsigned int *)t72);
    *((unsigned int *)t64) = (t39 | t40);
    t73 = (t20 + 4);
    t75 = (t63 + 4);
    t43 = *((unsigned int *)t20);
    t44 = (~(t43));
    t45 = *((unsigned int *)t73);
    t47 = (~(t45));
    t48 = *((unsigned int *)t63);
    t49 = (~(t48));
    t51 = *((unsigned int *)t75);
    t52 = (~(t51));
    t46 = (t44 & t47);
    t50 = (t49 & t52);
    t53 = (~(t46));
    t54 = (~(t50));
    t56 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t56 & t53);
    t57 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t57 & t54);
    t58 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t58 & t53);
    t59 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t59 & t54);
    goto LAB59;

LAB60:    *((unsigned int *)t74) = 1;
    goto LAB63;

LAB62:    t83 = (t74 + 4);
    *((unsigned int *)t74) = 1;
    *((unsigned int *)t83) = 1;
    goto LAB63;

LAB64:    t88 = (t0 + 3728);
    t89 = (t88 + 56U);
    t90 = *((char **)t89);
    t91 = *((double *)t90);
    t92 = (t0 + 4208);
    t93 = (t92 + 56U);
    t94 = *((char **)t93);
    t95 = *((double *)t94);
    t96 = (t91 + t95);
    t97 = (t96 / 2.0000000000000000);
    t98 = (t0 + 5168);
    t99 = (t98 + 56U);
    t100 = *((char **)t99);
    t101 = *((double *)t100);
    t102 = (t97 <= t101);
    *((unsigned int *)t103) = t102;
    t104 = (t103 + 4);
    *((unsigned int *)t104) = 0U;
    memset(t105, 0, 8);
    t106 = (t103 + 4);
    t107 = *((unsigned int *)t106);
    t108 = (~(t107));
    t109 = *((unsigned int *)t103);
    t110 = (t109 & t108);
    t111 = (t110 & 1U);
    if (t111 != 0)
        goto LAB67;

LAB68:    if (*((unsigned int *)t106) != 0)
        goto LAB69;

LAB70:    t114 = *((unsigned int *)t74);
    t115 = *((unsigned int *)t105);
    t116 = (t114 & t115);
    *((unsigned int *)t113) = t116;
    t117 = (t74 + 4);
    t118 = (t105 + 4);
    t119 = (t113 + 4);
    t120 = *((unsigned int *)t117);
    t121 = *((unsigned int *)t118);
    t122 = (t120 | t121);
    *((unsigned int *)t119) = t122;
    t123 = *((unsigned int *)t119);
    t124 = (t123 != 0);
    if (t124 == 1)
        goto LAB71;

LAB72:
LAB73:    goto LAB66;

LAB67:    *((unsigned int *)t105) = 1;
    goto LAB70;

LAB69:    t112 = (t105 + 4);
    *((unsigned int *)t105) = 1;
    *((unsigned int *)t112) = 1;
    goto LAB70;

LAB71:    t125 = *((unsigned int *)t113);
    t126 = *((unsigned int *)t119);
    *((unsigned int *)t113) = (t125 | t126);
    t127 = (t74 + 4);
    t128 = (t105 + 4);
    t129 = *((unsigned int *)t74);
    t130 = (~(t129));
    t131 = *((unsigned int *)t127);
    t132 = (~(t131));
    t133 = *((unsigned int *)t105);
    t134 = (~(t133));
    t135 = *((unsigned int *)t128);
    t136 = (~(t135));
    t137 = (t130 & t132);
    t138 = (t134 & t136);
    t139 = (~(t137));
    t140 = (~(t138));
    t141 = *((unsigned int *)t119);
    *((unsigned int *)t119) = (t141 & t139);
    t142 = *((unsigned int *)t119);
    *((unsigned int *)t119) = (t142 & t140);
    t143 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t143 & t139);
    t144 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t144 & t140);
    goto LAB73;

LAB74:
LAB77:    t151 = ((char*)((ng6)));
    t152 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t152, t151, 0, 0, 1, 0LL);
    goto LAB76;

}

static void Always_130_8(char *t0)
{
    char t8[8];
    char t9[8];
    char t36[8];
    char t38[8];
    char t66[8];
    char t68[8];
    char t76[8];
    char t104[8];
    char t112[8];
    char t160[8];
    char t161[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    double t24;
    char *t25;
    char *t26;
    char *t27;
    double t28;
    double t29;
    double t30;
    char *t31;
    char *t32;
    char *t33;
    double t34;
    unsigned int t35;
    char *t37;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    char *t53;
    double t54;
    char *t55;
    char *t56;
    char *t57;
    double t58;
    double t59;
    double t60;
    char *t61;
    char *t62;
    char *t63;
    double t64;
    unsigned int t65;
    char *t67;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    int t99;
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
    double t153;
    char *t154;
    char *t155;
    char *t156;
    double t157;
    double t158;
    double t159;

LAB0:    t1 = (t0 + 8064U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8512);
    *((int *)t2) = 1;
    t3 = (t0 + 8096);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    t4 = (t0 + 4848);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng5)));
    memset(t8, 0, 8);
    xsi_vlog_signed_equal(t8, 32, t6, 32, t7, 32);
    memset(t9, 0, 8);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t10);
    t12 = (~(t11));
    t13 = *((unsigned int *)t8);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB5;

LAB6:    if (*((unsigned int *)t10) != 0)
        goto LAB7;

LAB8:    t17 = (t9 + 4);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t17);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB9;

LAB10:    memcpy(t112, t9, 8);

LAB11:    t144 = (t112 + 4);
    t145 = *((unsigned int *)t144);
    t146 = (~(t145));
    t147 = *((unsigned int *)t112);
    t148 = (t147 & t146);
    t149 = (t148 != 0);
    if (t149 > 0)
        goto LAB33;

LAB34:
LAB35:    goto LAB2;

LAB5:    *((unsigned int *)t9) = 1;
    goto LAB8;

LAB7:    t16 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB8;

LAB9:    t21 = (t0 + 3728);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = *((double *)t23);
    t25 = (t0 + 4208);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    t28 = *((double *)t27);
    t29 = (t24 + t28);
    t30 = (t29 / 2.0000000000000000);
    t31 = (t0 + 5008);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = *((double *)t33);
    t35 = (t30 < t34);
    *((unsigned int *)t36) = t35;
    t37 = (t36 + 4);
    *((unsigned int *)t37) = 0U;
    memset(t38, 0, 8);
    t39 = (t36 + 4);
    t40 = *((unsigned int *)t39);
    t41 = (~(t40));
    t42 = *((unsigned int *)t36);
    t43 = (t42 & t41);
    t44 = (t43 & 1U);
    if (t44 != 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t39) != 0)
        goto LAB14;

LAB15:    t46 = (t38 + 4);
    t47 = *((unsigned int *)t38);
    t48 = (!(t47));
    t49 = *((unsigned int *)t46);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB16;

LAB17:    memcpy(t76, t38, 8);

LAB18:    memset(t104, 0, 8);
    t105 = (t76 + 4);
    t106 = *((unsigned int *)t105);
    t107 = (~(t106));
    t108 = *((unsigned int *)t76);
    t109 = (t108 & t107);
    t110 = (t109 & 1U);
    if (t110 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t105) != 0)
        goto LAB28;

LAB29:    t113 = *((unsigned int *)t9);
    t114 = *((unsigned int *)t104);
    t115 = (t113 & t114);
    *((unsigned int *)t112) = t115;
    t116 = (t9 + 4);
    t117 = (t104 + 4);
    t118 = (t112 + 4);
    t119 = *((unsigned int *)t116);
    t120 = *((unsigned int *)t117);
    t121 = (t119 | t120);
    *((unsigned int *)t118) = t121;
    t122 = *((unsigned int *)t118);
    t123 = (t122 != 0);
    if (t123 == 1)
        goto LAB30;

LAB31:
LAB32:    goto LAB11;

LAB12:    *((unsigned int *)t38) = 1;
    goto LAB15;

LAB14:    t45 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB15;

LAB16:    t51 = (t0 + 3728);
    t52 = (t51 + 56U);
    t53 = *((char **)t52);
    t54 = *((double *)t53);
    t55 = (t0 + 4208);
    t56 = (t55 + 56U);
    t57 = *((char **)t56);
    t58 = *((double *)t57);
    t59 = (t54 + t58);
    t60 = (t59 / 2.0000000000000000);
    t61 = (t0 + 5168);
    t62 = (t61 + 56U);
    t63 = *((char **)t62);
    t64 = *((double *)t63);
    t65 = (t60 > t64);
    *((unsigned int *)t66) = t65;
    t67 = (t66 + 4);
    *((unsigned int *)t67) = 0U;
    memset(t68, 0, 8);
    t69 = (t66 + 4);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t66);
    t73 = (t72 & t71);
    t74 = (t73 & 1U);
    if (t74 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t69) != 0)
        goto LAB21;

LAB22:    t77 = *((unsigned int *)t38);
    t78 = *((unsigned int *)t68);
    t79 = (t77 | t78);
    *((unsigned int *)t76) = t79;
    t80 = (t38 + 4);
    t81 = (t68 + 4);
    t82 = (t76 + 4);
    t83 = *((unsigned int *)t80);
    t84 = *((unsigned int *)t81);
    t85 = (t83 | t84);
    *((unsigned int *)t82) = t85;
    t86 = *((unsigned int *)t82);
    t87 = (t86 != 0);
    if (t87 == 1)
        goto LAB23;

LAB24:
LAB25:    goto LAB18;

LAB19:    *((unsigned int *)t68) = 1;
    goto LAB22;

LAB21:    t75 = (t68 + 4);
    *((unsigned int *)t68) = 1;
    *((unsigned int *)t75) = 1;
    goto LAB22;

LAB23:    t88 = *((unsigned int *)t76);
    t89 = *((unsigned int *)t82);
    *((unsigned int *)t76) = (t88 | t89);
    t90 = (t38 + 4);
    t91 = (t68 + 4);
    t92 = *((unsigned int *)t90);
    t93 = (~(t92));
    t94 = *((unsigned int *)t38);
    t95 = (t94 & t93);
    t96 = *((unsigned int *)t91);
    t97 = (~(t96));
    t98 = *((unsigned int *)t68);
    t99 = (t98 & t97);
    t100 = (~(t95));
    t101 = (~(t99));
    t102 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t102 & t100);
    t103 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t103 & t101);
    goto LAB25;

LAB26:    *((unsigned int *)t104) = 1;
    goto LAB29;

LAB28:    t111 = (t104 + 4);
    *((unsigned int *)t104) = 1;
    *((unsigned int *)t111) = 1;
    goto LAB29;

LAB30:    t124 = *((unsigned int *)t112);
    t125 = *((unsigned int *)t118);
    *((unsigned int *)t112) = (t124 | t125);
    t126 = (t9 + 4);
    t127 = (t104 + 4);
    t128 = *((unsigned int *)t9);
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
    goto LAB32;

LAB33:
LAB36:    t150 = (t0 + 3728);
    t151 = (t150 + 56U);
    t152 = *((char **)t151);
    t153 = *((double *)t152);
    t154 = (t0 + 4208);
    t155 = (t154 + 56U);
    t156 = *((char **)t155);
    t157 = *((double *)t156);
    t158 = (t153 + t157);
    t159 = (t158 / 2.0000000000000000);
    *((double *)t160) = t159;
    xsi_vlogfile_write(1, 0, 0, ng7, 2, t0, (char)114, t160, 64);
    t2 = (t0 + 880);
    t3 = *((char **)t2);
    t2 = xsi_vlog_time(t161, 1000.0000000000000, 1.0000000000000000);
    xsi_vlogfile_write(1, 0, 0, ng8, 3, t0, (char)118, t3, 80, (char)118, t161, 64);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    t2 = (t0 + 5008);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t24 = *((double *)t4);
    *((double *)t8) = t24;
    xsi_vlogfile_write(1, 0, 0, ng10, 2, t0, (char)114, t8, 64);
    t2 = (t0 + 5168);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t24 = *((double *)t4);
    *((double *)t8) = t24;
    xsi_vlogfile_write(1, 0, 0, ng11, 2, t0, (char)114, t8, 64);
    goto LAB35;

}


extern void unisims_ver_m_16563680829031172685_3486989180_init()
{
	static char *pe[] = {(void *)NetDecl_50_0,(void *)Cont_71_1,(void *)Cont_73_2,(void *)Cont_74_3,(void *)Cont_75_4,(void *)Cont_76_5,(void *)Always_79_6,(void *)Always_107_7,(void *)Always_130_8};
	xsi_register_didat("unisims_ver_m_16563680829031172685_3486989180", "isim/PicoTestbench_isim_beh.exe.sim/unisims_ver/m_16563680829031172685_3486989180.didat");
	xsi_register_executes(pe);
}
