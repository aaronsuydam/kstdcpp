project('kstd_cpp', 'cpp', 'c',
  default_options : ['cpp_exceptions=false', 'b_staticpic=true'])

kernel_version = '6.2.0-39-generic'
build_root = '/lib/modules/' + kernel_version + '/build'

# Specify kernel headers and include directories
linux_main_inc = include_directories('/usr/src/linux-headers-6.2.0-39-generic/include')


# Specify source files
sources = ['src/new.cpp']

library('kstd_cpp', sources,
  include_directories : [linux_main_inc],
  c_args : ['-fno-rtti'],
  cpp_args : ['-fno-exceptions', '-fno-rtti'],
  link_args : [build_root + '/scripts/module-common.lds'],
)
