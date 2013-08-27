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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/PicoAXIArbiter.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};



static void Cont_70_0(char *t0)
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
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 3912U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1640U);
    t4 = *((char **)t2);
    t2 = (t0 + 1640U);
    t5 = *((char **)t2);
    xsi_vlogtype_concat(t3, 4, 4, 2U, t5, 2, t4, 2);
    t2 = (t0 + 5368);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 15U;
    t11 = t10;
    t12 = (t3 + 4);
    t13 = *((unsigned int *)t3);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t2, 0, 3);
    t18 = (t0 + 5224);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_73_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4160U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 5240);
    *((int *)t2) = 1;
    t3 = (t0 + 4192);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(73, ng0);

LAB5:    xsi_set_current_line(74, ng0);
    t4 = (t0 + 1480U);
    t5 = *((char **)t4);
    t4 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 0LL);
    goto LAB2;

}

static void Always_78_2(char *t0)
{
    char t15[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;

LAB0:    t1 = (t0 + 4408U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 5256);
    *((int *)t2) = 1;
    t3 = (t0 + 4440);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(78, ng0);

LAB5:    xsi_set_current_line(79, ng0);
    t4 = (t0 + 3000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB10;

LAB11:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(79, ng0);

LAB9:    xsi_set_current_line(80, ng0);
    t13 = ((char*)((ng1)));
    t14 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 2, 0LL);
    goto LAB8;

LAB10:    xsi_set_current_line(81, ng0);

LAB13:    xsi_set_current_line(82, ng0);
    t4 = (t0 + 1960U);
    t5 = *((char **)t4);
    t4 = (t0 + 2680);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t13 = ((char*)((ng2)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 32, t7, 1, t13, 32);
    memset(t16, 0, 8);
    xsi_vlog_unsigned_rshift(t16, 4, t5, 4, t15, 32);
    t14 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t14, t16, 0, 0, 2, 0LL);
    goto LAB12;

}

static void Always_87_3(char *t0)
{
    char t6[8];
    char t16[8];
    char t33[8];
    char t37[8];
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
    char *t15;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t38;

LAB0:    t1 = (t0 + 4656U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 5272);
    *((int *)t2) = 1;
    t3 = (t0 + 4688);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(87, ng0);

LAB5:    xsi_set_current_line(88, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 2680);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(92, ng0);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 472);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_minus(t6, 32, t3, 32, t2, 32);
    t4 = (t0 + 2840);
    xsi_vlogvar_assign_value(t4, t6, 0, 0, 32);

LAB6:    t2 = (t0 + 2840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_signed_greatereq(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB7;

LAB8:    goto LAB2;

LAB7:    xsi_set_current_line(92, ng0);

LAB9:    xsi_set_current_line(93, ng0);
    t13 = (t0 + 2520);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t17 = (t0 + 2520);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t20 = (t0 + 2840);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    xsi_vlog_generic_get_index_select_value(t16, 1, t15, t19, 2, t22, 32, 1);
    t23 = (t16 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t16);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB10;

LAB11:
LAB12:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 2840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_minus(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 2840);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB6;

LAB10:    xsi_set_current_line(93, ng0);

LAB13:    xsi_set_current_line(94, ng0);
    t29 = (t0 + 2360);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    t32 = ((char*)((ng2)));
    memset(t33, 0, 8);
    xsi_vlog_unsigned_add(t33, 32, t31, 1, t32, 32);
    t34 = (t0 + 2840);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    memset(t37, 0, 8);
    xsi_vlog_unsigned_add(t37, 32, t33, 32, t36, 32);
    t38 = (t0 + 2680);
    xsi_vlogvar_assign_value(t38, t37, 0, 0, 1);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 2680);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 472);
    t7 = *((char **)t5);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB15;

LAB14:    t13 = (t7 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB15;

LAB18:    if (*((unsigned int *)t4) < *((unsigned int *)t7))
        goto LAB17;

LAB16:    *((unsigned int *)t6) = 1;

LAB17:    t15 = (t6 + 4);
    t8 = *((unsigned int *)t15);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB19;

LAB20:
LAB21:    goto LAB12;

LAB15:    t14 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB17;

LAB19:    xsi_set_current_line(95, ng0);

LAB22:    xsi_set_current_line(96, ng0);
    t17 = (t0 + 2680);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 472);
    t21 = *((char **)t20);
    memset(t16, 0, 8);
    xsi_vlog_unsigned_minus(t16, 32, t19, 1, t21, 32);
    t20 = (t0 + 2680);
    xsi_vlogvar_assign_value(t20, t16, 0, 0, 1);
    goto LAB21;

}

static void Always_103_4(char *t0)
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
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;

LAB0:    t1 = (t0 + 4904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 5288);
    *((int *)t2) = 1;
    t3 = (t0 + 4936);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(103, ng0);

LAB5:    xsi_set_current_line(104, ng0);
    t4 = (t0 + 3000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB10;

LAB11:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(104, ng0);

LAB9:    xsi_set_current_line(105, ng0);
    t13 = ((char*)((ng1)));
    t14 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 1, 0LL);
    goto LAB8;

LAB10:    xsi_set_current_line(106, ng0);

LAB13:    xsi_set_current_line(107, ng0);
    t4 = (t0 + 2680);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 1, 0LL);
    goto LAB12;

}


extern void work_m_08849139062885702042_1327769645_init()
{
	static char *pe[] = {(void *)Cont_70_0,(void *)Always_73_1,(void *)Always_78_2,(void *)Always_87_3,(void *)Always_103_4};
	xsi_register_didat("work_m_08849139062885702042_1327769645", "isim/PicoTestbench_isim_beh.exe.sim/work/m_08849139062885702042_1327769645.didat");
	xsi_register_executes(pe);
}
