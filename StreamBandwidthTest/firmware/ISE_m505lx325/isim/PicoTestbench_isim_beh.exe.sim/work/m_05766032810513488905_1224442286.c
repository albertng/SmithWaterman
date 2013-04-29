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
static const char *ng0 = "/home/albertng/SmithWaterman/StreamBandwidthTest/firmware/ISE_m505lx325/source/PicoTestbench.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng3[] = {16U, 0U};
static unsigned int ng4[] = {16U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng5[] = {32U, 0U};
static unsigned int ng6[] = {4096U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng7[] = {1U, 0U};
static unsigned int ng8[] = {80U, 0U};
static unsigned int ng9[] = {160U, 0U};
static unsigned int ng10[] = {240U, 0U};
static unsigned int ng11[] = {48U, 0U};
static unsigned int ng12[] = {1U, 0U, 4114U, 0U, 3735928559U, 0U, 1111638594U, 0U};
static const char *ng13 = "All Tests Successful!";
static const char *ng14 = "Bad data!";



static void Initial_10_0(char *t0)
{
    char t32[32];
    char t33[32];
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

LAB0:    t1 = (t0 + 2040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(10, ng0);

LAB4:    xsi_set_current_line(11, ng0);
    t2 = (t0 + 1848);
    t3 = (t0 + 3944);
    t4 = *((char **)t3);
    t5 = (t0 + 3952);
    t6 = xsi_create_subprogram_invocation(t2, 0, *((char **)t5), ((char*)(t4)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t4)), t6);

LAB7:    t7 = (t0 + 1944);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = (t0 + 3952);
    t16 = ((int  (*)(char *, char *))t14)(*((char **)t15), t8);

LAB9:    if (t16 != 0)
        goto LAB10;

LAB5:    t8 = (t0 + 3984);
    t17 = *((char **)t8);
    xsi_vlog_subprogram_popinvocation(((char*)(t17)));

LAB6:    t18 = (t0 + 1944);
    t19 = *((char **)t18);
    t18 = (t0 + 3984);
    t20 = *((char **)t18);
    t21 = (t0 + 1848);
    t22 = 0;
    xsi_delete_subprogram_invocation(((char*)(t20)), t19, t0, t21, t22);
    xsi_set_current_line(13, ng0);
    t2 = ((char*)((ng1)));
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1848);
    t5 = (t0 + 4032);
    t6 = *((char **)t5);
    t7 = (t0 + 4056);
    t8 = xsi_create_subprogram_invocation(t4, 0, *((char **)t7), ((char*)(t6)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t6)), t8);
    t9 = (t0 + 4040);
    t10 = *((char **)t9);
    xsi_vlogvar_assign_value(((char*)(t10)), t2, 0, 0, 12);
    t11 = (t0 + 4048);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t3, 0, 0, 128);

LAB13:    t13 = (t0 + 1944);
    t14 = *((char **)t13);
    t15 = (t14 + 80U);
    t17 = *((char **)t15);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = (t0 + 4056);
    t16 = ((int  (*)(char *, char *))t21)(*((char **)t22), t14);

LAB15:    if (t16 != 0)
        goto LAB16;

LAB11:    t14 = (t0 + 4096);
    t23 = *((char **)t14);
    xsi_vlog_subprogram_popinvocation(((char*)(t23)));

LAB12:    t24 = (t0 + 1944);
    t25 = *((char **)t24);
    t24 = (t0 + 4096);
    t26 = *((char **)t24);
    t27 = (t0 + 1848);
    t28 = 0;
    xsi_delete_subprogram_invocation(((char*)(t26)), t25, t0, t27, t28);
    xsi_set_current_line(14, ng0);
    t2 = ((char*)((ng3)));
    t3 = ((char*)((ng4)));
    t4 = (t0 + 1848);
    t5 = (t0 + 4160);
    t6 = *((char **)t5);
    t7 = (t0 + 4184);
    t8 = xsi_create_subprogram_invocation(t4, 0, *((char **)t7), ((char*)(t6)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t6)), t8);
    t9 = (t0 + 4168);
    t10 = *((char **)t9);
    xsi_vlogvar_assign_value(((char*)(t10)), t2, 0, 0, 12);
    t11 = (t0 + 4176);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t3, 0, 0, 128);

