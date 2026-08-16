// 600ac438  FUN_600ac438  size=210 bytes
// --- callers ---
//   600ab620 FUN_600ab620
//   600ac128 FUN_600ac128
//   600ac22c FUN_600ac22c
//   600ab778 FUN_600ab778
// --- callees ---
//   600f4376 FUN_600f4376
//   600f42d8 FUN_600f42d8
//   600ac2a4 FUN_600ac2a4
//   600b0730 FUN_600b0730
//   600f42fc FUN_600f42fc
//   600f610e FUN_600f610e
//   600ac014 FUN_600ac014
//   600f4266 FUN_600f4266
//   600f1b72 FUN_600f1b72


char FUN_600ac438(int *param_1)

{
  undefined1 uStack_14;
  char local_13;
  undefined1 local_12;
  byte local_11;
  int local_10;
  char local_9;
  
  local_10 = *param_1;
  local_9 = '\x01';
  local_11 = FUN_600f42fc(local_10);
  local_12 = FUN_600ac2a4(param_1);
  if (local_11 == 0) {
    FUN_600f42d8(local_10,local_12);
  }
  switch(local_12) {
  case 2:
    FUN_600ac014(param_1);
    break;
  case 3:
  case 4:
  case 5:
    if (local_11 < 3) {
      FUN_600f4376(local_12,&uStack_14);
      local_13 = FUN_600f1b72(local_10 + 0xd,*(undefined1 *)(local_10 + 0x13),DAT_600ac520,
                              &uStack_14);
      if ((local_13 != '\0') && (local_13 != '\x01')) {
        local_9 = '\0';
      }
    }
    if (local_9 != '\0') {
      FUN_600b0730(local_10,param_1);
    }
    break;
  case 6:
    FUN_600b0730(local_10,param_1);
    break;
  default:
    FUN_600f4266(1,param_1,local_12);
  }
  if (local_9 == '\0') {
    FUN_600f42d8(local_10,0);
    FUN_600f610e(local_10,4);
  }
  return local_9;
}


