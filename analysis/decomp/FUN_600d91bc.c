// 600d91bc  FUN_600d91bc  size=70 bytes
// --- callers ---
//   600fea16 FUN_600fea16
//   600fe960 FUN_600fe960
// --- callees ---
//   6006d8f0 FUN_6006d8f0
//   6006cfb8 FUN_6006cfb8


void FUN_600d91bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  ushort local_12a;
  undefined1 auStack_128 [280];
  
  local_12a = 0;
  iVar1 = FUN_6006cfb8(param_1,10,&local_12a,auStack_128,param_3);
  if (iVar1 == 0) {
    uVar2 = 0x85;
  }
  else if (local_12a < 10) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x8a;
  }
  FUN_6006d8f0(param_1,param_2,local_12a,auStack_128,uVar2,param_4);
  return;
}


