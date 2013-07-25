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
    xilinxcorelib_ver_m_13880558823444695255_2178597346_init();
    xilinxcorelib_ver_m_02693843609087607046_0118280997_init();
    xilinxcorelib_ver_m_09003160300769859152_0677933803_init();
    xilinxcorelib_ver_m_14518455072116702019_2499487607_init();
    work_m_18219643850453676170_3869918272_init();
    work_m_10220779066609030043_4264188366_init();
    work_m_13118469406992640436_3890803072_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_13118469406992640436_3890803072");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
