// 600d2a6e  FUN_600d2a6e  size=32 bytes
// --- callers ---
//   600d2b0e FUN_600d2b0e
//   600d2a8e FUN_600d2a8e
//   600d2dba FUN_600d2dba
// --- callees ---


void FUN_600d2a6e(int param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(param_1 + param_3 * 4);
  while ((puVar1 = puVar2, puVar1 != (uint *)0x0 && (-1 < (int)(*puVar1 << 0x1f)))) {
    puVar2 = (uint *)(*puVar1 & 0xffffffe0);
    if (puVar2 == param_2) {
      *puVar1 = *param_2;
      return;
    }
  }
  return;
}


