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
    work_m_03277184567634725335_3602042663_init();
    work_m_03447367028062913821_1084631206_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_03447367028062913821_1084631206");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
