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
static const char *ng0 = "/build/xfndry/isimco/hipsBuilds/P_hips_v16.0/rst/hips/oserdese2/B_OSERDESE2_enc.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 0U};



static void Cont_3207_0(char *t0)
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

LAB0:    t1 = (t0 + 3000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3207, ng0);
    t2 = (t0 + 2088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3928);
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
    t18 = (t0 + 3816);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_3208_1(char *t0)
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

LAB0:    t1 = (t0 + 3248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3208, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3992);
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
    t18 = (t0 + 3832);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_3210_2(char *t0)
{
    char t4[8];
    char t13[8];
    char t25[8];
    char t34[8];
    char t42[8];
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
    char *t12;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    int t66;
    int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;

LAB0:    t1 = (t0 + 3496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(3210, ng0);
    t2 = (t0 + 3848);
    *((int *)t2) = 1;
    t3 = (t0 + 3528);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(3211, ng0);

LAB5:    xsi_set_current_line(3212, ng0);
    t5 = (t0 + 1368U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    memset(t13, 0, 8);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t4);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t14) != 0)
        goto LAB12;

LAB13:    t21 = (t13 + 4);
    t22 = *((unsigned int *)t13);
    t23 = *((unsigned int *)t21);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB14;

LAB15:    memcpy(t42, t13, 8);

LAB16:    t74 = (t42 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t42);
    t78 = (t77 & t76);
    t79 = (t78 != 0);
    if (t79 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(3217, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB35;

LAB33:    if (*((unsigned int *)t2) == 0)
        goto LAB32;

LAB34:    t5 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t5) = 1;

LAB35:    memset(t13, 0, 8);
    t6 = (t4 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    t17 = *((unsigned int *)t4);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB36;

LAB37:    if (*((unsigned int *)t6) != 0)
        goto LAB38;

LAB39:    t14 = (t13 + 4);
    t22 = *((unsigned int *)t13);
    t23 = *((unsigned int *)t14);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB40;

LAB41:    memcpy(t34, t13, 8);

LAB42:    t47 = (t34 + 4);
    t69 = *((unsigned int *)t47);
    t70 = (~(t69));
    t71 = *((unsigned int *)t34);
    t72 = (t71 & t70);
    t73 = (t72 != 0);
    if (t73 > 0)
        goto LAB50;

LAB51:    xsi_set_current_line(3222, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t2) != 0)
        goto LAB56;

LAB57:    t6 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t6);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB58;

LAB59:    memcpy(t34, t4, 8);

LAB60:    t47 = (t34 + 4);
    t69 = *((unsigned int *)t47);
    t70 = (~(t69));
    t71 = *((unsigned int *)t34);
    t72 = (t71 & t70);
    t73 = (t72 != 0);
    if (t73 > 0)
        goto LAB72;

LAB73:    xsi_set_current_line(3227, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB76;

LAB77:    if (*((unsigned int *)t2) != 0)
        goto LAB78;

LAB79:    t6 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t6);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB80;

LAB81:    memcpy(t25, t4, 8);

LAB82:    t41 = (t25 + 4);
    t62 = *((unsigned int *)t41);
    t63 = (~(t62));
    t64 = *((unsigned int *)t25);
    t65 = (t64 & t63);
    t68 = (t65 != 0);
    if (t68 > 0)
        goto LAB90;

LAB91:    xsi_set_current_line(3233, ng0);

LAB94:    xsi_set_current_line(3234, ng0);
    t2 = (t0 + 2088);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(3235, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);

LAB92:
LAB74:
LAB52:
LAB30:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t13) = 1;
    goto LAB13;

LAB12:    t20 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 1528U);
    t27 = *((char **)t26);
    memset(t25, 0, 8);
    t26 = (t27 + 4);
    t28 = *((unsigned int *)t26);
    t29 = (~(t28));
    t30 = *((unsigned int *)t27);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB20;

LAB18:    if (*((unsigned int *)t26) == 0)
        goto LAB17;

LAB19:    t33 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t33) = 1;

LAB20:    memset(t34, 0, 8);
    t35 = (t25 + 4);
    t36 = *((unsigned int *)t35);
    t37 = (~(t36));
    t38 = *((unsigned int *)t25);
    t39 = (t38 & t37);
    t40 = (t39 & 1U);
    if (t40 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t35) != 0)
        goto LAB23;

