// 600ce96e  FUN_600ce96e  size=130 bytes
// --- callers ---
//   6005ef04 bee__6005ef04
// --- callees ---
//   600ce932 FUN_600ce932


undefined4 FUN_600ce96e(uint *param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  bool bVar2;
  
  if ((param_3 != 0) && (((param_3 & 3) != 0 || (param_4 != 0x10)))) {
    return 4;
  }
  do {
  } while (-1 < (int)(param_1[7] << 0x17));
  bVar2 = (*param_1 & 1) != 0;
  if (bVar2) {
    *param_1 = *param_1 & 0xffffffee;
  }
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xffffffdf;
    if (param_5 == 0) goto LAB_600ce9b8;
    if (param_6 != 0x10) {
      return 4;
    }
    puVar1 = param_1 + 8;
  }
  else {
    if (param_2 != 1) {
      return 4;
    }
    *param_1 = *param_1 | 0x20;
    if (param_5 == 0) goto LAB_600ce9b8;
    if (param_6 != 0x10) {
      return 4;
    }
    puVar1 = param_1 + 0xc;
  }
  FUN_600ce932(puVar1);
LAB_600ce9b8:
  if (param_3 != 0) {
    FUN_600ce932(param_1 + 3,param_3);
  }
  if (!bVar2) {
    return 0;
  }
  *param_1 = *param_1 | 0x11;
  return 0;
}


