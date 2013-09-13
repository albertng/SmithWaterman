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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/iserdese2/B_ISERDESE2_enc.v";
static unsigned int ng1[] = {0U, 1U};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {1U, 1U};



static void Cont_5323_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t17[8];
    char t26[8];
    char t34[8];
    char t83[8];
    char t84[8];
    char t85[8];
    char t93[8];
    char t107[8];
    char t114[8];
    char t162[8];
    char t163[8];
    char t166[8];
    char t177[8];
    char t186[8];
    char t194[8];
    char t242[8];
    char t243[8];
    char t244[8];
    char t253[8];
    char t267[8];
    char t274[8];
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
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
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
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    char *t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    char *t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    char *t106;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t113;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    char *t118;
    char *t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    char *t128;
    char *t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    int t138;
    int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    char *t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    char *t152;
    char *t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    char *t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    char *t164;
    char *t165;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    char *t172;
    char *t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    char *t178;
    char *t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    char *t185;
    char *t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    char *t193;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    char *t198;
    char *t199;
    char *t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    char *t208;
    char *t209;
    unsigned int t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    int t218;
    int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    char *t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    unsigned int t230;
    unsigned int t231;
    char *t232;
    char *t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    char *t237;
    unsigned int t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    char *t245;
    char *t246;
    unsigned int t247;
    unsigned int t248;
    unsigned int t249;
    unsigned int t250;
    unsigned int t251;
    char *t252;
    char *t254;
    unsigned int t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    unsigned int t259;
    char *t260;
    char *t261;
    unsigned int t262;
    unsigned int t263;
    unsigned int t264;
    char *t265;
    char *t266;
    unsigned int t268;
    unsigned int t269;
    unsigned int t270;
    unsigned int t271;
    unsigned int t272;
    char *t273;
    unsigned int t275;
    unsigned int t276;
    unsigned int t277;
    char *t278;
    char *t279;
    char *t280;
    unsigned int t281;
    unsigned int t282;
    unsigned int t283;
    unsigned int t284;
    unsigned int t285;
    unsigned int t286;
    unsigned int t287;
    char *t288;
    char *t289;
    unsigned int t290;
    unsigned int t291;
    unsigned int t292;
    unsigned int t293;
    unsigned int t294;
    unsigned int t295;
    unsigned int t296;
    unsigned int t297;
    int t298;
    int t299;
    unsigned int t300;
    unsigned int t301;
    unsigned int t302;
    unsigned int t303;
    unsigned int t304;
    unsigned int t305;
    char *t306;
    unsigned int t307;
    unsigned int t308;
    unsigned int t309;
    unsigned int t310;
    unsigned int t311;
    char *t312;
    char *t313;
    unsigned int t314;
    unsigned int t315;
    unsigned int t316;
    char *t317;
    unsigned int t318;
    unsigned int t319;
    unsigned int t320;
    unsigned int t321;
    char *t322;
    char *t323;
    char *t324;
    char *t325;
    char *t326;
    char *t327;
    unsigned int t328;
    unsigned int t329;
    char *t330;
    unsigned int t331;
    unsigned int t332;
    char *t333;
    unsigned int t334;
    unsigned int t335;
    char *t336;

LAB0:    t1 = (t0 + 2680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(5323, ng0);
    t2 = (t0 + 1368U);
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

LAB9:    memcpy(t34, t6, 8);

LAB10:    memset(t4, 0, 8);
    t66 = (t34 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (~(t67));
    t69 = *((unsigned int *)t34);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t66) != 0)
        goto LAB24;

LAB25:    t73 = (t4 + 4);
    t74 = *((unsigned int *)t4);
    t75 = *((unsigned int *)t73);
    t76 = (t74 || t75);
    if (t76 > 0)
        goto LAB26;

LAB27:    t79 = *((unsigned int *)t4);
    t80 = (~(t79));
    t81 = *((unsigned int *)t73);
    t82 = (t80 || t81);
    if (t82 > 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t73) > 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t4) > 0)
        goto LAB32;

LAB33:    memcpy(t3, t83, 8);

