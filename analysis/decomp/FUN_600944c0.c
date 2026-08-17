// 600944c0  FUN_600944c0  size=86 bytes
// --- callers ---
//   600c2d5c FUN_600c2d5c
//   60093d20 FUN_60093d20
//   600fd03a FUN_600fd03a
//   60093a30 FUN_60093a30
//   600ee33e FUN_600ee33e
// --- callees ---
//   600efcfe FUN_600efcfe


int FUN_600944c0(undefined4 param_1)

{
  int iVar1;
  int local_10;
  
  local_10 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(DAT_60094518 + 0xe4) <= local_10) {
      return 0;
    }
    iVar1 = FUN_600efcfe(local_10 * 0x20 + DAT_60094518 + 4,param_1);
    if (iVar1 == 0) break;
    local_10 = local_10 + 1;
  }
  return local_10 * 0x20 + DAT_60094518 + 4;
}


