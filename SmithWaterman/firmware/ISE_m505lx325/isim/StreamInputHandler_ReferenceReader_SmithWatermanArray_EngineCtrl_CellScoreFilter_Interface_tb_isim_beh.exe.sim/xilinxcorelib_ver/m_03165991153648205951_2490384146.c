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
static unsigned int ng0[] = {2147483649U, 0U};
static const char *ng1 = "%0s WARNING: Address %0h is outside range for A Write";
static int ng2[] = {1983340339, 0, 1734700639, 0, 1835363679, 0, 1651272543, 0};
static int ng3[] = {1, 0};
static int ng4[] = {0, 0};
static int ng5[] = {128, 0};
static int ng6[] = {9, 0};
static int ng7[] = {2, 0};
static int ng8[] = {3, 0};
static unsigned int ng9[] = {1U, 0U};
static int ng10[] = {135, 0};
static int ng11[] = {1952806966, 0, 7760242, 0};
static const char *ng12 = "%0s WARNING: Address %0h is outside range for B Write";
static const char *ng13 = "%0s WARNING: Address %0h is outside range for A Read";
static unsigned int ng14[] = {4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U};
static unsigned int ng15[] = {0U, 0U};
static const char *ng16 = "%0s WARNING: Address %0h is outside range for B Read";
static unsigned int ng17[] = {1U, 1U};
static unsigned int ng18[] = {4294967295U, 4294967295U};
static int ng19[] = {0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng20 = " Block Memory Generator CORE Generator module loading initial data...";
static int ng21[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng22 = "%0s ERROR: C_DEFAULT_DATA is empty!";
static const char *ng23 = "%h";
static const char *ng24 = "";
static int ng25[] = {539308147, 0, 1096040762, 0, 1280597828, 0, 1162232149, 0, 541286212, 0, 1718775661, 0, 1919246692, 0, 1835101216, 0, 1684366185, 0, 1751480417, 0, 1718971424, 0, 1667593075, 0, 1853060451, 0, 1379541077, 0, 1163022927, 0, 623932192, 0};
static int ng26[] = {48, 0};
static int ng27[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng28 = "%0s ERROR: C_INIT_FILE_NAME is empty!";
static const char *ng29 = "r";
static int ng30[] = {623932193, 0, 1296382496, 0, 1163873857, 0, 1598441804, 0, 1229867348, 0, 1852261215, 0, 1885695593, 0, 1701650543, 0, 1919902316, 0, 1379541072, 0, 1163022927, 0, 812854304, 0, 37, 0};
static const char *ng31 = "%b";
static const char *ng32 = " Block Memory Generator data initialization complete.";
static const char *ng33 = "Block Memory Generator CORE Generator module %m is using a behavioral model for simulation which will not precisely model memory collision behavior.";
static int ng34[] = {1952806967, 0, 7039342, 0};
static int ng35[] = {1952542262, 0, 1936744818, 0};
static int ng36[] = {17221, 0};
static int ng37[] = {21330, 0};
static int ng38[] = {1230132052, 0, 1094999878, 0, 21061, 0};
static const char *ng39 = "%0s collision detected at time: %0d, ";
static const char *ng40 = "A %0s address: %0h, B %0s address: %0h\n";
static int ng41[] = {1919513701, 0, 119, 0};
static int ng42[] = {1919246692, 0, 0, 0};



static int sp_write_a(char *t1, char *t2)
{
    char t10[8];
    char t18[8];
    char t39[32];
    char t43[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    char t70[8];
    char t118[8];
    char t124[8];
    char t154[8];
    char t155[8];
    char t172[8];
    char t179[40];
    char t184[32];
    char t185[16];
    char t202[8];
    char t210[8];
    char t240[8];
    char t256[8];
    char t272[8];
    char t280[8];
    char t310[8];
    char t318[8];
    char t352[8];
    char t353[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    unsigned int t13;
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
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t59;
    int t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    int t65;
    int t66;
    int t67;
    unsigned int t68;
    char *t69;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
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
    unsigned int t104;
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
    unsigned int t117;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    char *t156;
    char *t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    char *t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    char *t170;
    char *t171;
    char *t173;
    char *t174;
    char *t175;
    char *t176;
    char *t177;
    unsigned int t178;
    int t180;
    int t181;
    int t182;
    int t183;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    unsigned int t199;
    unsigned int t200;
    char *t201;
    char *t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    char *t214;
    char *t215;
    char *t216;
    unsigned int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    char *t224;
    char *t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    unsigned int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    unsigned int t237;
    unsigned int t238;
    unsigned int t239;
    char *t241;
    unsigned int t242;
    unsigned int t243;
    unsigned int t244;
    unsigned int t245;
    unsigned int t246;
    char *t247;
    char *t248;
    unsigned int t249;
    unsigned int t250;
    unsigned int t251;
    char *t252;
    char *t253;
    char *t254;
    char *t255;
    char *t257;
    char *t258;
    unsigned int t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    unsigned int t264;
    unsigned int t265;
    unsigned int t266;
    unsigned int t267;
    unsigned int t268;
    unsigned int t269;
    unsigned int t270;
    char *t271;
    char *t273;
    unsigned int t274;
    unsigned int t275;
    unsigned int t276;
    unsigned int t277;
    unsigned int t278;
    char *t279;
    unsigned int t281;
    unsigned int t282;
    unsigned int t283;
    char *t284;
    char *t285;
    char *t286;
    unsigned int t287;
    unsigned int t288;
    unsigned int t289;
    unsigned int t290;
    unsigned int t291;
    unsigned int t292;
    unsigned int t293;
    char *t294;
    char *t295;
    unsigned int t296;
    unsigned int t297;
    unsigned int t298;
    unsigned int t299;
    unsigned int t300;
    unsigned int t301;
    unsigned int t302;
    unsigned int t303;
    unsigned int t304;
    unsigned int t305;
    unsigned int t306;
    unsigned int t307;
    unsigned int t308;
    unsigned int t309;
    char *t311;
    unsigned int t312;
    unsigned int t313;
    unsigned int t314;
    unsigned int t315;
    unsigned int t316;
    char *t317;
    unsigned int t319;
    unsigned int t320;
    unsigned int t321;
    char *t322;
    char *t323;
    char *t324;
    unsigned int t325;
    unsigned int t326;
    unsigned int t327;
    unsigned int t328;
    unsigned int t329;
    unsigned int t330;
    unsigned int t331;
    char *t332;
    char *t333;
    unsigned int t334;
    unsigned int t335;
    unsigned int t336;
    unsigned int t337;
    unsigned int t338;
    unsigned int t339;
    unsigned int t340;
    unsigned int t341;
    unsigned int t342;
    unsigned int t343;
    char *t344;
    unsigned int t345;
    unsigned int t346;
    unsigned int t347;
    unsigned int t348;
    unsigned int t349;
    char *t350;
    char *t351;
    char *t354;
    char *t355;
    char *t356;
    char *t357;
    char *t358;
    char *t359;
    char *t360;
    char *t361;
    char *t362;
    char *t363;
    unsigned int t364;
    char *t365;
    unsigned int t366;
    int t367;
    unsigned int t368;
    unsigned int t369;
    int t370;
    int t371;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 12680);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 28048);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 9992);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    xsi_vlog_unsigned_divide(t10, 32, t7, 10, t9, 32);
    t8 = (t1 + 29008);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 10);
    t4 = (t1 + 29008);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3600);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB7;

LAB6:    t9 = (t8 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB7;

LAB10:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB9;

LAB8:    *((unsigned int *)t10) = 1;

LAB9:    t12 = (t10 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB11;

LAB12:
LAB23:    t4 = (t1 + 2920);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB24;

LAB25:
LAB58:    t4 = (t1 + 28368);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 28848);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 128);

LAB26:    t4 = (t1 + 7000);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB59;

LAB60:
LAB61:    t4 = (t1 + 6864);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB111;

LAB112:
LAB113:    t4 = (t1 + 9448);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB163;

LAB164:
LAB169:    t4 = ((char*)((ng4)));
    t5 = (t1 + 29168);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB170:    t4 = (t1 + 29168);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9448);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB171;

LAB172:
LAB165:    t4 = ((char*)((ng11)));
    t5 = ((char*)((ng11)));
    xsi_vlog_unsigned_equal(t185, 56, t4, 56, t5, 56);
    memset(t10, 0, 8);
    t6 = (t185 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t185);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB176;

LAB177:    if (*((unsigned int *)t6) != 0)
        goto LAB178;

LAB179:    t8 = (t10 + 4);
    t21 = *((unsigned int *)t10);
    t22 = *((unsigned int *)t8);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB180;

LAB181:    memcpy(t45, t10, 8);

LAB182:    t35 = (t45 + 4);
    t96 = *((unsigned int *)t35);
    t97 = (~(t96));
    t98 = *((unsigned int *)t45);
    t99 = (t98 & t97);
    t100 = (t99 != 0);
    if (t100 > 0)
        goto LAB190;

LAB191:
LAB192:    t4 = (t1 + 6864);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB312;

LAB313:
LAB314:
LAB13:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB7:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB9;

LAB11:
LAB14:    t19 = (t1 + 7816);
    t20 = *((char **)t19);
    memset(t18, 0, 8);
    t19 = (t20 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB18;

LAB16:    if (*((unsigned int *)t19) == 0)
        goto LAB15;

LAB17:    t26 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t26) = 1;

LAB18:    t27 = (t18 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t18);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB19;

LAB20:
LAB21:    goto LAB13;

LAB15:    *((unsigned int *)t18) = 1;
    goto LAB18;

LAB19:
LAB22:    t33 = ((char*)((ng0)));
    t34 = ((char*)((ng2)));
    t35 = (t1 + 28048);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 12680);
    xsi_vlogfile_fwrite(*((unsigned int *)t33), 1, 0, 0, ng1, 3, t38, (char)118, t34, 128, (char)118, t37, 10);
    goto LAB21;

LAB24:
LAB27:    t6 = (t1 + 9448);
    t7 = *((char **)t6);
    t6 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t7, 32, t6, 32);
    t8 = (t10 + 4);
    t21 = *((unsigned int *)t8);
    t22 = (~(t21));
    t23 = *((unsigned int *)t10);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB28;

LAB29:
LAB32:    t4 = ((char*)((ng4)));
    t5 = (t1 + 29168);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB33:    t4 = (t1 + 29168);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9448);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB34;

LAB35:
LAB30:    t4 = (t1 + 3056);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB39;

LAB40:
LAB47:    t4 = ((char*)((ng4)));
    t5 = (t1 + 29168);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB48:    t4 = (t1 + 29168);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3056);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB49;

LAB50:
LAB41:    goto LAB26;

LAB28:
LAB31:    t9 = (t1 + 23248);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 23248);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 23248);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 29008);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    xsi_vlog_generic_get_array_select_value(t39, 128, t12, t26, t34, 2, 1, t37, 10, 2);
    t38 = (t1 + 28848);
    xsi_vlogvar_assign_value(t38, t39, 0, 0, 128);
    goto LAB30;

LAB34:
LAB36:    t9 = (t1 + 23248);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 23248);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 23248);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 29008);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 9448);
    t40 = *((char **)t38);
    memset(t18, 0, 8);
    xsi_vlog_unsigned_multiply(t18, 32, t37, 10, t40, 32);
    t38 = (t1 + 29168);
    t41 = (t38 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_add(t43, 32, t18, 32, t42, 32);
    xsi_vlog_generic_get_array_select_value(t39, 128, t12, t26, t34, 2, 1, t43, 32, 2);
    t44 = (t1 + 28848);
    t48 = (t1 + 28848);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t1 + 8904);
    t52 = *((char **)t51);
    t51 = (t1 + 29168);
    t53 = (t51 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t52, 32, t54, 32);
    t56 = ((char*)((ng5)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t50)), 2, t55, 32, 1, t56, 32, 1, 1);
    t57 = (t45 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t46 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    t62 = (t47 + 4);
    t23 = *((unsigned int *)t62);
    t63 = (!(t23));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB37;

LAB38:    t4 = (t1 + 29168);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 29168);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB33;

LAB37:    t24 = *((unsigned int *)t47);
    t65 = (t24 + 0);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t46);
    t66 = (t25 - t28);
    t67 = (t66 + 1);
    xsi_vlogvar_assign_value(t44, t39, t65, *((unsigned int *)t46), t67);
    goto LAB38;

LAB39:
LAB42:    t7 = (t1 + 28208);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t18, 0, 8);
    t11 = (t18 + 4);
    t12 = (t9 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t18) = t23;
    t24 = *((unsigned int *)t12);
    t25 = (t24 >> 0);
    t28 = (t25 & 1);
    *((unsigned int *)t11) = t28;
    t19 = (t18 + 4);
    t29 = *((unsigned int *)t19);
    t30 = (~(t29));
    t31 = *((unsigned int *)t18);
    t32 = (t31 & t30);
    t68 = (t32 != 0);
    if (t68 > 0)
        goto LAB43;

LAB44:
LAB45:    goto LAB41;

LAB43:
LAB46:    t20 = (t1 + 28368);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    t33 = (t1 + 28848);
    xsi_vlogvar_assign_value(t33, t27, 0, 0, 128);
    goto LAB45;

LAB49:
LAB51:    t9 = (t1 + 28208);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 28208);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 29168);
    t33 = (t27 + 56U);
    t34 = *((char **)t33);
    xsi_vlog_generic_get_index_select_value(t18, 1, t12, t26, 2, t34, 32, 1);
    t35 = (t18 + 4);
    t21 = *((unsigned int *)t35);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB52;

LAB53:
LAB54:    t4 = (t1 + 29168);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 29168);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB48;

LAB52:
LAB55:    t36 = (t1 + 28368);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t40 = (t1 + 28368);
    t41 = (t40 + 72U);
    t42 = *((char **)t41);
    t44 = (t1 + 10536);
    t48 = *((char **)t44);
    t44 = (t1 + 29168);
    t49 = (t44 + 56U);
    t50 = *((char **)t49);
    memset(t45, 0, 8);
    xsi_vlog_signed_multiply(t45, 32, t48, 32, t50, 32);
    t51 = ((char*)((ng6)));
    xsi_vlog_get_indexed_partselect(t43, 9, t38, ((int*)(t42)), 2, t45, 32, 1, t51, 32, 1, 1);
    t52 = (t1 + 28848);
    t53 = (t1 + 28848);
    t54 = (t53 + 72U);
    t56 = *((char **)t54);
    t57 = (t1 + 10536);
    t59 = *((char **)t57);
    t57 = (t1 + 29168);
    t62 = (t57 + 56U);
    t69 = *((char **)t62);
    memset(t70, 0, 8);
    xsi_vlog_signed_multiply(t70, 32, t59, 32, t69, 32);
    t71 = ((char*)((ng6)));
    xsi_vlog_convert_indexed_partindices(t46, t47, t55, ((int*)(t56)), 2, t70, 32, 1, t71, 32, 1, 1);
    t72 = (t46 + 4);
    t28 = *((unsigned int *)t72);
    t58 = (!(t28));
    t73 = (t47 + 4);
    t29 = *((unsigned int *)t73);
    t60 = (!(t29));
    t61 = (t58 && t60);
    t74 = (t55 + 4);
    t30 = *((unsigned int *)t74);
    t63 = (!(t30));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB56;

LAB57:    goto LAB54;

LAB56:    t31 = *((unsigned int *)t55);
    t65 = (t31 + 0);
    t32 = *((unsigned int *)t46);
    t68 = *((unsigned int *)t47);
    t66 = (t32 - t68);
    t67 = (t66 + 1);
    xsi_vlogvar_assign_value(t52, t43, t65, *((unsigned int *)t47), t67);
    goto LAB57;

LAB59:
LAB62:    t7 = (t1 + 7136);
    t8 = *((char **)t7);
    t7 = ((char*)((ng7)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t8, 32, t7, 32);
    memset(t43, 0, 8);
    t9 = (t18 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t9) != 0)
        goto LAB65;

LAB66:    t12 = (t43 + 4);
    t28 = *((unsigned int *)t43);
    t29 = (!(t28));
    t30 = *((unsigned int *)t12);
    t31 = (t29 || t30);
    if (t31 > 0)
        goto LAB67;

LAB68:    memcpy(t47, t43, 8);

LAB69:    memset(t55, 0, 8);
    t38 = (t47 + 4);
    t98 = *((unsigned int *)t38);
    t99 = (~(t98));
    t100 = *((unsigned int *)t47);
    t101 = (t100 & t99);
    t102 = (t101 & 1U);
    if (t102 != 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t38) != 0)
        goto LAB79;

LAB80:    t41 = (t55 + 4);
    t103 = *((unsigned int *)t55);
    t104 = *((unsigned int *)t41);
    t105 = (t103 || t104);
    if (t105 > 0)
        goto LAB81;

LAB82:    memcpy(t124, t55, 8);

LAB83:    t71 = (t124 + 4);
    t149 = *((unsigned int *)t71);
    t150 = (~(t149));
    t151 = *((unsigned int *)t124);
    t152 = (t151 & t150);
    t153 = (t152 != 0);
    if (t153 > 0)
        goto LAB95;

LAB96:
LAB97:    goto LAB61;

LAB63:    *((unsigned int *)t43) = 1;
    goto LAB66;

LAB65:    t11 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB66;

LAB67:    t19 = (t1 + 7136);
    t20 = *((char **)t19);
    t19 = ((char*)((ng8)));
    memset(t45, 0, 8);
    xsi_vlog_signed_equal(t45, 32, t20, 32, t19, 32);
    memset(t46, 0, 8);
    t26 = (t45 + 4);
    t32 = *((unsigned int *)t26);
    t68 = (~(t32));
    t75 = *((unsigned int *)t45);
    t76 = (t75 & t68);
    t77 = (t76 & 1U);
    if (t77 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t26) != 0)
        goto LAB72;

LAB73:    t78 = *((unsigned int *)t43);
    t79 = *((unsigned int *)t46);
    t80 = (t78 | t79);
    *((unsigned int *)t47) = t80;
    t33 = (t43 + 4);
    t34 = (t46 + 4);
    t35 = (t47 + 4);
    t81 = *((unsigned int *)t33);
    t82 = *((unsigned int *)t34);
    t83 = (t81 | t82);
    *((unsigned int *)t35) = t83;
    t84 = *((unsigned int *)t35);
    t85 = (t84 != 0);
    if (t85 == 1)
        goto LAB74;

LAB75:
LAB76:    goto LAB69;

LAB70:    *((unsigned int *)t46) = 1;
    goto LAB73;

LAB72:    t27 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB73;

LAB74:    t86 = *((unsigned int *)t47);
    t87 = *((unsigned int *)t35);
    *((unsigned int *)t47) = (t86 | t87);
    t36 = (t43 + 4);
    t37 = (t46 + 4);
    t88 = *((unsigned int *)t36);
    t89 = (~(t88));
    t90 = *((unsigned int *)t43);
    t58 = (t90 & t89);
    t91 = *((unsigned int *)t37);
    t92 = (~(t91));
    t93 = *((unsigned int *)t46);
    t60 = (t93 & t92);
    t94 = (~(t58));
    t95 = (~(t60));
    t96 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t96 & t94);
    t97 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t97 & t95);
    goto LAB76;

LAB77:    *((unsigned int *)t55) = 1;
    goto LAB80;

LAB79:    t40 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB80;

LAB81:    t42 = (t1 + 28688);
    t44 = (t42 + 56U);
    t48 = *((char **)t44);
    t49 = ((char*)((ng9)));
    memset(t70, 0, 8);
    t50 = (t48 + 4);
    t51 = (t49 + 4);
    t106 = *((unsigned int *)t48);
    t107 = *((unsigned int *)t49);
    t108 = (t106 ^ t107);
    t109 = *((unsigned int *)t50);
    t110 = *((unsigned int *)t51);
    t111 = (t109 ^ t110);
    t112 = (t108 | t111);
    t113 = *((unsigned int *)t50);
    t114 = *((unsigned int *)t51);
    t115 = (t113 | t114);
    t116 = (~(t115));
    t117 = (t112 & t116);
    if (t117 != 0)
        goto LAB87;

LAB84:    if (t115 != 0)
        goto LAB86;

LAB85:    *((unsigned int *)t70) = 1;

LAB87:    memset(t118, 0, 8);
    t53 = (t70 + 4);
    t119 = *((unsigned int *)t53);
    t120 = (~(t119));
    t121 = *((unsigned int *)t70);
    t122 = (t121 & t120);
    t123 = (t122 & 1U);
    if (t123 != 0)
        goto LAB88;

LAB89:    if (*((unsigned int *)t53) != 0)
        goto LAB90;

LAB91:    t125 = *((unsigned int *)t55);
    t126 = *((unsigned int *)t118);
    t127 = (t125 & t126);
    *((unsigned int *)t124) = t127;
    t56 = (t55 + 4);
    t57 = (t118 + 4);
    t59 = (t124 + 4);
    t128 = *((unsigned int *)t56);
    t129 = *((unsigned int *)t57);
    t130 = (t128 | t129);
    *((unsigned int *)t59) = t130;
    t131 = *((unsigned int *)t59);
    t132 = (t131 != 0);
    if (t132 == 1)
        goto LAB92;

LAB93:
LAB94:    goto LAB83;

LAB86:    t52 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB87;

LAB88:    *((unsigned int *)t118) = 1;
    goto LAB91;

LAB90:    t54 = (t118 + 4);
    *((unsigned int *)t118) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB91;

LAB92:    t133 = *((unsigned int *)t124);
    t134 = *((unsigned int *)t59);
    *((unsigned int *)t124) = (t133 | t134);
    t62 = (t55 + 4);
    t69 = (t118 + 4);
    t135 = *((unsigned int *)t55);
    t136 = (~(t135));
    t137 = *((unsigned int *)t62);
    t138 = (~(t137));
    t139 = *((unsigned int *)t118);
    t140 = (~(t139));
    t141 = *((unsigned int *)t69);
    t142 = (~(t141));
    t61 = (t136 & t138);
    t63 = (t140 & t142);
    t143 = (~(t61));
    t144 = (~(t63));
    t145 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t145 & t143);
    t146 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t146 & t144);
    t147 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t147 & t143);
    t148 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t148 & t144);
    goto LAB94;

LAB95:
LAB98:    t72 = (t1 + 28848);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    memset(t155, 0, 8);
    t156 = (t155 + 4);
    t157 = (t74 + 4);
    t158 = *((unsigned int *)t74);
    t159 = (t158 >> 0);
    t160 = (t159 & 1);
    *((unsigned int *)t155) = t160;
    t161 = *((unsigned int *)t157);
    t162 = (t161 >> 0);
    t163 = (t162 & 1);
    *((unsigned int *)t156) = t163;
    memset(t154, 0, 8);
    t164 = (t155 + 4);
    t165 = *((unsigned int *)t164);
    t166 = (~(t165));
    t167 = *((unsigned int *)t155);
    t168 = (t167 & t166);
    t169 = (t168 & 1U);
    if (t169 != 0)
        goto LAB102;

LAB100:    if (*((unsigned int *)t164) == 0)
        goto LAB99;

LAB101:    t170 = (t154 + 4);
    *((unsigned int *)t154) = 1;
    *((unsigned int *)t170) = 1;

LAB102:    t171 = (t1 + 28848);
    t173 = (t1 + 28848);
    t174 = (t173 + 72U);
    t175 = *((char **)t174);
    t176 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t172, t175, 2, t176, 32, 1);
    t177 = (t172 + 4);
    t178 = *((unsigned int *)t177);
    t64 = (!(t178));
    if (t64 == 1)
        goto LAB103;

LAB104:    t4 = (t1 + 28848);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t18, 0, 8);
    t7 = (t18 + 4);
    t8 = (t6 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t18) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 1);
    t21 = (t17 & 1);
    *((unsigned int *)t7) = t21;
    memset(t10, 0, 8);
    t9 = (t18 + 4);
    t22 = *((unsigned int *)t9);
    t23 = (~(t22));
    t24 = *((unsigned int *)t18);
    t25 = (t24 & t23);
    t28 = (t25 & 1U);
    if (t28 != 0)
        goto LAB108;

LAB106:    if (*((unsigned int *)t9) == 0)
        goto LAB105;

LAB107:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;

LAB108:    t12 = (t1 + 28848);
    t19 = (t1 + 28848);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t43, t26, 2, t27, 32, 1);
    t33 = (t43 + 4);
    t29 = *((unsigned int *)t33);
    t58 = (!(t29));
    if (t58 == 1)
        goto LAB109;

LAB110:    goto LAB97;

LAB99:    *((unsigned int *)t154) = 1;
    goto LAB102;

LAB103:    xsi_vlogvar_assign_value(t171, t154, 0, *((unsigned int *)t172), 1);
    goto LAB104;

LAB105:    *((unsigned int *)t10) = 1;
    goto LAB108;

LAB109:    xsi_vlogvar_assign_value(t12, t10, 0, *((unsigned int *)t43), 1);
    goto LAB110;

LAB111:
LAB114:    t7 = (t1 + 7136);
    t8 = *((char **)t7);
    t7 = ((char*)((ng7)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t8, 32, t7, 32);
    memset(t43, 0, 8);
    t9 = (t18 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB115;

LAB116:    if (*((unsigned int *)t9) != 0)
        goto LAB117;

LAB118:    t12 = (t43 + 4);
    t28 = *((unsigned int *)t43);
    t29 = (!(t28));
    t30 = *((unsigned int *)t12);
    t31 = (t29 || t30);
    if (t31 > 0)
        goto LAB119;

LAB120:    memcpy(t47, t43, 8);

LAB121:    memset(t55, 0, 8);
    t38 = (t47 + 4);
    t98 = *((unsigned int *)t38);
    t99 = (~(t98));
    t100 = *((unsigned int *)t47);
    t101 = (t100 & t99);
    t102 = (t101 & 1U);
    if (t102 != 0)
        goto LAB129;

LAB130:    if (*((unsigned int *)t38) != 0)
        goto LAB131;

LAB132:    t41 = (t55 + 4);
    t103 = *((unsigned int *)t55);
    t104 = *((unsigned int *)t41);
    t105 = (t103 || t104);
    if (t105 > 0)
        goto LAB133;

LAB134:    memcpy(t124, t55, 8);

LAB135:    t71 = (t124 + 4);
    t149 = *((unsigned int *)t71);
    t150 = (~(t149));
    t151 = *((unsigned int *)t124);
    t152 = (t151 & t150);
    t153 = (t152 != 0);
    if (t153 > 0)
        goto LAB147;

LAB148:
LAB149:    goto LAB113;

LAB115:    *((unsigned int *)t43) = 1;
    goto LAB118;

LAB117:    t11 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB118;

LAB119:    t19 = (t1 + 7136);
    t20 = *((char **)t19);
    t19 = ((char*)((ng8)));
    memset(t45, 0, 8);
    xsi_vlog_signed_equal(t45, 32, t20, 32, t19, 32);
    memset(t46, 0, 8);
    t26 = (t45 + 4);
    t32 = *((unsigned int *)t26);
    t68 = (~(t32));
    t75 = *((unsigned int *)t45);
    t76 = (t75 & t68);
    t77 = (t76 & 1U);
    if (t77 != 0)
        goto LAB122;

LAB123:    if (*((unsigned int *)t26) != 0)
        goto LAB124;

LAB125:    t78 = *((unsigned int *)t43);
    t79 = *((unsigned int *)t46);
    t80 = (t78 | t79);
    *((unsigned int *)t47) = t80;
    t33 = (t43 + 4);
    t34 = (t46 + 4);
    t35 = (t47 + 4);
    t81 = *((unsigned int *)t33);
    t82 = *((unsigned int *)t34);
    t83 = (t81 | t82);
    *((unsigned int *)t35) = t83;
    t84 = *((unsigned int *)t35);
    t85 = (t84 != 0);
    if (t85 == 1)
        goto LAB126;

LAB127:
LAB128:    goto LAB121;

LAB122:    *((unsigned int *)t46) = 1;
    goto LAB125;

LAB124:    t27 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB125;

LAB126:    t86 = *((unsigned int *)t47);
    t87 = *((unsigned int *)t35);
    *((unsigned int *)t47) = (t86 | t87);
    t36 = (t43 + 4);
    t37 = (t46 + 4);
    t88 = *((unsigned int *)t36);
    t89 = (~(t88));
    t90 = *((unsigned int *)t43);
    t58 = (t90 & t89);
    t91 = *((unsigned int *)t37);
    t92 = (~(t91));
    t93 = *((unsigned int *)t46);
    t60 = (t93 & t92);
    t94 = (~(t58));
    t95 = (~(t60));
    t96 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t96 & t94);
    t97 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t97 & t95);
    goto LAB128;

LAB129:    *((unsigned int *)t55) = 1;
    goto LAB132;

LAB131:    t40 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB132;

LAB133:    t42 = (t1 + 28688);
    t44 = (t42 + 56U);
    t48 = *((char **)t44);
    t49 = ((char*)((ng9)));
    memset(t70, 0, 8);
    t50 = (t48 + 4);
    t51 = (t49 + 4);
    t106 = *((unsigned int *)t48);
    t107 = *((unsigned int *)t49);
    t108 = (t106 ^ t107);
    t109 = *((unsigned int *)t50);
    t110 = *((unsigned int *)t51);
    t111 = (t109 ^ t110);
    t112 = (t108 | t111);
    t113 = *((unsigned int *)t50);
    t114 = *((unsigned int *)t51);
    t115 = (t113 | t114);
    t116 = (~(t115));
    t117 = (t112 & t116);
    if (t117 != 0)
        goto LAB139;

LAB136:    if (t115 != 0)
        goto LAB138;

LAB137:    *((unsigned int *)t70) = 1;

LAB139:    memset(t118, 0, 8);
    t53 = (t70 + 4);
    t119 = *((unsigned int *)t53);
    t120 = (~(t119));
    t121 = *((unsigned int *)t70);
    t122 = (t121 & t120);
    t123 = (t122 & 1U);
    if (t123 != 0)
        goto LAB140;

LAB141:    if (*((unsigned int *)t53) != 0)
        goto LAB142;

LAB143:    t125 = *((unsigned int *)t55);
    t126 = *((unsigned int *)t118);
    t127 = (t125 & t126);
    *((unsigned int *)t124) = t127;
    t56 = (t55 + 4);
    t57 = (t118 + 4);
    t59 = (t124 + 4);
    t128 = *((unsigned int *)t56);
    t129 = *((unsigned int *)t57);
    t130 = (t128 | t129);
    *((unsigned int *)t59) = t130;
    t131 = *((unsigned int *)t59);
    t132 = (t131 != 0);
    if (t132 == 1)
        goto LAB144;

LAB145:
LAB146:    goto LAB135;

LAB138:    t52 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB139;

LAB140:    *((unsigned int *)t118) = 1;
    goto LAB143;

LAB142:    t54 = (t118 + 4);
    *((unsigned int *)t118) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB143;

LAB144:    t133 = *((unsigned int *)t124);
    t134 = *((unsigned int *)t59);
    *((unsigned int *)t124) = (t133 | t134);
    t62 = (t55 + 4);
    t69 = (t118 + 4);
    t135 = *((unsigned int *)t55);
    t136 = (~(t135));
    t137 = *((unsigned int *)t62);
    t138 = (~(t137));
    t139 = *((unsigned int *)t118);
    t140 = (~(t139));
    t141 = *((unsigned int *)t69);
    t142 = (~(t141));
    t61 = (t136 & t138);
    t63 = (t140 & t142);
    t143 = (~(t61));
    t144 = (~(t63));
    t145 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t145 & t143);
    t146 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t146 & t144);
    t147 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t147 & t143);
    t148 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t148 & t144);
    goto LAB146;

LAB147:
LAB150:    t72 = (t1 + 23408);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    xsi_vlog_get_part_select_value(t179, 134, t74, 133, 0);
    t156 = (t1 + 23408);
    t157 = (t1 + 23408);
    t164 = (t157 + 72U);
    t170 = *((char **)t164);
    t171 = ((char*)((ng10)));
    t173 = ((char*)((ng7)));
    xsi_vlog_convert_partindices(t154, t155, t172, ((int*)(t170)), 2, t171, 32, 1, t173, 32, 1);
    t174 = (t154 + 4);
    t158 = *((unsigned int *)t174);
    t64 = (!(t158));
    t175 = (t155 + 4);
    t159 = *((unsigned int *)t175);
    t65 = (!(t159));
    t66 = (t64 && t65);
    t176 = (t172 + 4);
    t160 = *((unsigned int *)t176);
    t67 = (!(t160));
    t180 = (t66 && t67);
    if (t180 == 1)
        goto LAB151;

LAB152:    t4 = (t1 + 23408);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t10, 0, 8);
    t7 = (t10 + 4);
    t8 = (t6 + 32);
    t9 = (t6 + 36);
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 7);
    t15 = (t14 & 1);
    *((unsigned int *)t10) = t15;
    t16 = *((unsigned int *)t9);
    t17 = (t16 >> 7);
    t21 = (t17 & 1);
    *((unsigned int *)t7) = t21;
    t11 = (t1 + 23408);
    t12 = (t1 + 23408);
    t19 = (t12 + 72U);
    t20 = *((char **)t19);
    t26 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t18, t20, 2, t26, 32, 1);
    t27 = (t18 + 4);
    t22 = *((unsigned int *)t27);
    t58 = (!(t22));
    if (t58 == 1)
        goto LAB153;

