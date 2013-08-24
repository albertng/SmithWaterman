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
static const char *ng0 = "/home/albertng/Documents/SmithWaterman/samples/DDR3_MovingAverage/firmware/ISE_m505lx325/source/coregen-LX325T/mig_M505_DDR3/rtl/phy/mig_7series_v1_8_ddr_if_post_fifo.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 3U};
static unsigned int ng3[] = {4U, 0U};
static unsigned int ng4[] = {6U, 0U};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {8U, 0U};
static int ng7[] = {0, 0};
static int ng8[] = {1, 0};
static int ng9[] = {2, 0};
static int ng10[] = {3, 0};
static unsigned int ng11[] = {9U, 0U};
static unsigned int ng12[] = {12U, 0U};
static unsigned int ng13[] = {13U, 0U};
static unsigned int ng14[] = {14U, 0U};
static unsigned int ng15[] = {5U, 0U};
static unsigned int ng16[] = {10U, 0U};
static const char *ng17 = "ERR %m @%t: Bad access: rd:%b,wr:%b,empty:%b,full:%b";
static unsigned int ng18[] = {3U, 3U};
static unsigned int ng19[] = {15U, 0U};



static int sp_updt_ptrs(char *t1, char *t2)
{
    char t9[8];
    char t12[8];
    char t40[8];
    char t44[16];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    int t27;
    char *t28;
    int t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t41;
    int t42;
    int t43;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 1392);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(114, ng0);

LAB5:    xsi_set_current_line(115, ng0);
    t5 = (t1 + 4504);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t7, 2, t8, 32);
    t10 = (t1 + 608);
    t11 = *((char **)t10);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_mod(t12, 32, t9, 32, t11, 32);
    t10 = (t1 + 5144);
    xsi_vlogvar_assign_value(t10, t12, 0, 0, 2);
    xsi_set_current_line(116, ng0);
    t4 = (t1 + 4664);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t6, 2, t7, 32);
    t8 = (t1 + 608);
    t10 = *((char **)t8);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_mod(t12, 32, t9, 32, t10, 32);
    t8 = (t1 + 5304);
    xsi_vlogvar_assign_value(t8, t12, 0, 0, 2);
    xsi_set_current_line(117, ng0);
    t4 = (t1 + 4344);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4184);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    memset(t12, 0, 8);
    t11 = (t12 + 4);
    t13 = (t10 + 4);
    t14 = *((unsigned int *)t10);
    t15 = (t14 >> 1);
    t16 = (t15 & 1);
    *((unsigned int *)t12) = t16;
    t17 = *((unsigned int *)t13);
    t18 = (t17 >> 1);
    t19 = (t18 & 1);
    *((unsigned int *)t11) = t19;
    t20 = (t1 + 4984);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t23 = (t1 + 4824);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    xsi_vlogtype_concat(t9, 4, 4, 4U, t25, 1, t22, 1, t12, 1, t6, 1);

LAB6:    t26 = ((char*)((ng2)));
    t27 = xsi_vlog_unsigned_case_zcompare(t9, 4, t26, 4);
    if (t27 == 1)
        goto LAB7;

LAB8:    t28 = ((char*)((ng3)));
    t29 = xsi_vlog_unsigned_case_zcompare(t9, 4, t28, 4);
    if (t29 == 1)
        goto LAB9;

LAB10:    t4 = ((char*)((ng4)));
    t27 = xsi_vlog_unsigned_case_zcompare(t9, 4, t4, 4);
    if (t27 == 1)
        goto LAB11;

LAB12:    t4 = ((char*)((ng6)));
    t27 = xsi_vlog_unsigned_case_zcompare(t9, 4, t4, 4);
    if (t27 == 1)
        goto LAB13;

LAB14:    t4 = ((char*)((ng11)));
    t27 = xsi_vlog_unsigned_case_zcompare(t9, 4, t4, 4);
    if (t27 == 1)
        goto LAB15;

LAB16:    t4 = ((char*)((ng12)));
    t27 = xsi_vlog_unsigned_case_zcompare(t9, 4, t4, 4);
    if (t27 == 1)
        goto LAB17;

LAB18:    t4 = ((char*)((ng13)));
    t27 = xsi_vlog_unsigned_case_zcompare(t9, 4, t4, 4);
    if (t27 == 1)
        goto LAB19;

LAB20:    t5 = ((char*)((ng14)));
    t29 = xsi_vlog_unsigned_case_zcompare(t9, 4, t5, 4);
    if (t29 == 1)
        goto LAB21;

LAB22:    t6 = ((char*)((ng15)));
    t42 = xsi_vlog_unsigned_case_zcompare(t9, 4, t6, 4);
    if (t42 == 1)
        goto LAB23;

LAB24:    t7 = ((char*)((ng16)));
    t43 = xsi_vlog_unsigned_case_zcompare(t9, 4, t7, 4);
    if (t43 == 1)
        goto LAB25;

LAB26:
LAB28:
LAB27:    xsi_set_current_line(159, ng0);

LAB63:    xsi_set_current_line(162, ng0);
    t8 = xsi_vlog_time(t44, 1000.0000000000000, 1.0000000000000000);
    t10 = (t1 + 4824);
    t11 = (t10 + 56U);
    t13 = *((char **)t11);
    t20 = (t1 + 4984);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t23 = (t1 + 4184);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t1 + 4344);
    t28 = (t26 + 56U);
    t30 = *((char **)t28);
    t31 = (t1 + 1392);
    xsi_vlogfile_write(1, 0, 0, ng17, 6, t31, (char)118, t44, 64, (char)118, t13, 1, (char)118, t22, 1, (char)118, t25, 4, (char)118, t30, 1);
    xsi_set_current_line(164, ng0);
    t4 = ((char*)((ng18)));
    t5 = (t1 + 4504);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 25000LL);
    xsi_set_current_line(165, ng0);
    t4 = ((char*)((ng18)));
    t5 = (t1 + 4664);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 25000LL);

LAB29:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB7:    goto LAB29;

LAB9:    xsi_set_current_line(119, ng0);

