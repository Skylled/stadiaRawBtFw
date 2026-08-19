// 600d411c  FUN_600d411c  size=60 bytes
// --- callers ---
// --- callees ---
//   6005c44c FUN_6005c44c
//   60079c50 FUN_60079c50
//   6007ec20 FUN_6007ec20
//   6007ec28 FUN_6007ec28
//   60074ba8 FUN_60074ba8
//   6007ec48 receiver__6007ec48


void FUN_600d411c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uStack_10;
  int local_c;
  
  uStack_10 = param_1;
  local_c = param_2;
  FUN_60079c50(&uStack_10);
  switch(param_2) {
  case 0:
    uVar1 = 0xb;
    goto LAB_600d4134;
  case 1:
    uVar1 = 10;
LAB_600d4134:
    FUN_60074ba8(uVar1);
    break;
  case 2:
    FUN_6007ec20();
    FUN_6007ec28();
    break;
  case 3:
    FUN_6007ec20();
    receiver__6007ec48();
  }
  if (local_c != 0) {
    FUN_6005c44c();
  }
  return;
}


