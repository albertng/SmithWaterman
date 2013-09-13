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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/coregen-LX325T/mig_M505_DDR3/rtl/axi/mig_7series_v1_8_ddr_axic_register_slice.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {2U, 0U};
static unsigned int ng3[] = {1U, 0U};



static void Cont_527_0(char *t0)
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

LAB0:    t1 = (t0 + 4368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(527, ng0);
    t2 = (t0 + 3136);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5824);
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
    t18 = (t0 + 5680);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_528_1(char *t0)
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

LAB0:    t1 = (t0 + 4616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(528, ng0);
    t2 = (t0 + 3296);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5888);
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
    t18 = (t0 + 5696);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_531_2(char *t0)
{
    char t4[8];
    char t9[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 4864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(531, ng0);
    t2 = (t0 + 5712);
    *((int *)t2) = 1;
    t3 = (t0 + 4896);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(531, ng0);

LAB5:    xsi_set_current_line(532, ng0);
    t5 = (t0 + 1616U);
    t6 = *((char **)t5);
    t5 = (t0 + 3456);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    xsi_vlogtype_concat(t4, 2, 2, 2U, t9, 1, t6, 1);
    t18 = (t0 + 3456);
    xsi_vlogvar_wait_assign_value(t18, t4, 0, 0, 2, 0LL);
    goto LAB2;

}

static void Always_536_3(char *t0)
{
    char t13[8];
    char t33[8];
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
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    int t56;
    int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;

LAB0:    t1 = (t0 + 5112U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(536, ng0);
    t2 = (t0 + 5728);
    *((int *)t2) = 1;
    t3 = (t0 + 5144);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(537, ng0);

LAB5:    xsi_set_current_line(538, ng0);
    t4 = (t0 + 1616U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(541, ng0);
    t2 = (t0 + 3456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB13;

LAB10:    if (t18 != 0)
        goto LAB12;

LAB11:    *((unsigned int *)t13) = 1;

LAB13:    t22 = (t13 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(543, ng0);
    t2 = (t0 + 3456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB21;

LAB18:    if (t18 != 0)
        goto LAB20;

LAB19:    *((unsigned int *)t13) = 1;

LAB21:    t22 = (t13 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB22;

LAB23:
LAB24:
LAB16:
LAB8:    xsi_set_current_line(552, ng0);
    t2 = (t0 + 3296);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t13, 0, 8);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB43;

LAB41:    if (*((unsigned int *)t5) == 0)
        goto LAB40;

LAB42:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;

LAB43:    t12 = (t13 + 4);
    t21 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (~(t14));
    *((unsigned int *)t13) = t15;
    *((unsigned int *)t12) = 0;
    if (*((unsigned int *)t21) != 0)
        goto LAB45;

LAB44:    t20 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t20 & 1U);
    t23 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t23 & 1U);
    t22 = (t13 + 4);
    t24 = *((unsigned int *)t22);
    t25 = (~(t24));
    t26 = *((unsigned int *)t13);
    t27 = (t26 & t25);
    t34 = (t27 != 0);
    if (t34 > 0)
        goto LAB46;

LAB47:
LAB48:    goto LAB2;

LAB6:    xsi_set_current_line(538, ng0);

LAB9:    xsi_set_current_line(539, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    xsi_set_current_line(540, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3296);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB8;

LAB12:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB13;

LAB14:    xsi_set_current_line(541, ng0);

LAB17:    xsi_set_current_line(542, ng0);
    t28 = ((char*)((ng3)));
    t29 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 1, 0LL);
    goto LAB16;

LAB20:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB21;

LAB22:    xsi_set_current_line(543, ng0);

LAB25:    xsi_set_current_line(544, ng0);
    t28 = (t0 + 3296);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t31 = (t0 + 2576U);
    t32 = *((char **)t31);
    t34 = *((unsigned int *)t30);
    t35 = *((unsigned int *)t32);
    t36 = (t34 & t35);
    *((unsigned int *)t33) = t36;
    t31 = (t30 + 4);
    t37 = (t32 + 4);
    t38 = (t33 + 4);
    t39 = *((unsigned int *)t31);
    t40 = *((unsigned int *)t37);
    t41 = (t39 | t40);
    *((unsigned int *)t38) = t41;
    t42 = *((unsigned int *)t38);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB26;

LAB27:
LAB28:    t64 = (t33 + 4);
    t65 = *((unsigned int *)t64);
    t66 = (~(t65));
    t67 = *((unsigned int *)t33);
    t68 = (t67 & t66);
    t69 = (t68 != 0);
    if (t69 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(547, ng0);
    t2 = (t0 + 1936U);
    t3 = *((char **)t2);
    t2 = (t0 + 3136);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t5);
    t8 = (t6 & t7);
    *((unsigned int *)t13) = t8;
    t11 = (t3 + 4);
    t12 = (t5 + 4);
    t21 = (t13 + 4);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t14 = (t9 | t10);
    *((unsigned int *)t21) = t14;
    t15 = *((unsigned int *)t21);
    t16 = (t15 != 0);
    if (t16 == 1)
        goto LAB33;

LAB34:
LAB35:    t29 = (t13 + 4);
    t43 = *((unsigned int *)t29);
    t44 = (~(t43));
    t45 = *((unsigned int *)t13);
    t48 = (t45 & t44);
    t49 = (t48 != 0);
    if (t49 > 0)
        goto LAB36;

LAB37:
LAB38:
LAB31:    goto LAB24;

LAB26:    t44 = *((unsigned int *)t33);
    t45 = *((unsigned int *)t38);
    *((unsigned int *)t33) = (t44 | t45);
    t46 = (t30 + 4);
    t47 = (t32 + 4);
    t48 = *((unsigned int *)t30);
    t49 = (~(t48));
    t50 = *((unsigned int *)t46);
    t51 = (~(t50));
    t52 = *((unsigned int *)t32);
    t53 = (~(t52));
    t54 = *((unsigned int *)t47);
    t55 = (~(t54));
    t56 = (t49 & t51);
    t57 = (t53 & t55);
    t58 = (~(t56));
    t59 = (~(t57));
    t60 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t60 & t58);
    t61 = *((unsigned int *)t38);
    *((unsigned int *)t38) = (t61 & t59);
    t62 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t62 & t58);
    t63 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t63 & t59);
    goto LAB28;

LAB29:    xsi_set_current_line(544, ng0);

LAB32:    xsi_set_current_line(545, ng0);
    t70 = ((char*)((ng3)));
    t71 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t71, t70, 0, 0, 1, 0LL);
    xsi_set_current_line(546, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3296);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB31;

LAB33:    t17 = *((unsigned int *)t13);
    t18 = *((unsigned int *)t21);
    *((unsigned int *)t13) = (t17 | t18);
    t22 = (t3 + 4);
    t28 = (t5 + 4);
    t19 = *((unsigned int *)t3);
    t20 = (~(t19));
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t5);
    t26 = (~(t25));
    t27 = *((unsigned int *)t28);
    t34 = (~(t27));
    t56 = (t20 & t24);
    t57 = (t26 & t34);
    t35 = (~(t56));
    t36 = (~(t57));
    t39 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t39 & t35);
    t40 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t40 & t36);
    t41 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t41 & t35);
    t42 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t42 & t36);
    goto LAB35;

