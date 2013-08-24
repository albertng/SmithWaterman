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
static int ng2[] = {8, 0};
static int ng3[] = {6, 0};
static int ng4[] = {5, 0};
static int ng5[] = {0, 0};



static void Always_965_0(char *t0)
{
    char t13[8];
    char t14[8];
    char t15[8];
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
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    int t21;
    char *t22;
    unsigned int t23;
    int t24;
    int t25;
    char *t26;
    unsigned int t27;
    int t28;
    int t29;
    unsigned int t30;
    int t31;
    unsigned int t32;
    unsigned int t33;
    int t34;
    int t35;

LAB0:    t1 = (t0 + 3000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(965, ng0);
    t2 = (t0 + 3320);
    *((int *)t2) = 1;
    t3 = (t0 + 3032);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(965, ng0);

LAB5:    xsi_set_current_line(966, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(967, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB9;

LAB10:
LAB11:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(966, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 9, 50000LL);
    goto LAB8;

LAB9:    xsi_set_current_line(967, ng0);

LAB12:    xsi_set_current_line(968, ng0);
    t4 = (t0 + 1048U);
    t5 = *((char **)t4);
    t4 = (t0 + 2088);
    t11 = (t0 + 2088);
    t12 = (t11 + 72U);
    t16 = *((char **)t12);
    t17 = ((char*)((ng2)));
    t18 = ((char*)((ng3)));
    xsi_vlog_convert_partindices(t13, t14, t15, ((int*)(t16)), 2, t17, 32, 1, t18, 32, 1);
    t19 = (t13 + 4);
    t20 = *((unsigned int *)t19);
    t21 = (!(t20));
    t22 = (t14 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (!(t23));
    t25 = (t21 && t24);
    t26 = (t15 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (!(t27));
    t29 = (t25 && t28);
    if (t29 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(969, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = (t0 + 2088);
    t4 = (t0 + 2088);
    t5 = (t4 + 72U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng4)));
    t16 = ((char*)((ng5)));
    xsi_vlog_convert_partindices(t13, t14, t15, ((int*)(t11)), 2, t12, 32, 1, t16, 32, 1);
    t17 = (t13 + 4);
    t6 = *((unsigned int *)t17);
    t21 = (!(t6));
    t18 = (t14 + 4);
    t7 = *((unsigned int *)t18);
    t24 = (!(t7));
    t25 = (t21 && t24);
    t19 = (t15 + 4);
    t8 = *((unsigned int *)t19);
    t28 = (!(t8));
    t29 = (t25 && t28);
    if (t29 == 1)
        goto LAB15;

LAB16:    goto LAB11;

LAB13:    t30 = *((unsigned int *)t15);
    t31 = (t30 + 0);
    t32 = *((unsigned int *)t13);
    t33 = *((unsigned int *)t14);
    t34 = (t32 - t33);
    t35 = (t34 + 1);
    xsi_vlogvar_wait_assign_value(t4, t5, t31, *((unsigned int *)t14), t35, 50000LL);
    goto LAB14;

LAB15:    t9 = *((unsigned int *)t15);
    t31 = (t9 + 0);
    t10 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    t34 = (t10 - t20);
    t35 = (t34 + 1);
    xsi_vlogvar_wait_assign_value(t2, t3, t31, *((unsigned int *)t14), t35, 50000LL);
    goto LAB16;

}


extern void secureip_m_04211575139649689420_2427293080_init()
{
	static char *pe[] = {(void *)Always_965_0};
	xsi_register_didat("secureip_m_04211575139649689420_2427293080", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_04211575139649689420_2427293080.didat");
	xsi_register_executes(pe);
}
