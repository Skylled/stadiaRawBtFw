// 600ff888  FUN_600ff888  size=254 bytes
// --- callers ---
//   600a96d8 FUN_600a96d8
// --- callees ---
//   600c712c FUN_600c712c
//   600c74a0 FUN_600c74a0
//   600c70ac FUN_600c70ac
//   600c7460 FUN_600c7460
//   600c7420 FUN_600c7420
//   600c71ac FUN_600c71ac
//   600c716c FUN_600c716c
//   600c73e0 FUN_600c73e0
//   600c70ec FUN_600c70ec


void FUN_600ff888(ushort param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 local_14;
  undefined1 auStack_13 [3];
  undefined1 *local_10;
  undefined1 *local_c;
  
  local_c = &local_14;
  local_10 = auStack_13;
  local_14 = param_2;
  if (param_1 == 0xc71) {
    FUN_600c73e0(local_c,param_3);
  }
  else if (param_1 < 0xc72) {
    if (param_1 == 0xc6e) {
      FUN_600c712c(local_c,param_3);
    }
    else if (param_1 < 0xc6f) {
      if (param_1 == 0xc3f) {
        FUN_600c70ac(local_c,param_3);
      }
    }
    else if (param_1 == 0xc6f) {
      FUN_600c716c(local_c,param_3);
    }
    else if (param_1 == 0xc70) {
      FUN_600c71ac(local_c,param_3);
    }
  }
  else if (param_1 == 0xc73) {
    FUN_600c7460(local_c,param_3);
  }
  else if (param_1 < 0xc73) {
    FUN_600c7420(local_c,param_3);
  }
  else if (param_1 == 0x140c) {
    FUN_600c74a0(local_c,param_3);
  }
  else if (param_1 == 0x2014) {
    FUN_600c70ec(local_c,param_3);
  }
  return;
}