LAB30:    xsi_set_current_line(121, ng0);
    t30 = (t1 + 5304);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t1 + 4664);
    xsi_vlogvar_wait_assign_value(t33, t32, 0, 0, 2, 25000LL);
    xsi_set_current_line(122, ng0);
    t4 = (t1 + 5304);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4504);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    memset(t12, 0, 8);
    t11 = (t6 + 4);
    t13 = (t10 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t13);
    t19 = (t17 ^ t18);
    t34 = (t16 | t19);
    t35 = *((unsigned int *)t11);
    t36 = *((unsigned int *)t13);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB34;

LAB31:    if (t37 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t12) = 1;

LAB34:    t21 = (t1 + 4344);
    xsi_vlogvar_wait_assign_value(t21, t12, 0, 0, 1, 25000LL);
    goto LAB29;

LAB11:    xsi_set_current_line(125, ng0);

LAB35:    xsi_set_current_line(127, ng0);
    t5 = (t1 + 5304);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 4664);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 2, 25000LL);
    xsi_set_current_line(128, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t1 + 4184);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 25000LL);
    goto LAB29;

LAB13:    xsi_set_current_line(131, ng0);

LAB36:    xsi_set_current_line(133, ng0);
    t5 = (t1 + 5144);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 4504);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 2, 25000LL);
    xsi_set_current_line(134, ng0);
    t4 = (t1 + 5144);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4664);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    memset(t12, 0, 8);
    t11 = (t6 + 4);
    t13 = (t10 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t13);
    t19 = (t17 ^ t18);
    t34 = (t16 | t19);
    t35 = *((unsigned int *)t11);
    t36 = *((unsigned int *)t13);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB40;

LAB37:    if (t37 != 0)
        goto LAB39;

LAB38:    *((unsigned int *)t12) = 1;

LAB40:    t21 = (t1 + 4184);
    t22 = (t1 + 4184);
    t23 = (t22 + 72U);
    t24 = *((char **)t23);
    t25 = ((char*)((ng7)));
    xsi_vlog_generic_convert_bit_index(t40, t24, 2, t25, 32, 1);
    t26 = (t40 + 4);
    t41 = *((unsigned int *)t26);
    t27 = (!(t41));
    if (t27 == 1)
        goto LAB41;

LAB42:    xsi_set_current_line(135, ng0);
    t4 = (t1 + 5144);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4664);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    memset(t12, 0, 8);
    t11 = (t6 + 4);
    t13 = (t10 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t13);
    t19 = (t17 ^ t18);
    t34 = (t16 | t19);
    t35 = *((unsigned int *)t11);
    t36 = *((unsigned int *)t13);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB46;

LAB43:    if (t37 != 0)
        goto LAB45;

LAB44:    *((unsigned int *)t12) = 1;

LAB46:    t21 = (t1 + 4184);
    t22 = (t1 + 4184);
    t23 = (t22 + 72U);
    t24 = *((char **)t23);
    t25 = ((char*)((ng8)));
    xsi_vlog_generic_convert_bit_index(t40, t24, 2, t25, 32, 1);
    t26 = (t40 + 4);
    t41 = *((unsigned int *)t26);
    t27 = (!(t41));
    if (t27 == 1)
        goto LAB47;

LAB48:    xsi_set_current_line(136, ng0);
    t4 = (t1 + 5144);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4664);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    memset(t12, 0, 8);
    t11 = (t6 + 4);
    t13 = (t10 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t13);
    t19 = (t17 ^ t18);
    t34 = (t16 | t19);
    t35 = *((unsigned int *)t11);
    t36 = *((unsigned int *)t13);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB52;

LAB49:    if (t37 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t12) = 1;

LAB52:    t21 = (t1 + 4184);
    t22 = (t1 + 4184);
    t23 = (t22 + 72U);
    t24 = *((char **)t23);
    t25 = ((char*)((ng9)));
    xsi_vlog_generic_convert_bit_index(t40, t24, 2, t25, 32, 1);
    t26 = (t40 + 4);
    t41 = *((unsigned int *)t26);
    t27 = (!(t41));
    if (t27 == 1)
        goto LAB53;

LAB54:    xsi_set_current_line(137, ng0);
    t4 = (t1 + 5144);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4664);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    memset(t12, 0, 8);
    t11 = (t6 + 4);
    t13 = (t10 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t13);
    t19 = (t17 ^ t18);
    t34 = (t16 | t19);
    t35 = *((unsigned int *)t11);
    t36 = *((unsigned int *)t13);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB58;

LAB55:    if (t37 != 0)
        goto LAB57;

LAB56:    *((unsigned int *)t12) = 1;

LAB58:    t21 = (t1 + 4184);
    t22 = (t1 + 4184);
    t23 = (t22 + 72U);
    t24 = *((char **)t23);
    t25 = ((char*)((ng10)));
    xsi_vlog_generic_convert_bit_index(t40, t24, 2, t25, 32, 1);
    t26 = (t40 + 4);
    t41 = *((unsigned int *)t26);
    t27 = (!(t41));
    if (t27 == 1)
        goto LAB59;

LAB60:    goto LAB29;

LAB15:    xsi_set_current_line(139, ng0);

LAB61:    xsi_set_current_line(141, ng0);
    t5 = (t1 + 5144);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 4504);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 2, 25000LL);
    xsi_set_current_line(142, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t1 + 4344);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 25000LL);
    goto LAB29;

LAB17:    xsi_set_current_line(144, ng0);

LAB62:    xsi_set_current_line(147, ng0);
    t5 = (t1 + 5144);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 4504);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 2, 25000LL);
    xsi_set_current_line(148, ng0);
    t4 = (t1 + 5304);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4664);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 2, 25000LL);
    goto LAB29;

LAB19:    goto LAB17;

LAB21:    goto LAB17;

LAB23:    goto LAB29;

LAB25:    goto LAB23;

LAB33:    t20 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB34;

LAB39:    t20 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB40;

LAB41:    xsi_vlogvar_wait_assign_value(t21, t12, 0, *((unsigned int *)t40), 1, 25000LL);
    goto LAB42;

