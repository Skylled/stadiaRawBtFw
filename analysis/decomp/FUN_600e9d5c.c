// 600e9d5c  FUN_600e9d5c  size=26 bytes
// --- callers ---
//   600e9d76 FUN_600e9d76
// --- callees ---
//   600e9bc2 FUN_600e9bc2
//   6010209a FUN_6010209a


void FUN_600e9d5c(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  if ((*(uint *)(param_6 + 0x18) == param_3) && (*(uint *)(param_6 + 0x18) < 0x12)) {
    FUN_600e9bc2();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_6010209a();
}