LAB154:    t4 = (t1 + 23408);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t10, 0, 8);
    t7 = (t10 + 4);
    t8 = (t6 + 32);
    t9 = (t6 + 36);
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 6);
    t15 = (t14 & 1);
    *((unsigned int *)t10) = t15;
    t16 = *((unsigned int *)t9);
    t17 = (t16 >> 6);
    t21 = (t17 & 1);
    *((unsigned int *)t7) = t21;
    t11 = (t1 + 23408);
    t12 = (t1 + 23408);
    t19 = (t12 + 72U);
    t20 = *((char **)t19);
    t26 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t18, t20, 2, t26, 32, 1);
    t27 = (t18 + 4);
    t22 = *((unsigned int *)t27);
    t58 = (!(t22));
    if (t58 == 1)
        goto LAB155;

LAB156:    t4 = (t1 + 28848);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 23408);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_get_part_select_value(t39, 128, t9, 127, 0);
    t13 = 0;

LAB160:    t14 = (t13 < 4);
    if (t14 == 1)
        goto LAB161;

LAB162:    t33 = (t1 + 28848);
    xsi_vlogvar_assign_value(t33, t184, 0, 0, 128);
    goto LAB149;

LAB151:    t161 = *((unsigned int *)t172);
    t181 = (t161 + 0);
    t162 = *((unsigned int *)t154);
    t163 = *((unsigned int *)t155);
    t182 = (t162 - t163);
    t183 = (t182 + 1);
    xsi_vlogvar_assign_value(t156, t179, t181, *((unsigned int *)t155), t183);
    goto LAB152;

LAB153:    xsi_vlogvar_assign_value(t11, t10, 0, *((unsigned int *)t18), 1);
    goto LAB154;

LAB155:    xsi_vlogvar_assign_value(t11, t10, 0, *((unsigned int *)t18), 1);
    goto LAB156;

LAB157:    t68 = *((unsigned int *)t19);
    t75 = *((unsigned int *)t27);
    *((unsigned int *)t19) = (t68 | t75);

LAB159:    t13 = (t13 + 1);
    goto LAB160;

LAB158:    goto LAB159;

LAB161:    t15 = (t13 * 8);
    t11 = (t6 + t15);
    t12 = (t39 + t15);
    t19 = (t184 + t15);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t21 = (t16 ^ t17);
    *((unsigned int *)t19) = t21;
    t22 = (t13 * 8);
    t23 = (t22 + 4);
    t20 = (t6 + t23);
    t24 = (t22 + 4);
    t26 = (t39 + t24);
    t25 = (t22 + 4);
    t27 = (t184 + t25);
    t28 = *((unsigned int *)t20);
    t29 = *((unsigned int *)t26);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = *((unsigned int *)t27);
    t32 = (t31 != 0);
    if (t32 == 1)
        goto LAB157;
    else
        goto LAB158;

LAB163:
LAB166:    t7 = (t1 + 28848);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t11 = (t1 + 23248);
    t12 = (t1 + 23248);
    t19 = (t12 + 72U);
    t20 = *((char **)t19);
    t26 = (t1 + 23248);
    t27 = (t26 + 64U);
    t33 = *((char **)t27);
    t34 = (t1 + 29008);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    t37 = (t1 + 9448);
    t38 = *((char **)t37);
    memset(t45, 0, 8);
    xsi_vlog_unsigned_multiply(t45, 32, t36, 10, t38, 32);
    xsi_vlog_generic_convert_array_indices(t18, t43, t20, t33, 2, 1, t45, 32, 2);
    t37 = (t18 + 4);
    t21 = *((unsigned int *)t37);
    t58 = (!(t21));
    t40 = (t43 + 4);
    t22 = *((unsigned int *)t40);
    t60 = (!(t22));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB167;

LAB168:    goto LAB165;

LAB167:    t23 = *((unsigned int *)t18);
    t24 = *((unsigned int *)t43);
    t63 = (t23 - t24);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t11, t9, 0, *((unsigned int *)t43), t64);
    goto LAB168;

LAB171:
LAB173:    t9 = (t1 + 28848);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 28848);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 8904);
    t33 = *((char **)t27);
    t27 = (t1 + 29168);
    t34 = (t27 + 56U);
    t35 = *((char **)t34);
    memset(t18, 0, 8);
    xsi_vlog_signed_multiply(t18, 32, t33, 32, t35, 32);
    t36 = ((char*)((ng5)));
    xsi_vlog_get_indexed_partselect(t39, 128, t12, ((int*)(t26)), 2, t18, 32, 1, t36, 32, 1, 1);
    t37 = (t1 + 23248);
    t38 = (t1 + 23248);
    t40 = (t38 + 72U);
    t41 = *((char **)t40);
    t42 = (t1 + 23248);
    t44 = (t42 + 64U);
    t48 = *((char **)t44);
    t49 = (t1 + 29008);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    t52 = (t1 + 9448);
    t53 = *((char **)t52);
    memset(t46, 0, 8);
    xsi_vlog_unsigned_multiply(t46, 32, t51, 10, t53, 32);
    t52 = (t1 + 29168);
    t54 = (t52 + 56U);
    t56 = *((char **)t54);
    memset(t47, 0, 8);
    xsi_vlog_unsigned_add(t47, 32, t46, 32, t56, 32);
    xsi_vlog_generic_convert_array_indices(t43, t45, t41, t48, 2, 1, t47, 32, 2);
    t57 = (t43 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t45 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB174;

LAB175:    t4 = (t1 + 29168);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 29168);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB170;

LAB174:    t23 = *((unsigned int *)t43);
    t24 = *((unsigned int *)t45);
    t63 = (t23 - t24);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t37, t39, 0, *((unsigned int *)t45), t64);
    goto LAB175;

LAB176:    *((unsigned int *)t10) = 1;
    goto LAB179;

LAB178:    t7 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB179;

LAB180:    t9 = (t1 + 7000);
    t11 = *((char **)t9);
    t9 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t11, 32, t9, 32);
    memset(t43, 0, 8);
    t12 = (t18 + 4);
    t24 = *((unsigned int *)t12);
    t25 = (~(t24));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t25);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB183;

LAB184:    if (*((unsigned int *)t12) != 0)
        goto LAB185;

LAB186:    t31 = *((unsigned int *)t10);
    t32 = *((unsigned int *)t43);
    t68 = (t31 & t32);
    *((unsigned int *)t45) = t68;
    t20 = (t10 + 4);
    t26 = (t43 + 4);
    t27 = (t45 + 4);
    t75 = *((unsigned int *)t20);
    t76 = *((unsigned int *)t26);
    t77 = (t75 | t76);
    *((unsigned int *)t27) = t77;
    t78 = *((unsigned int *)t27);
    t79 = (t78 != 0);
    if (t79 == 1)
        goto LAB187;

LAB188:
LAB189:    goto LAB182;

LAB183:    *((unsigned int *)t43) = 1;
    goto LAB186;

LAB185:    t19 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB186;

LAB187:    t80 = *((unsigned int *)t45);
    t81 = *((unsigned int *)t27);
    *((unsigned int *)t45) = (t80 | t81);
    t33 = (t10 + 4);
    t34 = (t43 + 4);
    t82 = *((unsigned int *)t10);
    t83 = (~(t82));
    t84 = *((unsigned int *)t33);
    t85 = (~(t84));
    t86 = *((unsigned int *)t43);
    t87 = (~(t86));
    t88 = *((unsigned int *)t34);
    t89 = (~(t88));
    t58 = (t83 & t85);
    t60 = (t87 & t89);
    t90 = (~(t58));
    t91 = (~(t60));
    t92 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t92 & t90);
    t93 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t93 & t91);
    t94 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t94 & t90);
    t95 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t95 & t91);
    goto LAB189;

LAB190:
LAB193:    t36 = (t1 + 7136);
    t37 = *((char **)t36);
    t36 = ((char*)((ng3)));
    memset(t46, 0, 8);
    xsi_vlog_signed_equal(t46, 32, t37, 32, t36, 32);
    memset(t47, 0, 8);
    t38 = (t46 + 4);
    t101 = *((unsigned int *)t38);
    t102 = (~(t101));
    t103 = *((unsigned int *)t46);
    t104 = (t103 & t102);
    t105 = (t104 & 1U);
    if (t105 != 0)
        goto LAB194;

LAB195:    if (*((unsigned int *)t38) != 0)
        goto LAB196;

LAB197:    t41 = (t47 + 4);
    t106 = *((unsigned int *)t47);
    t107 = *((unsigned int *)t41);
    t108 = (t106 || t107);
    if (t108 > 0)
        goto LAB198;

LAB199:    memcpy(t118, t47, 8);

LAB200:    memset(t124, 0, 8);
    t71 = (t118 + 4);
    t152 = *((unsigned int *)t71);
    t153 = (~(t152));
    t158 = *((unsigned int *)t118);
    t159 = (t158 & t153);
    t160 = (t159 & 1U);
    if (t160 != 0)
        goto LAB212;

LAB213:    if (*((unsigned int *)t71) != 0)
        goto LAB214;

LAB215:    t73 = (t124 + 4);
    t161 = *((unsigned int *)t124);
    t162 = (!(t161));
    t163 = *((unsigned int *)t73);
    t165 = (t162 || t163);
    if (t165 > 0)
        goto LAB216;

LAB217:    memcpy(t318, t124, 8);

LAB218:    t344 = (t318 + 4);
    t345 = *((unsigned int *)t344);
    t346 = (~(t345));
    t347 = *((unsigned int *)t318);
    t348 = (t347 & t346);
    t349 = (t348 != 0);
    if (t349 > 0)
        goto LAB262;

LAB263:
LAB268:    t4 = ((char*)((ng4)));
    t5 = (t1 + 23568);
    t6 = (t1 + 23568);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t1 + 23568);
    t11 = (t9 + 64U);
    t12 = *((char **)t11);
    t19 = (t1 + 28048);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t10, t18, t8, t12, 2, 1, t26, 10, 2);
    t27 = (t10 + 4);
    t13 = *((unsigned int *)t27);
    t58 = (!(t13));
    t33 = (t18 + 4);
    t14 = *((unsigned int *)t33);
    t60 = (!(t14));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB269;

LAB270:
LAB264:    t4 = (t1 + 7136);
    t5 = *((char **)t4);
    t4 = ((char*)((ng7)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    memset(t18, 0, 8);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB271;

LAB272:    if (*((unsigned int *)t6) != 0)
        goto LAB273;

LAB274:    t8 = (t18 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (!(t21));
    t23 = *((unsigned int *)t8);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB275;

LAB276:    memcpy(t46, t18, 8);

LAB277:    memset(t47, 0, 8);
    t35 = (t46 + 4);
    t93 = *((unsigned int *)t35);
    t94 = (~(t93));
    t95 = *((unsigned int *)t46);
    t96 = (t95 & t94);
    t97 = (t96 & 1U);
    if (t97 != 0)
        goto LAB285;

LAB286:    if (*((unsigned int *)t35) != 0)
        goto LAB287;

LAB288:    t37 = (t47 + 4);
    t98 = *((unsigned int *)t47);
    t99 = *((unsigned int *)t37);
    t100 = (t98 || t99);
    if (t100 > 0)
        goto LAB289;

LAB290:    memcpy(t118, t47, 8);

LAB291:    t59 = (t118 + 4);
    t144 = *((unsigned int *)t59);
    t145 = (~(t144));
    t146 = *((unsigned int *)t118);
    t147 = (t146 & t145);
    t148 = (t147 != 0);
    if (t148 > 0)
        goto LAB303;

LAB304:
LAB309:    t4 = ((char*)((ng4)));
    t5 = (t1 + 23728);
    t6 = (t1 + 23728);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t1 + 23728);
    t11 = (t9 + 64U);
    t12 = *((char **)t11);
    t19 = (t1 + 28048);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t10, t18, t8, t12, 2, 1, t26, 10, 2);
    t27 = (t10 + 4);
    t13 = *((unsigned int *)t27);
    t58 = (!(t13));
    t33 = (t18 + 4);
    t14 = *((unsigned int *)t33);
    t60 = (!(t14));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB310;

LAB311:
LAB305:    goto LAB192;

LAB194:    *((unsigned int *)t47) = 1;
    goto LAB197;

LAB196:    t40 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB197;

LAB198:    t42 = (t1 + 28528);
    t44 = (t42 + 56U);
    t48 = *((char **)t44);
    t49 = ((char*)((ng9)));
    memset(t55, 0, 8);
    t50 = (t48 + 4);
    t51 = (t49 + 4);
    t109 = *((unsigned int *)t48);
    t110 = *((unsigned int *)t49);
    t111 = (t109 ^ t110);
    t112 = *((unsigned int *)t50);
    t113 = *((unsigned int *)t51);
    t114 = (t112 ^ t113);
    t115 = (t111 | t114);
    t116 = *((unsigned int *)t50);
    t117 = *((unsigned int *)t51);
    t119 = (t116 | t117);
    t120 = (~(t119));
    t121 = (t115 & t120);
    if (t121 != 0)
        goto LAB204;

LAB201:    if (t119 != 0)
        goto LAB203;

LAB202:    *((unsigned int *)t55) = 1;

LAB204:    memset(t70, 0, 8);
    t53 = (t55 + 4);
    t122 = *((unsigned int *)t53);
    t123 = (~(t122));
    t125 = *((unsigned int *)t55);
    t126 = (t125 & t123);
    t127 = (t126 & 1U);
    if (t127 != 0)
        goto LAB205;

LAB206:    if (*((unsigned int *)t53) != 0)
        goto LAB207;

LAB208:    t128 = *((unsigned int *)t47);
    t129 = *((unsigned int *)t70);
    t130 = (t128 & t129);
    *((unsigned int *)t118) = t130;
    t56 = (t47 + 4);
    t57 = (t70 + 4);
    t59 = (t118 + 4);
    t131 = *((unsigned int *)t56);
    t132 = *((unsigned int *)t57);
    t133 = (t131 | t132);
    *((unsigned int *)t59) = t133;
    t134 = *((unsigned int *)t59);
    t135 = (t134 != 0);
    if (t135 == 1)
        goto LAB209;

LAB210:
LAB211:    goto LAB200;

LAB203:    t52 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB204;

LAB205:    *((unsigned int *)t70) = 1;
    goto LAB208;

LAB207:    t54 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB208;

LAB209:    t136 = *((unsigned int *)t118);
    t137 = *((unsigned int *)t59);
    *((unsigned int *)t118) = (t136 | t137);
    t62 = (t47 + 4);
    t69 = (t70 + 4);
    t138 = *((unsigned int *)t47);
    t139 = (~(t138));
    t140 = *((unsigned int *)t62);
    t141 = (~(t140));
    t142 = *((unsigned int *)t70);
    t143 = (~(t142));
    t144 = *((unsigned int *)t69);
    t145 = (~(t144));
    t61 = (t139 & t141);
    t63 = (t143 & t145);
    t146 = (~(t61));
    t147 = (~(t63));
    t148 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t148 & t146);
    t149 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t149 & t147);
    t150 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t150 & t146);
    t151 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t151 & t147);
    goto LAB211;

LAB212:    *((unsigned int *)t124) = 1;
    goto LAB215;

LAB214:    t72 = (t124 + 4);
    *((unsigned int *)t124) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB215;

LAB216:    t74 = (t1 + 7136);
    t156 = *((char **)t74);
    t74 = ((char*)((ng8)));
    memset(t154, 0, 8);
    xsi_vlog_signed_equal(t154, 32, t156, 32, t74, 32);
    memset(t155, 0, 8);
    t157 = (t154 + 4);
    t166 = *((unsigned int *)t157);
    t167 = (~(t166));
    t168 = *((unsigned int *)t154);
    t169 = (t168 & t167);
    t178 = (t169 & 1U);
    if (t178 != 0)
        goto LAB219;

LAB220:    if (*((unsigned int *)t157) != 0)
        goto LAB221;

LAB222:    t170 = (t155 + 4);
    t186 = *((unsigned int *)t155);
    t187 = *((unsigned int *)t170);
    t188 = (t186 || t187);
    if (t188 > 0)
        goto LAB223;

LAB224:    memcpy(t210, t155, 8);

LAB225:    memset(t240, 0, 8);
    t241 = (t210 + 4);
    t242 = *((unsigned int *)t241);
    t243 = (~(t242));
    t244 = *((unsigned int *)t210);
    t245 = (t244 & t243);
    t246 = (t245 & 1U);
    if (t246 != 0)
        goto LAB237;

LAB238:    if (*((unsigned int *)t241) != 0)
        goto LAB239;

LAB240:    t248 = (t240 + 4);
    t249 = *((unsigned int *)t240);
    t250 = *((unsigned int *)t248);
    t251 = (t249 || t250);
    if (t251 > 0)
        goto LAB241;

LAB242:    memcpy(t280, t240, 8);

LAB243:    memset(t310, 0, 8);
    t311 = (t280 + 4);
    t312 = *((unsigned int *)t311);
    t313 = (~(t312));
    t314 = *((unsigned int *)t280);
    t315 = (t314 & t313);
    t316 = (t315 & 1U);
    if (t316 != 0)
        goto LAB255;

LAB256:    if (*((unsigned int *)t311) != 0)
        goto LAB257;

LAB258:    t319 = *((unsigned int *)t124);
    t320 = *((unsigned int *)t310);
    t321 = (t319 | t320);
    *((unsigned int *)t318) = t321;
    t322 = (t124 + 4);
    t323 = (t310 + 4);
    t324 = (t318 + 4);
    t325 = *((unsigned int *)t322);
    t326 = *((unsigned int *)t323);
    t327 = (t325 | t326);
    *((unsigned int *)t324) = t327;
    t328 = *((unsigned int *)t324);
    t329 = (t328 != 0);
    if (t329 == 1)
        goto LAB259;

LAB260:
LAB261:    goto LAB218;

LAB219:    *((unsigned int *)t155) = 1;
    goto LAB222;

LAB221:    t164 = (t155 + 4);
    *((unsigned int *)t155) = 1;
    *((unsigned int *)t164) = 1;
    goto LAB222;

LAB223:    t171 = (t1 + 28528);
    t173 = (t171 + 56U);
    t174 = *((char **)t173);
    t175 = ((char*)((ng9)));
    memset(t172, 0, 8);
    t176 = (t174 + 4);
    t177 = (t175 + 4);
    t189 = *((unsigned int *)t174);
    t190 = *((unsigned int *)t175);
    t191 = (t189 ^ t190);
    t192 = *((unsigned int *)t176);
    t193 = *((unsigned int *)t177);
    t194 = (t192 ^ t193);
    t195 = (t191 | t194);
    t196 = *((unsigned int *)t176);
    t197 = *((unsigned int *)t177);
    t198 = (t196 | t197);
    t199 = (~(t198));
    t200 = (t195 & t199);
    if (t200 != 0)
        goto LAB229;

LAB226:    if (t198 != 0)
        goto LAB228;

LAB227:    *((unsigned int *)t172) = 1;

LAB229:    memset(t202, 0, 8);
    t203 = (t172 + 4);
    t204 = *((unsigned int *)t203);
    t205 = (~(t204));
    t206 = *((unsigned int *)t172);
    t207 = (t206 & t205);
    t208 = (t207 & 1U);
    if (t208 != 0)
        goto LAB230;

LAB231:    if (*((unsigned int *)t203) != 0)
        goto LAB232;

LAB233:    t211 = *((unsigned int *)t155);
    t212 = *((unsigned int *)t202);
    t213 = (t211 & t212);
    *((unsigned int *)t210) = t213;
    t214 = (t155 + 4);
    t215 = (t202 + 4);
    t216 = (t210 + 4);
    t217 = *((unsigned int *)t214);
    t218 = *((unsigned int *)t215);
    t219 = (t217 | t218);
    *((unsigned int *)t216) = t219;
    t220 = *((unsigned int *)t216);
    t221 = (t220 != 0);
    if (t221 == 1)
        goto LAB234;

LAB235:
LAB236:    goto LAB225;

LAB228:    t201 = (t172 + 4);
    *((unsigned int *)t172) = 1;
    *((unsigned int *)t201) = 1;
    goto LAB229;

LAB230:    *((unsigned int *)t202) = 1;
    goto LAB233;

LAB232:    t209 = (t202 + 4);
    *((unsigned int *)t202) = 1;
    *((unsigned int *)t209) = 1;
    goto LAB233;

LAB234:    t222 = *((unsigned int *)t210);
    t223 = *((unsigned int *)t216);
    *((unsigned int *)t210) = (t222 | t223);
    t224 = (t155 + 4);
    t225 = (t202 + 4);
    t226 = *((unsigned int *)t155);
    t227 = (~(t226));
    t228 = *((unsigned int *)t224);
    t229 = (~(t228));
    t230 = *((unsigned int *)t202);
    t231 = (~(t230));
    t232 = *((unsigned int *)t225);
    t233 = (~(t232));
    t64 = (t227 & t229);
    t65 = (t231 & t233);
    t234 = (~(t64));
    t235 = (~(t65));
    t236 = *((unsigned int *)t216);
    *((unsigned int *)t216) = (t236 & t234);
    t237 = *((unsigned int *)t216);
    *((unsigned int *)t216) = (t237 & t235);
    t238 = *((unsigned int *)t210);
    *((unsigned int *)t210) = (t238 & t234);
    t239 = *((unsigned int *)t210);
    *((unsigned int *)t210) = (t239 & t235);
    goto LAB236;

LAB237:    *((unsigned int *)t240) = 1;
    goto LAB240;

LAB239:    t247 = (t240 + 4);
    *((unsigned int *)t240) = 1;
    *((unsigned int *)t247) = 1;
    goto LAB240;

LAB241:    t252 = (t1 + 28688);
    t253 = (t252 + 56U);
    t254 = *((char **)t253);
    t255 = ((char*)((ng9)));
    memset(t256, 0, 8);
    t257 = (t254 + 4);
    t258 = (t255 + 4);
    t259 = *((unsigned int *)t254);
    t260 = *((unsigned int *)t255);
    t261 = (t259 ^ t260);
    t262 = *((unsigned int *)t257);
    t263 = *((unsigned int *)t258);
    t264 = (t262 ^ t263);
    t265 = (t261 | t264);
    t266 = *((unsigned int *)t257);
    t267 = *((unsigned int *)t258);
    t268 = (t266 | t267);
    t269 = (~(t268));
    t270 = (t265 & t269);
    if (t270 != 0)
        goto LAB245;

LAB244:    if (t268 != 0)
        goto LAB246;

LAB247:    memset(t272, 0, 8);
    t273 = (t256 + 4);
    t274 = *((unsigned int *)t273);
    t275 = (~(t274));
    t276 = *((unsigned int *)t256);
    t277 = (t276 & t275);
    t278 = (t277 & 1U);
    if (t278 != 0)
        goto LAB248;

LAB249:    if (*((unsigned int *)t273) != 0)
        goto LAB250;

LAB251:    t281 = *((unsigned int *)t240);
    t282 = *((unsigned int *)t272);
    t283 = (t281 & t282);
    *((unsigned int *)t280) = t283;
    t284 = (t240 + 4);
    t285 = (t272 + 4);
    t286 = (t280 + 4);
    t287 = *((unsigned int *)t284);
    t288 = *((unsigned int *)t285);
    t289 = (t287 | t288);
    *((unsigned int *)t286) = t289;
    t290 = *((unsigned int *)t286);
    t291 = (t290 != 0);
    if (t291 == 1)
        goto LAB252;

LAB253:
LAB254:    goto LAB243;

LAB245:    *((unsigned int *)t256) = 1;
    goto LAB247;

LAB246:    t271 = (t256 + 4);
    *((unsigned int *)t256) = 1;
    *((unsigned int *)t271) = 1;
    goto LAB247;

LAB248:    *((unsigned int *)t272) = 1;
    goto LAB251;

LAB250:    t279 = (t272 + 4);
    *((unsigned int *)t272) = 1;
    *((unsigned int *)t279) = 1;
    goto LAB251;

LAB252:    t292 = *((unsigned int *)t280);
    t293 = *((unsigned int *)t286);
    *((unsigned int *)t280) = (t292 | t293);
    t294 = (t240 + 4);
    t295 = (t272 + 4);
    t296 = *((unsigned int *)t240);
    t297 = (~(t296));
    t298 = *((unsigned int *)t294);
    t299 = (~(t298));
    t300 = *((unsigned int *)t272);
    t301 = (~(t300));
    t302 = *((unsigned int *)t295);
    t303 = (~(t302));
    t66 = (t297 & t299);
    t67 = (t301 & t303);
    t304 = (~(t66));
    t305 = (~(t67));
    t306 = *((unsigned int *)t286);
    *((unsigned int *)t286) = (t306 & t304);
    t307 = *((unsigned int *)t286);
    *((unsigned int *)t286) = (t307 & t305);
    t308 = *((unsigned int *)t280);
    *((unsigned int *)t280) = (t308 & t304);
    t309 = *((unsigned int *)t280);
    *((unsigned int *)t280) = (t309 & t305);
    goto LAB254;

LAB255:    *((unsigned int *)t310) = 1;
    goto LAB258;

LAB257:    t317 = (t310 + 4);
    *((unsigned int *)t310) = 1;
    *((unsigned int *)t317) = 1;
    goto LAB258;

LAB259:    t330 = *((unsigned int *)t318);
    t331 = *((unsigned int *)t324);
    *((unsigned int *)t318) = (t330 | t331);
    t332 = (t124 + 4);
    t333 = (t310 + 4);
    t334 = *((unsigned int *)t332);
    t335 = (~(t334));
    t336 = *((unsigned int *)t124);
    t180 = (t336 & t335);
    t337 = *((unsigned int *)t333);
    t338 = (~(t337));
    t339 = *((unsigned int *)t310);
    t181 = (t339 & t338);
    t340 = (~(t180));
    t341 = (~(t181));
    t342 = *((unsigned int *)t324);
    *((unsigned int *)t324) = (t342 & t340);
    t343 = *((unsigned int *)t324);
    *((unsigned int *)t324) = (t343 & t341);
    goto LAB261;

LAB262:
LAB265:    t350 = ((char*)((ng3)));
    t351 = (t1 + 23568);
    t354 = (t1 + 23568);
    t355 = (t354 + 72U);
    t356 = *((char **)t355);
    t357 = (t1 + 23568);
    t358 = (t357 + 64U);
    t359 = *((char **)t358);
    t360 = (t1 + 28048);
    t361 = (t360 + 56U);
    t362 = *((char **)t361);
    xsi_vlog_generic_convert_array_indices(t352, t353, t356, t359, 2, 1, t362, 10, 2);
    t363 = (t352 + 4);
    t364 = *((unsigned int *)t363);
    t182 = (!(t364));
    t365 = (t353 + 4);
    t366 = *((unsigned int *)t365);
    t183 = (!(t366));
    t367 = (t182 && t183);
    if (t367 == 1)
        goto LAB266;

LAB267:    goto LAB264;

LAB266:    t368 = *((unsigned int *)t352);
    t369 = *((unsigned int *)t353);
    t370 = (t368 - t369);
    t371 = (t370 + 1);
    xsi_vlogvar_assign_value(t351, t350, 0, *((unsigned int *)t353), t371);
    goto LAB267;

LAB269:    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t18);
    t63 = (t15 - t16);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t18), t64);
    goto LAB270;

LAB271:    *((unsigned int *)t18) = 1;
    goto LAB274;

LAB273:    t7 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB274;

LAB275:    t9 = (t1 + 7136);
    t11 = *((char **)t9);
    t9 = ((char*)((ng8)));
    memset(t43, 0, 8);
    xsi_vlog_signed_equal(t43, 32, t11, 32, t9, 32);
    memset(t45, 0, 8);
    t12 = (t43 + 4);
    t25 = *((unsigned int *)t12);
    t28 = (~(t25));
    t29 = *((unsigned int *)t43);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB278;

LAB279:    if (*((unsigned int *)t12) != 0)
        goto LAB280;

LAB281:    t32 = *((unsigned int *)t18);
    t68 = *((unsigned int *)t45);
    t75 = (t32 | t68);
    *((unsigned int *)t46) = t75;
    t20 = (t18 + 4);
    t26 = (t45 + 4);
    t27 = (t46 + 4);
    t76 = *((unsigned int *)t20);
    t77 = *((unsigned int *)t26);
    t78 = (t76 | t77);
    *((unsigned int *)t27) = t78;
    t79 = *((unsigned int *)t27);
    t80 = (t79 != 0);
    if (t80 == 1)
        goto LAB282;

LAB283:
LAB284:    goto LAB277;

LAB278:    *((unsigned int *)t45) = 1;
    goto LAB281;

LAB280:    t19 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB281;

LAB282:    t81 = *((unsigned int *)t46);
    t82 = *((unsigned int *)t27);
    *((unsigned int *)t46) = (t81 | t82);
    t33 = (t18 + 4);
    t34 = (t45 + 4);
    t83 = *((unsigned int *)t33);
    t84 = (~(t83));
    t85 = *((unsigned int *)t18);
    t58 = (t85 & t84);
    t86 = *((unsigned int *)t34);
    t87 = (~(t86));
    t88 = *((unsigned int *)t45);
    t60 = (t88 & t87);
    t89 = (~(t58));
    t90 = (~(t60));
    t91 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t91 & t89);
    t92 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t92 & t90);
    goto LAB284;

LAB285:    *((unsigned int *)t47) = 1;
    goto LAB288;

LAB287:    t36 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB288;

LAB289:    t38 = (t1 + 28688);
    t40 = (t38 + 56U);
    t41 = *((char **)t40);
    t42 = ((char*)((ng9)));
    memset(t55, 0, 8);
    t44 = (t41 + 4);
    t48 = (t42 + 4);
    t101 = *((unsigned int *)t41);
    t102 = *((unsigned int *)t42);
    t103 = (t101 ^ t102);
    t104 = *((unsigned int *)t44);
    t105 = *((unsigned int *)t48);
    t106 = (t104 ^ t105);
    t107 = (t103 | t106);
    t108 = *((unsigned int *)t44);
    t109 = *((unsigned int *)t48);
    t110 = (t108 | t109);
    t111 = (~(t110));
    t112 = (t107 & t111);
    if (t112 != 0)
        goto LAB295;

LAB292:    if (t110 != 0)
        goto LAB294;

LAB293:    *((unsigned int *)t55) = 1;

LAB295:    memset(t70, 0, 8);
    t50 = (t55 + 4);
    t113 = *((unsigned int *)t50);
    t114 = (~(t113));
    t115 = *((unsigned int *)t55);
    t116 = (t115 & t114);
    t117 = (t116 & 1U);
    if (t117 != 0)
        goto LAB296;

LAB297:    if (*((unsigned int *)t50) != 0)
        goto LAB298;

LAB299:    t119 = *((unsigned int *)t47);
    t120 = *((unsigned int *)t70);
    t121 = (t119 & t120);
    *((unsigned int *)t118) = t121;
    t52 = (t47 + 4);
    t53 = (t70 + 4);
    t54 = (t118 + 4);
    t122 = *((unsigned int *)t52);
    t123 = *((unsigned int *)t53);
    t125 = (t122 | t123);
    *((unsigned int *)t54) = t125;
    t126 = *((unsigned int *)t54);
    t127 = (t126 != 0);
    if (t127 == 1)
        goto LAB300;

LAB301:
LAB302:    goto LAB291;

LAB294:    t49 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB295;

LAB296:    *((unsigned int *)t70) = 1;
    goto LAB299;

LAB298:    t51 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB299;

LAB300:    t128 = *((unsigned int *)t118);
    t129 = *((unsigned int *)t54);
    *((unsigned int *)t118) = (t128 | t129);
    t56 = (t47 + 4);
    t57 = (t70 + 4);
    t130 = *((unsigned int *)t47);
    t131 = (~(t130));
    t132 = *((unsigned int *)t56);
    t133 = (~(t132));
    t134 = *((unsigned int *)t70);
    t135 = (~(t134));
    t136 = *((unsigned int *)t57);
    t137 = (~(t136));
    t61 = (t131 & t133);
    t63 = (t135 & t137);
    t138 = (~(t61));
    t139 = (~(t63));
    t140 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t140 & t138);
    t141 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t141 & t139);
    t142 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t142 & t138);
    t143 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t143 & t139);
    goto LAB302;

