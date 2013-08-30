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
static const char *ng10 = "Streaming query seq to FPGA";
static int ng11[] = {0, 0};
static unsigned int ng12[] = {8U, 0U, 0U, 0U, 63U, 0U, 126U, 0U};
static int ng13[] = {1, 0};
static int ng14[] = {16, 0};
static int ng15[] = {2, 0};
static const char *ng16 = "Streaming result from FPGA";
static const char *ng17 = "Stream:1 Query:%d Location:%d";
static const char *ng18 = "Stream:2 Query:%d Location:%d";
static const char *ng19 = "All Tests Successful!";



static void Initial_24_0(char *t0)
{
    char t32[32];
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
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
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
    t3 = (t0 + 5768);
    t4 = *((char **)t3);
    t5 = (t0 + 5776);
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
    t15 = (t0 + 5776);
    t16 = ((int  (*)(char *, char *))t14)(*((char **)t15), t8);

LAB9:    if (t16 != 0)
        goto LAB10;

LAB5:    t8 = (t0 + 5808);
    t17 = *((char **)t8);
    xsi_vlog_subprogram_popinvocation(((char*)(t17)));

LAB6:    t18 = (t0 + 3544);
    t19 = *((char **)t18);
    t18 = (t0 + 5808);
    t20 = *((char **)t18);
    t21 = (t0 + 3448);
    t22 = 0;
    xsi_delete_subprogram_invocation(((char*)(t20)), t19, t0, t21, t22);
    xsi_set_current_line(64, ng0);
    xsi_vlogfile_write(1, 0, 0, ng10, 1, t0);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng12)));
    t4 = (t0 + 3448);
    t5 = (t0 + 5856);
    t6 = *((char **)t5);
    t7 = (t0 + 5880);
    t8 = xsi_create_subprogram_invocation(t4, 0, *((char **)t7), ((char*)(t6)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t6)), t8);
    t9 = (t0 + 5864);
    t10 = *((char **)t9);
    xsi_vlogvar_assign_value(((char*)(t10)), t2, 0, 0, 12);
    t11 = (t0 + 5872);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t3, 0, 0, 128);

LAB13:    t13 = (t0 + 3544);
    t14 = *((char **)t13);
    t15 = (t14 + 80U);
    t17 = *((char **)t15);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = (t0 + 5880);
    t16 = ((int  (*)(char *, char *))t21)(*((char **)t22), t14);

LAB15:    if (t16 != 0)
        goto LAB16;

LAB11:    t14 = (t0 + 5920);
    t23 = *((char **)t14);
    xsi_vlog_subprogram_popinvocation(((char*)(t23)));

LAB12:    t24 = (t0 + 3544);
    t25 = *((char **)t24);
    t24 = (t0 + 5920);
    t26 = *((char **)t24);
    t27 = (t0 + 3448);
    t28 = 0;
    xsi_delete_subprogram_invocation(((char*)(t26)), t25, t0, t27, t28);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng13)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3448);
    t6 = (t0 + 5976);
    t7 = *((char **)t6);
    t8 = (t0 + 6008);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 5984);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 5992);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 6000);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB19:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 6008);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB21:    if (t16 != 0)
        goto LAB22;

LAB17:    t18 = (t0 + 6040);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB18:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6040);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 3448);
    t7 = (t0 + 6112);
    t8 = *((char **)t7);
    t9 = (t0 + 6136);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6120);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6128);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t5, 0, 0, 128);

LAB25:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t24 = (t0 + 6136);
    t16 = ((int  (*)(char *, char *))t23)(*((char **)t24), t17);

LAB27:    if (t16 != 0)
        goto LAB28;

LAB23:    t17 = (t0 + 6176);
    t25 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t25)));

LAB24:    t26 = (t0 + 3544);
    t27 = *((char **)t26);
    t26 = (t0 + 6176);
    t28 = *((char **)t26);
    t29 = (t0 + 3448);
    t30 = 0;
    xsi_delete_subprogram_invocation(((char*)(t28)), t27, t0, t29, t30);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng13)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3448);
    t6 = (t0 + 6232);
    t7 = *((char **)t6);
    t8 = (t0 + 6264);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 6240);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 6248);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 6256);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB31:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 6264);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB33:    if (t16 != 0)
        goto LAB34;

LAB29:    t18 = (t0 + 6296);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB30:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6296);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng12)));
    t4 = (t0 + 3448);
    t5 = (t0 + 6368);
    t6 = *((char **)t5);
    t7 = (t0 + 6392);
    t8 = xsi_create_subprogram_invocation(t4, 0, *((char **)t7), ((char*)(t6)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t6)), t8);
    t9 = (t0 + 6376);
    t10 = *((char **)t9);
    xsi_vlogvar_assign_value(((char*)(t10)), t2, 0, 0, 12);
    t11 = (t0 + 6384);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t3, 0, 0, 128);

