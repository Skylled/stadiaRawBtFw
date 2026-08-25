// 600f80c4  FUN_600f80c4  size=94 bytes
// --- callers ---
//   600ae7f8 FUN_600ae7f8
//   600f4cf4 FUN_600f4cf4
// --- callees ---
//   600f800a FUN_600f800a
//   600bb6dc FUN_600bb6dc


void FUN_600f80c4(undefined4 param_1,short param_2,ushort param_3)

{
  int iVar1;
  undefined2 local_18;
  
  iVar1 = FUN_600bb6dc(param_1,2);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + ((ushort)(param_2 - 4U) + 0x24) * 4) != 0) {
      local_18 = param_3;
      if (0xfb < param_3) {
        local_18 = 0xfb;
      }
      *(ushort *)(*(int *)(iVar1 + ((ushort)(param_2 - 4U) + 0x24) * 4) + 0x122) = local_18;
    }
    FUN_600f800a(iVar1);
  }
  return;
}


