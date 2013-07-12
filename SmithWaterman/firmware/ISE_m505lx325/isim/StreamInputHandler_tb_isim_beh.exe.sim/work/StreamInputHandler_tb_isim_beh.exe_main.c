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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    xilinxcorelib_ver_m_03971639830285338144_0692925145_init();
    xilinxcorelib_ver_m_08863506630922086634_0310667977_init();
    xilinxcorelib_ver_m_02693843609087607046_0175301085_init();
    xilinxcorelib_ver_m_12326241615891885690_0135035707_init();
    xilinxcorelib_ver_m_14518455072116702019_0689454589_init();
    work_m_05880053597461080167_3595067253_init();
    work_m_18371428805628354313_0962120008_init();
    work_m_01754186769873589898_3890821843_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_01754186769873589898_3890821843");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
