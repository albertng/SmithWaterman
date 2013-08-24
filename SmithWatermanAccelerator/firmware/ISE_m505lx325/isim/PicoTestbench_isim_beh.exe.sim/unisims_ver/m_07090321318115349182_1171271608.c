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
static int ng0[] = {1179595064, 0, 17993, 0, 0, 0};
static int ng1[] = {945763126, 0, 1229344561, 0, 70, 0};
static int ng2[] = {36, 0};
static const char *ng3 = "DRC Error : The attribute DATA_WIDTH must be set to 36 when attribute FIFO_MODE = FIFO18_36.";
static int ng4[] = {1, 0};
static const char *ng5 = "Attribute Syntax Error : The attribute FIFO_MODE on FIFO18E1 instance %m is set to %s.  Legal values for this attribute are FIFO18 or FIFO18_36.";
static int ng6[] = {4, 0};
static int ng7[] = {9, 0};
static int ng8[] = {18, 0};
static const char *ng9 = "DRC Error : The attribute FIFO_MODE must be set to FIFO18_36 when attribute DATA_WIDTH = 36.";
static const char *ng10 = "Attribute Syntax Error : The attribute DATA_WIDTH on FIFO18E1 instance %m is set to %d.  Legal values for this attribute are 4, 9, 18 or 36.";
static unsigned int ng11[] = {0U, 0U};



static void NetDecl_83_0(char *t0)
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

