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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/phaser_in/SIP_PHASER_IN.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static int ng3[] = {1, 0};



static void Always_3633_0(char *t0)
{
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

LAB0:    t1 = (t0 + 4440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3633, ng0);
    t2 = (t0 + 5504);
    *((int *)t2) = 1;
    t3 = (t0 + 4472);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(3633, ng0);

LAB5:    xsi_set_current_line(3634, ng0);
    t4 = (t0 + 2328U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(3635, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 2, 50000LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(3634, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 2, 50000LL);
    goto LAB8;

}

static void Always_3639_1(char *t0)
{
    char t13[8];
    char t17[8];
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
    char *t15;
    char *t16;
    char *t18;
    char *t19;
    unsigned int t20;
    char *t21;

LAB0:    t1 = (t0 + 4688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3639, ng0);
    t2 = (t0 + 5520);
    *((int *)t2) = 1;
    t3 = (t0 + 4720);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(3639, ng0);

LAB5:    xsi_set_current_line(3640, ng0);
    t4 = (t0 + 2328U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(3641, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2888);
    t11 = (t5 + 72U);
    t12 = *((char **)t11);
    t14 = (t0 + 3528);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memset(t17, 0, 8);
    t18 = (t17 + 4);
    t19 = (t16 + 4);
    t6 = *((unsigned int *)t16);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t17) = t8;
    t9 = *((unsigned int *)t19);
    t10 = (t9 >> 0);
    t20 = (t10 & 1);
    *((unsigned int *)t18) = t20;
    xsi_vlog_generic_get_index_select_value(t13, 1, t4, t12, 2, t17, 1, 2);
    t21 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t21, t13, 0, 0, 1, 50000LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(3640, ng0);
    t11 = ((char*)((ng2)));
    t12 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    goto LAB8;

}

static void Always_3645_2(char *t0)
{
    char t18[8];
    char t24[8];
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
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;

LAB0:    t1 = (t0 + 4936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3645, ng0);
    t2 = (t0 + 5536);
    *((int *)t2) = 1;
    t3 = (t0 + 4968);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(3645, ng0);

LAB5:    xsi_set_current_line(3646, ng0);
    t4 = (t0 + 2328U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(3649, ng0);
    t2 = (t0 + 1368U);
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

LAB6:    xsi_set_current_line(3646, ng0);

LAB9:    xsi_set_current_line(3647, ng0);
    t11 = ((char*)((ng2)));
    t12 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    xsi_set_current_line(3648, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);
    goto LAB8;

LAB10:    xsi_set_current_line(3649, ng0);

LAB13:    xsi_set_current_line(3650, ng0);
    t4 = (t0 + 2008U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(3653, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t18, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB21;

LAB19:    if (*((unsigned int *)t2) == 0)
        goto LAB18;

LAB20:    t4 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t4) = 1;

LAB21:    t5 = (t18 + 4);
    t13 = *((unsigned int *)t5);
    t14 = (~(t13));
    t15 = *((unsigned int *)t18);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(3656, ng0);

LAB35:    xsi_set_current_line(3657, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 50000LL);
    xsi_set_current_line(3658, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);

LAB24:
LAB16:    goto LAB12;

LAB14:    xsi_set_current_line(3650, ng0);

LAB17:    xsi_set_current_line(3651, ng0);
    t11 = ((char*)((ng2)));
    t12 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 50000LL);
    xsi_set_current_line(3652, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 50000LL);
    goto LAB16;

LAB18:    *((unsigned int *)t18) = 1;
    goto LAB21;

LAB22:    xsi_set_current_line(3653, ng0);

LAB25:    xsi_set_current_line(3654, ng0);
    t11 = (t0 + 1048U);
    t12 = *((char **)t11);
    t11 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t11, t12, 0, 0, 1, 50000LL);
    xsi_set_current_line(3655, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1048U);
    t11 = *((char **)t5);
    memset(t18, 0, 8);
    t5 = (t11 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t11);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB29;

LAB27:    if (*((unsigned int *)t5) == 0)
        goto LAB26;

LAB28:    t12 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t12) = 1;

LAB29:    t19 = (t18 + 4);
    t20 = (t11 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    *((unsigned int *)t18) = t14;
    *((unsigned int *)t19) = 0;
    if (*((unsigned int *)t20) != 0)
        goto LAB31;

LAB30:    t22 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t22 & 1U);
    t23 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t23 & 1U);
    t25 = *((unsigned int *)t4);
    t26 = *((unsigned int *)t18);
    t27 = (t25 & t26);
    *((unsigned int *)t24) = t27;
    t28 = (t4 + 4);
    t29 = (t18 + 4);
    t30 = (t24 + 4);
    t31 = *((unsigned int *)t28);
    t32 = *((unsigned int *)t29);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t34 = *((unsigned int *)t30);
    t35 = (t34 != 0);
    if (t35 == 1)
        goto LAB32;

LAB33:
LAB34:    t56 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t56, t24, 0, 0, 1, 50000LL);
    goto LAB24;

