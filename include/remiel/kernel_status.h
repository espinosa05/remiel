#ifndef _REMIEL_KERNEL_STATUS_H
#define _REMIEL_KERNEL_STATUS_H

#include <stdint.h>


#define SHUTDOWN_FAILURE	(0x3 << 28) 
#define SYSTEM_HALT			(0x4 << 28)
#define DISK_ERROR			(0xde << 24)
#define CPU_NOT_SUPPORTED	(0xdead << 20)

#ifdef _x64
  typedef uint64_t KERNEL_STATUS;
#else
  typedef uint32_t KERNEL_STATUS;
#endif // _x64

#endif // _REMIEL_KERNEL_STATUS_H
