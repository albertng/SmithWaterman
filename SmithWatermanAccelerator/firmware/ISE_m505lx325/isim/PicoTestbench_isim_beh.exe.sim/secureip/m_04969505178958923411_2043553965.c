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
static int ng1[] = {0, 0};
static unsigned int ng2[] = {63U, 0U};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {0U, 0U};
static unsigned int ng5[] = {7U, 0U};



static void Always_1193_0(char *t0)
{
    char t11[8];
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
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;

LAB0:    t1 = (t0 + 4440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1193, ng0);
    t2 = (t0 + 5008);
    *((int *)t2) = 1;
    t3 = (t0 + 4472);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(1193, ng0);

LAB5:    xsi_set_current_line(1194, ng0);
    t4 = (t0 + 2648U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(1197, ng0);
    t2 = (t0 + 2328U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB10;

LAB11:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(1194, ng0);

LAB9:    xsi_set_current_line(1195, ng0);
    t12 = (t0 + 2168U);
    t13 = *((char **)t12);
    memset(t11, 0, 8);
    t12 = (t11 + 4);
    t14 = (t13 + 4);
    t15 = *((unsigned int *)t13);
    t16 = (t15 >> 0);
    *((unsigned int *)t11) = t16;
    t17 = *((unsigned int *)t14);
    t18 = (t17 >> 0);
    *((unsigned int *)t12) = t18;
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t19 & 63U);
    t20 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t20 & 63U);
    t21 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t21, t11, 0, 0, 6, 50000LL);
    xsi_set_current_line(1196, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);
    goto LAB8;

LAB10:    xsi_set_current_line(1197, ng0);

LAB13:    xsi_set_current_line(1198, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(1199, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB17;

LAB18:
LAB19:
LAB16:    goto LAB12;

LAB14:    xsi_set_current_line(1198, ng0);
    t12 = (t0 + 1848U);
    t13 = *((char **)t12);
    memset(t11, 0, 8);
    t12 = (t11 + 4);
    t14 = (t13 + 4);
    t20 = *((unsigned int *)t13);
    t22 = (t20 >> 0);
    *((unsigned int *)t11) = t22;
    t23 = *((unsigned int *)t14);
    t24 = (t23 >> 0);
    *((unsigned int *)t12) = t24;
    t25 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t25 & 63U);
    t26 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t26 & 63U);
    t21 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t21, t11, 0, 0, 6, 50000LL);
    goto LAB16;

LAB17:    xsi_set_current_line(1199, ng0);

LAB20:    xsi_set_current_line(1200, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(1206, ng0);

LAB33:    xsi_set_current_line(1207, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t11, 0, 8);
    t12 = (t4 + 4);
    t13 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t12);
    t10 = *((unsigned int *)t13);
    t15 = (t9 ^ t10);
    t16 = (t8 | t15);
    t17 = *((unsigned int *)t12);
    t18 = *((unsigned int *)t13);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t22 = (t16 & t20);
    if (t22 != 0)
        goto LAB37;

LAB34:    if (t19 != 0)
        goto LAB36;

LAB35:    *((unsigned int *)t11) = 1;

LAB37:    t21 = (t11 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (~(t23));
    t25 = *((unsigned int *)t11);
    t26 = (t25 & t24);
    t29 = (t26 != 0);
    if (t29 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(1208, ng0);

LAB41:    xsi_set_current_line(1209, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_minus(t11, 32, t4, 6, t5, 32);
    t12 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 6, 50000LL);
    xsi_set_current_line(1210, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);

LAB40:
LAB23:    goto LAB19;

LAB21:    xsi_set_current_line(1200, ng0);

LAB24:    xsi_set_current_line(1201, ng0);
    t12 = (t0 + 3208);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t21 = ((char*)((ng2)));
    memset(t11, 0, 8);
    t27 = (t14 + 4);
    t28 = (t21 + 4);
    t20 = *((unsigned int *)t14);
    t22 = *((unsigned int *)t21);
    t23 = (t20 ^ t22);
    t24 = *((unsigned int *)t27);
    t25 = *((unsigned int *)t28);
    t26 = (t24 ^ t25);
    t29 = (t23 | t26);
    t30 = *((unsigned int *)t27);
    t31 = *((unsigned int *)t28);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t34 = (t29 & t33);
    if (t34 != 0)
        goto LAB28;

LAB25:    if (t32 != 0)
        goto LAB27;

LAB26:    *((unsigned int *)t11) = 1;

LAB28:    t36 = (t11 + 4);
    t37 = *((unsigned int *)t36);
    t38 = (~(t37));
    t39 = *((unsigned int *)t11);
    t40 = (t39 & t38);
    t41 = (t40 != 0);
    if (t41 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(1202, ng0);

LAB32:    xsi_set_current_line(1203, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t4, 6, t5, 32);
    t12 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 6, 50000LL);
    xsi_set_current_line(1204, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);

LAB31:    goto LAB23;

LAB27:    t35 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB28;

LAB29:    xsi_set_current_line(1201, ng0);
    t42 = ((char*)((ng3)));
    t43 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t43, t42, 0, 0, 1, 50000LL);
    goto LAB31;

LAB36:    t14 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB37;

LAB38:    xsi_set_current_line(1207, ng0);
    t27 = ((char*)((ng3)));
    t28 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t28, t27, 0, 0, 1, 50000LL);
    goto LAB40;

}

