// 600abb14  FUN_600abb14  size=172 bytes
// --- callers ---
//   600fd6aa FUN_600fd6aa
//   600aac04 FUN_600aac04
//   600fefac FUN_600fefac
// --- callees ---
//   600af610 FUN_600af610
//   600af814 FUN_600af814
//   600afd28 FUN_600afd28


void FUN_600abb14(byte param_1)

{
  int iVar1;
  undefined1 local_26;
  char local_25;
  undefined1 auStack_24 [6];
  undefined2 local_1e;
  int local_1c;
  int local_18;
  char local_11;
  
  iVar1 = FUN_600afd28(param_1);
  if (iVar1 != 0) {
    local_18 = DAT_600abbc0 + (param_1 - 1) * 0x30 + 0x1068;
    local_11 = '\0';
    while (iVar1 = FUN_600af610(local_11,auStack_24,&local_25,&local_26), iVar1 != 0) {
      local_1c = FUN_600af814(auStack_24,local_26);
      if ((*(int *)(local_18 + 0x14) != 0) && (local_1c != 0)) {
        local_1e = CONCAT11(*(undefined1 *)(local_1c + 0xfb),param_1);
        (**(code **)(local_18 + 0x14))(param_1,auStack_24,local_1e,1,0,local_26);
      }
      local_25 = local_25 + '\x01';
      local_11 = local_25;
    }
  }
  return;
}


