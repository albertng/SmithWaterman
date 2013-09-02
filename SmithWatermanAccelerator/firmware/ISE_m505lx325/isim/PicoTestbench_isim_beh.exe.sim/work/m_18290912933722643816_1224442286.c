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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/PicoTestbench.v";
static unsigned int ng1[] = {3964082448U, 0U, 36244169U, 0U, 3330713593U, 0U, 442163402U, 0U, 2886968005U, 0U, 348008105U, 0U, 675179041U, 0U, 3817453149U, 0U};
static unsigned int ng2[] = {3783505928U, 0U, 426952168U, 0U, 31525478U, 0U, 187662404U, 0U, 2167998723U, 0U, 2595094596U, 0U, 34253560U, 0U, 671785610U, 0U};
static unsigned int ng3[] = {2410457724U, 0U, 867836028U, 0U, 2416714048U, 0U, 831634995U, 0U, 1875282564U, 0U, 2353199702U, 0U, 2207553322U, 0U, 2235703332U, 0U};
static unsigned int ng4[] = {2425399878U, 0U, 592073U, 0U, 2651495044U, 0U, 2210671500U, 0U, 1804202026U, 0U, 1073889110U, 0U, 2727713954U, 0U, 169412913U, 0U};
static unsigned int ng5[] = {2687300283U, 0U, 982134697U, 0U, 2536073928U, 0U, 288433833U, 0U, 3435974426U, 0U, 3435973836U, 0U, 4009683148U, 0U, 1178643182U, 0U};
static unsigned int ng6[] = {1682606405U, 0U, 4198542U, 0U, 3242217492U, 0U, 340001809U, 0U, 604307906U, 0U, 3934851152U, 0U, 3794379434U, 0U, 2292869290U, 0U};
static unsigned int ng7[] = {1479627U, 0U, 370122890U, 0U, 2491571370U, 0U, 3994095418U, 0U, 1646472306U, 0U, 964698720U, 0U, 4003636259U, 0U, 2611110024U, 0U};
static unsigned int ng8[] = {2525757768U, 0U, 2584293382U, 0U, 1276888578U, 0U, 3299367578U, 0U, 2090996552U, 0U, 2399178968U, 0U, 1443497132U, 0U, 2156032257U, 0U};
static unsigned int ng9[] = {2309677060U, 0U, 2686495407U, 0U, 3263212072U, 0U, 3371879079U, 0U};
static const char *ng10 = "Writing ref seq to DRAM";
static int ng11[] = {0, 0};
static int ng12[] = {16, 0};
static int ng13[] = {32, 0};
static int ng14[] = {48, 0};
static int ng15[] = {64, 0};
static int ng16[] = {80, 0};
static int ng17[] = {96, 0};
static int ng18[] = {112, 0};
static int ng19[] = {128, 0};
static int ng20[] = {144, 0};
static int ng21[] = {160, 0};
static int ng22[] = {176, 0};
static int ng23[] = {192, 0};
static int ng24[] = {208, 0};
static int ng25[] = {224, 0};
static int ng26[] = {240, 0};
static int ng27[] = {0, 0, 0, 0};
static int ng28[] = {256, 0};
static const char *ng29 = "Streaming query seq to FPGA";
static unsigned int ng30[] = {8U, 0U, 0U, 0U, 64U, 0U, 128U, 0U};
static int ng31[] = {1, 0};
static const char *ng32 = "Streaming result from FPGA";
static const char *ng33 = "Stream:1 Query:%d Location:%d";
static const char *ng34 = "All Tests Successful!";



