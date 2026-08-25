// 600fb9d2  FUN_600fb9d2  size=52 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   600fabc6 FUN_600fabc6
//   600fc4d8 FUN_600fc4d8


void FUN_600fb9d2(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint extraout_r3;
  
  FUN_600fc4d8(param_1);
  uVar1 = (uint)*(byte *)(param_1 + 0x26);
  if (uVar1 == 1) {
    FUN_600fabc6(param_1,0);
    uVar1 = extraout_r3;
  }
  FUN_600c1a34(param_1,0x1e,0,uVar1,param_2);
  return;
}


