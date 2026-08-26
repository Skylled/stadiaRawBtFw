// 600d74b0  FUN_600d74b0  size=30 bytes
// --- callers ---
//   60066b40 keys__60066b40
//   60066a74 keys__60066a74
//   60066d94 keys__60066d94
//   600d74ce FUN_600d74ce
//   600668dc keys__600668dc
//   60066944 keys__60066944
//   600669a8 keys__600669a8
//   60066ce0 keys__60066ce0
//   60066ba8 keys__60066ba8
//   60066c28 keys__60066c28
// --- callees ---
//   6004cb28 FUN_6004cb28
//   600d7440 FUN_600d7440


void FUN_600d74b0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = FUN_6004cb28();
  }
  FUN_600d7440(uVar1,param_1);
  return;
}


