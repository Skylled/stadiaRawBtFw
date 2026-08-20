// 600e69c2  FUN_600e69c2  size=88 bytes
// --- callers ---
//   600eb588 FUN_600eb588
//   6008aad8 FUN_6008aad8
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e653e FUN_600e653e


void FUN_600e69c2(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  thunk_EXT_FUN_0000af90(param_4,0,0x60,param_4,param_4);
  do {
    uVar3 = param_1 ^ uVar2;
    uVar2 = uVar2 + 1;
    FUN_600e653e(param_4,uVar3,param_3,param_4);
    FUN_600e653e(param_4 + 0x20,uVar3,param_3 + 0x20,param_4 + 0x20);
    iVar1 = param_3 + 0x40;
    param_3 = param_3 + 0x60;
    FUN_600e653e(param_4 + 0x40,uVar3,iVar1,param_4 + 0x40);
  } while (param_2 != uVar2);
  return;
}