LAB45:    t20 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB46;

LAB47:    xsi_vlogvar_wait_assign_value(t21, t12, 0, *((unsigned int *)t40), 1, 25000LL);
    goto LAB48;

LAB51:    t20 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB52;

LAB53:    xsi_vlogvar_wait_assign_value(t21, t12, 0, *((unsigned int *)t40), 1, 25000LL);
    goto LAB54;

LAB57:    t20 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB58;

LAB59:    xsi_vlogvar_wait_assign_value(t21, t12, 0, *((unsigned int *)t40), 1, 25000LL);
    goto LAB60;

}

static void Cont_174_0(char *t0)
{
    char t3[24];
    char t4[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
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
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;

LAB0:    t1 = (t0 + 6216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 4184);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t7, 0, 8);
    t8 = (t7 + 4);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t9);
    t14 = (t13 >> 2);
    t15 = (t14 & 1);
    *((unsigned int *)t8) = t15;
    memset(t4, 0, 8);
    t16 = (t7 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t16) != 0)
        goto LAB6;

LAB7:    t23 = (t4 + 4);
    t24 = *((unsigned int *)t4);
    t25 = *((unsigned int *)t23);
    t26 = (t24 || t25);
    if (t26 > 0)
        goto LAB8;

LAB9:    t29 = *((unsigned int *)t4);
    t30 = (~(t29));
    t31 = *((unsigned int *)t23);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t33, 24);

LAB16:    t27 = (t0 + 8200);
    t34 = (t27 + 56U);
    t35 = *((char **)t34);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    xsi_vlog_bit_copy(t37, 0, t3, 0, 80);
    xsi_driver_vfirst_trans(t27, 0, 79);
    t38 = (t0 + 8024);
    *((int *)t38) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t22 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB7;

LAB8:    t27 = (t0 + 2664U);
    t28 = *((char **)t27);
    goto LAB9;

LAB10:    t27 = (t0 + 3304U);
    t33 = *((char **)t27);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 80, t28, 80, t33, 80);
    goto LAB16;

LAB14:    memcpy(t3, t28, 24);
    goto LAB16;

}

static void Cont_176_1(char *t0)
{
    char t4[8];
    char t15[8];
    char t24[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
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
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;

LAB0:    t1 = (t0 + 6464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 4184);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t15, 0, 8);
    t16 = (t15 + 4);
    t17 = (t14 + 4);
    t18 = *((unsigned int *)t14);
    t19 = (t18 >> 0);
    t20 = (t19 & 1);
    *((unsigned int *)t15) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t16) = t23;
    t25 = *((unsigned int *)t4);
    t26 = *((unsigned int *)t15);
    t27 = (t25 & t26);
    *((unsigned int *)t24) = t27;
    t28 = (t4 + 4);
    t29 = (t15 + 4);
    t30 = (t24 + 4);
    t31 = *((unsigned int *)t28);
    t32 = *((unsigned int *)t29);
    t33 = (t31 | t32);
    *((unsigned int *)t30) = t33;
    t34 = *((unsigned int *)t30);
    t35 = (t34 != 0);
    if (t35 == 1)
        goto LAB4;

LAB5:
LAB6:    t56 = (t0 + 8264);
    t57 = (t56 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memset(t60, 0, 8);
    t61 = 1U;
    t62 = t61;
    t63 = (t24 + 4);
    t64 = *((unsigned int *)t24);
    t61 = (t61 & t64);
    t65 = *((unsigned int *)t63);
    t62 = (t62 & t65);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t67 | t61);
    t68 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t68 | t62);
    xsi_driver_vfirst_trans(t56, 0, 0);
    t69 = (t0 + 8040);
    *((int *)t69) = 1;

LAB1:    return;
LAB4:    t36 = *((unsigned int *)t24);
    t37 = *((unsigned int *)t30);
    *((unsigned int *)t24) = (t36 | t37);
    t38 = (t4 + 4);
    t39 = (t15 + 4);
    t40 = *((unsigned int *)t4);
    t41 = (~(t40));
    t42 = *((unsigned int *)t38);
    t43 = (~(t42));
    t44 = *((unsigned int *)t15);
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
    goto LAB6;

}

static void Cont_177_2(char *t0)
{
    char t3[8];
    char t5[8];
    char t20[8];
    char t33[8];
    char t37[8];
    char t53[8];
    char t61[8];
    char *t1;
    char *t2;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
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
    char *t34;
    char *t35;
    char *t36;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    char *t102;

LAB0:    t1 = (t0 + 6712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(177, ng0);
    t2 = (t0 + 2344U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t5 + 4);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 3);
    t9 = (t8 & 1);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 3);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    memset(t3, 0, 8);
    t13 = (t5 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t5);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t13) == 0)
        goto LAB4;

LAB6:    t19 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t19) = 1;

LAB7:    memset(t20, 0, 8);
    t21 = (t3 + 4);
    t22 = *((unsigned int *)t21);
    t23 = (~(t22));
    t24 = *((unsigned int *)t3);
    t25 = (t24 & t23);
    t26 = (t25 & 1U);
    if (t26 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t21) != 0)
        goto LAB10;

LAB11:    t28 = (t20 + 4);
    t29 = *((unsigned int *)t20);
    t30 = (!(t29));
    t31 = *((unsigned int *)t28);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB12;

LAB13:    memcpy(t61, t20, 8);

LAB14:    t89 = (t0 + 8328);
    t90 = (t89 + 56U);
    t91 = *((char **)t90);
    t92 = (t91 + 56U);
    t93 = *((char **)t92);
    memset(t93, 0, 8);
    t94 = 1U;
    t95 = t94;
    t96 = (t61 + 4);
    t97 = *((unsigned int *)t61);
    t94 = (t94 & t97);
    t98 = *((unsigned int *)t96);
    t95 = (t95 & t98);
    t99 = (t93 + 4);
    t100 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t100 | t94);
    t101 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t101 | t95);
    xsi_driver_vfirst_trans(t89, 0, 0);
    t102 = (t0 + 8056);
    *((int *)t102) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t20) = 1;
    goto LAB11;

