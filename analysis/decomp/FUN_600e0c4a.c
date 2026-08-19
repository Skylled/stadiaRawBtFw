// 600e0c4a  FUN_600e0c4a  size=16 bytes
// --- callers ---
//   60091098 dsa__60091098
//   600ebf76 bcm__600ebf76
// --- callees ---
//   600ee100 FUN_600ee100
//   6010209a FUN_6010209a


void FUN_600e0c4a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_600ee100(param_1,0,param_3,param_4,param_4);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  return;
}


