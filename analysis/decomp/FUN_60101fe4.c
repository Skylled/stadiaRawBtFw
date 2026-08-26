// 60101fe4  FUN_60101fe4  size=54 bytes
// --- callers ---
//   60080f70 FUN_60080f70
// --- callees ---
//   6010201a FUN_6010201a
//   6004cb28 FUN_6004cb28
//   6010209a FUN_6010209a


void FUN_60101fe4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_20 [4];
  undefined4 *local_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar1 = FUN_6004cb28(param_1);
  local_1c = &uStack_c;
  FUN_6010201a(auStack_20 + -(iVar1 + 0x20eU & 0xfffffff8),iVar1 + 0x200,param_1,&uStack_c);
                    /* WARNING: Subroutine does not return */
  FUN_6010209a();
}


