// 600d9ae2  FUN_600d9ae2  size=100 bytes
// --- callers ---
//   60071478 FUN_60071478
// --- callees ---


uint FUN_600d9ae2(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 local_4 [4];
  
  uVar1 = 0;
  switch(param_1) {
  case 2:
  case 3:
    local_4[0] = 1;
    goto LAB_600d9afa;
  case 4:
    local_4._0_2_ = 0;
    uVar1 = 3;
    break;
  case 5:
    local_4._0_2_ = 0;
    uVar1 = 4;
    break;
  case 6:
    local_4._0_2_ = 0;
    uVar1 = 5;
    break;
  default:
    local_4[0] = 0;
LAB_600d9afa:
    local_4[1] = 0;
  }
  local_4._0_3_ = CONCAT12(uVar1,local_4._0_2_);
  return CONCAT13(0,local_4._0_3_);
}


