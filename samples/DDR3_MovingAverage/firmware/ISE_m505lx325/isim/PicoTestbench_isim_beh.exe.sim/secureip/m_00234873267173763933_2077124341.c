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
static unsigned int ng1[] = {1500U, 0U, 0U, 0U};
static int ng2[] = {0, 0};

static void NetReassign_6559_3(char *);


static void Always_6550_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    double t9;
    double t10;

LAB0:    t1 = (t0 + 3936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(6550, ng0);
    t2 = (t0 + 5000);
    *((int *)t2) = 1;
    t3 = (t0 + 3968);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(6550, ng0);

LAB5:    xsi_set_current_line(6552, ng0);
    t4 = (t0 + 2464U);
    t5 = *((char **)t4);
    t4 = (t0 + 2864);
    t6 = (t0 + 3024);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = *((double *)t8);
    t9 = (t9 * 1000.0000000000000);
    t10 = (t9 < 0.0000000000000000);
    if (t10 == 1)
        goto LAB6;

LAB7:    t9 = (t9 + 0.50000000000000000);
    t9 = ((int64)(t9));

LAB8:    t9 = (t9 * 1.0000000000000000);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, t9);
    goto LAB2;

LAB6:    t9 = 0.0000000000000000;
    goto LAB8;

}

static void Cont_6555_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 4184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(6555, ng0);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t6) == 0)
        goto LAB4;

LAB6:    t12 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t3 + 4);
    t14 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (~(t15));
    *((unsigned int *)t3) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB9;

LAB8:    t21 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 5096);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0);
    t36 = (t0 + 5016);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t17 = *((unsigned int *)t3);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t3) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB8;

}

static void Initial_6557_2(char *t0)
{
    char *t1;
    char *t2;
    double t3;
    double t4;
    double t5;
    char *t6;

LAB0:    t1 = (t0 + 4432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(6557, ng0);

LAB4:    xsi_set_current_line(6558, ng0);
    t2 = ((char*)((ng1)));
    t3 = xsi_vlog_convert_to_real(t2, 32, 1);
    t4 = (t3 * 103.00000000000000);
    t5 = (t4 / 360.00000000000000);
    t6 = (t0 + 3024);
    xsi_vlogvar_assign_value_double(t6, t5, 0);
    xsi_set_current_line(6559, ng0);
    t2 = (t0 + 2864);
    xsi_set_forcedflag(t2);
    t6 = (t0 + 6504);
    *((int *)t6) = 1;
    NetReassign_6559_3(t0);
    xsi_set_current_line(6560, ng0);
    t2 = (t0 + 4240);
    xsi_process_wait(t2, 3000000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(6560, ng0);
    t6 = (t0 + 2864);
    xsi_vlogvar_release(t6, 0, 0);
    goto LAB1;

}

static void NetReassign_6559_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(6559, ng0);
    t3 = 0;
    t2 = ((char*)((ng2)));
    t4 = (t0 + 6504);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 2864);
    xsi_vlogvar_forcevalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}


extern void secureip_m_00234873267173763933_2077124341_init()
{
	static char *pe[] = {(void *)Always_6550_0,(void *)Cont_6555_1,(void *)Initial_6557_2,(void *)NetReassign_6559_3};
	xsi_register_didat("secureip_m_00234873267173763933_2077124341", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_00234873267173763933_2077124341.didat");
	xsi_register_executes(pe);
}
