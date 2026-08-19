// 600d9414  FUN_600d9414  size=172 bytes
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   6006f018 FUN_6006f018


uint FUN_600d9414(undefined4 *param_1)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  byte local_25 [9];
  
  pbVar1 = local_25 + 1;
  local_25[1] = 5;
  uVar3 = thunk_EXT_FUN_00001ea4(*param_1,*(undefined1 *)(param_1 + 1),pbVar1,1,local_25,1,200);
  if ((uVar3 & 0xff) != 0) {
    return uVar3;
  }
  if ((local_25[0] & 0x30) != 0x10) {
    local_25[1] = 7;
    uVar3 = thunk_EXT_FUN_00001ea4(*param_1,*(undefined1 *)(param_1 + 1),pbVar1,1,local_25,1,200);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    bVar2 = local_25[0] & 8;
    if ((local_25[0] & 8) != 0) {
      param_1[3] = 0;
      return 0;
    }
    if (*(char *)(param_1 + 2) != '\0') {
      local_25[0] = local_25[0] | 8;
      local_25[1] = 7;
      local_25[2] = local_25[0];
      uVar3 = thunk_EXT_FUN_00001ea4(*param_1,*(undefined1 *)(param_1 + 1),pbVar1,2,bVar2,bVar2,200)
      ;
      if ((uVar3 & 0xff) != 0) {
        return uVar3;
      }
    }
  }
  uVar4 = FUN_6006f018();
  param_1[3] = uVar4;
  return 0;
}