LAB303:
LAB306:    t62 = ((char*)((ng3)));
    t69 = (t1 + 23728);
    t71 = (t1 + 23728);
    t72 = (t71 + 72U);
    t73 = *((char **)t72);
    t74 = (t1 + 23728);
    t156 = (t74 + 64U);
    t157 = *((char **)t156);
    t164 = (t1 + 28048);
    t170 = (t164 + 56U);
    t171 = *((char **)t170);
    xsi_vlog_generic_convert_array_indices(t124, t154, t73, t157, 2, 1, t171, 10, 2);
    t173 = (t124 + 4);
    t149 = *((unsigned int *)t173);
    t64 = (!(t149));
    t174 = (t154 + 4);
    t150 = *((unsigned int *)t174);
    t65 = (!(t150));
    t66 = (t64 && t65);
    if (t66 == 1)
        goto LAB307;

LAB308:    goto LAB305;

LAB307:    t151 = *((unsigned int *)t124);
    t152 = *((unsigned int *)t154);
    t67 = (t151 - t152);
    t180 = (t67 + 1);
    xsi_vlogvar_assign_value(t69, t62, 0, *((unsigned int *)t154), t180);
    goto LAB308;

LAB310:    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t18);
    t63 = (t15 - t16);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t18), t64);
    goto LAB311;

LAB312:
LAB315:    t7 = (t1 + 7136);
    t8 = *((char **)t7);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t8, 32, t7, 32);
    memset(t43, 0, 8);
    t9 = (t18 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB316;

LAB317:    if (*((unsigned int *)t9) != 0)
        goto LAB318;

LAB319:    t12 = (t43 + 4);
    t28 = *((unsigned int *)t43);
    t29 = *((unsigned int *)t12);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB320;

LAB321:    memcpy(t47, t43, 8);

LAB322:    memset(t55, 0, 8);
    t48 = (t47 + 4);
    t113 = *((unsigned int *)t48);
    t114 = (~(t113));
    t115 = *((unsigned int *)t47);
    t116 = (t115 & t114);
    t117 = (t116 & 1U);
    if (t117 != 0)
        goto LAB334;

LAB335:    if (*((unsigned int *)t48) != 0)
        goto LAB336;

LAB337:    t50 = (t55 + 4);
    t119 = *((unsigned int *)t55);
    t120 = (!(t119));
    t121 = *((unsigned int *)t50);
    t122 = (t120 || t121);
    if (t122 > 0)
        goto LAB338;

LAB339:    memcpy(t272, t55, 8);

LAB340:    t284 = (t272 + 4);
    t298 = *((unsigned int *)t284);
    t299 = (~(t298));
    t300 = *((unsigned int *)t272);
    t301 = (t300 & t299);
    t302 = (t301 != 0);
    if (t302 > 0)
        goto LAB384;

LAB385:
LAB390:    t4 = ((char*)((ng4)));
    t5 = (t1 + 23888);
    t6 = (t1 + 23888);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t1 + 23888);
    t11 = (t9 + 64U);
    t12 = *((char **)t11);
    t19 = (t1 + 28048);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t10, t18, t8, t12, 2, 1, t26, 10, 2);
    t27 = (t10 + 4);
    t13 = *((unsigned int *)t27);
    t58 = (!(t13));
    t33 = (t18 + 4);
    t14 = *((unsigned int *)t33);
    t60 = (!(t14));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB391;

LAB392:
LAB386:    t4 = (t1 + 7136);
    t5 = *((char **)t4);
    t4 = ((char*)((ng7)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    memset(t18, 0, 8);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB393;

LAB394:    if (*((unsigned int *)t6) != 0)
        goto LAB395;

LAB396:    t8 = (t18 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (!(t21));
    t23 = *((unsigned int *)t8);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB397;

LAB398:    memcpy(t46, t18, 8);

LAB399:    memset(t47, 0, 8);
    t35 = (t46 + 4);
    t93 = *((unsigned int *)t35);
    t94 = (~(t93));
    t95 = *((unsigned int *)t46);
    t96 = (t95 & t94);
    t97 = (t96 & 1U);
    if (t97 != 0)
        goto LAB407;

LAB408:    if (*((unsigned int *)t35) != 0)
        goto LAB409;

LAB410:    t37 = (t47 + 4);
    t98 = *((unsigned int *)t47);
    t99 = *((unsigned int *)t37);
    t100 = (t98 || t99);
    if (t100 > 0)
        goto LAB411;

LAB412:    memcpy(t118, t47, 8);

LAB413:    t59 = (t118 + 4);
    t144 = *((unsigned int *)t59);
    t145 = (~(t144));
    t146 = *((unsigned int *)t118);
    t147 = (t146 & t145);
    t148 = (t147 != 0);
    if (t148 > 0)
        goto LAB425;

LAB426:
LAB431:    t4 = ((char*)((ng4)));
    t5 = (t1 + 24048);
    t6 = (t1 + 24048);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t1 + 24048);
    t11 = (t9 + 64U);
    t12 = *((char **)t11);
    t19 = (t1 + 28048);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t10, t18, t8, t12, 2, 1, t26, 10, 2);
    t27 = (t10 + 4);
    t13 = *((unsigned int *)t27);
    t58 = (!(t13));
    t33 = (t18 + 4);
    t14 = *((unsigned int *)t33);
    t60 = (!(t14));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB432;

LAB433:
LAB427:    goto LAB314;

LAB316:    *((unsigned int *)t43) = 1;
    goto LAB319;

LAB318:    t11 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB319;

LAB320:    t19 = (t1 + 28528);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    t27 = ((char*)((ng9)));
    memset(t45, 0, 8);
    t33 = (t26 + 4);
    t34 = (t27 + 4);
    t31 = *((unsigned int *)t26);
    t32 = *((unsigned int *)t27);
    t68 = (t31 ^ t32);
    t75 = *((unsigned int *)t33);
    t76 = *((unsigned int *)t34);
    t77 = (t75 ^ t76);
    t78 = (t68 | t77);
    t79 = *((unsigned int *)t33);
    t80 = *((unsigned int *)t34);
    t81 = (t79 | t80);
    t82 = (~(t81));
    t83 = (t78 & t82);
    if (t83 != 0)
        goto LAB326;

LAB323:    if (t81 != 0)
        goto LAB325;

LAB324:    *((unsigned int *)t45) = 1;

LAB326:    memset(t46, 0, 8);
    t36 = (t45 + 4);
    t84 = *((unsigned int *)t36);
    t85 = (~(t84));
    t86 = *((unsigned int *)t45);
    t87 = (t86 & t85);
    t88 = (t87 & 1U);
    if (t88 != 0)
        goto LAB327;

LAB328:    if (*((unsigned int *)t36) != 0)
        goto LAB329;

LAB330:    t89 = *((unsigned int *)t43);
    t90 = *((unsigned int *)t46);
    t91 = (t89 & t90);
    *((unsigned int *)t47) = t91;
    t38 = (t43 + 4);
    t40 = (t46 + 4);
    t41 = (t47 + 4);
    t92 = *((unsigned int *)t38);
    t93 = *((unsigned int *)t40);
    t94 = (t92 | t93);
    *((unsigned int *)t41) = t94;
    t95 = *((unsigned int *)t41);
    t96 = (t95 != 0);
    if (t96 == 1)
        goto LAB331;

LAB332:
LAB333:    goto LAB322;

LAB325:    t35 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB326;

LAB327:    *((unsigned int *)t46) = 1;
    goto LAB330;

LAB329:    t37 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB330;

LAB331:    t97 = *((unsigned int *)t47);
    t98 = *((unsigned int *)t41);
    *((unsigned int *)t47) = (t97 | t98);
    t42 = (t43 + 4);
    t44 = (t46 + 4);
    t99 = *((unsigned int *)t43);
    t100 = (~(t99));
    t101 = *((unsigned int *)t42);
    t102 = (~(t101));
    t103 = *((unsigned int *)t46);
    t104 = (~(t103));
    t105 = *((unsigned int *)t44);
    t106 = (~(t105));
    t58 = (t100 & t102);
    t60 = (t104 & t106);
    t107 = (~(t58));
    t108 = (~(t60));
    t109 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t109 & t107);
    t110 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t110 & t108);
    t111 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t111 & t107);
    t112 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t112 & t108);
    goto LAB333;

LAB334:    *((unsigned int *)t55) = 1;
    goto LAB337;

LAB336:    t49 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB337;

LAB338:    t51 = (t1 + 7136);
    t52 = *((char **)t51);
    t51 = ((char*)((ng8)));
    memset(t70, 0, 8);
    xsi_vlog_signed_equal(t70, 32, t52, 32, t51, 32);
    memset(t118, 0, 8);
    t53 = (t70 + 4);
    t123 = *((unsigned int *)t53);
    t125 = (~(t123));
    t126 = *((unsigned int *)t70);
    t127 = (t126 & t125);
    t128 = (t127 & 1U);
    if (t128 != 0)
        goto LAB341;

LAB342:    if (*((unsigned int *)t53) != 0)
        goto LAB343;

LAB344:    t56 = (t118 + 4);
    t129 = *((unsigned int *)t118);
    t130 = *((unsigned int *)t56);
    t131 = (t129 || t130);
    if (t131 > 0)
        goto LAB345;

LAB346:    memcpy(t155, t118, 8);

LAB347:    memset(t172, 0, 8);
    t174 = (t155 + 4);
    t193 = *((unsigned int *)t174);
    t194 = (~(t193));
    t195 = *((unsigned int *)t155);
    t196 = (t195 & t194);
    t197 = (t196 & 1U);
    if (t197 != 0)
        goto LAB359;

LAB360:    if (*((unsigned int *)t174) != 0)
        goto LAB361;

LAB362:    t176 = (t172 + 4);
    t198 = *((unsigned int *)t172);
    t199 = *((unsigned int *)t176);
    t200 = (t198 || t199);
    if (t200 > 0)
        goto LAB363;

LAB364:    memcpy(t240, t172, 8);

LAB365:    memset(t256, 0, 8);
    t254 = (t240 + 4);
    t263 = *((unsigned int *)t254);
    t264 = (~(t263));
    t265 = *((unsigned int *)t240);
    t266 = (t265 & t264);
    t267 = (t266 & 1U);
    if (t267 != 0)
        goto LAB377;

LAB378:    if (*((unsigned int *)t254) != 0)
        goto LAB379;

LAB380:    t268 = *((unsigned int *)t55);
    t269 = *((unsigned int *)t256);
    t270 = (t268 | t269);
    *((unsigned int *)t272) = t270;
    t257 = (t55 + 4);
    t258 = (t256 + 4);
    t271 = (t272 + 4);
    t274 = *((unsigned int *)t257);
    t275 = *((unsigned int *)t258);
    t276 = (t274 | t275);
    *((unsigned int *)t271) = t276;
    t277 = *((unsigned int *)t271);
    t278 = (t277 != 0);
    if (t278 == 1)
        goto LAB381;

LAB382:
LAB383:    goto LAB340;

LAB341:    *((unsigned int *)t118) = 1;
    goto LAB344;

LAB343:    t54 = (t118 + 4);
    *((unsigned int *)t118) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB344;

LAB345:    t57 = (t1 + 28528);
    t59 = (t57 + 56U);
    t62 = *((char **)t59);
    t69 = ((char*)((ng9)));
    memset(t124, 0, 8);
    t71 = (t62 + 4);
    t72 = (t69 + 4);
    t132 = *((unsigned int *)t62);
    t133 = *((unsigned int *)t69);
    t134 = (t132 ^ t133);
    t135 = *((unsigned int *)t71);
    t136 = *((unsigned int *)t72);
    t137 = (t135 ^ t136);
    t138 = (t134 | t137);
    t139 = *((unsigned int *)t71);
    t140 = *((unsigned int *)t72);
    t141 = (t139 | t140);
    t142 = (~(t141));
    t143 = (t138 & t142);
    if (t143 != 0)
        goto LAB351;

LAB348:    if (t141 != 0)
        goto LAB350;

LAB349:    *((unsigned int *)t124) = 1;

LAB351:    memset(t154, 0, 8);
    t74 = (t124 + 4);
    t144 = *((unsigned int *)t74);
    t145 = (~(t144));
    t146 = *((unsigned int *)t124);
    t147 = (t146 & t145);
    t148 = (t147 & 1U);
    if (t148 != 0)
        goto LAB352;

LAB353:    if (*((unsigned int *)t74) != 0)
        goto LAB354;

LAB355:    t149 = *((unsigned int *)t118);
    t150 = *((unsigned int *)t154);
    t151 = (t149 & t150);
    *((unsigned int *)t155) = t151;
    t157 = (t118 + 4);
    t164 = (t154 + 4);
    t170 = (t155 + 4);
    t152 = *((unsigned int *)t157);
    t153 = *((unsigned int *)t164);
    t158 = (t152 | t153);
    *((unsigned int *)t170) = t158;
    t159 = *((unsigned int *)t170);
    t160 = (t159 != 0);
    if (t160 == 1)
        goto LAB356;

LAB357:
LAB358:    goto LAB347;

LAB350:    t73 = (t124 + 4);
    *((unsigned int *)t124) = 1;
    *((unsigned int *)t73) = 1;
    goto LAB351;

LAB352:    *((unsigned int *)t154) = 1;
    goto LAB355;

LAB354:    t156 = (t154 + 4);
    *((unsigned int *)t154) = 1;
    *((unsigned int *)t156) = 1;
    goto LAB355;

LAB356:    t161 = *((unsigned int *)t155);
    t162 = *((unsigned int *)t170);
    *((unsigned int *)t155) = (t161 | t162);
    t171 = (t118 + 4);
    t173 = (t154 + 4);
    t163 = *((unsigned int *)t118);
    t165 = (~(t163));
    t166 = *((unsigned int *)t171);
    t167 = (~(t166));
    t168 = *((unsigned int *)t154);
    t169 = (~(t168));
    t178 = *((unsigned int *)t173);
    t186 = (~(t178));
    t61 = (t165 & t167);
    t63 = (t169 & t186);
    t187 = (~(t61));
    t188 = (~(t63));
    t189 = *((unsigned int *)t170);
    *((unsigned int *)t170) = (t189 & t187);
    t190 = *((unsigned int *)t170);
    *((unsigned int *)t170) = (t190 & t188);
    t191 = *((unsigned int *)t155);
    *((unsigned int *)t155) = (t191 & t187);
    t192 = *((unsigned int *)t155);
    *((unsigned int *)t155) = (t192 & t188);
    goto LAB358;

LAB359:    *((unsigned int *)t172) = 1;
    goto LAB362;

LAB361:    t175 = (t172 + 4);
    *((unsigned int *)t172) = 1;
    *((unsigned int *)t175) = 1;
    goto LAB362;

LAB363:    t177 = (t1 + 28688);
    t201 = (t177 + 56U);
    t203 = *((char **)t201);
    t209 = ((char*)((ng9)));
    memset(t202, 0, 8);
    t214 = (t203 + 4);
    t215 = (t209 + 4);
    t204 = *((unsigned int *)t203);
    t205 = *((unsigned int *)t209);
    t206 = (t204 ^ t205);
    t207 = *((unsigned int *)t214);
    t208 = *((unsigned int *)t215);
    t211 = (t207 ^ t208);
    t212 = (t206 | t211);
    t213 = *((unsigned int *)t214);
    t217 = *((unsigned int *)t215);
    t218 = (t213 | t217);
    t219 = (~(t218));
    t220 = (t212 & t219);
    if (t220 != 0)
        goto LAB367;

LAB366:    if (t218 != 0)
        goto LAB368;

LAB369:    memset(t210, 0, 8);
    t224 = (t202 + 4);
    t221 = *((unsigned int *)t224);
    t222 = (~(t221));
    t223 = *((unsigned int *)t202);
    t226 = (t223 & t222);
    t227 = (t226 & 1U);
    if (t227 != 0)
        goto LAB370;

LAB371:    if (*((unsigned int *)t224) != 0)
        goto LAB372;

LAB373:    t228 = *((unsigned int *)t172);
    t229 = *((unsigned int *)t210);
    t230 = (t228 & t229);
    *((unsigned int *)t240) = t230;
    t241 = (t172 + 4);
    t247 = (t210 + 4);
    t248 = (t240 + 4);
    t231 = *((unsigned int *)t241);
    t232 = *((unsigned int *)t247);
    t233 = (t231 | t232);
    *((unsigned int *)t248) = t233;
    t234 = *((unsigned int *)t248);
    t235 = (t234 != 0);
    if (t235 == 1)
        goto LAB374;

LAB375:
LAB376:    goto LAB365;

LAB367:    *((unsigned int *)t202) = 1;
    goto LAB369;

LAB368:    t216 = (t202 + 4);
    *((unsigned int *)t202) = 1;
    *((unsigned int *)t216) = 1;
    goto LAB369;

LAB370:    *((unsigned int *)t210) = 1;
    goto LAB373;

LAB372:    t225 = (t210 + 4);
    *((unsigned int *)t210) = 1;
    *((unsigned int *)t225) = 1;
    goto LAB373;

LAB374:    t236 = *((unsigned int *)t240);
    t237 = *((unsigned int *)t248);
    *((unsigned int *)t240) = (t236 | t237);
    t252 = (t172 + 4);
    t253 = (t210 + 4);
    t238 = *((unsigned int *)t172);
    t239 = (~(t238));
    t242 = *((unsigned int *)t252);
    t243 = (~(t242));
    t244 = *((unsigned int *)t210);
    t245 = (~(t244));
    t246 = *((unsigned int *)t253);
    t249 = (~(t246));
    t64 = (t239 & t243);
    t65 = (t245 & t249);
    t250 = (~(t64));
    t251 = (~(t65));
    t259 = *((unsigned int *)t248);
    *((unsigned int *)t248) = (t259 & t250);
    t260 = *((unsigned int *)t248);
    *((unsigned int *)t248) = (t260 & t251);
    t261 = *((unsigned int *)t240);
    *((unsigned int *)t240) = (t261 & t250);
    t262 = *((unsigned int *)t240);
    *((unsigned int *)t240) = (t262 & t251);
    goto LAB376;

LAB377:    *((unsigned int *)t256) = 1;
    goto LAB380;

LAB379:    t255 = (t256 + 4);
    *((unsigned int *)t256) = 1;
    *((unsigned int *)t255) = 1;
    goto LAB380;

LAB381:    t281 = *((unsigned int *)t272);
    t282 = *((unsigned int *)t271);
    *((unsigned int *)t272) = (t281 | t282);
    t273 = (t55 + 4);
    t279 = (t256 + 4);
    t283 = *((unsigned int *)t273);
    t287 = (~(t283));
    t288 = *((unsigned int *)t55);
    t66 = (t288 & t287);
    t289 = *((unsigned int *)t279);
    t290 = (~(t289));
    t291 = *((unsigned int *)t256);
    t67 = (t291 & t290);
    t292 = (~(t66));
    t293 = (~(t67));
    t296 = *((unsigned int *)t271);
    *((unsigned int *)t271) = (t296 & t292);
    t297 = *((unsigned int *)t271);
    *((unsigned int *)t271) = (t297 & t293);
    goto LAB383;

LAB384:
LAB387:    t285 = ((char*)((ng3)));
    t286 = (t1 + 23888);
    t294 = (t1 + 23888);
    t295 = (t294 + 72U);
    t311 = *((char **)t295);
    t317 = (t1 + 23888);
    t322 = (t317 + 64U);
    t323 = *((char **)t322);
    t324 = (t1 + 28048);
    t332 = (t324 + 56U);
    t333 = *((char **)t332);
    xsi_vlog_generic_convert_array_indices(t280, t310, t311, t323, 2, 1, t333, 10, 2);
    t344 = (t280 + 4);
    t303 = *((unsigned int *)t344);
    t180 = (!(t303));
    t350 = (t310 + 4);
    t304 = *((unsigned int *)t350);
    t181 = (!(t304));
    t182 = (t180 && t181);
    if (t182 == 1)
        goto LAB388;

LAB389:    goto LAB386;

LAB388:    t305 = *((unsigned int *)t280);
    t306 = *((unsigned int *)t310);
    t183 = (t305 - t306);
    t367 = (t183 + 1);
    xsi_vlogvar_assign_value(t286, t285, 0, *((unsigned int *)t310), t367);
    goto LAB389;

LAB391:    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t18);
    t63 = (t15 - t16);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t18), t64);
    goto LAB392;

LAB393:    *((unsigned int *)t18) = 1;
    goto LAB396;

LAB395:    t7 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB396;

LAB397:    t9 = (t1 + 7136);
    t11 = *((char **)t9);
    t9 = ((char*)((ng8)));
    memset(t43, 0, 8);
    xsi_vlog_signed_equal(t43, 32, t11, 32, t9, 32);
    memset(t45, 0, 8);
    t12 = (t43 + 4);
    t25 = *((unsigned int *)t12);
    t28 = (~(t25));
    t29 = *((unsigned int *)t43);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB400;

LAB401:    if (*((unsigned int *)t12) != 0)
        goto LAB402;

LAB403:    t32 = *((unsigned int *)t18);
    t68 = *((unsigned int *)t45);
    t75 = (t32 | t68);
    *((unsigned int *)t46) = t75;
    t20 = (t18 + 4);
    t26 = (t45 + 4);
    t27 = (t46 + 4);
    t76 = *((unsigned int *)t20);
    t77 = *((unsigned int *)t26);
    t78 = (t76 | t77);
    *((unsigned int *)t27) = t78;
    t79 = *((unsigned int *)t27);
    t80 = (t79 != 0);
    if (t80 == 1)
        goto LAB404;

LAB405:
LAB406:    goto LAB399;

LAB400:    *((unsigned int *)t45) = 1;
    goto LAB403;

LAB402:    t19 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB403;

LAB404:    t81 = *((unsigned int *)t46);
    t82 = *((unsigned int *)t27);
    *((unsigned int *)t46) = (t81 | t82);
    t33 = (t18 + 4);
    t34 = (t45 + 4);
    t83 = *((unsigned int *)t33);
    t84 = (~(t83));
    t85 = *((unsigned int *)t18);
    t58 = (t85 & t84);
    t86 = *((unsigned int *)t34);
    t87 = (~(t86));
    t88 = *((unsigned int *)t45);
    t60 = (t88 & t87);
    t89 = (~(t58));
    t90 = (~(t60));
    t91 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t91 & t89);
    t92 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t92 & t90);
    goto LAB406;

LAB407:    *((unsigned int *)t47) = 1;
    goto LAB410;

LAB409:    t36 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB410;

LAB411:    t38 = (t1 + 28688);
    t40 = (t38 + 56U);
    t41 = *((char **)t40);
    t42 = ((char*)((ng9)));
    memset(t55, 0, 8);
    t44 = (t41 + 4);
    t48 = (t42 + 4);
    t101 = *((unsigned int *)t41);
    t102 = *((unsigned int *)t42);
    t103 = (t101 ^ t102);
    t104 = *((unsigned int *)t44);
    t105 = *((unsigned int *)t48);
    t106 = (t104 ^ t105);
    t107 = (t103 | t106);
    t108 = *((unsigned int *)t44);
    t109 = *((unsigned int *)t48);
    t110 = (t108 | t109);
    t111 = (~(t110));
    t112 = (t107 & t111);
    if (t112 != 0)
        goto LAB417;

LAB414:    if (t110 != 0)
        goto LAB416;

LAB415:    *((unsigned int *)t55) = 1;

LAB417:    memset(t70, 0, 8);
    t50 = (t55 + 4);
    t113 = *((unsigned int *)t50);
    t114 = (~(t113));
    t115 = *((unsigned int *)t55);
    t116 = (t115 & t114);
    t117 = (t116 & 1U);
    if (t117 != 0)
        goto LAB418;

LAB419:    if (*((unsigned int *)t50) != 0)
        goto LAB420;

LAB421:    t119 = *((unsigned int *)t47);
    t120 = *((unsigned int *)t70);
    t121 = (t119 & t120);
    *((unsigned int *)t118) = t121;
    t52 = (t47 + 4);
    t53 = (t70 + 4);
    t54 = (t118 + 4);
    t122 = *((unsigned int *)t52);
    t123 = *((unsigned int *)t53);
    t125 = (t122 | t123);
    *((unsigned int *)t54) = t125;
    t126 = *((unsigned int *)t54);
    t127 = (t126 != 0);
    if (t127 == 1)
        goto LAB422;

LAB423:
LAB424:    goto LAB413;

LAB416:    t49 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB417;

LAB418:    *((unsigned int *)t70) = 1;
    goto LAB421;

LAB420:    t51 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB421;

LAB422:    t128 = *((unsigned int *)t118);
    t129 = *((unsigned int *)t54);
    *((unsigned int *)t118) = (t128 | t129);
    t56 = (t47 + 4);
    t57 = (t70 + 4);
    t130 = *((unsigned int *)t47);
    t131 = (~(t130));
    t132 = *((unsigned int *)t56);
    t133 = (~(t132));
    t134 = *((unsigned int *)t70);
    t135 = (~(t134));
    t136 = *((unsigned int *)t57);
    t137 = (~(t136));
    t61 = (t131 & t133);
    t63 = (t135 & t137);
    t138 = (~(t61));
    t139 = (~(t63));
    t140 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t140 & t138);
    t141 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t141 & t139);
    t142 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t142 & t138);
    t143 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t143 & t139);
    goto LAB424;

LAB425:
LAB428:    t62 = ((char*)((ng3)));
    t69 = (t1 + 24048);
    t71 = (t1 + 24048);
    t72 = (t71 + 72U);
    t73 = *((char **)t72);
    t74 = (t1 + 24048);
    t156 = (t74 + 64U);
    t157 = *((char **)t156);
    t164 = (t1 + 28048);
    t170 = (t164 + 56U);
    t171 = *((char **)t170);
    xsi_vlog_generic_convert_array_indices(t124, t154, t73, t157, 2, 1, t171, 10, 2);
    t173 = (t124 + 4);
    t149 = *((unsigned int *)t173);
    t64 = (!(t149));
    t174 = (t154 + 4);
    t150 = *((unsigned int *)t174);
    t65 = (!(t150));
    t66 = (t64 && t65);
    if (t66 == 1)
        goto LAB429;

LAB430:    goto LAB427;

LAB429:    t151 = *((unsigned int *)t124);
    t152 = *((unsigned int *)t154);
    t67 = (t151 - t152);
    t180 = (t67 + 1);
    xsi_vlogvar_assign_value(t69, t62, 0, *((unsigned int *)t154), t180);
    goto LAB430;

LAB432:    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t18);
    t63 = (t15 - t16);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t18), t64);
    goto LAB433;

}

static int sp_write_b(char *t1, char *t2)
{
    char t10[8];
    char t18[8];
    char t39[32];
    char t43[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    char t70[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    unsigned int t13;
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
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t59;
    int t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    int t65;
    int t66;
    int t67;
    unsigned int t68;
    char *t69;
    char *t71;
    char *t72;
    char *t73;
    char *t74;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 13112);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 29328);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 10264);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    xsi_vlog_unsigned_divide(t10, 32, t7, 10, t9, 32);
    t8 = (t1 + 29968);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 10);
    t4 = (t1 + 29968);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5504);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB7;

LAB6:    t9 = (t8 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB7;

LAB10:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB9;

LAB8:    *((unsigned int *)t10) = 1;

LAB9:    t12 = (t10 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB11;

LAB12:
LAB23:    t4 = (t1 + 4824);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB24;

LAB25:
LAB58:    t4 = (t1 + 29648);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 29808);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 128);

LAB26:    t4 = (t1 + 9720);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB59;

LAB60:
LAB65:    t4 = ((char*)((ng4)));
    t5 = (t1 + 30128);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB66:    t4 = (t1 + 30128);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9720);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB67;

LAB68:
LAB61:
LAB13:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB7:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB9;

LAB11:
LAB14:    t19 = (t1 + 7816);
    t20 = *((char **)t19);
    memset(t18, 0, 8);
    t19 = (t20 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB18;

LAB16:    if (*((unsigned int *)t19) == 0)
        goto LAB15;

LAB17:    t26 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t26) = 1;

LAB18:    t27 = (t18 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t18);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB19;

LAB20:
LAB21:    goto LAB13;

LAB15:    *((unsigned int *)t18) = 1;
    goto LAB18;

LAB19:
LAB22:    t33 = ((char*)((ng0)));
    t34 = ((char*)((ng2)));
    t35 = (t1 + 29328);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 13112);
    xsi_vlogfile_fwrite(*((unsigned int *)t33), 1, 0, 0, ng12, 3, t38, (char)118, t34, 128, (char)118, t37, 10);
    goto LAB21;

LAB24:
LAB27:    t6 = (t1 + 9720);
    t7 = *((char **)t6);
    t6 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t7, 32, t6, 32);
    t8 = (t10 + 4);
    t21 = *((unsigned int *)t8);
    t22 = (~(t21));
    t23 = *((unsigned int *)t10);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB28;

LAB29:
LAB32:    t4 = ((char*)((ng4)));
    t5 = (t1 + 30128);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB33:    t4 = (t1 + 30128);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9720);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB34;

LAB35:
LAB30:    t4 = (t1 + 4960);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB39;

LAB40:
LAB47:    t4 = ((char*)((ng4)));
    t5 = (t1 + 30128);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB48:    t4 = (t1 + 30128);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4960);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB49;

LAB50:
LAB41:    goto LAB26;

LAB28:
LAB31:    t9 = (t1 + 23248);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 23248);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 23248);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 29968);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    xsi_vlog_generic_get_array_select_value(t39, 128, t12, t26, t34, 2, 1, t37, 10, 2);
    t38 = (t1 + 29808);
    xsi_vlogvar_assign_value(t38, t39, 0, 0, 128);
    goto LAB30;

LAB34:
LAB36:    t9 = (t1 + 23248);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 23248);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 23248);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 29968);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 9720);
    t40 = *((char **)t38);
    memset(t18, 0, 8);
    xsi_vlog_unsigned_multiply(t18, 32, t37, 10, t40, 32);
    t38 = (t1 + 30128);
    t41 = (t38 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_add(t43, 32, t18, 32, t42, 32);
    xsi_vlog_generic_get_array_select_value(t39, 128, t12, t26, t34, 2, 1, t43, 32, 2);
    t44 = (t1 + 29808);
    t48 = (t1 + 29808);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t1 + 8904);
    t52 = *((char **)t51);
    t51 = (t1 + 30128);
    t53 = (t51 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t52, 32, t54, 32);
    t56 = ((char*)((ng5)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t50)), 2, t55, 32, 1, t56, 32, 1, 1);
    t57 = (t45 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t46 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    t62 = (t47 + 4);
    t23 = *((unsigned int *)t62);
    t63 = (!(t23));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB37;

LAB38:    t4 = (t1 + 30128);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 30128);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB33;

LAB37:    t24 = *((unsigned int *)t47);
    t65 = (t24 + 0);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t46);
    t66 = (t25 - t28);
    t67 = (t66 + 1);
    xsi_vlogvar_assign_value(t44, t39, t65, *((unsigned int *)t46), t67);
    goto LAB38;

LAB39:
LAB42:    t7 = (t1 + 29488);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t18, 0, 8);
    t11 = (t18 + 4);
    t12 = (t9 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t18) = t23;
    t24 = *((unsigned int *)t12);
    t25 = (t24 >> 0);
    t28 = (t25 & 1);
    *((unsigned int *)t11) = t28;
    t19 = (t18 + 4);
    t29 = *((unsigned int *)t19);
    t30 = (~(t29));
    t31 = *((unsigned int *)t18);
    t32 = (t31 & t30);
    t68 = (t32 != 0);
    if (t68 > 0)
        goto LAB43;

LAB44:
LAB45:    goto LAB41;

LAB43:
LAB46:    t20 = (t1 + 29648);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    t33 = (t1 + 29808);
    xsi_vlogvar_assign_value(t33, t27, 0, 0, 128);
    goto LAB45;

LAB49:
LAB51:    t9 = (t1 + 29488);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 29488);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 30128);
    t33 = (t27 + 56U);
    t34 = *((char **)t33);
    xsi_vlog_generic_get_index_select_value(t18, 1, t12, t26, 2, t34, 32, 1);
    t35 = (t18 + 4);
    t21 = *((unsigned int *)t35);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB52;

LAB53:
LAB54:    t4 = (t1 + 30128);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 30128);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB48;

LAB52:
LAB55:    t36 = (t1 + 29648);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t40 = (t1 + 29648);
    t41 = (t40 + 72U);
    t42 = *((char **)t41);
    t44 = (t1 + 10536);
    t48 = *((char **)t44);
    t44 = (t1 + 30128);
    t49 = (t44 + 56U);
    t50 = *((char **)t49);
    memset(t45, 0, 8);
    xsi_vlog_signed_multiply(t45, 32, t48, 32, t50, 32);
    t51 = ((char*)((ng6)));
    xsi_vlog_get_indexed_partselect(t43, 9, t38, ((int*)(t42)), 2, t45, 32, 1, t51, 32, 1, 1);
    t52 = (t1 + 29808);
    t53 = (t1 + 29808);
    t54 = (t53 + 72U);
    t56 = *((char **)t54);
    t57 = (t1 + 10536);
    t59 = *((char **)t57);
    t57 = (t1 + 30128);
    t62 = (t57 + 56U);
    t69 = *((char **)t62);
    memset(t70, 0, 8);
    xsi_vlog_signed_multiply(t70, 32, t59, 32, t69, 32);
    t71 = ((char*)((ng6)));
    xsi_vlog_convert_indexed_partindices(t46, t47, t55, ((int*)(t56)), 2, t70, 32, 1, t71, 32, 1, 1);
    t72 = (t46 + 4);
    t28 = *((unsigned int *)t72);
    t58 = (!(t28));
    t73 = (t47 + 4);
    t29 = *((unsigned int *)t73);
    t60 = (!(t29));
    t61 = (t58 && t60);
    t74 = (t55 + 4);
    t30 = *((unsigned int *)t74);
    t63 = (!(t30));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB56;

