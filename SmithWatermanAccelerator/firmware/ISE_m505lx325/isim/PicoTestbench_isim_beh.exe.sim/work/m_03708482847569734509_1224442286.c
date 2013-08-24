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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/PicoTestbench.v";
static unsigned int ng1[] = {2309677060U, 0U, 2686495407U, 0U, 3263212072U, 0U, 3371879079U, 0U};
static const char *ng2 = "Streaming query seq to FPGA";
static int ng3[] = {0, 0};
static unsigned int ng4[] = {8U, 0U, 0U, 0U, 1U, 0U, 128U, 0U};
static int ng5[] = {1, 0};
static int ng6[] = {16, 0};
static const char *ng7 = "Streaming result from FPGA";
static const char *ng8 = "Query:%d Location:%d";
static const char *ng9 = "All Tests Successful!";



static void Initial_16_0(char *t0)
{
    char t32[32];
    char t33[8];
    char t40[8];
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
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;

LAB0:    t1 = (t0 + 2520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(16, ng0);

LAB4:    xsi_set_current_line(18, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(23, ng0);
    t2 = (t0 + 2328);
    t3 = (t0 + 4456);
    t4 = *((char **)t3);
    t5 = (t0 + 4464);
    t6 = xsi_create_subprogram_invocation(t2, 0, *((char **)t5), ((char*)(t4)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t4)), t6);

LAB7:    t7 = (t0 + 2424);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = (t0 + 4464);
    t16 = ((int  (*)(char *, char *))t14)(*((char **)t15), t8);

LAB9:    if (t16 != 0)
        goto LAB10;

LAB5:    t8 = (t0 + 4496);
    t17 = *((char **)t8);
    xsi_vlog_subprogram_popinvocation(((char*)(t17)));

LAB6:    t18 = (t0 + 2424);
    t19 = *((char **)t18);
    t18 = (t0 + 4496);
    t20 = *((char **)t18);
    t21 = (t0 + 2328);
    t22 = 0;
    xsi_delete_subprogram_invocation(((char*)(t20)), t19, t0, t21, t22);
    xsi_set_current_line(32, ng0);
    xsi_vlogfile_write(1, 0, 0, ng2, 1, t0);
    xsi_set_current_line(33, ng0);
    t2 = ((char*)((ng3)));
    t3 = ((char*)((ng4)));
    t4 = (t0 + 2328);
    t5 = (t0 + 4544);
    t6 = *((char **)t5);
    t7 = (t0 + 4568);
    t8 = xsi_create_subprogram_invocation(t4, 0, *((char **)t7), ((char*)(t6)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t6)), t8);
    t9 = (t0 + 4552);
    t10 = *((char **)t9);
    xsi_vlogvar_assign_value(((char*)(t10)), t2, 0, 0, 12);
    t11 = (t0 + 4560);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t3, 0, 0, 128);

LAB13:    t13 = (t0 + 2424);
    t14 = *((char **)t13);
    t15 = (t14 + 80U);
    t17 = *((char **)t15);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = (t0 + 4568);
    t16 = ((int  (*)(char *, char *))t21)(*((char **)t22), t14);

LAB15:    if (t16 != 0)
        goto LAB16;

LAB11:    t14 = (t0 + 4608);
    t23 = *((char **)t14);
    xsi_vlog_subprogram_popinvocation(((char*)(t23)));

LAB12:    t24 = (t0 + 2424);
    t25 = *((char **)t24);
    t24 = (t0 + 4608);
    t26 = *((char **)t24);
    t27 = (t0 + 2328);
    t28 = 0;
    xsi_delete_subprogram_invocation(((char*)(t26)), t25, t0, t27, t28);
    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng3)));
    t4 = ((char*)((ng6)));
    t5 = (t0 + 2328);
    t6 = (t0 + 4664);
    t7 = *((char **)t6);
    t8 = (t0 + 4696);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 4672);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 4680);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 4688);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB19:    t17 = (t0 + 2424);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 4696);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB21:    if (t16 != 0)
        goto LAB22;

