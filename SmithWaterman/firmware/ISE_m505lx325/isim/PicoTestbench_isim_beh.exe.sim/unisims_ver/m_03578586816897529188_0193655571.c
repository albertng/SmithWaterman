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
static int ng0[] = {5001047, 0, 0, 0, 0, 0};
static int ng1[] = {1380794700, 0, 20047, 0, 0, 0};
static int ng2[] = {1128354373, 0, 1330533471, 0, 68, 0};
static const char *ng3 = "Attribute Syntax Error : The attribute CAPACITANCE on IBUFGDS instance %m is set to %s.  Legal values for this attribute are DONT_CARE, LOW or NORMAL.";
static int ng4[] = {1414681925, 0, 0, 0};
static int ng5[] = {1095521093, 0, 70, 0};
static const char *ng6 = "Attribute Syntax Error : The attribute DIFF_TERM on IBUFGDS instance %m is set to %s.  Legal values for this attribute are TRUE or FALSE.";
static int ng7[] = {48, 0};
static int ng8[] = {49, 0};
static int ng9[] = {50, 0};
static int ng10[] = {51, 0};
static int ng11[] = {52, 0};
static int ng12[] = {53, 0};
static int ng13[] = {54, 0};
static int ng14[] = {55, 0};
static int ng15[] = {56, 0};
static int ng16[] = {57, 0};
static int ng17[] = {12592, 0};
static int ng18[] = {12593, 0};
static int ng19[] = {12594, 0};
static int ng20[] = {12595, 0};
static int ng21[] = {12596, 0};
static int ng22[] = {12597, 0};
static int ng23[] = {12598, 0};
static const char *ng24 = "Attribute Syntax Error : The attribute IBUF_DELAY_VALUE on IBUFGDS instance %m is set to %s.  Legal values for this attribute are 0, 1, 2, ... or 16.";
static const char *ng25 = "Attribute Syntax Error : The attribute IBUF_LOW_PWR on IBUF instance %m is set to %s.  Legal values for this attribute are TRUE or FALSE.";
static unsigned int ng26[] = {1U, 0U};
static unsigned int ng27[] = {0U, 0U};
static unsigned int ng28[] = {1U, 1U};
static unsigned int ng29[] = {0U, 1U};



static void Gate_42_0(char *t0)
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
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 3360U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4272);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 4);
    t11 = (t4 + 4);
    if (*((unsigned int *)t11) == 1)
        goto LAB4;

LAB5:    t12 = *((unsigned int *)t4);
    t13 = (t12 & 1);
    *((unsigned int *)t9) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 & 1);
    *((unsigned int *)t10) = t15;

LAB6:    t16 = (t0 + 4272);
    xsi_driver_vfirst_trans(t16, 0, 0);
    t17 = (t0 + 4176);
    *((int *)t17) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t9) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB6;

}

