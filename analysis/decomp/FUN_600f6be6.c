// 600f6be6  FUN_600f6be6  size=102 bytes
// --- callers ---
//   600f622a FUN_600f622a
//   600ae90c FUN_600ae90c
//   600ae670 FUN_600ae670
//   600ae7f8 FUN_600ae7f8
//   600aed40 FUN_600aed40
//   600aeb14 FUN_600aeb14
//   600f6516 FUN_600f6516
//   600f633e FUN_600f633e
//   600aee8c FUN_600aee8c
//   600ae4e0 FUN_600ae4e0
//   600adeb4 FUN_600adeb4
// --- callees ---
//   600c7eb8 FUN_600c7eb8
//   600adc88 FUN_600adc88
//   600ff9fe FUN_600ff9fe


undefined1
FUN_600f6be6(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
            char param_5)

{
  undefined2 local_14;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  undefined1 local_9;
  
  local_14 = param_4;
  local_12 = param_3;
  local_11 = param_2;
  local_10 = FUN_600c7eb8(param_1,1,&local_14);
  if (local_10 == 0) {
    local_9 = 0x11;
  }
  else {
    local_9 = FUN_600ff9fe(param_1,local_10);
  }
  if (param_5 != '\0') {
    FUN_600adc88(param_1);
  }
  return local_9;
}