LAB17:    t18 = (t0 + 4728);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB18:    t27 = (t0 + 2424);
    t28 = *((char **)t27);
    t27 = (t0 + 4728);
    t29 = *((char **)t27);
    t30 = (t0 + 2328);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(35, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1448);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2328);
    t7 = (t0 + 4800);
    t8 = *((char **)t7);
    t9 = (t0 + 4824);
    t10 = xsi_create_subprogram_invocation(t6, 0, *((char **)t9), ((char*)(t8)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t8)), t10);
    t11 = (t0 + 4808);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t2, 0, 0, 12);
    t13 = (t0 + 4816);
    t14 = *((char **)t13);
    xsi_vlogvar_assign_value(((char*)(t14)), t5, 0, 0, 128);

LAB25:    t15 = (t0 + 2424);
    t17 = *((char **)t15);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t24 = (t0 + 4824);
    t16 = ((int  (*)(char *, char *))t23)(*((char **)t24), t17);

LAB27:    if (t16 != 0)
        goto LAB28;

LAB23:    t17 = (t0 + 4864);
    t25 = *((char **)t17);
    xsi_vlog_subprogram_popinvocation(((char*)(t25)));

LAB24:    t26 = (t0 + 2424);
    t27 = *((char **)t26);
    t26 = (t0 + 4864);
    t28 = *((char **)t26);
    t29 = (t0 + 2328);
    t30 = 0;
    xsi_delete_subprogram_invocation(((char*)(t28)), t27, t0, t29, t30);
    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng3)));
    t4 = ((char*)((ng6)));
    t5 = (t0 + 2328);
    t6 = (t0 + 4920);
    t7 = *((char **)t6);
    t8 = (t0 + 4952);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 4928);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 4936);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 4944);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB31:    t17 = (t0 + 2424);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 4952);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB33:    if (t16 != 0)
        goto LAB34;

LAB29:    t18 = (t0 + 4984);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB30:    t27 = (t0 + 2424);
    t28 = *((char **)t27);
    t27 = (t0 + 4984);
    t29 = *((char **)t27);
    t30 = (t0 + 2328);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(39, ng0);
    xsi_vlogfile_write(1, 0, 0, ng7, 1, t0);
    xsi_set_current_line(40, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng3)));
    t4 = ((char*)((ng6)));
    t5 = (t0 + 2328);
    t6 = (t0 + 5048);
    t7 = *((char **)t6);
    t8 = (t0 + 5080);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 5056);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 5064);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 5072);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB37:    t17 = (t0 + 2424);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 5080);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB39:    if (t16 != 0)
        goto LAB40;

LAB35:    t18 = (t0 + 5112);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB36:    t27 = (t0 + 2424);
    t28 = *((char **)t27);
    t27 = (t0 + 5112);
    t29 = *((char **)t27);
    t30 = (t0 + 2328);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2328);
    t4 = (t0 + 5184);
    t5 = *((char **)t4);
    t6 = (t0 + 5200);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 5192);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB41:    t10 = (t0 + 2424);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 5200);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB43;

LAB42:    t11 = (t0 + 2424);
    t20 = *((char **)t11);
    t11 = (t0 + 5208);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t23 = *((char **)t22);
    memcpy(t32, t23, 32);
    t24 = (t0 + 5184);
    t25 = *((char **)t24);
    t26 = (t0 + 2328);
    t27 = 0;
    xsi_delete_subprogram_invocation(((char*)(t25)), t20, t0, t26, t27);
    t28 = (t0 + 1608);
    xsi_vlogvar_assign_value(t28, t32, 0, 0, 128);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 1608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t33, 0, 8);
    t5 = (t33 + 4);
    t6 = (t4 + 8);
    t7 = (t4 + 12);
    t34 = *((unsigned int *)t6);
    t35 = (t34 >> 0);
    *((unsigned int *)t33) = t35;
    t36 = *((unsigned int *)t7);
    t37 = (t36 >> 0);
    *((unsigned int *)t5) = t37;
    t38 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t38 & 65535U);
    t39 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t39 & 65535U);
    t8 = (t0 + 1608);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t40, 0, 8);
    t11 = (t40 + 4);
    t12 = (t10 + 4);
    t41 = *((unsigned int *)t10);
    t42 = (t41 >> 0);
    *((unsigned int *)t40) = t42;
    t43 = *((unsigned int *)t12);
    t44 = (t43 >> 0);
    *((unsigned int *)t11) = t44;
    t45 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t45 & 4294967295U);
    t46 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t46 & 4294967295U);
    xsi_vlogfile_write(1, 0, 0, ng8, 3, t0, (char)118, t33, 16, (char)118, t40, 32);
    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng3)));
    t4 = ((char*)((ng6)));
    t5 = (t0 + 2328);
    t6 = (t0 + 5240);
    t7 = *((char **)t6);
    t8 = (t0 + 5272);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 5248);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 5256);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 5264);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB46:    t17 = (t0 + 2424);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 5272);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB48:    if (t16 != 0)
        goto LAB49;