LAB19:    t13 = (t0 + 1944);
    t14 = *((char **)t13);
    t15 = (t14 + 80U);
    t17 = *((char **)t15);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = (t0 + 4184);
    t16 = ((int  (*)(char *, char *))t21)(*((char **)t22), t14);

LAB21:    if (t16 != 0)
        goto LAB22;

LAB17:    t14 = (t0 + 4224);
    t23 = *((char **)t14);
    xsi_vlog_subprogram_popinvocation(((char*)(t23)));

LAB18:    t24 = (t0 + 1944);
    t25 = *((char **)t24);
    t24 = (t0 + 4224);
    t26 = *((char **)t24);
    t27 = (t0 + 1848);
    t28 = 0;
    xsi_delete_subprogram_invocation(((char*)(t26)), t25, t0, t27, t28);
    xsi_set_current_line(15, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng6)));
    t4 = (t0 + 1848);
    t5 = (t0 + 4288);
    t6 = *((char **)t5);
    t7 = (t0 + 4312);
    t8 = xsi_create_subprogram_invocation(t4, 0, *((char **)t7), ((char*)(t6)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t6)), t8);
    t9 = (t0 + 4296);
    t10 = *((char **)t9);
    xsi_vlogvar_assign_value(((char*)(t10)), t2, 0, 0, 12);
    t11 = (t0 + 4304);
    t12 = *((char **)t11);
    xsi_vlogvar_assign_value(((char*)(t12)), t3, 0, 0, 128);

LAB25:    t13 = (t0 + 1944);
    t14 = *((char **)t13);
    t15 = (t14 + 80U);
    t17 = *((char **)t15);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = (t0 + 4312);
    t16 = ((int  (*)(char *, char *))t21)(*((char **)t22), t14);

LAB27:    if (t16 != 0)
        goto LAB28;

LAB23:    t14 = (t0 + 4352);
    t23 = *((char **)t14);
    xsi_vlog_subprogram_popinvocation(((char*)(t23)));

LAB24:    t24 = (t0 + 1944);
    t25 = *((char **)t24);
    t24 = (t0 + 4352);
    t26 = *((char **)t24);
    t27 = (t0 + 1848);
    t28 = 0;
    xsi_delete_subprogram_invocation(((char*)(t26)), t25, t0, t27, t28);
    xsi_set_current_line(17, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng3)));
    t5 = (t0 + 1848);
    t6 = (t0 + 4408);
    t7 = *((char **)t6);
    t8 = (t0 + 4440);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 4416);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 4424);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 4432);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB31:    t17 = (t0 + 1944);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 4440);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB33:    if (t16 != 0)
        goto LAB34;

LAB29:    t18 = (t0 + 4472);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB30:    t27 = (t0 + 1944);
    t28 = *((char **)t27);
    t27 = (t0 + 4472);
    t29 = *((char **)t27);
    t30 = (t0 + 1848);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(18, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng3)));
    t5 = (t0 + 1848);
    t6 = (t0 + 4536);
    t7 = *((char **)t6);
    t8 = (t0 + 4568);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 4544);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 4552);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 4560);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB37:    t17 = (t0 + 1944);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 4568);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB39:    if (t16 != 0)
        goto LAB40;

LAB35:    t18 = (t0 + 4600);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB36:    t27 = (t0 + 1944);
    t28 = *((char **)t27);
    t27 = (t0 + 4600);
    t29 = *((char **)t27);
    t30 = (t0 + 1848);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(19, ng0);
    t2 = (t0 + 1848);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB41;

