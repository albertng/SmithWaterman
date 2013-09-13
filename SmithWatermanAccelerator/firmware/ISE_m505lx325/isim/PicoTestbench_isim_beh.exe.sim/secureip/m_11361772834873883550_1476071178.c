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
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {0U, 1U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {8U, 0U};
static unsigned int ng7[] = {16U, 0U};
static unsigned int ng8[] = {32U, 0U};
static unsigned int ng9[] = {1U, 1U};



static void Cont_2405_0(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;

LAB0:    t1 = (t0 + 4920U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2405, ng0);
    t2 = (t0 + 1848U);
    t4 = *((char **)t2);
    t2 = (t0 + 2168U);
    t5 = *((char **)t2);
    t2 = (t0 + 2488U);
    t6 = *((char **)t2);
    t2 = (t0 + 2808U);
    t7 = *((char **)t2);
    t2 = (t0 + 3128U);
    t8 = *((char **)t2);
    xsi_vlogtype_concat(t3, 5, 5, 5U, t8, 1, t7, 1, t6, 1, t5, 1, t4, 1);
    t2 = (t0 + 5584);
    t9 = (t2 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memset(t12, 0, 8);
    t13 = 31U;
    t14 = t13;
    t15 = (t3 + 4);
    t16 = *((unsigned int *)t3);
    t13 = (t13 & t16);
    t17 = *((unsigned int *)t15);
    t14 = (t14 & t17);
    t18 = (t12 + 4);
    t19 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t19 | t13);
    t20 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t20 | t14);
    xsi_driver_vfirst_trans(t2, 0, 4);
    t21 = (t0 + 5488);
    *((int *)t21) = 1;

LAB1:    return;
}

static void Always_2408_1(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 5168U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2408, ng0);
    t2 = (t0 + 5504);
    *((int *)t2) = 1;
    t3 = (t0 + 5200);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(2409, ng0);

LAB5:    xsi_set_current_line(2410, ng0);
    t5 = (t0 + 3448U);
    t6 = *((char **)t5);
    t5 = (t0 + 3608U);
    t7 = *((char **)t5);
    xsi_vlogtype_concat(t4, 6, 6, 2U, t7, 5, t6, 1);

LAB6:    t5 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t5, 6);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 6);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 6);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 6);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 6);
    if (t8 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 6);
    if (t8 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 6);
    if (t8 == 1)
        goto LAB19;

LAB20:
LAB22:
LAB21:    xsi_set_current_line(2418, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB23:    goto LAB2;

LAB7:    xsi_set_current_line(2411, ng0);
    t9 = ((char*)((ng2)));
    t10 = (t0 + 4008);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 1);
    goto LAB23;

LAB9:    xsi_set_current_line(2412, ng0);
    t3 = ((char*)((ng3)));
    t5 = (t0 + 4008);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    goto LAB23;

LAB11:    xsi_set_current_line(2413, ng0);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    goto LAB23;

LAB13:    xsi_set_current_line(2414, ng0);
    t3 = (t0 + 1208U);
    t5 = *((char **)t3);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    goto LAB23;

LAB15:    xsi_set_current_line(2415, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    goto LAB23;

LAB17:    xsi_set_current_line(2416, ng0);
    t3 = (t0 + 1528U);
    t5 = *((char **)t3);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    goto LAB23;

LAB19:    xsi_set_current_line(2417, ng0);
    t3 = (t0 + 1688U);
    t5 = *((char **)t3);
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    goto LAB23;

}


extern void secureip_m_11361772834873883550_1476071178_init()
{
	static char *pe[] = {(void *)Cont_2405_0,(void *)Always_2408_1};
	xsi_register_didat("secureip_m_11361772834873883550_1476071178", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_11361772834873883550_1476071178.didat");
	xsi_register_executes(pe);
}
