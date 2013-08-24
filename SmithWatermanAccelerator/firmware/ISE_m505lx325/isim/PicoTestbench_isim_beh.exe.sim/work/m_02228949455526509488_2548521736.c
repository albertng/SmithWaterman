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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/Dummy_DRAM.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {0U, 0U, 0U, 0U};
static unsigned int ng4[] = {3964082448U, 0U, 36244169U, 0U, 3330713593U, 0U, 442163402U, 0U, 2886968005U, 0U, 348008105U, 0U, 675179041U, 0U, 3817453149U, 0U};
static unsigned int ng5[] = {32U, 0U, 0U, 0U};
static unsigned int ng6[] = {3783505928U, 0U, 426952168U, 0U, 31525478U, 0U, 187662404U, 0U, 2167998723U, 0U, 2595094596U, 0U, 34253560U, 0U, 671785610U, 0U};
static unsigned int ng7[] = {64U, 0U, 0U, 0U};
static unsigned int ng8[] = {2410457724U, 0U, 867836028U, 0U, 2416714048U, 0U, 831634995U, 0U, 1875282564U, 0U, 2353199702U, 0U, 2207553322U, 0U, 2235703332U, 0U};
static unsigned int ng9[] = {96U, 0U, 0U, 0U};
static unsigned int ng10[] = {2425399878U, 0U, 592073U, 0U, 2651495044U, 0U, 2210671500U, 0U, 1804202026U, 0U, 1073889110U, 0U, 2727713954U, 0U, 169412913U, 0U};
static unsigned int ng11[] = {128U, 0U, 0U, 0U};
static unsigned int ng12[] = {2687300283U, 0U, 982134697U, 0U, 2536073928U, 0U, 288433833U, 0U, 3435974426U, 0U, 3435973836U, 0U, 4009683148U, 0U, 1178643182U, 0U};
static unsigned int ng13[] = {160U, 0U, 0U, 0U};
static unsigned int ng14[] = {1682606405U, 0U, 4198542U, 0U, 3242217492U, 0U, 340001809U, 0U, 604307906U, 0U, 3934851152U, 0U, 3794379434U, 0U, 2292869290U, 0U};
static unsigned int ng15[] = {192U, 0U, 0U, 0U};
static unsigned int ng16[] = {1479627U, 0U, 370122890U, 0U, 2491571370U, 0U, 3994095418U, 0U, 1646472306U, 0U, 964698720U, 0U, 4003636259U, 0U, 2611110024U, 0U};
static unsigned int ng17[] = {224U, 0U, 0U, 0U};
static unsigned int ng18[] = {2525757768U, 0U, 2584293382U, 0U, 1276888578U, 0U, 3299367578U, 0U, 2090996552U, 0U, 2399178968U, 0U, 1443497132U, 0U, 2156032257U, 0U};
static unsigned int ng19[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};



static void Cont_28_0(char *t0)
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

LAB0:    t1 = (t0 + 5032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 3960);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7280);
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
    t18 = (t0 + 7088);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_29_1(char *t0)
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

LAB0:    t1 = (t0 + 5280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 1960U);
    t3 = *((char **)t2);
    t2 = (t0 + 7344);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 255U;
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
    xsi_driver_vfirst_trans(t2, 0, 7);
    t16 = (t0 + 7104);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_30_2(char *t0)
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

LAB0:    t1 = (t0 + 5528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(30, ng0);
    t2 = (t0 + 4120);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7408);
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
    t18 = (t0 + 7120);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_31_3(char *t0)
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

LAB0:    t1 = (t0 + 5776U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 3800);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7472);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t4, 0, 256);
    xsi_driver_vfirst_trans(t5, 0, 255);
    t10 = (t0 + 7136);
    *((int *)t10) = 1;

LAB1:    return;
}

static void Always_33_4(char *t0)
{
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

LAB0:    t1 = (t0 + 6024U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 7152);
    *((int *)t2) = 1;
    t3 = (t0 + 6056);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(33, ng0);

LAB5:    xsi_set_current_line(34, ng0);
    t4 = (t0 + 1480U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(36, ng0);

LAB10:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 3640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3480);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(34, ng0);

LAB9:    xsi_set_current_line(35, ng0);
    t11 = (t0 + 472);
    t12 = *((char **)t11);
    t11 = (t0 + 3480);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 1);
    goto LAB8;

}

static void Always_40_5(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 6272U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 7168);
    *((int *)t2) = 1;
    t3 = (t0 + 6304);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(40, ng0);

LAB5:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 3480);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = (t0 + 472);
    t8 = *((char **)t7);
    t9 = xsi_vlog_unsigned_case_compare(t6, 1, t8, 32);
    if (t9 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 1, t3, 32);
    if (t9 == 1)
        goto LAB9;

LAB10:
LAB11:    goto LAB2;

LAB7:    xsi_set_current_line(42, ng0);

LAB12:    xsi_set_current_line(43, ng0);
    t7 = (t0 + 2440U);
    t10 = *((char **)t7);
    t7 = (t10 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (~(t11));
    t13 = *((unsigned int *)t10);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB13;

LAB14:    xsi_set_current_line(45, ng0);

LAB17:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 472);
    t3 = *((char **)t2);
    t2 = (t0 + 3640);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);

LAB15:    goto LAB11;

LAB9:    xsi_set_current_line(50, ng0);