LAB37:    t13 = (t0 + 3544);
    t14 = *((char **)t13);
    t15 = (t14 + 80U);
    t17 = *((char **)t15);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = (t0 + 6392);
    t16 = ((int  (*)(char *, char *))t21)(*((char **)t22), t14);

LAB39:    if (t16 != 0)
        goto LAB40;

LAB35:    t14 = (t0 + 6432);
    t23 = *((char **)t14);
    xsi_vlog_subprogram_popinvocation(((char*)(t23)));

LAB36:    t24 = (t0 + 3544);
    t25 = *((char **)t24);
    t24 = (t0 + 6432);
    t26 = *((char **)t24);
    t27 = (t0 + 3448);
    t28 = 0;
    xsi_delete_subprogram_invocation(((char*)(t26)), t25, t0, t27, t28);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng15)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3448);
    t6 = (t0 + 6488);
    t7 = *((char **)t6);
    t8 = (t0 + 6520);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 6496);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 6504);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 6512);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB43:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 6520);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB45:    if (t16 != 0)
        goto LAB46;

LAB41:    t18 = (t0 + 6552);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB42:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6552);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2568);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 3448);
    t7 = (t0 + 6624);
    t8 = *((char **)t7);
    t9 = (t0 + 6648);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 6632);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 6640);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t5, 0, 0, 128);

LAB49:    t15 = (t0 + 3544);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t24 = (t0 + 6648);
    t16 = ((int  (*)(char *, char *))t23)(*((char **)t24), t17);

LAB51:    if (t16 != 0)
        goto LAB52;

LAB47:    t17 = (t0 + 6688);
    t25 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t25)));

LAB48:    t26 = (t0 + 3544);
    t27 = *((char **)t26);
    t26 = (t0 + 6688);
    t28 = *((char **)t26);
    t29 = (t0 + 3448);
    t30 = 0;
    xsi_delete_subprogram_invocation(((char*)(t28)), t27, t0, t29, t30);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng15)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3448);
    t6 = (t0 + 6744);
    t7 = *((char **)t6);
    t8 = (t0 + 6776);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 6752);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 6760);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 6768);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB55:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 6776);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB57:    if (t16 != 0)
        goto LAB58;

LAB53:    t18 = (t0 + 6808);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB54:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6808);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(75, ng0);
    xsi_vlogfile_write(1, 0, 0, ng16, 1, t0);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng13)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3448);
    t6 = (t0 + 6872);
    t7 = *((char **)t6);
    t8 = (t0 + 6904);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 6880);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 6888);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 6896);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB61:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 6904);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB63:    if (t16 != 0)
        goto LAB64;

LAB59:    t18 = (t0 + 6936);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB60:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 6936);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 3448);
    t4 = (t0 + 7008);
    t5 = *((char **)t4);
    t6 = (t0 + 7024);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 7016);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB65:    t10 = (t0 + 3544);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 7024);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB67;

LAB66:    t11 = (t0 + 3544);
    t20 = *((char **)t11);
    t11 = (t0 + 7032);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t23 = *((char **)t22);
    memcpy(t32, t23, 32);
    t24 = (t0 + 7008);
    t25 = *((char **)t24);
    t26 = (t0 + 3448);
    t27 = 0;
    xsi_delete_subprogram_invocation(((char*)(t25)), t20, t0, t26, t27);
    t28 = (t0 + 2728);
    xsi_vlogvar_assign_value(t28, t32, 0, 0, 128);
    xsi_set_current_line(78, ng0);
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
    xsi_vlogfile_write(1, 0, 0, ng17, 3, t0, (char)118, t33, 16, (char)118, t40, 32);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng15)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3448);
    t6 = (t0 + 7064);
    t7 = *((char **)t6);
    t8 = (t0 + 7096);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 7072);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 7080);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 7088);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB70:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 7096);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB72:    if (t16 != 0)
        goto LAB73;

LAB68:    t18 = (t0 + 7128);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB69:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7128);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 3448);
    t4 = (t0 + 7200);
    t5 = *((char **)t4);
    t6 = (t0 + 7216);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 7208);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB74:    t10 = (t0 + 3544);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 7216);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB76;

LAB75:    t11 = (t0 + 3544);
    t20 = *((char **)t11);
    t11 = (t0 + 7224);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t23 = *((char **)t22);
    memcpy(t32, t23, 32);
    t24 = (t0 + 7200);
    t25 = *((char **)t24);
    t26 = (t0 + 3448);
    t27 = 0;
    xsi_delete_subprogram_invocation(((char*)(t25)), t20, t0, t26, t27);
    t28 = (t0 + 2728);
    xsi_vlogvar_assign_value(t28, t32, 0, 0, 128);
    xsi_set_current_line(81, ng0);
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
    xsi_vlogfile_write(1, 0, 0, ng18, 3, t0, (char)118, t33, 16, (char)118, t40, 32);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng13)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3448);
    t6 = (t0 + 7256);
    t7 = *((char **)t6);
    t8 = (t0 + 7288);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 7264);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 7272);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 7280);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB79:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 7288);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB81:    if (t16 != 0)
        goto LAB82;