LAB57:    goto LAB54;

LAB56:    t31 = *((unsigned int *)t55);
    t65 = (t31 + 0);
    t32 = *((unsigned int *)t46);
    t68 = *((unsigned int *)t47);
    t66 = (t32 - t68);
    t67 = (t66 + 1);
    xsi_vlogvar_assign_value(t52, t43, t65, *((unsigned int *)t47), t67);
    goto LAB57;

LAB59:
LAB62:    t7 = (t1 + 29808);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t11 = (t1 + 23248);
    t12 = (t1 + 23248);
    t19 = (t12 + 72U);
    t20 = *((char **)t19);
    t26 = (t1 + 23248);
    t27 = (t26 + 64U);
    t33 = *((char **)t27);
    t34 = (t1 + 29968);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    t37 = (t1 + 9720);
    t38 = *((char **)t37);
    memset(t45, 0, 8);
    xsi_vlog_unsigned_multiply(t45, 32, t36, 10, t38, 32);
    xsi_vlog_generic_convert_array_indices(t18, t43, t20, t33, 2, 1, t45, 32, 2);
    t37 = (t18 + 4);
    t21 = *((unsigned int *)t37);
    t58 = (!(t21));
    t40 = (t43 + 4);
    t22 = *((unsigned int *)t40);
    t60 = (!(t22));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB63;

LAB64:    goto LAB61;

LAB63:    t23 = *((unsigned int *)t18);
    t24 = *((unsigned int *)t43);
    t63 = (t23 - t24);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t11, t9, 0, *((unsigned int *)t43), t64);
    goto LAB64;

LAB67:
LAB69:    t9 = (t1 + 29808);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 29808);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 8904);
    t33 = *((char **)t27);
    t27 = (t1 + 30128);
    t34 = (t27 + 56U);
    t35 = *((char **)t34);
    memset(t18, 0, 8);
    xsi_vlog_signed_multiply(t18, 32, t33, 32, t35, 32);
    t36 = ((char*)((ng5)));
    xsi_vlog_get_indexed_partselect(t39, 128, t12, ((int*)(t26)), 2, t18, 32, 1, t36, 32, 1, 1);
    t37 = (t1 + 23248);
    t38 = (t1 + 23248);
    t40 = (t38 + 72U);
    t41 = *((char **)t40);
    t42 = (t1 + 23248);
    t44 = (t42 + 64U);
    t48 = *((char **)t44);
    t49 = (t1 + 29968);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    t52 = (t1 + 9720);
    t53 = *((char **)t52);
    memset(t46, 0, 8);
    xsi_vlog_unsigned_multiply(t46, 32, t51, 10, t53, 32);
    t52 = (t1 + 30128);
    t54 = (t52 + 56U);
    t56 = *((char **)t54);
    memset(t47, 0, 8);
    xsi_vlog_unsigned_add(t47, 32, t46, 32, t56, 32);
    xsi_vlog_generic_convert_array_indices(t43, t45, t41, t48, 2, 1, t47, 32, 2);
    t57 = (t43 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t45 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB70;

LAB71:    t4 = (t1 + 30128);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 30128);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB66;

LAB70:    t23 = *((unsigned int *)t43);
    t24 = *((unsigned int *)t45);
    t63 = (t23 - t24);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t37, t39, 0, *((unsigned int *)t45), t64);
    goto LAB71;

}

static int sp_read_a(char *t1, char *t2)
{
    char t18[8];
    char t19[8];
    char t39[32];
    char t43[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
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
    char *t20;
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
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t59;
    int t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    int t65;
    int t66;
    int t67;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 13544);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 30448);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB6;

LAB7:
LAB10:    t4 = (t1 + 30288);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 10128);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    xsi_vlog_unsigned_divide(t18, 32, t6, 10, t8, 32);
    t7 = (t1 + 30608);
    xsi_vlogvar_assign_value(t7, t18, 0, 0, 10);
    t4 = (t1 + 30608);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3736);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB12;

LAB11:    t14 = (t8 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB12;

LAB15:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB14;

LAB13:    *((unsigned int *)t18) = 1;

LAB14:    t16 = (t18 + 4);
    t9 = *((unsigned int *)t16);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB16;

LAB17:
LAB28:    t4 = (t1 + 9584);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t5, 32, t4, 32);
    t6 = (t18 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB29;

LAB30:
LAB33:    t4 = ((char*)((ng4)));
    t5 = (t1 + 30768);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB34:    t4 = (t1 + 30768);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9584);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    xsi_vlog_signed_less(t18, 32, t6, 32, t8, 32);
    t7 = (t18 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB35;

LAB36:
LAB31:
LAB18:
LAB8:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:
LAB9:    t14 = (t1 + 25008);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 24208);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 128, 100LL);
    goto LAB8;

LAB12:    t15 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB14;

LAB16:
LAB19:    t17 = (t1 + 7816);
    t20 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t20 + 4);
    t21 = *((unsigned int *)t17);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB23;

LAB21:    if (*((unsigned int *)t17) == 0)
        goto LAB20;

LAB22:    t26 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t26) = 1;

LAB23:    t27 = (t19 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t19);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB24;

LAB25:
LAB26:    t4 = ((char*)((ng14)));
    t5 = (t1 + 24208);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 128, 100LL);
    goto LAB18;

LAB20:    *((unsigned int *)t19) = 1;
    goto LAB23;

LAB24:
LAB27:    t33 = ((char*)((ng0)));
    t34 = ((char*)((ng2)));
    t35 = (t1 + 30288);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 13544);
    xsi_vlogfile_fwrite(*((unsigned int *)t33), 1, 0, 0, ng13, 3, t38, (char)118, t34, 128, (char)118, t37, 10);
    goto LAB26;

LAB29:
LAB32:    t7 = (t1 + 23248);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    t15 = (t1 + 23248);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t20 = (t1 + 23248);
    t26 = (t20 + 64U);
    t27 = *((char **)t26);
    t33 = (t1 + 30608);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = (t1 + 9584);
    t37 = *((char **)t36);
    memset(t19, 0, 8);
    xsi_vlog_unsigned_multiply(t19, 32, t35, 10, t37, 32);
    xsi_vlog_generic_get_array_select_value(t39, 128, t14, t17, t27, 2, 1, t19, 32, 2);
    t36 = (t1 + 24208);
    xsi_vlogvar_wait_assign_value(t36, t39, 0, 0, 128, 100LL);
    goto LAB31;

LAB35:
LAB37:    t14 = (t1 + 23248);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 23248);
    t20 = (t17 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 23248);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 30608);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 9584);
    t40 = *((char **)t38);
    memset(t19, 0, 8);
    xsi_vlog_unsigned_multiply(t19, 32, t37, 10, t40, 32);
    t38 = (t1 + 30768);
    t41 = (t38 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_add(t43, 32, t19, 32, t42, 32);
    xsi_vlog_generic_get_array_select_value(t39, 128, t16, t26, t34, 2, 1, t43, 32, 2);
    t44 = (t1 + 24208);
    t48 = (t1 + 24208);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t1 + 8904);
    t52 = *((char **)t51);
    t51 = (t1 + 30768);
    t53 = (t51 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t52, 32, t54, 32);
    t56 = ((char*)((ng5)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t50)), 2, t55, 32, 1, t56, 32, 1, 1);
    t57 = (t45 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t46 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    t62 = (t47 + 4);
    t23 = *((unsigned int *)t62);
    t63 = (!(t23));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB38;

LAB39:    t4 = (t1 + 30768);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_add(t18, 32, t6, 32, t7, 32);
    t8 = (t1 + 30768);
    xsi_vlogvar_assign_value(t8, t18, 0, 0, 32);
    goto LAB34;

LAB38:    t24 = *((unsigned int *)t47);
    t65 = (t24 + 0);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t46);
    t66 = (t25 - t28);
    t67 = (t66 + 1);
    xsi_vlogvar_wait_assign_value(t44, t39, t65, *((unsigned int *)t46), t67, 100LL);
    goto LAB39;

}

static int sp_read_b(char *t1, char *t2)
{
    char t18[8];
    char t19[8];
    char t39[32];
    char t43[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    char t68[16];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
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
    char *t20;
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
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t59;
    int t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    int t65;
    int t66;
    int t67;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 13976);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 31088);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB6;

LAB7:
LAB10:    t4 = (t1 + 30928);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 10400);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    xsi_vlog_unsigned_divide(t18, 32, t6, 10, t8, 32);
    t7 = (t1 + 31248);
    xsi_vlogvar_assign_value(t7, t18, 0, 0, 10);
    t4 = (t1 + 31248);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5640);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB12;

LAB11:    t14 = (t8 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB12;

LAB15:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB14;

LAB13:    *((unsigned int *)t18) = 1;

LAB14:    t16 = (t18 + 4);
    t9 = *((unsigned int *)t16);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB16;

LAB17:
LAB28:    t4 = (t1 + 9856);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t5, 32, t4, 32);
    t6 = (t18 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB29;

LAB30:
LAB33:    t4 = ((char*)((ng4)));
    t5 = (t1 + 31408);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB34:    t4 = (t1 + 31408);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9856);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    xsi_vlog_signed_less(t18, 32, t6, 32, t8, 32);
    t7 = (t18 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB35;

LAB36:
LAB31:    t4 = ((char*)((ng11)));
    t5 = ((char*)((ng11)));
    xsi_vlog_unsigned_equal(t68, 56, t4, 56, t5, 56);
    memset(t18, 0, 8);
    t6 = (t68 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t68);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t6) != 0)
        goto LAB42;

LAB43:    t8 = (t18 + 4);
    t21 = *((unsigned int *)t18);
    t22 = *((unsigned int *)t8);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB44;

LAB45:    memcpy(t45, t18, 8);

LAB46:    t35 = (t45 + 4);
    t91 = *((unsigned int *)t35);
    t92 = (~(t91));
    t93 = *((unsigned int *)t45);
    t94 = (t93 & t92);
    t95 = (t94 != 0);
    if (t95 > 0)
        goto LAB54;

LAB55:    t4 = (t1 + 6864);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t5, 32, t4, 32);
    t6 = (t18 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB76;

LAB77:
LAB98:    t4 = ((char*)((ng4)));
    t5 = (t1 + 24848);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 100LL);
    t4 = ((char*)((ng15)));
    t5 = (t1 + 24688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng15)));
    t5 = (t1 + 24528);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB78:
LAB56:
LAB18:
LAB8:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:
LAB9:    t14 = (t1 + 25168);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 24368);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 128, 100LL);
    t4 = ((char*)((ng15)));
    t5 = (t1 + 24528);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng15)));
    t5 = (t1 + 24688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 24848);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 100LL);
    goto LAB8;

LAB12:    t15 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB14;

LAB16:
LAB19:    t17 = (t1 + 7816);
    t20 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t20 + 4);
    t21 = *((unsigned int *)t17);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB23;

LAB21:    if (*((unsigned int *)t17) == 0)
        goto LAB20;

LAB22:    t26 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t26) = 1;

LAB23:    t27 = (t19 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t19);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB24;

LAB25:
LAB26:    t4 = ((char*)((ng14)));
    t5 = (t1 + 24368);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 128, 100LL);
    t4 = ((char*)((ng17)));
    t5 = (t1 + 24528);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng17)));
    t5 = (t1 + 24688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng18)));
    t5 = (t1 + 24848);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 100LL);
    goto LAB18;

LAB20:    *((unsigned int *)t19) = 1;
    goto LAB23;

LAB24:
LAB27:    t33 = ((char*)((ng0)));
    t34 = ((char*)((ng2)));
    t35 = (t1 + 30928);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 13976);
    xsi_vlogfile_fwrite(*((unsigned int *)t33), 1, 0, 0, ng16, 3, t38, (char)118, t34, 128, (char)118, t37, 10);
    goto LAB26;

LAB29:
LAB32:    t7 = (t1 + 23248);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    t15 = (t1 + 23248);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t20 = (t1 + 23248);
    t26 = (t20 + 64U);
    t27 = *((char **)t26);
    t33 = (t1 + 31248);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = (t1 + 9856);
    t37 = *((char **)t36);
    memset(t19, 0, 8);
    xsi_vlog_unsigned_multiply(t19, 32, t35, 10, t37, 32);
    xsi_vlog_generic_get_array_select_value(t39, 128, t14, t17, t27, 2, 1, t19, 32, 2);
    t36 = (t1 + 24368);
    xsi_vlogvar_wait_assign_value(t36, t39, 0, 0, 128, 100LL);
    goto LAB31;

LAB35:
LAB37:    t14 = (t1 + 23248);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 23248);
    t20 = (t17 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 23248);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 31248);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 9856);
    t40 = *((char **)t38);
    memset(t19, 0, 8);
    xsi_vlog_unsigned_multiply(t19, 32, t37, 10, t40, 32);
    t38 = (t1 + 31408);
    t41 = (t38 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_add(t43, 32, t19, 32, t42, 32);
    xsi_vlog_generic_get_array_select_value(t39, 128, t16, t26, t34, 2, 1, t43, 32, 2);
    t44 = (t1 + 24368);
    t48 = (t1 + 24368);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t1 + 8904);
    t52 = *((char **)t51);
    t51 = (t1 + 31408);
    t53 = (t51 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t52, 32, t54, 32);
    t56 = ((char*)((ng5)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t50)), 2, t55, 32, 1, t56, 32, 1, 1);
    t57 = (t45 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t46 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    t62 = (t47 + 4);
    t23 = *((unsigned int *)t62);
    t63 = (!(t23));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB38;

LAB39:    t4 = (t1 + 31408);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_add(t18, 32, t6, 32, t7, 32);
    t8 = (t1 + 31408);
    xsi_vlogvar_assign_value(t8, t18, 0, 0, 32);
    goto LAB34;

LAB38:    t24 = *((unsigned int *)t47);
    t65 = (t24 + 0);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t46);
    t66 = (t25 - t28);
    t67 = (t66 + 1);
    xsi_vlogvar_wait_assign_value(t44, t39, t65, *((unsigned int *)t46), t67, 100LL);
    goto LAB39;

LAB40:    *((unsigned int *)t18) = 1;
    goto LAB43;

LAB42:    t7 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB43;

LAB44:    t14 = (t1 + 7000);
    t15 = *((char **)t14);
    t14 = ((char*)((ng3)));
    memset(t19, 0, 8);
    xsi_vlog_signed_equal(t19, 32, t15, 32, t14, 32);
    memset(t43, 0, 8);
    t16 = (t19 + 4);
    t24 = *((unsigned int *)t16);
    t25 = (~(t24));
    t28 = *((unsigned int *)t19);
    t29 = (t28 & t25);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t16) != 0)
        goto LAB49;

LAB50:    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t43);
    t69 = (t31 & t32);
    *((unsigned int *)t45) = t69;
    t20 = (t18 + 4);
    t26 = (t43 + 4);
    t27 = (t45 + 4);
    t70 = *((unsigned int *)t20);
    t71 = *((unsigned int *)t26);
    t72 = (t70 | t71);
    *((unsigned int *)t27) = t72;
    t73 = *((unsigned int *)t27);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB51;

LAB52:
LAB53:    goto LAB46;

LAB47:    *((unsigned int *)t43) = 1;
    goto LAB50;

LAB49:    t17 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB50;

LAB51:    t75 = *((unsigned int *)t45);
    t76 = *((unsigned int *)t27);
    *((unsigned int *)t45) = (t75 | t76);
    t33 = (t18 + 4);
    t34 = (t43 + 4);
    t77 = *((unsigned int *)t18);
    t78 = (~(t77));
    t79 = *((unsigned int *)t33);
    t80 = (~(t79));
    t81 = *((unsigned int *)t43);
    t82 = (~(t81));
    t83 = *((unsigned int *)t34);
    t84 = (~(t83));
    t58 = (t78 & t80);
    t60 = (t82 & t84);
    t85 = (~(t58));
    t86 = (~(t60));
    t87 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t87 & t85);
    t88 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t88 & t86);
    t89 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t89 & t85);
    t90 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t90 & t86);
    goto LAB53;

LAB54:
LAB57:    t36 = (t1 + 30928);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t40 = (t1 + 24848);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 10, 100LL);
    t4 = (t1 + 23568);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 23568);
    t8 = (t7 + 72U);
    t14 = *((char **)t8);
    t15 = (t1 + 23568);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t20 = (t1 + 30928);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 32, t6, t14, t17, 2, 1, t27, 10, 2);
    t33 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t34 = (t18 + 4);
    t35 = (t33 + 4);
    t9 = *((unsigned int *)t18);
    t10 = *((unsigned int *)t33);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t34);
    t13 = *((unsigned int *)t35);
    t21 = (t12 ^ t13);
    t22 = (t11 | t21);
    t23 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t23 | t24);
    t28 = (~(t25));
    t29 = (t22 & t28);
    if (t29 != 0)
        goto LAB61;

LAB58:    if (t25 != 0)
        goto LAB60;

LAB59:    *((unsigned int *)t19) = 1;

LAB61:    t37 = (t19 + 4);
    t30 = *((unsigned int *)t37);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t69 = (t32 & t31);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB62;

LAB63:
LAB66:    t4 = ((char*)((ng15)));
    t5 = (t1 + 24528);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB64:    t4 = (t1 + 23728);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 23728);
    t8 = (t7 + 72U);
    t14 = *((char **)t8);
    t15 = (t1 + 23728);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t20 = (t1 + 30928);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 32, t6, t14, t17, 2, 1, t27, 10, 2);
    t33 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t34 = (t18 + 4);
    t35 = (t33 + 4);
    t9 = *((unsigned int *)t18);
    t10 = *((unsigned int *)t33);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t34);
    t13 = *((unsigned int *)t35);
    t21 = (t12 ^ t13);
    t22 = (t11 | t21);
    t23 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t23 | t24);
    t28 = (~(t25));
    t29 = (t22 & t28);
    if (t29 != 0)
        goto LAB70;

LAB67:    if (t25 != 0)
        goto LAB69;

LAB68:    *((unsigned int *)t19) = 1;

LAB70:    t37 = (t19 + 4);
    t30 = *((unsigned int *)t37);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t69 = (t32 & t31);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB71;

LAB72:
LAB75:    t4 = ((char*)((ng15)));
    t5 = (t1 + 24688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB73:    goto LAB56;

LAB60:    t36 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB61;

LAB62:
LAB65:    t38 = ((char*)((ng9)));
    t40 = (t1 + 24528);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 1, 100LL);
    goto LAB64;

LAB69:    t36 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB70;

LAB71:
LAB74:    t38 = ((char*)((ng9)));
    t40 = (t1 + 24688);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 1, 100LL);
    goto LAB73;

LAB76:
LAB79:    t7 = (t1 + 30928);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    t15 = (t1 + 24848);
    xsi_vlogvar_wait_assign_value(t15, t14, 0, 0, 10, 100LL);
    t4 = (t1 + 23888);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 23888);
    t8 = (t7 + 72U);
    t14 = *((char **)t8);
    t15 = (t1 + 23888);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t20 = (t1 + 30928);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 32, t6, t14, t17, 2, 1, t27, 10, 2);
    t33 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t34 = (t18 + 4);
    t35 = (t33 + 4);
    t9 = *((unsigned int *)t18);
    t10 = *((unsigned int *)t33);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t34);
    t13 = *((unsigned int *)t35);
    t21 = (t12 ^ t13);
    t22 = (t11 | t21);
    t23 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t23 | t24);
    t28 = (~(t25));
    t29 = (t22 & t28);
    if (t29 != 0)
        goto LAB83;

LAB80:    if (t25 != 0)
        goto LAB82;

LAB81:    *((unsigned int *)t19) = 1;

LAB83:    t37 = (t19 + 4);
    t30 = *((unsigned int *)t37);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t69 = (t32 & t31);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB84;

LAB85:
LAB88:    t4 = ((char*)((ng15)));
    t5 = (t1 + 24528);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB86:    t4 = (t1 + 24048);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 24048);
    t8 = (t7 + 72U);
    t14 = *((char **)t8);
    t15 = (t1 + 24048);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t20 = (t1 + 30928);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 32, t6, t14, t17, 2, 1, t27, 10, 2);
    t33 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t34 = (t18 + 4);
    t35 = (t33 + 4);
    t9 = *((unsigned int *)t18);
    t10 = *((unsigned int *)t33);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t34);
    t13 = *((unsigned int *)t35);
    t21 = (t12 ^ t13);
    t22 = (t11 | t21);
    t23 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t23 | t24);
    t28 = (~(t25));
    t29 = (t22 & t28);
    if (t29 != 0)
        goto LAB92;

LAB89:    if (t25 != 0)
        goto LAB91;

LAB90:    *((unsigned int *)t19) = 1;

LAB92:    t37 = (t19 + 4);
    t30 = *((unsigned int *)t37);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t69 = (t32 & t31);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB93;

LAB94:
LAB97:    t4 = ((char*)((ng15)));
    t5 = (t1 + 24688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB95:    goto LAB78;

LAB82:    t36 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB83;

LAB84:
LAB87:    t38 = ((char*)((ng9)));
    t40 = (t1 + 24528);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 1, 100LL);
    goto LAB86;

LAB91:    t36 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB92;

LAB93:
LAB96:    t38 = ((char*)((ng9)));
    t40 = (t1 + 24688);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 1, 100LL);
    goto LAB95;

}

static int sp_reset_a(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
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

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 14408);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 31568);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB6;

LAB7:
LAB8:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:    t14 = (t1 + 25008);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 24208);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 128, 100LL);
    goto LAB8;

}

static int sp_reset_b(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
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

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 14840);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 31728);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB6;

LAB7:
LAB8:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:    t14 = (t1 + 25168);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 24368);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 128, 100LL);
    goto LAB8;

}

static int sp_init_memory(char *t1, char *t2)
{
    char t7[8];
    char t20[8];
    char t27[8];
    char t62[256];
    char t63[32];
    char t92[2048];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
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
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 15272);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = ((char*)((ng19)));
    t6 = (t1 + 32368);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 128);
    t4 = (t1 + 1696);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 & 4294967295U);
    if (t12 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t27, t7, 8);

LAB12:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB20;

LAB21:
LAB22:    t4 = (t1 + 1696);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB23;

LAB24:
LAB25:    t4 = (t1 + 9992);
    t5 = *((char **)t4);
    t4 = (t1 + 32048);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 32);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 31888);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB36:    t4 = (t1 + 31888);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 3600);
    t18 = *((char **)t13);
    t13 = (t1 + 32048);
    t19 = (t13 + 56U);
    t26 = *((char **)t19);
    memset(t7, 0, 8);
    xsi_vlog_signed_multiply(t7, 32, t18, 32, t26, 32);
    memset(t20, 0, 8);
    xsi_vlog_signed_less(t20, 32, t6, 32, t7, 32);
    t31 = (t20 + 4);
    t8 = *((unsigned int *)t31);
    t9 = (~(t8));
    t10 = *((unsigned int *)t20);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB37;

LAB38:    t4 = (t1 + 1424);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB46;

LAB47:
LAB48:    t4 = (t1 + 1696);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 & 4294967295U);
    if (t12 != 0)
        goto LAB74;

LAB75:    if (*((unsigned int *)t4) != 0)
        goto LAB76;

LAB77:    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB78;

LAB79:    memcpy(t27, t7, 8);

LAB80:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB88;

LAB89:
LAB90:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:    *((unsigned int *)t7) = 1;
    goto LAB9;

LAB8:    t6 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB10:    t18 = (t1 + 1424);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t7 + 4);
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
    t41 = (t7 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t7);
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

LAB20:    t61 = (t1 + 15272);
    xsi_vlogfile_write(1, 0, 0, ng20, 1, t61);
    goto LAB22;

LAB23:
LAB26:    t6 = (t1 + 26928);
    t13 = (t6 + 56U);
    t18 = *((char **)t13);
    t19 = ((char*)((ng21)));
    xsi_vlog_unsigned_equal(t62, 1024, t18, 1024, t19, 1024);
    t26 = (t62 + 4);
    t14 = *((unsigned int *)t26);
    t15 = (~(t14));
    t16 = *((unsigned int *)t62);
    t17 = (t16 & t15);
    t21 = (t17 != 0);
    if (t21 > 0)
        goto LAB27;

LAB28:
LAB31:    t4 = (t1 + 26928);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 32368);
    t18 = (t13 + 56U);
    t19 = *((char **)t18);
    xsi_vlog_bit_copy(t63, 0, t19, 0, 128);
    *((int *)t7) = xsi_vlogfile_sscanf(t6, 1024, ng23, 2, t1, (char)118, t63, 128);
    t26 = (t7 + 4);
    *((int *)t26) = 0;
    t31 = (t1 + 32368);
    xsi_vlogvar_assign_value(t31, t63, 0, 0, 128);
    t32 = (t1 + 32208);
    xsi_vlogvar_assign_value(t32, t7, 0, 0, 32);
    t4 = (t1 + 32208);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = ((char*)((ng4)));
    memset(t7, 0, 8);
    xsi_vlog_signed_equal(t7, 32, t6, 32, t13, 32);
    t18 = (t7 + 4);
    t8 = *((unsigned int *)t18);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB32;

LAB33:
LAB34:
LAB29:    goto LAB25;

LAB27:
LAB30:    t31 = ((char*)((ng0)));
    t32 = ((char*)((ng2)));
    t33 = (t1 + 15272);
    xsi_vlogfile_fwrite(*((unsigned int *)t31), 1, 0, 0, ng22, 2, t33, (char)118, t32, 128);
    xsi_vlog_finish(1);
    goto LAB29;

LAB32:
LAB35:    t19 = ((char*)((ng0)));
    t26 = ((char*)((ng25)));
    t31 = ((char*)((ng2)));
    t32 = ((char*)((ng26)));
    t33 = (t1 + 15272);
    xsi_vlogfile_fwrite(*((unsigned int *)t19), 1, 0, 0, ng24, 4, t33, (char)118, t26, 512, (char)118, t31, 128, (char)118, t32, 8);
    xsi_vlog_finish(1);
    goto LAB34;

LAB37:
LAB39:    t32 = (t1 + 31888);
    t33 = (t32 + 56U);
    t41 = *((char **)t33);
    t42 = ((char*)((ng9)));
    t55 = (t1 + 32368);
    t61 = (t55 + 56U);
    t64 = *((char **)t61);
    t65 = ((char*)((ng15)));
    t66 = ((char*)((ng15)));
    t67 = (t2 + 56U);
    t68 = *((char **)t67);
    t69 = (t2 + 56U);
    t70 = *((char **)t69);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t70, &&LAB40);
    t71 = (t2 + 56U);
    t72 = *((char **)t71);
    t73 = (t1 + 12680);
    t74 = xsi_create_subprogram_invocation(t72, 0, t1, t73, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t73, t74);
    t75 = (t1 + 28048);
    xsi_vlogvar_assign_value(t75, t41, 0, 0, 10);
    t76 = (t1 + 28208);
    xsi_vlogvar_assign_value(t76, t42, 0, 0, 1);
    t77 = (t1 + 28368);
    xsi_vlogvar_assign_value(t77, t64, 0, 0, 128);
    t78 = (t1 + 28528);
    xsi_vlogvar_assign_value(t78, t65, 0, 0, 1);
    t79 = (t1 + 28688);
    xsi_vlogvar_assign_value(t79, t66, 0, 0, 1);

LAB42:    t80 = (t2 + 64U);
    t81 = *((char **)t80);
    t82 = (t81 + 80U);
    t83 = *((char **)t82);
    t84 = (t83 + 272U);
    t85 = *((char **)t84);
    t86 = (t85 + 0U);
    t87 = *((char **)t86);
    t46 = ((int  (*)(char *, char *))t87)(t1, t81);
    if (t46 == -1)
        goto LAB43;

LAB44:    if (t46 != 0)
        goto LAB45;

LAB40:    t81 = (t1 + 12680);
    xsi_vlog_subprogram_popinvocation(t81);

LAB41:    t88 = (t2 + 64U);
    t89 = *((char **)t88);
    t88 = (t1 + 12680);
    t90 = (t2 + 56U);
    t91 = *((char **)t90);
    xsi_delete_subprogram_invocation(t88, t89, t1, t91, t2);
    t4 = (t1 + 31888);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 32048);
    t18 = (t13 + 56U);
    t19 = *((char **)t18);
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t6, 32, t19, 32);
    t26 = (t1 + 31888);
    xsi_vlogvar_assign_value(t26, t7, 0, 0, 32);
    goto LAB36;

LAB43:    t0 = -1;
    goto LAB1;

LAB45:    t80 = (t2 + 48U);
    *((char **)t80) = &&LAB42;
    goto LAB1;

LAB46:
LAB49:    t6 = (t1 + 27088);
    t13 = (t6 + 56U);
    t18 = *((char **)t13);
    t19 = ((char*)((ng27)));
    xsi_vlog_unsigned_equal(t92, 8184, t18, 8184, t19, 8184);
    t26 = (t92 + 4);
    t14 = *((unsigned int *)t26);
    t15 = (~(t14));
    t16 = *((unsigned int *)t92);
    t17 = (t16 & t15);
    t21 = (t17 != 0);
    if (t21 > 0)
        goto LAB50;

LAB51:
LAB54:    t4 = (t1 + 27088);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t7) = xsi_vlogfile_file_open_of_valname_ctype(t6, 8184, ng29);
    t13 = (t7 + 4);
    *((int *)t13) = 0;
    t18 = (t1 + 26288);
    xsi_vlogvar_assign_value(t18, t7, 0, 0, 32);
    t4 = (t1 + 26288);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = ((char*)((ng4)));
    memset(t7, 0, 8);
    xsi_vlog_signed_equal(t7, 32, t6, 32, t13, 32);
    t18 = (t7 + 4);
    t8 = *((unsigned int *)t18);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB55;

LAB56:
LAB59:    t4 = ((char*)((ng4)));
    t5 = (t1 + 31888);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB60:    t4 = (t1 + 31888);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 3600);
    t18 = *((char **)t13);
    t13 = (t1 + 32048);
    t19 = (t13 + 56U);
    t26 = *((char **)t19);
    memset(t7, 0, 8);
    xsi_vlog_signed_multiply(t7, 32, t18, 32, t26, 32);
    memset(t20, 0, 8);
    xsi_vlog_signed_less(t20, 32, t6, 32, t7, 32);
    t31 = (t20 + 4);
    t8 = *((unsigned int *)t31);
    t9 = (~(t8));
    t10 = *((unsigned int *)t20);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB61;

LAB62:    t4 = (t1 + 26288);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    xsi_vlogfile_fclose(*((unsigned int *)t6));

LAB57:
LAB52:    goto LAB48;

LAB50:
LAB53:    t31 = ((char*)((ng0)));
    t32 = ((char*)((ng2)));
    t33 = (t1 + 15272);
    xsi_vlogfile_fwrite(*((unsigned int *)t31), 1, 0, 0, ng28, 2, t33, (char)118, t32, 128);
    xsi_vlog_finish(1);
    goto LAB52;

LAB55:
LAB58:    t19 = ((char*)((ng0)));
    t26 = ((char*)((ng30)));
    t31 = ((char*)((ng2)));
    t32 = (t1 + 27088);
    t33 = (t32 + 56U);
    t41 = *((char **)t33);
    t42 = (t1 + 15272);
    xsi_vlogfile_fwrite(*((unsigned int *)t19), 1, 0, 0, ng24, 4, t42, (char)118, t26, 392, (char)118, t31, 128, (char)118, t41, 8184);
    xsi_vlog_finish(1);
    goto LAB57;

LAB61:
LAB63:    t32 = (t1 + 26288);
    t33 = (t32 + 56U);
    t41 = *((char **)t33);
    t42 = (t1 + 26448);
    t55 = (t42 + 56U);
    t61 = *((char **)t55);
    xsi_vlog_bit_copy(t63, 0, t61, 0, 128);
    *((int *)t27) = xsi_vlogfile_fscanf(*((unsigned int *)t41), ng31, 2, t1, (char)118, t63, 128);
    t64 = (t27 + 4);
    *((int *)t64) = 0;
    t65 = (t1 + 26448);
    xsi_vlogvar_assign_value(t65, t63, 0, 0, 128);
    t66 = (t1 + 32208);
    xsi_vlogvar_assign_value(t66, t27, 0, 0, 32);
    t4 = (t1 + 32208);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = ((char*)((ng4)));
    memset(t7, 0, 8);
    xsi_vlog_signed_greater(t7, 32, t6, 32, t13, 32);
    t18 = (t7 + 4);
    t8 = *((unsigned int *)t18);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB64;