LAB1:    return;
LAB8:;
LAB10:    t7 = (t0 + 2040U);
    *((char **)t7) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t13 = (t0 + 2040U);
    *((char **)t13) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t13 = (t0 + 2040U);
    *((char **)t13) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t13 = (t0 + 2040U);
    *((char **)t13) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t17 = (t0 + 2040U);
    *((char **)t17) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t17 = (t0 + 2040U);
    *((char **)t17) = &&LAB37;
    goto LAB1;

LAB41:    xsi_set_current_line(20, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng3)));
    t4 = ((char*)((ng5)));
    t5 = (t0 + 1848);
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

LAB44:    t17 = (t0 + 1944);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 4696);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB46:    if (t16 != 0)
        goto LAB47;

LAB42:    t18 = (t0 + 4728);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB43:    t27 = (t0 + 1944);
    t28 = *((char **)t27);
    t27 = (t0 + 4728);
    t29 = *((char **)t27);
    t30 = (t0 + 1848);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(21, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng9)));
    t4 = ((char*)((ng3)));
    t5 = (t0 + 1848);
    t6 = (t0 + 4792);
    t7 = *((char **)t6);
    t8 = (t0 + 4824);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 4800);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 4808);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 4816);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB50:    t17 = (t0 + 1944);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 4824);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB52:    if (t16 != 0)
        goto LAB53;

LAB48:    t18 = (t0 + 4856);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB49:    t27 = (t0 + 1944);
    t28 = *((char **)t27);
    t27 = (t0 + 4856);
    t29 = *((char **)t27);
    t30 = (t0 + 1848);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(22, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng10)));
    t4 = ((char*)((ng3)));
    t5 = (t0 + 1848);
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

LAB56:    t17 = (t0 + 1944);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 4952);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB58:    if (t16 != 0)
        goto LAB59;

LAB54:    t18 = (t0 + 4984);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB55:    t27 = (t0 + 1944);
    t28 = *((char **)t27);
    t27 = (t0 + 4984);
    t29 = *((char **)t27);
    t30 = (t0 + 1848);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(23, ng0);
    t2 = (t0 + 1848);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB60;
    goto LAB1;

LAB45:;
LAB47:    t17 = (t0 + 2040U);
    *((char **)t17) = &&LAB44;
    goto LAB1;

LAB51:;
LAB53:    t17 = (t0 + 2040U);
    *((char **)t17) = &&LAB50;
    goto LAB1;

LAB57:;
LAB59:    t17 = (t0 + 2040U);
    *((char **)t17) = &&LAB56;
    goto LAB1;

LAB60:    xsi_set_current_line(25, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng1)));
    t4 = ((char*)((ng11)));
    t5 = (t0 + 1848);
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

LAB63:    t17 = (t0 + 1944);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 5080);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB65:    if (t16 != 0)
        goto LAB66;

LAB61:    t18 = (t0 + 5112);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB62:    t27 = (t0 + 1944);
    t28 = *((char **)t27);
    t27 = (t0 + 5112);
    t29 = *((char **)t27);
    t30 = (t0 + 1848);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(26, ng0);
    t2 = ((char*)((ng7)));
    t3 = ((char*)((ng8)));
    t4 = ((char*)((ng3)));
    t5 = (t0 + 1848);
    t6 = (t0 + 5176);
    t7 = *((char **)t6);
    t8 = (t0 + 5208);
    t9 = xsi_create_subprogram_invocation(t5, 0, *((char **)t8), ((char*)(t7)), 0, 0);
    xsi_vlog_subprogram_pushinvocation(((char*)(t7)), t9);
    t10 = (t0 + 5184);
    t11 = *((char **)t10);
    xsi_vlogvar_assign_value(((char*)(t11)), t2, 0, 0, 7);
    t12 = (t0 + 5192);
    t13 = *((char **)t12);
    xsi_vlogvar_assign_value(((char*)(t13)), t3, 0, 0, 12);
    t14 = (t0 + 5200);
    t15 = *((char **)t14);
    xsi_vlogvar_assign_value(((char*)(t15)), t4, 0, 0, 32);

