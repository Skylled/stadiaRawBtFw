// 600ac128  FUN_600ac128  size=256 bytes
// --- callers ---
// --- callees ---
//   600f194c FUN_600f194c
//   600d9250 FUN_600d9250
//   600af814 FUN_600af814
//   600f42fc FUN_600f42fc
//   6006ddd8 FUN_6006ddd8
//   600ac438 FUN_600ac438
//   600f4266 FUN_600f4266


void FUN_600ac128(undefined4 param_1,undefined1 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  byte local_15;
  int *local_14;
  int local_10;
  short local_c;
  char local_9;
  
  local_9 = 0;
  local_10 = FUN_600af814(param_1,param_2);
  if (((local_10 != 0) && (iVar1 = FUN_600f42fc(local_10), iVar1 != 6)) &&
     (local_14 = (int *)FUN_600d9250(local_10), local_14 != (int *)0x0)) {
    if (param_4 == '\0') {
      iVar1 = FUN_600f42fc(local_10);
      if (iVar1 == 5) {
        FUN_600f194c(param_1,&local_15,param_2);
        if ((local_15 & 2) != 0) {
          local_9 = 1;
        }
      }
      else {
        local_9 = 1;
      }
    }
    if (*(char *)(*local_14 + 0x5c) != '\0') {
      FUN_600f4266(local_9,*local_14,*(undefined1 *)(local_10 + 0xc));
    }
    FUN_6006ddd8(local_14,DAT_600ac228,0xb5);
    local_c = *(short *)(local_10 + 8);
    local_9 = '\0';
    while (((local_c != 0 && (local_9 == '\0')) &&
           (local_14 = (int *)FUN_600d9250(local_10), local_14 != (int *)0x0))) {
      if (*(char *)(*local_14 + 0x5c) != '\0') {
        FUN_600ac438(*local_14);
        local_9 = '\x01';
      }
      FUN_6006ddd8(local_14,DAT_600ac228,0xc1);
      local_c = local_c + -1;
    }
  }
  return;
}