LAB26:    *((unsigned int *)t18) = 1;
    goto LAB29;

LAB31:    t15 = *((unsigned int *)t18);
    t16 = *((unsigned int *)t20);
    *((unsigned int *)t18) = (t15 | t16);
    t17 = *((unsigned int *)t19);
    t21 = *((unsigned int *)t20);
    *((unsigned int *)t19) = (t17 | t21);
    goto LAB30;

LAB32:    t36 = *((unsigned int *)t24);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t24) = (t36 | t37);
    t38 = (t4 + 4);
    t39 = (t18 + 4);
    t40 = *((unsigned int *)t4);
    t41 = (~(t40));
    t42 = *((unsigned int *)t38);
    t43 = (~(t42));
    t44 = *((unsigned int *)t18);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t47 = (~(t46));
    t48 = (t41 & t43);
    t49 = (t45 & t47);
    t50 = (~(t48));
    t51 = (~(t49));
    t52 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t52 & t50);
    t53 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t53 & t51);
    t54 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t54 & t50);
    t55 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t55 & t51);
    goto LAB34;

}

static void Always_3664_3(char *t0)
{
    char t13[8];
    char t18[8];
    char t26[8];
    char t75[8];
    char t76[8];
    char t83[8];
    char t90[8];
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
    char *t17;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t91;
    char *t92;
    char *t93;

LAB0:    t1 = (t0 + 5184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3664, ng0);
    t2 = (t0 + 5552);
    *((int *)t2) = 1;
    t3 = (t0 + 5216);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(3664, ng0);

LAB5:    xsi_set_current_line(3665, ng0);
    t4 = (t0 + 2328U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(3668, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t2) != 0)
        goto LAB12;

LAB13:    t5 = (t13 + 4);
    t14 = *((unsigned int *)t13);
    t15 = *((unsigned int *)t5);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB14;

LAB15:    memcpy(t26, t13, 8);

LAB16:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB24;

LAB25:
LAB26:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(3665, ng0);

LAB9:    xsi_set_current_line(3666, ng0);
    t11 = ((char*)((ng2)));
    t12 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 50000LL);
    xsi_set_current_line(3667, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 50000LL);
    goto LAB8;

LAB10:    *((unsigned int *)t13) = 1;
    goto LAB13;

LAB12:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB13;

LAB14:    t11 = (t0 + 3208);
    t12 = (t11 + 56U);
    t17 = *((char **)t12);
    memset(t18, 0, 8);
    t19 = (t17 + 4);
    t20 = *((unsigned int *)t19);
    t21 = (~(t20));
    t22 = *((unsigned int *)t17);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t19) != 0)
        goto LAB19;

LAB20:    t27 = *((unsigned int *)t13);
    t28 = *((unsigned int *)t18);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t13 + 4);
    t31 = (t18 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t18) = 1;
    goto LAB20;

LAB19:    t25 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB20;

LAB21:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t13 + 4);
    t41 = (t18 + 4);
    t42 = *((unsigned int *)t13);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t18);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB23;

LAB24:    xsi_set_current_line(3668, ng0);

LAB27:    xsi_set_current_line(3669, ng0);
    t64 = (t0 + 1688U);
    t65 = *((char **)t64);
    t64 = (t65 + 4);
    t66 = *((unsigned int *)t64);
    t67 = (~(t66));
    t68 = *((unsigned int *)t65);
    t69 = (t68 & t67);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(3670, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2888);
    t11 = (t5 + 72U);
    t12 = *((char **)t11);
    t17 = (t0 + 3528);
    t19 = (t17 + 56U);
    t25 = *((char **)t19);
    memset(t18, 0, 8);
    t30 = (t18 + 4);
    t31 = (t25 + 4);
    t6 = *((unsigned int *)t25);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t18) = t8;
    t9 = *((unsigned int *)t31);
    t10 = (t9 >> 0);
    t14 = (t10 & 1);
    *((unsigned int *)t30) = t14;
    xsi_vlog_generic_get_index_select_value(t13, 32, t4, t12, 2, t18, 1, 2);
    t32 = ((char*)((ng2)));
    memset(t26, 0, 8);
    t40 = (t13 + 4);
    t41 = (t32 + 4);
    t15 = *((unsigned int *)t13);
    t16 = *((unsigned int *)t32);
    t20 = (t15 ^ t16);
    t21 = *((unsigned int *)t40);
    t22 = *((unsigned int *)t41);
    t23 = (t21 ^ t22);
    t24 = (t20 | t23);
    t27 = *((unsigned int *)t40);
    t28 = *((unsigned int *)t41);
    t29 = (t27 | t28);
    t33 = (~(t29));
    t34 = (t24 & t33);
    if (t34 != 0)
        goto LAB34;

