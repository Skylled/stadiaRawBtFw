// 600e994c  FUN_600e994c  size=48 bytes
// --- callers ---
//   600e9a16 FUN_600e9a16
//   600e997c FUN_600e997c
// --- callees ---


void FUN_600e994c(int param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (param_3 != 0) {
    puVar3 = (uint *)(param_1 + -4);
    puVar1 = param_2;
    while (puVar2 = puVar1 + 1, puVar2 != param_2 + param_3) {
      puVar3 = puVar3 + 1;
      *puVar3 = *puVar2 << 0x1f | *puVar1 >> 1;
      puVar1 = puVar2;
    }
    *(uint *)(param_1 + param_3 * 4 + -4) = param_2[param_3 + -1] >> 1;
  }
  return;
}