LAB69:    t17 = (t0 + 1944);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = (t0 + 5208);
    t16 = ((int  (*)(char *, char *))t24)(*((char **)t25), t18);

LAB71:    if (t16 != 0)
        goto LAB72;

LAB67:    t18 = (t0 + 5240);
    t26 = *((char **)t18);
    xsi_vlog_subprogram_popinvocation(((char*)(t26)));

LAB68:    t27 = (t0 + 1944);
    t28 = *((char **)t27);
    t27 = (t0 + 5240);
    t29 = *((char **)t27);
    t30 = (t0 + 1848);
    t31 = 0;
    xsi_delete_subprogram_invocation(((char*)(t29)), t28, t0, t30, t31);
    xsi_set_current_line(28, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1848);
    t4 = (t0 + 5312);
    t5 = *((char **)t4);
    t6 = (t0 + 5328);
    t7 = xsi_create_subprogram_invocation(t3, 0, *((char **)t6), ((char*)(t5)), 0, 0);
    t8 = (t0 + 5320);
    t9 = *((char **)t8);
    xsi_vlogvar_assign_value(((char*)(t9)), t2, 0, 0, 12);

LAB73:    t10 = (t0 + 1944);
    t11 = *((char **)t10);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t17 = (t15 + 0U);
    t18 = *((char **)t17);
    t19 = (t0 + 5328);
    t16 = ((int  (*)(char *, char *))t18)(*((char **)t19), t11);
    if (t16 != 0)
        goto LAB75;

LAB74:    t11 = (t0 + 1944);
    t20 = *((char **)t11);
    t11 = (t0 + 5336);
    t21 = *((char **)t11);
    t22 = ((((char*)(t21))) + 56U);
    t23 = *((char **)t22);
    memcpy(t32, t23, 32);
    t24 = (t0 + 5312);
    t25 = *((char **)t24);
    t26 = (t0 + 1848);
    t27 = 0;
    xsi_delete_subprogram_invocation(((char*)(t25)), t20, t0, t26, t27);
    t28 = ((char*)((ng12)));
    xsi_vlog_unsigned_equal(t33, 128, t32, 128, t28, 128);
    t29 = (t33 + 4);
    t34 = *((unsigned int *)t29);
    t35 = (~(t34));
    t36 = *((unsigned int *)t33);
    t37 = (t36 & t35);
    t38 = (t37 != 0);
    if (t38 > 0)
        goto LAB76;

LAB77:    xsi_set_current_line(31, ng0);
    xsi_vlogfile_write(1, 0, 0, ng14, 1, t0);

LAB78:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 1848);
    xsi_process_wait(t2, 4000000LL);
    *((char **)t1) = &&LAB79;
    goto LAB1;

LAB64:;
LAB66:    t17 = (t0 + 2040U);
    *((char **)t17) = &&LAB63;
    goto LAB1;

LAB70:;
LAB72:    t17 = (t0 + 2040U);
    *((char **)t17) = &&LAB69;
    goto LAB1;

LAB75:    t10 = (t0 + 2040U);
    *((char **)t10) = &&LAB73;
    goto LAB1;

LAB76:    xsi_set_current_line(29, ng0);
    xsi_vlogfile_write(1, 0, 0, ng13, 1, t0);
    goto LAB78;

LAB79:    xsi_set_current_line(35, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_05766032810513488905_1224442286_init()
{
	static char *pe[] = {(void *)Initial_10_0};
	xsi_register_didat("work_m_05766032810513488905_1224442286", "isim/PicoTestbench_isim_beh.exe.sim/work/m_05766032810513488905_1224442286.didat");
	xsi_register_executes(pe);
}
