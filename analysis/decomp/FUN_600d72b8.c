// 600d72b8  FUN_600d72b8  size=52 bytes
// --- callers ---
//   600669a8 keys__600669a8
//   600666f0 keys__600666f0
//   600d732e FUN_600d732e
// --- callees ---
//   600d7282 FUN_600d7282
//   600d6e14 FUN_600d6e14
//   60065db0 FUN_60065db0
//   60065dd8 FUN_60065dd8
//   60066070 keys__60066070


void FUN_600d72b8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_600d6e14();
  if (iVar1 != 0) {
    uVar2 = FUN_60065db0(param_1);
    uVar3 = FUN_60065dd8(param_1);
    FUN_600d7282(uVar2,uVar3,param_2);
    return;
  }
  keys__60066070(param_1,param_2,4);
  return;
}