LAB65:
LAB66:    t4 = (t1 + 31888);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 32048);
    t18 = (t13 + 56U);
    t19 = *((char **)t18);
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t6, 32, t19, 32);
    t26 = (t1 + 31888);
    xsi_vlogvar_assign_value(t26, t7, 0, 0, 32);
    goto LAB60;

LAB64:
LAB67:    t19 = (t1 + 31888);
    t26 = (t19 + 56U);
    t31 = *((char **)t26);
    t32 = ((char*)((ng9)));
    t33 = (t1 + 26448);
    t41 = (t33 + 56U);
    t42 = *((char **)t41);
    t55 = ((char*)((ng15)));
    t61 = ((char*)((ng15)));
    t64 = (t2 + 56U);
    t65 = *((char **)t64);
    t66 = (t2 + 56U);
    t67 = *((char **)t66);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t67, &&LAB68);
    t68 = (t2 + 56U);
    t69 = *((char **)t68);
    t70 = (t1 + 12680);
    t71 = xsi_create_subprogram_invocation(t69, 0, t1, t70, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t70, t71);
    t72 = (t1 + 28048);
    xsi_vlogvar_assign_value(t72, t31, 0, 0, 10);
    t73 = (t1 + 28208);
    xsi_vlogvar_assign_value(t73, t32, 0, 0, 1);
    t74 = (t1 + 28368);
    xsi_vlogvar_assign_value(t74, t42, 0, 0, 128);
    t75 = (t1 + 28528);
    xsi_vlogvar_assign_value(t75, t55, 0, 0, 1);
    t76 = (t1 + 28688);
    xsi_vlogvar_assign_value(t76, t61, 0, 0, 1);

LAB70:    t77 = (t2 + 64U);
    t78 = *((char **)t77);
    t79 = (t78 + 80U);
    t80 = *((char **)t79);
    t81 = (t80 + 272U);
    t82 = *((char **)t81);
    t83 = (t82 + 0U);
    t84 = *((char **)t83);
    t46 = ((int  (*)(char *, char *))t84)(t1, t78);
    if (t46 == -1)
        goto LAB71;

LAB72:    if (t46 != 0)
        goto LAB73;

LAB68:    t78 = (t1 + 12680);
    xsi_vlog_subprogram_popinvocation(t78);

LAB69:    t85 = (t2 + 64U);
    t86 = *((char **)t85);
    t85 = (t1 + 12680);
    t87 = (t2 + 56U);
    t88 = *((char **)t87);
    xsi_delete_subprogram_invocation(t85, t86, t1, t88, t2);
    goto LAB66;

LAB71:    t0 = -1;
    goto LAB1;

LAB73:    t77 = (t2 + 48U);
    *((char **)t77) = &&LAB70;
    goto LAB1;

LAB74:    *((unsigned int *)t7) = 1;
    goto LAB77;

LAB76:    t6 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB77;

LAB78:    t18 = (t1 + 1424);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB81;

LAB82:    if (*((unsigned int *)t18) != 0)
        goto LAB83;

LAB84:    t28 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t7 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB85;

LAB86:
LAB87:    goto LAB80;

LAB81:    *((unsigned int *)t20) = 1;
    goto LAB84;

LAB83:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB84;

LAB85:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t7 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t7);
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
    goto LAB87;

LAB88:    t61 = (t1 + 15272);
    xsi_vlogfile_write(1, 0, 0, ng32, 1, t61);
    goto LAB90;

}

static int sp_log2roundup(char *t1, char *t2)
{
    char t7[8];
    char t20[8];
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
    char *t18;
    char *t19;
    char *t21;

LAB0:    t0 = 1;

LAB2:    t3 = ((char*)((ng4)));
    t4 = (t1 + 32848);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    t3 = (t1 + 32528);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng3)));
    memset(t7, 0, 8);
    xsi_vlog_signed_greater(t7, 32, t5, 32, t6, 32);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB3;

LAB4:
LAB5:    t3 = (t1 + 32848);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 32688);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    t0 = 0;

LAB1:    return t0;
LAB3:
LAB6:    t14 = ((char*)((ng3)));
    t15 = (t1 + 33008);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 32);

LAB7:    t3 = (t1 + 33008);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 32528);
    t8 = (t6 + 56U);
    t14 = *((char **)t8);
    memset(t7, 0, 8);
    xsi_vlog_signed_less(t7, 32, t5, 32, t14, 32);
    t15 = (t7 + 4);
    t9 = *((unsigned int *)t15);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB8;

LAB9:    goto LAB5;

LAB8:
LAB10:    t16 = (t1 + 32848);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = ((char*)((ng3)));
    memset(t20, 0, 8);
    xsi_vlog_signed_add(t20, 32, t18, 32, t19, 32);
    t21 = (t1 + 32848);
    xsi_vlogvar_assign_value(t21, t20, 0, 0, 32);
    t3 = (t1 + 33008);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    memset(t7, 0, 8);
    xsi_vlog_signed_multiply(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 33008);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB7;

}

static int sp_collision_check(char *t1, char *t2)
{
    char t11[8];
    char t12[8];
    char t13[8];
    char t73[8];
    char t86[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
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
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
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
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    int t53;
    int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    char *t94;
    int t95;
    int t96;

LAB0:    t0 = 1;

LAB2:    t3 = ((char*)((ng4)));
    t4 = (t1 + 33968);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t3 = ((char*)((ng4)));
    t4 = (t1 + 34128);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t3 = ((char*)((ng4)));
    t4 = (t1 + 34288);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t3 = (t1 + 33168);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 3872);
    t8 = *((char **)t7);
    t7 = (t1 + 27728);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 10, t12, 32);
    t14 = (t1 + 34448);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33488);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 5776);
    t8 = *((char **)t7);
    t7 = (t1 + 27728);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 10, t12, 32);
    t14 = (t1 + 34608);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33168);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 3872);
    t8 = *((char **)t7);
    t7 = (t1 + 27408);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 10, t12, 32);
    t14 = (t1 + 34768);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33488);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 5776);
    t8 = *((char **)t7);
    t7 = (t1 + 27408);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 10, t12, 32);
    t14 = (t1 + 34928);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33168);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 3872);
    t8 = *((char **)t7);
    t7 = (t1 + 27888);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 10, t12, 32);
    t14 = (t1 + 35088);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33488);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 5776);
    t8 = *((char **)t7);
    t7 = (t1 + 27888);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 10, t12, 32);
    t14 = (t1 + 35248);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33168);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 3872);
    t8 = *((char **)t7);
    t7 = (t1 + 27568);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 10, t12, 32);
    t14 = (t1 + 35408);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33488);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 5776);
    t8 = *((char **)t7);
    t7 = (t1 + 27568);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 10, t12, 32);
    t14 = (t1 + 35568);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t11, 0, 8);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 & 4294967295U);
    if (t19 != 0)
        goto LAB3;

LAB4:    if (*((unsigned int *)t6) != 0)
        goto LAB5;

LAB6:    t8 = (t11 + 4);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t8);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB7;

LAB8:    memcpy(t13, t11, 8);

LAB9:    t61 = (t13 + 4);
    t62 = *((unsigned int *)t61);
    t63 = (~(t62));
    t64 = *((unsigned int *)t13);
    t65 = (t64 & t63);
    t66 = (t65 != 0);
    if (t66 > 0)
        goto LAB17;

LAB18:
LAB19:    t3 = (t1 + 33328);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB36;

LAB37:
LAB38:    t3 = (t1 + 33648);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB55;

LAB56:
LAB57:    t3 = (t1 + 33968);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 34128);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t15 = *((unsigned int *)t5);
    t16 = *((unsigned int *)t8);
    t17 = (t15 | t16);
    *((unsigned int *)t11) = t17;
    t9 = (t5 + 4);
    t10 = (t8 + 4);
    t14 = (t11 + 4);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    *((unsigned int *)t14) = t20;
    t21 = *((unsigned int *)t14);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB74;

LAB75:
LAB76:    t33 = (t1 + 34288);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t40 = *((unsigned int *)t11);
    t41 = *((unsigned int *)t35);
    t42 = (t40 | t41);
    *((unsigned int *)t12) = t42;
    t43 = (t11 + 4);
    t44 = (t35 + 4);
    t61 = (t12 + 4);
    t45 = *((unsigned int *)t43);
    t46 = *((unsigned int *)t44);
    t47 = (t45 | t46);
    *((unsigned int *)t61) = t47;
    t48 = *((unsigned int *)t61);
    t49 = (t48 != 0);
    if (t49 == 1)
        goto LAB77;

LAB78:
LAB79:    t69 = (t1 + 33808);
    xsi_vlogvar_assign_value(t69, t12, 0, 0, 32);
    t0 = 0;

LAB1:    return t0;
LAB3:    *((unsigned int *)t11) = 1;
    goto LAB6;

LAB5:    t7 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB6;

LAB7:    t9 = (t1 + 33648);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    memset(t12, 0, 8);
    t23 = (t14 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t14);
    t27 = (t26 & t25);
    t28 = (t27 & 4294967295U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) != 0)
        goto LAB12;

LAB13:    t30 = *((unsigned int *)t11);
    t31 = *((unsigned int *)t12);
    t32 = (t30 & t31);
    *((unsigned int *)t13) = t32;
    t33 = (t11 + 4);
    t34 = (t12 + 4);
    t35 = (t13 + 4);
    t36 = *((unsigned int *)t33);
    t37 = *((unsigned int *)t34);
    t38 = (t36 | t37);
    *((unsigned int *)t35) = t38;
    t39 = *((unsigned int *)t35);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB14;

LAB15:
LAB16:    goto LAB9;

LAB10:    *((unsigned int *)t12) = 1;
    goto LAB13;

LAB12:    t29 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB13;

LAB14:    t41 = *((unsigned int *)t13);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t13) = (t41 | t42);
    t43 = (t11 + 4);
    t44 = (t12 + 4);
    t45 = *((unsigned int *)t11);
    t46 = (~(t45));
    t47 = *((unsigned int *)t43);
    t48 = (~(t47));
    t49 = *((unsigned int *)t12);
    t50 = (~(t49));
    t51 = *((unsigned int *)t44);
    t52 = (~(t51));
    t53 = (t46 & t48);
    t54 = (t50 & t52);
    t55 = (~(t53));
    t56 = (~(t54));
    t57 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t57 & t55);
    t58 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t58 & t56);
    t59 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t59 & t55);
    t60 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t60 & t56);
    goto LAB16;

LAB17:
LAB20:    t67 = (t1 + 27408);
    t68 = (t67 + 56U);
    t69 = *((char **)t68);
    t70 = (t1 + 27728);
    t71 = (t70 + 56U);
    t72 = *((char **)t71);
    memset(t73, 0, 8);
    xsi_vlog_signed_greater(t73, 32, t69, 32, t72, 32);
    t74 = (t73 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t73);
    t78 = (t77 & t76);
    t79 = (t78 != 0);
    if (t79 > 0)
        goto LAB21;

LAB22:
LAB30:    t3 = (t1 + 34928);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 34768);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t11, 0, 8);
    xsi_vlog_signed_equal(t11, 32, t5, 32, t8, 32);
    t9 = (t11 + 4);
    t15 = *((unsigned int *)t9);
    t16 = (~(t15));
    t17 = *((unsigned int *)t11);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB31;

LAB32:
LAB35:    t3 = ((char*)((ng4)));
    t4 = (t1 + 33968);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB33:
LAB23:    goto LAB19;

LAB21:
LAB24:    t80 = (t1 + 34448);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    t83 = (t1 + 34608);
    t84 = (t83 + 56U);
    t85 = *((char **)t84);
    memset(t86, 0, 8);
    xsi_vlog_signed_equal(t86, 32, t82, 32, t85, 32);
    t87 = (t86 + 4);
    t88 = *((unsigned int *)t87);
    t89 = (~(t88));
    t90 = *((unsigned int *)t86);
    t91 = (t90 & t89);
    t92 = (t91 != 0);
    if (t92 > 0)
        goto LAB25;

LAB26:
LAB29:    t3 = ((char*)((ng4)));
    t4 = (t1 + 33968);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB27:    goto LAB23;

LAB25:
LAB28:    t93 = ((char*)((ng3)));
    t94 = (t1 + 33968);
    xsi_vlogvar_assign_value(t94, t93, 0, 0, 1);
    goto LAB27;

LAB31:
LAB34:    t10 = ((char*)((ng3)));
    t14 = (t1 + 33968);
    xsi_vlogvar_assign_value(t14, t10, 0, 0, 1);
    goto LAB33;

LAB36:
LAB39:    t7 = (t1 + 27408);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t1 + 27888);
    t14 = (t10 + 56U);
    t23 = *((char **)t14);
    memset(t11, 0, 8);
    xsi_vlog_signed_greater(t11, 32, t9, 32, t23, 32);
    t29 = (t11 + 4);
    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t11);
    t24 = (t22 & t21);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB40;

LAB41:
LAB49:    t3 = (t1 + 34928);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 34768);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t11, 0, 8);
    xsi_vlog_signed_equal(t11, 32, t5, 32, t8, 32);
    t9 = (t11 + 4);
    t15 = *((unsigned int *)t9);
    t16 = (~(t15));
    t17 = *((unsigned int *)t11);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB50;

LAB51:
LAB54:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34128);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB52:
LAB42:    goto LAB38;

LAB40:
LAB43:    t33 = (t1 + 35088);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t43 = (t1 + 35248);
    t44 = (t43 + 56U);
    t61 = *((char **)t44);
    memset(t12, 0, 8);
    xsi_vlog_signed_equal(t12, 32, t35, 32, t61, 32);
    t67 = (t12 + 4);
    t26 = *((unsigned int *)t67);
    t27 = (~(t26));
    t28 = *((unsigned int *)t12);
    t30 = (t28 & t27);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB44;

LAB45:
LAB48:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34128);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB46:    goto LAB42;

LAB44:
LAB47:    t68 = ((char*)((ng3)));
    t69 = (t1 + 34128);
    xsi_vlogvar_assign_value(t69, t68, 0, 0, 1);
    goto LAB46;

LAB50:
LAB53:    t10 = ((char*)((ng3)));
    t14 = (t1 + 34128);
    xsi_vlogvar_assign_value(t14, t10, 0, 0, 1);
    goto LAB52;

LAB55:
LAB58:    t7 = (t1 + 27568);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t1 + 27728);
    t14 = (t10 + 56U);
    t23 = *((char **)t14);
    memset(t11, 0, 8);
    xsi_vlog_signed_greater(t11, 32, t9, 32, t23, 32);
    t29 = (t11 + 4);
    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t11);
    t24 = (t22 & t21);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB59;

LAB60:
LAB68:    t3 = (t1 + 35568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 35408);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t11, 0, 8);
    xsi_vlog_signed_equal(t11, 32, t5, 32, t8, 32);
    t9 = (t11 + 4);
    t15 = *((unsigned int *)t9);
    t16 = (~(t15));
    t17 = *((unsigned int *)t11);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB69;

LAB70:
LAB73:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34288);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB71:
LAB61:    goto LAB57;

LAB59:
LAB62:    t33 = (t1 + 34448);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t43 = (t1 + 34608);
    t44 = (t43 + 56U);
    t61 = *((char **)t44);
    memset(t12, 0, 8);
    xsi_vlog_signed_equal(t12, 32, t35, 32, t61, 32);
    t67 = (t12 + 4);
    t26 = *((unsigned int *)t67);
    t27 = (~(t26));
    t28 = *((unsigned int *)t12);
    t30 = (t28 & t27);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB63;

LAB64:
LAB67:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34288);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB65:    goto LAB61;

LAB63:
LAB66:    t68 = ((char*)((ng3)));
    t69 = (t1 + 34288);
    xsi_vlogvar_assign_value(t69, t68, 0, 0, 1);
    goto LAB65;

LAB69:
LAB72:    t10 = ((char*)((ng3)));
    t14 = (t1 + 34288);
    xsi_vlogvar_assign_value(t14, t10, 0, 0, 1);
    goto LAB71;

LAB74:    t24 = *((unsigned int *)t11);
    t25 = *((unsigned int *)t14);
    *((unsigned int *)t11) = (t24 | t25);
    t23 = (t5 + 4);
    t29 = (t8 + 4);
    t26 = *((unsigned int *)t23);
    t27 = (~(t26));
    t28 = *((unsigned int *)t5);
    t53 = (t28 & t27);
    t30 = *((unsigned int *)t29);
    t31 = (~(t30));
    t32 = *((unsigned int *)t8);
    t54 = (t32 & t31);
    t36 = (~(t53));
    t37 = (~(t54));
    t38 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t38 & t36);
    t39 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t39 & t37);
    goto LAB76;

LAB77:    t50 = *((unsigned int *)t12);
    t51 = *((unsigned int *)t61);
    *((unsigned int *)t12) = (t50 | t51);
    t67 = (t11 + 4);
    t68 = (t35 + 4);
    t52 = *((unsigned int *)t67);
    t55 = (~(t52));
    t56 = *((unsigned int *)t11);
    t95 = (t56 & t55);
    t57 = *((unsigned int *)t68);
    t58 = (~(t57));
    t59 = *((unsigned int *)t35);
    t96 = (t59 & t58);
    t60 = (~(t95));
    t62 = (~(t96));
    t63 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t63 & t60);
    t64 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t64 & t62);
    goto LAB79;

}

static void Cont_2330_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t7[8];
    char t21[8];
    char t22[8];
    char t30[8];
    char t62[8];
    char t77[8];
    char t78[8];
    char t86[8];
    char t127[8];
    char *t1;
    char *t2;
    char *t5;
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
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
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
    int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    char *t126;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    unsigned int t140;
    unsigned int t141;
    char *t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;

LAB0:    t1 = (t0 + 36480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 880);
    t5 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_equal(t6, 32, t5, 32, t2, 32);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB7:    t15 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB8;

LAB9:    memcpy(t30, t7, 8);

LAB10:    memset(t62, 0, 8);
    t63 = (t30 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t30);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t63) != 0)
        goto LAB20;

LAB21:    t70 = (t62 + 4);
    t71 = *((unsigned int *)t62);
    t72 = (!(t71));
    t73 = *((unsigned int *)t70);
    t74 = (t72 || t73);
    if (t74 > 0)
        goto LAB22;

LAB23:    memcpy(t86, t62, 8);

LAB24:    memset(t4, 0, 8);
    t114 = (t86 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t86);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t114) != 0)
        goto LAB34;

LAB35:    t121 = (t4 + 4);
    t122 = *((unsigned int *)t4);
    t123 = *((unsigned int *)t121);
    t124 = (t122 || t123);
    if (t124 > 0)
        goto LAB36;

LAB37:    t128 = *((unsigned int *)t4);
    t129 = (~(t128));
    t130 = *((unsigned int *)t121);
    t131 = (t129 || t130);
    if (t131 > 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t121) > 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t4) > 0)
        goto LAB42;

LAB43:    memcpy(t3, t125, 8);

LAB44:    t132 = (t0 + 41040);
    t133 = (t132 + 56U);
    t134 = *((char **)t133);
    t135 = (t134 + 56U);
    t136 = *((char **)t135);
    memset(t136, 0, 8);
    t137 = 1U;
    t138 = t137;
    t139 = (t3 + 4);
    t140 = *((unsigned int *)t3);
    t137 = (t137 & t140);
    t141 = *((unsigned int *)t139);
    t138 = (t138 & t141);
    t142 = (t136 + 4);
    t143 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t143 | t137);
    t144 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t144 | t138);
    xsi_driver_vfirst_trans(t132, 0, 0);
    t145 = (t0 + 40768);
    *((int *)t145) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB6:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB7;

LAB8:    t19 = (t0 + 7000);
    t20 = *((char **)t19);
    t19 = ((char*)((ng3)));
    memset(t21, 0, 8);
    xsi_vlog_signed_equal(t21, 32, t20, 32, t19, 32);
    memset(t22, 0, 8);
    t23 = (t21 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t21);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t23) != 0)
        goto LAB13;

LAB14:    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t22);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t34 = (t7 + 4);
    t35 = (t22 + 4);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t34);
    t38 = *((unsigned int *)t35);
    t39 = (t37 | t38);
    *((unsigned int *)t36) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t22) = 1;
    goto LAB14;

LAB13:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB14;

LAB15:    t42 = *((unsigned int *)t30);
    t43 = *((unsigned int *)t36);
    *((unsigned int *)t30) = (t42 | t43);
    t44 = (t7 + 4);
    t45 = (t22 + 4);
    t46 = *((unsigned int *)t7);
    t47 = (~(t46));
    t48 = *((unsigned int *)t44);
    t49 = (~(t48));
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t45);
    t53 = (~(t52));
    t54 = (t47 & t49);
    t55 = (t51 & t53);
    t56 = (~(t54));
    t57 = (~(t55));
    t58 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t58 & t56);
    t59 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t59 & t57);
    t60 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t60 & t56);
    t61 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t61 & t57);
    goto LAB17;

LAB18:    *((unsigned int *)t62) = 1;
    goto LAB21;

LAB20:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB21;

LAB22:    t75 = (t0 + 6864);
    t76 = *((char **)t75);
    t75 = ((char*)((ng3)));
    memset(t77, 0, 8);
    xsi_vlog_signed_equal(t77, 32, t76, 32, t75, 32);
    memset(t78, 0, 8);
    t79 = (t77 + 4);
    t80 = *((unsigned int *)t79);
    t81 = (~(t80));
    t82 = *((unsigned int *)t77);
    t83 = (t82 & t81);
    t84 = (t83 & 1U);
    if (t84 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t79) != 0)
        goto LAB27;

LAB28:    t87 = *((unsigned int *)t62);
    t88 = *((unsigned int *)t78);
    t89 = (t87 | t88);
    *((unsigned int *)t86) = t89;
    t90 = (t62 + 4);
    t91 = (t78 + 4);
    t92 = (t86 + 4);
    t93 = *((unsigned int *)t90);
    t94 = *((unsigned int *)t91);
    t95 = (t93 | t94);
    *((unsigned int *)t92) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 != 0);
    if (t97 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t78) = 1;
    goto LAB28;

LAB27:    t85 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t85) = 1;
    goto LAB28;

LAB29:    t98 = *((unsigned int *)t86);
    t99 = *((unsigned int *)t92);
    *((unsigned int *)t86) = (t98 | t99);
    t100 = (t62 + 4);
    t101 = (t78 + 4);
    t102 = *((unsigned int *)t100);
    t103 = (~(t102));
    t104 = *((unsigned int *)t62);
    t105 = (t104 & t103);
    t106 = *((unsigned int *)t101);
    t107 = (~(t106));
    t108 = *((unsigned int *)t78);
    t109 = (t108 & t107);
    t110 = (~(t105));
    t111 = (~(t109));
    t112 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t112 & t110);
    t113 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t113 & t111);
    goto LAB31;

LAB32:    *((unsigned int *)t4) = 1;
    goto LAB35;

LAB34:    t120 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB35;

LAB36:    t125 = (t0 + 20128U);
    t126 = *((char **)t125);
    memcpy(t127, t126, 8);
    goto LAB37;

LAB38:    t125 = ((char*)((ng4)));
    goto LAB39;

LAB40:    xsi_vlog_unsigned_bit_combine(t3, 32, t127, 32, t125, 32);
    goto LAB44;

LAB42:    memcpy(t3, t127, 8);
    goto LAB44;

}

static void Cont_2331_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t7[8];
    char t21[8];
    char t22[8];
    char t30[8];
    char t62[8];
    char t77[8];
    char t78[8];
    char t86[8];
    char t127[8];
    char *t1;
    char *t2;
    char *t5;
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
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
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
    int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    char *t126;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    unsigned int t140;
    unsigned int t141;
    char *t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;

LAB0:    t1 = (t0 + 36728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 880);
    t5 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_equal(t6, 32, t5, 32, t2, 32);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB7:    t15 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB8;

LAB9:    memcpy(t30, t7, 8);

LAB10:    memset(t62, 0, 8);
    t63 = (t30 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t30);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t63) != 0)
        goto LAB20;

LAB21:    t70 = (t62 + 4);
    t71 = *((unsigned int *)t62);
    t72 = (!(t71));
    t73 = *((unsigned int *)t70);
    t74 = (t72 || t73);
    if (t74 > 0)
        goto LAB22;

LAB23:    memcpy(t86, t62, 8);

LAB24:    memset(t4, 0, 8);
    t114 = (t86 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t86);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t114) != 0)
        goto LAB34;

LAB35:    t121 = (t4 + 4);
    t122 = *((unsigned int *)t4);
    t123 = *((unsigned int *)t121);
    t124 = (t122 || t123);
    if (t124 > 0)
        goto LAB36;

LAB37:    t128 = *((unsigned int *)t4);
    t129 = (~(t128));
    t130 = *((unsigned int *)t121);
    t131 = (t129 || t130);
    if (t131 > 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t121) > 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t4) > 0)
        goto LAB42;

LAB43:    memcpy(t3, t125, 8);

LAB44:    t132 = (t0 + 41104);
    t133 = (t132 + 56U);
    t134 = *((char **)t133);
    t135 = (t134 + 56U);
    t136 = *((char **)t135);
    memset(t136, 0, 8);
    t137 = 1U;
    t138 = t137;
    t139 = (t3 + 4);
    t140 = *((unsigned int *)t3);
    t137 = (t137 & t140);
    t141 = *((unsigned int *)t139);
    t138 = (t138 & t141);
    t142 = (t136 + 4);
    t143 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t143 | t137);
    t144 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t144 | t138);
    xsi_driver_vfirst_trans(t132, 0, 0);
    t145 = (t0 + 40784);
    *((int *)t145) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB6:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB7;

LAB8:    t19 = (t0 + 7000);
    t20 = *((char **)t19);
    t19 = ((char*)((ng3)));
    memset(t21, 0, 8);
    xsi_vlog_signed_equal(t21, 32, t20, 32, t19, 32);
    memset(t22, 0, 8);
    t23 = (t21 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t21);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t23) != 0)
        goto LAB13;

LAB14:    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t22);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t34 = (t7 + 4);
    t35 = (t22 + 4);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t34);
    t38 = *((unsigned int *)t35);
    t39 = (t37 | t38);
    *((unsigned int *)t36) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t22) = 1;
    goto LAB14;

LAB13:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB14;

LAB15:    t42 = *((unsigned int *)t30);
    t43 = *((unsigned int *)t36);
    *((unsigned int *)t30) = (t42 | t43);
    t44 = (t7 + 4);
    t45 = (t22 + 4);
    t46 = *((unsigned int *)t7);
    t47 = (~(t46));
    t48 = *((unsigned int *)t44);
    t49 = (~(t48));
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t45);
    t53 = (~(t52));
    t54 = (t47 & t49);
    t55 = (t51 & t53);
    t56 = (~(t54));
    t57 = (~(t55));
    t58 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t58 & t56);
    t59 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t59 & t57);
    t60 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t60 & t56);
    t61 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t61 & t57);
    goto LAB17;

LAB18:    *((unsigned int *)t62) = 1;
    goto LAB21;

LAB20:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB21;

LAB22:    t75 = (t0 + 6864);
    t76 = *((char **)t75);
    t75 = ((char*)((ng3)));
    memset(t77, 0, 8);
    xsi_vlog_signed_equal(t77, 32, t76, 32, t75, 32);
    memset(t78, 0, 8);
    t79 = (t77 + 4);
    t80 = *((unsigned int *)t79);
    t81 = (~(t80));
    t82 = *((unsigned int *)t77);
    t83 = (t82 & t81);
    t84 = (t83 & 1U);
    if (t84 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t79) != 0)
        goto LAB27;

LAB28:    t87 = *((unsigned int *)t62);
    t88 = *((unsigned int *)t78);
    t89 = (t87 | t88);
    *((unsigned int *)t86) = t89;
    t90 = (t62 + 4);
    t91 = (t78 + 4);
    t92 = (t86 + 4);
    t93 = *((unsigned int *)t90);
    t94 = *((unsigned int *)t91);
    t95 = (t93 | t94);
    *((unsigned int *)t92) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 != 0);
    if (t97 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t78) = 1;
    goto LAB28;

LAB27:    t85 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t85) = 1;
    goto LAB28;

LAB29:    t98 = *((unsigned int *)t86);
    t99 = *((unsigned int *)t92);
    *((unsigned int *)t86) = (t98 | t99);
    t100 = (t62 + 4);
    t101 = (t78 + 4);
    t102 = *((unsigned int *)t100);
    t103 = (~(t102));
    t104 = *((unsigned int *)t62);
    t105 = (t104 & t103);
    t106 = *((unsigned int *)t101);
    t107 = (~(t106));
    t108 = *((unsigned int *)t78);
    t109 = (t108 & t107);
    t110 = (~(t105));
    t111 = (~(t109));
    t112 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t112 & t110);
    t113 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t113 & t111);
    goto LAB31;

LAB32:    *((unsigned int *)t4) = 1;
    goto LAB35;

LAB34:    t120 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB35;

LAB36:    t125 = (t0 + 20288U);
    t126 = *((char **)t125);
    memcpy(t127, t126, 8);
    goto LAB37;

LAB38:    t125 = ((char*)((ng4)));
    goto LAB39;

LAB40:    xsi_vlog_unsigned_bit_combine(t3, 32, t127, 32, t125, 32);
    goto LAB44;

LAB42:    memcpy(t3, t127, 8);
    goto LAB44;

}

static void Cont_2332_2(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[16];
    char t7[8];
    char t21[8];
    char t22[8];
    char t30[8];
    char t62[8];
    char t76[8];
    char t77[8];
    char t85[8];
    char t117[8];
    char t132[8];
    char t133[8];
    char t141[8];
    char t182[8];
    char *t1;
    char *t2;
    char *t5;
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
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    char *t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    char *t124;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    char *t130;
    char *t131;
    char *t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    char *t140;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;
    char *t146;
    char *t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    char *t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    char *t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    char *t175;
    char *t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    char *t180;
    char *t181;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    char *t187;
    char *t188;
    char *t189;
    char *t190;
    char *t191;
    unsigned int t192;
    unsigned int t193;
    char *t194;
    unsigned int t195;
    unsigned int t196;
    char *t197;
    unsigned int t198;
    unsigned int t199;
    char *t200;

LAB0:    t1 = (t0 + 36976U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng11)));
    t5 = ((char*)((ng11)));
    xsi_vlog_unsigned_equal(t6, 56, t2, 56, t5, 56);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB7:    t15 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB8;

LAB9:    memcpy(t30, t7, 8);

LAB10:    memset(t62, 0, 8);
    t63 = (t30 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t30);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t63) != 0)
        goto LAB20;

LAB21:    t70 = (t62 + 4);
    t71 = *((unsigned int *)t62);
    t72 = *((unsigned int *)t70);
    t73 = (t71 || t72);
    if (t73 > 0)
        goto LAB22;

LAB23:    memcpy(t85, t62, 8);

LAB24:    memset(t117, 0, 8);
    t118 = (t85 + 4);
    t119 = *((unsigned int *)t118);
    t120 = (~(t119));
    t121 = *((unsigned int *)t85);
    t122 = (t121 & t120);
    t123 = (t122 & 1U);
    if (t123 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t118) != 0)
        goto LAB34;

LAB35:    t125 = (t117 + 4);
    t126 = *((unsigned int *)t117);
    t127 = (!(t126));
    t128 = *((unsigned int *)t125);
    t129 = (t127 || t128);
    if (t129 > 0)
        goto LAB36;

LAB37:    memcpy(t141, t117, 8);

LAB38:    memset(t4, 0, 8);
    t169 = (t141 + 4);
    t170 = *((unsigned int *)t169);
    t171 = (~(t170));
    t172 = *((unsigned int *)t141);
    t173 = (t172 & t171);
    t174 = (t173 & 1U);
    if (t174 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t169) != 0)
        goto LAB48;

LAB49:    t176 = (t4 + 4);
    t177 = *((unsigned int *)t4);
    t178 = *((unsigned int *)t176);
    t179 = (t177 || t178);
    if (t179 > 0)
        goto LAB50;

LAB51:    t183 = *((unsigned int *)t4);
    t184 = (~(t183));
    t185 = *((unsigned int *)t176);
    t186 = (t184 || t185);
    if (t186 > 0)
        goto LAB52;

LAB53:    if (*((unsigned int *)t176) > 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t4) > 0)
        goto LAB56;

LAB57:    memcpy(t3, t180, 8);

LAB58:    t187 = (t0 + 41168);
    t188 = (t187 + 56U);
    t189 = *((char **)t188);
    t190 = (t189 + 56U);
    t191 = *((char **)t190);
    memset(t191, 0, 8);
    t192 = 1023U;
    t193 = t192;
    t194 = (t3 + 4);
    t195 = *((unsigned int *)t3);
    t192 = (t192 & t195);
    t196 = *((unsigned int *)t194);
    t193 = (t193 & t196);
    t197 = (t191 + 4);
    t198 = *((unsigned int *)t191);
    *((unsigned int *)t191) = (t198 | t192);
    t199 = *((unsigned int *)t197);
    *((unsigned int *)t197) = (t199 | t193);
    xsi_driver_vfirst_trans(t187, 0, 9);
    t200 = (t0 + 40800);
    *((int *)t200) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB6:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB7;