LAB10:    t27 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB11;

LAB12:    t34 = (t0 + 4184);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    memset(t37, 0, 8);
    t38 = (t37 + 4);
    t39 = (t36 + 4);
    t40 = *((unsigned int *)t36);
    t41 = (t40 >> 3);
    t42 = (t41 & 1);
    *((unsigned int *)t37) = t42;
    t43 = *((unsigned int *)t39);
    t44 = (t43 >> 3);
    t45 = (t44 & 1);
    *((unsigned int *)t38) = t45;
    memset(t33, 0, 8);
    t46 = (t37 + 4);
    t47 = *((unsigned int *)t46);
    t48 = (~(t47));
    t49 = *((unsigned int *)t37);
    t50 = (t49 & t48);
    t51 = (t50 & 1U);
    if (t51 != 0)
        goto LAB18;

LAB16:    if (*((unsigned int *)t46) == 0)
        goto LAB15;

LAB17:    t52 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t52) = 1;

LAB18:    memset(t53, 0, 8);
    t54 = (t33 + 4);
    t55 = *((unsigned int *)t54);
    t56 = (~(t55));
    t57 = *((unsigned int *)t33);
    t58 = (t57 & t56);
    t59 = (t58 & 1U);
    if (t59 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t54) != 0)
        goto LAB21;

LAB22:    t62 = *((unsigned int *)t20);
    t63 = *((unsigned int *)t53);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = (t20 + 4);
    t66 = (t53 + 4);
    t67 = (t61 + 4);
    t68 = *((unsigned int *)t65);
    t69 = *((unsigned int *)t66);
    t70 = (t68 | t69);
    *((unsigned int *)t67) = t70;
    t71 = *((unsigned int *)t67);
    t72 = (t71 != 0);
    if (t72 == 1)
        goto LAB23;

LAB24:
LAB25:    goto LAB14;

LAB15:    *((unsigned int *)t33) = 1;
    goto LAB18;

LAB19:    *((unsigned int *)t53) = 1;
    goto LAB22;

LAB21:    t60 = (t53 + 4);
    *((unsigned int *)t53) = 1;
    *((unsigned int *)t60) = 1;
    goto LAB22;

LAB23:    t73 = *((unsigned int *)t61);
    t74 = *((unsigned int *)t67);
    *((unsigned int *)t61) = (t73 | t74);
    t75 = (t20 + 4);
    t76 = (t53 + 4);
    t77 = *((unsigned int *)t75);
    t78 = (~(t77));
    t79 = *((unsigned int *)t20);
    t80 = (t79 & t78);
    t81 = *((unsigned int *)t76);
    t82 = (~(t81));
    t83 = *((unsigned int *)t53);
    t84 = (t83 & t82);
    t85 = (~(t80));
    t86 = (~(t84));
    t87 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t87 & t85);
    t88 = *((unsigned int *)t67);
    *((unsigned int *)t67) = (t88 & t86);
    goto LAB25;

}

static void Always_179_3(char *t0)
{
    char t13[8];
    char t15[8];
    char t26[8];
    char t37[8];
    char t45[8];
    char t77[8];
    char t91[8];
    char t98[8];
    char t130[8];
    char t142[8];
    char t145[8];
    char t160[8];
    char t168[8];
    char t208[8];
    char t210[8];
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
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    int t69;
    int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    char *t102;
    char *t103;
    char *t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    int t122;
    int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    char *t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    char *t137;
    char *t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    char *t143;
    char *t144;
    char *t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    char *t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    char *t159;
    char *t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t167;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    char *t172;
    char *t173;
    char *t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    char *t182;
    char *t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    int t192;
    int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    unsigned int t199;
    char *t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    char *t206;
    char *t207;
    char *t209;
    char *t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    char *t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    char *t224;
    char *t225;
    char *t226;
    char *t227;
    char *t228;
    char *t229;
    char *t230;
    char *t231;
    char *t232;
    char *t233;
    char *t234;
    char *t235;
    char *t236;
    char *t237;
    int t238;
    char *t239;
    char *t240;
    char *t241;
    char *t242;

LAB0:    t1 = (t0 + 6960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(179, ng0);
    t2 = (t0 + 8072);
    *((int *)t2) = 1;
    t3 = (t0 + 6992);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(180, ng0);
    t4 = (t0 + 2184U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB5;

LAB6:    xsi_set_current_line(185, ng0);

LAB9:    xsi_set_current_line(190, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t13, 0, 8);
    t5 = (t13 + 4);
    t11 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 1);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t11);
    t10 = (t9 >> 1);
    t14 = (t10 & 1);
    *((unsigned int *)t5) = t14;
    memset(t15, 0, 8);
    t12 = (t13 + 4);
    t16 = *((unsigned int *)t12);
    t17 = (~(t16));
    t18 = *((unsigned int *)t13);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) != 0)
        goto LAB12;

LAB13:    t22 = (t15 + 4);
    t23 = *((unsigned int *)t15);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t45, t15, 8);

LAB16:    memset(t77, 0, 8);
    t78 = (t45 + 4);
    t79 = *((unsigned int *)t78);
    t80 = (~(t79));
    t81 = *((unsigned int *)t45);
    t82 = (t81 & t80);
    t83 = (t82 & 1U);
    if (t83 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t78) != 0)
        goto LAB30;

LAB31:    t85 = (t77 + 4);
    t86 = *((unsigned int *)t77);
    t87 = *((unsigned int *)t85);
    t88 = (t86 || t87);
    if (t88 > 0)
        goto LAB32;

LAB33:    memcpy(t98, t77, 8);

LAB34:    memset(t130, 0, 8);
    t131 = (t98 + 4);
    t132 = *((unsigned int *)t131);
    t133 = (~(t132));
    t134 = *((unsigned int *)t98);
    t135 = (t134 & t133);
    t136 = (t135 & 1U);
    if (t136 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t131) != 0)
        goto LAB44;

