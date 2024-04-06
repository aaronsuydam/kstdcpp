# Define the source directory and build directory for kernel components
# Getting the running kernel version using run_command
uname_r = run_command('uname', '-r').stdout().strip()
kernel_src_dir = '/lib/modules/' + uname_r + '/build'
kernel_build_dir = meson.current_source_dir()

# Define the command to invoke the Makefile for the C++ kernel library
# Adjust the paths as necessary
make_cmd = ['make', '-C', kernel_src_dir, 'M=' + kernel_build_dir, 'modules']

# Use a custom target to invoke the Make command
# This will build your C++ kernel library using its Makefile
kstdcpp = custom_target('kstdcpp_lib',
    output : 'kstdcpp.o',
    command : make_cmd,
    build_by_default : true
)