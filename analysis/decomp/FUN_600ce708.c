// 600ce708  FUN_600ce708  size=60 bytes
// --- callers ---
// --- callees ---
//   600cf2be FUN_600cf2be


undefined4 FUN_600ce708(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  iVar1 = FUN_600cf2be(*(undefined4 *)*param_3,param_3[1],&local_10,0);
  if (iVar1 == 4) {
    uVar2 = 0xfffffffb;
  }
  else if (iVar1 == 0x514) {
    uVar2 = 0xfffffffe;
  }
  else if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