LAB34:    t323 = (t0 + 3080);
    t324 = (t323 + 56U);
    t325 = *((char **)t324);
    t326 = (t325 + 56U);
    t327 = *((char **)t326);
    memset(t327, 0, 8);
    t328 = 1U;
    t329 = t328;
    t330 = (t3 + 4);
    t331 = *((unsigned int *)t3);
    t328 = (t328 & t331);
    t332 = *((unsigned int *)t330);
    t329 = (t329 & t332);
    t333 = (t327 + 4);
    t334 = *((unsigned int *)t327);
    *((unsigned int *)t327) = (t334 | t328);
    t335 = *((unsigned int *)t333);
    *((unsigned int *)t333) = (t335 | t329);
    xsi_driver_vfirst_trans(t323, 0, 0);
    t336 = (t0 + 3000);
    *((int *)t336) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t6) = 1;
    goto LAB7;

LAB6:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 1528U);
    t19 = *((char **)t18);
    memset(t17, 0, 8);
    t18 = (t19 + 4);
    t20 = *((unsigned int *)t18);
    t21 = (~(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB14;

LAB12:    if (*((unsigned int *)t18) == 0)
        goto LAB11;

LAB13:    t25 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t25) = 1;

LAB14:    memset(t26, 0, 8);
    t27 = (t17 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t17);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t27) != 0)
        goto LAB17;

LAB18:    t35 = *((unsigned int *)t6);
    t36 = *((unsigned int *)t26);
    t37 = (t35 & t36);
    *((unsigned int *)t34) = t37;
    t38 = (t6 + 4);
    t39 = (t26 + 4);
    t40 = (t34 + 4);
    t41 = *((unsigned int *)t38);
    t42 = *((unsigned int *)t39);
    t43 = (t41 | t42);
    *((unsigned int *)t40) = t43;
    t44 = *((unsigned int *)t40);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB19;

LAB20:
LAB21:    goto LAB10;

LAB11:    *((unsigned int *)t17) = 1;
    goto LAB14;

LAB15:    *((unsigned int *)t26) = 1;
    goto LAB18;

LAB17:    t33 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB18;

LAB19:    t46 = *((unsigned int *)t34);
    t47 = *((unsigned int *)t40);
    *((unsigned int *)t34) = (t46 | t47);
    t48 = (t6 + 4);
    t49 = (t26 + 4);
    t50 = *((unsigned int *)t6);
    t51 = (~(t50));
    t52 = *((unsigned int *)t48);
    t53 = (~(t52));
    t54 = *((unsigned int *)t26);
    t55 = (~(t54));
    t56 = *((unsigned int *)t49);
    t57 = (~(t56));
    t58 = (t51 & t53);
    t59 = (t55 & t57);
    t60 = (~(t58));
    t61 = (~(t59));
    t62 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t62 & t60);
    t63 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t63 & t61);
    t64 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t64 & t60);
    t65 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t65 & t61);
    goto LAB21;

LAB22:    *((unsigned int *)t4) = 1;
    goto LAB25;

LAB24:    t72 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB25;

LAB26:    t77 = (t0 + 1208U);
    t78 = *((char **)t77);
    goto LAB27;

LAB28:    t77 = (t0 + 1368U);
    t86 = *((char **)t77);
    memset(t85, 0, 8);
    t77 = (t86 + 4);
    t87 = *((unsigned int *)t77);
    t88 = (~(t87));
    t89 = *((unsigned int *)t86);
    t90 = (t89 & t88);
    t91 = (t90 & 1U);
    if (t91 != 0)
        goto LAB38;

LAB36:    if (*((unsigned int *)t77) == 0)
        goto LAB35;

LAB37:    t92 = (t85 + 4);
    *((unsigned int *)t85) = 1;
    *((unsigned int *)t92) = 1;

LAB38:    memset(t93, 0, 8);
    t94 = (t85 + 4);
    t95 = *((unsigned int *)t94);
    t96 = (~(t95));
    t97 = *((unsigned int *)t85);
    t98 = (t97 & t96);
    t99 = (t98 & 1U);
    if (t99 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t94) != 0)
        goto LAB41;