LAB18:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 472);
    t4 = *((char **)t2);
    t2 = (t0 + 3640);
    xsi_vlogvar_assign_value(t2, t4, 0, 0, 1);
    goto LAB11;

LAB13:    xsi_set_current_line(43, ng0);

LAB16:    xsi_set_current_line(44, ng0);
    t16 = (t0 + 608);
    t17 = *((char **)t16);
    t16 = (t0 + 3640);
    xsi_vlogvar_assign_value(t16, t17, 0, 0, 1);
    goto LAB15;

}

static void Always_55_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;

LAB0:    t1 = (t0 + 6520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 7184);
    *((int *)t2) = 1;
    t3 = (t0 + 6552);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(55, ng0);

LAB5:    xsi_set_current_line(56, ng0);
    t4 = (t0 + 3480);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = (t0 + 472);
    t8 = *((char **)t7);
    t9 = xsi_vlog_unsigned_case_compare(t6, 1, t8, 32);
    if (t9 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 1, t3, 32);
    if (t9 == 1)
        goto LAB9;

LAB10:
LAB11:    goto LAB2;

LAB7:    xsi_set_current_line(57, ng0);

LAB12:    xsi_set_current_line(58, ng0);
    t7 = ((char*)((ng1)));
    t10 = (t0 + 3960);
    xsi_vlogvar_assign_value(t10, t7, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4120);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB11;

LAB9:    xsi_set_current_line(62, ng0);

LAB13:    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 3960);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4120);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB11;

}

static void Always_69_7(char *t0)
{
    char t6[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;

LAB0:    t1 = (t0 + 6768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 7200);
    *((int *)t2) = 1;
    t3 = (t0 + 6800);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(69, ng0);

LAB5:    xsi_set_current_line(70, ng0);
    t4 = (t0 + 2120U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    xsi_vlog_unsigned_equal(t6, 33, t5, 33, t4, 33);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    xsi_vlog_unsigned_equal(t6, 33, t3, 33, t2, 33);
    t4 = (t6 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
    xsi_vlog_unsigned_equal(t6, 33, t3, 33, t2, 33);
    t4 = (t6 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    xsi_vlog_unsigned_equal(t6, 33, t3, 33, t2, 33);
    t4 = (t6 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng11)));
    xsi_vlog_unsigned_equal(t6, 33, t3, 33, t2, 33);
    t4 = (t6 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng13)));
    xsi_vlog_unsigned_equal(t6, 33, t3, 33, t2, 33);
    t4 = (t6 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng15)));
    xsi_vlog_unsigned_equal(t6, 33, t3, 33, t2, 33);
    t4 = (t6 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB30;

LAB31:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng17)));
    xsi_vlog_unsigned_equal(t6, 33, t3, 33, t2, 33);
    t4 = (t6 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB34;

LAB35:    xsi_set_current_line(86, ng0);

LAB38:    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 3800);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 256);

LAB36:
LAB32:
LAB28:
LAB24:
LAB20:
LAB16:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(70, ng0);

LAB9:    xsi_set_current_line(71, ng0);
    t13 = ((char*)((ng4)));
    t14 = (t0 + 3800);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 256);
    goto LAB8;

LAB10:    xsi_set_current_line(72, ng0);

LAB13:    xsi_set_current_line(73, ng0);
    t5 = ((char*)((ng6)));
    t7 = (t0 + 3800);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 256);
    goto LAB12;

LAB14:    xsi_set_current_line(74, ng0);

LAB17:    xsi_set_current_line(75, ng0);
    t5 = ((char*)((ng8)));
    t7 = (t0 + 3800);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 256);
    goto LAB16;

LAB18:    xsi_set_current_line(76, ng0);

LAB21:    xsi_set_current_line(77, ng0);
    t5 = ((char*)((ng10)));
    t7 = (t0 + 3800);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 256);
    goto LAB20;

LAB22:    xsi_set_current_line(78, ng0);

LAB25:    xsi_set_current_line(79, ng0);
    t5 = ((char*)((ng12)));
    t7 = (t0 + 3800);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 256);
    goto LAB24;

LAB26:    xsi_set_current_line(80, ng0);

LAB29:    xsi_set_current_line(81, ng0);
    t5 = ((char*)((ng14)));
    t7 = (t0 + 3800);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 256);
    goto LAB28;

LAB30:    xsi_set_current_line(82, ng0);

LAB33:    xsi_set_current_line(83, ng0);
    t5 = ((char*)((ng16)));
    t7 = (t0 + 3800);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 256);
    goto LAB32;

LAB34:    xsi_set_current_line(84, ng0);

LAB37:    xsi_set_current_line(85, ng0);
    t5 = ((char*)((ng18)));
    t7 = (t0 + 3800);
    xsi_vlogvar_assign_value(t7, t5, 0, 0, 256);
    goto LAB36;

}


extern void work_m_02228949455526509488_2548521736_init()
{
	static char *pe[] = {(void *)Cont_28_0,(void *)Cont_29_1,(void *)Cont_30_2,(void *)Cont_31_3,(void *)Always_33_4,(void *)Always_40_5,(void *)Always_55_6,(void *)Always_69_7};
	xsi_register_didat("work_m_02228949455526509488_2548521736", "isim/PicoTestbench_isim_beh.exe.sim/work/m_02228949455526509488_2548521736.didat");
	xsi_register_executes(pe);
}
