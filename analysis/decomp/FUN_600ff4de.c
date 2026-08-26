// 600ff4de  FUN_600ff4de  size=168 bytes
// --- callers ---
// --- callees ---
//   60095d4c FUN_60095d4c
//   600f3e00 FUN_600f3e00
//   600f3c42 FUN_600f3c42
//   60095b2c FUN_60095b2c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60095cd4 FUN_60095cd4


void FUN_600ff4de(undefined2 param_1,undefined4 param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  char local_22;
  undefined1 local_21;
  undefined1 auStack_20 [8];
  undefined4 local_18;
  undefined2 local_14;
  undefined4 local_10;
  int local_c;
  
  thunk_EXT_FUN_0000b5ba(auStack_20,0,0x14);
  iVar1 = FUN_600f3e00(param_1,&local_21,auStack_20,&local_22);
  if (iVar1 != 0) {
    local_c = FUN_60095b2c(local_21);
    if (param_3 != '\x04') {
      FUN_600f3c42(local_21,auStack_20,1,local_22);
    }
    if ((local_c != 0) && (*(int *)(local_c + 0x18) != 0)) {
      if (local_22 == '\x01') {
        FUN_60095d4c(0x1e,0xff,auStack_20);
        FUN_60095cd4(0x1e,0xff,auStack_20);
      }
      local_18 = param_2;
      local_14 = param_1;
      local_10 = param_4;
      (**(code **)(local_c + 0x18))(param_3,auStack_20);
    }
  }
  return;
}


