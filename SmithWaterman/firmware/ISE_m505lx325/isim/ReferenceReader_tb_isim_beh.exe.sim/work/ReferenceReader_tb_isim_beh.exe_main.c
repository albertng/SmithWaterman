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
    xilinxcorelib_ver_m_13880558823444695255_3491632229_init();
    xilinxcorelib_ver_m_02693843609087607046_3566275113_init();
    xilinxcorelib_ver_m_09003160300769859152_3668156805_init();
    xilinxcorelib_ver_m_14518455072116702019_0190450084_init();
    work_m_18219643850453676170_1185934629_init();
    work_m_12462826048998305829_2627010146_init();
    work_m_00553723662635941550_1678361156_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_00553723662635941550_1678361156");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
