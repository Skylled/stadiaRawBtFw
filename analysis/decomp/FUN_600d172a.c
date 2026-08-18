// 600d172a  FUN_600d172a  size=28 bytes
// --- callers ---
// --- callees ---
//   60055860 FUN_60055860


void FUN_600d172a(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_60055860();
  if (iVar1 != 0) {
    if (param_2 == 0) {
      uVar2 = *(uint *)(iVar1 + 0x30) & 0xfffffffd;
    }
    else {
      uVar2 = *(uint *)(iVar1 + 0x30) | 2;
    }
    *(uint *)(iVar1 + 0x30) = uVar2;
  }
  return;
}