static void Initial_24_0(char *t0)
{
    char t23[32];
    char t33[8];
    char t40[8];
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
    char *t13;
    char *t14;
    char *t15;
    int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;

LAB0:    t1 = (t0 + 3640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(24, ng0);

LAB4:    xsi_set_current_line(26, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1288);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(27, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(28, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(29, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(30, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(31, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(33, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);
    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(41, ng0);
    t2 = (t0 + 3448);
    t3 = (t0 + 5800);
    t4 = *((char **)t3);
    t5 = (t0 + 5808);
    t6 = xsi_create_subprogram_invocation(t2, 0, *((char **)t5), ((char*)(t4)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t4)), t6);

LAB7:    t7 = (t0 + 3544);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = (t0 + 5808);
    t16 = ((int  (*)(char *, char *))t14)(*((char **)t15), t8);

LAB9:    if (t16 != 0)
        goto LAB10;

LAB5:    t8 = (t0 + 5840);
    t17 = *((char **)t8);
    xsi_vlog_subprogram_popinvocation(((char*)(t17)));

LAB6:    t18 = (t0 + 3544);
    t19 = *((char **)t18);
    t18 = (t0 + 5840);
    t20 = *((char **)t18);
    t21 = (t0 + 3448);
    t22 = 0;
    xsi_delete_subprogram_invocation(((char*)(t20)), t19, t0, t21, t22);
    xsi_set_current_line(44, ng0);
    xsi_vlogfile_write(1, 0, 0, ng10, 1, t0);
    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 127, 0);
    t6 = (t0 + 3448);
    t7 = (t0 + 5888);
    t8 = *((char **)t7);
    t9 = (t0 + 5912);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 5896);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 5904);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB13:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 5912);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB15:    if (t16 != 0)
        goto LAB16;

LAB11:    t17 = (t0 + 5952);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB12:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 5952);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(46, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 255, 128);
    t6 = (t0 + 3448);
    t7 = (t0 + 6016);
    t8 = *((char **)t7);
    t9 = (t0 + 6040);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6024);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6032);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB19:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 6040);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB21:    if (t16 != 0)
        goto LAB22;

LAB17:    t17 = (t0 + 6080);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB18:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6080);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1448);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 127, 0);
    t6 = (t0 + 3448);
    t7 = (t0 + 6144);
    t8 = *((char **)t7);
    t9 = (t0 + 6168);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6152);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6160);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB25:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 6168);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB27:    if (t16 != 0)
        goto LAB28;

LAB23:    t17 = (t0 + 6208);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB24:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6208);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1448);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 255, 128);
    t6 = (t0 + 3448);
    t7 = (t0 + 6272);
    t8 = *((char **)t7);
    t9 = (t0 + 6296);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6280);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6288);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB31:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 6296);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB33:    if (t16 != 0)
        goto LAB34;

LAB29:    t17 = (t0 + 6336);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB30:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6336);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1608);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 127, 0);
    t6 = (t0 + 3448);
    t7 = (t0 + 6400);
    t8 = *((char **)t7);
    t9 = (t0 + 6424);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6408);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6416);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB37:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 6424);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB39:    if (t16 != 0)
        goto LAB40;

LAB35:    t17 = (t0 + 6464);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB36:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6464);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 1608);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 255, 128);
    t6 = (t0 + 3448);
    t7 = (t0 + 6528);
    t8 = *((char **)t7);
    t9 = (t0 + 6552);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6536);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6544);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB43:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 6552);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB45:    if (t16 != 0)
        goto LAB46;

LAB41:    t17 = (t0 + 6592);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB42:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6592);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 127, 0);
    t6 = (t0 + 3448);
    t7 = (t0 + 6656);
    t8 = *((char **)t7);
    t9 = (t0 + 6680);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6664);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6672);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB49:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 6680);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB51:    if (t16 != 0)
        goto LAB52;

LAB47:    t17 = (t0 + 6720);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB48:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6720);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 255, 128);
    t6 = (t0 + 3448);
    t7 = (t0 + 6784);
    t8 = *((char **)t7);
    t9 = (t0 + 6808);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6792);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6800);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB55:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 6808);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB57:    if (t16 != 0)
        goto LAB58;

