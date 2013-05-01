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
static int ng0[] = {1179595574, 0, 17993, 0, 0, 0};
static int ng1[] = {912209714, 0, 1229344563, 0, 70, 0};
static int ng2[] = {72, 0};
static const char *ng3 = "DRC Error : The attribute DATA_WIDTH must be set to 72 when attribute FIFO_MODE = FIFO36_72.";
static int ng4[] = {1, 0};
static const char *ng5 = "Attribute Syntax Error : The attribute FIFO_MODE on FIFO36E1 instance %m is set to %s.  Legal values for this attribute are FIFO36 or FIFO36_72.";
static int ng6[] = {4, 0};
static int ng7[] = {9, 0};
static int ng8[] = {18, 0};
static int ng9[] = {36, 0};
static const char *ng10 = "DRC Error : The attribute FIFO_MODE must be set to FIFO36_72 when attribute DATA_WIDTH = 72.";
static const char *ng11 = "Attribute Syntax Error : The attribute DATA_WIDTH on FIFO36E1 instance %m is set to %d.  Legal values for this attribute are 4, 9, 18, 36 or 72.";



static void NetDecl_97_0(char *t0)
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

LAB0:    t1 = (t0 + 8104U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 11408);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 8752);
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
    t18 = (t0 + 8672);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Initial_102_1(char *t0)
{
    char t8[8];
    char t21[24];
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
    int t18;
    char *t19;
    char *t20;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;

LAB0:
LAB2:    t1 = (t0 + 1424);
    t2 = *((char **)t1);

LAB3:    t1 = ((char*)((ng0)));
    t3 = xsi_vlog_unsigned_case_compare(t2, 72, t1, 72);
    if (t3 == 1)
        goto LAB4;

LAB5:    t4 = ((char*)((ng1)));
    t5 = xsi_vlog_unsigned_case_compare(t2, 72, t4, 72);
    if (t5 == 1)
        goto LAB6;

LAB7:
LAB9:
LAB8:
LAB15:    t1 = (t0 + 1424);
    t4 = *((char **)t1);
    xsi_vlogfile_write(1, 0, 0, ng5, 2, t0, (char)118, t4, 72);
    t1 = ((char*)((ng4)));
    t4 = (t0 + 7192);
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

LAB22:    t9 = ((char*)((ng9)));
    t16 = xsi_vlog_signed_case_compare(t4, 32, t9, 32);
    if (t16 == 1)
        goto LAB23;

LAB24:    t17 = ((char*)((ng2)));
    t18 = xsi_vlog_signed_case_compare(t4, 32, t17, 32);
    if (t18 == 1)
        goto LAB25;

LAB26:
LAB28:
LAB27:
LAB34:    t1 = (t0 + 744);
    t6 = *((char **)t1);
    xsi_vlogfile_write(1, 0, 0, ng11, 2, t0, (char)119, t6, 32);
    t1 = ((char*)((ng4)));
    t6 = (t0 + 7192);
    xsi_vlogvar_assign_value(t6, t1, 0, 0, 1);

LAB29:    t1 = (t0 + 7192);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t9 = ((char*)((ng4)));
    memset(t8, 0, 8);
    t17 = (t7 + 4);
    t19 = (t9 + 4);
    t10 = *((unsigned int *)t7);
    t11 = *((unsigned int *)t9);
    t12 = (t10 ^ t11);
    t13 = *((unsigned int *)t17);
    t14 = *((unsigned int *)t19);
    t23 = (t13 ^ t14);
    t24 = (t12 | t23);
    t25 = *((unsigned int *)t17);
    t26 = *((unsigned int *)t19);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB38;

LAB35:    if (t27 != 0)
        goto LAB37;

LAB36:    *((unsigned int *)t8) = 1;

LAB38:    t22 = (t8 + 4);
    t30 = *((unsigned int *)t22);
    t31 = (~(t30));
    t32 = *((unsigned int *)t8);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB39;

LAB40:
LAB41:
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
    t4 = (t0 + 7192);
    xsi_vlogvar_assign_value(t4, t1, 0, 0, 1);
    goto LAB13;

LAB17:    goto LAB29;

LAB19:    goto LAB17;

LAB21:    goto LAB17;

LAB23:    goto LAB17;

LAB25:    t19 = (t0 + 1424);
    t20 = *((char **)t19);
    t19 = ((char*)((ng1)));
    xsi_vlog_unsigned_not_equal(t21, 72, t20, 72, t19, 72);
    t22 = (t21 + 4);
    t10 = *((unsigned int *)t22);
    t11 = (~(t10));
    t12 = *((unsigned int *)t21);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB30;

LAB31:
LAB32:    goto LAB29;

LAB30:
LAB33:    xsi_vlogfile_write(1, 0, 0, ng10, 1, t0);
    t1 = ((char*)((ng4)));
    t6 = (t0 + 7192);
    xsi_vlogvar_assign_value(t6, t1, 0, 0, 1);
    goto LAB32;

LAB37:    t20 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB38;

LAB39:    xsi_vlog_finish(1);
    goto LAB41;

}


extern void unisims_ver_m_10103215136513494468_1905346062_init()
{
	static char *pe[] = {(void *)NetDecl_97_0,(void *)Initial_102_1};
	xsi_register_didat("unisims_ver_m_10103215136513494468_1905346062", "isim/PicoTestbench_isim_beh.exe.sim/unisims_ver/m_10103215136513494468_1905346062.didat");
	xsi_register_executes(pe);
}