static void Initial_44_1(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    int t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    char *t12;
    int t13;
    char *t14;
    int t15;
    char *t16;
    int t17;
    char *t18;
    int t19;
    char *t20;
    int t21;
    char *t22;
    int t23;
    char *t24;
    int t25;
    char *t26;
    int t27;
    char *t28;
    int t29;
    char *t30;
    int t31;
    char *t32;
    int t33;
    char *t34;
    int t35;
    char *t36;
    int t37;
    char *t38;
    char *t39;

LAB0:
LAB2:    t1 = (t0 + 472);
    t2 = *((char **)t1);

LAB3:    t1 = ((char*)((ng0)));
    t3 = xsi_vlog_unsigned_case_compare(t2, 72, t1, 72);
    if (t3 == 1)
        goto LAB4;

LAB5:    t4 = ((char*)((ng1)));
    t5 = xsi_vlog_unsigned_case_compare(t2, 72, t4, 72);
    if (t5 == 1)
        goto LAB6;

LAB7:    t6 = ((char*)((ng2)));
    t7 = xsi_vlog_unsigned_case_compare(t2, 72, t6, 72);
    if (t7 == 1)
        goto LAB8;

LAB9:
LAB11:
LAB10:
LAB13:    t8 = (t0 + 472);
    t9 = *((char **)t8);
    xsi_vlogfile_write(1, 0, 0, ng3, 2, t0, (char)118, t9, 72);
    xsi_vlog_finish(1);

LAB12:    t1 = (t0 + 608);
    t4 = *((char **)t1);

LAB14:    t1 = ((char*)((ng4)));
    t3 = xsi_vlog_unsigned_case_compare(t4, 40, t1, 40);
    if (t3 == 1)
        goto LAB15;

LAB16:    t6 = ((char*)((ng5)));
    t5 = xsi_vlog_unsigned_case_compare(t4, 40, t6, 40);
    if (t5 == 1)
        goto LAB17;

LAB18:
LAB20:
LAB19:
LAB22:    t8 = (t0 + 608);
    t9 = *((char **)t8);
    xsi_vlogfile_write(1, 0, 0, ng6, 2, t0, (char)118, t9, 40);
    xsi_vlog_finish(1);

LAB21:    t1 = (t0 + 744);
    t6 = *((char **)t1);

LAB23:    t1 = ((char*)((ng7)));
    t3 = xsi_vlog_unsigned_case_compare(t6, 8, t1, 16);
    if (t3 == 1)
        goto LAB24;

LAB25:    t8 = ((char*)((ng8)));
    t5 = xsi_vlog_unsigned_case_compare(t6, 8, t8, 16);
    if (t5 == 1)
        goto LAB26;

LAB27:    t9 = ((char*)((ng9)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 8, t9, 16);
    if (t7 == 1)
        goto LAB28;

LAB29:    t10 = ((char*)((ng10)));
    t11 = xsi_vlog_unsigned_case_compare(t6, 8, t10, 16);
    if (t11 == 1)
        goto LAB30;

LAB31:    t12 = ((char*)((ng11)));
    t13 = xsi_vlog_unsigned_case_compare(t6, 8, t12, 16);
    if (t13 == 1)
        goto LAB32;

LAB33:    t14 = ((char*)((ng12)));
    t15 = xsi_vlog_unsigned_case_compare(t6, 8, t14, 16);
    if (t15 == 1)
        goto LAB34;

LAB35:    t16 = ((char*)((ng13)));
    t17 = xsi_vlog_unsigned_case_compare(t6, 8, t16, 16);
    if (t17 == 1)
        goto LAB36;

LAB37:    t18 = ((char*)((ng14)));
    t19 = xsi_vlog_unsigned_case_compare(t6, 8, t18, 16);
    if (t19 == 1)
        goto LAB38;

LAB39:    t20 = ((char*)((ng15)));
    t21 = xsi_vlog_unsigned_case_compare(t6, 8, t20, 16);
    if (t21 == 1)
        goto LAB40;

LAB41:    t22 = ((char*)((ng16)));
    t23 = xsi_vlog_unsigned_case_compare(t6, 8, t22, 16);
    if (t23 == 1)
        goto LAB42;

LAB43:    t24 = ((char*)((ng17)));
    t25 = xsi_vlog_unsigned_case_compare(t6, 8, t24, 16);
    if (t25 == 1)
        goto LAB44;

LAB45:    t26 = ((char*)((ng18)));
    t27 = xsi_vlog_unsigned_case_compare(t6, 8, t26, 16);
    if (t27 == 1)
        goto LAB46;

LAB47:    t28 = ((char*)((ng19)));
    t29 = xsi_vlog_unsigned_case_compare(t6, 8, t28, 16);
    if (t29 == 1)
        goto LAB48;

LAB49:    t30 = ((char*)((ng20)));
    t31 = xsi_vlog_unsigned_case_compare(t6, 8, t30, 16);
    if (t31 == 1)
        goto LAB50;

LAB51:    t32 = ((char*)((ng21)));
    t33 = xsi_vlog_unsigned_case_compare(t6, 8, t32, 16);
    if (t33 == 1)
        goto LAB52;

LAB53:    t34 = ((char*)((ng22)));
    t35 = xsi_vlog_unsigned_case_compare(t6, 8, t34, 16);
    if (t35 == 1)
        goto LAB54;

LAB55:    t36 = ((char*)((ng23)));
    t37 = xsi_vlog_unsigned_case_compare(t6, 8, t36, 16);
    if (t37 == 1)
        goto LAB56;

LAB57:
LAB59:
LAB58:
LAB61:    t38 = (t0 + 744);
    t39 = *((char **)t38);
    xsi_vlogfile_write(1, 0, 0, ng24, 2, t0, (char)118, t39, 8);
    xsi_vlog_finish(1);

LAB60:    t1 = (t0 + 880);
    t8 = *((char **)t1);

LAB62:    t1 = ((char*)((ng5)));
    t3 = xsi_vlog_unsigned_case_compare(t8, 32, t1, 40);
    if (t3 == 1)
        goto LAB63;

LAB64:    t9 = ((char*)((ng4)));
    t5 = xsi_vlog_unsigned_case_compare(t8, 32, t9, 40);
    if (t5 == 1)
        goto LAB65;

LAB66:
LAB68:
LAB67:
LAB70:    t10 = (t0 + 880);
    t12 = *((char **)t10);
    xsi_vlogfile_write(1, 0, 0, ng25, 2, t0, (char)118, t12, 32);
    xsi_vlog_finish(1);

LAB69:
LAB1:    return;
LAB4:    goto LAB12;

LAB6:    goto LAB4;

LAB8:    goto LAB4;

LAB15:    goto LAB21;

LAB17:    goto LAB15;

LAB24:    goto LAB60;

LAB26:    goto LAB24;

LAB28:    goto LAB24;

LAB30:    goto LAB24;

LAB32:    goto LAB24;

LAB34:    goto LAB24;

LAB36:    goto LAB24;

LAB38:    goto LAB24;

LAB40:    goto LAB24;

LAB42:    goto LAB24;

LAB44:    goto LAB24;

LAB46:    goto LAB24;

LAB48:    goto LAB24;

LAB50:    goto LAB24;

LAB52:    goto LAB24;

LAB54:    goto LAB24;

LAB56:    goto LAB24;

LAB63:    goto LAB69;

LAB65:    goto LAB63;

}

static void Always_91_2(char *t0)
{
    char t6[8];
    char t22[8];
    char t36[8];
    char t52[8];
    char t60[8];
    char t100[8];
    char t102[8];
    char t118[8];
    char t126[8];
    char t154[8];
    char t169[8];
    char t185[8];
    char t193[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
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
    char *t21;
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
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t53;
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
    unsigned int t101;
    char *t103;
    char *t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    char *t130;
    char *t131;
    char *t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    char *t140;
    char *t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    char *t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    char *t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t167;
    char *t168;
    char *t170;
    char *t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    char *t184;
    char *t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    char *t192;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    char *t197;
    char *t198;
    char *t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    char *t207;
    char *t208;
    unsigned int t209;
    unsigned int t210;
    unsigned int t211;
    int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    int t216;
    unsigned int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    char *t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    char *t227;
    char *t228;

LAB0:    t1 = (t0 + 3856U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4192);
    *((int *)t2) = 1;
    t3 = (t0 + 3888);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 1888U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng26)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    memset(t22, 0, 8);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) != 0)
        goto LAB12;

