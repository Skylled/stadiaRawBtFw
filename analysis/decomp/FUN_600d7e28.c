// 600d7e28  FUN_600d7e28  size=26 bytes
// --- callers ---
// --- callees ---
//   6008cb7c bcm__6008cb7c


undefined4 FUN_600d7e28(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = bcm__6008cb7c(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),0,param_4,
                        param_4);
  if (iVar1 == 0) {
    uVar2 = 0xd;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


