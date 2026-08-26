// 600d82f6  FUN_600d82f6  size=44 bytes
// --- callers ---
//   6005c270 FUN_6005c270
// --- callees ---
//   600d82c0 FUN_600d82c0
//   600d82d8 FUN_600d82d8


void FUN_600d82f6(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  FUN_600d82d8(&uStack_10,param_1,5);
  if (param_2 == 0) {
    bVar1 = uStack_c._1_1_ & 0xfb;
  }
  else {
    bVar1 = uStack_c._1_1_ | 4;
  }
  uStack_c._0_2_ = CONCAT11(bVar1,(undefined1)uStack_c);
  FUN_600d82c0(&uStack_10);
  return;
}