LAB13:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t30);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB14;

LAB15:    memcpy(t60, t22, 8);

LAB16:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB28;

LAB29:    t2 = (t0 + 1888U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng27)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB34;

LAB31:    if (t18 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t6) = 1;

LAB34:    memset(t22, 0, 8);
    t8 = (t6 + 4);
    t24 = *((unsigned int *)t8);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t8) != 0)
        goto LAB37;

LAB38:    t23 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t23);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB39;

LAB40:    memcpy(t60, t22, 8);

LAB41:    t74 = (t60 + 4);
    t93 = *((unsigned int *)t74);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB53;

LAB54:    t2 = (t0 + 1888U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng28)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB59;

LAB56:    if (t18 != 0)
        goto LAB58;

LAB57:    *((unsigned int *)t6) = 1;

LAB59:    memset(t22, 0, 8);
    t8 = (t6 + 4);
    t24 = *((unsigned int *)t8);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t8) != 0)
        goto LAB62;

LAB63:    t23 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = (!(t31));
    t33 = *((unsigned int *)t23);
    t39 = (t32 || t33);
    if (t39 > 0)
        goto LAB64;

LAB65:    memcpy(t60, t22, 8);

LAB66:    memset(t100, 0, 8);
    t74 = (t60 + 4);
    t89 = *((unsigned int *)t74);
    t90 = (~(t89));
    t91 = *((unsigned int *)t60);
    t93 = (t91 & t90);
    t94 = (t93 & 1U);
    if (t94 != 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t74) != 0)
        goto LAB80;

