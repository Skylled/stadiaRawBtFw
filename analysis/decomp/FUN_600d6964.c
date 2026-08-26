// 600d6964  FUN_600d6964  size=40 bytes
// --- callers ---
// --- callees ---
//   600d6956 FUN_600d6956
//   600d68fe FUN_600d68fe
//   600d68ba FUN_600d68ba


void FUN_600d6964(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 uVar2;
  undefined4 extraout_r2_00;
  
  FUN_600d6956(param_1 + 0x108,0);
  if (param_4 == 0) {
    FUN_600d68ba(param_1);
    uVar1 = 1;
    uVar2 = extraout_r2_00;
  }
  else {
    uVar1 = 8;
    uVar2 = extraout_r2;
  }
  FUN_600d68fe(param_1,uVar1,uVar2,param_4);
  return;
}


