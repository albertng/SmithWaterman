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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/phaser_out/SIP_PHASER_OUT.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {5U, 0U};
static unsigned int ng7[] = {6U, 0U};
static unsigned int ng8[] = {7U, 0U};
static unsigned int ng9[] = {1U, 1U};



static void Always_6696_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;
    char *t11;

LAB0:    t1 = (t0 + 4760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(6696, ng0);
    t2 = (t0 + 5576);
    *((int *)t2) = 1;
    t3 = (t0 + 4792);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(6697, ng0);
    t5 = (t0 + 2648U);
    t6 = *((char **)t5);
    t5 = (t0 + 2488U);
    t7 = *((char **)t5);
    t5 = (t0 + 1688U);
    t8 = *((char **)t5);
    xsi_vlogtype_concat(t4, 3, 3, 3U, t8, 1, t7, 1, t6, 1);

LAB5:    t5 = ((char*)((ng1)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t9 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng2)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB8;

LAB9:    t2 = ((char*)((ng3)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng4)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng5)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng6)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng7)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng8)));
    t9 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t9 == 1)
        goto LAB20;

LAB21:
LAB23:
LAB22:    xsi_set_current_line(6730, ng0);

LAB33:    xsi_set_current_line(6731, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(6732, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB24:    goto LAB2;

LAB6:    xsi_set_current_line(6698, ng0);

LAB25:    xsi_set_current_line(6699, ng0);
    t10 = ((char*)((ng2)));
    t11 = (t0 + 3688);
    xsi_vlogvar_assign_value(t11, t10, 0, 0, 1);
    xsi_set_current_line(6700, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB24;

LAB8:    xsi_set_current_line(6702, ng0);

LAB26:    xsi_set_current_line(6703, ng0);
    t3 = ((char*)((ng2)));
    t5 = (t0 + 3688);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(6704, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB24;

LAB10:    xsi_set_current_line(6706, ng0);

LAB27:    xsi_set_current_line(6707, ng0);
    t3 = ((char*)((ng2)));
    t5 = (t0 + 3688);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(6708, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB24;

LAB12:    xsi_set_current_line(6710, ng0);

LAB28:    xsi_set_current_line(6711, ng0);
    t3 = ((char*)((ng2)));
    t5 = (t0 + 3688);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(6712, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB24;

LAB14:    xsi_set_current_line(6714, ng0);

LAB29:    xsi_set_current_line(6715, ng0);
    t3 = (t0 + 2968U);
    t5 = *((char **)t3);
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    xsi_set_current_line(6716, ng0);
    t2 = (t0 + 2808U);
    t3 = *((char **)t2);
    t2 = (t0 + 3848);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    goto LAB24;

LAB16:    xsi_set_current_line(6718, ng0);

LAB30:    xsi_set_current_line(6719, ng0);
    t3 = (t0 + 2968U);
    t5 = *((char **)t3);
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    xsi_set_current_line(6720, ng0);
    t2 = (t0 + 2808U);
    t3 = *((char **)t2);
    t2 = (t0 + 3848);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    goto LAB24;

LAB18:    xsi_set_current_line(6722, ng0);

LAB31:    xsi_set_current_line(6723, ng0);
    t3 = (t0 + 2168U);
    t5 = *((char **)t3);
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    xsi_set_current_line(6724, ng0);
    t2 = (t0 + 2328U);
    t3 = *((char **)t2);
    t2 = (t0 + 3848);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    goto LAB24;

LAB20:    xsi_set_current_line(6726, ng0);

LAB32:    xsi_set_current_line(6727, ng0);
    t3 = (t0 + 3288U);
    t5 = *((char **)t3);
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 1);
    xsi_set_current_line(6728, ng0);
    t2 = (t0 + 3128U);
    t3 = *((char **)t2);
    t2 = (t0 + 3848);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    goto LAB24;

}

static void Cont_6736_1(char *t0)
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

LAB0:    t1 = (t0 + 5008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(6736, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5688);
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
    t18 = (t0 + 5592);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_6737_2(char *t0)
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

LAB0:    t1 = (t0 + 5256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(6737, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5752);
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
    t18 = (t0 + 5608);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void secureip_m_11587532380784211522_4019316665_init()
{
	static char *pe[] = {(void *)Always_6696_0,(void *)Cont_6736_1,(void *)Cont_6737_2};
	xsi_register_didat("secureip_m_11587532380784211522_4019316665", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_11587532380784211522_4019316665.didat");
	xsi_register_executes(pe);
}