LAB81:    t92 = (t100 + 4);
    t95 = *((unsigned int *)t100);
    t96 = (!(t95));
    t97 = *((unsigned int *)t92);
    t101 = (t96 || t97);
    if (t101 > 0)
        goto LAB82;

LAB83:    memcpy(t126, t100, 8);

LAB84:    memset(t154, 0, 8);
    t155 = (t126 + 4);
    t156 = *((unsigned int *)t155);
    t157 = (~(t156));
    t158 = *((unsigned int *)t126);
    t159 = (t158 & t157);
    t160 = (t159 & 1U);
    if (t160 != 0)
        goto LAB96;

LAB97:    if (*((unsigned int *)t155) != 0)
        goto LAB98;

LAB99:    t162 = (t154 + 4);
    t163 = *((unsigned int *)t154);
    t164 = (!(t163));
    t165 = *((unsigned int *)t162);
    t166 = (t164 || t165);
    if (t166 > 0)
        goto LAB100;

LAB101:    memcpy(t193, t154, 8);

LAB102:    t221 = (t193 + 4);
    t222 = *((unsigned int *)t221);
    t223 = (~(t222));
    t224 = *((unsigned int *)t193);
    t225 = (t224 & t223);
    t226 = (t225 != 0);
    if (t226 > 0)
        goto LAB114;

LAB115:
LAB116:
LAB55:
LAB30:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t22) = 1;
    goto LAB13;

LAB12:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB13;

LAB14:    t34 = (t0 + 2048U);
    t35 = *((char **)t34);
    t34 = ((char*)((ng27)));
    memset(t36, 0, 8);
    t37 = (t35 + 4);
    t38 = (t34 + 4);
    t39 = *((unsigned int *)t35);
    t40 = *((unsigned int *)t34);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t37);
    t43 = *((unsigned int *)t38);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t37);
    t47 = *((unsigned int *)t38);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB20;

LAB17:    if (t48 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t36) = 1;

LAB20:    memset(t52, 0, 8);
    t53 = (t36 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t36);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t53) != 0)
        goto LAB23;

LAB24:    t61 = *((unsigned int *)t22);
    t62 = *((unsigned int *)t52);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t22 + 4);
    t65 = (t52 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB19:    t51 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t52) = 1;
    goto LAB24;

LAB23:    t59 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB24;

LAB25:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t22 + 4);
    t75 = (t52 + 4);
    t76 = *((unsigned int *)t22);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t52);
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
    goto LAB27;

LAB28:    t98 = (t0 + 1888U);
    t99 = *((char **)t98);
    t98 = (t0 + 2448);
    xsi_vlogvar_wait_assign_value(t98, t99, 0, 0, 1, 0LL);
    goto LAB30;

LAB33:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB34;

LAB35:    *((unsigned int *)t22) = 1;
    goto LAB38;

LAB37:    t21 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB38;

LAB39:    t29 = (t0 + 2048U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng26)));
    memset(t36, 0, 8);
    t34 = (t30 + 4);
    t35 = (t29 + 4);
    t39 = *((unsigned int *)t30);
    t40 = *((unsigned int *)t29);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t34);
    t43 = *((unsigned int *)t35);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t34);
    t47 = *((unsigned int *)t35);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB45;