LAB53:    t17 = (t0 + 6848);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB54:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6848);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 1928);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 127, 0);
    t6 = (t0 + 3448);
    t7 = (t0 + 6912);
    t8 = *((char **)t7);
    t9 = (t0 + 6936);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6920);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6928);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB61:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 6936);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB63:    if (t16 != 0)
        goto LAB64;

LAB59:    t17 = (t0 + 6976);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB60:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6976);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1928);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 255, 128);
    t6 = (t0 + 3448);
    t7 = (t0 + 7040);
    t8 = *((char **)t7);
    t9 = (t0 + 7064);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 7048);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 7056);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB67:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 7064);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB69:    if (t16 != 0)
        goto LAB70;

LAB65:    t17 = (t0 + 7104);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB66:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7104);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng21)));
    t3 = (t0 + 2088);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 127, 0);
    t6 = (t0 + 3448);
    t7 = (t0 + 7168);
    t8 = *((char **)t7);
    t9 = (t0 + 7192);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 7176);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 7184);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB73:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 7192);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB75:    if (t16 != 0)
        goto LAB76;

LAB71:    t17 = (t0 + 7232);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB72:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7232);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 2088);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 255, 128);
    t6 = (t0 + 3448);
    t7 = (t0 + 7296);
    t8 = *((char **)t7);
    t9 = (t0 + 7320);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 7304);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 7312);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB79:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 7320);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB81:    if (t16 != 0)
        goto LAB82;

LAB77:    t17 = (t0 + 7360);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB78:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7360);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng23)));
    t3 = (t0 + 2248);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 127, 0);
    t6 = (t0 + 3448);
    t7 = (t0 + 7424);
    t8 = *((char **)t7);
    t9 = (t0 + 7448);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 7432);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 7440);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB85:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 7448);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB87:    if (t16 != 0)
        goto LAB88;

LAB83:    t17 = (t0 + 7488);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB84:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7488);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 2248);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 255, 128);
    t6 = (t0 + 3448);
    t7 = (t0 + 7552);
    t8 = *((char **)t7);
    t9 = (t0 + 7576);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 7560);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 7568);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB91:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 7576);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB93:    if (t16 != 0)
        goto LAB94;

LAB89:    t17 = (t0 + 7616);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB90:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7616);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng25)));
    t3 = (t0 + 2408);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 127, 0);
    t6 = (t0 + 3448);
    t7 = (t0 + 7680);
    t8 = *((char **)t7);
    t9 = (t0 + 7704);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 7688);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 7696);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB97:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 7704);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB99:    if (t16 != 0)
        goto LAB100;

LAB95:    t17 = (t0 + 7744);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB96:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7744);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 2408);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t23, 128, t5, 255, 128);
    t6 = (t0 + 3448);
    t7 = (t0 + 7808);
    t8 = *((char **)t7);
    t9 = (t0 + 7832);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 7816);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 7824);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t23, 0, 0, 128);

LAB103:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 7832);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB105:    if (t16 != 0)
        goto LAB106;

LAB101:    t17 = (t0 + 7872);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB102:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7872);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng27)));
    t3 = ((char*)((ng28)));
    t4 = ((char*)((ng11)));
    t5 = (t0 + 3448);
    t6 = (t0 + 7928);
    t7 = *((char **)t6);
    t8 = (t0 + 7960);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 7936);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 33);
    t12 = (t0 + 7944);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 32);
    t14 = (t0 + 7952);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 7);

LAB109:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t24 = (t22 + 0U);
    t25 = *((char **)t24);
    t26 = (t0 + 7960);
    t16 = ((int  (*)(char *, char *))t25)(*((char **)t26), t18);

LAB111:    if (t16 != 0)
        goto LAB112;

LAB107:    t18 = (t0 + 7992);
    t27 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t27)));

