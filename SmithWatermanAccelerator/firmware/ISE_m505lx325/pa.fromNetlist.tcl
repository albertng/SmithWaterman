
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name m505lx325 -dir "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/planAhead_run_1" -part xc7k325tffg900-2
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/Pico_Toplevel.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325} {source} {../ipcore_dir} }
add_files [list {source/coregen_fifo_32x128.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../ipcore_dir/cellscorefilter_fifo.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../ipcore_dir/inter_ref_block_fifo.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../ipcore_dir/ref_seq_block_buffer.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../ipcore_dir/query_seq_bram.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {../ipcore_dir/stream_data_sync_buffer.ncf}] -fileset [get_property constrset [current_run]]
set_property target_constrs_file "/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/M505_LX325T_PCIe.ucf" [current_fileset -constrset]
add_files [list {/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/M505_LX325T_PCIe.ucf}] -fileset [get_property constrset [current_run]]
add_files [list {/home/albertng/Documents/SmithWaterman/SmithWatermanAccelerator/firmware/ISE_m505lx325/source/M505_LX325T_DDR3.ucf}] -fileset [get_property constrset [current_run]]
link_design