LAB44:    t18 = (t0 + 5304);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB45:    t27 = (t0 + 2424);
    t28 = *((char **)t27);
    t27 = (t0 + 5304);
    t29 = *((char **)t27);
    t30 = (t0 + 2328);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2328);
    t4 = (t0 + 5376);
    t5 = *((char **)t4);
    t6 = (t0 + 5392);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 5384);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB50:    t10 = (t0 + 2424);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 5392);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB52;

LAB51:    t11 = (t0 + 2424);
    t20 = *((char **)t11);
    t11 = (t0 + 5400);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t23 = *((char **)t22);
    memcpy(t32, t23, 32);
    t24 = (t0 + 5376);
    t25 = *((char **)t24);
    t26 = (t0 + 2328);
    t27 = 0;
    xsi_delete_subprogram_invocation(((char*)(t25)), t20, t0, t26, t27);
    t28 = (t0 + 1608);
    xsi_vlogvar_assign_value(t28, t32, 0, 0, 128);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t33, 0, 8);
    t5 = (t33 + 4);
    t6 = (t4 + 8);
    t7 = (t4 + 12);
    t34 = *((unsigned int *)t6);
    t35 = (t34 >> 0);
    *((unsigned int *)t33) = t35;
    t36 = *((unsigned int *)t7);
    t37 = (t36 >> 0);
    *((unsigned int *)t5) = t37;
    t38 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t38 & 65535U);
    t39 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t39 & 65535U);
    t8 = (t0 + 1608);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t40, 0, 8);
    t11 = (t40 + 4);
    t12 = (t10 + 4);
    t41 = *((unsigned int *)t10);
    t42 = (t41 >> 0);
    *((unsigned int *)t40) = t42;
    t43 = *((unsigned int *)t12);
    t44 = (t43 >> 0);
    *((unsigned int *)t11) = t44;
    t45 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t45 & 4294967295U);
    t46 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t46 & 4294967295U);
    xsi_vlogfile_write(1, 0, 0, ng8, 3, t0, (char)118, t33, 16, (char)118, t40, 32);
    xsi_set_current_line(50, ng0);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    xsi_set_current_line(51, ng0);
    xsi_vlog_stop(1);

LAB1:    return;
LAB8:;
LAB10:    t7 = (t0 + 2520U);
    *((char **)t7) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t13 = (t0 + 2520U);
    *((char **)t13) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t17 = (t0 + 2520U);
    *((char **)t17) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t15 = (t0 + 2520U);
    *((char **)t15) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t17 = (t0 + 2520U);
    *((char **)t17) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t17 = (t0 + 2520U);
    *((char **)t17) = &&LAB37;
    goto LAB1;

LAB43:    t10 = (t0 + 2520U);
    *((char **)t10) = &&LAB41;
    goto LAB1;

LAB47:;
LAB49:    t17 = (t0 + 2520U);
    *((char **)t17) = &&LAB46;
    goto LAB1;

LAB52:    t10 = (t0 + 2520U);
    *((char **)t10) = &&LAB50;
    goto LAB1;

}


extern void work_m_03708482847569734509_1224442286_init()
{
	static char *pe[] = {(void *)Initial_16_0};
	xsi_register_didat("work_m_03708482847569734509_1224442286", "isim/PicoTestbench_isim_beh.exe.sim/work/m_03708482847569734509_1224442286.didat");
	xsi_register_executes(pe);
}