LAB36:    xsi_set_current_line(547, ng0);

LAB39:    xsi_set_current_line(548, ng0);
    t30 = ((char*)((ng1)));
    t31 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 1, 0LL);
    xsi_set_current_line(549, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3296);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB38;

LAB40:    *((unsigned int *)t13) = 1;
    goto LAB43;

LAB45:    t16 = *((unsigned int *)t13);
    t17 = *((unsigned int *)t21);
    *((unsigned int *)t13) = (t16 | t17);
    t18 = *((unsigned int *)t12);
    t19 = *((unsigned int *)t21);
    *((unsigned int *)t12) = (t18 | t19);
    goto LAB44;

LAB46:    xsi_set_current_line(552, ng0);

LAB49:    xsi_set_current_line(553, ng0);
    t28 = (t0 + 1776U);
    t29 = *((char **)t28);
    t28 = (t0 + 2976);
    xsi_vlogvar_wait_assign_value(t28, t29, 0, 0, 75, 0LL);
    goto LAB48;

}

static void Cont_556_4(char *t0)
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
    char *t10;

LAB0:    t1 = (t0 + 5360U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(556, ng0);
    t2 = (t0 + 2976);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5952);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t4, 0, 75);
    xsi_driver_vfirst_trans(t5, 0, 74);
    t10 = (t0 + 5744);
    *((int *)t10) = 1;

LAB1:    return;
}


extern void work_m_10687184325720698260_1795330315_init()
{
	static char *pe[] = {(void *)Cont_527_0,(void *)Cont_528_1,(void *)Always_531_2,(void *)Always_536_3,(void *)Cont_556_4};
	xsi_register_didat("work_m_10687184325720698260_1795330315", "isim/PicoTestbench_isim_beh.exe.sim/work/m_10687184325720698260_1795330315.didat");
	xsi_register_executes(pe);
}