LAB42:    if (t48 != 0)
        goto LAB44;

LAB43:    *((unsigned int *)t36) = 1;

LAB45:    memset(t52, 0, 8);
    t38 = (t36 + 4);
    t54 = *((unsigned int *)t38);
    t55 = (~(t54));
    t56 = *((unsigned int *)t36);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t38) != 0)
        goto LAB48;

LAB49:    t61 = *((unsigned int *)t22);
    t62 = *((unsigned int *)t52);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t53 = (t22 + 4);
    t59 = (t52 + 4);
    t64 = (t60 + 4);
    t67 = *((unsigned int *)t53);
    t68 = *((unsigned int *)t59);
    t69 = (t67 | t68);
    *((unsigned int *)t64) = t69;
    t70 = *((unsigned int *)t64);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB41;

LAB44:    t37 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB45;

LAB46:    *((unsigned int *)t52) = 1;
    goto LAB49;

LAB48:    t51 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB49;

LAB50:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t64);
    *((unsigned int *)t60) = (t72 | t73);
    t65 = (t22 + 4);
    t66 = (t52 + 4);
    t76 = *((unsigned int *)t22);
    t77 = (~(t76));
    t78 = *((unsigned int *)t65);
    t79 = (~(t78));
    t80 = *((unsigned int *)t52);
    t81 = (~(t80));
    t82 = *((unsigned int *)t66);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t88 & t86);
    t89 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB52;

LAB53:    t75 = (t0 + 1888U);
    t92 = *((char **)t75);
    t75 = (t0 + 2448);
    xsi_vlogvar_wait_assign_value(t75, t92, 0, 0, 1, 0LL);
    goto LAB55;

LAB58:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB59;

LAB60:    *((unsigned int *)t22) = 1;
    goto LAB63;

LAB62:    t21 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB63;

LAB64:    t29 = (t0 + 1888U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng29)));
    memset(t36, 0, 8);
    t34 = (t30 + 4);
    t35 = (t29 + 4);
    t40 = *((unsigned int *)t30);
    t41 = *((unsigned int *)t29);
    t42 = (t40 ^ t41);
    t43 = *((unsigned int *)t34);
    t44 = *((unsigned int *)t35);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t47 = *((unsigned int *)t34);
    t48 = *((unsigned int *)t35);
    t49 = (t47 | t48);
    t50 = (~(t49));
    t54 = (t46 & t50);
    if (t54 != 0)
        goto LAB70;

LAB67:    if (t49 != 0)
        goto LAB69;

LAB68:    *((unsigned int *)t36) = 1;

LAB70:    memset(t52, 0, 8);
    t38 = (t36 + 4);
    t55 = *((unsigned int *)t38);
    t56 = (~(t55));
    t57 = *((unsigned int *)t36);
    t58 = (t57 & t56);
    t61 = (t58 & 1U);
    if (t61 != 0)
        goto LAB71;

LAB72:    if (*((unsigned int *)t38) != 0)
        goto LAB73;

LAB74:    t62 = *((unsigned int *)t22);
    t63 = *((unsigned int *)t52);
    t67 = (t62 | t63);
    *((unsigned int *)t60) = t67;
    t53 = (t22 + 4);
    t59 = (t52 + 4);
    t64 = (t60 + 4);
    t68 = *((unsigned int *)t53);
    t69 = *((unsigned int *)t59);
    t70 = (t68 | t69);
    *((unsigned int *)t64) = t70;
    t71 = *((unsigned int *)t64);
    t72 = (t71 != 0);
    if (t72 == 1)
        goto LAB75;

LAB76:
LAB77:    goto LAB66;

LAB69:    t37 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB70;

LAB71:    *((unsigned int *)t52) = 1;
    goto LAB74;

LAB73:    t51 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB74;

