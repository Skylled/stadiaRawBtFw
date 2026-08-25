// 600f5db4  FUN_600f5db4  size=136 bytes
// --- callers ---
// --- callees ---
//   600afea0 FUN_600afea0
//   600f6132 FUN_600f6132
//   600b02e0 FUN_600b02e0
//   600f7a34 FUN_600f7a34
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f610e FUN_600f610e
//   600f7912 FUN_600f7912


void FUN_600f5db4(undefined2 param_1,short param_2)

{
  int iVar1;
  undefined1 auStack_54 [2];
  undefined1 local_52;
  undefined2 local_50;
  int local_c;
  
  local_c = FUN_600afea0(param_1);
  if (local_c != 0) {
    iVar1 = FUN_600f6132(local_c);
    if (iVar1 == 2) {
      if (param_2 == 0) {
        FUN_600f610e(local_c,3);
        thunk_EXT_FUN_0000b5ba(auStack_54,0,0x48);
        local_52 = 1;
        local_50 = 0x205;
        FUN_600f7912(param_1,auStack_54);
      }
      else {
        FUN_600b02e0(local_c + 0xd,param_2,1);
      }
    }
    else if (param_2 == 0) {
      FUN_600f7a34(param_1);
    }
  }
  return;
}