LAB45:    t138 = (t130 + 4);
    t139 = *((unsigned int *)t130);
    t140 = *((unsigned int *)t138);
    t141 = (t139 || t140);
    if (t141 > 0)
        goto LAB46;

LAB47:    memcpy(t168, t130, 8);

LAB48:    t200 = (t168 + 4);
    t201 = *((unsigned int *)t200);
    t202 = (~(t201));
    t203 = *((unsigned int *)t168);
    t204 = (t203 & t202);
    t205 = (t204 != 0);
    if (t205 > 0)
        goto LAB60;

LAB61:    xsi_set_current_line(196, ng0);
    t206 = (t0 + 2504U);
    t207 = *((char **)t206);
    t206 = (t0 + 2344U);
    t209 = *((char **)t206);
    memset(t210, 0, 8);
    t206 = (t210 + 4);
    t211 = (t209 + 4);
    t212 = *((unsigned int *)t209);
    t213 = (t212 >> 1);
    t214 = (t213 & 1);
    *((unsigned int *)t210) = t214;
    t215 = *((unsigned int *)t211);
    t216 = (t215 >> 1);
    t217 = (t216 & 1);
    *((unsigned int *)t206) = t217;
    memset(t208, 0, 8);
    t218 = (t210 + 4);
    t219 = *((unsigned int *)t218);
    t220 = (~(t219));
    t221 = *((unsigned int *)t210);
    t222 = (t221 & t220);
    t223 = (t222 & 1U);
    if (t223 != 0)
        goto LAB66;

LAB64:    if (*((unsigned int *)t218) == 0)
        goto LAB63;

LAB65:    t224 = (t208 + 4);
    *((unsigned int *)t208) = 1;
    *((unsigned int *)t224) = 1;

LAB66:    t225 = (t0 + 6768);
    t226 = (t0 + 1392);
    t227 = xsi_create_subprogram_invocation(t225, 0, t0, t226, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t226, t227);
    t228 = (t0 + 4824);
    xsi_vlogvar_assign_value(t228, t207, 0, 0, 1);
    t229 = (t0 + 4984);
    xsi_vlogvar_assign_value(t229, t208, 0, 0, 1);

LAB69:    t230 = (t0 + 6864);
    t231 = *((char **)t230);
    t232 = (t231 + 80U);
    t233 = *((char **)t232);
    t234 = (t233 + 272U);
    t235 = *((char **)t234);
    t236 = (t235 + 0U);
    t237 = *((char **)t236);
    t238 = ((int  (*)(char *, char *))t237)(t0, t231);

LAB71:    if (t238 != 0)
        goto LAB72;

LAB67:    t231 = (t0 + 1392);
    xsi_vlog_subprogram_popinvocation(t231);

LAB68:    t239 = (t0 + 6864);
    t240 = *((char **)t239);
    t239 = (t0 + 1392);
    t241 = (t0 + 6768);
    t242 = 0;
    xsi_delete_subprogram_invocation(t239, t240, t0, t241, t242);

LAB62:
LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(180, ng0);

LAB8:    xsi_set_current_line(181, ng0);
    t11 = ((char*)((ng19)));
    t12 = (t0 + 4184);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 4, 25000LL);
    xsi_set_current_line(182, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4344);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 25000LL);
    xsi_set_current_line(183, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4504);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 25000LL);
    xsi_set_current_line(184, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4664);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 25000LL);
    goto LAB7;

LAB10:    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB12:    t21 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB13;

LAB14:    t27 = (t0 + 4344);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memset(t26, 0, 8);
    t30 = (t29 + 4);
    t31 = *((unsigned int *)t30);
    t32 = (~(t31));
    t33 = *((unsigned int *)t29);
    t34 = (t33 & t32);
    t35 = (t34 & 1U);
    if (t35 != 0)
        goto LAB20;

LAB18:    if (*((unsigned int *)t30) == 0)
        goto LAB17;

LAB19:    t36 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t36) = 1;

LAB20:    memset(t37, 0, 8);
    t38 = (t26 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t26);
    t42 = (t41 & t40);
    t43 = (t42 & 1U);
    if (t43 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t38) != 0)
        goto LAB23;

LAB24:    t46 = *((unsigned int *)t15);
    t47 = *((unsigned int *)t37);
    t48 = (t46 & t47);
    *((unsigned int *)t45) = t48;
    t49 = (t15 + 4);
    t50 = (t37 + 4);
    t51 = (t45 + 4);
    t52 = *((unsigned int *)t49);
    t53 = *((unsigned int *)t50);
    t54 = (t52 | t53);
    *((unsigned int *)t51) = t54;
    t55 = *((unsigned int *)t51);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB17:    *((unsigned int *)t26) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t37) = 1;
    goto LAB24;

LAB23:    t44 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB24;

LAB25:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t45) = (t57 | t58);
    t59 = (t15 + 4);
    t60 = (t37 + 4);
    t61 = *((unsigned int *)t15);
    t62 = (~(t61));
    t63 = *((unsigned int *)t59);
    t64 = (~(t63));
    t65 = *((unsigned int *)t37);
    t66 = (~(t65));
    t67 = *((unsigned int *)t60);
    t68 = (~(t67));
    t69 = (t62 & t64);
    t70 = (t66 & t68);
    t71 = (~(t69));
    t72 = (~(t70));
    t73 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t73 & t71);
    t74 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t74 & t72);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t71);
    t76 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t76 & t72);
    goto LAB27;

LAB28:    *((unsigned int *)t77) = 1;
    goto LAB31;

LAB30:    t84 = (t77 + 4);
    *((unsigned int *)t77) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB31;

LAB32:    t89 = (t0 + 2504U);
    t90 = *((char **)t89);
    memset(t91, 0, 8);
    t89 = (t90 + 4);
    t92 = *((unsigned int *)t89);
    t93 = (~(t92));
    t94 = *((unsigned int *)t90);
    t95 = (t94 & t93);
    t96 = (t95 & 1U);
    if (t96 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t89) != 0)
        goto LAB37;

