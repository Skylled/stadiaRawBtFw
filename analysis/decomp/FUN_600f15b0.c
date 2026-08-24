// 600f15b0  FUN_600f15b0  size=150 bytes
// --- callers ---
//   600f1646 FUN_600f1646
//   600f2532 FUN_600f2532
// --- callees ---
//   600f103a FUN_600f103a
//   6009ef10 FUN_6009ef10


void FUN_600f15b0(char *param_1,ushort param_2)

{
  int iVar1;
  char *pcVar2;
  char *local_24;
  undefined1 auStack_20 [8];
  undefined1 auStack_18 [5];
  char local_13 [3];
  
  local_13[2] = 0;
  local_13[1] = *param_1;
  iVar1 = FUN_6009ef10(auStack_20);
  if ((iVar1 != 0) && (local_13[1] == '\0')) {
    if (param_2 < 9) {
      pcVar2 = local_13;
      for (iVar1 = 0; local_24 = param_1 + 1, iVar1 < 6; iVar1 = iVar1 + 1) {
        *pcVar2 = *local_24;
        pcVar2 = pcVar2 + -1;
        param_1 = local_24;
      }
    }
    else {
      pcVar2 = local_13;
      local_24 = param_1 + 0x1a;
      for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
        *pcVar2 = *local_24;
        pcVar2 = pcVar2 + -1;
        local_24 = local_24 + 1;
      }
    }
    FUN_600f103a(auStack_20,auStack_18,local_13[2]);
  }
  return;
}