LAB108:    t28 = (t0 + 3544);
    t29 = *((char **)t28);
    t28 = (t0 + 7992);
    t30 = *((char **)t28);
    t31 = (t0 + 3448);
    t32 = 0;
    xsi_delete_subprogram_invocation(((char*)(t30)), t29, t0, t31, t32);
    xsi_set_current_line(64, ng0);
    xsi_vlogfile_write(1, 0, 0, ng29, 1, t0);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng30)));
    t4 = (t0 + 3448);
    t5 = (t0 + 8064);
    t6 = *((char **)t5);
    t7 = (t0 + 8088);
    t8 = xsi_create_subprogram_invocation(t4, 0, *((char **)t7), ((char*)(t6)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t6)), t8);
    t9 = (t0 + 8072);
    t10 = *((char **)t9);
    xsi_vlogvar_assign_value(((char*)(t10)), t2, 0, 0, 12);
    t11 = (t0 + 8080);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t3, 0, 0, 128);

LAB115:    t13 = (t0 + 3544);
    t14 = *((char **)t13);
    t15 = (t14 + 80U);
    t17 = *((char **)t15);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = (t0 + 8088);
    t16 = ((int  (*)(char *, char *))t21)(*((char **)t22), t14);

LAB117:    if (t16 != 0)
        goto LAB118;

LAB113:    t14 = (t0 + 8128);
    t24 = *((char **)t14);
    xsi_vlog_subprogram_popinvocation(((char*)(t24)));

LAB114:    t25 = (t0 + 3544);
    t26 = *((char **)t25);
    t25 = (t0 + 8128);
    t27 = *((char **)t25);
    t28 = (t0 + 3448);
    t29 = 0;
    xsi_delete_subprogram_invocation(((char*)(t27)), t26, t0, t28, t29);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng31)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng12)));
    t5 = (t0 + 3448);
    t6 = (t0 + 8184);
    t7 = *((char **)t6);
    t8 = (t0 + 8216);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 8192);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 8200);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 8208);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB121:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t24 = (t22 + 0U);
    t25 = *((char **)t24);
    t26 = (t0 + 8216);
    t16 = ((int  (*)(char *, char *))t25)(*((char **)t26), t18);

LAB123:    if (t16 != 0)
        goto LAB124;

LAB119:    t18 = (t0 + 8248);
    t27 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t27)));

LAB120:    t28 = (t0 + 3544);
    t29 = *((char **)t28);
    t28 = (t0 + 8248);
    t30 = *((char **)t28);
    t31 = (t0 + 3448);
    t32 = 0;
    xsi_delete_subprogram_invocation(((char*)(t30)), t29, t0, t31, t32);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 3448);
    t7 = (t0 + 8320);
    t8 = *((char **)t7);
    t9 = (t0 + 8344);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 8328);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 8336);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t5, 0, 0, 128);

LAB127:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t24 = *((char **)t22);
    t25 = (t0 + 8344);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t17);

LAB129:    if (t16 != 0)
        goto LAB130;

LAB125:    t17 = (t0 + 8384);
    t26 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB126:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 8384);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng31)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng12)));
    t5 = (t0 + 3448);
    t6 = (t0 + 8440);
    t7 = *((char **)t6);
    t8 = (t0 + 8472);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 8448);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 8456);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 8464);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB133:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t24 = (t22 + 0U);
    t25 = *((char **)t24);
    t26 = (t0 + 8472);
    t16 = ((int  (*)(char *, char *))t25)(*((char **)t26), t18);

LAB135:    if (t16 != 0)
        goto LAB136;

LAB131:    t18 = (t0 + 8504);
    t27 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t27)));

