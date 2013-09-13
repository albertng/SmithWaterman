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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/phy_control/SIP_PHY_CONTROL.v";
static int ng1[] = {1, 0};
static int ng2[] = {0, 0};
static int ng3[] = {12229747, 0};
static int ng4[] = {2260000, 0};
static int ng5[] = {30000, 0};
static int ng6[] = {1380000, 0};
static int ng7[] = {10000, 0};
static int ng8[] = {5000, 0};
static int ng9[] = {335000, 0};



static void Initial_696_0(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    double t7;
    double t8;
    char *t9;

LAB0:    t1 = (t0 + 3000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(696, ng0);

LAB4:    xsi_set_current_line(697, ng0);
    t2 = (t0 + 2808);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(698, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(699, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(700, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(701, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(702, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(703, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_signed_divide(t6, 32, t2, 32, t5, 32);
    t7 = xsi_vlog_convert_to_real(t6, 32, 1);
    t8 = (t7 < 0.0000000000000000);
    if (t8 == 1)
        goto LAB6;

LAB7:    t7 = (t7 + 0.50000000000000000);
    t7 = ((int64)(t7));

LAB8:    t7 = (t7 * 1000.0000000000000);
    t9 = (t0 + 2808);
    xsi_process_wait(t9, t7);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB6:    t7 = 0.0000000000000000;
    goto LAB8;

LAB9:    xsi_set_current_line(704, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(705, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_signed_divide(t6, 32, t2, 32, t5, 32);
    t7 = xsi_vlog_convert_to_real(t6, 32, 1);
    t8 = (t7 < 0.0000000000000000);
    if (t8 == 1)
        goto LAB10;

LAB11:    t7 = (t7 + 0.50000000000000000);
    t7 = ((int64)(t7));

LAB12:    t7 = (t7 * 1000.0000000000000);
    t9 = (t0 + 2808);
    xsi_process_wait(t9, t7);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB10:    t7 = 0.0000000000000000;
    goto LAB12;

LAB13:    xsi_set_current_line(706, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(707, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_signed_divide(t6, 32, t2, 32, t5, 32);
    t7 = xsi_vlog_convert_to_real(t6, 32, 1);
    t8 = (t7 < 0.0000000000000000);
    if (t8 == 1)
        goto LAB14;

LAB15:    t7 = (t7 + 0.50000000000000000);
    t7 = ((int64)(t7));

LAB16:    t7 = (t7 * 1000.0000000000000);
    t9 = (t0 + 2808);
    xsi_process_wait(t9, t7);
    *((char **)t1) = &&LAB17;
    goto LAB1;

LAB14:    t7 = 0.0000000000000000;
    goto LAB16;

LAB17:    xsi_set_current_line(708, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(709, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_signed_divide(t6, 32, t2, 32, t5, 32);
    t7 = xsi_vlog_convert_to_real(t6, 32, 1);
    t8 = (t7 < 0.0000000000000000);
    if (t8 == 1)
        goto LAB18;

LAB19:    t7 = (t7 + 0.50000000000000000);
    t7 = ((int64)(t7));

LAB20:    t7 = (t7 * 1000.0000000000000);
    t9 = (t0 + 2808);
    xsi_process_wait(t9, t7);
    *((char **)t1) = &&LAB21;
    goto LAB1;

LAB18:    t7 = 0.0000000000000000;
    goto LAB20;

LAB21:    xsi_set_current_line(710, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(711, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_signed_divide(t6, 32, t2, 32, t5, 32);
    t7 = xsi_vlog_convert_to_real(t6, 32, 1);
    t8 = (t7 < 0.0000000000000000);
    if (t8 == 1)
        goto LAB22;

LAB23:    t7 = (t7 + 0.50000000000000000);
    t7 = ((int64)(t7));

LAB24:    t7 = (t7 * 1000.0000000000000);
    t9 = (t0 + 2808);
    xsi_process_wait(t9, t7);
    *((char **)t1) = &&LAB25;
    goto LAB1;

LAB22:    t7 = 0.0000000000000000;
    goto LAB24;

LAB25:    xsi_set_current_line(712, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(713, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_signed_divide(t6, 32, t2, 32, t5, 32);
    t7 = xsi_vlog_convert_to_real(t6, 32, 1);
    t8 = (t7 < 0.0000000000000000);
    if (t8 == 1)
        goto LAB26;

LAB27:    t7 = (t7 + 0.50000000000000000);
    t7 = ((int64)(t7));

LAB28:    t7 = (t7 * 1000.0000000000000);
    t9 = (t0 + 2808);
    xsi_process_wait(t9, t7);
    *((char **)t1) = &&LAB29;
    goto LAB1;

LAB26:    t7 = 0.0000000000000000;
    goto LAB28;

LAB29:    xsi_set_current_line(714, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(715, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1288);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_signed_divide(t6, 32, t2, 32, t5, 32);
    t7 = xsi_vlog_convert_to_real(t6, 32, 1);
    t8 = (t7 < 0.0000000000000000);
    if (t8 == 1)
        goto LAB30;

LAB31:    t7 = (t7 + 0.50000000000000000);
    t7 = ((int64)(t7));

LAB32:    t7 = (t7 * 1000.0000000000000);
    t9 = (t0 + 2808);
    xsi_process_wait(t9, t7);
    *((char **)t1) = &&LAB33;
    goto LAB1;

LAB30:    t7 = 0.0000000000000000;
    goto LAB32;

LAB33:    xsi_set_current_line(716, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB1;

}


extern void secureip_m_15383170757244245533_0062413351_init()
{
	static char *pe[] = {(void *)Initial_696_0};
	xsi_register_didat("secureip_m_15383170757244245533_0062413351", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_15383170757244245533_0062413351.didat");
	xsi_register_executes(pe);
}
