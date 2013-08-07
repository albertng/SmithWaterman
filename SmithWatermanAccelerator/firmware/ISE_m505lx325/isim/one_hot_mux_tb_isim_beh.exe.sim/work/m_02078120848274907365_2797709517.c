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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/DDR3_MovingAverage/firmware/one_hot_mux_tb.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {83U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {3U, 0U};
static const char *ng5 = "Error, Select %d: Got %d Expected %d";
static unsigned int ng6[] = {2U, 0U};
static unsigned int ng7[] = {4U, 0U};
static unsigned int ng8[] = {8U, 0U};
static unsigned int ng9[] = {0U, 0U};



static void Initial_26_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
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
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    t1 = (t0 + 2520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(26, ng0);

LAB4:    xsi_set_current_line(28, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 12);
    xsi_set_current_line(29, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(32, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 12);
    xsi_set_current_line(35, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(36, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB8;

LAB7:    if (t16 != 0)
        goto LAB9;

LAB10:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB11;

LAB12:
LAB13:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB10;

LAB9:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB10;

LAB11:    xsi_set_current_line(37, ng0);

LAB14:    xsi_set_current_line(38, ng0);
    t26 = (t0 + 1608);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t0 + 1048U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng4)));
    xsi_vlogfile_write(1, 0, 0, ng5, 4, t0, (char)118, t28, 4, (char)118, t30, 3, (char)118, t29, 3);
    goto LAB13;

LAB15:    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB18;

LAB17:    if (t16 != 0)
        goto LAB19;

LAB20:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB21;

LAB22:
LAB23:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB25;
    goto LAB1;

LAB18:    *((unsigned int *)t4) = 1;
    goto LAB20;

LAB19:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB20;

LAB21:    xsi_set_current_line(43, ng0);

LAB24:    xsi_set_current_line(44, ng0);
    t26 = (t0 + 1608);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t0 + 1048U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng6)));
    xsi_vlogfile_write(1, 0, 0, ng5, 4, t0, (char)118, t28, 4, (char)118, t30, 3, (char)118, t29, 3);
    goto LAB23;

LAB25:    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB26;
    goto LAB1;

LAB26:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB28;

LAB27:    if (t16 != 0)
        goto LAB29;

LAB30:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB31;

LAB32:
LAB33:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB28:    *((unsigned int *)t4) = 1;
    goto LAB30;

LAB29:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB30;

LAB31:    xsi_set_current_line(49, ng0);

LAB34:    xsi_set_current_line(50, ng0);
    t26 = (t0 + 1608);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t0 + 1048U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng3)));
    xsi_vlogfile_write(1, 0, 0, ng5, 4, t0, (char)118, t28, 4, (char)118, t30, 3, (char)118, t29, 3);
    goto LAB33;

LAB35:    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB36;
    goto LAB1;

LAB36:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB38;

LAB37:    if (t16 != 0)
        goto LAB39;

LAB40:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB41;

LAB42:
LAB43:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB45;
    goto LAB1;

LAB38:    *((unsigned int *)t4) = 1;
    goto LAB40;

LAB39:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB40;

LAB41:    xsi_set_current_line(55, ng0);

LAB44:    xsi_set_current_line(56, ng0);
    t26 = (t0 + 1608);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t0 + 1048U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng9)));
    xsi_vlogfile_write(1, 0, 0, ng5, 4, t0, (char)118, t28, 4, (char)118, t30, 3, (char)118, t29, 3);
    goto LAB43;

LAB45:    xsi_set_current_line(60, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_02078120848274907365_2797709517_init()
{
	static char *pe[] = {(void *)Initial_26_0};
	xsi_register_didat("work_m_02078120848274907365_2797709517", "isim/one_hot_mux_tb_isim_beh.exe.sim/work/m_02078120848274907365_2797709517.didat");
	xsi_register_executes(pe);
}
