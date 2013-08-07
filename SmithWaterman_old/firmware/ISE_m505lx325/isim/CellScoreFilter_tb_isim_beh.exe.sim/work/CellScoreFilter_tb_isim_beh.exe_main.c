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
    xilinxcorelib_ver_m_03971639830285338144_2632141972_init();
    xilinxcorelib_ver_m_08863506630922086634_3403046994_init();
    xilinxcorelib_ver_m_02693843609087607046_2195159621_init();
    xilinxcorelib_ver_m_15587637214769302633_0800330770_init();
    xilinxcorelib_ver_m_14518455072116702019_4121881667_init();
    work_m_05880053597461080167_3869918272_init();
    work_m_06239606121695036953_4264188366_init();
    work_m_06574242053307746810_3890803072_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_06574242053307746810_3890803072");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
