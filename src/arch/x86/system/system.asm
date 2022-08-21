
%include "system_header.asm"
_optimized_memset_32:
  
  push ebp
  mov ebp, esp

  mov eax, [ebp - 4] ; src
  mov edi, [ebp - 8] ; *dst
  mov ecx, [ebp - 12] ; iterations

  rep stos dword ptr [edi]
  
  pop ebp
  ret

_optimized_memcpy_32:
  push ebp
  mov ebp, esp
  
  nop
  
  pop ebp
  ret
.cpy_loop:
  

  jnz .cpy_loop