LAB42:    t101 = (t93 + 4);
    t102 = *((unsigned int *)t93);
    t103 = *((unsigned int *)t101);
    t104 = (t102 || t103);
    if (t104 > 0)
        goto LAB43;

LAB44:    memcpy(t114, t93, 8);

LAB45:    memset(t84, 0, 8);
    t146 = (t114 + 4);
    t147 = *((unsigned int *)t146);
    t148 = (~(t147));
    t149 = *((unsigned int *)t114);
    t150 = (t149 & t148);
    t151 = (t150 & 1U);
    if (t151 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t146) != 0)
        goto LAB55;

LAB56:    t153 = (t84 + 4);
    t154 = *((unsigned int *)t84);
    t155 = *((unsigned int *)t153);
    t156 = (t154 || t155);
    if (t156 > 0)
        goto LAB57;

LAB58:    t158 = *((unsigned int *)t84);
    t159 = (~(t158));
    t160 = *((unsigned int *)t153);
    t161 = (t159 || t160);
    if (t161 > 0)
        goto LAB59;

LAB60:    if (*((unsigned int *)t153) > 0)
        goto LAB61;

LAB62:    if (*((unsigned int *)t84) > 0)
        goto LAB63;

LAB64:    memcpy(t83, t162, 8);

LAB65:    goto LAB29;

LAB30:    xsi_vlog_unsigned_bit_combine(t3, 1, t78, 1, t83, 1);
    goto LAB34;

LAB32:    memcpy(t3, t78, 8);
    goto LAB34;

LAB35:    *((unsigned int *)t85) = 1;
    goto LAB38;

LAB39:    *((unsigned int *)t93) = 1;
    goto LAB42;

LAB41:    t100 = (t93 + 4);
    *((unsigned int *)t93) = 1;
    *((unsigned int *)t100) = 1;
    goto LAB42;

LAB43:    t105 = (t0 + 1528U);
    t106 = *((char **)t105);
    memset(t107, 0, 8);
    t105 = (t106 + 4);
    t108 = *((unsigned int *)t105);
    t109 = (~(t108));
    t110 = *((unsigned int *)t106);
    t111 = (t110 & t109);
    t112 = (t111 & 1U);
    if (t112 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t105) != 0)
        goto LAB48;

LAB49:    t115 = *((unsigned int *)t93);
    t116 = *((unsigned int *)t107);
    t117 = (t115 & t116);
    *((unsigned int *)t114) = t117;
    t118 = (t93 + 4);
    t119 = (t107 + 4);
    t120 = (t114 + 4);
    t121 = *((unsigned int *)t118);
    t122 = *((unsigned int *)t119);
    t123 = (t121 | t122);
    *((unsigned int *)t120) = t123;
    t124 = *((unsigned int *)t120);
    t125 = (t124 != 0);
    if (t125 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB45;

LAB46:    *((unsigned int *)t107) = 1;
    goto LAB49;

LAB48:    t113 = (t107 + 4);
    *((unsigned int *)t107) = 1;
    *((unsigned int *)t113) = 1;
    goto LAB49;

LAB50:    t126 = *((unsigned int *)t114);
    t127 = *((unsigned int *)t120);
    *((unsigned int *)t114) = (t126 | t127);
    t128 = (t93 + 4);
    t129 = (t107 + 4);
    t130 = *((unsigned int *)t93);
    t131 = (~(t130));
    t132 = *((unsigned int *)t128);
    t133 = (~(t132));
    t134 = *((unsigned int *)t107);
    t135 = (~(t134));
    t136 = *((unsigned int *)t129);
    t137 = (~(t136));
    t138 = (t131 & t133);
    t139 = (t135 & t137);
    t140 = (~(t138));
    t141 = (~(t139));
    t142 = *((unsigned int *)t120);
    *((unsigned int *)t120) = (t142 & t140);
    t143 = *((unsigned int *)t120);
    *((unsigned int *)t120) = (t143 & t141);
    t144 = *((unsigned int *)t114);
    *((unsigned int *)t114) = (t144 & t140);
    t145 = *((unsigned int *)t114);
    *((unsigned int *)t114) = (t145 & t141);
    goto LAB52;

LAB53:    *((unsigned int *)t84) = 1;
    goto LAB56;

LAB55:    t152 = (t84 + 4);
    *((unsigned int *)t84) = 1;
    *((unsigned int *)t152) = 1;
    goto LAB56;

LAB57:    t157 = ((char*)((ng1)));
    goto LAB58;

LAB59:    t164 = (t0 + 1368U);
    t165 = *((char **)t164);
    memset(t166, 0, 8);
    t164 = (t165 + 4);
    t167 = *((unsigned int *)t164);
    t168 = (~(t167));
    t169 = *((unsigned int *)t165);
    t170 = (t169 & t168);
    t171 = (t170 & 1U);
    if (t171 != 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t164) != 0)
        goto LAB68;

