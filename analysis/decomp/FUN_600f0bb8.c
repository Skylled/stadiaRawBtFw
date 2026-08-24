// 600f0bb8  FUN_600f0bb8  size=204 bytes
// --- callers ---
//   600f1b72 FUN_600f1b72
// --- callees ---
//   600f0b06 FUN_600f0b06
//   600c0578 FUN_600c0578
//   6009ff18 FUN_6009ff18
//   6009afd4 FUN_6009afd4


undefined1 FUN_600f0bb8(undefined4 param_1,byte *param_2,char param_3)

{
  undefined1 uVar1;
  int iVar2;
  char local_12;
  undefined1 local_11;
  int local_10;
  byte local_a;
  undefined1 local_9;
  
  local_9 = 3;
  local_a = *param_2;
  local_10 = FUN_6009ff18(param_1);
  if (local_10 == 0) {
    local_9 = 6;
  }
  else {
    if (local_a == 3) {
      *(ushort *)(local_10 + 0x54) = *(ushort *)(local_10 + 0x54) | 0x1000;
    }
    if (local_a == 1) {
      if (param_3 == '\0') {
        uVar1 = FUN_6009afd4(param_1,0,0);
        return uVar1;
      }
    }
    else if ((local_a == 0) || (3 < local_a)) {
      return 6;
    }
    if (param_3 == '\0') {
      if (local_a == 2) {
        local_11 = 1;
      }
      else {
        local_11 = 5;
      }
      FUN_600f0b06(param_1,local_11,&local_12);
      if (local_12 == '\x01') {
        uVar1 = FUN_6009afd4(param_1,0,0);
        return uVar1;
      }
    }
    iVar2 = FUN_600c0578(param_1);
    if (iVar2 == 0x15) {
      local_9 = 1;
      *(undefined1 *)(local_10 + 0x50) = 1;
    }
  }
  return local_9;
}