LAB75:    t73 = *((unsigned int *)t60);
    t76 = *((unsigned int *)t64);
    *((unsigned int *)t60) = (t73 | t76);
    t65 = (t22 + 4);
    t66 = (t52 + 4);
    t77 = *((unsigned int *)t65);
    t78 = (~(t77));
    t79 = *((unsigned int *)t22);
    t84 = (t79 & t78);
    t80 = *((unsigned int *)t66);
    t81 = (~(t80));
    t82 = *((unsigned int *)t52);
    t85 = (t82 & t81);
    t83 = (~(t84));
    t86 = (~(t85));
    t87 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t87 & t83);
    t88 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t88 & t86);
    goto LAB77;

LAB78:    *((unsigned int *)t100) = 1;
    goto LAB81;

LAB80:    t75 = (t100 + 4);
    *((unsigned int *)t100) = 1;
    *((unsigned int *)t75) = 1;
    goto LAB81;

LAB82:    t98 = (t0 + 2048U);
    t99 = *((char **)t98);
    t98 = ((char*)((ng28)));
    memset(t102, 0, 8);
    t103 = (t99 + 4);
    t104 = (t98 + 4);
    t105 = *((unsigned int *)t99);
    t106 = *((unsigned int *)t98);
    t107 = (t105 ^ t106);
    t108 = *((unsigned int *)t103);
    t109 = *((unsigned int *)t104);
    t110 = (t108 ^ t109);
    t111 = (t107 | t110);
    t112 = *((unsigned int *)t103);
    t113 = *((unsigned int *)t104);
    t114 = (t112 | t113);
    t115 = (~(t114));
    t116 = (t111 & t115);
    if (t116 != 0)
        goto LAB88;

LAB85:    if (t114 != 0)
        goto LAB87;

LAB86:    *((unsigned int *)t102) = 1;

LAB88:    memset(t118, 0, 8);
    t119 = (t102 + 4);
    t120 = *((unsigned int *)t119);
    t121 = (~(t120));
    t122 = *((unsigned int *)t102);
    t123 = (t122 & t121);
    t124 = (t123 & 1U);
    if (t124 != 0)
        goto LAB89;

LAB90:    if (*((unsigned int *)t119) != 0)
        goto LAB91;

LAB92:    t127 = *((unsigned int *)t100);
    t128 = *((unsigned int *)t118);
    t129 = (t127 | t128);
    *((unsigned int *)t126) = t129;
    t130 = (t100 + 4);
    t131 = (t118 + 4);
    t132 = (t126 + 4);
    t133 = *((unsigned int *)t130);
    t134 = *((unsigned int *)t131);
    t135 = (t133 | t134);
    *((unsigned int *)t132) = t135;
    t136 = *((unsigned int *)t132);
    t137 = (t136 != 0);
    if (t137 == 1)
        goto LAB93;

LAB94:
LAB95:    goto LAB84;

LAB87:    t117 = (t102 + 4);
    *((unsigned int *)t102) = 1;
    *((unsigned int *)t117) = 1;
    goto LAB88;

LAB89:    *((unsigned int *)t118) = 1;
    goto LAB92;

LAB91:    t125 = (t118 + 4);
    *((unsigned int *)t118) = 1;
    *((unsigned int *)t125) = 1;
    goto LAB92;

LAB93:    t138 = *((unsigned int *)t126);
    t139 = *((unsigned int *)t132);
    *((unsigned int *)t126) = (t138 | t139);
    t140 = (t100 + 4);
    t141 = (t118 + 4);
    t142 = *((unsigned int *)t140);
    t143 = (~(t142));
    t144 = *((unsigned int *)t100);
    t145 = (t144 & t143);
    t146 = *((unsigned int *)t141);
    t147 = (~(t146));
    t148 = *((unsigned int *)t118);
    t149 = (t148 & t147);
    t150 = (~(t145));
    t151 = (~(t149));
    t152 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t152 & t150);
    t153 = *((unsigned int *)t132);
    *((unsigned int *)t132) = (t153 & t151);
    goto LAB95;

LAB96:    *((unsigned int *)t154) = 1;
    goto LAB99;