LAB38:    t99 = *((unsigned int *)t77);
    t100 = *((unsigned int *)t91);
    t101 = (t99 & t100);
    *((unsigned int *)t98) = t101;
    t102 = (t77 + 4);
    t103 = (t91 + 4);
    t104 = (t98 + 4);
    t105 = *((unsigned int *)t102);
    t106 = *((unsigned int *)t103);
    t107 = (t105 | t106);
    *((unsigned int *)t104) = t107;
    t108 = *((unsigned int *)t104);
    t109 = (t108 != 0);
    if (t109 == 1)
        goto LAB39;

LAB40:
LAB41:    goto LAB34;

LAB35:    *((unsigned int *)t91) = 1;
    goto LAB38;

LAB37:    t97 = (t91 + 4);
    *((unsigned int *)t91) = 1;
    *((unsigned int *)t97) = 1;
    goto LAB38;

LAB39:    t110 = *((unsigned int *)t98);
    t111 = *((unsigned int *)t104);
    *((unsigned int *)t98) = (t110 | t111);
    t112 = (t77 + 4);
    t113 = (t91 + 4);
    t114 = *((unsigned int *)t77);
    t115 = (~(t114));
    t116 = *((unsigned int *)t112);
    t117 = (~(t116));
    t118 = *((unsigned int *)t91);
    t119 = (~(t118));
    t120 = *((unsigned int *)t113);
    t121 = (~(t120));
    t122 = (t115 & t117);
    t123 = (t119 & t121);
    t124 = (~(t122));
    t125 = (~(t123));
    t126 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t126 & t124);
    t127 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t127 & t125);
    t128 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t128 & t124);
    t129 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t129 & t125);
    goto LAB41;

LAB42:    *((unsigned int *)t130) = 1;
    goto LAB45;

LAB44:    t137 = (t130 + 4);
    *((unsigned int *)t130) = 1;
    *((unsigned int *)t137) = 1;
    goto LAB45;

LAB46:    t143 = (t0 + 2344U);
    t144 = *((char **)t143);
    memset(t145, 0, 8);
    t143 = (t145 + 4);
    t146 = (t144 + 4);
    t147 = *((unsigned int *)t144);
    t148 = (t147 >> 1);
    t149 = (t148 & 1);
    *((unsigned int *)t145) = t149;
    t150 = *((unsigned int *)t146);
    t151 = (t150 >> 1);
    t152 = (t151 & 1);
    *((unsigned int *)t143) = t152;
    memset(t142, 0, 8);
    t153 = (t145 + 4);
    t154 = *((unsigned int *)t153);
    t155 = (~(t154));
    t156 = *((unsigned int *)t145);
    t157 = (t156 & t155);
    t158 = (t157 & 1U);
    if (t158 != 0)
        goto LAB52;

LAB50:    if (*((unsigned int *)t153) == 0)
        goto LAB49;

LAB51:    t159 = (t142 + 4);
    *((unsigned int *)t142) = 1;
    *((unsigned int *)t159) = 1;

LAB52:    memset(t160, 0, 8);
    t161 = (t142 + 4);
    t162 = *((unsigned int *)t161);
    t163 = (~(t162));
    t164 = *((unsigned int *)t142);
    t165 = (t164 & t163);
    t166 = (t165 & 1U);
    if (t166 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t161) != 0)
        goto LAB55;

LAB56:    t169 = *((unsigned int *)t130);
    t170 = *((unsigned int *)t160);
    t171 = (t169 & t170);
    *((unsigned int *)t168) = t171;
    t172 = (t130 + 4);
    t173 = (t160 + 4);
    t174 = (t168 + 4);
    t175 = *((unsigned int *)t172);
    t176 = *((unsigned int *)t173);
    t177 = (t175 | t176);
    *((unsigned int *)t174) = t177;
    t178 = *((unsigned int *)t174);
    t179 = (t178 != 0);
    if (t179 == 1)
        goto LAB57;

LAB58:
LAB59:    goto LAB48;

LAB49:    *((unsigned int *)t142) = 1;
    goto LAB52;

LAB53:    *((unsigned int *)t160) = 1;
    goto LAB56;

LAB55:    t167 = (t160 + 4);
    *((unsigned int *)t160) = 1;
    *((unsigned int *)t167) = 1;
    goto LAB56;

LAB57:    t180 = *((unsigned int *)t168);
    t181 = *((unsigned int *)t174);
    *((unsigned int *)t168) = (t180 | t181);
    t182 = (t130 + 4);
    t183 = (t160 + 4);
    t184 = *((unsigned int *)t130);
    t185 = (~(t184));
    t186 = *((unsigned int *)t182);
    t187 = (~(t186));
    t188 = *((unsigned int *)t160);
    t189 = (~(t188));
    t190 = *((unsigned int *)t183);
    t191 = (~(t190));
    t192 = (t185 & t187);
    t193 = (t189 & t191);
    t194 = (~(t192));
    t195 = (~(t193));
    t196 = *((unsigned int *)t174);
    *((unsigned int *)t174) = (t196 & t194);
    t197 = *((unsigned int *)t174);
    *((unsigned int *)t174) = (t197 & t195);
    t198 = *((unsigned int *)t168);
    *((unsigned int *)t168) = (t198 & t194);
    t199 = *((unsigned int *)t168);
    *((unsigned int *)t168) = (t199 & t195);
    goto LAB59;

LAB60:    goto LAB62;

LAB63:    *((unsigned int *)t208) = 1;
    goto LAB66;

LAB70:;
LAB72:    t230 = (t0 + 6960U);
    *((char **)t230) = &&LAB69;
    goto LAB1;

}

