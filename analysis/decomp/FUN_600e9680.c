// 600e9680  FUN_600e9680  size=70 bytes
// --- callers ---
//   600e96c6 FUN_600e96c6
// --- callees ---
//   6013cfb0 thunk_EXT_FUN_0000ac52
//   600e8b7a FUN_600e8b7a
//   6010209a FUN_6010209a
//   600e90aa FUN_600e90aa
//   600e7b96 FUN_600e7b96


void FUN_600e9680(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined1 auStack_98 [140];
  
  if ((param_2 == param_4 * 2) && (param_4 < 0x12)) {
    if (param_4 == 4) {
      FUN_600e90aa(param_1,param_3);
    }
    else if (param_4 == 8) {
      FUN_600e8b7a(param_1,param_3);
    }
    else {
      if (param_4 != 0) {
        FUN_600e7b96(param_1,param_3,param_4,auStack_98);
      }
      thunk_EXT_FUN_0000ac52(auStack_98,param_4 << 3);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_6010209a();
}


