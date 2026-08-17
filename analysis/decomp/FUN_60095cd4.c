// 60095cd4  FUN_60095cd4  size=116 bytes
// --- callers ---
//   600ff4de FUN_600ff4de
//   600ff21c FUN_600ff21c
//   600fe496 FUN_600fe496
//   600c68fc FUN_600c68fc
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60095d9c FUN_60095d9c


void FUN_60095cd4(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_18 [6];
  undefined1 local_12;
  undefined1 local_11;
  
  if (*(int *)(DAT_60095d48 + 0x13c) != 0) {
    (**(code **)(DAT_60095d48 + 0x13c))(6,param_1,param_2,param_3);
  }
  if (*(int *)(DAT_60095d48 + 0x140) != 0) {
    local_12 = param_1;
    local_11 = param_2;
    thunk_EXT_FUN_0000b572(auStack_18,param_3,6);
    iVar1 = FUN_60095d9c(4,auStack_18);
    if (iVar1 == 0) {
      (**(code **)(DAT_60095d48 + 0x140))(6,param_1,param_2,param_3);
    }
  }
  return;
}