LAB0:    t1 = (t0 + 8792U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 13416);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 10464);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 0U);
    t18 = (t0 + 10352);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Initial_92_1(char *t0)
{
    char t8[8];
    char t19[24];
    char *t1;
    char *t2;
    int t3;
    char *t4;
    int t5;
    char *t6;
    char *t7;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    int t15;
    int t16;
    char *t17;
    char *t18;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;

LAB0:
LAB2:    t1 = (t0 + 1152);
    t2 = *((char **)t1);

LAB3:    t1 = ((char*)((ng0)));
    t3 = xsi_vlog_unsigned_case_compare(t2, 48, t1, 72);
    if (t3 == 1)
        goto LAB4;

LAB5:    t4 = ((char*)((ng1)));
    t5 = xsi_vlog_unsigned_case_compare(t2, 48, t4, 72);
    if (t5 == 1)
        goto LAB6;

LAB7:
LAB9:
LAB8:
LAB15:    t1 = (t0 + 1152);
    t4 = *((char **)t1);
    xsi_vlogfile_write(1, 0, 0, ng5, 2, t0, (char)118, t4, 48);
    t1 = ((char*)((ng4)));
    t4 = (t0 + 7880);
    xsi_vlogvar_assign_value(t4, t1, 0, 0, 1);

LAB10:    t1 = (t0 + 744);
    t4 = *((char **)t1);

LAB16:    t1 = ((char*)((ng6)));
    t3 = xsi_vlog_signed_case_compare(t4, 32, t1, 32);
    if (t3 == 1)
        goto LAB17;

LAB18:    t6 = ((char*)((ng7)));
    t5 = xsi_vlog_signed_case_compare(t4, 32, t6, 32);
    if (t5 == 1)
        goto LAB19;

LAB20:    t7 = ((char*)((ng8)));
    t15 = xsi_vlog_signed_case_compare(t4, 32, t7, 32);
    if (t15 == 1)
        goto LAB21;

LAB22:    t9 = ((char*)((ng2)));
    t16 = xsi_vlog_signed_case_compare(t4, 32, t9, 32);
    if (t16 == 1)
        goto LAB23;

LAB24:
LAB26:
LAB25:
LAB32:    t1 = (t0 + 744);
    t6 = *((char **)t1);
    xsi_vlogfile_write(1, 0, 0, ng10, 2, t0, (char)119, t6, 32);
    t1 = ((char*)((ng4)));
    t6 = (t0 + 7880);
    xsi_vlogvar_assign_value(t6, t1, 0, 0, 1);

LAB27:    t1 = (t0 + 7880);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t9 = ((char*)((ng4)));
    memset(t8, 0, 8);
    t17 = (t7 + 4);
    t18 = (t9 + 4);
    t10 = *((unsigned int *)t7);
    t11 = *((unsigned int *)t9);
    t12 = (t10 ^ t11);
    t13 = *((unsigned int *)t17);
    t14 = *((unsigned int *)t18);
    t21 = (t13 ^ t14);
    t22 = (t12 | t21);
    t23 = *((unsigned int *)t17);
    t24 = *((unsigned int *)t18);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB36;

LAB33:    if (t25 != 0)
        goto LAB35;

LAB34:    *((unsigned int *)t8) = 1;

LAB36:    t28 = (t8 + 4);
    t29 = *((unsigned int *)t28);
    t30 = (~(t29));
    t31 = *((unsigned int *)t8);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB37;

LAB38:
LAB39:
LAB1:    return;
LAB4:    goto LAB10;

LAB6:    t6 = (t0 + 744);
    t7 = *((char **)t6);
    t6 = ((char*)((ng2)));
    memset(t8, 0, 8);
    xsi_vlog_signed_not_equal(t8, 32, t7, 32, t6, 32);
    t9 = (t8 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (~(t10));
    t12 = *((unsigned int *)t8);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB11;

LAB12:
LAB13:    goto LAB10;

LAB11:
LAB14:    xsi_vlogfile_write(1, 0, 0, ng3, 1, t0);
    t1 = ((char*)((ng4)));
    t4 = (t0 + 7880);
    xsi_vlogvar_assign_value(t4, t1, 0, 0, 1);
    goto LAB13;

LAB17:    goto LAB27;

LAB19:    goto LAB17;

LAB21:    goto LAB17;

LAB23:    t17 = (t0 + 1152);
    t18 = *((char **)t17);
    t17 = ((char*)((ng1)));
    xsi_vlog_unsigned_not_equal(t19, 72, t18, 48, t17, 72);
    t20 = (t19 + 4);
    t10 = *((unsigned int *)t20);
    t11 = (~(t10));
    t12 = *((unsigned int *)t19);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB28;

LAB29:
LAB30:    goto LAB27;

LAB28:
LAB31:    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    t1 = ((char*)((ng4)));
    t6 = (t0 + 7880);
    xsi_vlogvar_assign_value(t6, t1, 0, 0, 1);
    goto LAB30;

LAB35:    t20 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB36;

LAB37:    xsi_vlog_finish(1);
    goto LAB39;

}

static void implSig1_execute(char *t0)
{
    char t3[16];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 9288U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4280U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng11)));
    xsi_vlogtype_concat(t3, 64, 64, 2U, t2, 32, t4, 32);
    t5 = (t0 + 10528);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t3, 0, 64);
    xsi_driver_vfirst_trans(t5, 0, 63);
    t10 = (t0 + 10368);
    *((int *)t10) = 1;

LAB1:    return;
}

static void implSig2_execute(char *t0)
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

LAB0:    t1 = (t0 + 9536U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4440U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng11)));
    xsi_vlogtype_concat(t3, 8, 8, 2U, t2, 4, t4, 4);
    t5 = (t0 + 10592);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
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
    xsi_driver_vfirst_trans(t5, 0, 7);
    t18 = (t0 + 10384);
    *((int *)t18) = 1;

LAB1:    return;
}

static void implSig3_execute(char *t0)
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
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 9784U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng11)));
    t3 = (t0 + 10656);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig4_execute(char *t0)
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
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 10032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng11)));
    t3 = (t0 + 10720);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}


extern void unisims_ver_m_07090321318115349182_1171271608_init()
{
	static char *pe[] = {(void *)NetDecl_83_0,(void *)Initial_92_1,(void *)implSig1_execute,(void *)implSig2_execute,(void *)implSig3_execute,(void *)implSig4_execute};
	xsi_register_didat("unisims_ver_m_07090321318115349182_1171271608", "isim/PicoTestbench_isim_beh.exe.sim/unisims_ver/m_07090321318115349182_1171271608.didat");
	xsi_register_executes(pe);
}