LAB24:    t43 = *((unsigned int *)t13);
    t44 = *((unsigned int *)t34);
    t45 = (t43 & t44);
    *((unsigned int *)t42) = t45;
    t46 = (t13 + 4);
    t47 = (t34 + 4);
    t48 = (t42 + 4);
    t49 = *((unsigned int *)t46);
    t50 = *((unsigned int *)t47);
    t51 = (t49 | t50);
    *((unsigned int *)t48) = t51;
    t52 = *((unsigned int *)t48);
    t53 = (t52 != 0);
    if (t53 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB17:    *((unsigned int *)t25) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t34) = 1;
    goto LAB24;

LAB23:    t41 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB24;

LAB25:    t54 = *((unsigned int *)t42);
    t55 = *((unsigned int *)t48);
    *((unsigned int *)t42) = (t54 | t55);
    t56 = (t13 + 4);
    t57 = (t34 + 4);
    t58 = *((unsigned int *)t13);
    t59 = (~(t58));
    t60 = *((unsigned int *)t56);
    t61 = (~(t60));
    t62 = *((unsigned int *)t34);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (~(t64));
    t66 = (t59 & t61);
    t67 = (t63 & t65);
    t68 = (~(t66));
    t69 = (~(t67));
    t70 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t70 & t68);
    t71 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t71 & t69);
    t72 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t72 & t68);
    t73 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t73 & t69);
    goto LAB27;

LAB28:    xsi_set_current_line(3213, ng0);

LAB31:    xsi_set_current_line(3214, ng0);
    t80 = ((char*)((ng1)));
    t81 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t81, t80, 0, 0, 1, 0LL);
    xsi_set_current_line(3215, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB30;

LAB32:    *((unsigned int *)t4) = 1;
    goto LAB35;

LAB36:    *((unsigned int *)t13) = 1;
    goto LAB39;

LAB38:    t12 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB39;

LAB40:    t20 = (t0 + 1528U);
    t21 = *((char **)t20);
    memset(t25, 0, 8);
    t20 = (t21 + 4);
    t28 = *((unsigned int *)t20);
    t29 = (~(t28));
    t30 = *((unsigned int *)t21);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t20) != 0)
        goto LAB45;

LAB46:    t36 = *((unsigned int *)t13);
    t37 = *((unsigned int *)t25);
    t38 = (t36 & t37);
    *((unsigned int *)t34) = t38;
    t27 = (t13 + 4);
    t33 = (t25 + 4);
    t35 = (t34 + 4);
    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    t43 = (t39 | t40);
    *((unsigned int *)t35) = t43;
    t44 = *((unsigned int *)t35);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB47;

LAB48:
LAB49:    goto LAB42;

LAB43:    *((unsigned int *)t25) = 1;
    goto LAB46;

LAB45:    t26 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB46;

LAB47:    t49 = *((unsigned int *)t34);
    t50 = *((unsigned int *)t35);
    *((unsigned int *)t34) = (t49 | t50);
    t41 = (t13 + 4);
    t46 = (t25 + 4);
    t51 = *((unsigned int *)t13);
    t52 = (~(t51));
    t53 = *((unsigned int *)t41);
    t54 = (~(t53));
    t55 = *((unsigned int *)t25);
    t58 = (~(t55));
    t59 = *((unsigned int *)t46);
    t60 = (~(t59));
    t66 = (t52 & t54);
    t67 = (t58 & t60);
    t61 = (~(t66));
    t62 = (~(t67));
    t63 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t63 & t61);
    t64 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t64 & t62);
    t65 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t65 & t61);
    t68 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t68 & t62);
    goto LAB49;

LAB50:    xsi_set_current_line(3218, ng0);

LAB53:    xsi_set_current_line(3219, ng0);
    t48 = ((char*)((ng1)));
    t56 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t56, t48, 0, 0, 1, 0LL);
    xsi_set_current_line(3220, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB54:    *((unsigned int *)t4) = 1;
    goto LAB57;

LAB56:    t5 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB57;

LAB58:    t12 = (t0 + 1528U);
    t14 = *((char **)t12);
    memset(t13, 0, 8);
    t12 = (t14 + 4);
    t18 = *((unsigned int *)t12);
    t19 = (~(t18));
    t22 = *((unsigned int *)t14);
    t23 = (t22 & t19);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB64;

LAB62:    if (*((unsigned int *)t12) == 0)
        goto LAB61;

LAB63:    t20 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t20) = 1;

LAB64:    memset(t25, 0, 8);
    t21 = (t13 + 4);
    t28 = *((unsigned int *)t21);
    t29 = (~(t28));
    t30 = *((unsigned int *)t13);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB65;

LAB66:    if (*((unsigned int *)t21) != 0)
        goto LAB67;