LAB8:    t19 = (t0 + 880);
    t20 = *((char **)t19);
    t19 = ((char*)((ng3)));
    memset(t21, 0, 8);
    xsi_vlog_signed_equal(t21, 32, t20, 32, t19, 32);
    memset(t22, 0, 8);
    t23 = (t21 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t21);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t23) != 0)
        goto LAB13;

LAB14:    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t22);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t34 = (t7 + 4);
    t35 = (t22 + 4);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t34);
    t38 = *((unsigned int *)t35);
    t39 = (t37 | t38);
    *((unsigned int *)t36) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t22) = 1;
    goto LAB14;

LAB13:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB14;

LAB15:    t42 = *((unsigned int *)t30);
    t43 = *((unsigned int *)t36);
    *((unsigned int *)t30) = (t42 | t43);
    t44 = (t7 + 4);
    t45 = (t22 + 4);
    t46 = *((unsigned int *)t7);
    t47 = (~(t46));
    t48 = *((unsigned int *)t44);
    t49 = (~(t48));
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t45);
    t53 = (~(t52));
    t54 = (t47 & t49);
    t55 = (t51 & t53);
    t56 = (~(t54));
    t57 = (~(t55));
    t58 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t58 & t56);
    t59 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t59 & t57);
    t60 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t60 & t56);
    t61 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t61 & t57);
    goto LAB17;

LAB18:    *((unsigned int *)t62) = 1;
    goto LAB21;

LAB20:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB21;

LAB22:    t74 = (t0 + 7000);
    t75 = *((char **)t74);
    t74 = ((char*)((ng3)));
    memset(t76, 0, 8);
    xsi_vlog_signed_equal(t76, 32, t75, 32, t74, 32);
    memset(t77, 0, 8);
    t78 = (t76 + 4);
    t79 = *((unsigned int *)t78);
    t80 = (~(t79));
    t81 = *((unsigned int *)t76);
    t82 = (t81 & t80);
    t83 = (t82 & 1U);
    if (t83 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t78) != 0)
        goto LAB27;

LAB28:    t86 = *((unsigned int *)t62);
    t87 = *((unsigned int *)t77);
    t88 = (t86 & t87);
    *((unsigned int *)t85) = t88;
    t89 = (t62 + 4);
    t90 = (t77 + 4);
    t91 = (t85 + 4);
    t92 = *((unsigned int *)t89);
    t93 = *((unsigned int *)t90);
    t94 = (t92 | t93);
    *((unsigned int *)t91) = t94;
    t95 = *((unsigned int *)t91);
    t96 = (t95 != 0);
    if (t96 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t77) = 1;
    goto LAB28;

LAB27:    t84 = (t77 + 4);
    *((unsigned int *)t77) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB28;

LAB29:    t97 = *((unsigned int *)t85);
    t98 = *((unsigned int *)t91);
    *((unsigned int *)t85) = (t97 | t98);
    t99 = (t62 + 4);
    t100 = (t77 + 4);
    t101 = *((unsigned int *)t62);
    t102 = (~(t101));
    t103 = *((unsigned int *)t99);
    t104 = (~(t103));
    t105 = *((unsigned int *)t77);
    t106 = (~(t105));
    t107 = *((unsigned int *)t100);
    t108 = (~(t107));
    t109 = (t102 & t104);
    t110 = (t106 & t108);
    t111 = (~(t109));
    t112 = (~(t110));
    t113 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t113 & t111);
    t114 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t114 & t112);
    t115 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t115 & t111);
    t116 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t116 & t112);
    goto LAB31;

LAB32:    *((unsigned int *)t117) = 1;
    goto LAB35;

LAB34:    t124 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t124) = 1;
    goto LAB35;

LAB36:    t130 = (t0 + 6864);
    t131 = *((char **)t130);
    t130 = ((char*)((ng3)));
    memset(t132, 0, 8);
    xsi_vlog_signed_equal(t132, 32, t131, 32, t130, 32);
    memset(t133, 0, 8);
    t134 = (t132 + 4);
    t135 = *((unsigned int *)t134);
    t136 = (~(t135));
    t137 = *((unsigned int *)t132);
    t138 = (t137 & t136);
    t139 = (t138 & 1U);
    if (t139 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t134) != 0)
        goto LAB41;

LAB42:    t142 = *((unsigned int *)t117);
    t143 = *((unsigned int *)t133);
    t144 = (t142 | t143);
    *((unsigned int *)t141) = t144;
    t145 = (t117 + 4);
    t146 = (t133 + 4);
    t147 = (t141 + 4);
    t148 = *((unsigned int *)t145);
    t149 = *((unsigned int *)t146);
    t150 = (t148 | t149);
    *((unsigned int *)t147) = t150;
    t151 = *((unsigned int *)t147);
    t152 = (t151 != 0);
    if (t152 == 1)
        goto LAB43;

LAB44:
LAB45:    goto LAB38;

LAB39:    *((unsigned int *)t133) = 1;
    goto LAB42;

LAB41:    t140 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t140) = 1;
    goto LAB42;

LAB43:    t153 = *((unsigned int *)t141);
    t154 = *((unsigned int *)t147);
    *((unsigned int *)t141) = (t153 | t154);
    t155 = (t117 + 4);
    t156 = (t133 + 4);
    t157 = *((unsigned int *)t155);
    t158 = (~(t157));
    t159 = *((unsigned int *)t117);
    t160 = (t159 & t158);
    t161 = *((unsigned int *)t156);
    t162 = (~(t161));
    t163 = *((unsigned int *)t133);
    t164 = (t163 & t162);
    t165 = (~(t160));
    t166 = (~(t164));
    t167 = *((unsigned int *)t147);
    *((unsigned int *)t147) = (t167 & t165);
    t168 = *((unsigned int *)t147);
    *((unsigned int *)t147) = (t168 & t166);
    goto LAB45;

LAB46:    *((unsigned int *)t4) = 1;
    goto LAB49;

LAB48:    t175 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t175) = 1;
    goto LAB49;

LAB50:    t180 = (t0 + 21088U);
    t181 = *((char **)t180);
    memcpy(t182, t181, 8);
    goto LAB51;

LAB52:    t180 = ((char*)((ng4)));
    goto LAB53;

LAB54:    xsi_vlog_unsigned_bit_combine(t3, 32, t182, 32, t180, 32);
    goto LAB58;

LAB56:    memcpy(t3, t182, 8);
    goto LAB58;

}

static void Cont_2336_3(char *t0)
{
    char t4[8];
    char t5[8];
    char t20[8];
    char t27[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;

LAB0:    t1 = (t0 + 37224U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2648);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t3, 32, t2, 32);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    memcpy(t27, t5, 8);

LAB10:    t55 = (t0 + 41232);
    t56 = (t55 + 56U);
    t57 = *((char **)t56);
    t58 = (t57 + 56U);
    t59 = *((char **)t58);
    memset(t59, 0, 8);
    t60 = 1U;
    t61 = t60;
    t62 = (t27 + 4);
    t63 = *((unsigned int *)t27);
    t60 = (t60 & t63);
    t64 = *((unsigned int *)t62);
    t61 = (t61 & t64);
    t65 = (t59 + 4);
    t66 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t66 | t60);
    t67 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t67 | t61);
    xsi_driver_vfirst_trans(t55, 0, 0);
    t68 = (t0 + 40816);
    *((int *)t68) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 17088U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t18) != 0)
        goto LAB13;

LAB14:    t28 = *((unsigned int *)t5);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t5 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t20) = 1;
    goto LAB14;

LAB13:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB14;

LAB15:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t5 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t5);
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
    goto LAB17;

}

static void Cont_2337_4(char *t0)
{
    char t4[8];
    char t5[8];
    char t20[8];
    char t27[8];
    char t55[8];
    char t68[8];
    char t76[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
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
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    int t100;
    int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    char *t108;
    char *t109;
    char *t110;
    char *t111;
    char *t112;
    unsigned int t113;
    unsigned int t114;
    char *t115;
    unsigned int t116;
    unsigned int t117;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;

LAB0:    t1 = (t0 + 37472U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4552);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t3, 32, t2, 32);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    memcpy(t27, t5, 8);

LAB10:    memset(t55, 0, 8);
    t56 = (t27 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t27);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t56) != 0)
        goto LAB20;

LAB21:    t63 = (t55 + 4);
    t64 = *((unsigned int *)t55);
    t65 = *((unsigned int *)t63);
    t66 = (t64 || t65);
    if (t66 > 0)
        goto LAB22;

LAB23:    memcpy(t76, t55, 8);

LAB24:    t108 = (t0 + 41296);
    t109 = (t108 + 56U);
    t110 = *((char **)t109);
    t111 = (t110 + 56U);
    t112 = *((char **)t111);
    memset(t112, 0, 8);
    t113 = 1U;
    t114 = t113;
    t115 = (t76 + 4);
    t116 = *((unsigned int *)t76);
    t113 = (t113 & t116);
    t117 = *((unsigned int *)t115);
    t114 = (t114 & t117);
    t118 = (t112 + 4);
    t119 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t119 | t113);
    t120 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t120 | t114);
    xsi_driver_vfirst_trans(t108, 0, 0);
    t121 = (t0 + 40832);
    *((int *)t121) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 18368U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t18) != 0)
        goto LAB13;

LAB14:    t28 = *((unsigned int *)t5);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t5 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t20) = 1;
    goto LAB14;

LAB13:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB14;

LAB15:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t5 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t5);
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
    goto LAB17;

LAB18:    *((unsigned int *)t55) = 1;
    goto LAB21;

LAB20:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB21;

LAB22:    t67 = ((char*)((ng9)));
    memset(t68, 0, 8);
    t69 = (t67 + 4);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t67);
    t73 = (t72 & t71);
    t74 = (t73 & 1U);
    if (t74 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t69) != 0)
        goto LAB27;

LAB28:    t77 = *((unsigned int *)t55);
    t78 = *((unsigned int *)t68);
    t79 = (t77 & t78);
    *((unsigned int *)t76) = t79;
    t80 = (t55 + 4);
    t81 = (t68 + 4);
    t82 = (t76 + 4);
    t83 = *((unsigned int *)t80);
    t84 = *((unsigned int *)t81);
    t85 = (t83 | t84);
    *((unsigned int *)t82) = t85;
    t86 = *((unsigned int *)t82);
    t87 = (t86 != 0);
    if (t87 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t68) = 1;
    goto LAB28;

LAB27:    t75 = (t68 + 4);
    *((unsigned int *)t68) = 1;
    *((unsigned int *)t75) = 1;
    goto LAB28;

LAB29:    t88 = *((unsigned int *)t76);
    t89 = *((unsigned int *)t82);
    *((unsigned int *)t76) = (t88 | t89);
    t90 = (t55 + 4);
    t91 = (t68 + 4);
    t92 = *((unsigned int *)t55);
    t93 = (~(t92));
    t94 = *((unsigned int *)t90);
    t95 = (~(t94));
    t96 = *((unsigned int *)t68);
    t97 = (~(t96));
    t98 = *((unsigned int *)t91);
    t99 = (~(t98));
    t100 = (t93 & t95);
    t101 = (t97 & t99);
    t102 = (~(t100));
    t103 = (~(t101));
    t104 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t104 & t102);
    t105 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t105 & t103);
    t106 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t106 & t102);
    t107 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t107 & t103);
    goto LAB31;

}

static void Cont_2338_5(char *t0)
{
    char t3[8];
    char t4[8];
    char t5[8];
    char t19[8];
    char t26[8];
    char t71[8];
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
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
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
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;

LAB0:    t1 = (t0 + 37720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng9)));
    memset(t5, 0, 8);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t2);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t26, t5, 8);

LAB10:    memset(t4, 0, 8);
    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 & 1U);
    if (t63 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t58) != 0)
        goto LAB20;

LAB21:    t65 = (t4 + 4);
    t66 = *((unsigned int *)t4);
    t67 = *((unsigned int *)t65);
    t68 = (t66 || t67);
    if (t68 > 0)
        goto LAB22;

LAB23:    t72 = *((unsigned int *)t4);
    t73 = (~(t72));
    t74 = *((unsigned int *)t65);
    t75 = (t73 || t74);
    if (t75 > 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t65) > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t4) > 0)
        goto LAB28;

LAB29:    memcpy(t3, t69, 8);

LAB30:    t76 = (t0 + 41360);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    t79 = (t78 + 56U);
    t80 = *((char **)t79);
    memset(t80, 0, 8);
    t81 = 1U;
    t82 = t81;
    t83 = (t3 + 4);
    t84 = *((unsigned int *)t3);
    t81 = (t81 & t84);
    t85 = *((unsigned int *)t83);
    t82 = (t82 & t85);
    t86 = (t80 + 4);
    t87 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t87 | t81);
    t88 = *((unsigned int *)t86);
    *((unsigned int *)t86) = (t88 | t82);
    xsi_driver_vfirst_trans(t76, 0, 0);
    t89 = (t0 + 40848);
    *((int *)t89) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 21248U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB13:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB14;

LAB15:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t5);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB17;

LAB18:    *((unsigned int *)t4) = 1;
    goto LAB21;

LAB20:    t64 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB21;

LAB22:    t69 = (t0 + 17408U);
    t70 = *((char **)t69);
    memcpy(t71, t70, 8);
    goto LAB23;

LAB24:    t69 = ((char*)((ng15)));
    goto LAB25;

LAB26:    xsi_vlog_unsigned_bit_combine(t3, 32, t71, 32, t69, 32);
    goto LAB30;

LAB28:    memcpy(t3, t71, 8);
    goto LAB30;

}

static void Cont_2339_6(char *t0)
{
    char t3[8];
    char t4[8];
    char t5[8];
    char t19[8];
    char t26[8];
    char t71[8];
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
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
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
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;

LAB0:    t1 = (t0 + 37968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng15)));
    memset(t5, 0, 8);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t2);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t26, t5, 8);

LAB10:    memset(t4, 0, 8);
    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 & 1U);
    if (t63 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t58) != 0)
        goto LAB20;

LAB21:    t65 = (t4 + 4);
    t66 = *((unsigned int *)t4);
    t67 = *((unsigned int *)t65);
    t68 = (t66 || t67);
    if (t68 > 0)
        goto LAB22;

LAB23:    t72 = *((unsigned int *)t4);
    t73 = (~(t72));
    t74 = *((unsigned int *)t65);
    t75 = (t73 || t74);
    if (t75 > 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t65) > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t4) > 0)
        goto LAB28;

LAB29:    memcpy(t3, t69, 8);

LAB30:    t76 = (t0 + 41424);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    t79 = (t78 + 56U);
    t80 = *((char **)t79);
    memset(t80, 0, 8);
    t81 = 1U;
    t82 = t81;
    t83 = (t3 + 4);
    t84 = *((unsigned int *)t3);
    t81 = (t81 & t84);
    t85 = *((unsigned int *)t83);
    t82 = (t82 & t85);
    t86 = (t80 + 4);
    t87 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t87 | t81);
    t88 = *((unsigned int *)t86);
    *((unsigned int *)t86) = (t88 | t82);
    xsi_driver_vfirst_trans(t76, 0, 0);
    t89 = (t0 + 40864);
    *((int *)t89) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 21408U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB13:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB14;

LAB15:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t5);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB17;

LAB18:    *((unsigned int *)t4) = 1;
    goto LAB21;

LAB20:    t64 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB21;

LAB22:    t69 = (t0 + 18688U);
    t70 = *((char **)t69);
    memcpy(t71, t70, 8);
    goto LAB23;

LAB24:    t69 = ((char*)((ng15)));
    goto LAB25;

LAB26:    xsi_vlog_unsigned_bit_combine(t3, 32, t71, 32, t69, 32);
    goto LAB30;

LAB28:    memcpy(t3, t71, 8);
    goto LAB30;

}

static void Cont_2340_7(char *t0)
{
    char t3[8];
    char t4[8];
    char t18[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 38216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng15)));
    memset(t4, 0, 8);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t2);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t5) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t19 = *((unsigned int *)t4);
    t20 = (~(t19));
    t21 = *((unsigned int *)t12);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t16, 8);

LAB16:    t23 = (t0 + 41488);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0);
    t36 = (t0 + 40880);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 21248U);
    t17 = *((char **)t16);
    memcpy(t18, t17, 8);
    goto LAB9;

LAB10:    t16 = ((char*)((ng15)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t18, 32, t16, 32);
    goto LAB16;

LAB14:    memcpy(t3, t18, 8);
    goto LAB16;

}

static void Cont_2341_8(char *t0)
{
    char t3[8];
    char t4[8];
    char t18[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 38464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng9)));
    memset(t4, 0, 8);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t2);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t5) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t19 = *((unsigned int *)t4);
    t20 = (~(t19));
    t21 = *((unsigned int *)t12);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t16, 8);

LAB16:    t23 = (t0 + 41552);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0);
    t36 = (t0 + 40896);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 21408U);
    t17 = *((char **)t16);
    memcpy(t18, t17, 8);
    goto LAB9;

LAB10:    t16 = ((char*)((ng15)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t18, 32, t16, 32);
    goto LAB16;

LAB14:    memcpy(t3, t18, 8);
    goto LAB16;

}

static void Cont_2345_9(char *t0)
{
    char t4[8];
    char t5[8];
    char t19[8];
    char t26[8];
    char t58[8];
    char t72[8];
    char t73[8];
    char t81[8];
    char t113[8];
    char t128[8];
    char t129[8];
    char t143[8];
    char t150[8];
    char t182[8];
    char t196[8];
    char t197[8];
    char t205[8];
    char t237[8];
    char t245[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
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
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    char *t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    char *t127;
    char *t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    char *t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    char *t142;
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
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    int t174;
    int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    char *t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    char *t189;
    char *t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    char *t194;
    char *t195;
    char *t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    char *t204;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    char *t210;
    char *t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    char *t219;
    char *t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    int t229;
    int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    char *t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    unsigned int t243;
    char *t244;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    char *t249;
    char *t250;
    char *t251;
    unsigned int t252;
    unsigned int t253;
    unsigned int t254;
    unsigned int t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    char *t259;
    char *t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    int t264;
    unsigned int t265;
    unsigned int t266;
    unsigned int t267;
    int t268;
    unsigned int t269;
    unsigned int t270;
    unsigned int t271;
    unsigned int t272;
    char *t273;
    char *t274;
    char *t275;
    char *t276;
    char *t277;
    unsigned int t278;
    unsigned int t279;
    char *t280;
    unsigned int t281;
    unsigned int t282;
    char *t283;
    unsigned int t284;
    unsigned int t285;
    char *t286;

LAB0:    t1 = (t0 + 38712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2104);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t3, 32, t2, 32);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t26, t5, 8);

LAB10:    memset(t58, 0, 8);
    t59 = (t26 + 4);
    t60 = *((unsigned int *)t59);
    t61 = (~(t60));
    t62 = *((unsigned int *)t26);
    t63 = (t62 & t61);
    t64 = (t63 & 1U);
    if (t64 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t59) != 0)
        goto LAB20;

LAB21:    t66 = (t58 + 4);
    t67 = *((unsigned int *)t58);
    t68 = *((unsigned int *)t66);
    t69 = (t67 || t68);
    if (t69 > 0)
        goto LAB22;

LAB23:    memcpy(t81, t58, 8);

LAB24:    memset(t113, 0, 8);
    t114 = (t81 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t81);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t114) != 0)
        goto LAB34;

LAB35:    t121 = (t113 + 4);
    t122 = *((unsigned int *)t113);
    t123 = (!(t122));
    t124 = *((unsigned int *)t121);
    t125 = (t123 || t124);
    if (t125 > 0)
        goto LAB36;

LAB37:    memcpy(t245, t113, 8);

LAB38:    t273 = (t0 + 41616);
    t274 = (t273 + 56U);
    t275 = *((char **)t274);
    t276 = (t275 + 56U);
    t277 = *((char **)t276);
    memset(t277, 0, 8);
    t278 = 1U;
    t279 = t278;
    t280 = (t245 + 4);
    t281 = *((unsigned int *)t245);
    t278 = (t278 & t281);
    t282 = *((unsigned int *)t280);
    t279 = (t279 & t282);
    t283 = (t277 + 4);
    t284 = *((unsigned int *)t277);
    *((unsigned int *)t277) = (t284 | t278);
    t285 = *((unsigned int *)t283);
    *((unsigned int *)t283) = (t285 | t279);
    xsi_driver_vfirst_trans(t273, 0, 0);
    t286 = (t0 + 40912);
    *((int *)t286) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 16928U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB13:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB14;

LAB15:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t5);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB17;

LAB18:    *((unsigned int *)t58) = 1;
    goto LAB21;

LAB20:    t65 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t65) = 1;
    goto LAB21;

LAB22:    t70 = (t0 + 12032);
    t71 = *((char **)t70);
    t70 = ((char*)((ng4)));
    memset(t72, 0, 8);
    xsi_vlog_signed_equal(t72, 32, t71, 32, t70, 32);
    memset(t73, 0, 8);
    t74 = (t72 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t72);
    t78 = (t77 & t76);
    t79 = (t78 & 1U);
    if (t79 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t74) != 0)
        goto LAB27;

LAB28:    t82 = *((unsigned int *)t58);
    t83 = *((unsigned int *)t73);
    t84 = (t82 & t83);
    *((unsigned int *)t81) = t84;
    t85 = (t58 + 4);
    t86 = (t73 + 4);
    t87 = (t81 + 4);
    t88 = *((unsigned int *)t85);
    t89 = *((unsigned int *)t86);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = *((unsigned int *)t87);
    t92 = (t91 != 0);
    if (t92 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t73) = 1;
    goto LAB28;

LAB27:    t80 = (t73 + 4);
    *((unsigned int *)t73) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB28;

LAB29:    t93 = *((unsigned int *)t81);
    t94 = *((unsigned int *)t87);
    *((unsigned int *)t81) = (t93 | t94);
    t95 = (t58 + 4);
    t96 = (t73 + 4);
    t97 = *((unsigned int *)t58);
    t98 = (~(t97));
    t99 = *((unsigned int *)t95);
    t100 = (~(t99));
    t101 = *((unsigned int *)t73);
    t102 = (~(t101));
    t103 = *((unsigned int *)t96);
    t104 = (~(t103));
    t105 = (t98 & t100);
    t106 = (t102 & t104);
    t107 = (~(t105));
    t108 = (~(t106));
    t109 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t109 & t107);
    t110 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t110 & t108);
    t111 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t111 & t107);
    t112 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t112 & t108);
    goto LAB31;

LAB32:    *((unsigned int *)t113) = 1;
    goto LAB35;

LAB34:    t120 = (t113 + 4);
    *((unsigned int *)t113) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB35;

LAB36:    t126 = (t0 + 2104);
    t127 = *((char **)t126);
    t126 = ((char*)((ng3)));
    memset(t128, 0, 8);
    xsi_vlog_signed_equal(t128, 32, t127, 32, t126, 32);
    memset(t129, 0, 8);
    t130 = (t128 + 4);
    t131 = *((unsigned int *)t130);
    t132 = (~(t131));
    t133 = *((unsigned int *)t128);
    t134 = (t133 & t132);
    t135 = (t134 & 1U);
    if (t135 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t130) != 0)
        goto LAB41;

LAB42:    t137 = (t129 + 4);
    t138 = *((unsigned int *)t129);
    t139 = *((unsigned int *)t137);
    t140 = (t138 || t139);
    if (t140 > 0)
        goto LAB43;

LAB44:    memcpy(t150, t129, 8);

LAB45:    memset(t182, 0, 8);
    t183 = (t150 + 4);
    t184 = *((unsigned int *)t183);
    t185 = (~(t184));
    t186 = *((unsigned int *)t150);
    t187 = (t186 & t185);
    t188 = (t187 & 1U);
    if (t188 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t183) != 0)
        goto LAB55;

LAB56:    t190 = (t182 + 4);
    t191 = *((unsigned int *)t182);
    t192 = *((unsigned int *)t190);
    t193 = (t191 || t192);
    if (t193 > 0)
        goto LAB57;

LAB58:    memcpy(t205, t182, 8);

LAB59:    memset(t237, 0, 8);
    t238 = (t205 + 4);
    t239 = *((unsigned int *)t238);
    t240 = (~(t239));
    t241 = *((unsigned int *)t205);
    t242 = (t241 & t240);
    t243 = (t242 & 1U);
    if (t243 != 0)
        goto LAB67;

LAB68:    if (*((unsigned int *)t238) != 0)
        goto LAB69;

LAB70:    t246 = *((unsigned int *)t113);
    t247 = *((unsigned int *)t237);
    t248 = (t246 | t247);
    *((unsigned int *)t245) = t248;
    t249 = (t113 + 4);
    t250 = (t237 + 4);
    t251 = (t245 + 4);
    t252 = *((unsigned int *)t249);
    t253 = *((unsigned int *)t250);
    t254 = (t252 | t253);
    *((unsigned int *)t251) = t254;
    t255 = *((unsigned int *)t251);
    t256 = (t255 != 0);
    if (t256 == 1)
        goto LAB71;

LAB72:
LAB73:    goto LAB38;

LAB39:    *((unsigned int *)t129) = 1;
    goto LAB42;

LAB41:    t136 = (t129 + 4);
    *((unsigned int *)t129) = 1;
    *((unsigned int *)t136) = 1;
    goto LAB42;

LAB43:    t141 = (t0 + 16928U);
    t142 = *((char **)t141);
    memset(t143, 0, 8);
    t141 = (t142 + 4);
    t144 = *((unsigned int *)t141);
    t145 = (~(t144));
    t146 = *((unsigned int *)t142);
    t147 = (t146 & t145);
    t148 = (t147 & 1U);
    if (t148 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t141) != 0)
        goto LAB48;

LAB49:    t151 = *((unsigned int *)t129);
    t152 = *((unsigned int *)t143);
    t153 = (t151 & t152);
    *((unsigned int *)t150) = t153;
    t154 = (t129 + 4);
    t155 = (t143 + 4);
    t156 = (t150 + 4);
    t157 = *((unsigned int *)t154);
    t158 = *((unsigned int *)t155);
    t159 = (t157 | t158);
    *((unsigned int *)t156) = t159;
    t160 = *((unsigned int *)t156);
    t161 = (t160 != 0);
    if (t161 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB45;

LAB46:    *((unsigned int *)t143) = 1;
    goto LAB49;

LAB48:    t149 = (t143 + 4);
    *((unsigned int *)t143) = 1;
    *((unsigned int *)t149) = 1;
    goto LAB49;

LAB50:    t162 = *((unsigned int *)t150);
    t163 = *((unsigned int *)t156);
    *((unsigned int *)t150) = (t162 | t163);
    t164 = (t129 + 4);
    t165 = (t143 + 4);
    t166 = *((unsigned int *)t129);
    t167 = (~(t166));
    t168 = *((unsigned int *)t164);
    t169 = (~(t168));
    t170 = *((unsigned int *)t143);
    t171 = (~(t170));
    t172 = *((unsigned int *)t165);
    t173 = (~(t172));
    t174 = (t167 & t169);
    t175 = (t171 & t173);
    t176 = (~(t174));
    t177 = (~(t175));
    t178 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t178 & t176);
    t179 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t179 & t177);
    t180 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t180 & t176);
    t181 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t181 & t177);
    goto LAB52;

LAB53:    *((unsigned int *)t182) = 1;
    goto LAB56;

LAB55:    t189 = (t182 + 4);
    *((unsigned int *)t182) = 1;
    *((unsigned int *)t189) = 1;
    goto LAB56;

LAB57:    t194 = (t0 + 2376);
    t195 = *((char **)t194);
    t194 = ((char*)((ng3)));
    memset(t196, 0, 8);
    xsi_vlog_signed_equal(t196, 32, t195, 32, t194, 32);
    memset(t197, 0, 8);
    t198 = (t196 + 4);
    t199 = *((unsigned int *)t198);
    t200 = (~(t199));
    t201 = *((unsigned int *)t196);
    t202 = (t201 & t200);
    t203 = (t202 & 1U);
    if (t203 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t198) != 0)
        goto LAB62;

LAB63:    t206 = *((unsigned int *)t182);
    t207 = *((unsigned int *)t197);
    t208 = (t206 & t207);
    *((unsigned int *)t205) = t208;
    t209 = (t182 + 4);
    t210 = (t197 + 4);
    t211 = (t205 + 4);
    t212 = *((unsigned int *)t209);
    t213 = *((unsigned int *)t210);
    t214 = (t212 | t213);
    *((unsigned int *)t211) = t214;
    t215 = *((unsigned int *)t211);
    t216 = (t215 != 0);
    if (t216 == 1)
        goto LAB64;

LAB65:
LAB66:    goto LAB59;

LAB60:    *((unsigned int *)t197) = 1;
    goto LAB63;

LAB62:    t204 = (t197 + 4);
    *((unsigned int *)t197) = 1;
    *((unsigned int *)t204) = 1;
    goto LAB63;

LAB64:    t217 = *((unsigned int *)t205);
    t218 = *((unsigned int *)t211);
    *((unsigned int *)t205) = (t217 | t218);
    t219 = (t182 + 4);
    t220 = (t197 + 4);
    t221 = *((unsigned int *)t182);
    t222 = (~(t221));
    t223 = *((unsigned int *)t219);
    t224 = (~(t223));
    t225 = *((unsigned int *)t197);
    t226 = (~(t225));
    t227 = *((unsigned int *)t220);
    t228 = (~(t227));
    t229 = (t222 & t224);
    t230 = (t226 & t228);
    t231 = (~(t229));
    t232 = (~(t230));
    t233 = *((unsigned int *)t211);
    *((unsigned int *)t211) = (t233 & t231);
    t234 = *((unsigned int *)t211);
    *((unsigned int *)t211) = (t234 & t232);
    t235 = *((unsigned int *)t205);
    *((unsigned int *)t205) = (t235 & t231);
    t236 = *((unsigned int *)t205);
    *((unsigned int *)t205) = (t236 & t232);
    goto LAB66;

LAB67:    *((unsigned int *)t237) = 1;
    goto LAB70;

LAB69:    t244 = (t237 + 4);
    *((unsigned int *)t237) = 1;
    *((unsigned int *)t244) = 1;
    goto LAB70;

LAB71:    t257 = *((unsigned int *)t245);
    t258 = *((unsigned int *)t251);
    *((unsigned int *)t245) = (t257 | t258);
    t259 = (t113 + 4);
    t260 = (t237 + 4);
    t261 = *((unsigned int *)t259);
    t262 = (~(t261));
    t263 = *((unsigned int *)t113);
    t264 = (t263 & t262);
    t265 = *((unsigned int *)t260);
    t266 = (~(t265));
    t267 = *((unsigned int *)t237);
    t268 = (t267 & t266);
    t269 = (~(t264));
    t270 = (~(t268));
    t271 = *((unsigned int *)t251);
    *((unsigned int *)t251) = (t271 & t269);
    t272 = *((unsigned int *)t251);
    *((unsigned int *)t251) = (t272 & t270);
    goto LAB73;

}

static void Cont_2349_10(char *t0)
{
    char t4[8];
    char t5[8];
    char t19[8];
    char t26[8];
    char t58[8];
    char t72[8];
    char t73[8];
    char t81[8];
    char t113[8];
    char t128[8];
    char t129[8];
    char t143[8];
    char t150[8];
    char t182[8];
    char t196[8];
    char t197[8];
    char t205[8];
    char t237[8];
    char t245[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
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
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    char *t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    char *t127;
    char *t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    char *t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    char *t142;
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
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    int t174;
    int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    char *t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    char *t189;
    char *t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    char *t194;
    char *t195;
    char *t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    char *t204;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    char *t210;
    char *t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    char *t219;
    char *t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    int t229;
    int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    char *t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    unsigned int t243;
    char *t244;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    char *t249;
    char *t250;
    char *t251;
    unsigned int t252;
    unsigned int t253;
    unsigned int t254;
    unsigned int t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    char *t259;
    char *t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    int t264;
    unsigned int t265;
    unsigned int t266;
    unsigned int t267;
    int t268;
    unsigned int t269;
    unsigned int t270;
    unsigned int t271;
    unsigned int t272;
    char *t273;
    char *t274;
    char *t275;
    char *t276;
    char *t277;
    unsigned int t278;
    unsigned int t279;
    char *t280;
    unsigned int t281;
    unsigned int t282;
    char *t283;
    unsigned int t284;
    unsigned int t285;
    char *t286;

LAB0:    t1 = (t0 + 38960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4008);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t3, 32, t2, 32);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t26, t5, 8);

LAB10:    memset(t58, 0, 8);
    t59 = (t26 + 4);
    t60 = *((unsigned int *)t59);
    t61 = (~(t60));
    t62 = *((unsigned int *)t26);
    t63 = (t62 & t61);
    t64 = (t63 & 1U);
    if (t64 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t59) != 0)
        goto LAB20;