LAB77:    t18 = (t0 + 7320);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB78:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7320);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 3448);
    t4 = (t0 + 7392);
    t5 = *((char **)t4);
    t6 = (t0 + 7408);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 7400);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB83:    t10 = (t0 + 3544);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 7408);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB85;

LAB84:    t11 = (t0 + 3544);
    t20 = *((char **)t11);
    t11 = (t0 + 7416);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t23 = *((char **)t22);
    memcpy(t32, t23, 32);
    t24 = (t0 + 7392);
    t25 = *((char **)t24);
    t26 = (t0 + 3448);
    t27 = 0;
    xsi_delete_subprogram_invocation(((char*)(t25)), t20, t0, t26, t27);
    t28 = (t0 + 2728);
    xsi_vlogvar_assign_value(t28, t32, 0, 0, 128);
    xsi_set_current_line(84, ng0);
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
    xsi_vlogfile_write(1, 0, 0, ng17, 3, t0, (char)118, t33, 16, (char)118, t40, 32);
    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng15)));
    t3 = ((char*)((ng11)));
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3448);
    t6 = (t0 + 7448);
    t7 = *((char **)t6);
    t8 = (t0 + 7480);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 7456);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 7464);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 7472);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB88:    t17 = (t0 + 3544);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 7480);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB90:    if (t16 != 0)
        goto LAB91;

LAB86:    t18 = (t0 + 7512);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB87:    t27 = (t0 + 3544);
    t28 = *((char **)t27);
    t27 = (t0 + 7512);
    t29 = *((char **)t27);
    t30 = (t0 + 3448);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 3448);
    t4 = (t0 + 7584);
    t5 = *((char **)t4);
    t6 = (t0 + 7600);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 7592);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB92:    t10 = (t0 + 3544);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 7600);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB94;

LAB93:    t11 = (t0 + 3544);
    t20 = *((char **)t11);
    t11 = (t0 + 7608);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t23 = *((char **)t22);
    memcpy(t32, t23, 32);
    t24 = (t0 + 7584);
    t25 = *((char **)t24);
    t26 = (t0 + 3448);
    t27 = 0;
    xsi_delete_subprogram_invocation(((char*)(t25)), t20, t0, t26, t27);
    t28 = (t0 + 2728);
    xsi_vlogvar_assign_value(t28, t32, 0, 0, 128);
    xsi_set_current_line(87, ng0);
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
    xsi_vlogfile_write(1, 0, 0, ng18, 3, t0, (char)118, t33, 16, (char)118, t40, 32);
    xsi_set_current_line(92, ng0);
    xsi_vlogfile_write(1, 0, 0, ng19, 1, t0);
    xsi_set_current_line(93, ng0);
    xsi_vlog_stop(1);

LAB1:    return;
LAB8:;
LAB10:    t7 = (t0 + 3640U);
    *((char **)t7) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t13 = (t0 + 3640U);
    *((char **)t13) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t13 = (t0 + 3640U);
    *((char **)t13) = &&LAB37;
    goto LAB1;

LAB44:;
LAB46:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB43;
    goto LAB1;

LAB50:;
LAB52:    t15 = (t0 + 3640U);
    *((char **)t15) = &&LAB49;
    goto LAB1;

LAB56:;
LAB58:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB55;
    goto LAB1;

LAB62:;
LAB64:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB61;
    goto LAB1;

LAB67:    t10 = (t0 + 3640U);
    *((char **)t10) = &&LAB65;
    goto LAB1;

LAB71:;
LAB73:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB70;
    goto LAB1;

LAB76:    t10 = (t0 + 3640U);
    *((char **)t10) = &&LAB74;
    goto LAB1;

LAB80:;
LAB82:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB79;
    goto LAB1;

LAB85:    t10 = (t0 + 3640U);
    *((char **)t10) = &&LAB83;
    goto LAB1;

LAB89:;
LAB91:    t17 = (t0 + 3640U);
    *((char **)t17) = &&LAB88;
    goto LAB1;

LAB94:    t10 = (t0 + 3640U);
    *((char **)t10) = &&LAB92;
    goto LAB1;

}


extern void work_m_18290912933722643816_1224442286_init()
{
	static char *pe[] = {(void *)Initial_24_0};
	xsi_register_didat("work_m_18290912933722643816_1224442286", "isim/PicoTestbench_isim_beh.exe.sim/work/m_18290912933722643816_1224442286.didat");
	xsi_register_executes(pe);
}
