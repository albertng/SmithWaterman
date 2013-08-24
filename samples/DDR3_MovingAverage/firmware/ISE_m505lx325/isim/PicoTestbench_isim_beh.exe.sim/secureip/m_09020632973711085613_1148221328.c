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
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};



static void Always_2969_0(char *t0)
{
    char t13[8];
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
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    int t19;

LAB0:    t1 = (t0 + 4824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2969, ng0);
    t2 = (t0 + 5144);
    *((int *)t2) = 1;
    t3 = (t0 + 4856);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(2969, ng0);

LAB5:    xsi_set_current_line(2970, ng0);
    t4 = (t0 + 2072U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(2973, ng0);

LAB10:    xsi_set_current_line(2974, ng0);
    t2 = (t0 + 2872U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 255U);
    if (t10 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t2) != 0)
        goto LAB13;

LAB14:    t5 = (t0 + 3912);
    t11 = (t0 + 3912);
    t12 = (t11 + 72U);
    t15 = *((char **)t12);
    t16 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t14, t15, 2, t16, 32, 1);
    t17 = (t14 + 4);
    t18 = *((unsigned int *)t17);
    t19 = (!(t18));
    if (t19 == 1)
        goto LAB15;

LAB16:    xsi_set_current_line(2975, ng0);
    t2 = (t0 + 3032U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 255U);
    if (t10 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t2) != 0)
        goto LAB19;

LAB20:    t5 = (t0 + 3912);
    t11 = (t0 + 3912);
    t12 = (t11 + 72U);
    t15 = *((char **)t12);
    t16 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t14, t15, 2, t16, 32, 1);
    t17 = (t14 + 4);
    t18 = *((unsigned int *)t17);
    t19 = (!(t18));
    if (t19 == 1)
        goto LAB21;

LAB22:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(2970, ng0);

LAB9:    xsi_set_current_line(2971, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 2, 10000LL);
    goto LAB8;

LAB11:    *((unsigned int *)t13) = 1;
    goto LAB14;

LAB13:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB14;

LAB15:    xsi_vlogvar_wait_assign_value(t5, t13, 0, *((unsigned int *)t14), 1, 10000LL);
    goto LAB16;

LAB17:    *((unsigned int *)t13) = 1;
    goto LAB20;

LAB19:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB20;

LAB21:    xsi_vlogvar_wait_assign_value(t5, t13, 0, *((unsigned int *)t14), 1, 10000LL);
    goto LAB22;

}


extern void secureip_m_09020632973711085613_1148221328_init()
{
	static char *pe[] = {(void *)Always_2969_0};
	xsi_register_didat("secureip_m_09020632973711085613_1148221328", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_09020632973711085613_1148221328.didat");
	xsi_register_executes(pe);
}