static void Cont_201_4(char *t0)
{
    char t3[8];
    char t5[8];
    char t20[8];
    char t29[8];
    char t40[8];
    char t74[8];
    char t77[8];
    char t93[8];
    char t125[8];
    char t153[8];
    char *t1;
    char *t2;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    int t64;
    int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    char *t75;
    char *t76;
    char *t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    char *t107;
    char *t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    int t117;
    int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    char *t129;
    char *t130;
    char *t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    char *t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    char *t157;
    char *t158;
    char *t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t167;
    char *t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    int t177;
    int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    char *t185;
    char *t186;
    char *t187;
    char *t188;
    char *t189;
    unsigned int t190;
    unsigned int t191;
    char *t192;
    unsigned int t193;
    unsigned int t194;
    char *t195;
    unsigned int t196;
    unsigned int t197;
    char *t198;

LAB0:    t1 = (t0 + 7208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(201, ng0);
    t2 = (t0 + 2344U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t5 + 4);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    memset(t3, 0, 8);
    t13 = (t5 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t5);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t13) == 0)
        goto LAB4;

LAB6:    t19 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t19) = 1;

LAB7:    t21 = (t0 + 2504U);
    t22 = *((char **)t21);
    memset(t20, 0, 8);
    t21 = (t22 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (~(t23));
    t25 = *((unsigned int *)t22);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB11;

LAB9:    if (*((unsigned int *)t21) == 0)
        goto LAB8;

LAB10:    t28 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t28) = 1;

LAB11:    t30 = (t0 + 4344);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    memset(t29, 0, 8);
    t33 = (t32 + 4);
    t34 = *((unsigned int *)t33);
    t35 = (~(t34));
    t36 = *((unsigned int *)t32);
    t37 = (t36 & t35);
    t38 = (t37 & 1U);
    if (t38 != 0)
        goto LAB15;

LAB13:    if (*((unsigned int *)t33) == 0)
        goto LAB12;

LAB14:    t39 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t39) = 1;

LAB15:    t41 = *((unsigned int *)t20);
    t42 = *((unsigned int *)t29);
    t43 = (t41 & t42);
    *((unsigned int *)t40) = t43;
    t44 = (t20 + 4);
    t45 = (t29 + 4);
    t46 = (t40 + 4);
    t47 = *((unsigned int *)t44);
    t48 = *((unsigned int *)t45);
    t49 = (t47 | t48);
    *((unsigned int *)t46) = t49;
    t50 = *((unsigned int *)t46);
    t51 = (t50 != 0);
    if (t51 == 1)
        goto LAB16;

LAB17:
LAB18:    t72 = (t0 + 2504U);
    t73 = *((char **)t72);
    t72 = (t0 + 4184);
    t75 = (t72 + 56U);
    t76 = *((char **)t75);
    memset(t77, 0, 8);
    t78 = (t77 + 4);
    t79 = (t76 + 4);
    t80 = *((unsigned int *)t76);
    t81 = (t80 >> 2);
    t82 = (t81 & 1);
    *((unsigned int *)t77) = t82;
    t83 = *((unsigned int *)t79);
    t84 = (t83 >> 2);
    t85 = (t84 & 1);
    *((unsigned int *)t78) = t85;
    memset(t74, 0, 8);
    t86 = (t77 + 4);
    t87 = *((unsigned int *)t86);
    t88 = (~(t87));
    t89 = *((unsigned int *)t77);
    t90 = (t89 & t88);
    t91 = (t90 & 1U);
    if (t91 != 0)
        goto LAB22;

LAB20:    if (*((unsigned int *)t86) == 0)
        goto LAB19;

LAB21:    t92 = (t74 + 4);
    *((unsigned int *)t74) = 1;
    *((unsigned int *)t92) = 1;

LAB22:    t94 = *((unsigned int *)t73);
    t95 = *((unsigned int *)t74);
    t96 = (t94 & t95);
    *((unsigned int *)t93) = t96;
    t97 = (t73 + 4);
    t98 = (t74 + 4);
    t99 = (t93 + 4);
    t100 = *((unsigned int *)t97);
    t101 = *((unsigned int *)t98);
    t102 = (t100 | t101);
    *((unsigned int *)t99) = t102;
    t103 = *((unsigned int *)t99);
    t104 = (t103 != 0);
    if (t104 == 1)
        goto LAB23;

LAB24:
LAB25:    t126 = *((unsigned int *)t40);
    t127 = *((unsigned int *)t93);
    t128 = (t126 | t127);
    *((unsigned int *)t125) = t128;
    t129 = (t40 + 4);
    t130 = (t93 + 4);
    t131 = (t125 + 4);
    t132 = *((unsigned int *)t129);
    t133 = *((unsigned int *)t130);
    t134 = (t132 | t133);
    *((unsigned int *)t131) = t134;
    t135 = *((unsigned int *)t131);
    t136 = (t135 != 0);
    if (t136 == 1)
        goto LAB26;

LAB27:
LAB28:    t154 = *((unsigned int *)t3);
    t155 = *((unsigned int *)t125);
    t156 = (t154 & t155);
    *((unsigned int *)t153) = t156;
    t157 = (t3 + 4);
    t158 = (t125 + 4);
    t159 = (t153 + 4);
    t160 = *((unsigned int *)t157);
    t161 = *((unsigned int *)t158);
    t162 = (t160 | t161);
    *((unsigned int *)t159) = t162;
    t163 = *((unsigned int *)t159);
    t164 = (t163 != 0);
    if (t164 == 1)
        goto LAB29;

LAB30:
LAB31:    t185 = (t0 + 8392);
    t186 = (t185 + 56U);
    t187 = *((char **)t186);
    t188 = (t187 + 56U);
    t189 = *((char **)t188);
    memset(t189, 0, 8);
    t190 = 1U;
    t191 = t190;
    t192 = (t153 + 4);
    t193 = *((unsigned int *)t153);
    t190 = (t190 & t193);
    t194 = *((unsigned int *)t192);
    t191 = (t191 & t194);
    t195 = (t189 + 4);
    t196 = *((unsigned int *)t189);
    *((unsigned int *)t189) = (t196 | t190);
    t197 = *((unsigned int *)t195);
    *((unsigned int *)t195) = (t197 | t191);
    xsi_driver_vfirst_trans(t185, 0, 0);
    t198 = (t0 + 8088);
    *((int *)t198) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t20) = 1;
    goto LAB11;

LAB12:    *((unsigned int *)t29) = 1;
    goto LAB15;