LAB69:    t173 = (t166 + 4);
    t174 = *((unsigned int *)t166);
    t175 = *((unsigned int *)t173);
    t176 = (t174 || t175);
    if (t176 > 0)
        goto LAB70;

LAB71:    memcpy(t194, t166, 8);

LAB72:    memset(t163, 0, 8);
    t226 = (t194 + 4);
    t227 = *((unsigned int *)t226);
    t228 = (~(t227));
    t229 = *((unsigned int *)t194);
    t230 = (t229 & t228);
    t231 = (t230 & 1U);
    if (t231 != 0)
        goto LAB84;

LAB85:    if (*((unsigned int *)t226) != 0)
        goto LAB86;

LAB87:    t233 = (t163 + 4);
    t234 = *((unsigned int *)t163);
    t235 = *((unsigned int *)t233);
    t236 = (t234 || t235);
    if (t236 > 0)
        goto LAB88;

LAB89:    t238 = *((unsigned int *)t163);
    t239 = (~(t238));
    t240 = *((unsigned int *)t233);
    t241 = (t239 || t240);
    if (t241 > 0)
        goto LAB90;

LAB91:    if (*((unsigned int *)t233) > 0)
        goto LAB92;

LAB93:    if (*((unsigned int *)t163) > 0)
        goto LAB94;

LAB95:    memcpy(t162, t242, 8);

LAB96:    goto LAB60;

LAB61:    xsi_vlog_unsigned_bit_combine(t83, 1, t157, 1, t162, 1);
    goto LAB65;

LAB63:    memcpy(t83, t157, 8);
    goto LAB65;

LAB66:    *((unsigned int *)t166) = 1;
    goto LAB69;

LAB68:    t172 = (t166 + 4);
    *((unsigned int *)t166) = 1;
    *((unsigned int *)t172) = 1;
    goto LAB69;

LAB70:    t178 = (t0 + 1208U);
    t179 = *((char **)t178);
    memset(t177, 0, 8);
    t178 = (t179 + 4);
    t180 = *((unsigned int *)t178);
    t181 = (~(t180));
    t182 = *((unsigned int *)t179);
    t183 = (t182 & t181);
    t184 = (t183 & 1U);
    if (t184 != 0)
        goto LAB76;

LAB74:    if (*((unsigned int *)t178) == 0)
        goto LAB73;

LAB75:    t185 = (t177 + 4);
    *((unsigned int *)t177) = 1;
    *((unsigned int *)t185) = 1;

LAB76:    memset(t186, 0, 8);
    t187 = (t177 + 4);
    t188 = *((unsigned int *)t187);
    t189 = (~(t188));
    t190 = *((unsigned int *)t177);
    t191 = (t190 & t189);
    t192 = (t191 & 1U);
    if (t192 != 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t187) != 0)
        goto LAB79;

LAB80:    t195 = *((unsigned int *)t166);
    t196 = *((unsigned int *)t186);
    t197 = (t195 & t196);
    *((unsigned int *)t194) = t197;
    t198 = (t166 + 4);
    t199 = (t186 + 4);
    t200 = (t194 + 4);
    t201 = *((unsigned int *)t198);
    t202 = *((unsigned int *)t199);
    t203 = (t201 | t202);
    *((unsigned int *)t200) = t203;
    t204 = *((unsigned int *)t200);
    t205 = (t204 != 0);
    if (t205 == 1)
        goto LAB81;