static void Always_1217_1(char *t0)
{
    char t11[8];
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
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;

LAB0:    t1 = (t0 + 4688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(1217, ng0);
    t2 = (t0 + 5024);
    *((int *)t2) = 1;
    t3 = (t0 + 4720);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(1217, ng0);

LAB5:    xsi_set_current_line(1218, ng0);
    t4 = (t0 + 2648U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(1221, ng0);
    t2 = (t0 + 2328U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB10;

LAB11:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(1218, ng0);

LAB9:    xsi_set_current_line(1219, ng0);
    t12 = (t0 + 2008U);
    t13 = *((char **)t12);
    memset(t11, 0, 8);
    t12 = (t11 + 4);
    t14 = (t13 + 4);
    t15 = *((unsigned int *)t13);
    t16 = (t15 >> 0);
    *((unsigned int *)t11) = t16;
    t17 = *((unsigned int *)t14);
    t18 = (t17 >> 0);
    *((unsigned int *)t12) = t18;
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t19 & 7U);
    t20 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t20 & 7U);
    t21 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t21, t11, 0, 0, 3, 50000LL);
    xsi_set_current_line(1220, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);
    goto LAB8;

LAB10:    xsi_set_current_line(1221, ng0);

LAB13:    xsi_set_current_line(1222, ng0);
    t4 = (t0 + 1688U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(1223, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB17;

LAB18:
LAB19:
LAB16:    goto LAB12;

LAB14:    xsi_set_current_line(1222, ng0);
    t12 = (t0 + 1848U);
    t13 = *((char **)t12);
    memset(t11, 0, 8);
    t12 = (t11 + 4);
    t14 = (t13 + 4);
    t20 = *((unsigned int *)t13);
    t22 = (t20 >> 6);
    *((unsigned int *)t11) = t22;
    t23 = *((unsigned int *)t14);
    t24 = (t23 >> 6);
    *((unsigned int *)t12) = t24;
    t25 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t25 & 7U);
    t26 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t26 & 7U);
    t21 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t21, t11, 0, 0, 3, 50000LL);
    goto LAB16;

LAB17:    xsi_set_current_line(1223, ng0);

LAB20:    xsi_set_current_line(1224, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(1230, ng0);

LAB33:    xsi_set_current_line(1231, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t11, 0, 8);
    t12 = (t4 + 4);
    t13 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t12);
    t10 = *((unsigned int *)t13);
    t15 = (t9 ^ t10);
    t16 = (t8 | t15);
    t17 = *((unsigned int *)t12);
    t18 = *((unsigned int *)t13);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t22 = (t16 & t20);
    if (t22 != 0)
        goto LAB37;

LAB34:    if (t19 != 0)
        goto LAB36;

LAB35:    *((unsigned int *)t11) = 1;

LAB37:    t21 = (t11 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (~(t23));
    t25 = *((unsigned int *)t11);
    t26 = (t25 & t24);
    t29 = (t26 != 0);
    if (t29 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(1232, ng0);

LAB41:    xsi_set_current_line(1233, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_minus(t11, 32, t4, 3, t5, 32);
    t12 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 50000LL);
    xsi_set_current_line(1234, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);

LAB40:
LAB23:    goto LAB19;

LAB21:    xsi_set_current_line(1224, ng0);

LAB24:    xsi_set_current_line(1225, ng0);
    t12 = (t0 + 3048);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t21 = ((char*)((ng5)));
    memset(t11, 0, 8);
    t27 = (t14 + 4);
    t28 = (t21 + 4);
    t20 = *((unsigned int *)t14);
    t22 = *((unsigned int *)t21);
    t23 = (t20 ^ t22);
    t24 = *((unsigned int *)t27);
    t25 = *((unsigned int *)t28);
    t26 = (t24 ^ t25);
    t29 = (t23 | t26);
    t30 = *((unsigned int *)t27);
    t31 = *((unsigned int *)t28);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t34 = (t29 & t33);
    if (t34 != 0)
        goto LAB28;

LAB25:    if (t32 != 0)
        goto LAB27;

LAB26:    *((unsigned int *)t11) = 1;

LAB28:    t36 = (t11 + 4);
    t37 = *((unsigned int *)t36);
    t38 = (~(t37));
    t39 = *((unsigned int *)t11);
    t40 = (t39 & t38);
    t41 = (t40 != 0);
    if (t41 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(1226, ng0);

LAB32:    xsi_set_current_line(1227, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t4, 3, t5, 32);
    t12 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 50000LL);
    xsi_set_current_line(1228, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);

LAB31:    goto LAB23;

LAB27:    t35 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB28;

LAB29:    xsi_set_current_line(1225, ng0);
    t42 = ((char*)((ng3)));
    t43 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t43, t42, 0, 0, 1, 50000LL);
    goto LAB31;

LAB36:    t14 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB37;

LAB38:    xsi_set_current_line(1231, ng0);
    t27 = ((char*)((ng3)));
    t28 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t28, t27, 0, 0, 1, 50000LL);
    goto LAB40;

}


extern void secureip_m_04969505178958923411_2043553965_init()
{
	static char *pe[] = {(void *)Always_1193_0,(void *)Always_1217_1};
	xsi_register_didat("secureip_m_04969505178958923411_2043553965", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_04969505178958923411_2043553965.didat");
	xsi_register_executes(pe);
}