LAB16:    t52 = *((unsigned int *)t40);
    t53 = *((unsigned int *)t46);
    *((unsigned int *)t40) = (t52 | t53);
    t54 = (t20 + 4);
    t55 = (t29 + 4);
    t56 = *((unsigned int *)t20);
    t57 = (~(t56));
    t58 = *((unsigned int *)t54);
    t59 = (~(t58));
    t60 = *((unsigned int *)t29);
    t61 = (~(t60));
    t62 = *((unsigned int *)t55);
    t63 = (~(t62));
    t64 = (t57 & t59);
    t65 = (t61 & t63);
    t66 = (~(t64));
    t67 = (~(t65));
    t68 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t68 & t66);
    t69 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t69 & t67);
    t70 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t70 & t66);
    t71 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t71 & t67);
    goto LAB18;

LAB19:    *((unsigned int *)t74) = 1;
    goto LAB22;

LAB23:    t105 = *((unsigned int *)t93);
    t106 = *((unsigned int *)t99);
    *((unsigned int *)t93) = (t105 | t106);
    t107 = (t73 + 4);
    t108 = (t74 + 4);
    t109 = *((unsigned int *)t73);
    t110 = (~(t109));
    t111 = *((unsigned int *)t107);
    t112 = (~(t111));
    t113 = *((unsigned int *)t74);
    t114 = (~(t113));
    t115 = *((unsigned int *)t108);
    t116 = (~(t115));
    t117 = (t110 & t112);
    t118 = (t114 & t116);
    t119 = (~(t117));
    t120 = (~(t118));
    t121 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t121 & t119);
    t122 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t122 & t120);
    t123 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t123 & t119);
    t124 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t124 & t120);
    goto LAB25;

LAB26:    t137 = *((unsigned int *)t125);
    t138 = *((unsigned int *)t131);
    *((unsigned int *)t125) = (t137 | t138);
    t139 = (t40 + 4);
    t140 = (t93 + 4);
    t141 = *((unsigned int *)t139);
    t142 = (~(t141));
    t143 = *((unsigned int *)t40);
    t144 = (t143 & t142);
    t145 = *((unsigned int *)t140);
    t146 = (~(t145));
    t147 = *((unsigned int *)t93);
    t148 = (t147 & t146);
    t149 = (~(t144));
    t150 = (~(t148));
    t151 = *((unsigned int *)t131);
    *((unsigned int *)t131) = (t151 & t149);
    t152 = *((unsigned int *)t131);
    *((unsigned int *)t131) = (t152 & t150);
    goto LAB28;

LAB29:    t165 = *((unsigned int *)t153);
    t166 = *((unsigned int *)t159);
    *((unsigned int *)t153) = (t165 | t166);
    t167 = (t3 + 4);
    t168 = (t125 + 4);
    t169 = *((unsigned int *)t3);
    t170 = (~(t169));
    t171 = *((unsigned int *)t167);
    t172 = (~(t171));
    t173 = *((unsigned int *)t125);
    t174 = (~(t173));
    t175 = *((unsigned int *)t168);
    t176 = (~(t175));
    t177 = (t170 & t172);
    t178 = (t174 & t176);
    t179 = (~(t177));
    t180 = (~(t178));
    t181 = *((unsigned int *)t159);
    *((unsigned int *)t159) = (t181 & t179);
    t182 = *((unsigned int *)t159);
    *((unsigned int *)t159) = (t182 & t180);
    t183 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t183 & t179);
    t184 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t184 & t180);
    goto LAB31;

}

static void Always_205_5(char *t0)
{
    char t13[8];
    char t14[8];
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
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    unsigned int t25;
    int t26;
    char *t27;
    unsigned int t28;
    int t29;
    int t30;
    unsigned int t31;
    unsigned int t32;
    int t33;
    int t34;

LAB0:    t1 = (t0 + 7456U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(205, ng0);
    t2 = (t0 + 8104);
    *((int *)t2) = 1;
    t3 = (t0 + 7488);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(206, ng0);

LAB5:    xsi_set_current_line(207, ng0);
    t4 = (t0 + 3464U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(208, ng0);
    t11 = (t0 + 2664U);
    t12 = *((char **)t11);
    t11 = (t0 + 4024);
    t15 = (t0 + 4024);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t18 = (t0 + 4024);
    t19 = (t18 + 64U);
    t20 = *((char **)t19);
    t21 = (t0 + 4664);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    xsi_vlog_generic_convert_array_indices(t13, t14, t17, t20, 2, 1, t23, 2, 2);
    t24 = (t13 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (!(t25));
    t27 = (t14 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (!(t28));
    t30 = (t26 && t29);
    if (t30 == 1)
        goto LAB9;

LAB10:    goto LAB8;

LAB9:    t31 = *((unsigned int *)t13);
    t32 = *((unsigned int *)t14);
    t33 = (t31 - t32);
    t34 = (t33 + 1);
    xsi_vlogvar_wait_assign_value(t11, t12, 0, *((unsigned int *)t14), t34, 25000LL);
    goto LAB10;

}

static void Cont_211_6(char *t0)
{
    char t5[24];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
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
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 7704U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(211, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 4024);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 4024);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 4504);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_generic_get_array_select_value(t5, 80, t4, t8, t11, 2, 1, t14, 2, 2);
    t15 = (t0 + 8456);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    xsi_vlog_bit_copy(t19, 0, t5, 0, 80);
    xsi_driver_vfirst_trans(t15, 0, 79);
    t20 = (t0 + 8120);
    *((int *)t20) = 1;

LAB1:    return;
}


extern void work_m_02393599663072758043_4117430834_init()
{
	static char *pe[] = {(void *)Cont_174_0,(void *)Cont_176_1,(void *)Cont_177_2,(void *)Always_179_3,(void *)Cont_201_4,(void *)Always_205_5,(void *)Cont_211_6};
	static char *se[] = {(void *)sp_updt_ptrs};
	xsi_register_didat("work_m_02393599663072758043_4117430834", "isim/PicoTestbench_isim_beh.exe.sim/work/m_02393599663072758043_4117430834.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