LAB98:    t161 = (t154 + 4);
    *((unsigned int *)t154) = 1;
    *((unsigned int *)t161) = 1;
    goto LAB99;

LAB100:    t167 = (t0 + 2048U);
    t168 = *((char **)t167);
    t167 = ((char*)((ng29)));
    memset(t169, 0, 8);
    t170 = (t168 + 4);
    t171 = (t167 + 4);
    t172 = *((unsigned int *)t168);
    t173 = *((unsigned int *)t167);
    t174 = (t172 ^ t173);
    t175 = *((unsigned int *)t170);
    t176 = *((unsigned int *)t171);
    t177 = (t175 ^ t176);
    t178 = (t174 | t177);
    t179 = *((unsigned int *)t170);
    t180 = *((unsigned int *)t171);
    t181 = (t179 | t180);
    t182 = (~(t181));
    t183 = (t178 & t182);
    if (t183 != 0)
        goto LAB106;

LAB103:    if (t181 != 0)
        goto LAB105;

LAB104:    *((unsigned int *)t169) = 1;

LAB106:    memset(t185, 0, 8);
    t186 = (t169 + 4);
    t187 = *((unsigned int *)t186);
    t188 = (~(t187));
    t189 = *((unsigned int *)t169);
    t190 = (t189 & t188);
    t191 = (t190 & 1U);
    if (t191 != 0)
        goto LAB107;

LAB108:    if (*((unsigned int *)t186) != 0)
        goto LAB109;

LAB110:    t194 = *((unsigned int *)t154);
    t195 = *((unsigned int *)t185);
    t196 = (t194 | t195);
    *((unsigned int *)t193) = t196;
    t197 = (t154 + 4);
    t198 = (t185 + 4);
    t199 = (t193 + 4);
    t200 = *((unsigned int *)t197);
    t201 = *((unsigned int *)t198);
    t202 = (t200 | t201);
    *((unsigned int *)t199) = t202;
    t203 = *((unsigned int *)t199);
    t204 = (t203 != 0);
    if (t204 == 1)
        goto LAB111;

LAB112:
LAB113:    goto LAB102;

LAB105:    t184 = (t169 + 4);
    *((unsigned int *)t169) = 1;
    *((unsigned int *)t184) = 1;
    goto LAB106;

LAB107:    *((unsigned int *)t185) = 1;
    goto LAB110;

LAB109:    t192 = (t185 + 4);
    *((unsigned int *)t185) = 1;
    *((unsigned int *)t192) = 1;
    goto LAB110;

LAB111:    t205 = *((unsigned int *)t193);
    t206 = *((unsigned int *)t199);
    *((unsigned int *)t193) = (t205 | t206);
    t207 = (t154 + 4);
    t208 = (t185 + 4);
    t209 = *((unsigned int *)t207);
    t210 = (~(t209));
    t211 = *((unsigned int *)t154);
    t212 = (t211 & t210);
    t213 = *((unsigned int *)t208);
    t214 = (~(t213));
    t215 = *((unsigned int *)t185);
    t216 = (t215 & t214);
    t217 = (~(t212));
    t218 = (~(t216));
    t219 = *((unsigned int *)t199);
    *((unsigned int *)t199) = (t219 & t217);
    t220 = *((unsigned int *)t199);
    *((unsigned int *)t199) = (t220 & t218);
    goto LAB113;

LAB114:    t227 = ((char*)((ng28)));
    t228 = (t0 + 2448);
    xsi_vlogvar_wait_assign_value(t228, t227, 0, 0, 1, 0LL);
    goto LAB116;

}


extern void unisims_ver_m_03578586816897529188_0193655571_init()
{
	static char *pe[] = {(void *)Gate_42_0,(void *)Initial_44_1,(void *)Always_91_2};
	xsi_register_didat("unisims_ver_m_03578586816897529188_0193655571", "isim/PicoTestbench_isim_beh.exe.sim/unisims_ver/m_03578586816897529188_0193655571.didat");
	xsi_register_executes(pe);
}