LAB68:    t36 = *((unsigned int *)t4);
    t37 = *((unsigned int *)t25);
    t38 = (t36 & t37);
    *((unsigned int *)t34) = t38;
    t27 = (t4 + 4);
    t33 = (t25 + 4);
    t35 = (t34 + 4);
    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    t43 = (t39 | t40);
    *((unsigned int *)t35) = t43;
    t44 = *((unsigned int *)t35);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB69;

LAB70:
LAB71:    goto LAB60;

LAB61:    *((unsigned int *)t13) = 1;
    goto LAB64;

LAB65:    *((unsigned int *)t25) = 1;
    goto LAB68;

LAB67:    t26 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB68;

LAB69:    t49 = *((unsigned int *)t34);
    t50 = *((unsigned int *)t35);
    *((unsigned int *)t34) = (t49 | t50);
    t41 = (t4 + 4);
    t46 = (t25 + 4);
    t51 = *((unsigned int *)t4);
    t52 = (~(t51));
    t53 = *((unsigned int *)t41);
    t54 = (~(t53));
    t55 = *((unsigned int *)t25);
    t58 = (~(t55));
    t59 = *((unsigned int *)t46);
    t60 = (~(t59));
    t66 = (t52 & t54);
    t67 = (t58 & t60);
    t61 = (~(t66));
    t62 = (~(t67));
    t63 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t63 & t61);
    t64 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t64 & t62);
    t65 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t65 & t61);
    t68 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t68 & t62);
    goto LAB71;

LAB72:    xsi_set_current_line(3223, ng0);

LAB75:    xsi_set_current_line(3224, ng0);
    t48 = ((char*)((ng2)));
    t56 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t56, t48, 0, 0, 1, 0LL);
    xsi_set_current_line(3225, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB74;

LAB76:    *((unsigned int *)t4) = 1;
    goto LAB79;

LAB78:    t5 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB79;

LAB80:    t12 = (t0 + 1528U);
    t14 = *((char **)t12);
    memset(t13, 0, 8);
    t12 = (t14 + 4);
    t18 = *((unsigned int *)t12);
    t19 = (~(t18));
    t22 = *((unsigned int *)t14);
    t23 = (t22 & t19);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t12) != 0)
        goto LAB85;

LAB86:    t28 = *((unsigned int *)t4);
    t29 = *((unsigned int *)t13);
    t30 = (t28 & t29);
    *((unsigned int *)t25) = t30;
    t21 = (t4 + 4);
    t26 = (t13 + 4);
    t27 = (t25 + 4);
    t31 = *((unsigned int *)t21);
    t32 = *((unsigned int *)t26);
    t36 = (t31 | t32);
    *((unsigned int *)t27) = t36;
    t37 = *((unsigned int *)t27);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB87;

LAB88:
LAB89:    goto LAB82;

LAB83:    *((unsigned int *)t13) = 1;
    goto LAB86;

LAB85:    t20 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB86;

LAB87:    t39 = *((unsigned int *)t25);
    t40 = *((unsigned int *)t27);
    *((unsigned int *)t25) = (t39 | t40);
    t33 = (t4 + 4);
    t35 = (t13 + 4);
    t43 = *((unsigned int *)t4);
    t44 = (~(t43));
    t45 = *((unsigned int *)t33);
    t49 = (~(t45));
    t50 = *((unsigned int *)t13);
    t51 = (~(t50));
    t52 = *((unsigned int *)t35);
    t53 = (~(t52));
    t66 = (t44 & t49);
    t67 = (t51 & t53);
    t54 = (~(t66));
    t55 = (~(t67));
    t58 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t58 & t54);
    t59 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t59 & t55);
    t60 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t60 & t54);
    t61 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t61 & t55);
    goto LAB89;

LAB90:    xsi_set_current_line(3228, ng0);

LAB93:    xsi_set_current_line(3229, ng0);
    t46 = (t0 + 2088);
    t47 = (t46 + 56U);
    t48 = *((char **)t47);
    t56 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t56, t48, 0, 0, 1, 0LL);
    xsi_set_current_line(3230, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    goto LAB92;

}


extern void secureip_m_17599826399057085527_2816617683_init()
{
	static char *pe[] = {(void *)Cont_3207_0,(void *)Cont_3208_1,(void *)Always_3210_2};
	xsi_register_didat("secureip_m_17599826399057085527_2816617683", "isim/PicoTestbench_isim_beh.exe.sim/secureip/m_17599826399057085527_2816617683.didat");
	xsi_register_executes(pe);
}
