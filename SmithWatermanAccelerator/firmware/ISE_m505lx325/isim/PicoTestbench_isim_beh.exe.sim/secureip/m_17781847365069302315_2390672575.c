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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/oserdese2/B_OSERDESE2_enc.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {0U, 1U};
static unsigned int ng4[] = {1U, 1U};



static void Always_1686_0(char *t0)
{
    char t14[8];
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
    int t13;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    int t25;

LAB0:    t1 = (t0 + 2840U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1686, ng0);
    t2 = (t0 + 3408);
    *((int *)t2) = 1;
    t3 = (t0 + 2872);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(1686, ng0);

LAB5:    xsi_set_current_line(1687, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(1690, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);

LAB9:    t2 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 1, t2, 1);
    if (t13 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng1)));
    t13 = xsi_vlog_unsigned_case_compare(t3, 1, t2, 1);
    if (t13 == 1)
        goto LAB12;

LAB13:    t4 = ((char*)((ng3)));
    t25 = xsi_vlog_unsigned_case_compare(t3, 1, t4, 1);
    if (t25 == 1)
        goto LAB14;

LAB15:
LAB17:
LAB16:    xsi_set_current_line(1693, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);

LAB18:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(1688, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 1928);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 1);
    goto LAB8;

LAB10:    xsi_set_current_line(1691, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    memset(t14, 0, 8);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB22;

LAB20:    if (*((unsigned int *)t4) == 0)
        goto LAB19;

LAB21:    t11 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t11) = 1;

LAB22:    t12 = (t14 + 4);
    t15 = (t5 + 4);
    t16 = *((unsigned int *)t5);
    t17 = (~(t16));
    *((unsigned int *)t14) = t17;
    *((unsigned int *)t12) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB24;

LAB23:    t22 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t22 & 1U);
    t23 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t23 & 1U);
    t24 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t24, t14, 0, 0, 1, 0LL);
    goto LAB18;

LAB12:    goto LAB10;

LAB14:    xsi_set_current_line(1692, ng0);
    t5 = (t0 + 1928);
    t11 = (t5 + 56U);
    t12 = *((char **)t11);
    t15 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t15, t12, 0, 0, 1, 0LL);
    goto LAB18;

LAB19:    *((unsigned int *)t14) = 1;
    goto LAB22;

LAB24:    t18 = *((unsigned int *)t14);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t18 | t19);
    t20 = *((unsigned int *)t12);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t12) = (t20 | t21);
    goto LAB23;

}

static void Cont_1696_1(char *t0)
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

LAB0:    t1 = (t0 + 3088U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1696, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3504);
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
    t18 = (t0 + 3424);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void secureip_m_17781847365069302315_2390672575_init()
{
	static char *pe[] = {(void *)Always_1686_0,(void *)Cont_1696_1};
	xsi_register_didat("secureip_m_17781847365069302315_2390672575", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_17781847365069302315_2390672575.didat");
	xsi_register_executes(pe);
}