LAB132:    t28 = (t0 + 3544);
    t29 = *((char **)t28);
    t28 = (t0 + 8504);
    t30 = *((char **)t28);
    t31 = (t0 + 3448);
    t32 = 0;
    xsi_delete_subprogram_invocation(((char*)(t30)), t29, t0, t31, t32);
    xsi_set_current_line(87, ng0);
    xsi_vlogfile_write(1, 0, 0, ng32, 1, t0);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng31)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng12)));
    t5 = (t0 + 3448);
    t6 = (t0 + 8568);
    t7 = *((char **)t6);
    t8 = (t0 + 8600);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 8576);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 8584);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 8592);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB139:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t24 = (t22 + 0U);
    t25 = *((char **)t24);
    t26 = (t0 + 8600);
    t16 = ((int  (*)(char *, char *))t25)(*((char **)t26), t18);

LAB141:    if (t16 != 0)
        goto LAB142;

LAB137:    t18 = (t0 + 8632);
    t27 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t27)));

LAB138:    t28 = (t0 + 3544);
    t29 = *((char **)t28);
    t28 = (t0 + 8632);
    t30 = *((char **)t28);
    t31 = (t0 + 3448);
    t32 = 0;
    xsi_delete_subprogram_invocation(((char*)(t30)), t29, t0, t31, t32);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 3448);
    t4 = (t0 + 8704);
    t5 = *((char **)t4);
    t6 = (t0 + 8720);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 8712);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB143:    t10 = (t0 + 3544);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 8720);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB145;

LAB144:    t11 = (t0 + 3544);
    t20 = *((char **)t11);
    t11 = (t0 + 8728);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t24 = *((char **)t22);
    memcpy(t23, t24, 32);
    t25 = (t0 + 8704);
    t26 = *((char **)t25);
    t27 = (t0 + 3448);
    t28 = 0;
    xsi_delete_subprogram_invocation(((char*)(t26)), t20, t0, t27, t28);
    t29 = (t0 + 2728);
    xsi_vlogvar_assign_value(t29, t23, 0, 0, 128);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t33, 0, 8);
    t5 = (t33 + 4);
    t6 = (t4 + 8);
    t7 = (t4 + 12);
    t34 = *((unsigned int *)t6);
    t35 = (t34 >> 0);
    *((unsigned int *)t33) = t35;
    t36 = *((unsigned int *)t7);
    t37 = (t36 >> 0);
    *((unsigned int *)t5) = t37;
    t38 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t38 & 65535U);
    t39 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t39 & 65535U);
    t8 = (t0 + 2728);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t40, 0, 8);
    t11 = (t40 + 4);
    t12 = (t10 + 4);
    t41 = *((unsigned int *)t10);
    t42 = (t41 >> 0);
    *((unsigned int *)t40) = t42;
    t43 = *((unsigned int *)t12);
    t44 = (t43 >> 0);
    *((unsigned int *)t11) = t44;
    t45 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t45 & 4294967295U);
    t46 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t46 & 4294967295U);
    xsi_vlogfile_write(1, 0, 0, ng33, 3, t0, (char)118, t33, 16, (char)118, t40, 32);
    xsi_set_current_line(103, ng0);
    t2 = ((char*)((ng31)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng12)));
    t5 = (t0 + 3448);
    t6 = (t0 + 8760);
    t7 = *((char **)t6);
    t8 = (t0 + 8792);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 8768);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 8776);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 8784);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB148:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t24 = (t22 + 0U);
    t25 = *((char **)t24);
    t26 = (t0 + 8792);
    t16 = ((int  (*)(char *, char *))t25)(*((char **)t26), t18);

LAB150:    if (t16 != 0)
        goto LAB151;

LAB146:    t18 = (t0 + 8824);
    t27 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t27)));

LAB147:    t28 = (t0 + 3544);
    t29 = *((char **)t28);
    t28 = (t0 + 8824);
    t30 = *((char **)t28);
    t31 = (t0 + 3448);
    t32 = 0;
    xsi_delete_subprogram_invocation(((char*)(t30)), t29, t0, t31, t32);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 3448);
    t4 = (t0 + 8896);
    t5 = *((char **)t4);
    t6 = (t0 + 8912);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 8904);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB152:    t10 = (t0 + 3544);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 8912);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB154;

