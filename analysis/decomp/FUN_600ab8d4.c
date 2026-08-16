// 600ab8d4  FUN_600ab8d4  size=222 bytes
// --- callers ---
//   600c611c FUN_600c611c
//   600aac04 FUN_600aac04
//   600c6ad0 FUN_600c6ad0
// --- callees ---
//   600b0444 FUN_600b0444
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d168 thunk_EXT_FUN_0000b554


undefined1 FUN_600ab8d4(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte local_15;
  undefined4 *local_14;
  
  FUN_600b0444(*param_1,param_1[1],param_1[2],param_1[3],param_1[4]);
  local_15 = 0;
  local_14 = DAT_600ab9b4;
  while( true ) {
    if (9 < local_15) {
      local_15 = 0;
      local_14 = DAT_600ab9b4;
      while( true ) {
        if (9 < local_15) {
          return 0;
        }
        if (*(char *)((int)local_14 + 0x2d) == '\0') break;
        local_15 = local_15 + 1;
        local_14 = local_14 + 0xc;
      }
      thunk_EXT_FUN_0000b5ba(local_14,0,0x30);
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      *local_14 = *param_1;
      local_14[1] = uVar2;
      local_14[2] = uVar3;
      local_14[3] = uVar4;
      local_14[4] = param_1[4];
      *(byte *)(local_14 + 0xb) = local_15 + 1;
      uVar2 = param_2[1];
      uVar3 = param_2[2];
      uVar4 = param_2[3];
      local_14[5] = *param_2;
      local_14[6] = uVar2;
      local_14[7] = uVar3;
      local_14[8] = uVar4;
      uVar2 = param_2[5];
      local_14[9] = param_2[4];
      local_14[10] = uVar2;
      *(undefined1 *)((int)local_14 + 0x2d) = 1;
      return *(undefined1 *)(local_14 + 0xb);
    }
    if ((*(char *)((int)local_14 + 0x2d) != '\0') &&
       (iVar1 = thunk_EXT_FUN_0000b554(param_1 + 1,local_14 + 1,0x10), iVar1 == 0)) break;
    local_15 = local_15 + 1;
    local_14 = local_14 + 0xc;
  }
  return 0;
}