LAB21:    t66 = (t58 + 4);
    t67 = *((unsigned int *)t58);
    t68 = *((unsigned int *)t66);
    t69 = (t67 || t68);
    if (t69 > 0)
        goto LAB22;

LAB23:    memcpy(t81, t58, 8);

LAB24:    memset(t113, 0, 8);
    t114 = (t81 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t81);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t114) != 0)
        goto LAB34;

LAB35:    t121 = (t113 + 4);
    t122 = *((unsigned int *)t113);
    t123 = (!(t122));
    t124 = *((unsigned int *)t121);
    t125 = (t123 || t124);
    if (t125 > 0)
        goto LAB36;

LAB37:    memcpy(t245, t113, 8);

LAB38:    t273 = (t0 + 41680);
    t274 = (t273 + 56U);
    t275 = *((char **)t274);
    t276 = (t275 + 56U);
    t277 = *((char **)t276);
    memset(t277, 0, 8);
    t278 = 1U;
    t279 = t278;
    t280 = (t245 + 4);
    t281 = *((unsigned int *)t245);
    t278 = (t278 & t281);
    t282 = *((unsigned int *)t280);
    t279 = (t279 & t282);
    t283 = (t277 + 4);
    t284 = *((unsigned int *)t277);
    *((unsigned int *)t277) = (t284 | t278);
    t285 = *((unsigned int *)t283);
    *((unsigned int *)t283) = (t285 | t279);
    xsi_driver_vfirst_trans(t273, 0, 0);
    t286 = (t0 + 40928);
    *((int *)t286) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 18208U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB13:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB14;

LAB15:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t5);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB17;

LAB18:    *((unsigned int *)t58) = 1;
    goto LAB21;

LAB20:    t65 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t65) = 1;
    goto LAB21;

LAB22:    t70 = (t0 + 12168);
    t71 = *((char **)t70);
    t70 = ((char*)((ng4)));
    memset(t72, 0, 8);
    xsi_vlog_signed_equal(t72, 32, t71, 32, t70, 32);
    memset(t73, 0, 8);
    t74 = (t72 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t72);
    t78 = (t77 & t76);
    t79 = (t78 & 1U);
    if (t79 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t74) != 0)
        goto LAB27;

LAB28:    t82 = *((unsigned int *)t58);
    t83 = *((unsigned int *)t73);
    t84 = (t82 & t83);
    *((unsigned int *)t81) = t84;
    t85 = (t58 + 4);
    t86 = (t73 + 4);
    t87 = (t81 + 4);
    t88 = *((unsigned int *)t85);
    t89 = *((unsigned int *)t86);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = *((unsigned int *)t87);
    t92 = (t91 != 0);
    if (t92 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t73) = 1;
    goto LAB28;

LAB27:    t80 = (t73 + 4);
    *((unsigned int *)t73) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB28;

LAB29:    t93 = *((unsigned int *)t81);
    t94 = *((unsigned int *)t87);
    *((unsigned int *)t81) = (t93 | t94);
    t95 = (t58 + 4);
    t96 = (t73 + 4);
    t97 = *((unsigned int *)t58);
    t98 = (~(t97));
    t99 = *((unsigned int *)t95);
    t100 = (~(t99));
    t101 = *((unsigned int *)t73);
    t102 = (~(t101));
    t103 = *((unsigned int *)t96);
    t104 = (~(t103));
    t105 = (t98 & t100);
    t106 = (t102 & t104);
    t107 = (~(t105));
    t108 = (~(t106));
    t109 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t109 & t107);
    t110 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t110 & t108);
    t111 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t111 & t107);
    t112 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t112 & t108);
    goto LAB31;

LAB32:    *((unsigned int *)t113) = 1;
    goto LAB35;

LAB34:    t120 = (t113 + 4);
    *((unsigned int *)t113) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB35;

LAB36:    t126 = (t0 + 4008);
    t127 = *((char **)t126);
    t126 = ((char*)((ng3)));
    memset(t128, 0, 8);
    xsi_vlog_signed_equal(t128, 32, t127, 32, t126, 32);
    memset(t129, 0, 8);
    t130 = (t128 + 4);
    t131 = *((unsigned int *)t130);
    t132 = (~(t131));
    t133 = *((unsigned int *)t128);
    t134 = (t133 & t132);
    t135 = (t134 & 1U);
    if (t135 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t130) != 0)
        goto LAB41;

LAB42:    t137 = (t129 + 4);
    t138 = *((unsigned int *)t129);
    t139 = *((unsigned int *)t137);
    t140 = (t138 || t139);
    if (t140 > 0)
        goto LAB43;

LAB44:    memcpy(t150, t129, 8);

LAB45:    memset(t182, 0, 8);
    t183 = (t150 + 4);
    t184 = *((unsigned int *)t183);
    t185 = (~(t184));
    t186 = *((unsigned int *)t150);
    t187 = (t186 & t185);
    t188 = (t187 & 1U);
    if (t188 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t183) != 0)
        goto LAB55;

LAB56:    t190 = (t182 + 4);
    t191 = *((unsigned int *)t182);
    t192 = *((unsigned int *)t190);
    t193 = (t191 || t192);
    if (t193 > 0)
        goto LAB57;

LAB58:    memcpy(t205, t182, 8);

LAB59:    memset(t237, 0, 8);
    t238 = (t205 + 4);
    t239 = *((unsigned int *)t238);
    t240 = (~(t239));
    t241 = *((unsigned int *)t205);
    t242 = (t241 & t240);
    t243 = (t242 & 1U);
    if (t243 != 0)
        goto LAB67;

LAB68:    if (*((unsigned int *)t238) != 0)
        goto LAB69;

LAB70:    t246 = *((unsigned int *)t113);
    t247 = *((unsigned int *)t237);
    t248 = (t246 | t247);
    *((unsigned int *)t245) = t248;
    t249 = (t113 + 4);
    t250 = (t237 + 4);
    t251 = (t245 + 4);
    t252 = *((unsigned int *)t249);
    t253 = *((unsigned int *)t250);
    t254 = (t252 | t253);
    *((unsigned int *)t251) = t254;
    t255 = *((unsigned int *)t251);
    t256 = (t255 != 0);
    if (t256 == 1)
        goto LAB71;

LAB72:
LAB73:    goto LAB38;

LAB39:    *((unsigned int *)t129) = 1;
    goto LAB42;

LAB41:    t136 = (t129 + 4);
    *((unsigned int *)t129) = 1;
    *((unsigned int *)t136) = 1;
    goto LAB42;

LAB43:    t141 = (t0 + 18208U);
    t142 = *((char **)t141);
    memset(t143, 0, 8);
    t141 = (t142 + 4);
    t144 = *((unsigned int *)t141);
    t145 = (~(t144));
    t146 = *((unsigned int *)t142);
    t147 = (t146 & t145);
    t148 = (t147 & 1U);
    if (t148 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t141) != 0)
        goto LAB48;

LAB49:    t151 = *((unsigned int *)t129);
    t152 = *((unsigned int *)t143);
    t153 = (t151 & t152);
    *((unsigned int *)t150) = t153;
    t154 = (t129 + 4);
    t155 = (t143 + 4);
    t156 = (t150 + 4);
    t157 = *((unsigned int *)t154);
    t158 = *((unsigned int *)t155);
    t159 = (t157 | t158);
    *((unsigned int *)t156) = t159;
    t160 = *((unsigned int *)t156);
    t161 = (t160 != 0);
    if (t161 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB45;

LAB46:    *((unsigned int *)t143) = 1;
    goto LAB49;

LAB48:    t149 = (t143 + 4);
    *((unsigned int *)t143) = 1;
    *((unsigned int *)t149) = 1;
    goto LAB49;

LAB50:    t162 = *((unsigned int *)t150);
    t163 = *((unsigned int *)t156);
    *((unsigned int *)t150) = (t162 | t163);
    t164 = (t129 + 4);
    t165 = (t143 + 4);
    t166 = *((unsigned int *)t129);
    t167 = (~(t166));
    t168 = *((unsigned int *)t164);
    t169 = (~(t168));
    t170 = *((unsigned int *)t143);
    t171 = (~(t170));
    t172 = *((unsigned int *)t165);
    t173 = (~(t172));
    t174 = (t167 & t169);
    t175 = (t171 & t173);
    t176 = (~(t174));
    t177 = (~(t175));
    t178 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t178 & t176);
    t179 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t179 & t177);
    t180 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t180 & t176);
    t181 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t181 & t177);
    goto LAB52;

LAB53:    *((unsigned int *)t182) = 1;
    goto LAB56;

LAB55:    t189 = (t182 + 4);
    *((unsigned int *)t182) = 1;
    *((unsigned int *)t189) = 1;
    goto LAB56;

LAB57:    t194 = (t0 + 4280);
    t195 = *((char **)t194);
    t194 = ((char*)((ng3)));
    memset(t196, 0, 8);
    xsi_vlog_signed_equal(t196, 32, t195, 32, t194, 32);
    memset(t197, 0, 8);
    t198 = (t196 + 4);
    t199 = *((unsigned int *)t198);
    t200 = (~(t199));
    t201 = *((unsigned int *)t196);
    t202 = (t201 & t200);
    t203 = (t202 & 1U);
    if (t203 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t198) != 0)
        goto LAB62;

LAB63:    t206 = *((unsigned int *)t182);
    t207 = *((unsigned int *)t197);
    t208 = (t206 & t207);
    *((unsigned int *)t205) = t208;
    t209 = (t182 + 4);
    t210 = (t197 + 4);
    t211 = (t205 + 4);
    t212 = *((unsigned int *)t209);
    t213 = *((unsigned int *)t210);
    t214 = (t212 | t213);
    *((unsigned int *)t211) = t214;
    t215 = *((unsigned int *)t211);
    t216 = (t215 != 0);
    if (t216 == 1)
        goto LAB64;

LAB65:
LAB66:    goto LAB59;

LAB60:    *((unsigned int *)t197) = 1;
    goto LAB63;

LAB62:    t204 = (t197 + 4);
    *((unsigned int *)t197) = 1;
    *((unsigned int *)t204) = 1;
    goto LAB63;

LAB64:    t217 = *((unsigned int *)t205);
    t218 = *((unsigned int *)t211);
    *((unsigned int *)t205) = (t217 | t218);
    t219 = (t182 + 4);
    t220 = (t197 + 4);
    t221 = *((unsigned int *)t182);
    t222 = (~(t221));
    t223 = *((unsigned int *)t219);
    t224 = (~(t223));
    t225 = *((unsigned int *)t197);
    t226 = (~(t225));
    t227 = *((unsigned int *)t220);
    t228 = (~(t227));
    t229 = (t222 & t224);
    t230 = (t226 & t228);
    t231 = (~(t229));
    t232 = (~(t230));
    t233 = *((unsigned int *)t211);
    *((unsigned int *)t211) = (t233 & t231);
    t234 = *((unsigned int *)t211);
    *((unsigned int *)t211) = (t234 & t232);
    t235 = *((unsigned int *)t205);
    *((unsigned int *)t205) = (t235 & t231);
    t236 = *((unsigned int *)t205);
    *((unsigned int *)t205) = (t236 & t232);
    goto LAB66;

LAB67:    *((unsigned int *)t237) = 1;
    goto LAB70;

LAB69:    t244 = (t237 + 4);
    *((unsigned int *)t237) = 1;
    *((unsigned int *)t244) = 1;
    goto LAB70;

LAB71:    t257 = *((unsigned int *)t245);
    t258 = *((unsigned int *)t251);
    *((unsigned int *)t245) = (t257 | t258);
    t259 = (t113 + 4);
    t260 = (t237 + 4);
    t261 = *((unsigned int *)t259);
    t262 = (~(t261));
    t263 = *((unsigned int *)t113);
    t264 = (t263 & t262);
    t265 = *((unsigned int *)t260);
    t266 = (~(t265));
    t267 = *((unsigned int *)t237);
    t268 = (t267 & t266);
    t269 = (~(t264));
    t270 = (~(t268));
    t271 = *((unsigned int *)t251);
    *((unsigned int *)t251) = (t271 & t269);
    t272 = *((unsigned int *)t251);
    *((unsigned int *)t251) = (t272 & t270);
    goto LAB73;

}

static void Initial_2918_11(char *t0)
{
    char t18[32];
    char t19[8];
    char t30[8];
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
    char *t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;

LAB0:    t1 = (t0 + 39208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:
LAB4:    t2 = (t0 + 39016);
    t3 = (t0 + 15272);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB7:    t5 = (t0 + 39112);
    t6 = *((char **)t5);
    t7 = (t6 + 80U);
    t8 = *((char **)t7);
    t9 = (t8 + 272U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t13 = ((int  (*)(char *, char *))t12)(t0, t6);

LAB9:    if (t13 != 0)
        goto LAB10;

LAB5:    t6 = (t0 + 15272);
    xsi_vlog_subprogram_popinvocation(t6);

LAB6:    t14 = (t0 + 39112);
    t15 = *((char **)t14);
    t14 = (t0 + 15272);
    t16 = (t0 + 39016);
    t17 = 0;
    xsi_delete_subprogram_invocation(t14, t15, t0, t16, t17);
    t2 = (t0 + 26608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 25008);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_bit_copy(t18, 0, t7, 0, 128);
    *((int *)t19) = xsi_vlogfile_sscanf(t4, 1024, ng23, 2, t0, (char)118, t18, 128);
    t8 = (t19 + 4);
    *((int *)t8) = 0;
    t9 = (t0 + 25008);
    xsi_vlogvar_assign_value(t9, t18, 0, 0, 128);
    t10 = (t19 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB11;

LAB12:
LAB15:    t2 = ((char*)((ng19)));
    t3 = (t0 + 24208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);

LAB13:    t2 = (t0 + 26768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 25168);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_bit_copy(t18, 0, t7, 0, 128);
    *((int *)t19) = xsi_vlogfile_sscanf(t4, 1024, ng23, 2, t0, (char)118, t18, 128);
    t8 = (t19 + 4);
    *((int *)t8) = 0;
    t9 = (t0 + 25168);
    xsi_vlogvar_assign_value(t9, t18, 0, 0, 128);
    t10 = (t19 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB16;

LAB17:
LAB20:    t2 = ((char*)((ng19)));
    t3 = (t0 + 24368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);

LAB18:    t2 = ((char*)((ng15)));
    t3 = (t0 + 24528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 24688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 24848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 10);
    t2 = (t0 + 3872);
    t3 = *((char **)t2);
    t2 = (t0 + 9992);
    t4 = *((char **)t2);
    t2 = (t0 + 39016);
    t5 = (t0 + 15704);
    t6 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t7 = (t0 + 32528);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 32);

LAB21:    t8 = (t0 + 39112);
    t9 = *((char **)t8);
    t10 = (t9 + 80U);
    t11 = *((char **)t10);
    t12 = (t11 + 272U);
    t14 = *((char **)t12);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t13 = ((int  (*)(char *, char *))t16)(t0, t9);
    if (t13 != 0)
        goto LAB23;

LAB22:    t9 = (t0 + 39112);
    t17 = *((char **)t9);
    t9 = (t0 + 32688);
    t25 = (t9 + 56U);
    t26 = *((char **)t25);
    memcpy(t19, t26, 8);
    t27 = (t0 + 15704);
    t28 = (t0 + 39016);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t17, t0, t28, t29);
    memset(t30, 0, 8);
    xsi_vlog_signed_minus(t30, 32, t3, 32, t19, 32);
    t31 = (t0 + 27408);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    t2 = (t0 + 3872);
    t3 = *((char **)t2);
    t2 = (t0 + 10128);
    t4 = *((char **)t2);
    t2 = (t0 + 39016);
    t5 = (t0 + 15704);
    t6 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t7 = (t0 + 32528);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 32);

LAB24:    t8 = (t0 + 39112);
    t9 = *((char **)t8);
    t10 = (t9 + 80U);
    t11 = *((char **)t10);
    t12 = (t11 + 272U);
    t14 = *((char **)t12);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t13 = ((int  (*)(char *, char *))t16)(t0, t9);
    if (t13 != 0)
        goto LAB26;

LAB25:    t9 = (t0 + 39112);
    t17 = *((char **)t9);
    t9 = (t0 + 32688);
    t25 = (t9 + 56U);
    t26 = *((char **)t25);
    memcpy(t19, t26, 8);
    t27 = (t0 + 15704);
    t28 = (t0 + 39016);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t17, t0, t28, t29);
    memset(t30, 0, 8);
    xsi_vlog_signed_minus(t30, 32, t3, 32, t19, 32);
    t31 = (t0 + 27568);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    t2 = (t0 + 5776);
    t3 = *((char **)t2);
    t2 = (t0 + 10264);
    t4 = *((char **)t2);
    t2 = (t0 + 39016);
    t5 = (t0 + 15704);
    t6 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t7 = (t0 + 32528);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 32);

LAB27:    t8 = (t0 + 39112);
    t9 = *((char **)t8);
    t10 = (t9 + 80U);
    t11 = *((char **)t10);
    t12 = (t11 + 272U);
    t14 = *((char **)t12);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t13 = ((int  (*)(char *, char *))t16)(t0, t9);
    if (t13 != 0)
        goto LAB29;

LAB28:    t9 = (t0 + 39112);
    t17 = *((char **)t9);
    t9 = (t0 + 32688);
    t25 = (t9 + 56U);
    t26 = *((char **)t25);
    memcpy(t19, t26, 8);
    t27 = (t0 + 15704);
    t28 = (t0 + 39016);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t17, t0, t28, t29);
    memset(t30, 0, 8);
    xsi_vlog_signed_minus(t30, 32, t3, 32, t19, 32);
    t31 = (t0 + 27728);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    t2 = (t0 + 5776);
    t3 = *((char **)t2);
    t2 = (t0 + 10400);
    t4 = *((char **)t2);
    t2 = (t0 + 39016);
    t5 = (t0 + 15704);
    t6 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t7 = (t0 + 32528);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 32);

LAB30:    t8 = (t0 + 39112);
    t9 = *((char **)t8);
    t10 = (t9 + 80U);
    t11 = *((char **)t10);
    t12 = (t11 + 272U);
    t14 = *((char **)t12);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t13 = ((int  (*)(char *, char *))t16)(t0, t9);
    if (t13 != 0)
        goto LAB32;

LAB31:    t9 = (t0 + 39112);
    t17 = *((char **)t9);
    t9 = (t0 + 32688);
    t25 = (t9 + 56U);
    t26 = *((char **)t25);
    memcpy(t19, t26, 8);
    t27 = (t0 + 15704);
    t28 = (t0 + 39016);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t17, t0, t28, t29);
    memset(t30, 0, 8);
    xsi_vlog_signed_minus(t30, 32, t3, 32, t19, 32);
    t31 = (t0 + 27888);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    xsi_vlogfile_write(1, 0, 0, ng33, 1, t0);

LAB1:    return;
LAB8:;
LAB10:    t5 = (t0 + 39208U);
    *((char **)t5) = &&LAB7;
    goto LAB1;

LAB11:
LAB14:    t11 = (t0 + 25008);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    t15 = (t0 + 24208);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 128);
    goto LAB13;

LAB16:
LAB19:    t11 = (t0 + 25168);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    t15 = (t0 + 24368);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 128);
    goto LAB18;

LAB23:    t8 = (t0 + 39208U);
    *((char **)t8) = &&LAB21;
    goto LAB1;

LAB26:    t8 = (t0 + 39208U);
    *((char **)t8) = &&LAB24;
    goto LAB1;

LAB29:    t8 = (t0 + 39208U);
    *((char **)t8) = &&LAB27;
    goto LAB1;

LAB32:    t8 = (t0 + 39208U);
    *((char **)t8) = &&LAB30;
    goto LAB1;

}

static void Always_3061_12(char *t0)
{
    char t6[16];
    char t7[8];
    char t21[8];
    char t37[8];
    char t45[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
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
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
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
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    int t69;
    int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    char *t101;
    char *t102;
    int t103;
    char *t104;
    char *t105;
    char *t106;
    char *t107;

LAB0:    t1 = (t0 + 39456U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 40944);
    *((int *)t2) = 1;
    t3 = (t0 + 39488);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = ((char*)((ng34)));
    t5 = ((char*)((ng35)));
    xsi_vlog_unsigned_equal(t6, 64, t4, 56, t5, 64);
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

LAB11:    memcpy(t45, t7, 8);

LAB12:    t77 = (t45 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (t80 & t79);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB24;

LAB25:
LAB46:    t2 = (t0 + 22208U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB47;

LAB48:
LAB49:
LAB26:    t2 = ((char*)((ng34)));
    t3 = ((char*)((ng35)));
    xsi_vlog_unsigned_equal(t6, 64, t2, 56, t3, 64);
    memset(t7, 0, 8);
    t4 = (t6 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t4) != 0)
        goto LAB58;

LAB59:    t8 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB60;

LAB61:    memcpy(t45, t7, 8);

LAB62:    t59 = (t45 + 4);
    t78 = *((unsigned int *)t59);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (t80 & t79);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB74;

LAB75:
LAB96:    t2 = (t0 + 22368U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB97;

LAB98:
LAB99:
LAB76:    t2 = (t0 + 21888U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB106;

LAB107:
LAB108:    t2 = (t0 + 22048U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB115;

LAB116:
LAB117:    goto LAB2;

LAB6:    *((unsigned int *)t7) = 1;
    goto LAB9;

LAB8:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB9;

LAB10:    t19 = ((char*)((ng36)));
    t20 = ((char*)((ng37)));
    memset(t21, 0, 8);
    t22 = (t19 + 4);
    t23 = (t20 + 4);
    t24 = *((unsigned int *)t19);
    t25 = *((unsigned int *)t20);
    t26 = (t24 ^ t25);
    t27 = *((unsigned int *)t22);
    t28 = *((unsigned int *)t23);
    t29 = (t27 ^ t28);
    t30 = (t26 | t29);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t23);
    t33 = (t31 | t32);
    t34 = (~(t33));
    t35 = (t30 & t34);
    if (t35 != 0)
        goto LAB16;

LAB13:    if (t33 != 0)
        goto LAB15;

LAB14:    *((unsigned int *)t21) = 1;

LAB16:    memset(t37, 0, 8);
    t38 = (t21 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t21);
    t42 = (t41 & t40);
    t43 = (t42 & 1U);
    if (t43 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t38) != 0)
        goto LAB19;

LAB20:    t46 = *((unsigned int *)t7);
    t47 = *((unsigned int *)t37);
    t48 = (t46 & t47);
    *((unsigned int *)t45) = t48;
    t49 = (t7 + 4);
    t50 = (t37 + 4);
    t51 = (t45 + 4);
    t52 = *((unsigned int *)t49);
    t53 = *((unsigned int *)t50);
    t54 = (t52 | t53);
    *((unsigned int *)t51) = t54;
    t55 = *((unsigned int *)t51);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB12;

LAB15:    t36 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB16;

LAB17:    *((unsigned int *)t37) = 1;
    goto LAB20;

LAB19:    t44 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB20;

LAB21:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t45) = (t57 | t58);
    t59 = (t7 + 4);
    t60 = (t37 + 4);
    t61 = *((unsigned int *)t7);
    t62 = (~(t61));
    t63 = *((unsigned int *)t59);
    t64 = (~(t63));
    t65 = *((unsigned int *)t37);
    t66 = (~(t65));
    t67 = *((unsigned int *)t60);
    t68 = (~(t67));
    t69 = (t62 & t64);
    t70 = (t66 & t68);
    t71 = (~(t69));
    t72 = (~(t70));
    t73 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t73 & t71);
    t74 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t74 & t72);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t71);
    t76 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t76 & t72);
    goto LAB23;

LAB24:
LAB27:    t83 = (t0 + 21568U);
    t84 = *((char **)t83);
    t83 = (t84 + 4);
    t85 = *((unsigned int *)t83);
    t86 = (~(t85));
    t87 = *((unsigned int *)t84);
    t88 = (t87 & t86);
    t89 = (t88 != 0);
    if (t89 > 0)
        goto LAB28;

LAB29:    t2 = (t0 + 22208U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB37;

LAB38:
LAB39:
LAB30:    goto LAB26;

LAB28:    t90 = (t0 + 21568U);
    t91 = *((char **)t90);
    t90 = (t0 + 39264);
    t92 = (t0 + 14408);
    t93 = xsi_create_subprogram_invocation(t90, 0, t0, t92, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t92, t93);
    t94 = (t0 + 31568);
    xsi_vlogvar_assign_value(t94, t91, 0, 0, 1);

LAB33:    t95 = (t0 + 39360);
    t96 = *((char **)t95);
    t97 = (t96 + 80U);
    t98 = *((char **)t97);
    t99 = (t98 + 272U);
    t100 = *((char **)t99);
    t101 = (t100 + 0U);
    t102 = *((char **)t101);
    t103 = ((int  (*)(char *, char *))t102)(t0, t96);

LAB35:    if (t103 != 0)
        goto LAB36;

LAB31:    t96 = (t0 + 14408);
    xsi_vlog_subprogram_popinvocation(t96);

LAB32:    t104 = (t0 + 39360);
    t105 = *((char **)t104);
    t104 = (t0 + 14408);
    t106 = (t0 + 39264);
    t107 = 0;
    xsi_delete_subprogram_invocation(t104, t105, t0, t106, t107);
    goto LAB30;

LAB34:;
LAB36:    t95 = (t0 + 39456U);
    *((char **)t95) = &&LAB33;
    goto LAB1;

LAB37:    t4 = (t0 + 17568U);
    t5 = *((char **)t4);
    t4 = (t0 + 21568U);
    t8 = *((char **)t4);
    t4 = (t0 + 39264);
    t14 = (t0 + 13544);
    t15 = xsi_create_subprogram_invocation(t4, 0, t0, t14, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t14, t15);
    t19 = (t0 + 30288);
    xsi_vlogvar_assign_value(t19, t5, 0, 0, 10);
    t20 = (t0 + 30448);
    xsi_vlogvar_assign_value(t20, t8, 0, 0, 1);

LAB42:    t22 = (t0 + 39360);
    t23 = *((char **)t22);
    t36 = (t23 + 80U);
    t38 = *((char **)t36);
    t44 = (t38 + 272U);
    t49 = *((char **)t44);
    t50 = (t49 + 0U);
    t51 = *((char **)t50);
    t69 = ((int  (*)(char *, char *))t51)(t0, t23);

LAB44:    if (t69 != 0)
        goto LAB45;

LAB40:    t23 = (t0 + 13544);
    xsi_vlog_subprogram_popinvocation(t23);

LAB41:    t59 = (t0 + 39360);
    t60 = *((char **)t59);
    t59 = (t0 + 13544);
    t77 = (t0 + 39264);
    t83 = 0;
    xsi_delete_subprogram_invocation(t59, t60, t0, t77, t83);
    goto LAB39;

LAB43:;
LAB45:    t22 = (t0 + 39456U);
    *((char **)t22) = &&LAB42;
    goto LAB1;

LAB47:    t4 = (t0 + 17568U);
    t5 = *((char **)t4);
    t4 = (t0 + 21568U);
    t8 = *((char **)t4);
    t4 = (t0 + 39264);
    t14 = (t0 + 13544);
    t15 = xsi_create_subprogram_invocation(t4, 0, t0, t14, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t14, t15);
    t19 = (t0 + 30288);
    xsi_vlogvar_assign_value(t19, t5, 0, 0, 10);
    t20 = (t0 + 30448);
    xsi_vlogvar_assign_value(t20, t8, 0, 0, 1);

LAB52:    t22 = (t0 + 39360);
    t23 = *((char **)t22);
    t36 = (t23 + 80U);
    t38 = *((char **)t36);
    t44 = (t38 + 272U);
    t49 = *((char **)t44);
    t50 = (t49 + 0U);
    t51 = *((char **)t50);
    t69 = ((int  (*)(char *, char *))t51)(t0, t23);

LAB54:    if (t69 != 0)
        goto LAB55;

LAB50:    t23 = (t0 + 13544);
    xsi_vlog_subprogram_popinvocation(t23);

LAB51:    t59 = (t0 + 39360);
    t60 = *((char **)t59);
    t59 = (t0 + 13544);
    t77 = (t0 + 39264);
    t83 = 0;
    xsi_delete_subprogram_invocation(t59, t60, t0, t77, t83);
    goto LAB49;

LAB53:;
LAB55:    t22 = (t0 + 39456U);
    *((char **)t22) = &&LAB52;
    goto LAB1;

LAB56:    *((unsigned int *)t7) = 1;
    goto LAB59;

LAB58:    t5 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB59;

LAB60:    t14 = ((char*)((ng36)));
    t15 = ((char*)((ng37)));
    memset(t21, 0, 8);
    t19 = (t14 + 4);
    t20 = (t15 + 4);
    t24 = *((unsigned int *)t14);
    t25 = *((unsigned int *)t15);
    t26 = (t24 ^ t25);
    t27 = *((unsigned int *)t19);
    t28 = *((unsigned int *)t20);
    t29 = (t27 ^ t28);
    t30 = (t26 | t29);
    t31 = *((unsigned int *)t19);
    t32 = *((unsigned int *)t20);
    t33 = (t31 | t32);
    t34 = (~(t33));
    t35 = (t30 & t34);
    if (t35 != 0)
        goto LAB66;

LAB63:    if (t33 != 0)
        goto LAB65;

LAB64:    *((unsigned int *)t21) = 1;

LAB66:    memset(t37, 0, 8);
    t23 = (t21 + 4);
    t39 = *((unsigned int *)t23);
    t40 = (~(t39));
    t41 = *((unsigned int *)t21);
    t42 = (t41 & t40);
    t43 = (t42 & 1U);
    if (t43 != 0)
        goto LAB67;

LAB68:    if (*((unsigned int *)t23) != 0)
        goto LAB69;

LAB70:    t46 = *((unsigned int *)t7);
    t47 = *((unsigned int *)t37);
    t48 = (t46 & t47);
    *((unsigned int *)t45) = t48;
    t38 = (t7 + 4);
    t44 = (t37 + 4);
    t49 = (t45 + 4);
    t52 = *((unsigned int *)t38);
    t53 = *((unsigned int *)t44);
    t54 = (t52 | t53);
    *((unsigned int *)t49) = t54;
    t55 = *((unsigned int *)t49);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB71;

LAB72:
LAB73:    goto LAB62;

LAB65:    t22 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB66;

LAB67:    *((unsigned int *)t37) = 1;
    goto LAB70;

LAB69:    t36 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB70;

LAB71:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t49);
    *((unsigned int *)t45) = (t57 | t58);
    t50 = (t7 + 4);
    t51 = (t37 + 4);
    t61 = *((unsigned int *)t7);
    t62 = (~(t61));
    t63 = *((unsigned int *)t50);
    t64 = (~(t63));
    t65 = *((unsigned int *)t37);
    t66 = (~(t65));
    t67 = *((unsigned int *)t51);
    t68 = (~(t67));
    t69 = (t62 & t64);
    t70 = (t66 & t68);
    t71 = (~(t69));
    t72 = (~(t70));
    t73 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t73 & t71);
    t74 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t74 & t72);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t71);
    t76 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t76 & t72);
    goto LAB73;

LAB74:
LAB77:    t60 = (t0 + 21728U);
    t77 = *((char **)t60);
    t60 = (t77 + 4);
    t85 = *((unsigned int *)t60);
    t86 = (~(t85));
    t87 = *((unsigned int *)t77);
    t88 = (t87 & t86);
    t89 = (t88 != 0);
    if (t89 > 0)
        goto LAB78;