LAB82:
LAB83:    goto LAB72;

LAB73:    *((unsigned int *)t177) = 1;
    goto LAB76;

LAB77:    *((unsigned int *)t186) = 1;
    goto LAB80;

LAB79:    t193 = (t186 + 4);
    *((unsigned int *)t186) = 1;
    *((unsigned int *)t193) = 1;
    goto LAB80;

LAB81:    t206 = *((unsigned int *)t194);
    t207 = *((unsigned int *)t200);
    *((unsigned int *)t194) = (t206 | t207);
    t208 = (t166 + 4);
    t209 = (t186 + 4);
    t210 = *((unsigned int *)t166);
    t211 = (~(t210));
    t212 = *((unsigned int *)t208);
    t213 = (~(t212));
    t214 = *((unsigned int *)t186);
    t215 = (~(t214));
    t216 = *((unsigned int *)t209);
    t217 = (~(t216));
    t218 = (t211 & t213);
    t219 = (t215 & t217);
    t220 = (~(t218));
    t221 = (~(t219));
    t222 = *((unsigned int *)t200);
    *((unsigned int *)t200) = (t222 & t220);
    t223 = *((unsigned int *)t200);
    *((unsigned int *)t200) = (t223 & t221);
    t224 = *((unsigned int *)t194);
    *((unsigned int *)t194) = (t224 & t220);
    t225 = *((unsigned int *)t194);
    *((unsigned int *)t194) = (t225 & t221);
    goto LAB83;

LAB84:    *((unsigned int *)t163) = 1;
    goto LAB87;

LAB86:    t232 = (t163 + 4);
    *((unsigned int *)t163) = 1;
    *((unsigned int *)t232) = 1;
    goto LAB87;

LAB88:    t237 = ((char*)((ng2)));
    goto LAB89;

LAB90:    t245 = (t0 + 1528U);
    t246 = *((char **)t245);
    memset(t244, 0, 8);
    t245 = (t246 + 4);
    t247 = *((unsigned int *)t245);
    t248 = (~(t247));
    t249 = *((unsigned int *)t246);
    t250 = (t249 & t248);
    t251 = (t250 & 1U);
    if (t251 != 0)
        goto LAB100;

LAB98:    if (*((unsigned int *)t245) == 0)
        goto LAB97;

LAB99:    t252 = (t244 + 4);
    *((unsigned int *)t244) = 1;
    *((unsigned int *)t252) = 1;

LAB100:    memset(t253, 0, 8);
    t254 = (t244 + 4);
    t255 = *((unsigned int *)t254);
    t256 = (~(t255));
    t257 = *((unsigned int *)t244);
    t258 = (t257 & t256);
    t259 = (t258 & 1U);
    if (t259 != 0)
        goto LAB101;

LAB102:    if (*((unsigned int *)t254) != 0)
        goto LAB103;

LAB104:    t261 = (t253 + 4);
    t262 = *((unsigned int *)t253);
    t263 = *((unsigned int *)t261);
    t264 = (t262 || t263);
    if (t264 > 0)
        goto LAB105;

LAB106:    memcpy(t274, t253, 8);

LAB107:    memset(t243, 0, 8);
    t306 = (t274 + 4);
    t307 = *((unsigned int *)t306);
    t308 = (~(t307));
    t309 = *((unsigned int *)t274);
    t310 = (t309 & t308);
    t311 = (t310 & 1U);
    if (t311 != 0)
        goto LAB115;

LAB116:    if (*((unsigned int *)t306) != 0)
        goto LAB117;

LAB118:    t313 = (t243 + 4);
    t314 = *((unsigned int *)t243);
    t315 = *((unsigned int *)t313);
    t316 = (t314 || t315);
    if (t316 > 0)
        goto LAB119;

LAB120:    t318 = *((unsigned int *)t243);
    t319 = (~(t318));
    t320 = *((unsigned int *)t313);
    t321 = (t319 || t320);
    if (t321 > 0)
        goto LAB121;

LAB122:    if (*((unsigned int *)t313) > 0)
        goto LAB123;

