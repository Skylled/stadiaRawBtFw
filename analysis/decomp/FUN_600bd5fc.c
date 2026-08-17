// 600bd5fc  FUN_600bd5fc  size=86 bytes
// --- callers ---
//   600be558 FUN_600be558
// --- callees ---


int * FUN_600bd5fc(int param_1)

{
  int *local_c;
  
  local_c = DAT_600bd658;
  while( true ) {
    if ((int *)((uint)*(ushort *)(DAT_600bd654 + 0x102) * 0x1cc + DAT_600bd654 + 0x104) <= local_c)
    {
      return (int *)0x0;
    }
    if (param_1 == *local_c) break;
    local_c = local_c + 0x73;
  }
  return local_c;
}