LAB79:    t2 = (t0 + 22368U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB87;

LAB88:
LAB89:
LAB80:    goto LAB76;

LAB78:    t83 = (t0 + 21728U);
    t84 = *((char **)t83);
    t83 = (t0 + 39264);
    t90 = (t0 + 14840);
    t91 = xsi_create_subprogram_invocation(t83, 0, t0, t90, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t90, t91);
    t92 = (t0 + 31728);
    xsi_vlogvar_assign_value(t92, t84, 0, 0, 1);

LAB83:    t93 = (t0 + 39360);
    t94 = *((char **)t93);
    t95 = (t94 + 80U);
    t96 = *((char **)t95);
    t97 = (t96 + 272U);
    t98 = *((char **)t97);
    t99 = (t98 + 0U);
    t100 = *((char **)t99);
    t103 = ((int  (*)(char *, char *))t100)(t0, t94);

LAB85:    if (t103 != 0)
        goto LAB86;

LAB81:    t94 = (t0 + 14840);
    xsi_vlog_subprogram_popinvocation(t94);

LAB82:    t101 = (t0 + 39360);
    t102 = *((char **)t101);
    t101 = (t0 + 14840);
    t104 = (t0 + 39264);
    t105 = 0;
    xsi_delete_subprogram_invocation(t101, t102, t0, t104, t105);
    goto LAB80;

LAB84:;
LAB86:    t93 = (t0 + 39456U);
    *((char **)t93) = &&LAB83;
    goto LAB1;

LAB87:    t4 = (t0 + 18848U);
    t5 = *((char **)t4);
    t4 = (t0 + 21728U);
    t8 = *((char **)t4);
    t4 = (t0 + 39264);
    t14 = (t0 + 13976);
    t15 = xsi_create_subprogram_invocation(t4, 0, t0, t14, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t14, t15);
    t19 = (t0 + 30928);
    xsi_vlogvar_assign_value(t19, t5, 0, 0, 10);
    t20 = (t0 + 31088);
    xsi_vlogvar_assign_value(t20, t8, 0, 0, 1);

LAB92:    t22 = (t0 + 39360);
    t23 = *((char **)t22);
    t36 = (t23 + 80U);
    t38 = *((char **)t36);
    t44 = (t38 + 272U);
    t49 = *((char **)t44);
    t50 = (t49 + 0U);
    t51 = *((char **)t50);
    t69 = ((int  (*)(char *, char *))t51)(t0, t23);

LAB94:    if (t69 != 0)
        goto LAB95;

LAB90:    t23 = (t0 + 13976);
    xsi_vlog_subprogram_popinvocation(t23);

LAB91:    t59 = (t0 + 39360);
    t60 = *((char **)t59);
    t59 = (t0 + 13976);
    t77 = (t0 + 39264);
    t83 = 0;
    xsi_delete_subprogram_invocation(t59, t60, t0, t77, t83);
    goto LAB89;

LAB93:;
LAB95:    t22 = (t0 + 39456U);
    *((char **)t22) = &&LAB92;
    goto LAB1;

LAB97:    t4 = (t0 + 18848U);
    t5 = *((char **)t4);
    t4 = (t0 + 21728U);
    t8 = *((char **)t4);
    t4 = (t0 + 39264);
    t14 = (t0 + 13976);
    t15 = xsi_create_subprogram_invocation(t4, 0, t0, t14, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t14, t15);
    t19 = (t0 + 30928);
    xsi_vlogvar_assign_value(t19, t5, 0, 0, 10);
    t20 = (t0 + 31088);
    xsi_vlogvar_assign_value(t20, t8, 0, 0, 1);

LAB102:    t22 = (t0 + 39360);
    t23 = *((char **)t22);
    t36 = (t23 + 80U);
    t38 = *((char **)t36);
    t44 = (t38 + 272U);
    t49 = *((char **)t44);
    t50 = (t49 + 0U);
    t51 = *((char **)t50);
    t69 = ((int  (*)(char *, char *))t51)(t0, t23);

LAB104:    if (t69 != 0)
        goto LAB105;

LAB100:    t23 = (t0 + 13976);
    xsi_vlog_subprogram_popinvocation(t23);

LAB101:    t59 = (t0 + 39360);
    t60 = *((char **)t59);
    t59 = (t0 + 13976);
    t77 = (t0 + 39264);
    t83 = 0;
    xsi_delete_subprogram_invocation(t59, t60, t0, t77, t83);
    goto LAB99;

LAB103:;
LAB105:    t22 = (t0 + 39456U);
    *((char **)t22) = &&LAB102;
    goto LAB1;

LAB106:    t4 = (t0 + 17568U);
    t5 = *((char **)t4);
    t4 = (t0 + 21888U);
    t8 = *((char **)t4);
    t4 = (t0 + 17728U);
    t14 = *((char **)t4);
    t4 = (t0 + 19328U);
    t15 = *((char **)t4);
    t4 = (t0 + 19488U);
    t19 = *((char **)t4);
    t4 = (t0 + 39264);
    t20 = (t0 + 12680);
    t22 = xsi_create_subprogram_invocation(t4, 0, t0, t20, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t20, t22);
    t23 = (t0 + 28048);
    xsi_vlogvar_assign_value(t23, t5, 0, 0, 10);
    t36 = (t0 + 28208);
    xsi_vlogvar_assign_value(t36, t8, 0, 0, 1);
    t38 = (t0 + 28368);
    xsi_vlogvar_assign_value(t38, t14, 0, 0, 128);
    t44 = (t0 + 28528);
    xsi_vlogvar_assign_value(t44, t15, 0, 0, 1);
    t49 = (t0 + 28688);
    xsi_vlogvar_assign_value(t49, t19, 0, 0, 1);

LAB111:    t50 = (t0 + 39360);
    t51 = *((char **)t50);
    t59 = (t51 + 80U);
    t60 = *((char **)t59);
    t77 = (t60 + 272U);
    t83 = *((char **)t77);
    t84 = (t83 + 0U);
    t90 = *((char **)t84);
    t69 = ((int  (*)(char *, char *))t90)(t0, t51);

LAB113:    if (t69 != 0)
        goto LAB114;

LAB109:    t51 = (t0 + 12680);
    xsi_vlog_subprogram_popinvocation(t51);

LAB110:    t91 = (t0 + 39360);
    t92 = *((char **)t91);
    t91 = (t0 + 12680);
    t93 = (t0 + 39264);
    t94 = 0;
    xsi_delete_subprogram_invocation(t91, t92, t0, t93, t94);
    goto LAB108;

LAB112:;
LAB114:    t50 = (t0 + 39456U);
    *((char **)t50) = &&LAB111;
    goto LAB1;

LAB115:    t4 = (t0 + 18848U);
    t5 = *((char **)t4);
    t4 = (t0 + 22048U);
    t8 = *((char **)t4);
    t4 = (t0 + 19008U);
    t14 = *((char **)t4);
    t4 = (t0 + 39264);
    t15 = (t0 + 13112);
    t19 = xsi_create_subprogram_invocation(t4, 0, t0, t15, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t15, t19);
    t20 = (t0 + 29328);
    xsi_vlogvar_assign_value(t20, t5, 0, 0, 10);
    t22 = (t0 + 29488);
    xsi_vlogvar_assign_value(t22, t8, 0, 0, 1);
    t23 = (t0 + 29648);
    xsi_vlogvar_assign_value(t23, t14, 0, 0, 128);

LAB120:    t36 = (t0 + 39360);
    t38 = *((char **)t36);
    t44 = (t38 + 80U);
    t49 = *((char **)t44);
    t50 = (t49 + 272U);
    t51 = *((char **)t50);
    t59 = (t51 + 0U);
    t60 = *((char **)t59);
    t69 = ((int  (*)(char *, char *))t60)(t0, t38);

LAB122:    if (t69 != 0)
        goto LAB123;

LAB118:    t38 = (t0 + 13112);
    xsi_vlog_subprogram_popinvocation(t38);

LAB119:    t77 = (t0 + 39360);
    t83 = *((char **)t77);
    t77 = (t0 + 13112);
    t84 = (t0 + 39264);
    t90 = 0;
    xsi_delete_subprogram_invocation(t77, t83, t0, t84, t90);
    goto LAB117;

LAB121:;
LAB123:    t36 = (t0 + 39456U);
    *((char **)t36) = &&LAB120;
    goto LAB1;

}

static void Always_3402_13(char *t0)
{
    char t6[8];
    char t19[8];
    char t26[8];
    char t66[8];
    char t80[8];
    char t87[8];
    char t124[8];
    char t127[8];
    char t146[8];
    char t151[24];
    char t155[16];
    char t156[16];
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
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
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
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
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
    unsigned int t77;
    char *t78;
    char *t79;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    char *t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;
    char *t122;
    char *t123;
    char *t125;
    char *t126;
    char *t128;
    char *t129;
    char *t130;
    char *t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    char *t137;
    char *t138;
    char *t139;
    char *t140;
    char *t141;
    int t142;
    char *t143;
    char *t144;
    char *t145;
    char *t147;
    char *t148;
    char *t149;
    char *t150;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;

LAB0:    t1 = (t0 + 39704U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 40960);
    *((int *)t2) = 1;
    t3 = (t0 + 39736);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 21248U);
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
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB10;

LAB11:    memcpy(t26, t6, 8);

LAB12:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB20;

LAB21:
LAB46:    t2 = ((char*)((ng4)));
    t3 = (t0 + 25328);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB22:    t2 = ((char*)((ng38)));
    t3 = ((char*)((ng38)));
    xsi_vlog_unsigned_equal(t151, 80, t2, 80, t3, 80);
    memset(t6, 0, 8);
    t4 = (t151 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t151);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t4) != 0)
        goto LAB49;

LAB50:    t12 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t12);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB51;

LAB52:    memcpy(t26, t6, 8);

LAB53:    memset(t66, 0, 8);
    t41 = (t26 + 4);
    t59 = *((unsigned int *)t41);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 & 1U);
    if (t63 != 0)
        goto LAB61;

LAB62:    if (*((unsigned int *)t41) != 0)
        goto LAB63;

LAB64:    t64 = (t66 + 4);
    t67 = *((unsigned int *)t66);
    t68 = *((unsigned int *)t64);
    t69 = (t67 || t68);
    if (t69 > 0)
        goto LAB65;

LAB66:    memcpy(t124, t66, 8);

LAB67:    t102 = (t124 + 4);
    t119 = *((unsigned int *)t102);
    t120 = (~(t119));
    t152 = *((unsigned int *)t124);
    t153 = (t152 & t120);
    t154 = (t153 != 0);
    if (t154 > 0)
        goto LAB79;

LAB80:
LAB81:    t2 = ((char*)((ng38)));
    t3 = ((char*)((ng38)));
    xsi_vlog_unsigned_equal(t151, 80, t2, 80, t3, 80);
    memset(t6, 0, 8);
    t4 = (t151 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t151);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t4) != 0)
        goto LAB85;

LAB86:    t12 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t12);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB87;

LAB88:    memcpy(t26, t6, 8);

LAB89:    memset(t66, 0, 8);
    t41 = (t26 + 4);
    t59 = *((unsigned int *)t41);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 & 1U);
    if (t63 != 0)
        goto LAB97;

LAB98:    if (*((unsigned int *)t41) != 0)
        goto LAB99;

LAB100:    t64 = (t66 + 4);
    t67 = *((unsigned int *)t66);
    t68 = *((unsigned int *)t64);
    t69 = (t67 || t68);
    if (t69 > 0)
        goto LAB101;

LAB102:    memcpy(t124, t66, 8);

LAB103:    t102 = (t124 + 4);
    t119 = *((unsigned int *)t102);
    t120 = (~(t119));
    t152 = *((unsigned int *)t124);
    t153 = (t152 & t120);
    t154 = (t153 != 0);
    if (t154 > 0)
        goto LAB115;

LAB116:
LAB117:    t2 = (t0 + 25328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB119;

LAB120:    if (*((unsigned int *)t5) != 0)
        goto LAB121;

LAB122:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB123;

LAB124:    memcpy(t87, t6, 8);

LAB125:    t101 = (t87 + 4);
    t109 = *((unsigned int *)t101);
    t111 = (~(t109));
    t112 = *((unsigned int *)t87);
    t113 = (t112 & t111);
    t114 = (t113 != 0);
    if (t114 > 0)
        goto LAB147;

LAB148:
LAB149:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t17 = (t0 + 21408U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t17) != 0)
        goto LAB15;

LAB16:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t6 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t19) = 1;
    goto LAB16;

LAB15:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB16;

LAB17:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t6 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB19;

LAB20:
LAB23:    t64 = (t0 + 21888U);
    t65 = *((char **)t64);
    memset(t66, 0, 8);
    t64 = (t65 + 4);
    t67 = *((unsigned int *)t64);
    t68 = (~(t67));
    t69 = *((unsigned int *)t65);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t64) != 0)
        goto LAB26;

LAB27:    t73 = (t66 + 4);
    t74 = *((unsigned int *)t66);
    t75 = (!(t74));
    t76 = *((unsigned int *)t73);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB28;

LAB29:    memcpy(t87, t66, 8);

LAB30:    t115 = (t87 + 4);
    t116 = *((unsigned int *)t115);
    t117 = (~(t116));
    t118 = *((unsigned int *)t87);
    t119 = (t118 & t117);
    t120 = (t119 != 0);
    if (t120 > 0)
        goto LAB38;

LAB39:
LAB45:    t2 = ((char*)((ng4)));
    t3 = (t0 + 25328);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB40:    goto LAB22;

LAB24:    *((unsigned int *)t66) = 1;
    goto LAB27;

LAB26:    t72 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB27;

LAB28:    t78 = (t0 + 22048U);
    t79 = *((char **)t78);
    memset(t80, 0, 8);
    t78 = (t79 + 4);
    t81 = *((unsigned int *)t78);
    t82 = (~(t81));
    t83 = *((unsigned int *)t79);
    t84 = (t83 & t82);
    t85 = (t84 & 1U);
    if (t85 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t78) != 0)
        goto LAB33;

LAB34:    t88 = *((unsigned int *)t66);
    t89 = *((unsigned int *)t80);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = (t66 + 4);
    t92 = (t80 + 4);
    t93 = (t87 + 4);
    t94 = *((unsigned int *)t91);
    t95 = *((unsigned int *)t92);
    t96 = (t94 | t95);
    *((unsigned int *)t93) = t96;
    t97 = *((unsigned int *)t93);
    t98 = (t97 != 0);
    if (t98 == 1)
        goto LAB35;

LAB36:
LAB37:    goto LAB30;

LAB31:    *((unsigned int *)t80) = 1;
    goto LAB34;

LAB33:    t86 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t86) = 1;
    goto LAB34;

LAB35:    t99 = *((unsigned int *)t87);
    t100 = *((unsigned int *)t93);
    *((unsigned int *)t87) = (t99 | t100);
    t101 = (t66 + 4);
    t102 = (t80 + 4);
    t103 = *((unsigned int *)t101);
    t104 = (~(t103));
    t105 = *((unsigned int *)t66);
    t106 = (t105 & t104);
    t107 = *((unsigned int *)t102);
    t108 = (~(t107));
    t109 = *((unsigned int *)t80);
    t110 = (t109 & t108);
    t111 = (~(t106));
    t112 = (~(t110));
    t113 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t113 & t111);
    t114 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t114 & t112);
    goto LAB37;

LAB38:
LAB41:    t121 = (t0 + 17568U);
    t122 = *((char **)t121);
    t121 = (t0 + 21888U);
    t123 = *((char **)t121);
    memcpy(t124, t123, 8);
    t121 = (t0 + 18848U);
    t125 = *((char **)t121);
    t121 = (t0 + 22048U);
    t126 = *((char **)t121);
    memcpy(t127, t126, 8);
    t121 = (t0 + 39512);
    t128 = (t0 + 16136);
    t129 = xsi_create_subprogram_invocation(t121, 0, t0, t128, 0, 0);
    t130 = (t0 + 33168);
    xsi_vlogvar_assign_value(t130, t122, 0, 0, 10);
    t131 = (t0 + 33328);
    xsi_vlogvar_assign_value(t131, t124, 0, 0, 32);
    t132 = (t0 + 33488);
    xsi_vlogvar_assign_value(t132, t125, 0, 0, 10);
    t133 = (t0 + 33648);
    xsi_vlogvar_assign_value(t133, t127, 0, 0, 32);

LAB42:    t134 = (t0 + 39608);
    t135 = *((char **)t134);
    t136 = (t135 + 80U);
    t137 = *((char **)t136);
    t138 = (t137 + 272U);
    t139 = *((char **)t138);
    t140 = (t139 + 0U);
    t141 = *((char **)t140);
    t142 = ((int  (*)(char *, char *))t141)(t0, t135);
    if (t142 != 0)
        goto LAB44;

LAB43:    t135 = (t0 + 39608);
    t143 = *((char **)t135);
    t135 = (t0 + 33808);
    t144 = (t135 + 56U);
    t145 = *((char **)t144);
    memcpy(t146, t145, 8);
    t147 = (t0 + 16136);
    t148 = (t0 + 39512);
    t149 = 0;
    xsi_delete_subprogram_invocation(t147, t143, t0, t148, t149);
    t150 = (t0 + 25328);
    xsi_vlogvar_wait_assign_value(t150, t146, 0, 0, 1, 0LL);
    goto LAB40;

LAB44:    t134 = (t0 + 39704U);
    *((char **)t134) = &&LAB42;
    goto LAB1;

LAB47:    *((unsigned int *)t6) = 1;
    goto LAB50;

LAB49:    t5 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB50;

LAB51:    t13 = (t0 + 21888U);
    t17 = *((char **)t13);
    memset(t19, 0, 8);
    t13 = (t17 + 4);
    t20 = *((unsigned int *)t13);
    t21 = (~(t20));
    t22 = *((unsigned int *)t17);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t13) != 0)
        goto LAB56;

LAB57:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t25 = (t6 + 4);
    t30 = (t19 + 4);
    t31 = (t26 + 4);
    t33 = *((unsigned int *)t25);
    t34 = *((unsigned int *)t30);
    t35 = (t33 | t34);
    *((unsigned int *)t31) = t35;
    t36 = *((unsigned int *)t31);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB58;

LAB59:
LAB60:    goto LAB53;

LAB54:    *((unsigned int *)t19) = 1;
    goto LAB57;

LAB56:    t18 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB57;

LAB58:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t31);
    *((unsigned int *)t26) = (t38 | t39);
    t32 = (t6 + 4);
    t40 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t32);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t40);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t54 & t52);
    t55 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB60;

LAB61:    *((unsigned int *)t66) = 1;
    goto LAB64;

LAB63:    t58 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB64;

LAB65:    t65 = (t0 + 22048U);
    t72 = *((char **)t65);
    memset(t80, 0, 8);
    t65 = (t72 + 4);
    t70 = *((unsigned int *)t65);
    t71 = (~(t70));
    t74 = *((unsigned int *)t72);
    t75 = (t74 & t71);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB71;

LAB69:    if (*((unsigned int *)t65) == 0)
        goto LAB68;

LAB70:    t73 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t73) = 1;

LAB71:    memset(t87, 0, 8);
    t78 = (t80 + 4);
    t77 = *((unsigned int *)t78);
    t81 = (~(t77));
    t82 = *((unsigned int *)t80);
    t83 = (t82 & t81);
    t84 = (t83 & 1U);
    if (t84 != 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t78) != 0)
        goto LAB74;

LAB75:    t85 = *((unsigned int *)t66);
    t88 = *((unsigned int *)t87);
    t89 = (t85 & t88);
    *((unsigned int *)t124) = t89;
    t86 = (t66 + 4);
    t91 = (t87 + 4);
    t92 = (t124 + 4);
    t90 = *((unsigned int *)t86);
    t94 = *((unsigned int *)t91);
    t95 = (t90 | t94);
    *((unsigned int *)t92) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 != 0);
    if (t97 == 1)
        goto LAB76;

LAB77:
LAB78:    goto LAB67;

LAB68:    *((unsigned int *)t80) = 1;
    goto LAB71;

LAB72:    *((unsigned int *)t87) = 1;
    goto LAB75;

LAB74:    t79 = (t87 + 4);
    *((unsigned int *)t87) = 1;
    *((unsigned int *)t79) = 1;
    goto LAB75;

LAB76:    t98 = *((unsigned int *)t124);
    t99 = *((unsigned int *)t92);
    *((unsigned int *)t124) = (t98 | t99);
    t93 = (t66 + 4);
    t101 = (t87 + 4);
    t100 = *((unsigned int *)t66);
    t103 = (~(t100));
    t104 = *((unsigned int *)t93);
    t105 = (~(t104));
    t107 = *((unsigned int *)t87);
    t108 = (~(t107));
    t109 = *((unsigned int *)t101);
    t111 = (~(t109));
    t106 = (t103 & t105);
    t110 = (t108 & t111);
    t112 = (~(t106));
    t113 = (~(t110));
    t114 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t114 & t112);
    t116 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t116 & t113);
    t117 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t117 & t112);
    t118 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t118 & t113);
    goto LAB78;

LAB79:
LAB82:    t115 = ((char*)((ng4)));
    t121 = (t0 + 25328);
    xsi_vlogvar_wait_assign_value(t121, t115, 0, 0, 1, 0LL);
    goto LAB81;

LAB83:    *((unsigned int *)t6) = 1;
    goto LAB86;

LAB85:    t5 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB86;

LAB87:    t13 = (t0 + 22048U);
    t17 = *((char **)t13);
    memset(t19, 0, 8);
    t13 = (t17 + 4);
    t20 = *((unsigned int *)t13);
    t21 = (~(t20));
    t22 = *((unsigned int *)t17);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB90;

LAB91:    if (*((unsigned int *)t13) != 0)
        goto LAB92;

LAB93:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t25 = (t6 + 4);
    t30 = (t19 + 4);
    t31 = (t26 + 4);
    t33 = *((unsigned int *)t25);
    t34 = *((unsigned int *)t30);
    t35 = (t33 | t34);
    *((unsigned int *)t31) = t35;
    t36 = *((unsigned int *)t31);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB94;

LAB95:
LAB96:    goto LAB89;

LAB90:    *((unsigned int *)t19) = 1;
    goto LAB93;

LAB92:    t18 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB93;

LAB94:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t31);
    *((unsigned int *)t26) = (t38 | t39);
    t32 = (t6 + 4);
    t40 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t32);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t40);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t54 & t52);
    t55 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB96;

LAB97:    *((unsigned int *)t66) = 1;
    goto LAB100;

LAB99:    t58 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB100;

LAB101:    t65 = (t0 + 21888U);
    t72 = *((char **)t65);
    memset(t80, 0, 8);
    t65 = (t72 + 4);
    t70 = *((unsigned int *)t65);
    t71 = (~(t70));
    t74 = *((unsigned int *)t72);
    t75 = (t74 & t71);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB107;

LAB105:    if (*((unsigned int *)t65) == 0)
        goto LAB104;

LAB106:    t73 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t73) = 1;

LAB107:    memset(t87, 0, 8);
    t78 = (t80 + 4);
    t77 = *((unsigned int *)t78);
    t81 = (~(t77));
    t82 = *((unsigned int *)t80);
    t83 = (t82 & t81);
    t84 = (t83 & 1U);
    if (t84 != 0)
        goto LAB108;

LAB109:    if (*((unsigned int *)t78) != 0)
        goto LAB110;

LAB111:    t85 = *((unsigned int *)t66);
    t88 = *((unsigned int *)t87);
    t89 = (t85 & t88);
    *((unsigned int *)t124) = t89;
    t86 = (t66 + 4);
    t91 = (t87 + 4);
    t92 = (t124 + 4);
    t90 = *((unsigned int *)t86);
    t94 = *((unsigned int *)t91);
    t95 = (t90 | t94);
    *((unsigned int *)t92) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 != 0);
    if (t97 == 1)
        goto LAB112;

LAB113:
LAB114:    goto LAB103;

LAB104:    *((unsigned int *)t80) = 1;
    goto LAB107;

LAB108:    *((unsigned int *)t87) = 1;
    goto LAB111;

LAB110:    t79 = (t87 + 4);
    *((unsigned int *)t87) = 1;
    *((unsigned int *)t79) = 1;
    goto LAB111;

LAB112:    t98 = *((unsigned int *)t124);
    t99 = *((unsigned int *)t92);
    *((unsigned int *)t124) = (t98 | t99);
    t93 = (t66 + 4);
    t101 = (t87 + 4);
    t100 = *((unsigned int *)t66);
    t103 = (~(t100));
    t104 = *((unsigned int *)t93);
    t105 = (~(t104));
    t107 = *((unsigned int *)t87);
    t108 = (~(t107));
    t109 = *((unsigned int *)t101);
    t111 = (~(t109));
    t106 = (t103 & t105);
    t110 = (t108 & t111);
    t112 = (~(t106));
    t113 = (~(t110));
    t114 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t114 & t112);
    t116 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t116 & t113);
    t117 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t117 & t112);
    t118 = *((unsigned int *)t124);
    *((unsigned int *)t124) = (t118 & t113);
    goto LAB114;

LAB115:
LAB118:    t115 = ((char*)((ng4)));
    t121 = (t0 + 25328);
    xsi_vlogvar_wait_assign_value(t121, t115, 0, 0, 1, 0LL);
    goto LAB117;

LAB119:    *((unsigned int *)t6) = 1;
    goto LAB122;

LAB121:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB122;

LAB123:    t17 = (t0 + 21888U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB126;

LAB127:    if (*((unsigned int *)t17) != 0)
        goto LAB128;

LAB129:    t30 = (t19 + 4);
    t27 = *((unsigned int *)t19);
    t28 = (!(t27));
    t29 = *((unsigned int *)t30);
    t33 = (t28 || t29);
    if (t33 > 0)
        goto LAB130;

LAB131:    memcpy(t66, t19, 8);

LAB132:    memset(t80, 0, 8);
    t73 = (t66 + 4);
    t67 = *((unsigned int *)t73);
    t68 = (~(t67));
    t69 = *((unsigned int *)t66);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB140;

LAB141:    if (*((unsigned int *)t73) != 0)
        goto LAB142;

LAB143:    t74 = *((unsigned int *)t6);
    t75 = *((unsigned int *)t80);
    t76 = (t74 & t75);
    *((unsigned int *)t87) = t76;
    t79 = (t6 + 4);
    t86 = (t80 + 4);
    t91 = (t87 + 4);
    t77 = *((unsigned int *)t79);
    t81 = *((unsigned int *)t86);
    t82 = (t77 | t81);
    *((unsigned int *)t91) = t82;
    t83 = *((unsigned int *)t91);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB144;

LAB145:
LAB146:    goto LAB125;

LAB126:    *((unsigned int *)t19) = 1;
    goto LAB129;

LAB128:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB129;

LAB130:    t31 = (t0 + 22048U);
    t32 = *((char **)t31);
    memset(t26, 0, 8);
    t31 = (t32 + 4);
    t34 = *((unsigned int *)t31);
    t35 = (~(t34));
    t36 = *((unsigned int *)t32);
    t37 = (t36 & t35);
    t38 = (t37 & 1U);
    if (t38 != 0)
        goto LAB133;

LAB134:    if (*((unsigned int *)t31) != 0)
        goto LAB135;

LAB136:    t39 = *((unsigned int *)t19);
    t42 = *((unsigned int *)t26);
    t43 = (t39 | t42);
    *((unsigned int *)t66) = t43;
    t41 = (t19 + 4);
    t58 = (t26 + 4);
    t64 = (t66 + 4);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t58);
    t46 = (t44 | t45);
    *((unsigned int *)t64) = t46;
    t47 = *((unsigned int *)t64);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB137;

LAB138:
LAB139:    goto LAB132;

LAB133:    *((unsigned int *)t26) = 1;
    goto LAB136;

LAB135:    t40 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB136;

LAB137:    t49 = *((unsigned int *)t66);
    t52 = *((unsigned int *)t64);
    *((unsigned int *)t66) = (t49 | t52);
    t65 = (t19 + 4);
    t72 = (t26 + 4);
    t53 = *((unsigned int *)t65);
    t54 = (~(t53));
    t55 = *((unsigned int *)t19);
    t50 = (t55 & t54);
    t56 = *((unsigned int *)t72);
    t57 = (~(t56));
    t59 = *((unsigned int *)t26);
    t51 = (t59 & t57);
    t60 = (~(t50));
    t61 = (~(t51));
    t62 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t62 & t60);
    t63 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t63 & t61);
    goto LAB139;

LAB140:    *((unsigned int *)t80) = 1;
    goto LAB143;

LAB142:    t78 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB143;

LAB144:    t85 = *((unsigned int *)t87);
    t88 = *((unsigned int *)t91);
    *((unsigned int *)t87) = (t85 | t88);
    t92 = (t6 + 4);
    t93 = (t80 + 4);
    t89 = *((unsigned int *)t6);
    t90 = (~(t89));
    t94 = *((unsigned int *)t92);
    t95 = (~(t94));
    t96 = *((unsigned int *)t80);
    t97 = (~(t96));
    t98 = *((unsigned int *)t93);
    t99 = (~(t98));
    t106 = (t90 & t95);
    t110 = (t97 & t99);
    t100 = (~(t106));
    t103 = (~(t110));
    t104 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t104 & t100);
    t105 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t105 & t103);
    t107 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t107 & t100);
    t108 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t108 & t103);
    goto LAB146;

LAB147:
LAB150:    t102 = ((char*)((ng0)));
    t115 = ((char*)((ng2)));
    t121 = xsi_vlog_time(t155, 1.0000000000000000, 1.0000000000000000);
    xsi_vlogfile_fwrite(*((unsigned int *)t102), 0, 0, 1, ng39, 3, t0, (char)118, t115, 128, (char)118, t155, 64);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 21888U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t4 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB151;

LAB152:    if (*((unsigned int *)t3) != 0)
        goto LAB153;

LAB154:    t12 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t12);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB155;

LAB156:    t20 = *((unsigned int *)t6);
    t21 = (~(t20));
    t22 = *((unsigned int *)t12);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB157;

LAB158:    if (*((unsigned int *)t12) > 0)
        goto LAB159;

LAB160:    if (*((unsigned int *)t6) > 0)
        goto LAB161;

LAB162:    memcpy(t155, t17, 16);

LAB163:    t18 = (t0 + 17568U);
    t25 = *((char **)t18);
    t18 = (t0 + 22048U);
    t30 = *((char **)t18);
    memset(t19, 0, 8);
    t18 = (t30 + 4);
    t24 = *((unsigned int *)t18);
    t27 = (~(t24));
    t28 = *((unsigned int *)t30);
    t29 = (t28 & t27);
    t33 = (t29 & 1U);
    if (t33 != 0)
        goto LAB164;

LAB165:    if (*((unsigned int *)t18) != 0)
        goto LAB166;

LAB167:    t32 = (t19 + 4);
    t34 = *((unsigned int *)t19);
    t35 = *((unsigned int *)t32);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB168;

LAB169:    t37 = *((unsigned int *)t19);
    t38 = (~(t37));
    t39 = *((unsigned int *)t32);
    t42 = (t38 || t39);
    if (t42 > 0)
        goto LAB170;

LAB171:    if (*((unsigned int *)t32) > 0)
        goto LAB172;

LAB173:    if (*((unsigned int *)t19) > 0)
        goto LAB174;

LAB175:    memcpy(t156, t41, 16);

LAB176:    t58 = (t0 + 18848U);
    t64 = *((char **)t58);
    xsi_vlogfile_fwrite(*((unsigned int *)t2), 0, 0, 1, ng40, 5, t0, (char)118, t155, 40, (char)118, t25, 10, (char)118, t156, 40, (char)118, t64, 10);
    goto LAB149;

LAB151:    *((unsigned int *)t6) = 1;
    goto LAB154;

LAB153:    t5 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB154;

LAB155:    t13 = ((char*)((ng41)));
    goto LAB156;

LAB157:    t17 = ((char*)((ng42)));
    goto LAB158;

LAB159:    xsi_vlog_unsigned_bit_combine(t155, 40, t13, 40, t17, 40);
    goto LAB163;

LAB161:    memcpy(t155, t13, 16);
    goto LAB163;

LAB164:    *((unsigned int *)t19) = 1;
    goto LAB167;

LAB166:    t31 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB167;

LAB168:    t40 = ((char*)((ng41)));
    goto LAB169;

LAB170:    t41 = ((char*)((ng42)));
    goto LAB171;

LAB172:    xsi_vlog_unsigned_bit_combine(t156, 40, t40, 40, t41, 40);
    goto LAB176;

LAB174:    memcpy(t156, t40, 16);
    goto LAB176;

}

static void implSig1_execute(char *t0)
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

LAB0:    t1 = (t0 + 39952U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng15)));
    t3 = (t0 + 41744);
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

static void implSig2_execute(char *t0)
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

LAB0:    t1 = (t0 + 40200U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng15)));
    t3 = (t0 + 41808);
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

static void implSig3_execute(char *t0)
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

LAB0:    t1 = (t0 + 40448U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng15)));
    t3 = (t0 + 41872);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1023U;
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
    xsi_driver_vfirst_trans(t3, 0, 9);

LAB1:    return;
}


extern void xilinxcorelib_ver_m_03165991153648205951_2490384146_init()
{
	static char *pe[] = {(void *)Cont_2330_0,(void *)Cont_2331_1,(void *)Cont_2332_2,(void *)Cont_2336_3,(void *)Cont_2337_4,(void *)Cont_2338_5,(void *)Cont_2339_6,(void *)Cont_2340_7,(void *)Cont_2341_8,(void *)Cont_2345_9,(void *)Cont_2349_10,(void *)Initial_2918_11,(void *)Always_3061_12,(void *)Always_3402_13,(void *)implSig1_execute,(void *)implSig2_execute,(void *)implSig3_execute};
	static char *se[] = {(void *)sp_write_a,(void *)sp_write_b,(void *)sp_read_a,(void *)sp_read_b,(void *)sp_reset_a,(void *)sp_reset_b,(void *)sp_init_memory,(void *)sp_log2roundup,(void *)sp_collision_check};
	xsi_register_didat("xilinxcorelib_ver_m_03165991153648205951_2490384146", "isim/StreamInputHandler_ReferenceReader_SmithWatermanArray_EngineCtrl_CellScoreFilter_Interface_tb_isim_beh.exe.sim/xilinxcorelib_ver/m_03165991153648205951_2490384146.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