LAB124:    if (*((unsigned int *)t243) > 0)
        goto LAB125;

LAB126:    memcpy(t242, t322, 8);

LAB127:    goto LAB91;

LAB92:    xsi_vlog_unsigned_bit_combine(t162, 1, t237, 1, t242, 1);
    goto LAB96;

LAB94:    memcpy(t162, t237, 8);
    goto LAB96;

LAB97:    *((unsigned int *)t244) = 1;
    goto LAB100;

LAB101:    *((unsigned int *)t253) = 1;
    goto LAB104;

LAB103:    t260 = (t253 + 4);
    *((unsigned int *)t253) = 1;
    *((unsigned int *)t260) = 1;
    goto LAB104;

LAB105:    t265 = (t0 + 1208U);
    t266 = *((char **)t265);
    memset(t267, 0, 8);
    t265 = (t266 + 4);
    t268 = *((unsigned int *)t265);
    t269 = (~(t268));
    t270 = *((unsigned int *)t266);
    t271 = (t270 & t269);
    t272 = (t271 & 1U);
    if (t272 != 0)
        goto LAB108;

LAB109:    if (*((unsigned int *)t265) != 0)
        goto LAB110;

LAB111:    t275 = *((unsigned int *)t253);
    t276 = *((unsigned int *)t267);
    t277 = (t275 & t276);
    *((unsigned int *)t274) = t277;
    t278 = (t253 + 4);
    t279 = (t267 + 4);
    t280 = (t274 + 4);
    t281 = *((unsigned int *)t278);
    t282 = *((unsigned int *)t279);
    t283 = (t281 | t282);
    *((unsigned int *)t280) = t283;
    t284 = *((unsigned int *)t280);
    t285 = (t284 != 0);
    if (t285 == 1)
        goto LAB112;

LAB113:
LAB114:    goto LAB107;

LAB108:    *((unsigned int *)t267) = 1;
    goto LAB111;

LAB110:    t273 = (t267 + 4);
    *((unsigned int *)t267) = 1;
    *((unsigned int *)t273) = 1;
    goto LAB111;

LAB112:    t286 = *((unsigned int *)t274);
    t287 = *((unsigned int *)t280);
    *((unsigned int *)t274) = (t286 | t287);
    t288 = (t253 + 4);
    t289 = (t267 + 4);
    t290 = *((unsigned int *)t253);
    t291 = (~(t290));
    t292 = *((unsigned int *)t288);
    t293 = (~(t292));
    t294 = *((unsigned int *)t267);
    t295 = (~(t294));
    t296 = *((unsigned int *)t289);
    t297 = (~(t296));
    t298 = (t291 & t293);
    t299 = (t295 & t297);
    t300 = (~(t298));
    t301 = (~(t299));
    t302 = *((unsigned int *)t280);
    *((unsigned int *)t280) = (t302 & t300);
    t303 = *((unsigned int *)t280);
    *((unsigned int *)t280) = (t303 & t301);
    t304 = *((unsigned int *)t274);
    *((unsigned int *)t274) = (t304 & t300);
    t305 = *((unsigned int *)t274);
    *((unsigned int *)t274) = (t305 & t301);
    goto LAB114;

LAB115:    *((unsigned int *)t243) = 1;
    goto LAB118;

LAB117:    t312 = (t243 + 4);
    *((unsigned int *)t243) = 1;
    *((unsigned int *)t312) = 1;
    goto LAB118;

LAB119:    t317 = ((char*)((ng3)));
    goto LAB120;

LAB121:    t322 = ((char*)((ng4)));
    goto LAB122;

LAB123:    xsi_vlog_unsigned_bit_combine(t242, 1, t317, 1, t322, 1);
    goto LAB127;

LAB125:    memcpy(t242, t317, 8);
    goto LAB127;

}


extern void secureip_m_17186213605327609427_2192819093_init()
{
	static char *pe[] = {(void *)Cont_5323_0};
	xsi_register_didat("secureip_m_17186213605327609427_2192819093", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_17186213605327609427_2192819093.didat");
	xsi_register_executes(pe);
}
