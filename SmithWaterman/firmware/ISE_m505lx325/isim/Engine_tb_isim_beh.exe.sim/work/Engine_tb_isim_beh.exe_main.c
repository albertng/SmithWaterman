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
    xilinxcorelib_ver_m_04284627112054182733_2499657294_init();
    xilinxcorelib_ver_m_18166792875774041790_2569074717_init();
    xilinxcorelib_ver_m_03165991153648205951_2490384146_init();
    xilinxcorelib_ver_m_10066368518302646626_1505135901_init();
    work_m_04920115474770924055_2734403329_init();
    work_m_03277184567634725335_3775303473_init();
    work_m_03759114923906703665_4061799277_init();
    xilinxcorelib_ver_m_16971754672448907676_1494731290_init();
    xilinxcorelib_ver_m_07126858663298141595_4192619990_init();
    xilinxcorelib_ver_m_14518455072116702019_2164875875_init();
    work_m_18219643850453676170_3331025664_init();
    work_m_14115257714309620655_3627157545_init();
    work_m_11946439932700699647_0819255089_init();
    work_m_07791789989081813340_2561090136_init();
    work_m_04495456174737964254_0970487157_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_04495456174737964254_0970487157");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
