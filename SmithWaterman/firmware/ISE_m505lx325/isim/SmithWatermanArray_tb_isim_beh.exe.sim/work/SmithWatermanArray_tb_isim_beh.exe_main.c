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
    xilinxcorelib_ver_m_16971754672448907676_1494731290_init();
    xilinxcorelib_ver_m_07126858663298141595_4192619990_init();
    xilinxcorelib_ver_m_14518455072116702019_2164875875_init();
    work_m_18219643850453676170_3331025664_init();
    work_m_09624243058189173774_3627157545_init();
    work_m_02530831803115982894_0816465317_init();
    work_m_06207911632835694233_0097652272_init();
    work_m_03917263297488337725_1274815430_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_03917263297488337725_1274815430");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