LAB153:    t11 = (t0 + 3544);
    t20 = *((char **)t11);
    t11 = (t0 + 8920);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t24 = *((char **)t22);
    memcpy(t23, t24, 32);
    t25 = (t0 + 8896);
    t26 = *((char **)t25);
    t27 = (t0 + 3448);
    t28 = 0;
    xsi_delete_subprogram_invocation(((char*)(t26)), t20, t0, t27, t28);
    t29 = (t0 + 2728);
    xsi_vlogvar_assign_value(t29, t23, 0, 0, 128);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t33, 0, 8);
    t5 = (t33 + 4);
    t6 = (t4 + 8);
    t7 = (t4 + 12);
    t34 = *((unsigned int *)t6);
    t35 = (t34 >> 0);
    *((unsigned int *)t33) = t35;
    t36 = *((unsigned int *)t7);
    t37 = (t36 >> 0);
    *((unsigned int *)t5) = t37;
    t38 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t38 & 65535U);
    t39 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t39 & 65535U);
    t8 = (t0 + 2728);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t40, 0, 8);
    t11 = (t40 + 4);
    t12 = (t10 + 4);
    t41 = *((unsigned int *)t10);
    t42 = (t41 >> 0);
    *((unsigned int *)t40) = t42;
    t43 = *((unsigned int *)t12);
    t44 = (t43 >> 0);
    *((unsigned int *)t11) = t44;
    t45 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t45 & 4294967295U);
    t46 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t46 & 4294967295U);
    xsi_vlogfile_write(1, 0, 0, ng33, 3, t0, (char)118, t33, 16, (char)118, t40, 32);
    xsi_set_current_line(122, ng0);
    xsi_vlogfile_write(1, 0, 0, ng34, 1, t0);
    xsi_set_current_line(123, ng0);
    xsi_vlog_stop(1);

LAB1:    return;
LAB8:;
LAB10:    t7 = (t0 + 3640U);
    *((char **)t7) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB37;
    goto LAB1;

LAB44:;
LAB46:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB43;
    goto LAB1;

LAB50:;
LAB52:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB49;
    goto LAB1;

LAB56:;
LAB58:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB55;
    goto LAB1;

LAB62:;
LAB64:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB61;
    goto LAB1;

LAB68:;
LAB70:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB67;
    goto LAB1;

LAB74:;
LAB76:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB73;
    goto LAB1;

LAB80:;
LAB82:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB79;
    goto LAB1;

LAB86:;
LAB88:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB85;
    goto LAB1;

LAB92:;
LAB94:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB91;
    goto LAB1;

LAB98:;
LAB100:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB97;
    goto LAB1;

LAB104:;
LAB106:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB103;
    goto LAB1;

LAB110:;
LAB112:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB109;
    goto LAB1;

LAB116:;
LAB118:    t13 = (t0 + 3640U);
    *((char **)t13) = &&LAB115;
    goto LAB1;

LAB122:;
LAB124:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB121;
    goto LAB1;

LAB128:;
LAB130:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB127;
    goto LAB1;

LAB134:;
LAB136:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB133;
    goto LAB1;

LAB140:;
LAB142:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB139;
    goto LAB1;

LAB145:    t10 = (t0 + 3640U);
    *((char **)t10) = &&LAB143;
    goto LAB1;

LAB149:;
LAB151:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB148;
    goto LAB1;

LAB154:    t10 = (t0 + 3640U);
    *((char **)t10) = &&LAB152;
    goto LAB1;

}


extern void work_m_18290912933722643816_1224442286_init()
{
	static char *pe[] = {(void *)Initial_24_0};
	xsi_register_didat("work_m_18290912933722643816_1224442286", "isim/PicoTestbench_isim_beh.exe.sim/work/m_18290912933722643816_1224442286.didat");
	xsi_register_executes(pe);
}