LAB31:    if (t29 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t26) = 1;

LAB34:    t64 = (t26 + 4);
    t35 = *((unsigned int *)t64);
    t36 = (~(t35));
    t37 = *((unsigned int *)t26);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB35;

LAB36:
LAB37:
LAB30:    goto LAB26;

LAB28:    xsi_set_current_line(3669, ng0);
    t71 = ((char*)((ng1)));
    t72 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t72, t71, 0, 0, 3, 50000LL);
    goto LAB30;

LAB33:    t58 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB34;

LAB35:    xsi_set_current_line(3670, ng0);

LAB38:    xsi_set_current_line(3671, ng0);
    t65 = (t0 + 3048);
    t71 = (t65 + 56U);
    t72 = *((char **)t71);
    t73 = (t0 + 1528U);
    t74 = *((char **)t73);
    t73 = ((char*)((ng3)));
    memset(t75, 0, 8);
    xsi_vlog_unsigned_add(t75, 32, t74, 3, t73, 32);
    memset(t76, 0, 8);
    t77 = (t72 + 4);
    t78 = (t75 + 4);
    t42 = *((unsigned int *)t72);
    t43 = *((unsigned int *)t75);
    t44 = (t42 ^ t43);
    t45 = *((unsigned int *)t77);
    t46 = *((unsigned int *)t78);
    t47 = (t45 ^ t46);
    t48 = (t44 | t47);
    t49 = *((unsigned int *)t77);
    t52 = *((unsigned int *)t78);
    t53 = (t49 | t52);
    t54 = (~(t53));
    t55 = (t48 & t54);
    if (t55 != 0)
        goto LAB42;

LAB39:    if (t53 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t76) = 1;

LAB42:    t80 = (t76 + 4);
    t56 = *((unsigned int *)t80);
    t57 = (~(t56));
    t59 = *((unsigned int *)t76);
    t60 = (t59 & t57);
    t61 = (t60 != 0);
    if (t61 > 0)
        goto LAB43;

LAB44:    xsi_set_current_line(3674, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 32, t4, 3, t5, 32);
    t11 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 3, 50000LL);

LAB45:    goto LAB37;

LAB41:    t79 = (t76 + 4);
    *((unsigned int *)t76) = 1;
    *((unsigned int *)t79) = 1;
    goto LAB42;

LAB43:    xsi_set_current_line(3671, ng0);

LAB46:    xsi_set_current_line(3672, ng0);
    t81 = ((char*)((ng3)));
    t82 = (t0 + 2888);
    t84 = (t0 + 2888);
    t85 = (t84 + 72U);
    t86 = *((char **)t85);
    t87 = (t0 + 3528);
    t88 = (t87 + 56U);
    t89 = *((char **)t88);
    memset(t90, 0, 8);
    t91 = (t90 + 4);
    t92 = (t89 + 4);
    t62 = *((unsigned int *)t89);
    t63 = (t62 >> 0);
    t66 = (t63 & 1);
    *((unsigned int *)t90) = t66;
    t67 = *((unsigned int *)t92);
    t68 = (t67 >> 0);
    t69 = (t68 & 1);
    *((unsigned int *)t91) = t69;
    xsi_vlog_generic_convert_bit_index(t83, t86, 2, t90, 1, 2);
    t93 = (t83 + 4);
    t70 = *((unsigned int *)t93);
    t50 = (!(t70));
    if (t50 == 1)
        goto LAB47;

LAB48:    xsi_set_current_line(3673, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 50000LL);
    goto LAB45;

LAB47:    xsi_vlogvar_wait_assign_value(t82, t81, 0, *((unsigned int *)t83), 1, 50000LL);
    goto LAB48;

}


extern void secureip_m_04450330200070695222_2490050764_init()
{
	static char *pe[] = {(void *)Always_3633_0,(void *)Always_3639_1,(void *)Always_3645_2,(void *)Always_3664_3};
	xsi_register_didat("secureip_m_04450330200070695222_2490050764", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_04450330200070695222_2490050764.didat");
	xsi_register_executes(pe);
}
