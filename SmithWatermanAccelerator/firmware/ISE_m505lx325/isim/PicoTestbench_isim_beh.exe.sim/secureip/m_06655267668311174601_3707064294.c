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
static unsigned int ng2[] = {1U, 0U};



static void Always_2418_0(char *t0)
{
    char t13[8];
    char t16[8];
    char t48[8];
    char t57[8];
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
    char *t14;
    int t15;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t47;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;

LAB0:    t1 = (t0 + 3616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2418, ng0);
    t2 = (t0 + 4184);
    *((int *)t2) = 1;
    t3 = (t0 + 3648);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(2418, ng0);

LAB5:    xsi_set_current_line(2419, ng0);
    t4 = (t0 + 1344U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(2426, ng0);

LAB12:    xsi_set_current_line(2428, ng0);
    t2 = (t0 + 1824U);
    t3 = *((char **)t2);
    t2 = (t0 + 2704);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t5);
    t8 = (t6 & t7);
    *((unsigned int *)t16) = t8;
    t11 = (t3 + 4);
    t12 = (t5 + 4);
    t14 = (t16 + 4);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t17 = (t9 | t10);
    *((unsigned int *)t14) = t17;
    t18 = *((unsigned int *)t14);
    t19 = (t18 != 0);
    if (t19 == 1)
        goto LAB13;

LAB14:
LAB15:    memset(t13, 0, 8);
    t39 = (t16 + 4);
    t40 = *((unsigned int *)t39);
    t41 = (~(t40));
    t42 = *((unsigned int *)t16);
    t43 = (t42 & t41);
    t44 = (t43 & 255U);
    if (t44 != 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t39) != 0)
        goto LAB18;

LAB19:    t46 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t46, t13, 0, 0, 1, 10000LL);
    xsi_set_current_line(2429, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 10000LL);
    xsi_set_current_line(2431, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2384);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t5);
    t8 = (t6 & t7);
    *((unsigned int *)t13) = t8;
    t11 = (t3 + 4);
    t12 = (t5 + 4);
    t14 = (t13 + 4);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t17 = (t9 | t10);
    *((unsigned int *)t14) = t17;
    t18 = *((unsigned int *)t14);
    t19 = (t18 != 0);
    if (t19 == 1)
        goto LAB20;

LAB21:
LAB22:    t39 = (t13 + 4);
    t40 = *((unsigned int *)t39);
    t41 = (~(t40));
    t42 = *((unsigned int *)t13);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB23;

LAB24:
LAB25:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(2419, ng0);

LAB9:    xsi_set_current_line(2421, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 10000LL);
    xsi_set_current_line(2422, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2704);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 10000LL);
    xsi_set_current_line(2423, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2704);
    t4 = (t0 + 2704);
    t5 = (t4 + 72U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t13, t11, 2, t12, 32, 1);
    t14 = (t13 + 4);
    t6 = *((unsigned int *)t14);
    t15 = (!(t6));
    if (t15 == 1)
        goto LAB10;

LAB11:    xsi_set_current_line(2424, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 10000LL);
    goto LAB8;

LAB10:    xsi_vlogvar_wait_assign_value(t3, t2, 0, *((unsigned int *)t13), 1, 10000LL);
    goto LAB11;

LAB13:    t20 = *((unsigned int *)t16);
    t21 = *((unsigned int *)t14);
    *((unsigned int *)t16) = (t20 | t21);
    t22 = (t3 + 4);
    t23 = (t5 + 4);
    t24 = *((unsigned int *)t3);
    t25 = (~(t24));
    t26 = *((unsigned int *)t22);
    t27 = (~(t26));
    t28 = *((unsigned int *)t5);
    t29 = (~(t28));
    t30 = *((unsigned int *)t23);
    t31 = (~(t30));
    t15 = (t25 & t27);
    t32 = (t29 & t31);
    t33 = (~(t15));
    t34 = (~(t32));
    t35 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t35 & t33);
    t36 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t36 & t34);
    t37 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t37 & t33);
    t38 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t38 & t34);
    goto LAB15;

LAB16:    *((unsigned int *)t13) = 1;
    goto LAB19;

LAB18:    t45 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB19;

LAB20:    t20 = *((unsigned int *)t13);
    t21 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t20 | t21);
    t22 = (t3 + 4);
    t23 = (t5 + 4);
    t24 = *((unsigned int *)t3);
    t25 = (~(t24));
    t26 = *((unsigned int *)t22);
    t27 = (~(t26));
    t28 = *((unsigned int *)t5);
    t29 = (~(t28));
    t30 = *((unsigned int *)t23);
    t31 = (~(t30));
    t15 = (t25 & t27);
    t32 = (t29 & t31);
    t33 = (~(t15));
    t34 = (~(t32));
    t35 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t35 & t33);
    t36 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t36 & t34);
    t37 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t37 & t33);
    t38 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t38 & t34);
    goto LAB22;

LAB23:    xsi_set_current_line(2431, ng0);

LAB26:    xsi_set_current_line(2432, ng0);
    t45 = (t0 + 2704);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    memset(t48, 0, 8);
    t49 = (t48 + 4);
    t50 = (t47 + 4);
    t51 = *((unsigned int *)t47);
    t52 = (t51 >> 7);
    t53 = (t52 & 1);
    *((unsigned int *)t48) = t53;
    t54 = *((unsigned int *)t50);
    t55 = (t54 >> 7);
    t56 = (t55 & 1);
    *((unsigned int *)t49) = t56;
    t58 = (t0 + 2704);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memset(t57, 0, 8);
    t61 = (t57 + 4);
    t62 = (t60 + 4);
    t63 = *((unsigned int *)t60);
    t64 = (t63 >> 0);
    *((unsigned int *)t57) = t64;
    t65 = *((unsigned int *)t62);
    t66 = (t65 >> 0);
    *((unsigned int *)t61) = t66;
    t67 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t67 & 127U);
    t68 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t68 & 127U);
    xsi_vlogtype_concat(t16, 8, 8, 2U, t57, 7, t48, 1);
    t69 = (t0 + 2704);
    xsi_vlogvar_wait_assign_value(t69, t16, 0, 0, 8, 10000LL);
    xsi_set_current_line(2433, ng0);
    t2 = (t0 + 2704);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 10000LL);
    goto LAB25;

}

static void Always_2439_1(char *t0)
{
    char t13[8];
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

LAB0:    t1 = (t0 + 3864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(2439, ng0);
    t2 = (t0 + 4200);
    *((int *)t2) = 1;
    t3 = (t0 + 3896);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(2439, ng0);

LAB5:    xsi_set_current_line(2440, ng0);
    t4 = (t0 + 1344U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(2443, ng0);

LAB10:    xsi_set_current_line(2444, ng0);
    t2 = (t0 + 1664U);
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

LAB14:    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t13, 0, 0, 1, 10000LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(2440, ng0);

LAB9:    xsi_set_current_line(2441, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 10000LL);
    goto LAB8;

LAB11:    *((unsigned int *)t13) = 1;
    goto LAB14;

LAB13:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB14;

}


extern void secureip_m_06655267668311174601_3707064294_init()
{
	static char *pe[] = {(void *)Always_2418_0,(void *)Always_2439_1};
	xsi_register_didat("secureip_m_06655267668311174601_3707064294", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_06655267668311174601_3707064294.didat");
	xsi_register_executes(pe);
}
